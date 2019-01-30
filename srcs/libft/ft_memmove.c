/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:49:10 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/30 23:50:41 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	char			dir;
	size_t			start;
	unsigned char	*s;
	unsigned char	*d;

	i = -1;
	dir = 1;
	start = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (dst > src && (dir = -1))
		start = len - 1;
	while (++i < len)
		d[start + (i * dir)] = s[start + (i * dir)];
	return (dst);
}
