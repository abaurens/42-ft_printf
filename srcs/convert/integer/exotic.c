/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exotic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:22:40 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/13 16:17:31 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

char			*intmax_integer(t_printf *const data, t_arg *const ar)
{
	intmax_t	v;
	size_t		l;
	char		*tab;

	v = (intmax_t)ar->value;
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
	if ((ar->flags & (F_PLUS | F_SPAC)) && (intmax_t)ar->value >= 0)
		tab[ft_idxof('0', tab)] = (ar->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*size_integer(t_printf *const data, t_arg *const ar)
{
	size_t		v;
	size_t		l;
	char		*tab;

	v = (size_t)ar->value;
	if ((l = ft_numlen(v)) > (size_t)ar->precision)
		ar->precision = l;
	if ((ar->flags & (F_PLUS | F_SPAC)) && ++l)
		ar->precision++;
	if (l > (size_t)ar->min_width)
		ar->min_width = l;
	if ((ar->flags & F_ZERO) && ar->precision < ar->min_width)
		ar->precision = ar->min_width;
	if (!(tab = padded_lltoa(v, ar->precision, ar->min_width,
		(ar->flags & F_MINS) != 0)))
		return (NULL);
	if ((ar->flags & (F_PLUS | F_SPAC)) && (long long)v >= 0)
		tab[ft_idxof('0', tab)] = (ar->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*ssize_integer(t_printf *const data, t_arg *const ar)
{
	ssize_t		v;
	size_t		l;
	char		*tab;

	v = (ssize_t)ar->value;
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
	if ((ar->flags & (F_PLUS | F_SPAC)) && v >= 0)
		tab[ft_idxof('0', tab)] = (ar->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*ptrdiff_integer(t_printf *const data, t_arg *const ar)
{
	ptrdiff_t	v;
	size_t		l;
	char		*tab;

	v = (ptrdiff_t)ar->value;
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
	if ((ar->flags & (F_PLUS | F_SPAC)) && (ptrdiff_t)ar->value >= 0)
		tab[ft_idxof('0', tab)] = (ar->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*quad_integer(t_printf *const data, t_arg *const ar)
{
	quad_t		v;
	size_t		l;
	char		*tab;

	v = (quad_t)ar->value;
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
	if ((ar->flags & (F_PLUS | F_SPAC)) && (quad_t)ar->value >= 0)
		tab[ft_idxof('0', tab)] = (ar->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
