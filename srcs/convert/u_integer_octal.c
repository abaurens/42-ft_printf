/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_integer_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 21:02:59 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/14 20:05:38 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "ft_types.h"
#include "debug.h"
#include "libft.h"

static char			*integer(t_printf *const data, t_arg *const arg)
{
	unsigned int	v;
	char			*tab;
	int				len;

	v = (unsigned int)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width;
	if (arg->flags & F_HASH
		&& (len = ft_unsignedlen_base(v, "01234567")) >= arg->precision)
		arg->precision = len + 1;
	if (!(tab = padded_ulltoa_octal(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	tab = (char *)ft_freturn(tab, (long long)ft_strmcat(data->buf, tab, -1));
	if (!tab)
		return (NULL);
	return (data->buf = (char *)ft_freturn(data->buf, (long long)tab));
}

static char			*long_integer(t_printf *const data, t_arg *const arg)
{
	unsigned long	v;
	char			*tab;
	int				len;

	v = (long int)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width;
	if (arg->flags & F_HASH
		&& (len = ft_unsignedlen_base(v, "01234567")) >= arg->precision)
		arg->precision = len + 1;
	if (!(tab = padded_ulltoa_octal(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	tab = (char *)ft_freturn(tab, (long long)ft_strmcat(data->buf, tab, -1));
	if (!tab)
		return (NULL);
	return (data->buf = (char *)ft_freturn(data->buf, (long long)tab));
}

static char			*long_long_integer(t_printf *const data, t_arg *const arg)
{
	unsigned long long	v;
	char				*tab;
	int					len;

	v = (unsigned long long)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width;
	if (arg->flags & F_HASH
		&& (len = ft_unsignedlen_base(v, "01234567")) >= arg->precision)
		arg->precision = len + 1;
	if (!(tab = padded_ulltoa_octal(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	tab = (char *)ft_freturn(tab, (long long)ft_strmcat(data->buf, tab, -1));
	if (!tab)
		return (NULL);
	return (data->buf = (char *)ft_freturn(data->buf, (long long)tab));
}

static char			*short_integer(t_printf *const data, t_arg *const arg)
{
	unsigned short	v;
	char			*tab;
	int				len;

	v = (unsigned short int)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width;
	if (arg->flags & F_HASH
		&& (len = ft_unsignedlen_base(v, "01234567")) >= arg->precision)
		arg->precision = len + 1;
	if (!(tab = padded_ulltoa_octal(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	tab = (char *)ft_freturn(tab, (long long)ft_strmcat(data->buf, tab, -1));
	if (!tab)
		return (NULL);
	return (data->buf = (char *)ft_freturn(data->buf, (long long)tab));
}

static char			*short_short_integer(t_printf *const data, t_arg *const arg)
{
	unsigned char	v;
	char			*tab;
	int				len;

	v = (unsigned char)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width;
	if (arg->flags & F_HASH
		&& (len = ft_unsignedlen_base(v, "01234567")) >= arg->precision)
		arg->precision = len + 1;
	if (!(tab = padded_ulltoa_octal(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	tab = (char *)ft_freturn(tab, (long long)ft_strmcat(data->buf, tab, -1));
	if (!tab)
		return (NULL);
	return (data->buf = (char *)ft_freturn(data->buf, (long long)tab));
}

static char		*intmax_integer(t_printf *const data, t_arg *const arg)
{
	uintmax_t	v;
	char		*tab;
	int			len;

	v = (uintmax_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width;
	if (arg->flags & F_HASH
		&& (len = ft_unsignedlen_base(v, "01234567")) >= arg->precision)
		arg->precision = len + 1;
	if (!(tab = padded_ulltoa_octal(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	tab = (char *)ft_freturn(tab, (long long)ft_strmcat(data->buf, tab, -1));
	if (!tab)
		return (NULL);
	return (data->buf = (char *)ft_freturn(data->buf, (long long)tab));
}

static char		*size_integer(t_printf *const data, t_arg *const arg)
{
	size_t		v;
	char		*tab;
	int			len;

	v = (size_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width;
	if (arg->flags & F_HASH
		&& (len = ft_unsignedlen_base(v, "01234567")) >= arg->precision)
		arg->precision = len + 1;
	if (!(tab = padded_ulltoa_octal(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	tab = (char *)ft_freturn(tab, (long long)ft_strmcat(data->buf, tab, -1));
	if (!tab)
		return (NULL);
	return (data->buf = (char *)ft_freturn(data->buf, (long long)tab));
}

static char		*ptrdiff_integer(t_printf *const data, t_arg *const arg)
{
	ptrdiff_t	v;
	char		*tab;
	int			len;

	v = (ptrdiff_t)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width;
	if (arg->flags & F_HASH
		&& (len = ft_unsignedlen_base(v, "01234567")) >= arg->precision)
		arg->precision = len + 1;
	if (!(tab = padded_ulltoa_octal(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	tab = (char *)ft_freturn(tab, (long long)ft_strmcat(data->buf, tab, -1));
	if (!tab)
		return (NULL);
	return (data->buf = (char *)ft_freturn(data->buf, (long long)tab));
}

static const t_converter	g_funcs[] =
{
	{'H', TRUE, short_short_integer},
	{'h', TRUE, short_integer},
	{' ', TRUE, integer},
	{'j', TRUE, intmax_integer},
	{'l', TRUE, long_integer},
	{'L', TRUE, long_long_integer},
	{'z', TRUE, size_integer},
	{'t', TRUE, ptrdiff_integer},
	{'\0', FALSE, NULL}
};

char	*convert_u_integer_octal(t_printf *data, t_arg *arg)
{
	int			i;
	long long	prec;
	long long	min;

	min = arg->min_width;
	prec = arg->precision;
	i = get_arg(data, arg->flag_idx, &arg->value);
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
