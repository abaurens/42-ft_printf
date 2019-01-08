/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:20:02 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/08 18:13:00 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "ft_types.h"
#include "libft.h"

static char		*integer(t_printf *const data, t_arg *const arg)
{
	int			v;
	char		*tab;

	v = (int)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - (v < 0);
	if ((arg->flags & (F_PLUS | F_SPAC)) && v >= 0)
		arg->precision++;
	if (!(tab = padded_lltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (int)arg->value >= 0)
		tab[ft_idxof('0', tab)] = (arg->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static char		*long_integer(t_printf *const data, t_arg *const arg)
{
	long int	v;
	char		*tab;

	v = (long int)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - (v < 0);
	if ((arg->flags & (F_PLUS | F_SPAC)) && v >= 0)
		arg->precision++;
	if (!(tab = padded_lltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (long int)arg->value >= 0)
		tab[ft_idxof('0', tab)] = (arg->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static char		*long_long_integer(t_printf *const data, t_arg *const arg)
{
	long long	v;
	char		*tab;

	v = (long long)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - (v < 0);
	if ((arg->flags & (F_PLUS | F_SPAC)) && v >= 0)
		arg->precision++;
	if (!(tab = padded_lltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (long long)arg->value >= 0)
		tab[ft_idxof('0', tab)] = (arg->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static char		*short_integer(t_printf *const data, t_arg *const arg)
{
	short int	v;
	char		*tab;

	v = (short int)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - (v < 0);
	if ((arg->flags & (F_PLUS | F_SPAC)) && v >= 0)
		arg->precision++;
	if (!(tab = padded_lltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (short int)arg->value >= 0)
		tab[ft_idxof('0', tab)] = (arg->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static char		*short_short_integer(t_printf *const data, t_arg *const arg)
{
	signed char	v;
	char		*tab;

	v = (signed char)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - (v < 0);
	if ((arg->flags & (F_PLUS | F_SPAC)) && v >= 0)
		arg->precision++;
	if (!(tab = padded_lltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (signed char)arg->value >= 0)
		tab[ft_idxof('0', tab)] = (arg->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static char		*intmax_integer(t_printf *const data, t_arg *const arg)
{
	intmax_t	v;
	char		*tab;

	v = (intmax_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - (v < 0);
	if ((arg->flags & (F_PLUS | F_SPAC)) && v >= 0)
		arg->precision++;
	if (!(tab = padded_lltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (intmax_t)arg->value >= 0)
		tab[ft_idxof('0', tab)] = (arg->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static char		*size_integer(t_printf *const data, t_arg *const arg)
{
	size_t		v;
	char		*tab;

	v = (size_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - ((long long)v < 0);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (long long)v >= 0)
		arg->precision++;
	if (!(tab = padded_lltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (long long)v >= 0)
		tab[ft_idxof('0', tab)] = (arg->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static char		*ssize_integer(t_printf *const data, t_arg *const arg)
{
	ssize_t		v;
	char		*tab;

	v = (ssize_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - ((long long)v < 0);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (long long)v >= 0)
		arg->precision++;
	if (!(tab = padded_lltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (long long)v >= 0)
		tab[ft_idxof('0', tab)] = (arg->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static char		*ptrdiff_integer(t_printf *const data, t_arg *const arg)
{
	ptrdiff_t	v;
	char		*tab;

	v = (ptrdiff_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - (v < 0);
	if ((arg->flags & (F_PLUS | F_SPAC)) && v >= 0)
		v = -v;
	if (!(tab = padded_lltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (ptrdiff_t)arg->value >= 0)
		tab[ft_idxof('0', tab)] = (arg->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static char		*quad_integer(t_printf *const data, t_arg *const arg)
{
	quad_t		v;
	char		*tab;

	v = (quad_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width - (v < 0);
	if ((arg->flags & (F_PLUS | F_SPAC)) && v >= 0)
		v = -v;
	if (!(tab = padded_lltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & (F_PLUS | F_SPAC)) && (quad_t)arg->value >= 0)
		tab[ft_idxof('0', tab)] = (arg->flags & F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{'H', TRUE, short_short_integer},
	{'h', TRUE, short_integer},
	{' ', TRUE, integer},
	{'j', TRUE, intmax_integer},
	{'l', TRUE, long_integer},
	{'L', TRUE, long_long_integer},
	{'q', TRUE, quad_integer},
	{'z', TRUE, size_integer},
	{'Z', TRUE, ssize_integer},
	{'t', TRUE, ptrdiff_integer},
	{'\0', FALSE, NULL}
};

char			*convert_integer(t_printf *const data, t_arg *const arg)
{
	int			i;
	long long	prec;
	long long	min;

	min = arg->min_width;
	prec = arg->precision;
	i = (get_arg(data, arg->flag_idx, &arg->value));
	i = (i || (arg->min_width_idx && get_arg(data, arg->min_width_idx, &min)));
	if (i || (arg->precision_idx && get_arg(data, arg->precision_idx, &prec)))
		return (NULL);
	i = 0;
	arg->min_width = (((int)min) < 0 ? 0 : (int)min);
	if ((arg->precision = (((int)prec) < 0 ? 0 : (int)prec))
		|| (arg->flags & F_MINS))
		arg->flags &= ~F_ZERO;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
