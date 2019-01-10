/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:41:42 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/10 15:46:55 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

char				*short_uinteger(t_printf *const data, t_arg *const arg)
{
	unsigned short	v;
	char			*tab;

	v = (unsigned short int)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width;
	if (!(tab = padded_ulltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*short_short_uinteger(t_printf *const data, t_arg *const arg)
{
	unsigned char	v;
	char			*tab;

	v = (unsigned char)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width;
	if (!(tab = padded_ulltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
