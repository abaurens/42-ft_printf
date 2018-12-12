/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:20:02 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/12 23:47:00 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/ft_printf.h"
#include "../../includes/ft_types.h"
#include "../../includes/debug.h"
#include "libft.h"

# define MAX(x, y) ((x) > (y) ? (x) : (y))

static void		integer(t_printf *const data, t_arg *const arg)
{
	int			v;
	int			i;
	char		*tmp;
	char		buf[12];

	v = (int)arg->value;
	ft_bzero(buf, 12);
	i = MAX(ft_numlen(v), (size_t)arg->precision);
	while (--i >= 0)
	{
		buf[i] = (v % 10) + '0';
		v /= 10;
	}
	tmp = data->buf;
	data->buf = ft_strmcat(data->buf, buf, -1);
	free(tmp);
}

static void		long_integer(t_printf *const data, t_arg *const arg)
{
	long int	v;

	v = (long int)arg->value;
	UNUSED(data);
	UNUSED(arg);
	printf("%ld", v);
	fflush(stdout);
}

static void		long_long_integer(t_printf *const data, t_arg *const arg)
{
	UNUSED(data);
	UNUSED(arg);
	printf("%lld", arg->value);
	fflush(stdout);
}

static void		short_integer(t_printf *const data, t_arg *const arg)
{
	short int	v;

	v = (short int)arg->value;
	UNUSED(data);
	UNUSED(arg);
	printf("%hd", v);
	fflush(stdout);
}

static void		short_short_integer(t_printf *const data, t_arg *const arg)
{
	signed char	v;

	v = (signed char)arg->value;
	UNUSED(data);
	UNUSED(arg);
	printf("%hhd", v);
	fflush(stdout);
}

static void		intmax_integer(t_printf *const data, t_arg *const arg)
{
	intmax_t	v;

	v = (intmax_t)arg->value;
	UNUSED(data);
	UNUSED(arg);
	printf("%jd", v);
	fflush(stdout);
}

static void		size_integer(t_printf *const data, t_arg *const arg)
{
	size_t	v;

	v = (size_t)arg->value;
	UNUSED(data);
	UNUSED(arg);
	printf("%zd", v);
	fflush(stdout);
}

static void		ptrdiff_integer(t_printf *const data, t_arg *const arg)
{
	ptrdiff_t	v;

	v = (ptrdiff_t)arg->value;
	UNUSED(data);
	UNUSED(arg);
	printf("%td", v);
	fflush(stdout);
}

static const t_converter	funcs[] =
{
	{'H', TRUE, short_short_integer},
	{'h', TRUE, short_integer},
	{' ', TRUE, integer},
	{'j', TRUE, intmax_integer},
	{'l', TRUE, long_integer},
	{'L', TRUE, long_long_integer},
	{'z', TRUE, size_integer},
	{'t', TRUE, ptrdiff_integer},
	{'\0', FALSE, NULL}
};

void			convert_integer(t_printf *const data, t_arg *const arg)
{
	int			i;
	long long	prec;
	long long	min;

	min = 0;
	prec = 0;
	i = get_arg(data, arg->flag_idx, &arg->value);
	i = (i || (arg->min_width_idx && get_arg(data, arg->min_width_idx, &min)));
	if (i || (arg->precision_idx && get_arg(data, arg->precision_idx, &prec)))
		return ;
	i = 0;
	arg->min_width = (((int)min) < 0 ? 0 : (int)min);
	arg->precision = (((int)prec) < 0 ? 0 : (int)prec);
	/*print_arg_data(arg, data->use_chain_format);*/
	while (funcs[i].c && funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	funcs[i].func(data, arg);
}
