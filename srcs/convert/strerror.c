/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:36:51 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/17 19:52:07 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ft_core.h"
#include "core/ft_error.h"
#include "core/ft_types.h"
#include "libft.h"

static char		*character_string(t_printf *data, t_arg *arg)
{
	char		*v;
	char		*res;
	int			len;
	int			tab_len;

	v = ft_strerror(data->err);
	if ((len = ft_strlen(v)) > arg->prec && arg->prec)
		len = arg->prec;
	if ((tab_len = arg->min) < len)
		tab_len = len;
	if (!(res = malloc(tab_len + 1)))
		return (NULL);
	res[tab_len] = 0;
	ft_memset(res, flag(arg, F_ZERO) ? '0' : ' ', tab_len);
	tab_len -= (flag(arg, F_MINS) ? tab_len : len);
	ft_strncpy(res + tab_len, v, len);
	insert_buffer(data, res, ft_strlen(res));
	free(res);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{' ', TRUE, character_string},
	{'\0', FALSE, NULL}
};

char			*convert_strerror(t_printf *data, t_arg *arg)
{
	int			i;
	long long	prec;
	long long	min;

	min = arg->min;
	prec = arg->prec;
	i = (arg->min_idx && get_arg(data, arg->min_idx, &min));
	if (i || (arg->prec_idx && get_arg(data, arg->prec_idx, &prec)))
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
