/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:20:02 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/17 19:44:03 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "integer.h"
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

static char		*integer(t_printf *const data, t_arg *const ar)
{
	int			v;
	size_t		l;
	char		*tab;

	v = (int)ar->value;
	if ((l = (ft_numlen(v) - (v < 0))) > (size_t)ar->prec)
		ar->prec = l;
	if (flag(ar, (F_PLUS | F_SPAC)) && v >= 0 && ++l)
		ar->prec++;
	if ((l + (v < 0)) > (size_t)ar->min)
		ar->min = l + (v < 0);
	if (flag(ar, F_ZERO) && ar->prec < ar->min)
		ar->prec = ar->min - (v < 0);
	if (!(tab = padded_lltoa(v, ar->prec, ar->min, flag(ar, F_MINS))))
		return (NULL);
	if (flag(ar, (F_PLUS | F_SPAC)) && (int)ar->value >= 0)
		tab[ft_idxof('0', tab)] = flag(ar, F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{'H', TRUE, short_short_integer},
	{'h', TRUE, short_integer},
	{' ', TRUE, integer},
	{'j', TRUE, intmax_integer},
	{'l', TRUE, long_integer},
	{'L', TRUE, long_long_integer},
	{'q', TRUE, quad_integer},
	{'z', TRUE, size_integer},
	{'Z', TRUE, ssize_integer},
	{'t', TRUE, ptrdiff_integer},
	{'\0', FALSE, NULL}
};

char			*convert_integer(t_printf *const data, t_arg *const arg)
{
	int			i;
	long long	prec;
	long long	min;

	min = arg->min;
	prec = arg->prec;
	i = (get_arg(data, arg->flag_idx, &arg->value));
	i = (i || (arg->min_idx && get_arg(data, arg->min_idx, &min)));
	if (i || (arg->prec_idx && get_arg(data, arg->prec_idx, &prec)))
		return (NULL);
	i = 0;
	arg->min = (((int)min) < 0 ? 0 : (int)min);
	if ((arg->prec = (((int)prec) < 0 ? 0 : (int)prec)) || flag(arg, F_MINS))
		arg->flags &= ~F_ZERO;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}

char			*convert_linteger(t_printf *const data, t_arg *const arg)
{
	arg->conv.c = 'd';
	arg->length_modifier = ft_idxof('l', LEN_MD_CHRS);
	return (convert_integer(data, arg));
}
