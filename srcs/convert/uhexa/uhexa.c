/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uhexa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:26:04 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/13 17:00:30 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"
#include "uhexa.h"

static char			*hexa(t_printf *const data, t_arg *const arg)
{
	unsigned int	v;
	int				len;
	char			*tab;

	v = (unsigned int)arg->value;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->precision)
		arg->precision = len;
	if ((arg->flags & F_HASH) && v != 0)
		arg->precision += 2;
	if (arg->flags & F_ZERO && arg->min_width > arg->precision)
		arg->precision = arg->min_width;
	if (!(tab = padded_ulltoa_hexa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{'H', TRUE, short_short_hexa},
	{'h', TRUE, short_hexa},
	{' ', TRUE, hexa},
	{'j', TRUE, intmax_hexa},
	{'l', TRUE, long_hexa},
	{'L', TRUE, long_long_hexa},
	{'q', TRUE, quad_hexa},
	{'z', TRUE, size_hexa},
	{'Z', TRUE, ssize_hexa},
	{'t', TRUE, ptrdiff_hexa},
	{'\0', FALSE, NULL}
};

char				*convert_u_integer_hexa(t_printf *data, t_arg *arg)
{
	int				i;
	long long		min;
	long long		prec;

	min = arg->min_width;
	prec = arg->precision;
	i = get_arg(data, arg->flag_idx, &arg->value);
	i = (i || (arg->min_width_idx && get_arg(data, arg->min_width_idx, &min)));
	if (i || (arg->precision_idx && get_arg(data, arg->precision_idx, &prec)))
		return (NULL);
	arg->min_width = (((int)min) < 0 ? 0 : (int)min);
	if ((arg->precision = (((int)prec) < 0 ? 0 : (int)prec))
		|| (arg->flags & F_MINS))
		arg->flags &= ~F_ZERO;
	i = 0;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
