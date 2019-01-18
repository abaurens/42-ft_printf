/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_long.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:30:32 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/18 19:23:56 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ft_types.h"

char			*long_length(t_printf *const data, t_arg *const arg)
{
	long int	*v;

	v = (long int *)arg->val.p;
	*v = data->len;
	return (data->buf);
}

char			*long_long_length(t_printf *const data, t_arg *const arg)
{
	long long	*v;

	v = (long long int *)arg->val.p;
	*v = data->len;
	return (data->buf);
}
