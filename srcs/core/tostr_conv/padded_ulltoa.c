/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padded_ulltoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:02:00 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/14 16:23:16 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "core/libft.h"

char		*padded_ulltoa(unsigned long long nb, const int min_d,
	const int pad, char r)
{
	int		len;
	int		pad_i;
	char	*ret;

	r = (r != 0);
	if ((len = ft_unsignedlen(nb)) < min_d)
		len = min_d;
	pad_i = (pad > len) ? (pad - len) : 0;
	if (!(ret = (char *)malloc(pad_i + len + 1)))
		return (NULL);
	ret[pad_i + len] = 0;
	ft_memset(ret + (!r * pad_i), '0', len);
	ft_memset(ret + (r * len), ' ', pad_i);
	ret[(!r * pad_i)] = '0';
	while (nb != 0)
	{
		ret[(!r * pad_i) + --len] = (nb % 10 + '0');
		nb /= 10;
	}
	return (ret);
}
