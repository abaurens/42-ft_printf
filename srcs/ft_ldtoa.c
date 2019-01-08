/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:51:08 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/08 17:43:49 by abaurens         ###   ########.fr       */
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

static char			*process_exponent(char *val, int exp)
{
	if (exp < 0)
		ft_memmove(val, val - exp + 1, ft_strlen(val - exp));
	((char *)ft_memmove(val + 1, val, ft_idxof('.', val)))[0] = '.';
	return (val);
}

char				*exp_dbl(long double d, size_t prec)
{
	size_t			expl;
	char			sign;
	int				exp;
	char			*tmp;
	char			*res;

	if ((sign = 0) || d != d)
		return (ft_strdup("nan"));
	if ((exp = 0) || dbl_abs(&d, &sign) == (1.0 / 0.0))
		return (ft_strdup(sign ? "-inf" : "inf"));
	if (!(tmp = ft_ldtoa(d)))
		return (NULL);
	while (d != 0.0 && ((d < 1.0 && --exp) || (d >= 10.0 && ++exp)))
		d = (d >= 10.0 ? d / 10.0 : d * 10.0);
	tmp = process_exponent(tmp, exp);
	round_tabflt(tmp, prec, &exp);
	expl = ft_max(2, ft_unsignedlen(ft_abs(exp)));
	if (!tmp || !(res = ft_memalloc(sign + 2 + prec + 2 + expl + 1)))
		return ((char *)ft_freturn(tmp, 0x0));
	*res = ft_freturn(NULL + !ft_memset(res + sign, 48, sign + 2 + prec), '-');
	ft_strncpy(res + sign, tmp, ft_min(sign + 2 + prec, ft_strlen(tmp)));
	ft_memcpy(res + sign + 2 + prec, (exp < 0 ? "e-" : "e+"), 2);
	while (expl-- > 0 && (res[sign + 4 + prec + expl] = ft_abs(exp % 10) + '0'))
		exp = ft_abs(exp / 10);
	return ((char *)ft_freturn(tmp, (long)res));
}

static char		*get_exp_hex(long double *d, int *exp)
{
	t_bflt		two;
	t_bflt		*tmp;
	char		*res;

	*exp = 0;
	dbl_abs(d, NULL);
	set_bflt(&two, *d >= 16.0 ? "0.5" : "2.0");
	tmp = new_ftobflt(*d);
	if (*d >= 16.0)
		while ((*d) >= 16.0 && ++*exp)
		{
			*d *= 0.5;
			tmp = mul_bflt(tmp, &two);
		}
	else if (*d <= 16.0)
		while ((*d * 2.0) < 16.0 && --*exp)
		{
			*d *= 2.0;
			tmp = mul_bflt(tmp, &two);
		}
	unset_bflt(&two);
	res = to_hex(tmp);
	del_bflt(tmp);
	return (res);
}

char			*exp_dbl_hex(long double d, int prec)
{
	int				exp;
	char			sign;
	char			*tmp;
	char			*res;
	size_t			expl;

	if ((sign = 0) || d != d)
		return (ft_strdup("nan"));
	if ((exp = 0) || dbl_abs(&d, &sign) == (1.0 / 0.0))
		return (ft_strdup(sign ? "-inf" : "inf"));
	tmp = get_exp_hex(&d, &exp);
	if (!tmp || (prec >= 0 && !round_hex(tmp, prec, &exp)))
		return (NULL);
	prec = (prec < 0 ? ft_strlen(tmp) : prec + 2);
	expl = ft_unsignedlen(ft_abs(exp));
	if (!tmp || !(res = ft_memalloc(sign + 2 + prec + 2 + expl + 1)))
		return (NULL);
	*res = '-';
	ft_memset(res + sign, '0', 2 + prec + 2 + expl);
	ft_memcpy(res + sign, "0x", 2);
	ft_memcpy(res + sign + 2, tmp, ft_min(prec + 2, ft_strlen(tmp)));
	ft_memcpy(res + sign + 2 + prec, (exp < 0 ? "p-" : "p+"), 2);
	while (expl-- > 0 && (res[sign + 4 + prec + expl] = ft_abs(exp % 10) + '0'))
		exp = ft_abs(exp / 10);
	return (res);
}
