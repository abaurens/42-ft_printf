/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exotic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:22:40 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/10 15:25:11 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

char			*intmax_integer(t_printf *const data, t_arg *const arg)
{
	intmax_t	v;
	char		*tab;

	v = (intmax_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - (v < 0);
	if ((arg->flags & (F_PLUS | F_SPAC)) && v >= 0)
		arg->precision++;
	if (!(tab = padded_lltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (intmax_t)arg->value >= 0)
		tab[ft_idxof('0', tab)] = (arg->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*size_integer(t_printf *const data, t_arg *const arg)
{
	size_t		v;
	char		*tab;

	v = (size_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - ((long long)v < 0);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (long long)v >= 0)
		arg->precision++;
	if (!(tab = padded_lltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (long long)v >= 0)
		tab[ft_idxof('0', tab)] = (arg->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*ssize_integer(t_printf *const data, t_arg *const arg)
{
	ssize_t		v;
	char		*tab;

	v = (ssize_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - ((long long)v < 0);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (long long)v >= 0)
		arg->precision++;
	if (!(tab = padded_lltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (long long)v >= 0)
		tab[ft_idxof('0', tab)] = (arg->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*ptrdiff_integer(t_printf *const data, t_arg *const arg)
{
	ptrdiff_t	v;
	char		*tab;

	v = (ptrdiff_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - (v < 0);
	if ((arg->flags & (F_PLUS | F_SPAC)) && v >= 0)
		v = -v;
	if (!(tab = padded_lltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (ptrdiff_t)arg->value >= 0)
		tab[ft_idxof('0', tab)] = (arg->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*quad_integer(t_printf *const data, t_arg *const arg)
{
	quad_t		v;
	char		*tab;

	v = (quad_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - (v < 0);
	if ((arg->flags & (F_PLUS | F_SPAC)) && v >= 0)
		v = -v;
	if (!(tab = padded_lltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (quad_t)arg->value >= 0)
		tab[ft_idxof('0', tab)] = (arg->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
