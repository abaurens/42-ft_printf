/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:17:28 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/18 19:23:22 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "length.h"
#include "core/ft_core.h"
#include "core/ft_types.h"

static char		*length(t_printf *const data, t_arg *const arg)
{
	int			*v;

	v = (int *)arg->val.p;
	*v = data->len;
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{'H', TRUE, short_short_length},
	{'h', TRUE, short_length},
	{' ', TRUE, length},
	{'j', TRUE, intmax_length},
	{'l', TRUE, long_length},
	{'L', TRUE, long_long_length},
	{'q', TRUE, quad_length},
	{'z', TRUE, size_length},
	{'Z', TRUE, ssize_length},
	{'t', TRUE, ptrdiff_length},
	{'\0', FALSE, NULL}
};

char			*convert_length(t_printf *data, t_arg *arg)
{
	int			i;

	i = 0;
	if (get_arg_a(data, arg->flag_idx, arg))
		return (NULL);
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
