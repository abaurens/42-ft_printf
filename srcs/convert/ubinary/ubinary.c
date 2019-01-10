/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ubinary.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:40:26 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/10 15:54:02 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ubinary.h"
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

static char			*binary(t_printf *const data, t_arg *const arg)
{
	unsigned int	v;
	char			*tab;
	int				len;

	v = (unsigned int)arg->value;
	if ((len = ft_unsignedlen_base(v, "01")) > arg->precision)
		arg->precision = len;
	if (arg->flags & F_ZERO && arg->min_width > arg->precision)
		arg->precision = arg->min_width;
	if ((arg->flags & F_HASH) && v != 0 && arg->precision < (len + 2))
		arg->precision += ((len + 2) - arg->precision);
	if (!(tab = padded_ulltoa_bin(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & F_HASH) && v != 0)
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
