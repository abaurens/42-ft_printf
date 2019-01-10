/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:31:05 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/10 15:37:15 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ft_types.h"

char			*short_length(t_printf *const data, t_arg *const arg)
{
	short int	*v;

	v = (short int *)arg->value;
	*v = data->len;
	return (data->buf);
}

char			*short_short_length(t_printf *const data, t_arg *const arg)
{
	signed char	*v;

	v = (signed char *)arg->value;
	*v = data->len;
	return (data->buf);
}
