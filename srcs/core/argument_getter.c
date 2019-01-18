/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_getter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:23:09 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/18 19:29:36 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

t_val				get_pointer(va_list ap, const char t, const int l)
{
	t_val			ret;

	((void)t);
	((void)l);
	ret.lf = 0.0;
	ret.p = ((void *)va_arg(ap, intptr_t));
	return (ret);
}

t_val				get_double(va_list ap, const char t, const int l)
{
	t_val			ret;

	((void)t);
	ret.lf = 0.0;
	if (LEN_MD_CHRS[l] == 'L')
		ret.lf = ((long double)va_arg(ap, long double));
	else
		ret.f = ((double)va_arg(ap, double));
	return (ret);
}

t_val				get_integer(va_list ap, const char t, const int l)
{
	t_val			ret;

	ret.lf = 0.0;
	((void)t);
	if (LEN_MD_CHRS[l] == 'q')
		ret.i = ((long long int)va_arg(ap, quad_t));
	else if (LEN_MD_CHRS[l] == 'j')
		ret.i = ((long long int)va_arg(ap, intmax_t));
	else if (LEN_MD_CHRS[l] == 'z')
		ret.i = ((long long int)va_arg(ap, size_t));
	else if (LEN_MD_CHRS[l] == 'Z')
		ret.i = ((long long int)va_arg(ap, ssize_t));
	else if (LEN_MD_CHRS[l] == 't')
		ret.i = ((long long int)va_arg(ap, ptrdiff_t));
	else if (LEN_MD_CHRS[l] == 'l')
		ret.i = ((long long int)va_arg(ap, long));
	else if (LEN_MD_CHRS[l] == 'L')
		ret.i = ((long long int)va_arg(ap, long long));
	else if (LEN_MD_CHRS[l] == 'h')
		ret.i = ((long long int)va_arg(ap, int));
	else if (LEN_MD_CHRS[l] == 'H')
		ret.i = ((long long int)va_arg(ap, int));
	else
		ret.i = ((long long int)va_arg(ap, int));
	return (ret);
}
