/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_compact.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:29:42 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/06 18:19:48 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_core.h"
#include "converter.h"
#include "ft_types.h"
#include "libft.h"

static char		*remove_zeros(char *str, t_arg *arg)
{
	size_t		i;
	size_t		len;
	char		type;

	if (!str || !ft_strchr(str, '.'))
		return (str);
	len = ft_min(ft_idxof('e', str), ft_idxof('E', str));
	type = (str[len] == 'e');
	i = len;
	while (str[--i] == '0' || str[i] == ' ')
		str[i] = (i < (size_t)arg->min_width) || type ? ' ' : 0;
	if (str[i] == '.')
		str[i] = (i < (size_t)arg->min_width) || type ? ' ' : 0;
	if (type)
		ft_memmove(str + i + 1, str + len, ft_strlen(str + len - 1));
	return (str);
}

static char		*long_double(t_printf *const data, t_arg *const arg)
{
	long double	tmp;
	char		num;
	int			exp;
	char		*res;

	exp = 0;
	tmp = arg->ldbl;
	if (!arg->precision)
		arg->precision++;
	if ((num = (!fnan(tmp))))
		dbl_abs(&tmp, NULL);
	num = (num && tmp != (1.0 / 0.0));
	while (num && tmp != .0 && ((tmp < 1.0 && --exp) || (tmp >= 10.0 && ++exp)))
		tmp = (tmp >= 10.0 ? tmp / 10.0 : tmp * 10.0);
	if (num && (exp < -4 || exp >= arg->precision) && arg->precision--)
		return (remove_zeros(convert_double_scientific(data, arg), arg));
	arg->precision -= (exp + 1);
	if (!(res = remove_zeros(printf_ldbl(data, arg), arg)))
		return (NULL);
	if (!(res = (char *)ft_freturn(res, (long)ft_strmcat(data->buf, res, -1))))
		return (NULL);
	return (data->buf = (char *)ft_freturn(data->buf, (long)res));
}

static char		*std_double(t_printf *const data, t_arg *const arg)
{
	arg->ldbl = (long double)arg->dbl;
	return (long_double(data, arg));
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, std_double},
	{'l', TRUE, std_double},
	{'L', TRUE, long_double},
	{'\0', FALSE, NULL}
};

char			*convert_double_compact(t_printf *data, t_arg *arg)
{
	int			i;
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
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
