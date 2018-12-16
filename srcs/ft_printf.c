/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:56:12 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/16 16:19:53 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <errno.h>
#include "ft_printf.h"
#include "ft_types.h"
#include "libft.h"

int				ft_printf(const char *format, ...)
{
	int			size;
	t_printf	data;

	if (!format)
		return (ERROR);
	data.buf = NULL;
	data.err = errno;
	data.arg_count = 0;
	data.args.size = 0;
	data.args.head = NULL;
	data.args.tail = NULL;
	data.use_chain_format = MAYBE;
	va_start(data.va_lst, format);
	if ((size = get_non_arg(format, &data)) < 0)
		return (ft_freturn(data.buf, ERROR));
	while (*(format += size))
	{
		if ((size = parse_conversion(&format, &data)) < 0)
			return (ft_freturn(data.buf, ERROR));
		if ((size = get_non_arg(format, &data)) < 0)
			return (ft_freturn(data.buf, ERROR));
	}
	va_end(data.va_lst);
	clear_list(&data.args);
	return (ft_freturn(data.buf, write(1, data.buf, ft_strlen(data.buf))));
}
