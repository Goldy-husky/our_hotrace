/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 02:15:29 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/15 05:36:36 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_keyword	*hr_chg(t_keyword *kword, t_keyword *tmp, t_hash key, char *value)
{
	if (tmp->key == key)
	{
		ft_strdel(&tmp->value);
		tmp->value = ft_strdup(value);
		if (!tmp->value)
		{
			hr_keyword_lstdel(kword);
			free(kword);
			return (NULL);
		}
	}
	return (tmp);
}

t_keyword	*hr_keyword_lstadd(t_keyword *keyword, t_hash key, char *value)
{
	t_keyword	*elem;
	t_keyword	*tmp;

	if ((elem = (t_keyword *) malloc(sizeof(t_keyword))) == NULL)
		return (NULL);
	elem->value = ft_strdup(value);
	if (!elem->value)
	{
		free(elem);
		return (NULL);
	}
	elem->key = key;
	elem->next = NULL;
	if (!keyword)
		return (elem);
	tmp = keyword;
	tmp = hr_chg(keyword, tmp, key, value);
	while (tmp->next)
	{
		tmp = hr_chg(keyword, tmp, key, value);
		tmp = tmp->next;
	}
	tmp->next = elem;
	return (keyword);
}

void		hr_keyword_lstdel(t_keyword *keyword)
{
	t_keyword	*current;
	t_keyword	*next;

	current = keyword;
	while (current)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
}
