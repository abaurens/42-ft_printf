/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padded_lltoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:02:00 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/13 20:06:07 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*padded_lltoa(long long nb, const int min_d, int pad, char r)
{
	int		len;
	int		pad_i;
	char	*ret;

	r = (r != 0);
	if ((len = ft_numlen(nb)) < (min_d + (nb < 0)))
		len = (min_d + (nb < 0));
	pad_i = (pad > len) ? (pad - len) : 0;
	if (!(ret = (char *)malloc(pad_i + len + 1)))
		return (NULL);
	ret[pad_i + len] = 0;
	ft_memset(ret + (!r * pad_i), '0', len);
	ft_memset(ret + (r * len), ' ', pad_i);
	ret[(!r * pad_i)] = (nb < 0 ? '-' : '0');
	while (nb != 0)
	{
		ret[(!r * pad_i) + --len] = (ft_abs(nb % 10) + '0');
		nb /= 10;
	}
	return (ret);
}
