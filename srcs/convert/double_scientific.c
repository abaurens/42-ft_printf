/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_scientific.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:28:58 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/17 20:30:06 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

char			*printf_ldbl_s(t_arg *const ar)
{
	size_t		l;
	size_t		add;
	char		s;
	char		*t;
	char		*r;

	if (!(t = exp_dbl(ar->ldbl, ar->prec)))
		return (NULL);
	if (ft_isupper(ar->conv.c))
		ft_strupcase(t);
	if ((s = (*t != '-' && flag(ar, (F_PLUS | F_SPAC)))) && !fnan(ar->ldbl))
		t = (char *)ft_freturn(t, (long)ft_strmcat(" ", t, -1));
	s = ((s || *t == '-') && !fnan(ar->ldbl));
	if (!flag(ar, F_HASH) && !ar->prec && ldbl_num(ar->ldbl))
		ft_memmove(t + s + 1, t + s + 2, ft_strlen(t + s + 1));
	l = ft_strlen(t);
	add = ((size_t)ar->min > l) ? ar->min - l : 0;
	if (!(r = ft_memalloc(l + add + 1)))
		return ((char *)ft_freturn(t, 0x0));
	if (*t == '-' || (*t == ' ' && ((flag(ar, F_PLUS) && (*t = '+')) || 1)))
		*r = *t;
	s *= flag(ar, F_ZERO);
	ft_memset(r + s, (s && ldbl_num(ar->ldbl)) ? '0' : ' ', add + l - s);
	ft_memcpy(r + add * !flag(ar, F_MINS) + s, t + s, l - s);
	return (r);
}

static char		*std_ldouble(t_printf *const data, t_arg *const arg)
{
	((void)data);
	return (printf_ldbl_s(arg));
}

static char		*std_double(t_printf *const data, t_arg *const arg)
{
	arg->ldbl = (long double)arg->dbl;
	return (printf_ldbl_s(arg));
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, std_double},
	{'l', TRUE, std_double},
	{'L', TRUE, std_ldouble},
	{'\0', FALSE, NULL}
};

char			*convert_double_scientific(t_printf *data, t_arg *arg)
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
