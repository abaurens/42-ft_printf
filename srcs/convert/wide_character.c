/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:31:35 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/06 22:45:02 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "ft_types.h"
#include "converter.h"
#include "libft.h"

char					*wide_character(t_printf *data, t_arg *arg)
{
	wchar_t				v[2];
	char				*res;
	int					len;
	size_t				wchr_ln;
	int					tab_len;

	v[1] = 0;
	wchr_ln = sizeof(wchar_t);
	if (!(*v = (wchar_t)arg->value))
		return (data->buf);
	if ((len = ft_wstrlen(v)) > arg->precision && arg->precision)
		len = arg->precision;
	if ((tab_len = arg->min_width) < len)
		tab_len = len;
	if (!(res = ft_memalloc(tab_len + 1)))
		return (NULL);
	ft_memset(res, (arg->flags & F_ZERO) ? '0' : ' ', tab_len);
	tab_len -= ((arg->flags & F_MINS) ? tab_len : len);
	ft_wstrtostr(res + tab_len, v);
	insert_buffer(data, res, ft_strlen(res));
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
