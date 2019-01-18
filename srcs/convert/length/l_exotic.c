/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_exotic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:32:54 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/18 19:24:18 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ft_types.h"

char			*intmax_length(t_printf *const data, t_arg *const arg)
{
	intmax_t	*v;

	v = (intmax_t *)arg->val.p;
	*v = data->len;
	return (data->buf);
}

char			*size_length(t_printf *const data, t_arg *const arg)
{
	size_t		*v;

	v = (size_t *)arg->val.p;
	*v = data->len;
	return (data->buf);
}

char			*ssize_length(t_printf *const data, t_arg *const arg)
{
	ssize_t		*v;

	v = (ssize_t *)arg->val.p;
	*v = data->len;
	return (data->buf);
}

char			*ptrdiff_length(t_printf *const data, t_arg *const arg)
{
	ptrdiff_t	*v;

	v = (ptrdiff_t *)arg->val.p;
	*v = data->len;
	return (data->buf);
}

char			*quad_length(t_printf *const data, t_arg *const arg)
{
	quad_t		*v;

	v = (quad_t *)arg->val.p;
	*v = data->len;
	return (data->buf);
}
