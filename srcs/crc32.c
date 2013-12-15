/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crc32.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 04:40:57 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/15 07:55:22 by cmehay           ###   ########.fr       */
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

t_hash	hr_crc32(t_crc crc, const char *str, int size, int shift)
{
	static t_bool	flag = FALSE;
	const char		*tmp;
	static t_crc	table[256];

	if (!flag)
	{
		hr_crc_init_32(table);
		flag = TRUE;
	}
	crc = crc ^ ~0U;
	tmp = str;
	while (size--)
		crc = table[(crc ^ (*tmp++ << shift)) & 0xFF] ^ (crc >> 8);
	return (crc ^ ~0U);
}

t_hash		 set_tab_len(int reduce)
{
	int 	base;
	int 	i;
	t_hash	rtn;

	base = 2;
	rtn = base;
	i = 0;
	while (++i < reduce)
		rtn *= base;
	return (rtn);
}
