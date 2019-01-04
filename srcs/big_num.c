/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:22:26 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/04 13:26:15 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "ft_bigfloat.h"
#include "libft.h"

t_bflt		*new_ftobflt(long double d)
{
	t_float	fl;
	t_bflt	*res;
	t_bflt	*tmp;
	t_bflt	*expo;

	if (d == (1.0 / 0.0))
		return (NULL);
	if (d != d)
		return (NULL);
	fl = get_float_components(d);
	res = get_mantissa(&fl);
	expo = new_bflt(fl.exponent < 0 ? "0.5" : "2");
	while ((expo && res) && fl.exponent--)
	{
		tmp = res;
		res = mul_bflt(expo, res);
		del_bflt(tmp);
	}
	del_bflt(expo);
	return (res);
}
