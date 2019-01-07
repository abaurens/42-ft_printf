/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:30:24 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/07 18:29:05 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_types.h"
#include "libft.h"

static char		*long_double(t_printf *const data, t_arg *const arg)
{
	exp_dbl_hex(arg->ldbl, arg->precision);
	return (NULL);
}

static char		*std_double(t_printf *const data, t_arg *const arg)
{
	arg->ldbl = (long double)arg->dbl;
	return (printf_ldbl(data, arg));
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, std_double},
	{'l', TRUE, std_double},
	{'L', TRUE, long_double},
	{'\0', FALSE, NULL}
};

char			*convert_double_hexa(t_printf *data, t_arg *arg)
{
	int			i;
	char		*res;
	long long	min;
	long long	prec;
	t_lst_elem	*tmp;

	min = arg->min_width;
	prec = arg->precision;
	i = (arg->min_width_idx && get_arg(data, arg->min_width_idx, &min));
	i = (i || (arg->precision_idx && get_arg(data, arg->precision_idx, &prec)));
	if (i || !(tmp = get_arg_f(data, arg->flag_idx)))
		return (NULL);
	i = 0;
	arg->dbl = tmp->dbl;
	arg->ldbl = tmp->ldbl;
	arg->min_width = (((int)min) < 0 ? 0 : (int)min);
	arg->precision = (((int)prec) < 0 ? 6 : (int)prec);
	if (arg->flags & F_MINS)
		arg->flags &= ~F_ZERO;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	res = g_funcs[!!g_funcs[i].c * i].func(data, arg);
	ft_freturn(res, (long)insert_buffer(data, res, ft_idxof(0, res)));
	return (data->buf);
}
