/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:31:35 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/13 17:14:11 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

char					*wide_character(t_printf *data, t_arg *arg)
{
	wchar_t				v[2];
	char				*res;
	int					len;
	int					tab_len;

	v[1] = 0;
	*v = (wchar_t)arg->value;
	len = ft_wchar_len(*v);
	if ((tab_len = arg->min_width) < len)
		tab_len = len;
	if (!(res = ft_memalloc(tab_len + 1)))
		return (NULL);
	ft_memset(res, (arg->flags & F_ZERO) ? '0' : ' ', tab_len);
	len = tab_len - len;
	if ((arg->flags & F_MINS))
		len = 0;
	ft_wstrtostr(res + len, v);
	insert_buffer(data, res, tab_len);
	free(res);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, wide_character},
	{'\0', FALSE, NULL}
};

char					*convert_wide_char(t_printf *data, t_arg *arg)
{
	int					i;
	long long			prec;
	long long			min;

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
