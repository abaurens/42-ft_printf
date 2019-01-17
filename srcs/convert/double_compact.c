/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_compact.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:29:42 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/17 19:53:36 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ft_core.h"
#include "core/converter.h"
#include "core/ft_types.h"
#include "libft.h"

static char		*padd(char *str, t_arg *arg)
{
	size_t		add;
	size_t		len;
	char		*res;
	char		sign;

	sign = 0;
	if (!str)
		return (str);
	len = ft_strlen(str);
	if (flag(arg, F_ZERO) && ft_contains(*str, " +-") && (sign = *str))
		str++;
	add = ((size_t)arg->min > len ? arg->min - len : 0);
	if (!(res = ft_memalloc(len + add + 1)))
		return ((char *)ft_freturn(str, 0x0));
	ft_memset(res, flag(arg, F_ZERO) && ldbl_num(arg->ldbl) ? '0' : ' ', len + add);
	add *= !flag(arg, F_MINS);
	ft_memmove(res + add + !!sign, str, ft_strlen(str));
	if (sign && --str)
		*res = sign;
	fflush(stdout);
	return ((char *)ft_freturn(str, (long)res));
}

static char		*remove_zeros(char *str, t_arg *arg)
{
	size_t		i;
	size_t		len;
	char		type;

	if (!str || !ft_strchr(str, '.'))
		return (padd(str, arg));
	len = ft_min(ft_idxof('e', str), ft_idxof('E', str));
	type = (str[len] == 'e' || str[len] == 'E');
	i = len - 1;
	if (!flag(arg, F_HASH))
		while (str[i] == '0' && (str[i - 1] != '.' || !flag(arg, F_HASH)))
			str[i--] = type ? '0' : 0;
	if (!flag(arg, F_HASH) && str[i] == '.' && (i-- || 1))
		str[i + 1] = type ? str[i + 1] : 0;
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
	int			min;

	exp = 0;
	tmp = arg->ldbl;
	if (!arg->prec)
		arg->prec++;
	min = arg->min;
	arg->min = 0;
	if ((num = (!fnan(tmp))))
		dbl_abs(&tmp, NULL);
	num = (num && tmp != (1.0 / 0.0));
	while (num && tmp != .0 && ((tmp < 1.0 && --exp) || (tmp >= 10.0 && ++exp)))
		tmp = (tmp >= 10.0 ? tmp / 10.0 : tmp * 10.0);
	if (num && (exp < -4 || exp >= arg->prec) && arg->prec--)
		res = printf_ldbl_s(data, arg);
	else
	{
		arg->prec -= (exp + 1);
		res = printf_ldbl(data, arg);
	}
	arg->min = min;
	res = padd(remove_zeros(res, arg), arg);
	return (insert_buffer(data, res, ft_strlen(res)));
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

	min = arg->min;
	prec = arg->prec;
	i = (arg->min_idx && get_arg(data, arg->min_idx, &min));
	i = (i || (arg->prec_idx && get_arg(data, arg->prec_idx, &prec)));
	if (i || !(tmp = get_arg_f(data, arg->flag_idx)))
		return (NULL);
	i = 0;
	arg->dbl = tmp->dbl;
	arg->ldbl = tmp->ldbl;
	arg->min = (((int)min) < 0 ? 0 : (int)min);
	arg->prec = (((int)prec) < 0 ? 6 : (int)prec);
	if (flag(arg, F_MINS))
		arg->flags &= ~F_ZERO;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
