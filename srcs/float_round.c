/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 19:22:34 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/04 17:50:53 by abaurens         ###   ########.fr       */
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
		if (val[i] >= '5')
		{
			val[i - (val[i - 1] == '.' ? 2 : 1)]++;
			val[i] = '0';
		}
	i++;
	while (val && i-- > entl)
		if (val[i] != '.' && val[i] > '9')
		{
			val[i - (val[i - 1] == '.' ? 2 : 1)]++;
			val[i] = '0';
		}
	return (exp ? round_scientific(val, exp) : round_int_part(val));
}
