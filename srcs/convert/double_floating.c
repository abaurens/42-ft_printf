/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_floating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:19:18 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/17 19:53:55 by abaurens         ###   ########.fr       */
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
	if (arg->prec && ++l)
		while (i++ < (size_t)arg->prec)
			l++;
	i = 0;
	if (!arg->prec && flag(arg, F_HASH))
		i++;
	if (!(res = ft_memalloc(l + i + add + 1)))
		return (NULL);
	ft_memset(res, flag(arg, F_ZERO) ? '0' : ' ', l + i + add);
	return (res);
}

static char		*build_res(t_arg *ar)
{
	int			i;
	size_t		add;
	int			enl;
	char		*val;
	char		*rs;

	if (!ldbl_num(ar->ldbl))
		ar->flags &= ~F_HASH;
	if (!(val = round_tabflt(ft_ldtoa(ar->ldbl), ar->prec, NULL)))
		return (NULL);
	if ((add = 0) || ft_isupper(ar->conv.c))
		ft_strupcase(val);
	enl = ft_idxof('.', val);
	i = (ar->ldbl >= 0.0 && flag(ar, F_SPAC | F_PLUS));
	if ((enl + i + ar->prec + (ar->prec || flag(ar, F_HASH))) < ar->min)
		add = ar->min - (enl + i + ar->prec + (ar->prec || flag(ar, F_HASH)));
	if (!(rs = alloc_res(enl + i, ar, add)) || (ar->prec && !++enl))
		return (NULL);
	if (ldbl_num(ar->ldbl) && !ar->prec && flag(ar, F_HASH))
		enl++;
	add *= !flag(ar, F_MINS);
	ft_memcpy(rs + add + i, val, ft_min(ft_strlen(val), enl + ar->prec));
	if (ft_freturn(val, i))
		rs[add * !flag(ar, F_ZERO)] = flag(ar, F_PLUS) ? '+' : ' ';
	return (rs);
}

char			*printf_ldbl(t_printf *const data, t_arg *const arg)
{
	size_t		i;
	int			j;
	char		*res;

	j = 0;
	((void)data);
	arg->flags = (!ldbl_num(arg->ldbl) ? flag(arg, ~F_ZERO) : arg->flags);
	arg->prec *= !(arg->ldbl != arg->ldbl || arg->ldbl == 1.0 / 0.0);
	if (!(res = build_res(arg)))
		return (NULL);
	if (flag(arg, F_ZERO) && arg->ldbl < 0.0 && (i = ft_idxof('-', res)))
	{
		res[i] = res[0];
		res[0] = '-';
	}
	i = ft_idxof('.', res);
	while (!flag(arg, F_ZERO) && j < arg->prec && res[i + j++])
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
	res = g_funcs[!!g_funcs[i].c * i].func(data, arg);
	ft_freturn(res, (long)insert_buffer(data, res, ft_idxof(0, res)));
	return (data->buf);
}
