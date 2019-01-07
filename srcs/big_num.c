/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:22:26 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/07 22:14:43 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "ft_bigfloat.h"
#include "libft.h"

t_bflt		*new_ftobflt(long double d)
{
	t_float	fl;
	t_bflt	*res;
	t_bflt	*tmp;
	t_bflt	*expo;

	if (d == (1.0 / 0.0))
		return (NULL);
	if (d != d)
		return (NULL);
	fl = get_float_components(d);
	res = get_mantissa(&fl);
	expo = new_bflt(fl.exponent < 0 ? "0.5" : "2");
	while ((expo && res) && fl.exponent--)
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

char		*to_hex(t_bflt *deci)
{
	t_bflt	bse;
	char	*tab;
	char	res[51];
	int		l;

	res[50] = 0;
	set_bflt(&bse, "16.0");
	ft_memset(res, '0', 50);
	while (deci->decl > 0)
		deci = mul_bflt(deci, &bse);
	tab = bflt_tostr(deci);
	l = 0;
	printf("before | %s\n", tab);
	while ((tab[0] != '0' || tab[1] != 0))
	{
		res[l] = "0123456789abcdef"[div_tab(tab, 16)];
		printf("%c\n", res[l]);
		l++;
	}
	printf("%d\n", l);
	printf("res = %s\n", res);
	return (NULL);
}
