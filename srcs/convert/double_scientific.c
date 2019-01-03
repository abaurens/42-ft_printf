/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_scientific.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:28:58 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/03 20:24:59 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"
#include "ft_types.h"
#include "libft.h"

static char		*long_double(t_printf *const data, t_arg *const arg)
{
	size_t		l;
	size_t		add;
	char		*res;

	if (!(res = exp_dbl(arg->ldbl, arg->precision)))
		return (NULL);
	if (ft_isupper(arg->conv.c))
		ft_strupcase(res);
	if ((arg->flags & (F_PLUS | F_SPAC)))
		res = (char *)ft_freturn(res, (long)ft_strmcat(" ", res, -1));
	l = ft_strlen(res);
	printf("r = %s\n", res);
	free(res);
	return (NULL);
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
