/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:51:08 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/06 17:52:37 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bigfloat.h"
#include "ft_printf.h"
#include "ft_types.h"
#include "libft.h"

char				*ft_ldtoa(long double d)
{
	t_float			fl;
	t_bflt			*tmp;
	t_bflt			*expo;
	t_bflt			*mant;
	char			*res;

	if (d != d)
		return (ft_strdup("nan"));
	if (d == (1.0 / 0.0) || d == -(1.0 / 0.0))
		return (ft_strdup(d < 0.0 ? "-inf" : "inf"));
	fl = get_float_components(d);
	mant = get_mantissa(&fl);
	expo = new_bflt(fl.exponent < 0 ? "0.5" : "2");
	while ((expo && mant) && fl.exponent && ((tmp = mant) || 1))
	{
		fl.exponent += (fl.exponent < 0 ? 1 : -1);
		mant = mul_bflt(expo, mant);
		del_bflt(tmp);
	}
	del_bflt(expo);
	res = expo ? bflt_tostr(mant) : NULL;
	del_bflt(mant);
	if (res && fl.sign)
		res = (char *)ft_freturn(res, (long)ft_strmcat("-", res, -1));
	return (res);
}
