/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lltoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:26:44 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/13 18:44:19 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*printf_lltoa(long long int nb, const int min)
{
	int		len;
	char	*ret;

	if ((len = ft_numlen(nb)) < (min + (nb < 0)))
		len = (min + (nb < 0));
	if (!(ret = (char *)malloc(len + 1)))
		return (NULL);
	ret[len] = 0;
	ft_memset(ret, '0', len);
	ret[0] = (nb < 0 ? '-' : '0');
	while (nb != 0)
	{
		ret[--len] = (ft_abs(nb % 10) + '0');
		nb /= 10;
	}
	return (ret);
}
