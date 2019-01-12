/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:21:12 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/12 21:13:49 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

char			*long_integer(t_printf *const data, t_arg *const ar)
{
	long int	v;
	size_t		l;
	char		*tab;

	v = (long int)ar->value;
	if ((l = (ft_numlen(v) - (v < 0))) > (size_t)ar->precision)
		ar->precision = l;
	if (ar->flags & F_ZERO && l < (size_t)ar->min_width)
		ar->precision = ar->min_width - (v < 0);
	if ((size_t)ar->min_width <= l && (ar->flags & (F_PLUS | F_SPAC)) && v >= 0)
		ar->precision++;
	if (!(tab = padded_lltoa(v, ar->precision, ar->min_width,
		(ar->flags & F_MINS) != 0)))
		return (NULL);
	if ((ar->flags & (F_PLUS | F_SPAC)) && (long int)ar->value >= 0)
		tab[ft_idxof('0', tab)] = (ar->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*long_long_integer(t_printf *const data, t_arg *const ar)
{
	long long	v;
	size_t		l;
	char		*tab;

	v = (long long)ar->value;
	if ((l = (ft_numlen(v) - (v < 0))) > (size_t)ar->precision)
		ar->precision = l;
	if (ar->flags & F_ZERO && l < (size_t)ar->min_width)
		ar->precision = ar->min_width - (v < 0);
	if ((size_t)ar->min_width <= l && (ar->flags & (F_PLUS | F_SPAC)) && v >= 0)
		ar->precision++;
	if (!(tab = padded_lltoa(v, ar->precision, ar->min_width,
		(ar->flags & F_MINS) != 0)))
		return (NULL);
	if ((ar->flags & (F_PLUS | F_SPAC)) && (long long)ar->value >= 0)
		tab[ft_idxof('0', tab)] = (ar->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
