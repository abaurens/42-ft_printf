/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:10:29 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/07 18:19:09 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

long double		ft_pow(long double v, long long int p)
{
	long double	res;

	if (p == 0)
		return (1);
	res = ft_pow(v, p + (p < 0 ? 1 : -1)) * v;
	return (res);
}
