/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uoctal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 21:02:59 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/13 16:17:50 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "uoctal.h"
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

static char			*uoctal(t_printf *const data, t_arg *const arg)
{
	unsigned int	v;
	char			*tab;
	int				len;

	v = (unsigned int)arg->value;
	if ((len = ft_unsignedlen_base(v, "01234567")) > arg->precision)
		arg->precision = len;
	if (arg->flags & F_ZERO && arg->min_width > arg->precision)
		arg->precision = arg->min_width;
	if (arg->flags & F_HASH && v != 0 && arg->precision <= len)
		arg->precision++;
	if (!(tab = padded_ulltoa_octal(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{'H', TRUE, short_short_uoctal},
	{'h', TRUE, short_uoctal},
	{' ', TRUE, uoctal},
	{'j', TRUE, intmax_uoctal},
	{'l', TRUE, long_uoctal},
	{'L', TRUE, long_long_uoctal},
	{'q', TRUE, quad_uoctal},
	{'z', TRUE, size_uoctal},
	{'Z', TRUE, ssize_uoctal},
	{'t', TRUE, ptrdiff_uoctal},
	{'\0', FALSE, NULL}
};

char				*convert_u_integer_octal(t_printf *data, t_arg *arg)
{
	int				i;
	long long		prec;
	long long		min;

	min = arg->min_width;
	prec = arg->precision;
	i = get_arg(data, arg->flag_idx, &arg->value);
	i = (i || (arg->min_width_idx && get_arg(data, arg->min_width_idx, &min)));
	if (i || (arg->precision_idx && get_arg(data, arg->precision_idx, &prec)))
		return (NULL);
	i = 0;
	arg->min_width = (((int)min) < 0 ? 0 : (int)min);
	if ((arg->precision = (((int)prec) < 0 ? 0 : (int)prec))
		|| (arg->flags & F_MINS))
		arg->flags &= ~F_ZERO;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}

char			*convert_u_linteger_octal(t_printf *data, t_arg *arg)
{
	arg->conv.c = 'o';
	arg->length_modifier = ft_idxof('l', LEN_MD_CHRS);
	return (convert_u_integer_octal(data, arg));
}
