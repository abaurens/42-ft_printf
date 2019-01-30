/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uinteger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:25:04 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/18 19:38:52 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "uinteger.h"
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "core/libft.h"

static char			*uinteger(t_printf *const data, t_arg *const arg)
{
	unsigned int	v;
	char			*tab;

	v = (unsigned int)arg->val.i;
	if (flag(arg, F_ZERO))
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{'H', TRUE, short_short_uinteger},
	{'h', TRUE, short_uinteger},
	{' ', TRUE, uinteger},
	{'j', TRUE, intmax_uinteger},
	{'l', TRUE, long_uinteger},
	{'L', TRUE, long_long_uinteger},
	{'q', TRUE, quad_uinteger},
	{'z', TRUE, size_uinteger},
	{'Z', TRUE, ssize_uinteger},
	{'t', TRUE, ptrdiff_uinteger},
	{'\0', FALSE, NULL}
};

char				*convert_u_integer(t_printf *data, t_arg *arg)
{
	int				i;
	int				min;
	int				prec;

	min = arg->min;
	prec = arg->prec;
	i = get_arg_a(data, arg->flag_idx, arg);
	i = (i || (arg->min_idx && get_arg_i(data, arg->min_idx, &min)));
	if (i || (arg->prec_idx && get_arg_i(data, arg->prec_idx, &prec)))
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

char				*convert_u_linteger(t_printf *data, t_arg *arg)
{
	arg->conv.c = 'u';
	arg->length_modifier = ft_idxof('l', LEN_MD_CHRS);
	return (convert_u_integer(data, arg));
}
