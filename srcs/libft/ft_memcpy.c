/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:45:18 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/30 23:50:41 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/libft.h"
#include <unistd.h>

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;

	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	while (n > 0)
	{
		n--;
		*to++ = *from++;
	}
	return (dst);
}
