/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:28:24 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/31 13:06:44 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_types.h"

static int			add_arg(t_ftlist *lst, long long int value,
							long double ldbl, double dbl)
{
	t_lst_elem		*new;

	if (!lst || !(new = malloc(sizeof(t_lst_elem))))
		return (1);
	new->value = value;
	new->ldbl = ldbl;
	new->dbl = dbl;
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

static t_lst_elem	*get_at(t_ftlist *lst, const size_t idx)
{
	size_t			i;
	t_lst_elem		*cur;

	i = 0;
	cur = lst->head;
	if (lst->size < idx)
		return (NULL);
	while (cur && ++i < idx)
		cur = cur->next;
	return (cur);
}

t_lst_elem			*get_arg_f(t_printf *data, const size_t idx)
{
	va_list			cpy;
	va_list			cpy2;

	va_copy(cpy, data->va_lst);
	va_copy(cpy2, data->va_lst);
	if (idx == 0 || !data)
		return (0);
	while (data->args.size < idx)
	{
		if (add_arg(&data->args, va_arg(data->va_lst, long long int),
			va_arg(cpy2, long double), va_arg(cpy, double)))
			return (NULL);
	}
	va_end(cpy2);
	va_end(cpy);
	return (get_at(&data->args, idx));
}

int					get_arg(t_printf *data, const size_t idx, long long *val)
{
	t_lst_elem		*tmp;

	if (!(tmp = get_arg_f(data, idx)))
		return (1);
	if (val)
		*val = tmp->value;
	return (0);
}
