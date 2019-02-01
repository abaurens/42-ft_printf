/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:21:12 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/01 15:09:34 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "core/libft.h"

char			*short_short_integer(t_printf *const data, t_arg *const ar)
{
	signed char	v;
	size_t		l;
	char		*tab;

	v = (signed char)ar->val.i;
	if ((l = (ft_numlen(v) - (v < 0))) > (size_t)ar->prec)
		ar->prec = l;
	if (flag(ar, (F_PLUS | F_SPAC)) && v >= 0 && ++l)
		ar->prec++;
	if ((l + (v < 0)) > (size_t)ar->min)
		ar->min = l + (v < 0);
	if (flag(ar, F_ZERO) && ar->prec < ar->min)
		ar->prec = ar->min - (v < 0);
	if (!(tab = padded_lltoa(v, ar->prec, ar->min, flag(ar, F_MINS))))
		return (NULL);
	if (flag(ar, (F_PLUS | F_SPAC)) && (signed char)ar->val.i >= 0)
		tab[ft_idxof('0', tab)] = flag(ar, F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*short_integer(t_printf *const data, t_arg *const ar)
{
	short int	v;
	size_t		l;
	char		*tab;

	v = (short int)ar->val.i;
	if ((l = (ft_numlen(v) - (v < 0))) > (size_t)ar->prec)
		ar->prec = l;
	if (flag(ar, (F_PLUS | F_SPAC)) && v >= 0 && ++l)
		ar->prec++;
	if ((l + (v < 0)) > (size_t)ar->min)
		ar->min = l + (v < 0);
	if (flag(ar, F_ZERO) && ar->prec < ar->min)
		ar->prec = ar->min - (v < 0);
	if (!(tab = padded_lltoa(v, ar->prec, ar->min, flag(ar, F_MINS))))
		return (NULL);
	if (flag(ar, (F_PLUS | F_SPAC)) && (short int)ar->val.i >= 0)
		tab[ft_idxof('0', tab)] = flag(ar, F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*long_integer(t_printf *const data, t_arg *const ar)
{
	long int	v;
	size_t		l;
	char		*tab;

	v = (long int)ar->val.i;
	if ((l = (ft_numlen(v) - (v < 0))) > (size_t)ar->prec)
		ar->prec = l;
	if (flag(ar, (F_PLUS | F_SPAC)) && v >= 0 && ++l)
		ar->prec++;
	if ((l + (v < 0)) > (size_t)ar->min)
		ar->min = l + (v < 0);
	if (flag(ar, F_ZERO) && ar->prec < ar->min)
		ar->prec = ar->min - (v < 0);
	if (!(tab = padded_lltoa(v, ar->prec, ar->min, flag(ar, F_MINS))))
		return (NULL);
	if (flag(ar, (F_PLUS | F_SPAC)) && (long int)ar->val.i >= 0)
		tab[ft_idxof('0', tab)] = flag(ar, F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char			*long_long_integer(t_printf *const data, t_arg *const ar)
{
	long long	v;
	size_t		l;
	char		*tab;

	v = (long long)ar->val.i;
	if ((l = (ft_numlen(v) - (v < 0))) > (size_t)ar->prec)
		ar->prec = l;
	if (flag(ar, (F_PLUS | F_SPAC)) && v >= 0 && ++l)
		ar->prec++;
	if ((l + (v < 0)) > (size_t)ar->min)
		ar->min = l + (v < 0);
	if (flag(ar, F_ZERO) && ar->prec < ar->min)
		ar->prec = ar->min - (v < 0);
	if (!(tab = padded_lltoa(v, ar->prec, ar->min, flag(ar, F_MINS))))
		return (NULL);
	if (flag(ar, (F_PLUS | F_SPAC)) && (long long)ar->val.i >= 0)
		tab[ft_idxof('0', tab)] = flag(ar, F_PLUS) ? '+' : ' ';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
