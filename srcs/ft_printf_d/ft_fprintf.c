/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:12:33 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/10 14:48:59 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <wchar.h>

int		ft_vfprintf(FILE *stream, const char *format, va_list ap)
{
	(void)stream;
	(void)format;
	(void)ap;
	return (-1);
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
