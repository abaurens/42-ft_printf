/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:17:28 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/16 20:39:49 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_types.h"
#include "libft.h"

static char		*integer(t_printf *const data, t_arg *const arg)
{
	int			*v;

	v = (int *)arg->value;
	*v = ft_strlen(data->buf);
	return (data->buf);
}

static char		*long_integer(t_printf *const data, t_arg *const arg)
{
	long int	*v;

	v = (long int *)arg->value;
	*v = ft_strlen(data->buf);
	return (data->buf);
}

static char		*long_long_integer(t_printf *const data, t_arg *const arg)
{
	long long	*v;

	v = (long long int *)arg->value;
	*v = ft_strlen(data->buf);
	return (data->buf);
}

static char		*short_integer(t_printf *const data, t_arg *const arg)
{
	short int	*v;

	v = (short int *)arg->value;
	*v = ft_strlen(data->buf);
	return (data->buf);
}

static char		*short_short_integer(t_printf *const data, t_arg *const arg)
{
	signed char	*v;

	v = (signed char *)arg->value;
	*v = ft_strlen(data->buf);
	return (data->buf);
}

static char		*intmax_integer(t_printf *const data, t_arg *const arg)
{
	intmax_t	*v;

	v = (intmax_t *)arg->value;
	*v = ft_strlen(data->buf);
	return (data->buf);
}

static char		*size_integer(t_printf *const data, t_arg *const arg)
{
	size_t		*v;

	v = (size_t *)arg->value;
	*v = ft_strlen(data->buf);
	return (data->buf);
}

static char		*ssize_integer(t_printf *const data, t_arg *const arg)
{
	ssize_t		*v;

	v = (ssize_t *)arg->value;
	*v = ft_strlen(data->buf);
	return (data->buf);
}

static char		*ptrdiff_integer(t_printf *const data, t_arg *const arg)
{
	ptrdiff_t	*v;

	v = (ptrdiff_t *)arg->value;
	*v = ft_strlen(data->buf);
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
	{'q', TRUE, long_long_integer},
	{'z', TRUE, size_integer},
	{'Z', TRUE, ssize_integer},
	{'t', TRUE, ptrdiff_integer},
	{'\0', FALSE, NULL}
};

char			*convert_length(t_printf *data, t_arg *arg)
{
	int			i;

	i = 0;
	if (get_arg(data, arg->flag_idx, &arg->value))
		return (NULL);
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
