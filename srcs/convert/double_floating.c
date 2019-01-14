/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_floating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:19:18 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/14 18:47:29 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <stdarg.h>
#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

static char		*alloc_res(size_t dtl, t_arg *arg, size_t add)
{
	size_t		i;
	size_t		l;
	char		*res;

	l = 0;
	i = 0;
	l = dtl;
	if (arg->precision && ++l)
		while (i++ < (size_t)arg->precision)
			l++;
	i = 0;
	if (!arg->precision && (arg->flags & F_HASH))
		i++;
	if (!(res = ft_memalloc(l + i + add + 1)))
		return (NULL);
	i = 0;
	while (i++ < l + add)
		res[i - 1] = arg->flags & F_ZERO ? '0' : ' ';
	return (res);
}

static char		*build_res(t_arg *ar)
{
	size_t		i;
	size_t		add;
	int			enl;
	char		*val;
	char		*rs;

	if (!(val = round_tabflt(ft_ldtoa(ar->ldbl), ar->precision, NULL)))
		return (NULL);
	if ((add = 0) || ft_isupper(ar->conv.c))
		ft_strupcase(val);
	enl = ft_idxof('.', val);
	i = (ar->ldbl >= 0.0 && (ar->flags & (F_SPAC | F_PLUS)));
	if ((enl + (int)i + ar->precision + (!!ar->precision)) < ar->min_width)
		add = ar->min_width - (enl + i + ar->precision + (!!ar->precision));
	if (!(rs = alloc_res(enl + i, ar, add)) || (ar->precision && !++enl))
		return (NULL);
	if (ldbl_num(ar->ldbl) && !ar->precision && (ar->flags & F_HASH) && enl++)
		add--;
	add *= !(ar->flags & F_MINS);
	ft_memcpy(rs + add + i, val, ft_min(ft_strlen(val), enl + ar->precision));
	if (ft_freturn(val, i))
		rs[add * !(ar->flags & F_ZERO)] = (ar->flags & F_PLUS) ? '+' : ' ';
	return (rs);
}

char			*printf_ldbl(t_printf *const data, t_arg *const arg)
{
	size_t		i;
	int			j;
	char		*res;

	j = 0;
	((void)data);
	arg->flags = (!ldbl_num(arg->ldbl) ? (arg->flags & ~F_ZERO) : arg->flags);
	arg->precision *= !(arg->ldbl != arg->ldbl || arg->ldbl == 1.0 / 0.0);
	if (!(res = build_res(arg)))
		return (NULL);
	if ((arg->flags & F_ZERO) && arg->ldbl < 0.0 && (i = ft_idxof('-', res)))
	{
		res[i] = res[0];
		res[0] = '-';
	}
	i = ft_idxof('.', res);
	while (!(arg->flags & F_ZERO) && j < arg->precision && res[i + j++])
		if (res[i + j] == ' ')
			res[i + j] = '0';
	j = (*res == '+' || *res == '-' || *res == ' ');
	while (res[j] >= '0' && res[j] <= ':')
		j++;
	return (res);
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
	{'L', TRUE, printf_ldbl},
	{'\0', FALSE, NULL}
};

char			*convert_double_floating(t_printf *data, t_arg *arg)
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
