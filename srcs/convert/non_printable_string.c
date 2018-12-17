/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_printable_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:44:41 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/17 16:14:49 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "ft_types.h"
#include "libft.h"

static size_t		ft_unprint_strlen(const char *s)
{
	register size_t	i;
	register size_t	len;

	i = 0;
	len = 0;
	while (s && s[i])
	{
		if (!ft_isprint(s[i++]))
			len += 2;
		len++;
	}
	return (len);
}

static char			*ft_unprint_strncpy(char *dest, char *src, size_t n, char l)
{
	register char	*d;
	register char	*s;

	d = dest;
	s = src;
	if (n <= 0 || !dest || !src)
		return (dest);
	while (*s || l)
	{
		if (*s == 0)
			l = 0;
		*d = *s;
		if (!ft_isprint(*s))
		{
			*d++ = '\\';
			*(d + 1) = "0123456789abcdef"[(*s % 16)];
			*d++ = "0123456789abcdef"[((*s / 16) % 16)];
		}
		d++;
		if (*s)
			s++;
	}
	return (dest);
}

static char			*non_printable(t_printf *data, t_arg *arg)
{
	char		*v;
	char		*res;
	int			len;
	int			tab_len;

	v = (!arg->value) ? "(null)" : (char *)arg->value;
	if ((len = ft_unprint_strlen(v)) > arg->precision && arg->precision)
		len = arg->precision;
	len += (arg->flags & F_HASH) ? 3 : 0;
	if ((tab_len = arg->min_width) < len)
		tab_len = len;
	if (!(res = malloc(tab_len + 1)))
		return (NULL);
	res[tab_len] = 0;
	ft_memset(res, (arg->flags & F_ZERO) ? '0' : ' ', tab_len);
	tab_len -= ((arg->flags & F_MINS) ? tab_len : len);
	ft_unprint_strncpy(res + tab_len, v, len, (arg->flags & F_HASH));
	res = (char *)ft_freturn(res, (long long)ft_strmcat(data->buf, res, -1));
	if (!res)
		return (NULL);
	free(data->buf);
	data->buf = res;
	return (res);
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, non_printable},
	{'\0', FALSE, NULL}
};

char				*convert_non_printable_string(t_printf *data, t_arg *arg)
{
	int				i;
	long long		prec;
	long long		min;

	min = arg->min_width;
	prec = arg->precision;
	i = get_arg(data, arg->flag_idx, &arg->value);
	i = (i || (arg->min_width_idx && get_arg(data, arg->min_width_idx, &min)));
	if (i || (arg->precision_idx && get_arg(data, arg->precision_idx, &prec)))
		return (NULL);
	i = 0;
	arg->min_width = (((int)min) < 0 ? 0 : (int)min);
	arg->precision = (((int)prec) < 0 ? 0 : (int)prec);
	if (arg->flags & F_MINS)
		arg->flags &= ~F_ZERO;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
