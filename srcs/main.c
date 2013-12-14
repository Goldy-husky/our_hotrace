/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 22:55:23 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/14 07:37:16 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	hr_parseinput(char *str, int lines, t_keyword *table)
{
	static t_bool		flag = FALSE;
	static unsigned int	hashx = 0;
	static unsigned int hashy = 0;
	size_t				strlen;
	char				*tmp;

	tmp = ft_
	strlen = ft_strlen(str);
	hashx = (!(lines % 2) || flag) ? hr_crc_32(str, strlen, ROTATE_X) : hashx;
	hashy = (!(lines % 2) || flag) ? hr_crc_32(str, strlen, ROTATE_Y) : hashy;
	if (!strlen && !(lines % 2))
		flag = TRUE;
	if (!flag && !(lines % 2))
		hr_insert_keyword(table, str, hashx, hashy);
	if (!flag && (lines % 2))
		hr_insert_value(table, str, hashx, hashy);
	if (flag && strlen)
		hr_search(str, table, hashx, hashy);
}

int				main()
{
	t_keyword	**hashtable;
	char		*str;
	int			i;

	hashtable = (t_keyword**) malloc(sizeof(t_keyword*) * TABLESIZE);
	if (hashtable == NULL)
		return (1);
	i = 0;
	while (i < TABLESIZE)
		hashtable[i++] = NULL;
	i = 0;
	while (get_next_line(0, &str) == 1)
		parseinput(str, i++, hashtable);
	return (0);
}
