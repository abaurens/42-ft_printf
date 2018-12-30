/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_floating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:19:18 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/30 22:27:20 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "ft_types.h"
#include "libft.h"

static char		*std_double(t_printf *const data, t_arg *const arg)
{
	return (NULL);
}

static char		*long_double(t_printf *const data, t_arg *const arg)
{
	long double	v;

	v = (long double)arg->ldbl;
	printf("%Lf", v);
	fflush(stdout);
	return (NULL);
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, std_double},
	{'l', TRUE, std_double},
	{'L', TRUE, long_double},
	{'\0', FALSE, NULL}
};

static int		add_arg_f(t_ftlist *lst, long long int value, long double ldbl)
{
	t_lst_elem	*new;

	if (!lst || !(new = malloc(sizeof(t_lst_elem))))
		return (1);
	new->value = value;
	new->ldbl = ldbl;
	new->next = NULL;
	new->prev = lst->tail;
	if (lst->tail)
		lst->tail->next = new;
	lst->tail = new;
	if (!lst->head)
		lst->head = new;
	lst->size++;
	return (0);
}

static int		get_at_f(t_ftlist *lst, const size_t idx, long double *val)
{
	size_t		i;
	t_lst_elem	*cur;

	i = 0;
	cur = lst->head;
	if (lst->size < idx)
		return (1);
	while (cur && ++i < idx)
		cur = cur->next;
	if (cur)
		*val = cur->ldbl;
	return (0);
}

static int		get_arg_f(t_printf *data, const size_t idx, void *val)
{
	va_list		cpy;

	va_copy(cpy, data->va_lst);
	if (idx == 0 || !data)
		return (0);
	while (data->args.size < idx)
	{
		if (add_arg_f(&data->args, va_arg(data->va_lst, long long int),
			va_arg(cpy, long double)))
			return (1);
	}
	va_end(cpy);
	return (get_at_f(&data->args, idx, val));
}

char			*convert_double_floating(t_printf *data, t_arg *arg)
{
	int			i;
	long long	prec;
	long long	min;

	min = arg->min_width;
	prec = arg->precision;
	i = get_arg_f(data, arg->flag_idx, &arg->ldbl);
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
