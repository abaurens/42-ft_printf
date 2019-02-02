/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:31:35 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/02 17:33:44 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_types.h"
#include "core/ft_core.h"
#include "core/libft.h"

/*
static char		*wide_character(t_printf *data, t_arg *arg)
{
	return (wide_char(data, arg));
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, wide_character},
	{'\0', FALSE, NULL}
};

char			*convert_wide_char(t_printf *data, t_arg *arg)
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
	arg->min = (((int)min) < 0 ? 0 : (int)min);
	if ((arg->prec = (((int)prec) < 0 ? 0 : (int)prec)) || flag(arg, F_MINS))
		arg->flags &= ~F_ZERO;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
*/
