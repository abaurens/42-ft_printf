/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 19:22:34 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/16 19:56:34 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "core/ft_core.h"
#include "libft.h"

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
			printf("%3d", val[i]);
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
			printf("%3d", val[i]);
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
	if (prec + 1 >= ln)
		return (val);
	while (--i > (prec + 1))
		f = (blen == 10 && (f || val[i]));
	i--;
	cur = val + (i - (val[i] == '.'));
	next = i + 1 > ln ? 0 : val[i + 1];
	f = (f || (i + 2 > ln ? 0 : val[i + 2]) % 2);
	if ((size_t)next > lim || ((size_t)next == lim && (f || (blen == 10 && *cur % 2))))
		(*cur)++;
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
	if ((size_t)(*val) == blen)
	{
		ft_memmove(val + 1, val, ln++);
		*val = val[1] / blen;
		val[1] %= blen;
	}
	return (val);
}

char			*banker_round(char *val, const size_t prec, const char *base)
{
	size_t		i;
	size_t		len;
	size_t		entl;
	size_t		blen;
	char		sign;

	sign = 0;
	if (!val || !base)
		return (val);
	entl = ft_idxof('.', val);
	blen = ft_strlen(base);
	if (blen < 2 || !(len = ft_strlen(val)) || prec >= len || !val[entl])
		return (val);
	i = 0;
	while (i < len)
		if (i++ != entl)
			val[i - 1] = ft_idxof(val[i - 1], base);
	rnd(val, len, prec + entl, blen);
	i = 0;
	while (i < len)
		if ((size_t)(val[i++]) < blen)
			val[i - 1] = base[(int)val[i - 1]];
	return (val);
}

char			*round_tabflt(char *val, size_t prec, int *exp)
{
	size_t		point;
	char		sign;

	sign = 0;
	if (!ft_strchr(val, '.'))
		return (val);
	while (ft_contains(*val, " +-") && *(++val))
		sign++;
	banker_round(val, prec, DECI);
	if (exp && (point = ft_idxof('.', val)) != 1 && (*exp)++)
		*(((char *)ft_memmove(val + 2, val + 1, point - 1)) - 1) = '.';
	return (val - sign);
}

static char		*round_hex_core(char *val, size_t prec, size_t len)
{
	size_t		i;
	size_t		entl;

	i = len;
	entl = 0;
	while (entl < len && val[entl] != '.')
		++entl;
	while (val && i-- > entl + prec + 1)
		if (val[i] > 8 || (val[i - 1] != '.' && val[i] >= 8))
			val[i - ((val[i - 1] == '.') + 1)]++;
	if (val && (val[entl] == '.' && val[entl + 1] == 58 && val[entl + 2] != 0))
		val[entl - 1]++;
	++i;
	while (val && i-- > entl)
		if (val[i] != '.' && val[i] >= 16)
		{
			val[i - (val[i - 1] == '.' ? 2 : 1)]++;
			val[i] = 0;
		}
	return (val);
}

char			*round_hex(char *val, size_t prec, int *exp)
{
	size_t		i;
	size_t		len;
	char		sign;
	size_t		point;

	sign = 0;
	if (!val || !exp)
		return (val);
	while (ft_contains(*val, " +-") && *(++val))
		sign++;
	len = ft_strlen(val);
	i = len;
	banker_round(val, prec, HEXA);
	if (exp && (point = ft_idxof('.', val)) != 1 && ((*exp) += 4))
		*(((char *)ft_memmove(val + 2, val + 1, point - 1)) - 1) = '.';
	return (val - sign);
}
