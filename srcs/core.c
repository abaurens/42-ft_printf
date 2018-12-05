/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:17:43 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/05 21:12:31 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int					parse_chain_format(t_char *format, t_printf *data, int *val)
{
	int				i;

	i = 0;
	*val = 0;
	while (format[i] && format[i] >= '0' && format[i] <= '9')
		i++;
	if (i <= 0)
	{
		if (format[i] == '$' || data->use_chain_format == TRUE)
			return (-1);
		data->use_chain_format = FALSE;
		return (0);
	}
	if (format[i] != '$' && data->use_chain_format == MAYBE)
	{
		data->use_chain_format = FALSE;
		return (0);
	}
	if (format[i] != '$' || data->use_chain_format == FALSE)
		return (-1);
	data->use_chain_format = TRUE;
	*val = ft_atoi(format);
	return (i + 1);
}

int					get_format(t_char *format, t_printf *data)
{
	char			*tmp;
	size_t			blen;
	size_t			i;

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

size_t				parse_flags(t_char *format, t_arg *arg)
{
	char			*tab;
	char			c;
	int				i;
	int				j;

	j = 0;
	i = -1;
	tab = (char[]){F_MINS, F_ZERO, F_PLUS, F_SPAC, F_HASH, F_COLO};
	while ((c = FLAGS_V[++i]))
	{
		if (format[j] == c && (++j))
		{
			arg->flags |= tab[i];
			i = -1;
		}
	}
	return (j);
}

int					parse_min_width(t_char *format, t_printf *data, t_arg *arg)
{
	int				i;

	i = 0;
	if ((arg->min_width = 0) || *format == '*')
	{
		if ((i = parse_chain_format(format + 1, data, &arg->min_width_idx)) < 0)
			return (-1);
		++i;
		return (i);
	}
	arg->min_width = ft_atoi(format);
	while (format[i] && format[i] >= '0' && format[i] <= '9')
		i++;
	return (i);
}

int					parse_precision(t_char *format, t_printf *data, t_arg *arg)
{
	int				i;

	i = 0;
	if ((arg->precision = 0) || *format++ != '.')
		return (0);
	if (*format == '*')
	{
		if ((i = parse_chain_format(format + 1, data, &arg->precision_idx)) < 0)
			return (-1);
		++i;
		return (i + 1);
	}
	while (format[i] && format[i] >= '0' && format[i] <= '9')
		i++;
	arg->precision = ft_atoi(format);
	return (i + 1);
}

int					process_args(const char *format, t_printf *data)
{
	int				i;
	t_arg			arg;
	register t_char	*f;

	i = 0;
	arg.flags = 0;
	f = (format + 1);
	if ((i = parse_chain_format(f, data, &arg.flag_idx)) < 0)
		return (-1);
	f += i;
	if ((i = parse_flags(f, &arg)) < 0)
		return (-1);
	f += i;
	if ((i = parse_min_width(f, data, &arg)) < 0)
		return (-1);
	f += i;
	if ((i = parse_precision(f, data, &arg)) < 0)
		return (-1);
	f += i;
	if (!ft_contains(*f, CONV_V))
		return (-1);
	arg.conv_id = ft_idxof(*f++, CONV_V);
	return (f - format);
}

int						get_args(const char *format, t_printf *data)
{
	size_t				blen;
	int					i;

	blen = 0;
	(void)blen;
	if (!data || (format && *format != '%'))
		return (ERROR);
	if (data->buf != NULL)
		blen = ft_strlen(data->buf);
	if ((i = process_args(format, data)) < 0)
		return (1);
	return (i);
}
