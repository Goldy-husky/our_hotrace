/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:50:40 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/15 00:43:02 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*cpy;
	size_t		i;

	cpy = (const char *) s;
	i = 0;
	while (i < n)
	{
		if (cpy[i] == (unsigned char) c)
			return ((void *) &cpy[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}
