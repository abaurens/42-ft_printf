/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:40:22 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/30 23:50:41 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*t;

	t = (unsigned char *)b;
	while (len > 0)
	{
		len--;
		*t++ = (unsigned char)c;
	}
	return (b);
}
