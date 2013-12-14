/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_print_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 06:33:15 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/14 23:51:55 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*hr_key_search(t_keyword *keyword, t_hash key)
{
	t_keyword	current;

	current = keyword;
	while (current)
	{
		if (current->key == key)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
