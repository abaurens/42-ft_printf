/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:16:59 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/18 19:22:28 by abaurens         ###   ########.fr       */
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
	*v = (char)arg->val.i;
	if (arg->min < 1)
		arg->min = 1;
	tab_len = arg->min;
	if (!(res = malloc(arg->min + 1)))
		return (NULL);
	res[tab_len] = 0;
	ft_memset(res, flag(arg, F_ZERO) ? '0' : ' ', tab_len);
	tab_len -= (flag(arg, F_MINS) ? tab_len : 1);
	ft_strncpy(res + tab_len, v, 1);
	return (insert_buffer(data, res, arg->min));
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
	int			prec;
	int			min;

	min = arg->min;
	prec = arg->prec;
	i = get_arg_a(data, arg->flag_idx, arg);
	i = (i || (arg->min_idx && get_arg_i(data, arg->min_idx, &min)));
	if (i || (arg->prec_idx && get_arg_i(data, arg->prec_idx, &prec)))
		return (NULL);
	i = 0;
	arg->min = (((int)min) < 0 ? 1 : (int)min);
	if ((arg->prec = (((int)prec) < 0 ? 1 : (int)prec)) || flag(arg, F_MINS))
		arg->flags &= ~F_ZERO;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
