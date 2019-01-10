/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exotic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:41:40 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/10 15:47:08 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

char			*intmax_uinteger(t_printf *const data, t_arg *const arg)
{
	uintmax_t		v;
	char			*tab;

	v = (uintmax_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width;
	if (!(tab = padded_ulltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*size_uinteger(t_printf *const data, t_arg *const arg)
{
	size_t			v;
	char			*tab;

	v = (size_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width;
	if (!(tab = padded_ulltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*ssize_uinteger(t_printf *const data, t_arg *const arg)
{
	ssize_t			v;
	char			*tab;

	v = (ssize_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width;
	if (!(tab = padded_ulltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*ptrdiff_uinteger(t_printf *const data, t_arg *const arg)
{
	ptrdiff_t		v;
	char			*tab;

	v = (ptrdiff_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - (v < 0);
	if (!(tab = padded_ulltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*quad_uinteger(t_printf *const data, t_arg *const arg)
{
	u_quad_t		v;
	char			*tab;

	v = (quad_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width;
	if (!(tab = padded_ulltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
