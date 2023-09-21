/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aydemir <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:09:56 by aydemir           #+#    #+#             */
/*   Updated: 2022/12/04 16:09:58 by aydemir          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void	*src, size_t len)
{
	char	*d;
	char	*s;

	if (dst == src || len == 0)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len)
		{
			len--;
			d[len] = s[len];
		}
	}
	return (dst);
}
