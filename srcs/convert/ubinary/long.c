/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:40:26 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/10 15:52:05 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

char				*long_binary(t_printf *const data, t_arg *const arg)
{
	unsigned long	v;
	char			*tab;
	int				len;

	v = (long int)arg->value;
	if ((len = ft_unsignedlen_base(v, "01")) > arg->precision)
		arg->precision = len;
	if (arg->flags & F_ZERO && arg->min_width > arg->precision)
		arg->precision = arg->min_width;
	if ((arg->flags & F_HASH) && v != 0 && arg->precision < (len + 2))
		arg->precision += ((len + 2) - arg->precision);
	if (!(tab = padded_ulltoa_bin(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'b';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*long_long_binary(t_printf *const data, t_arg *const arg)
{
	unsigned long long	v;
	char				*tab;
	int					len;

	v = (unsigned long long)arg->value;
	if ((len = ft_unsignedlen_base(v, "01")) > arg->precision)
		arg->precision = len;
	if (arg->flags & F_ZERO && arg->min_width > arg->precision)
		arg->precision = arg->min_width;
	if ((arg->flags & F_HASH) && v != 0 && arg->precision < (len + 2))
		arg->precision += ((len + 2) - arg->precision);
	if (!(tab = padded_ulltoa_bin(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'b';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
