/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:16:59 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/10 15:19:08 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/converter.h"
#include "core/ft_types.h"
#include "libft.h"

static char		*character(t_printf *data, t_arg *arg)
{
	char		v[2];
	char		*res;
	int			tab_len;

	v[1] = 0;
	*v = (char)arg->value;
	if (arg->min_width < 1)
		arg->min_width = 1;
	tab_len = arg->min_width;
	if (!(res = malloc(arg->min_width + 1)))
		return (NULL);
	res[tab_len] = 0;
	ft_memset(res, (arg->flags & F_ZERO) ? '0' : ' ', tab_len);
	tab_len -= ((arg->flags & F_MINS) ? tab_len : 1);
	ft_strncpy(res + tab_len, v, 1);
	return (insert_buffer(data, res, arg->min_width));
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, character},
	{'l', TRUE, wide_character},
	{'\0', FALSE, NULL}
};

char			*convert_char(t_printf *data, t_arg *arg)
{
	int			i;
	long long	prec;
	long long	min;

	min = arg->min_width;
	prec = arg->precision;
	i = get_arg(data, arg->flag_idx, &arg->value);
	i = (i || (arg->min_width_idx && get_arg(data, arg->min_width_idx, &min)));
	if (i || (arg->precision_idx && get_arg(data, arg->precision_idx, &prec)))
		return (NULL);
	i = 0;
	arg->min_width = (((int)min) < 0 ? 1 : (int)min);
	if ((arg->precision = (((int)prec) < 0 ? 1 : (int)prec))
		|| (arg->flags & F_MINS))
		arg->flags &= ~F_ZERO;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
