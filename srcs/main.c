/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 22:55:23 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/14 23:51:57 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	hr_parseinput(char *str, int lines, t_keyword **table)
{
	static t_bool	flag = FALSE;
	static t_hash	hashx = 0;
	static t_hash	hashy = 0;
	size_t			strlen;

	strlen = ft_strlen(str);
	hashx = (!(lines % 2) || flag) ? hr_crc32(str, strlen, ROTATE_X, 1) : hashx;
	hashy = (!(lines % 2) || flag) ? hr_crc32(str, strlen, ROTATE_Y, 0) : hashy;
	if (!strlen && !(lines % 2))
		flag = TRUE;
	if (!flag && (lines % 2))
		table[hashx] = hr_keyword_lstadd(table[hashx], str, hashy);
	if (flag && strlen)
		hr_search(str, table, hashx, hashy);
}

int	main()
{
	t_keyword	**hashtable;
	char		*str;
	int			i;

	hashtable = (t_keyword**) malloc(sizeof(t_keyword*) * set_tab_len(REDUCE));
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
