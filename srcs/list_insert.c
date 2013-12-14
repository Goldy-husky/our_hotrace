/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 02:15:29 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/14 07:38:59 by sbethoua         ###   ########.fr       */
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
	if (!elem->value)
	{
		free(elem);
		return (NULL); // ! Retourne un keyword * ! //
	}
	elem->key = key;
	elem->next = NULL;
	if (!keyword)
		return (elem);
	tmp = keyword;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	return (elem);
	// TO DO: Replace value if key is in list
}

void		hr_keyword_lstchg(t_keyword *keyword, int key, const char *value)
{
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
				return (NULL)
			}
		}
		current = current->next;
	}
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