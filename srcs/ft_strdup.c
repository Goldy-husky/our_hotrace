/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:50:13 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/15 00:43:15 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cpy1;
	const char	*cpy2;
	size_t		i;

	cpy1 = (char *) dst;
	cpy2 = (const char *) src;
	i = 0;
	while (i < n)
	{
		cpy1[i] = cpy2[i];
		i++;
	}
	return (dst);
}

char	*ft_strcpy(char *dst, const char *src)
{
	return (ft_memcpy(dst, src, ft_strlen(src) + 1));
}

char	*ft_strdup(const char *src)
{
	char	*dst;

	dst = (char *) malloc(sizeof(char) * (ft_strlen(src) + 1));
	ft_strcpy(dst, src);
	return (dst);
}
