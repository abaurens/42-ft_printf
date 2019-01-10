/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padded_ulltoa_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:02:00 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/06 22:22:14 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*padded_ulltoa_hexa(unsigned long long nb, const int min_d,
	const int pad, char r)
{
	int		len;
	int		pad_i;
	char	*ret;
	char	*base;

	r = (r != 0);
	base = "0123456789abcdef";
	if ((len = ft_unsignedlen_base(nb, base)) < min_d)
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
		ret[(!r * pad_i) + --len] = base[nb % 16];
		nb /= 16;
	}
	return (ret);
}
