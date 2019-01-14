/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:21:53 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/13 15:55:54 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

char			*short_integer(t_printf *const data, t_arg *const ar)
{
	short int	v;
	size_t		l;
	char		*tab;

	v = (short int)ar->value;
	if ((l = (ft_numlen(v) - (v < 0))) > (size_t)ar->precision)
		ar->precision = l;
	if ((ar->flags & (F_PLUS | F_SPAC)) && v >= 0 && ++l)
		ar->precision++;
	if ((l + (v < 0)) > (size_t)ar->min_width)
		ar->min_width = l + (v < 0);
	if ((ar->flags & F_ZERO) && ar->precision < ar->min_width)
		ar->precision = ar->min_width - (v < 0);
	if (!(tab = padded_lltoa(v, ar->precision, ar->min_width,
		(ar->flags & F_MINS) != 0)))
		return (NULL);
	if ((ar->flags & (F_PLUS | F_SPAC)) && (short int)ar->value >= 0)
		tab[ft_idxof('0', tab)] = (ar->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*short_short_integer(t_printf *const data, t_arg *const ar)
{
	signed char	v;
	size_t		l;
	char		*tab;

	v = (signed char)ar->value;
	if ((l = (ft_numlen(v) - (v < 0))) > (size_t)ar->precision)
		ar->precision = l;
	if ((ar->flags & (F_PLUS | F_SPAC)) && v >= 0 && ++l)
		ar->precision++;
	if ((l + (v < 0)) > (size_t)ar->min_width)
		ar->min_width = l + (v < 0);
	if ((ar->flags & F_ZERO) && ar->precision < ar->min_width)
		ar->precision = ar->min_width - (v < 0);
	if (!(tab = padded_lltoa(v, ar->precision, ar->min_width,
		(ar->flags & F_MINS) != 0)))
		return (NULL);
	if ((ar->flags & (F_PLUS | F_SPAC)) && (signed char)ar->value >= 0)
		tab[ft_idxof('0', tab)] = (ar->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
