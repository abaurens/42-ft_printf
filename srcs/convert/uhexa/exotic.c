/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exotic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:57:11 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/13 17:00:55 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

char				*intmax_hexa(t_printf *const data, t_arg *const arg)
{
	uintmax_t		v;
	int				len;
	char			*tab;

	v = (uintmax_t)arg->value;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->precision)
		arg->precision = len;
	if ((arg->flags & F_HASH) && v != 0)
		arg->precision += 2;
	if (arg->flags & F_ZERO && arg->min_width > arg->precision)
		arg->precision = arg->min_width;
	if (!(tab = padded_ulltoa_hexa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*size_hexa(t_printf *const data, t_arg *const arg)
{
	size_t			v;
	int				len;
	char			*tab;

	v = (size_t)arg->value;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->precision)
		arg->precision = len;
	if ((arg->flags & F_HASH) && v != 0)
		arg->precision += 2;
	if (arg->flags & F_ZERO && arg->min_width > arg->precision)
		arg->precision = arg->min_width;
	if (!(tab = padded_ulltoa_hexa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*ssize_hexa(t_printf *const data, t_arg *const arg)
{
	ssize_t			v;
	int				len;
	char			*tab;

	v = (ssize_t)arg->value;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->precision)
		arg->precision = len;
	if ((arg->flags & F_HASH) && v != 0)
		arg->precision += 2;
	if (arg->flags & F_ZERO && arg->min_width > arg->precision)
		arg->precision = arg->min_width;
	if (!(tab = padded_ulltoa_hexa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*ptrdiff_hexa(t_printf *const data, t_arg *const arg)
{
	ptrdiff_t		v;
	int				len;
	char			*tab;

	v = (ptrdiff_t)arg->value;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->precision)
		arg->precision = len;
	if ((arg->flags & F_HASH) && v != 0)
		arg->precision += 2;
	if (arg->flags & F_ZERO && arg->min_width > arg->precision)
		arg->precision = arg->min_width;
	if (!(tab = padded_ulltoa_hexa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*quad_hexa(t_printf *const data, t_arg *const arg)
{
	u_quad_t		v;
	int				len;
	char			*tab;

	v = (u_quad_t)arg->value;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->precision)
		arg->precision = len;
	if ((arg->flags & F_HASH) && v != 0)
		arg->precision += 2;
	if (arg->flags & F_ZERO && arg->min_width > arg->precision)
		arg->precision = arg->min_width;
	if (!(tab = padded_ulltoa_hexa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	if ((arg->flags & F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
