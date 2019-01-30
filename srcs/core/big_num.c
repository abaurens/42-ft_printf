/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:22:26 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/30 14:27:48 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "ft_bigfloat.h"
#include "libft.h"

t_bflt					*new_ftobflt(long double d)
{
	t_float				fl;
	t_bflt				*res;
	t_bflt				*tmp;
	t_bflt				*expo;

	if (d == (1.0 / 0.0))
		return (NULL);
	if (d != d)
		return (NULL);
	fl = get_float_components(d);
	res = get_mantissa(&fl);
	expo = new_bflt(fl.exponent < 0 ? "0.5" : "2");
	while ((expo && res) && fl.exponent < 0 ? fl.exponent++ : fl.exponent--)
	{
		tmp = res;
		res = mul_bflt(expo, res);
		del_bflt(tmp);
	}
	del_bflt(expo);
	return (res);
}

/*
**	This function stores the division of the ascii formated number
**	given as argument by div in the same argument argument (like '/=' op).
**	This means v has to be allocated and that it WILL be changed.
**	This function also gives the modulus as return value.
*/

static unsigned long	div_tab(char *v, unsigned long div)
{
	size_t				i;
	unsigned long		d;
	char				*nb;
	char				first;

	i = 0;
	d = 0;
	nb = v;
	first = 1;
	while (v && *v)
	{
		d = (d * 10 + (*v++ - '0'));
		while (first && *v && d < div)
			d = (d * 10 + (*v++ - '0'));
		nb[i++] = (d / div) + '0';
		d %= div;
		if (first)
			first = 0;
	}
	if (v && !*v)
		nb[i] = 0;
	return (d);
}

static char				*to_hex_two(char *tab, char *res)
{
	size_t				l;

	l = 0;
	while ((tab[0] != '0' || tab[1] != 0) && ++l)
		div_tab(tab, 16);
	tab = (char *)ft_freturn(tab, (long)res);
	if (!(res = ft_memalloc(l + 3)))
		return ((char *)ft_freturn(tab, 0x0));
	while ((tab[0] != '0' || tab[1] != 0))
		res[l--] = HEXA[div_tab(tab, 16)];
	res[0] = (char)ft_freturn(tab, (long)res[1]);
	res[1] = '.';
	return (res);
}

char					*to_hex(t_bflt *deci)
{
	t_bflt				base;
	t_bflt				*tmp;
	char				*tab;
	char				*res;
	int					l;

	l = 0;
	set_bflt(&base, "16.0");
	while (deci && deci->decl > 0 && (tmp = deci))
		if ((deci = mul_bflt(deci, &base)) && l++)
			del_bflt(tmp);
	unset_bflt(&base);
	if (!(tab = bflt_tostr(deci)) || l)
		del_bflt(deci);
	if (!tab || !(res = ft_strdup(tab)))
		return ((char *)ft_freturn(tab, 0x0));
	tab[ft_idxof('.', tab)] = 0;
	res[ft_idxof('.', res)] = 0;
	return (to_hex_two(tab, res));
}
