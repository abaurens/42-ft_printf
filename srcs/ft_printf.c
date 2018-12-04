/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:56:12 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/04 02:13:10 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

int				get_format(const char *format, char **buffer)
{
	char		*tmp;
	size_t		blen;
	size_t		i;

	blen = 0;
	if (!buffer)
		return (ERROR);
	if (*buffer != NULL)
		blen = ft_strlen(*buffer);
	i = ft_idxof('%', format);
	tmp = *buffer;
	if (!(*buffer = ft_strmcat(*buffer, format, blen + i)))
		return (ERROR);
	free(tmp);
	return (i);
}

int				get_converters(const char *format, char **buffer, va_list *lst)
{
	char		*tmp;
	size_t		blen;
	size_t		i;

	blen = 0;
	if (!buffer)
		return (ERROR);
	if (*buffer != NULL)
		blen = ft_strlen(*buffer);
	if (*format != '%')
		return (ERROR);
	i = 1;
	tmp = *buffer;
	if (!(*buffer = ft_strmcat(*buffer, "%", blen + i)))
		return (ERROR);
	free(tmp);
	return (i);
}

int				ft_printf(const char *format, ...)
{
	int			size;
	char		*buf;
	va_list		lst;

	buf = NULL;
	if (!format)
		return (ERROR);
	va_start(lst, format);
	if ((size = get_format(format, &buf)) < 0)
		return (ft_freturn(buf, ERROR));
	format += size;
	while (*format)
	{
		if (*format != '%' || (size = get_converters(++format, &buf, &lst)) < 0)
			return (ft_freturn(buf, ERROR));
		if ((size + get_format(format += size, &buf)) < 0)
			return (ft_freturn(buf, ERROR));
		format += size;
	}
	va_end(lst);
	return (ft_freturn(buf, write(1, buf, ft_strlen(buf))));
}
