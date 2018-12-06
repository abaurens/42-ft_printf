/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:17:43 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/06 16:41:07 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int					parse_flags(t_char *format, t_arg *arg)
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

int					parse_chain_format(t_char *format, t_printf *data, int *val)
{
	int				i;

	i = 0;
	*val = 0;
	while (format[i] && (format[i] >= '0' && format[i] <= '9'))
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

int					parse_min_width(t_char *format, t_printf *data, t_arg *arg)
{
	int				i;
	const char		*f;

	i = 0;
	f = format;
	format += parse_flags(format, arg);
	if ((arg->min_width = 0) || *format == '*')
	{
		if ((i = parse_chain_format(format + 1, data, &arg->min_width_idx)) < 0)
			return (0);
		++i;
		return ((format + i) - f);
	}
	arg->min_width = ft_atoi(format);
	while (format[i] && format[i] >= '0' && format[i] <= '9')
		i++;
	return ((format + i) - f);
}

int					parse_precision(t_char *format, t_printf *data, t_arg *arg)
{
	int				i;
	const char		*f;

	i = 0;
	f = format;
	format += parse_flags(format, arg);
	if ((arg->precision = 0) || *format++ != '.')
		return (0);
	if (*format == '*')
	{
		if ((i = parse_chain_format(format + 1, data, &arg->precision_idx)) < 0)
			return (0);
		++i;
		return ((format + i + 1) - f);
	}
	while (format[i] && format[i] >= '0' && format[i] <= '9')
		i++;
	arg->precision = ft_atoi(format);
	return ((format + i + 1) - f);
}

int					parse_length_modifier(t_char *format, t_printf *data,
	t_arg *arg)
{
	char			c;
	int				i;
	int				j;

	j = 0;
	i = -1;
	(void)data;
	while ((c = LEN_MD[++i]))
	{
		j += parse_flags(format + j, arg);
		if (format[j] == c && (++j))
		{
			i = -1;
		}
	}
	return (j);
}

int					process_args(const char **format, t_printf *data, t_arg *a)
{
	int				i;
	const char		*f;

	i = 0;
	a->flags = 0;
	f = *format;
	*format += parse_flags(*format + 1, a) + 1;
	printf("R : |%s\n", *format);
	if ((i = parse_chain_format(*format, data, &a->flag_idx)) < 0)
		i = 0;
	*format += i;
	printf("R : |%s", *format);
	*format += parse_min_width(*format, data, a);
	*format += parse_precision(*format, data, a);
	*format += parse_length_modifier(*format, data, a);
	a->conv_c = *(*format)++;
	if (!ft_contains(a->conv_c, CONV_V))
		return (*format - f);
	a->conv_id = ft_idxof(a->conv_c, CONV_V);
	i = (*format - f);
	return (i);
}

int						get_args(const char **format, t_printf *data)
{
	size_t				blen;
	char				tb[2];
	char				*tmp;
	t_arg				arg;
	int					i;

	blen = 0;
	(void)blen;
	tb[1] = 0;
	if (!data || (format && *format && **format != '%'))
		return (ERROR);
	if (data->buf != NULL)
		blen = ft_strlen(data->buf);
	if ((i = process_args(format, data, &arg)) < 0)
		return (0);
	tb[0] = arg.conv_c;
	tmp = ft_strmcat(data->buf, tb, -1);
	free(data->buf);
	data->buf = tmp;
	return (i);
}
