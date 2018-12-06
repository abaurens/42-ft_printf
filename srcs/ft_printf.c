/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:56:12 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/06 13:01:01 by abaurens         ###   ########.fr       */
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
	t_printf	data;

	if (!format)
		return (ERROR);
	data.buf = NULL;
	data.use_chain_format = MAYBE;
	va_start(data.lst, format);
	if ((size = get_format(format, &data)) < 0)
		return (ft_freturn(data.buf, ERROR));
	while (*(format += size))
	{
		if ((size = get_args(&format, &data)) < 0)
			return (ft_freturn(data.buf, size));
		if ((size = get_format(format, &data)) < 0)
			return (ft_freturn(data.buf, ERROR));
	}
	va_end(data.lst);
	return (ft_freturn(data.buf, write(1, data.buf, ft_strlen(data.buf))));
}
