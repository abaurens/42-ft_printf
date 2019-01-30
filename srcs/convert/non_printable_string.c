/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_printable_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:44:41 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/18 19:21:39 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "core/libft.h"

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

	v = (!arg->val.p) ? "(null)" : (char *)arg->val.p;
	if ((len = ft_unprint_strlen(v)) > arg->prec && arg->prec)
		len = arg->prec;
	len += flag(arg, F_HASH) ? 3 : 0;
	if ((tab_len = arg->min) < len)
		tab_len = len;
	if (!(res = malloc(tab_len + 1)))
		return (NULL);
	res[tab_len] = 0;
	ft_memset(res, flag(arg, F_ZERO) ? '0' : ' ', tab_len);
	tab_len -= (flag(arg, F_MINS) ? tab_len : len);
	ft_unprint_strncpy(res + tab_len, v, len, flag(arg, F_HASH));
	insert_buffer(data, res, ft_strlen(res));
	free(res);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, non_printable},
	{'\0', FALSE, NULL}
};

char				*convert_non_printable_string(t_printf *data, t_arg *arg)
{
	int				i;
	int				prec;
	int				min;

	min = arg->min;
	prec = arg->prec;
	i = get_arg_a(data, arg->flag_idx, arg);
	i = (i || (arg->min_idx && get_arg_i(data, arg->min_idx, &min)));
	if (i || (arg->prec_idx && get_arg_i(data, arg->prec_idx, &prec)))
		return (NULL);
	i = 0;
	arg->min = (((int)min) < 0 ? 0 : (int)min);
	arg->prec = (((int)prec) < 0 ? 0 : (int)prec);
	if (flag(arg, F_MINS))
		arg->flags &= ~F_ZERO;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
