/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:16:59 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/14 20:03:48 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "converter.h"
#include "ft_types.h"
#include "libft.h"

static char		*character(t_printf *data, t_arg *arg)
{
	char		v[2];
	char		*res;
	int			len;
	int			tab_len;

	v[1] = 0;
	if (!(*v = (char)arg->value))
		return (data->buf);
	if ((len = 1) > arg->precision && arg->precision)
		len = arg->precision;
	if ((tab_len = arg->min_width) && tab_len < len)
		tab_len = len;
	if (!(res = malloc(tab_len + 1)))
		return (NULL);
	res[tab_len] = 0;
	ft_memset(res, (arg->flags & F_ZERO) ? '0' : ' ', tab_len);
	tab_len -= ((arg->flags & F_MINS) ? tab_len : len);
	ft_strncpy(res + tab_len, v, len);
	res = (char *)ft_freturn(res, (long)ft_strmcat(data->buf, res, -1));
	if (!res)
		return (NULL);
	free(data->buf);
	data->buf = res;
	return (res);
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
