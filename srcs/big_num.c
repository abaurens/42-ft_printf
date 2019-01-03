/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:22:26 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/03 15:52:43 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "ft_bigfloat.h"
#include "libft.h"

t_bflt			*two_pow(int pow)
{
	t_bflt		two;
	t_bflt		*tmp;
	t_bflt		*res;

	if (!set_bflt(&two, pow < 0 ? "0.5" : "2.0"))
		return (NULL);
	res = new_bflt("1.0");
	while (res && pow != 0)
	{
		tmp = res;
		res = mul_bflt(&two, res);
		del_bflt(tmp);
		pow < 0 ? ++pow : --pow;
	}
	unset_bflt(&two);
	return (res);
}
