/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:54:23 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/06 20:30:07 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "ft_types.h"
#include "libft.h"

static char	*percent(t_printf *data, t_arg *arg)
{
	char	*res;
	size_t	len;

	len = ft_max(1, arg->min_width);
	if (!(res = ft_memalloc(len + 1)))
		return (NULL);
	ft_memset(res, (arg->flags & F_ZERO) ? '0' : ' ', len);
	res[(len - 1) * !(arg->flags & F_MINS)] = '%';
	return (insert_buffer(data, res, len));
}

char		*convert_percent(t_printf *data, t_arg *arg)
{
	int			i;
	long long	prec;
	long long	min;

	min = arg->min_width;
	prec = arg->precision;
	i = (get_arg(data, arg->flag_idx, &arg->value));
	if (i || (arg->min_width_idx && get_arg(data, arg->min_width_idx, &min)))
		return (NULL);
	i = 0;
	arg->min_width = (((int)min) < 0 ? 1 : (int)min);
	if (arg->flags & F_MINS)
		arg->flags &= ~F_ZERO;
	return (percent(data, arg));
}
