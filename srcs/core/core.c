/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:17:43 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/12 17:22:18 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "core/ft_core.h"
#include "libft.h"

int				get_non_arg(const char *format, t_printf *data)
{
	size_t		i;

	if (!data)
		return (ERROR);
	if ((i = ft_idxof('%', format)) > 0)
		insert_buffer(data, format, i);
	return (i);
}

int				parse_conversion(const char **format, t_printf *data)
{
	t_arg		arg;
	int			i;

	arg.flags = 0;
	arg.flag_idx = 0;
	if (!data || (format && *format && **format && **format != '%'))
		return (ERROR);
	if ((i = parse_arg(format, data, &arg)) < 0)
		return (0);
	if (data->use_chain_format == FALSE)
		arg.flag_idx = ++data->arg_count;
	if (arg.conv.func != NULL)
		arg.conv.func(data, &arg);
	return (i);
}
