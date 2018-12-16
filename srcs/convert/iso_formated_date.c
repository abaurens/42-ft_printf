/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_formated_date.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:45:31 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/16 20:29:47 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "ft_types.h"
#include "libft.h"

static void		get_time_iso(char str[21], time_t time)
{
	int			i;
	int			j;
	t_tm		tm;
	char		*sep;
	int			tab[6];

	j = -1;
	sep = "--T::Z";
	tm = *localtime(&time);
	tab[0] = tm.tm_year + 1900;
	tab[1] = tm.tm_mon + 1;
	tab[2] = tm.tm_mday;
	tab[3] = tm.tm_hour;
	tab[4] = tm.tm_min;
	tab[5] = tm.tm_sec;
	while (++j < 6 && (i = -1))
	{
		while (++i < (!j ? 4 : 2))
		{
			str[(!j ? 3 : 1) - i] = (tab[j] % 10 + '0');
			tab[j] /= 10;
		}
		str[i++] = sep[j];
		str += i;
	}
}

static const char *g_months[] =
{
	"Jan ",
	"Feb ",
	"Mar ",
	"Apr ",
	"May ",
	"Jun ",
	"Jul ",
	"Aug ",
	"Sep ",
	"Oct ",
	"Nov ",
	"Dec ",
	NULL
};

static void		get_time_ls(char str[21], time_t cur_time)
{
	t_tm		tm;
	char		year[4];
	time_t		rest;

	tm = *localtime(&cur_time);
	ft_memcpy(year, str, 4);
	ft_strcpy(str, g_months[tm.tm_mon]);
	ft_memmove(str + 4, str + 8, 3);
	if (str[4] == '0')
		str[4] = ' ';
	ft_memcpy(str + 6, "  ", 2);
	if ((rest = (time(NULL) - cur_time)) < 0 || rest >= 15728400)
		ft_memcpy(str + 8, year, 4);
	else
		ft_memmove(str + 7, str + 11, 5);
	ft_bzero(str + 12, 9);
}

static char		*date(t_printf *data, t_arg *arg)
{
	char		str[21];
	char		*res;
	int			len;
	int			tab_len;

	ft_bzero(str, 21);
	get_time_iso(str, (time_t)arg->value);
	if ((arg->flags & F_HASH))
		get_time_ls(str, (time_t)arg->value);
	if ((len = ft_strlen(str)) > arg->precision && arg->precision)
		len = arg->precision;
	if ((tab_len = arg->min_width) < len)
		tab_len = len;
	if (!(res = malloc(tab_len + 1)))
		return (NULL);
	res[tab_len] = 0;
	ft_memset(res, (arg->flags & F_ZERO) ? '0' : ' ', tab_len);
	tab_len -= ((arg->flags & F_MINS) ? tab_len : len);
	ft_strncpy(res + tab_len, str, len);
	res = (char *)ft_freturn(res, (long long)ft_strmcat(data->buf, res, -1));
	if (!res)
		return (NULL);
	free(data->buf);
	data->buf = res;
	return (res);
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, date},
	{'\0', FALSE, NULL}
};

char			*convert_iso_date(t_printf *data, t_arg *arg)
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
	arg->min_width = (((int)min) < 0 ? 0 : (int)min);
	if ((arg->precision = (((int)prec) < 0 ? 0 : (int)prec))
		|| (arg->flags & F_MINS))
		arg->flags &= ~F_ZERO;
	i = 0;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}
