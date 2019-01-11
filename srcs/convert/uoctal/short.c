/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:29:12 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/11 21:29:34 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

char			*short_uoctal(t_printf *const data, t_arg *const arg)
{
	unsigned short	v;
	char			*tab;
	int				len;

	v = (unsigned short int)arg->value;
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

char			*short_short_uoctal(t_printf *const data, t_arg *const arg)
{
	unsigned char	v;
	char			*tab;
	int				len;

	v = (unsigned char)arg->value;
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
