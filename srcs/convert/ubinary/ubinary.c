/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ubinary.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:40:26 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/18 19:26:40 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ubinary.h"
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "core/libft.h"

static char			*binary(t_printf *const data, t_arg *const arg)
{
	unsigned int	v;
	char			*tab;
	int				len;

	v = (unsigned int)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "01")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH) && v != 0 && arg->prec < (len + 2))
		arg->prec += ((len + 2) - arg->prec);
	if (!(tab = padded_ulltoa_bin(v, arg->prec, arg->min,
		flag(arg, F_MINS) != 0)))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'b';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{'H', TRUE, short_short_binary},
	{'h', TRUE, short_binary},
	{' ', TRUE, binary},
	{'j', TRUE, intmax_binary},
	{'l', TRUE, long_binary},
	{'L', TRUE, long_long_binary},
	{'q', TRUE, quad_binary},
	{'z', TRUE, size_binary},
	{'Z', TRUE, ssize_binary},
	{'t', TRUE, ptrdiff_binary},
	{'\0', FALSE, NULL}
};

char				*convert_u_integer_binary(t_printf *data, t_arg *arg)
{
	int				i;
	int				prec;
	int				min;

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
