/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:31:35 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/14 20:05:51 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "ft_types.h"
#include "converter.h"
#include "libft.h"

static size_t			ft_wstrlen(const wchar_t *wstr)
{
	register wchar_t	*s;
	register size_t		l;

	l = 0;
	s = (wchar_t *)wstr;
	while (*s)
	{
		l++;
		if (*s >= 0x80)
			l++;
		if (*s >= 0x800)
			l++;
		if (*s >= 0x10000)
			l++;
		s++;
	}
	return (l);
}

static size_t			wchartochars(char *dst, wchar_t c)
{
	char				u[4];
	size_t				len;

	len = 1;
	ft_bzero(u, 4);
	u[3] = (c & 0b01111111);
	if (c >= 0x80 && len++)
	{
		u[3] = 0b10000000 | (c & 0b00111111);
		u[2] = 0b11000000 | ((c >> 6) & 0b00011111);
		if (c >= 0x800 && len++)
		{
			u[2] = 0b10000000 | ((c >> 6) & 0b00111111);
			u[1] = 0b11100000 | ((c >> 12) & 0b00001111);
			if (c >= 0x10000 && len++)
			{
				u[1] = 0b10000000 | ((c >> 12) & 0b00111111);
				u[0] = 0b11110000 | ((c >> 18) & 0b00000111);
			}
		}
	}
	ft_memcpy(dst, u + (4 - len), len);
	return (len);
}

static char				*ft_wstrtostr(char *dst, const wchar_t *src)
{
	char				l;
	char				*d;

	d = (char *)dst;
	while (*src)
	{
		l = wchartochars(d, *src);
		d += l;
		src++;
	}
	*d = 0;
	return (dst);
}

char					*wide_character(t_printf *data, t_arg *arg)
{
	wchar_t				v[2];
	char				*res;
	int					len;
	size_t				wchr_ln;
	int					tab_len;

	v[1] = 0;
	wchr_ln = sizeof(wchar_t);
	if (!(*v = (wchar_t)arg->value))
		return (data->buf);
	if ((len = ft_wstrlen(v)) > arg->precision && arg->precision)
		len = arg->precision;
	if ((tab_len = arg->min_width) < len)
		tab_len = len;
	if (!(res = malloc((wchr_ln * tab_len) + 1)))
		return (NULL);
	res[wchr_ln * tab_len] = 0;
	ft_memset(res, (arg->flags & F_ZERO) ? '0' : ' ', wchr_ln * tab_len);
	tab_len -= ((arg->flags & F_MINS) ? tab_len : len);
	ft_wstrtostr(res, v);
	res = (char *)ft_freturn(res, (long long)ft_strmcat(data->buf, res, -1));
	if (!res)
		return (NULL);
	data->buf = (char *)ft_freturn(data->buf, (long long)res);
	return (res);
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, wide_character},
	{'\0', FALSE, NULL}
};

char					*convert_wide_char(t_printf *data, t_arg *arg)
{
	int					i;
	long long			prec;
	long long			min;

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
