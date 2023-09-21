/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aydemir <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:14:14 by aydemir           #+#    #+#             */
/*   Updated: 2022/12/04 16:14:16 by aydemir          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	d;

	d = 0;
	s = 0;
	while (dst[d] && (d < size))
		d++;
	while (src[s] && d + s + 1 < size)
	{
		dst[s + d] = src[s];
		s++;
	}
	if (d < size)
		dst[d + s] = '\0';
	return (d + ft_strlen(src));
}
