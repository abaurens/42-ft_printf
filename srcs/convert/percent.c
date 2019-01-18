/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:54:23 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/18 16:02:23 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

char		*convert_percent(t_printf *data, t_arg *arg)
{
	int			i;
	long long	min;
	size_t		len;
	char		*res;

	min = arg->min;
	if (arg->min_idx && get_arg(data, arg->min_idx, &min))
		return (NULL);
	arg->min = (((int)min) < 0 ? 1 : (int)min);
	if (flag(arg, F_MINS))
		arg->flags &= ~F_ZERO;
	len = ft_max(1, arg->min);
	if (!(res = ft_memalloc(len + 1)))
		return (NULL);
	ft_memset(res, flag(arg, F_ZERO) ? '0' : ' ', len);
	res[(len - 1) * !flag(arg, F_MINS)] = '%';
	return (insert_buffer(data, res, len));
}
