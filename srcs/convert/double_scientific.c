/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_scientific.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:28:58 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/08 16:48:42 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "ft_types.h"
#include "libft.h"

static char		*long_double(t_printf *const data, t_arg *const ar)
{
	size_t		l;
	size_t		add;
	char		s;
	char		*t;
	char		*r;

	if (!(t = exp_dbl(ar->ldbl, ar->precision)))
		return (NULL);
	if (ft_isupper(ar->conv.c))
		ft_strupcase(t);
	if ((s = (*t != '-' && (ar->flags & (F_PLUS | F_SPAC)))) && !fnan(ar->ldbl))
		t = (char *)ft_freturn(t, (long)ft_strmcat(" ", t, -1));
	s = ((s || *t == '-') && !fnan(ar->ldbl));
	if (!(ar->flags & F_HASH) && !ar->precision && ldbl_num(ar->ldbl))
		ft_memmove(t + s + 1, t + s + 2, ft_strlen(t + s + 1));
	l = ft_strlen(t);
	add = ((size_t)ar->min_width > l) ? ar->min_width - l : 0;
	if (!(r = ft_memalloc(l + add + 1)))
		return ((char *)ft_freturn(t, 0x0));
	if (*t == '-' || (*t == ' ' && (ar->flags & F_PLUS) && (*t = '+')))
		*r = *t;
	s *= !!(ar->flags & F_ZERO);
	ft_memset(r + s, (ar->flags & F_ZERO) ? '0' : ' ', add + l - s);
	ft_memcpy(r + add * !(ar->flags & F_MINS) + s, t + s, l - s);
	return ((char *)ft_freturn(t, (long)insert_buffer(data, r, ft_strlen(r))));
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

char			*convert_double_scientific(t_printf *data, t_arg *arg)
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
