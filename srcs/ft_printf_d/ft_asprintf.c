/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:16:38 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/10 14:57:42 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "ft_core.h"
#include "libft.h"

int		ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int			size;
	t_printf	data;

	if (!format)
		return (ERROR);
	ft_bzero(&data, sizeof(data));
	data.err = errno;
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
	*ret = data.buf;
	return (data.len);
}

int		ft_asprintf(char **ret, const char *format, ...)
{
	int			l;
	va_list		lst;

	va_start(lst, format);
	l = ft_vasprintf(ret, format, lst);
	va_end(lst);
	return (l);
}
