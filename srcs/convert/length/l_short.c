/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_short.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:31:05 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/18 19:24:01 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ft_types.h"

char			*short_length(t_printf *const data, t_arg *const arg)
{
	short int	*v;

	v = (short int *)arg->val.p;
	*v = data->len;
	return (data->buf);
}

char			*short_short_length(t_printf *const data, t_arg *const arg)
{
	signed char	*v;

	v = (signed char *)arg->val.p;
	*v = data->len;
	return (data->buf);
}
