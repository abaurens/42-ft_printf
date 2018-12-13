/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:57:31 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/13 16:41:44 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static int		get_flags(const char *format, t_arg *arg)
{
	char		c;
	int			i;
	int			j;

	j = 0;
	i = -1;
	while ((c = FLAGS_V[++i]))
	{
		if (format[j] == c && (++j))
		{
			arg->flags |= g_flags_masks[i];
			i = -1;
		}
	}
	return (j);
}

static int		get_min_width(const char *format, t_printf *data, t_arg *arg)
{
	int			i;
	const char	*f;

	i = 0;
	f = format;
	format += get_flags(format, arg);
	arg->min_width_idx = 0;
	if ((arg->min_width = 0) || *format == '*')
	{
		arg->min_width_idx = ++data->arg_count;
		if ((i = get_chain_format(format + 1, data, &arg->min_width_idx)) < 0)
			return (0);
		++i;
		return ((format + i) - f);
	}
	arg->min_width = ft_atoi(format);
	while (format[i] && format[i] >= '0' && format[i] <= '9')
		i++;
	return ((format + i) - f);
}

static int		get_precision(const char *format, t_printf *data, t_arg *arg)
{
	int			i;
	const char	*f;

	i = 0;
	f = format;
	arg->precision_idx = 0;
	if ((arg->precision = 0) || *format++ != '.')
		return (0);
	if (*format == '*')
	{
		format += 1;
		arg->precision_idx = ++data->arg_count;
		if ((i = get_chain_format(format, data, &arg->precision_idx)) < 0)
			return (0);
		return ((format + i) - f);
	}
	while (format[i] && format[i] >= '0' && format[i] <= '9')
		i++;
	arg->precision = ft_atoi(format);
	return ((format + i) - f);
}

static int		get_length_modifier(const char *frm, t_printf *data, t_arg *arg)
{
	char		c;
	int			i;
	int			j;

	j = 0;
	i = -1;
	c = *frm;
	(void)data;
	arg->length_modifier = -1;
	if (ft_contains(frm[j], LEN_MD) == 1)
		arg->length_modifier = ft_idxof(frm[j++], LEN_MD);
	arg->length_modifier++;
	if (frm[j] == c)
	{
		if (c != 'l' && c != 'h')
			return (j);
		arg->length_modifier++;
		j++;
	}
	while ((c = LEN_MD[++i]))
		if (frm[j] == c && (++j))
			i = -1;
	return (j);
}

int				get_chain_format(const char *format, t_printf *data, size_t *v)
{
	int			i;

	i = 0;
	while (format[i] && (format[i] >= '0' && format[i] <= '9'))
		i++;
	if (i <= 0)
	{
		if (format[i] == '$' || data->use_chain_format == TRUE)
			return (-1);
		data->use_chain_format = FALSE;
		return (i);
	}
	if (format[i] != '$' && data->use_chain_format == MAYBE)
	{
		data->use_chain_format = FALSE;
		return (-1);
	}
	if (format[i] != '$' || data->use_chain_format == FALSE)
		return (-1);
	data->use_chain_format = TRUE;
	*v = ft_atoi(format);
	return (i + 1);
}

int		(*const g_funcs[])(const char *, t_printf *, t_arg *) =
{
	get_min_width,
	get_precision,
	get_length_modifier
};
