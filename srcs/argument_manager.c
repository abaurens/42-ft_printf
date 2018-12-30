/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:28:24 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/30 22:04:54 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_types.h"

static int		add_arg(t_ftlist *lst, long long int value, long double ldbl)
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

static int		rm_last(t_ftlist *lst)
{
	t_lst_elem	*rm;

	if (!lst || !lst->tail || !lst->head || !lst->size)
		return (0);
	rm = lst->tail;
	lst->tail = rm->prev;
	if (rm == lst->head)
		lst->head = NULL;
	free(rm);
	lst->size--;
	return (0);
}

void			clear_list(t_ftlist *lst)
{
	while (lst && lst->head && lst->tail && lst->size)
	{
		rm_last(lst);
	}
}

static int		get_at(t_ftlist *lst, const size_t idx, long long *val)
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
		*val = cur->value;
	return (0);
}

int				get_arg(t_printf *data, const size_t idx, void *val)
{
	va_list		cpy;

	va_copy(cpy, data->va_lst);
	if (idx == 0 || !data)
		return (0);
	while (data->args.size < idx)
	{
		if (add_arg(&data->args, va_arg(data->va_lst, long long int),
			va_arg(cpy, long double)))
			return (1);
	}
	va_end(cpy);
	return (get_at(&data->args, idx, val));
}
