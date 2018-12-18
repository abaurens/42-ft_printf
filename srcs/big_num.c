/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:22:26 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/18 21:42:31 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

char		*bignum_add_dot(const char *n1, const char *n2)
{
	size_t	i;
	size_t	l1;
	size_t	l2;
	size_t	len;
	char	*res;

	if (!n1 || !n2)
		return (NULL);
	l1 = ft_strlen(n1);
	l2 = ft_strlen(n2);
	len = ft_max(l1, l2);
	if (!(res = (char *)malloc(len + 2)))
		return (NULL);
	ft_memset(res++, 0, len + 2 + (i = 0));
	while (++i <= len)
	{
		res[len - i] += (len - i < l1) * (n1[len - i] - '0')\
		+ ((len - i < l2) * (n2[len - i] - '0'));
		if (res[len - i] > 9 && (res[len - i - 1] += res[len - i] / 10))
			res[len - i] %= 10;
		res[len - i] += '0';
	}
	if ((*--res += '0') == '0')
		ft_memmove(res, res + 1, len + 1);
	return (res);
}
