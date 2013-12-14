/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crc32.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 04:40:57 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/14 07:42:16 by sbethoua         ###   ########.fr       */
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
		rem = div << (WIDTH - 8);
		bit = 8;
		while (bit-- > 0)
			rem = (rem & TOPBIT) ? (rem << 1) ^ POLY : (rem << 1);
		table[div++] = rem;
	}
}

t_crc	hr_crc_32(char *str, int size, int rotate)
{
	static t_bool	flag = FALSE;
	uint8_t			data;
	t_crc			rem;
	int				byte;
	static t_crc	table[256];

	if (!flag)
	{
		hr_crc_init_32(table);
		flag = TRUE;
	}
	rem = 0;
	byte = 0;
	while (byte < size)
	{
		data = ((str[byte] << rotate) | (str[i] >> (32 - rotate)))
			^ (rem >> (WIDTH - 8));
		rem = table[data] ^ (rem << 8);
	}
	return (rem);
}
