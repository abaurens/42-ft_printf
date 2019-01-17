/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uoctal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 21:02:59 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/17 19:43:42 by abaurens         ###   ########.fr       */
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
	if ((len = ft_unsignedlen_base(v, "01234567")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH && v != 0 && arg->prec <= len))
		arg->prec++;
	if (!(tab = padded_ulltoa_octal(v, arg->prec, arg->min, flag(arg, F_MINS))))
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

	min = arg->min;
	prec = arg->prec;
	i = get_arg(data, arg->flag_idx, &arg->value);
	i = (i || (arg->min_idx && get_arg(data, arg->min_idx, &min)));
	if (i || (arg->prec_idx && get_arg(data, arg->prec_idx, &prec)))
		return (NULL);
	i = 0;
	arg->min = (((int)min) < 0 ? 0 : (int)min);
	if ((arg->prec = (((int)prec) < 0 ? 0 : (int)prec))
		|| flag(arg, F_MINS))
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
