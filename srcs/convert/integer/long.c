/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:21:12 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/10 15:25:23 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

char			*long_integer(t_printf *const data, t_arg *const arg)
{
	long int	v;
	char		*tab;

	v = (long int)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - (v < 0);
	if ((arg->flags & (F_PLUS | F_SPAC)) && v >= 0)
		arg->precision++;
	if (!(tab = padded_lltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (long int)arg->value >= 0)
		tab[ft_idxof('0', tab)] = (arg->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*long_long_integer(t_printf *const data, t_arg *const arg)
{
	long long	v;
	char		*tab;

	v = (long long)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - (v < 0);
	if ((arg->flags & (F_PLUS | F_SPAC)) && v >= 0)
		arg->precision++;
	if (!(tab = padded_lltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (long long)arg->value >= 0)
		tab[ft_idxof('0', tab)] = (arg->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
