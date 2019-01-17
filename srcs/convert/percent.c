/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:54:23 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/17 19:51:26 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

static char	*percent(t_printf *data, t_arg *arg)
{
	char	*res;
	size_t	len;

	len = ft_max(1, arg->min);
	if (!(res = ft_memalloc(len + 1)))
		return (NULL);
	ft_memset(res, flag(arg, F_ZERO) ? '0' : ' ', len);
	res[(len - 1) * !flag(arg, F_MINS)] = '%';
	return (insert_buffer(data, res, len));
}

char		*convert_percent(t_printf *data, t_arg *arg)
{
	int			i;
	long long	prec;
	long long	min;

	min = arg->min;
	prec = arg->prec;
	i = (get_arg(data, arg->flag_idx, &arg->value));
	if (i || (arg->min_idx && get_arg(data, arg->min_idx, &min)))
		return (NULL);
	i = 0;
	arg->min = (((int)min) < 0 ? 1 : (int)min);
	if (flag(arg, F_MINS))
		arg->flags &= ~F_ZERO;
	return (percent(data, arg));
}
