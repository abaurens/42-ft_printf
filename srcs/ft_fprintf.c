/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:12:33 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/02 18:32:10 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "core/ft_error.h"
#include "core/ft_core.h"
#include "core/libft.h"

int		ft_vfprintf(FILE *stream, const char *format, va_list ap)
{
	int			size;
	t_printf	data;

	if (!format)
		return (ERROR);
	ft_bzero(&data, sizeof(data));
	data.err = get_errno();
	data.use_chain_format = MAYBE;
	va_copy(data.va_lst, ap);
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
	return (ft_freturn(data.buf, fputs(data.buf, stream)));
}

int		ft_fprintf(FILE *stream, const char *format, ...)
{
	int		l;
	va_list	ap;

	va_start(ap, format);
	l = ft_vfprintf(stream, format, ap);
	va_end(ap);
	return (l);
}
