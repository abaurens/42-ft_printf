/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:28:50 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/12 22:58:34 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_types.h"
#include "ft_printf.h"

void		print_arg_data(t_arg *arg, t_bool idx_given)
{
	int		j;

	j = -1;
	printf("Conversion type : (%c)(%p)\n", arg->conv.c, arg->conv.func);
	printf(" consume argument ? : %s\n", arg->conv.w_arg == 1 ? "Yes" : "No");
	if (arg->conv.w_arg == TRUE)
	{
		printf(" Using $ style ? : %s\n", idx_given == TRUE ? "Yes" : "No");
		printf(" Value index : %lu\n", arg->flag_idx);
		printf(" Value : %lld\n", arg->value);
	}
	while (FLAGS_V[++j])
		printf(" Flag '%c' : %s\n", FLAGS_V[j],
			(arg->flags & g_flags_masks[j]) ? "YES" : "NO");
	if (arg->min_width_idx != 0)
		printf(" Minimum field width index : %lu\n", arg->min_width_idx);
	printf(" Minimum field width : %d\n", arg->min_width);
	if (arg->precision_idx != 0)
		printf(" Precision index : %lu\n", arg->precision_idx);
	printf(" Precision : %d\n", arg->precision);
	printf(" Length modifier : %d (%c)\n", arg->length_modifier,
		LEN_MD_CHRS[arg->length_modifier]);
}
