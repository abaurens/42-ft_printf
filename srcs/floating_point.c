/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floating_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:39:57 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/04 18:51:37 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include <stdlib.h>
#include "ft_bigfloat.h"
#include "ft_printf.h"
#include "ft_types.h"
#include "libft.h"

static const char				*g_man_vals[] =
{
	"1.0",
	"0.5",
	"0.25",
	"0.125",
	"0.0625",
	"0.03125",
	"0.015625",
	"0.0078125",
	"0.00390625",
	"0.001953125",
	"0.0009765625",
	"0.00048828125",
	"0.000244140625",
	"0.0001220703125",
	"0.00006103515625",
	"0.000030517578125",
	"0.0000152587890625",
	"0.00000762939453125",
	"0.000003814697265625",
	"0.0000019073486328125",
	"0.00000095367431640625",
	"0.000000476837158203125",
	"0.0000002384185791015625",
	"0.00000011920928955078125",
	"0.000000059604644775390625",
	"0.0000000298023223876953125",
	"0.00000001490116119384765625",
	"0.000000007450580596923828125",
	"0.0000000037252902984619140625",
	"0.00000000186264514923095703125",
	"0.000000000931322574615478515625",
	"0.0000000004656612873077392578125",
	"0.00000000023283064365386962890625",
	"0.000000000116415321826934814453125",
	"0.0000000000582076609134674072265625",
	"0.00000000002910383045673370361328125",
	"0.000000000014551915228366851806640625",
	"0.0000000000072759576141834259033203125",
	"0.00000000000363797880709171295166015625",
	"0.000000000001818989403545856475830078125",
	"0.0000000000009094947017729282379150390625",
	"0.00000000000045474735088646411895751953125",
	"0.000000000000227373675443232059478759765625",
	"0.0000000000001136868377216160297393798828125",
	"0.00000000000005684341886080801486968994140625",
	"0.000000000000028421709430404007434844970703125",
	"0.0000000000000142108547152020037174224853515625",
	"0.00000000000000710542735760100185871124267578125",
	"0.000000000000003552713678800500929355621337890625",
	"0.0000000000000017763568394002504646778106689453125",
	"0.00000000000000088817841970012523233890533447265625",
	"0.000000000000000444089209850062616169452667236328125",
	"0.0000000000000002220446049250313080847263336181640625",
	"0.00000000000000011102230246251565404236316680908203125",
	"0.000000000000000055511151231257827021181583404541015625",
	"0.0000000000000000277555756156289135105907917022705078125",
	"0.00000000000000001387778780781445675529539585113525390625",
	"0.000000000000000006938893903907228377647697925567626953125",
	"0.0000000000000000034694469519536141888238489627838134765625",
	"0.00000000000000000173472347597680709441192448139190673828125",
	"0.000000000000000000867361737988403547205962240695953369140625",
	"0.0000000000000000004336808689942017736029811203479766845703125",
	"0.00000000000000000021684043449710088680149056017398834228515625",
	"0.000000000000000000108420217248550443400745280086994171142578125",
	NULL
};

t_bflt				*get_mantissa(t_float *f)
{
	int				i;
	t_bflt			expo;
	t_bflt			*tmp;
	t_bflt			*mant;

	i = 0;
	mant = new_bflt("0");
	ft_bzero(&expo, sizeof(t_bflt));
	while (mant && i < LDBL_MANT_DIG)
	{
		if (!((f->mantissa >> (LDBL_MANT_DIG - ++i)) & 0b1))
			continue ;
		tmp = mant;
		if (set_bflt(&expo, g_man_vals[i - 1]))
		{
			mant = add_bflt(&expo, mant);
			del_bflt(tmp);
			unset_bflt(&expo);
		}
	}
	return (mant);
}

t_float				get_float_components(long double d)
{
	t_float			ret;
	t_float_conv	conv;
	int				exp_ln;
	int				man_ln;

	exp_ln = 0;
	ft_bzero(&conv, sizeof(conv));
	conv.value = d;
	man_ln = LDBL_MAX_EXP;
	while (man_ln != 0 && ++exp_ln)
		man_ln >>= 1;
	man_ln = LDBL_MANT_DIG - (sizeof(d) == sizeof(double));
	ft_memcpy(&ret.mantissa, conv.bytes, man_ln / 8);
	ret.exponent = *((unsigned short *)(conv.bytes + (man_ln / 8)));
	ret.sign = ret.exponent >> exp_ln;
	ret.exponent &= ~(1 << exp_ln);
	if (d != 0.0 && d != -0.0)
		ret.exponent -= (LDBL_MAX_EXP - 1);
	return (ret);
}

long double			dbl_abs(long double *d, char *sign)
{
	char			s;

	if (d && (s = get_float_components(*d).sign))
		*d = -*d;
	if (d && sign)
		*sign = s;
	return (d ? *d : 0.0 / 0.0);
}

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
	((char *)ft_memmove(tmp + 1, tmp, ft_idxof('.', tmp)))[0] = '.';
	while (d != 0.0 && ((d < 1.0 && --exp) || (d >= 10.0 && ++exp)))
		d = (d >= 10.0 ? d / 10.0 : d * 10.0);
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
