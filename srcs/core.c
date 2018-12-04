/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:17:43 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/04 18:19:25 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int					get_format(const char *format, char **buffer)
{
	char			*tmp;
	size_t			blen;
	size_t			i;

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

size_t				parse_flags(const char *format, t_arg *arg)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (FLAGS[i])
	{
		if (format[j] == FLAGS[i] && (i = -1))
			printf("\t\tfound the flag '%c' in pos %d\n", format[j], j++);
		i++;
	}
	return (j);
}

size_t				process_args(const char *format)
{
	t_arg			arg;
	register char	*f;

	f = (format + 1);
	printf("\twith flags :    |%s|\n", f);
	f += parse_flags(f, &arg);
	printf("\twithout flags : |%s|\n", f);
	exit(0);
	return (0);
}

int					get_args(const char *format, char **buffer, va_list *lst)
{
	size_t			blen;
	size_t			i;

	blen = 0;
	if (!buffer)
		return (ERROR);
	if (*buffer != NULL)
		blen = ft_strlen(*buffer);
	if (*format != '%')
		return (ERROR);
	i = process_args(format);
	return (i);
}
