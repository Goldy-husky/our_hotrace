/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 02:15:29 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/15 01:14:27 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

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
	while (tmp->next)
	{
		// Begin check if key is present in list
		if (tmp->key == key)
		{
			ft_strdel(&tmp->value);
			tmp->value = ft_strdup(value);
			if (!tmp->value)
			{
				free(elem);
				hr_keyword_lstdel(keyword);
				free(keyword);
				return (NULL);
			}
		}
		// End
		tmp = tmp->next;
	}
	tmp->next = elem;
	return (keyword);
}

/*
void		hr_keyword_lstchg(t_keyword *keyword, t_hash key, const char *value)
{ // FUNCTION NOT USED ?
	t_keyword	current;

	current = keyword;
	while (current != next)
	{
		if (current->key == key)
		{
			current->value = ft_strdup(value);
			if (!current->value)
			{
				hr_keyword_lstdel(keyword);
				free(keyword);
				return (NULL) // Function return void !? //
			}
		}
		current = current->next;
	}
}
*/

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
