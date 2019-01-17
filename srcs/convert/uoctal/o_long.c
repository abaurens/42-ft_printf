/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:29:23 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/17 19:46:26 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

char			*long_uoctal(t_printf *const data, t_arg *const arg)
{
	unsigned long	v;
	char			*tab;
	int				len;

	v = (long int)arg->value;
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

char			*long_long_uoctal(t_printf *const data, t_arg *const arg)
{
	unsigned long long	v;
	char				*tab;
	int					len;

	v = (unsigned long long)arg->value;
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
