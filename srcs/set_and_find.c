/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 06:30:06 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/14 23:51:58 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*hr_key_search(t_keyword *keyword, int key)
{
	t_keyword   current;

	current = keyword;
	while (current)
	{
		if (current->key == key)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

void	hr_print(char *str, char *value)
{
	if (!value)
	{
		ft_putstr(str);
		ft_putendl(": Not found.")
	}
	else
		ft_putendl(value);
}

void	hr_search(const char *str, t_keyword **hashtable, t_hash x, t_hash y)
{
	if (hatshtable[x])
		hr_print(str, hr_key_search(hatshtable[x], y));
	else
		hr_print(str, NULL);
}

int		hr_insert_value(t_keyword **table, t_hash x, t_hash y)
{
	t_keyword	*keyword;

	keyword = NULL;
	table[x] = hr_keyword_lstadd(table[x], y, )
}
