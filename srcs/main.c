/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 22:55:23 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/15 07:54:44 by cmehay           ###   ########.fr       */
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
	hashx = (!(lines % 2) || flag) ? hr_crc32(0, str, strlen, 0) : hashx;
	hashy = (!(lines % 2) || flag) ? hr_crc32(30, str, strlen, 2) : hashy;
	if (!strlen && !(lines % 2))
		flag = TRUE;
	if (!flag && (lines % 2))
		table[hashx] = hr_keyword_lstadd(table[hashx], hashy, str);
	if (flag && strlen)
		hr_search(str, table, hashx, hashy);
	return (0);
}

int	main(void)
{
	t_keyword	**hashtable;
	char		*str;
	t_hash		i;
	t_hash		len;

	len = set_tab_len(REDUCE);
	hashtable = (t_keyword**) malloc(sizeof(t_keyword*) * 4294967296);
	if (hashtable == NULL)
		return (1);
	i = 0;
	while (i < len)
		hashtable[i++] = NULL;
	i = 0;
	while (get_next_line(0, &str) == 1)
		hr_parseinput(str, i++, hashtable);
	return (0);
}
