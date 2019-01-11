/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exotic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:27:11 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/11 21:29:38 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

char			*intmax_uoctal(t_printf *const data, t_arg *const arg)
{
	uintmax_t		v;
	char			*tab;
	int				len;

	v = (uintmax_t)arg->value;
	if ((len = ft_unsignedlen_base(v, "01234567")) > arg->precision)
		arg->precision = len;
	if (arg->flags & F_ZERO && arg->min_width > arg->precision)
		arg->precision = arg->min_width;
	if (arg->flags & F_HASH && v != 0 && arg->precision <= len)
		arg->precision++;
	if (!(tab = padded_ulltoa_octal(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*size_uoctal(t_printf *const data, t_arg *const arg)
{
	size_t			v;
	char			*tab;
	int				len;

	v = (size_t)arg->value;
	if ((len = ft_unsignedlen_base(v, "01234567")) > arg->precision)
		arg->precision = len;
	if (arg->flags & F_ZERO && arg->min_width > arg->precision)
		arg->precision = arg->min_width;
	if (arg->flags & F_HASH && v != 0 && arg->precision <= len)
		arg->precision++;
	if (!(tab = padded_ulltoa_octal(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*ssize_uoctal(t_printf *const data, t_arg *const arg)
{
	ssize_t			v;
	char			*tab;
	int				len;

	v = (ssize_t)arg->value;
	if ((len = ft_unsignedlen_base(v, "01234567")) > arg->precision)
		arg->precision = len;
	if (arg->flags & F_ZERO && arg->min_width > arg->precision)
		arg->precision = arg->min_width;
	if (arg->flags & F_HASH && v != 0 && arg->precision <= len)
		arg->precision++;
	if (!(tab = padded_ulltoa_octal(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*ptrdiff_uoctal(t_printf *const data, t_arg *const arg)
{
	ptrdiff_t		v;
	char			*tab;
	int				len;

	v = (ptrdiff_t)arg->value;
	if ((len = ft_unsignedlen_base(v, "01234567")) > arg->precision)
		arg->precision = len;
	if (arg->flags & F_ZERO && arg->min_width > arg->precision)
		arg->precision = arg->min_width;
	if (arg->flags & F_HASH && v != 0 && arg->precision <= len)
		arg->precision++;
	if (!(tab = padded_ulltoa_octal(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*quad_uoctal(t_printf *const data, t_arg *const arg)
{
	u_quad_t		v;
	char			*tab;
	int				len;

	v = (u_quad_t)arg->value;
	if ((len = ft_unsignedlen_base(v, "01234567")) > arg->precision)
		arg->precision = len;
	if (arg->flags & F_ZERO && arg->min_width > arg->precision)
		arg->precision = arg->min_width;
	if (arg->flags & F_HASH && v != 0 && arg->precision <= len)
		arg->precision++;
	if (!(tab = padded_ulltoa_octal(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
