/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 22:55:23 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/14 02:08:35 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

unsigned int	hr_rotate(char *str, int rotate)
{
	int				i;
	unsigned int	rtn;

	i = -1;
	rtn = 1;
	while (str[++i])
		rtn *= (str[i] << rotate) | (str[i] >> (32 - rotate));
	return (rtn % TABLESIZE);
}

void			hr_parseinput(char *str, int lines, t_keyword *table)
{
	static t_bool		flag = FALSE;
	static unsigned int	hashx = 0;
	static unsigned int hashy = 0;

	hashx = (!(lines % 2) || flag) ? hr_rotate(str, ROTATE_X) : hashx;
	hashy = (!(lines % 2) || flag) ? hr_rotate(str, ROTATE_Y) : hashy;
	if (!str[0])
		flag = TRUE;
	if (!flag && !(lines % 2))
		hr_insert_keyword(table, str, hashx, hashy);
	if (!flag && (lines % 2))
		hr_insert_value(table, str, hashx, hashy);
	if (flag)
		hr_search(table, hashx, hashy);
}

int	main()
{
	t_keyword	*hashtable;
	char		*str;
	int			i;

	hashtable = (t_keyword*) malloc(sizeof(t_keyword) * TABLESIZE);
	i = 0;
	while (get_next_line(0, &str) == 1)
		parseinput(str, i++, hashtable);
	return (0);
}
