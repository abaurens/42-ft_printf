/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 19:22:34 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/08 16:34:11 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static char		*round_int_part(char *val)
{
	size_t		i;
	char		cary;
	char		sign;

	i = ft_idxof('.', val);
	if (val && (sign = ft_contains(*val, " +-")))
		val++;
	while (val && i-- > 0)
		if ((cary = (val[i] - '0') / 10))
		{
			if (i > 0)
				val[i - 1] += cary;
			val[i] = '0';
		}
	if (val && sign)
		val--;
	if (val && cary)
	{
		if (!(val = (char *)ft_freturn(val, (long)ft_strmcat("0", val, -1))))
			return (NULL);
		if ((val[1] < '0' || val[1] > '9') && (*val = val[1]))
			val[1] = cary + '0';
	}
	return (val);
}

static char		*round_scientific(char *val, int *exp)
{
	char		sign;

	if (val && (sign = ft_contains(*val, " +-")))
		val++;
	if (val && *val > '9')
	{
		*val = '1';
		(*exp)++;
	}
	if (val && sign)
		val--;
	return (val);
}

char			*round_tabflt(char *val, size_t prec, int *exp)
{
	size_t		i;
	size_t		entl;

	i = ft_idxof(0, val);
	entl = ft_idxof('.', val);
	if (i && (!ft_strcmp(val, "nan") || !ft_strcmp(val + (*val == '-'), "inf")))
		return (val);
	while (val && i-- > entl + prec + 1)
		if (val[i] > '5' || (val[i - 1] != '.' && val[i] >= '5'))
			val[i - (val[i - 1] == '.' ? 2 : 1)]++;
	if (val && (val[entl] == '.' && val[entl + 1] == '5' && val[entl + 2] != 0))
		val[entl - 1]++;
	i++;
	while (val && i-- > entl)
		if (val[i] != '.' && val[i] > '9')
		{
			val[i - (val[i - 1] == '.' ? 2 : 1)]++;
			val[i] = '0';
		}
	return (exp ? round_scientific(val, exp) : round_int_part(val));
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

	if (val && (sign = ft_contains(*val, " +-")))
		val++;
	len = ft_idxof(0, val);
	i = len;
	while (val && i-- > 0)
		val[i] = val[i] == '.' ? '.' : ft_idxof(val[i], "0123456789abcdef");
	val = round_hex_core(val, prec, len);
	if (val && *val >= 16 && (*val = 1))
		(*exp) += 4;
	i = 0;
	while (val && i++ < len)
		if (val[i - 1] != '.')
			val[i - 1] = "0123456789abcdef"[(int)val[i - 1]];
	if (val && sign)
		val--;
	return (val);
}
