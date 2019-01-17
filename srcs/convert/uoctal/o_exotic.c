/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exotic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:27:11 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/17 19:46:43 by abaurens         ###   ########.fr       */
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
	if ((len = ft_unsignedlen_base(v, "01234567")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH && v != 0 && arg->prec <= len))
		arg->prec++;
	if (!(tab = padded_ulltoa_octal(v, arg->prec, arg->min, flag(arg, F_MINS))))
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
	if ((len = ft_unsignedlen_base(v, "01234567")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH && v != 0 && arg->prec <= len))
		arg->prec++;
	if (!(tab = padded_ulltoa_octal(v, arg->prec, arg->min, flag(arg, F_MINS))))
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
	if ((len = ft_unsignedlen_base(v, "01234567")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH && v != 0 && arg->prec <= len))
		arg->prec++;
	if (!(tab = padded_ulltoa_octal(v, arg->prec, arg->min, flag(arg, F_MINS))))
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
	if ((len = ft_unsignedlen_base(v, "01234567")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH && v != 0 && arg->prec <= len))
		arg->prec++;
	if (!(tab = padded_ulltoa_octal(v, arg->prec, arg->min, flag(arg, F_MINS))))
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
	if ((len = ft_unsignedlen_base(v, "01234567")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH && v != 0 && arg->prec <= len))
		arg->prec++;
	if (!(tab = padded_ulltoa_octal(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
