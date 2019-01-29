/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:51:08 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/29 20:31:50 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bigfloat.h"
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "core/dragon.h"
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
	printf("ft_ldtoa returned '%s'\n", res);
	return (res);
}


static char			*process_exponent(char *val, int expo)
{
	size_t			l;
	size_t			nl;

	l = ft_strlen(val);
	if (expo < 0)
		ft_memmove(val, val - expo + 1, ft_strlen(val - expo));
	nl = ft_strlen(val);
	while (nl < l)
		val[nl++] = 0;
	((char *)ft_memmove(val + 1, val, ft_idxof('.', val)))[0] = '.';
	if (val[ft_idxof('.', val) + 1] == 0)
		val[ft_idxof('.', val) + 1] = '0';
	return (val);
}

static char			*get_exp_hex(long double *d, int *expo, t_bool lng)
{
	t_bflt			two;
	t_bflt			*tmp;
	char			*res;
	long double		lim;

	dbl_abs(d, NULL);
	lim = (lng ? 16.0 : 1.0);
	set_bflt(&two, *d >= lim ? "0.5" : "2.0");
	tmp = new_ftobflt(*d);
	if ((*expo = 0) || *d >= lim)
		while (*d >= (lng ? 16.0 : 2.0) && ++(*expo))
		{
			*d *= 0.5;
			tmp = mul_bflt(tmp, &two);
		}
	else if (*d <= 16.0)
		while ((*d * (long double)(1 + lng)) < lim && --(*expo))
		{
			*d *= 2.0;
			tmp = mul_bflt(tmp, &two);
		}
	unset_bflt(&two);
	res = to_hex(tmp);
	del_bflt(tmp);
	return (res);
}

char				*exp_dbl(long double d, size_t prec)
{
	size_t			xpl;
	char			sign;
	int				expo;
	char			*tmp;
	char			*res;

	if ((sign = 0) || d != d)
		return (ft_strdup("nan"));
	if ((expo = 0) || dbl_abs(&d, &sign) == (1.0 / 0.0))
		return (ft_strdup(sign ? "-inf" : "inf"));
	if (!(tmp = ft_ldtoa2(d)))
		return (NULL);
	while (d != 0.0 && ((d < 1.0 && --expo) || (d >= 10.0 && ++expo)))
		d = (d >= 10.0 ? d / 10.0 : d * 10.0);
	tmp = process_exponent(tmp, expo);
	round_tabflt(tmp, prec, &expo);
	xpl = ft_max(2, ft_unsignedlen(ft_abs(expo)));
	if (!tmp || !(res = ft_memalloc(sign + 2 + prec + 2 + xpl + 1)))
		return ((char *)ft_freturn(tmp, 0x0));
	*res = ft_freturn(NULL + !ft_memset(res + sign, 48, sign + 2 + prec), '-');
	ft_memcpy(res + sign + 2 + prec, (expo < 0 ? "e-" : "e+"), 2);
	ft_strncpy(res + sign, tmp, ft_min(2 + prec, ft_strlen(tmp)));
	while (xpl-- > 0 && (res[sign + 4 + prec + xpl] = ft_abs(expo % 10) + '0'))
		expo = ft_abs(expo / 10);
	return ((char *)ft_freturn(tmp, (long)res));
}

char				*exp_dbl_hex(long double d, int prec, t_bool lng)
{
	int				expo;
	char			sign;
	char			*tmp;
	char			*res;
	size_t			xpl;

	if ((sign = 0) || d != d)
		return (ft_strdup("nan"));
	if ((expo = 0) || dbl_abs(&d, &sign) == (1.0 / 0.0))
		return (ft_strdup(sign ? "-inf" : "inf"));
	tmp = get_exp_hex(&d, &expo, lng);
	if (!tmp || (prec >= 0 && !round_hex(tmp, prec, &expo)))
		return (NULL);
	prec = (prec < 0 ? ft_strlen(tmp) : (size_t)(prec + 2));
	xpl = ft_unsignedlen(ft_abs(expo));
	if (!tmp || !(res = ft_memalloc(sign + 2 + prec + 2 + xpl + 1)))
		return (NULL);
	*res = '-';
	ft_memset(res + sign, '0', 2 + prec + 2 + xpl);
	ft_memcpy(res + sign, "0x", 2);
	ft_memcpy(res + sign + 2, tmp, ft_min(prec + 2, ft_strlen(tmp)));
	ft_memcpy(res + sign + 2 + prec, (expo < 0 ? "p-" : "p+"), 2);
	while (xpl-- > 0 && (res[sign + 4 + prec + xpl] = ft_abs(expo % 10) + '0'))
		expo = ft_abs(expo / 10);
	return (res);
}
