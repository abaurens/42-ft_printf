/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:17:43 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/13 16:56:23 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

#include "debug.h"

int				get_non_arg(const char *format, t_printf *data)
{
	char		*tmp;
	size_t		blen;
	size_t		i;

	blen = 0;
	if (!data)
		return (ERROR);
	if (data->buf != NULL)
		blen = ft_strlen(data->buf);
	i = ft_idxof('%', format);
	tmp = data->buf;
	if (!(data->buf = ft_strmcat(tmp, format, blen + i)))
		return (ERROR);
	free(tmp);
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
