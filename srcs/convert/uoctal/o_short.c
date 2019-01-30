/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_short.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:29:12 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/18 18:20:03 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "core/libft.h"

char			*short_uoctal(t_printf *const data, t_arg *const arg)
{
	unsigned short	v;
	char			*tab;
	int				len;

	v = (unsigned short int)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "01234567")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH) && v != 0 && arg->prec <= len)
		arg->prec++;
	if (!(tab = padded_ulltoa_octal(v, arg->prec, arg->min, flag(arg, F_MINS))))
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

	v = (unsigned char)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "01234567")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH) && v != 0 && arg->prec <= len)
		arg->prec++;
	if (!(tab = padded_ulltoa_octal(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
