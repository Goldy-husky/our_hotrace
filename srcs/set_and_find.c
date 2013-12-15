/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 06:30:06 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/15 01:24:39 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*hr_key_search(t_keyword *keyword, t_hash key)
{
	t_keyword	*current;

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
		ft_putendl(": Not found.");
	}
	else
		ft_putendl(value);
}

void	hr_search(char *str, t_keyword **table, t_hash x, t_hash y)
{
	if (table[x])
		hr_print(str, hr_key_search(table[x], y));
	else
		hr_print(str, NULL);
}
