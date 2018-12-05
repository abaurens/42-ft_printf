/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:17:43 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/05 09:46:21 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

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
	tab = (char []){F_MINS, F_ZERO, F_PLUS, F_SPAC, F_HASH, F_COLO};
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

size_t				parse_min_width(t_char *format, t_printf *data, t_arg *arg)
{
	int				i;

	i = 0;
	arg->min_width = 0;
	if (*format == '*' || data->use_chain_format)
	{
		i = 1;
		if (*format != '*')
			return (-1);
		arg->min_width_idx = 0;
		while (format[i] && format[i] >= '0' && format[i] <= '9')
			i++;
		if (i > 1)
		{
			if (format[i++] != '$')
				return (-1);
			arg->min_width_idx = ft_atoi(format + 1);
		}
		return (i);
	}
	arg->min_width = ft_atoi(format);
	while (format[i] && format[i] >= '0' && format[i] <= '9')
		i++;
	return (i);
}

size_t				parse_precision(t_char *format, t_printf *data, t_arg *arg)
{
	int				i;

	i = 0;
	arg->precision = 0;
	if (*format++ != '.')
		return (0);
	if (*format == '*' || data->use_chain_format)
	{
		i = 1;
		if (*format != '*')
			return (-1);
		arg->precision_idx = 0;
		while (format[i] && format[i] >= '0' && format[i] <= '9')
			i++;
		if (i > 1)
		{
			if (format[i++] != '$')
				return (-1);
			arg->min_width_idx = ft_atoi(format + 1);
		}
		return (i + 1);
	}
	arg->precision = ft_atoi(format);
	while (format[i] && format[i] >= '0' && format[i] <= '9')
		i++;
	return (i + 1);
}

size_t				process_args(const char *format, t_printf *data)
{
	int				i;
	t_arg			arg;
	register t_char	*f;

	i = 0;
	arg.flags = 0;
	f = (format + 1);
	printf("\t$ format, flags, min_width, precision, convertion : |%.*s|\n", ft_idxof('\n', f), f);

	while (data->use_chain_format && f[i] && f[i] >= '0' && f[i] <= '9')
		i++;
	if (i > 0)
	{
		if (f[i] != '$')
			return (-1);
		arg.flag_idx = ft_atoi(f);
		data->use_chain_format = TRUE;
		f += i + 1;
	}
	printf("\tflags, min_width, precision, convertion :           |%.*s|\n", ft_idxof('\n', f), f);

	if ((i = parse_flags(f, &arg)) < 0)
		return (-1);
	printf("\tmin_width, precision, convertion :                  |%.*s|\n", ft_idxof('\n', f), f);
	f += i;
	if ((i = parse_min_width(f, data, &arg)) < 0)
		return (-1);
	f += i;
	printf("\tprecision, convertion:                              |%.*s|\n", ft_idxof('\n', f), f);
	if ((i = parse_precision(f, data, &arg)) < 0)
		return (-1);
	f += i;
	printf("\tconvertion :                                        |%.*s|\n", ft_idxof('\n', f), f);

	printf("\nstruct value :\nusing $ format : %d\nenabeled flags : %d\nminimum field width : %d\nprecision : %d\n",
		data->use_chain_format,
		arg.flags,
		arg.min_width,
		arg.precision);
	exit(0);
	return (0);
}

int						get_args(const char *format, t_printf *data)
{
	size_t				blen;
	size_t				i;

	blen = 0;
	(void)blen;
	if (!data || (format && *format != '%'))
		return (ERROR);
	if (data->buf != NULL)
		blen = ft_strlen(data->buf);
	i = process_args(format, data);
	return (i);
}
