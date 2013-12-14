/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 02:15:29 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/14 06:02:32 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_keyword	*hr_keyword_lstadd(t_keyword *keyword, int key, const char *value)
{
	t_keyword	*elem;
	t_keyword	*tmp;

	if ((elem = (t_keyword *) malloc(sizeof(t_keyword))) == NULL)
		return (NULL);
	elem->value = ft_strdup(value);
	if (elem->value == NULL)
	{
		free(elem);
		return (NULL);
	}
	elem->key = key;
	elem->next = NULL;
	if (keyword == NULL)
		return (elem);
	tmp = keyword;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
	return (elem);
}

void		hr_keyword_lstreplace(t_keyword *keyword, int key, const char *value)
{
	t_keyword	current;

	current = keyword;
	while (current != next)
	{
		if (current->key == key)
			current->value = ft_strdup(value);
		current = current->next;
	}
}

void		hr_keyword_lstdel(t_keyword *keyword)
{
	t_keyword	*current;
	t_keyword	*next;

	current = keyword;
	while (current != NULL)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
}
