/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:56:12 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/04 16:26:16 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

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
	while (*(format += size))
	{
		if ((size = get_args(format, &buf, &lst)) < 0)
			return (ft_freturn(buf, size));
		if ((size = get_format(format += size, &buf)) < 0)
			return (ft_freturn(buf, ERROR));
	}
	va_end(lst);
	return (ft_freturn(buf, write(1, buf, ft_strlen(buf))));
}
