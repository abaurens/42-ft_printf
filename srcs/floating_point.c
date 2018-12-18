/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floating_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:39:57 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/18 22:36:43 by abaurens         ###   ########.fr       */
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

/*
**	m*b^e
**
**	m = mantissa
**	b = RADIX (base)
**	e = exponent
**
**	3*2^1
**
**	bits in mantissa are equals to :
**	2^0, 2^-1, 2^-2, 2^-3, 2^-4, ..., 2^-man_ln
**	 ^-- this value is only in the mantissa part with long double.
*/

void					print_double_binary(long double d)
{
	int					i;
	int					exp_ln;
	int					man_ln;
	int					exponent_max;
	t_float_conv		conv;

	exp_ln = 0;
	ft_bzero(&conv, sizeof(conv));
	conv.value = d;
	man_ln = LDBL_MANT_DIG - (sizeof(d) == sizeof(double));
	exponent_max = LDBL_MAX_EXP;
	while (exponent_max != 0 && (++exp_ln || 1))
		exponent_max /= 2;
	printf("d            = %Lf\n", (long double)d);
	printf("sizeof(d)    = %lu\n", sizeof(d));
	printf("bits in d    = %lu\n\n", sizeof(d) * 8);
	printf("FLT_RADIX    = %d\n", FLT_RADIX);
	printf("DBL_MAX_EXP  = %d\n", LDBL_MAX_EXP);
	printf("DBL_MANT_DIG = %d\n", LDBL_MANT_DIG);
	printf("exponent len = %d\n", exp_ln);
	printf("total used   = %d\n", exp_ln + man_ln + 1);
	exponent_max = sizeof(d) * 8;
	printf("requiered bits : %d\n", exponent_max);
	exponent_max -= (exp_ln + man_ln + 1);
	i = 0;
	while (i < (int)sizeof(d) && !conv.bytes[sizeof(d) - (i + 1)])
		i++;
	while (++i <= (int)sizeof(d))
		ft_printf("%.8b ", conv.bytes[sizeof(d) - i]);
	ft_printf("\n");
	printf("\n");
	printf("S ");
	i = -1;
	while (++i < exp_ln)
		printf("E");
	printf(" ");
	i = -1;
	while (++i < man_ln)
		printf("M");
	printf("\n");
}

static const char				*g_mantissa_values[] =
{
	"5",
	"25",
	"125",
	"0625",
	"03125",
	"015625",
	"0078125",
	"00390625",
	"001953125",
	"0009765625",
	"00048828125",
	"000244140625",
	"0001220703125",
	"00006103515625",
	"000030517578125",
	"0000152587890625",
	"00000762939453125",
	"000003814697265625",
	"0000019073486328125",
	"00000095367431640625",
	"000000476837158203125",
	"0000002384185791015625",
	"00000011920928955078125",
	"000000059604644775390625",
	"0000000298023223876953125",
	"00000001490116119384765625",
	"000000007450580596923828125",
	"0000000037252902984619140625",
	"00000000186264514923095703125",
	"000000000931322574615478515625",
	"0000000004656612873077392578125",
	"00000000023283064365386962890625",
	"000000000116415321826934814453125",
	"0000000000582076609134674072265625",
	"00000000002910383045673370361328125",
	"000000000014551915228366851806640625",
	"0000000000072759576141834259033203125",
	"00000000000363797880709171295166015625",
	"000000000001818989403545856475830078125",
	"0000000000009094947017729282379150390625",
	"00000000000045474735088646411895751953125",
	"000000000000227373675443232059478759765625",
	"0000000000001136868377216160297393798828125",
	"00000000000005684341886080801486968994140625",
	"000000000000028421709430404007434844970703125",
	"0000000000000142108547152020037174224853515625",
	"00000000000000710542735760100185871124267578125",
	"000000000000003552713678800500929355621337890625",
	"0000000000000017763568394002504646778106689453125",
	"00000000000000088817841970012523233890533447265625",
	"000000000000000444089209850062616169452667236328125",
	"0000000000000002220446049250313080847263336181640625",
	"00000000000000011102230246251565404236316680908203125",
	"000000000000000055511151231257827021181583404541015625",
	"0000000000000000277555756156289135105907917022705078125",
	"00000000000000001387778780781445675529539585113525390625",
	"000000000000000006938893903907228377647697925567626953125",
	"0000000000000000034694469519536141888238489627838134765625",
	"00000000000000000173472347597680709441192448139190673828125",
	"000000000000000000867361737988403547205962240695953369140625",
	"0000000000000000004336808689942017736029811203479766845703125",
	"00000000000000000021684043449710088680149056017398834228515625",
	"000000000000000000108420217248550443400745280086994171142578125",
	"0000000000000000000542101086242752217003726400434970855712890625",
	NULL
};

t_float					get_float_components(t_ft_dbl d)
{
	t_float				ret;
	t_float_conv		conv;
	int					exp_ln;
	int					man_ln;
	unsigned long int	mantissa;
	unsigned char		negative;
	int					exponent;

	exp_ln = 0;
	/*print_double_binary(d);*/
	ft_bzero(&conv, sizeof(conv));
	conv.value = d;
	man_ln = LDBL_MAX_EXP;
	while (man_ln != 0 && ++exp_ln)
		man_ln >>= 1;
	man_ln = LDBL_MANT_DIG - (sizeof(d) == sizeof(double));
	ft_memcpy(&mantissa, conv.bytes, man_ln / 8);
	exponent = *((unsigned short *)(conv.bytes + (man_ln / 8)));
	negative = exponent >> exp_ln;
	exponent &= ~(1 << exp_ln);
	ft_printf("%.1b %.15b %.*lb\n", negative, exponent, man_ln, mantissa);
	/*printf("%L.4938e\n", d);*/
	int i;
	char *t = malloc(2);
	ft_memcpy(t, "0", 2);
	for (i = 1; g_mantissa_values[i]; ++i)
	{
		if (((mantissa >> (63 - i)) & 0b1))
		{
			/*ft_printf("%.*lb\n", man_ln, (mantissa >> (63 - i)));*/
			t = (char *)ft_freturn(t, (long long)bignum_add_dot(t, g_mantissa_values[i - 1]));
			/*printf("adding (%d)%s\n", i, g_mantissa_values[i - 1]);*/
		}
	}
	printf("1.%s * %d^%d\n", t, FLT_RADIX, exponent - (LDBL_MAX_EXP - 1));
	return (ret);
}

void					print_float(t_ft_dbl d)
{
	;
}
