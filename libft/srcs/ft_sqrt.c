/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:06:40 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/07 18:25:40 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	sqrt_num_len(long double nb)
{
	long long		i;

	i = 1;
	while (nb >= 10.0)
	{
		i++;
		nb /= 10.0;
	}
	return (i);
}

long double			ft_sqrt(long double nb)
{
	int				i;
	long double		a;

	i = 0;
	if (nb < 0.0)
		return (-1);
	if (nb == 0.0 || nb == 1.0)
		return (nb);
	if (nb > 7447441.0)
		return (2.0 * ft_sqrt(nb / 4.0));
	a = ft_pow(10.0, sqrt_num_len(nb) / 2.0);
	while (++i < 20)
		a = 0.5 * (a + (nb / a));
	return (a);
}
