/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crc32.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 04:40:57 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/15 09:15:05 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	hr_crc_init_32(t_crc *table)
{
	t_crc		rem;
	int			div;
	uint8_t		bit;

	div = 0;
	while (div < 256)
	{
		rem = div;
		bit = 8;
		while (bit-- > 0)
			rem = (rem & 1) ? (rem >> 1) ^ POLY : (rem >> 1);
		table[div++] = rem;
	}
}

t_hash	hr_crc32(const char *str, int size, int shift, t_bool reduce)
{
	static t_bool	flag = FALSE;
	const char		*tmp;
	static t_crc	table[256];
	int				red;
	t_crc			crc;

	red = REDUCE;
	reduce = (REDUCE < 32) ? reduce : FALSE;
	if (!flag)
	{
		hr_crc_init_32(table);
		flag = TRUE;
	}
	crc = 0 ^ ~0U;
	tmp = str;
	while (size--)
		crc = table[(crc ^ (*tmp++ << shift)) & 0xFF] ^ (crc >> 8);
	if (reduce)
		return ((crc ^ ~0U) & ((1 << red) - 1));
	return (crc ^ ~0U);
}

uint64_t		 set_tab_len(int reduce)
{
	int 		base;
	int 		i;
	uint64_t	rtn;

	base = 2;
	rtn = base;
	i = 0;
	while (++i < reduce)
		rtn *= base;
	return (rtn);
}
