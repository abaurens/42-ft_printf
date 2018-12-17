/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floating_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:39:57 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/17 21:39:40 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_types.h"
#include "libft.h"
#include <float.h>

/*
**	SEEEEEEE
**	EMMMMMMM
**	MMMMMMMM
**	MMMMMMMM
*/
/*
**	1
**	0000000000
**	00000000000000000000000000000000000000000000000000000
**
**	0
**	0000000000
**	00000000000000000000000000000000000000000000000000000
*/

/*
**	FLT_RADIX = the coding base
**	DBL_MAX_EXP = the maximum value in the exponent (FLT_RADIX^X = DBL_MAX_EXP)
**	(X is the number of digits used in base FLT_RADIX in the exponent).
**	DBL_MANT_DIG = the number of digits in the mantissa in base FLT_RADIX
**
**	X + DBL_MANT_DIG + 1 = number of bits used in the double.
**
**	ex (double):
**		FLT_RADIX = 2
**		DBL_MANT_DIG = 53
**		DBL_MAX_EXP = 1024
**		X = 10 (2^10 = 1024)
**		53 + 10 + 1 = 63 + 1 = 64 <= (8 * 8) = 8 bytes
**
**	ex2 (long double):
**		FLT_RADIX = 2
**		DBL_MANT_DIG = 64
**		DBL_MAX_EXP = 16384
**		X = 14; (2^14 = 16384)
**		64 + 14 + 1 = 78 + 1 = 79 <= (16 * 8 (128)) = 16 bytes
**		(49 bits should be left unused)
**
**
**   o FLT_RADIX == 2: binary encoding
**   o DBL_MAX_EXP == 1024: 11 bits exponent, where one bit is used
**     to indicate special numbers (e.g. NaN and Infinity), so the
**     maximum exponent is 10 bits wide (2^10 == 1024).
**   o DBL_MANT_DIG == 53: The mantissa is 52 bits wide, but because
**     numbers are normalized the initial binary 1 is represented
**     implicitly (the so-called "hidden bit"), which leaves us with
**     the ability to represent 53 bits wide mantissa.
**
**		0000000000000000000000000000000000000000000000000
00000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000
*/

t_float				get_float_components(t_ft_dbl d)
{
	t_float			ret;
	t_ldbl			test;
	/*
	int				exp_ln;
	int				man_ln;
	int				exponent_max;
	t_float_conv	conv;

	exp_ln = -1;
	ft_bzero(&conv, sizeof(conv));
	conv.value = d;
	man_ln = LDBL_MANT_DIG;
	exponent_max = LDBL_MAX_EXP;
	while (exponent_max != 0 && (++exp_ln || 1))
		exponent_max /= 2;
	*/
	test.d = d;
	ft_bzero(&ret, sizeof(ret));
	ft_printf("negative : %d\n", test.dta_nan.negative);
	/*
	printf("d            = %Lf\n", d);
	printf("sizeof(d)    = %lu\n", sizeof(d));
	printf("bits in d    = %lu\n\n", sizeof(d) * 8);
	printf("FLT_RADIX    = %d\n", FLT_RADIX);
	printf("DBL_MAX_EXP  = %d\n", LDBL_MAX_EXP);
	printf("DBL_MANT_DIG = %d\n", LDBL_MANT_DIG);
	printf("exponent len = %d\n", exp_ln);
	printf("total used   = %d\n", exp_ln + man_ln + 1);

	exponent_max = sizeof(d) * 8;
	/*while (exponent_max < (exp_ln + man_ln + 1))
		exponent_max *= 2;*//*
	printf("requiered bits : %d\n", exponent_max);
	printf("\n");
	exponent_max -= (exp_ln + man_ln + 1);
	while (exponent_max > 0)
	{
		printf("0");
		exponent_max--;
		if (!exponent_max)
			printf("");
	}
	printf("1");
	while (exp_ln)
	{
		printf("0");
		exp_ln--;
	}
	printf("");
	while (man_ln)
	{
		printf("0");
		man_ln--;
	}
	printf("\n");
	while (man_ln < (int)sizeof(d))
	{
		ft_printf("%.8b", conv.bytes[sizeof(d) - (man_ln + 1)]);
		man_ln++;
	}
	ft_printf("\n");*/
	return (ret);
}
