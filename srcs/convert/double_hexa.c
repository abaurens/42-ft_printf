/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:30:24 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/17 19:53:22 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

static char		*manage_prefix(char *r, t_printf *const data, t_arg *const ar)
{
	int			i;
	char		*sgns;
	char		*s
;
	i = -1;
	sgns = " +-";
	if (ldbl_num(ar->ldbl) && flag(ar, F_ZERO))
	{
		while (sgns[++i])
			if ((s = ft_strchr(r, sgns[i])) && s[-1] != 'p')
			{
				r[ft_idxof(sgns[i], r)] = '0';
				r[0] = sgns[i];
				break;
			}
		r[ft_idxof('x', r)] = '0';
		r[ft_idxof('0', r) + 1] = 'x';
	}
	if (ft_isupper(ar->conv.c))
		ft_strupcase(r);
	return (insert_buffer(data, r, ft_strlen(r)));
}

static char		*long_double_h(t_printf *const data, t_arg *const ar)
{
	size_t		l;
	size_t		add;
	char		s;
	char		*t;
	char		*r;

	if (!(t = exp_dbl_hex(ar->ldbl, ar->prec, !!ar->length_modifier)))
		return (NULL);
	if ((s = (*t != '-' && flag(ar, (F_PLUS | F_SPAC)))) && !fnan(ar->ldbl))
		t = (char *)ft_freturn(t, (long)ft_strmcat(" ", t, -1));
	s = ((s || *t == '-') && !fnan(ar->ldbl));
	if (!flag(ar, F_HASH) && !ar->prec && ldbl_num(ar->ldbl))
		ft_memmove(t + s + 3, t + s + 4, ft_strlen(t + s + 3));
	l = ft_strlen(t);
	add = ((size_t)ar->min > l) ? ar->min - l : 0;
	if (!(r = ft_memalloc(l + add + 1)))
		return ((char *)ft_freturn(t, 0x0));
	if (*t == '-' || (*t == ' ' && flag(ar, F_PLUS) && (*t = '+')))
		*r = *t;
	s *= !!flag(ar, F_ZERO);
	ft_memset(r, flag(ar, F_ZERO) && ldbl_num(ar->ldbl) ? '0' : ' ', add + l);
	ft_memcpy(r + add * !flag(ar, F_MINS), t, l);
	return ((char *)ft_freturn(t, (long)manage_prefix(r, data, ar)));
}

static char		*std_double(t_printf *const data, t_arg *const arg)
{
	arg->length_modifier = 0;
	arg->ldbl = (long double)arg->dbl;
	return (long_double_h(data, arg));
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, std_double},
	{'l', TRUE, std_double},
	{'L', TRUE, long_double_h},
	{'\0', FALSE, NULL}
};

char			*convert_double_hexa(t_printf *data, t_arg *arg)
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
	arg->prec = (((int)prec) < 0 ? -1 : (int)prec);
	if (flag(arg, F_MINS))
		arg->flags &= ~F_ZERO;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
