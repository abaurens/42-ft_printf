/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:41:44 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/10 15:47:39 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

char				*long_uinteger(t_printf *const data, t_arg *const arg)
{
	unsigned long	v;
	char			*tab;

	v = (long int)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width;
	if (!(tab = padded_ulltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*long_long_uinteger(t_printf *const data, t_arg *const arg)
{
	unsigned long long	v;
	char				*tab;

	v = (unsigned long long)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width;
	if (!(tab = padded_ulltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
