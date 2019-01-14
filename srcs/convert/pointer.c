/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:18:44 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/13 19:15:38 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_types.h"
#include "core/ft_core.h"
#include "core/converter.h"
#include "libft.h"

static char			*long_hexa_ptr(t_printf *const data, t_arg *const arg)
{
	unsigned long	v;
	int				len;
	char			*tab;

	v = (long int)arg->value;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->precision)
		arg->precision = len;
	arg->precision += 2;
	if (arg->flags & F_ZERO && arg->min_width > arg->precision)
		arg->precision = arg->min_width;
	if (!(tab = padded_ulltoa_hexa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char	*convert_pointer(t_printf *data, t_arg *arg)
{
	int				i;
	long long		min;
	long long		prec;

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
	return (long_hexa_ptr(data, arg));
}
