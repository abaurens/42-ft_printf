/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:44:53 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/28 21:48:58 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "core/ft_types.h"
#include "core/ft_core.h"
#include "core/dragon.h"

static size_t	add_digit(char **buffer, const size_t l, const char c)
{
	size_t		i;
	size_t		nl;
	char		*new;

	if (!buffer)
		return (0);
	i = l ? l : 32;
	nl = *buffer ? strlen(*buffer) : 0;
	if (nl + 1 >= l)
	{
		i <<= 1;
		if (!(new = malloc(i)))
			return (0);
		memcpy(new, *buffer, nl);
		free(*buffer);
		*buffer = new;
	}
	(*buffer)[nl] = c;
	(*buffer)[nl + 1] = 0;
	return (i);
}

static long		get_fdig(long double d)
{
	long		r;

	r = 0;
	if (d < 0.0)
		d = -d;
	if (d == 0.0)
		return (0);
	if (d < 1.0)
		while (d < 1.0 && --r)
			d *= 10.0;
	else if (d >= 10.0)
		while (d >= 10.0 && ++r)
			d /= 10.0;
	return (r);
}

static int		dragon_prepare(long fdig, t_float *fc, t_bint *num, t_bint *den)
{
	int			i;
	i = 0;
	bi_set(den, 1);
	bi_set(num, fc->mantissa);
	if (fc->exponent > 0)
		bi_shift_left(num, fc->exponent);
	else
		bi_shift_left(den, -fc->exponent);
	if (fdig > 0)
		bimul_pow10(den, den, fdig);
	else if (fdig < 0 && ((i = -(fdig - 1)) || 1))
		bimul_pow10(num, num, -fdig);
	return (i);
}

static size_t		dragon_finish(char **res, size_t len, long fdig)
{
	if ((fdig > 0 ? (fdig + 1) : 1) < len)
		res[fdig > 0 ? (fdig + 1) : 1] = '.';
	else
		len = add_digit(res, len, '.');
	return (len);
}

static size_t		dragon4(char **res, long fdig, t_float *fc)
{
	int				i;
	size_t			len;
	t_bint			num;
	t_bint			den;

	len = 0;
	*res = NULL;
	i = dragon_prepare(fdig, fc, &num, &den);
	while (bicmplng(&num, 0) > 0 && ++i)
	{
		if ((i - 1) != (fdig + 2))
		{
			len = add_digit(&res, len, '0' + bidiv_maxq92(&num, &den));
			bimul10(&num, &num);
		}
		else
			add_digit(&res, len, '0');
	}
	while (i - 1 <= fdig && ++i)
		len = add_digit(res, len, '0');
	if ((fdig > 0 ? (fdig + 1) : 1) < len)
		res[fdig > 0 ? (fdig + 1) : 1] = '.';
	else
		len = add_digit(res, len, '.');
	return (dragon_finish(res, len, fdig));
}

char			*ft_ldtoa2(long double d)
{
	t_float			fc;
	char			sign;
	char			*res;
	long			fdig;
	size_t			l;

	res = NULL;
	fc = get_float_components(d);
	fc.exponent -= (LDBL_MANT_DIG - 1);
	if ((sign = fc.sign))
		d = -d;
	l = dragon4(&res, get_fdig((long double)d), &fc);
	if (strchr(res, '.') != NULL && *((char *)strchr(res, '.') + 1) == 0)
		add_digit(&res, l, '0');
	return (res);
}
