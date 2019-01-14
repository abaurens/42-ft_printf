/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:21:47 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/14 16:37:26 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include <unistd.h>
#include <float.h>
#include <math.h>

#include <stdio.h> ///
#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_unwarn.h"

void		print_digits(char *val, const size_t len)
{
	size_t	i;

	i = 0;
	printf("   \e[0;49;32m");
	while (i < len)
	{
		if (val[i] == '.')
			printf(".");
		else
			printf("%d", val[i]);
		i++;
	}
	printf("\e[0m\n");
}

void		print_digits_o(char *val, const size_t len)
{
	size_t	i;

	i = 0;
	printf("   \e[0;49;31m");
	while (i < len)
	{
		if (val[i] == '.')
			printf(".");
		else
			printf("%d", val[i]);
		i++;
	}
	printf("\e[0m\n");
}

char		*rnd(char *val, size_t ln, const size_t prec, const size_t blen)
{
	size_t	i;
	size_t	lim;
	char	*cur;
	char	next;
	char	f;

	f = 0;
	i = ln;
	lim = blen / 2;
	printf("prec = %lu\n", prec);
	printf("i = %lu\n", prec);
	print_digits(val, ln);
	while (--i > (prec + 1))
	{
		printf("val[%lu] = %d\n", i, val[i]);
		f = (f || val[i]);
	}
	i--;
	cur = val + (i - (val[i] == '.'));
	next = i + 1 > ln ? 0 : val[i + 1];
	printf("cur = %d(val[%lu])\n", *cur, (i - (val[i] == '.')));
	printf("next = %d(val[%lu])\n", next, i + 1);
	print_digits(val, ln);
	if (next > lim || (next == lim && (f || (*cur % 2))))
	{
		print_digits_o(val, ln);
		printf("(next > lim || (next == lim && (f || (*cur %% 2))))\n");
		printf("(  %d >   %lu  || (  %d  ==  %lu  && (%d || (  %d  %% 2))))\n", next, lim, next, lim, f, *cur);
		(*cur)++;
	}
	print_digits(val, ln);
	i = ln;
	while (i-- > 1)
	{
		if (val[i] == '.')
			continue;
		if (val[i - 1] != '.')
			val[i - 1] += (val[i] / blen);
		else
			val[i - 2] += (val[i] / blen);
		val[i] %= blen;
	}
	print_digits(val, ln);
	if (*val == blen)
	{
		ft_memmove(val + 1, val, ln++);
		val[0] = val[1] / blen;
		val[1] %= blen;
		print_digits(val, ln);
	}
	print_digits(val, ln);
	return (val);
}

char		*banker_round(char *val, const size_t prec, const char *base)
{
	size_t	i;
	size_t	len;
	size_t	entl;
	size_t	blen;
	char	sign;

	sign = 0;
	if (!val || !base)
		return (val);
	while (ft_contains(*val, " +-") && *(++val))
		sign++;
	entl = ft_idxof('.', val);
	blen = ft_strlen(base);
	if (blen < 2 || !(len = ft_strlen(val)) || prec >= len || !val[entl])
		return (val - sign);
	i = 0;
	while (i < len)
		if (i++ != entl)
			val[i - 1] = ft_idxof(val[i - 1], base);
	rnd(val, len, prec + entl, blen);
	i = 0;
	while (i < len)
		if ((size_t)(val[i++]) < blen)
			val[i - 1] = base[(int)val[i - 1]];
	return (val - sign);
}

int			main(void)
{
	double	d;
	char	*val;
	int		prec;
/*
	ft_printf("%%i validated\n");
	ft_printf("%%d validated\n");
	ft_printf("%%D validated\n");
	ft_printf("%%o validated\n");
	ft_printf("%%O validated\n");
	ft_printf("%%u validated\n");
	ft_printf("%%U validated\n");
	ft_printf("%%x validated\n");
	ft_printf("%%X validated\n");
	ft_printf("%%c validated\n");
	ft_printf("%%C validated\n");
	ft_printf("%%s validated\n");
	ft_printf("%%S validated\n");
	ft_printf("%%p validated\n");

	ft_printf("\n");
*/

	d = 99.995;
	prec = 2;
	while (d <= 1.0 || 1)
	{
		val = NULL;
		asprintf(&val, "% .28f%c", d, 0);
		printf("F:%s\n", val);
		banker_round(val, prec, "0123456789");
		printf("F:%s\n", val);
		printf("R:% .*f\n", prec, d);
		printf("\n");
		free(val);
		d += 0.1;
		exit(10);
	}
	return (0);
}
