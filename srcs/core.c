/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:17:43 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/11 20:39:17 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"
#include "parser.h"///

int				get_non_arg(const char *format, t_printf *data)
{
	char		*tmp;
	size_t		blen;
	size_t		i;

	blen = 0;
	if (!data)
		return (ERROR);
	if (data->buf != NULL)
		blen = ft_strlen(data->buf);
	i = ft_idxof('%', format);
	tmp = data->buf;
	if (!(data->buf = ft_strmcat(tmp, format, blen + i)))
		return (ERROR);
	free(tmp);
	return (i);
}

static void		print_arg_data(t_arg *arg, t_bool idx_given)
{
	int			j;

	j = -1;
	printf("Conversion type : (%c)(%p)\n", arg->conv.c, arg->conv.func);
	printf(" consume argument ? : %s\n", arg->conv.w_arg == 1 ? "Yes" : "No");
	if (arg->conv.w_arg == TRUE)
	{
		printf(" Using $ style ? : %s\n", idx_given == TRUE ? "Yes" : "No");
		printf(" Value index : %lu\n", arg->flag_idx);
	}
	while (FLAGS_V[++j])
		printf(" Flag '%c' : %s\n", FLAGS_V[j],
			(arg->flags & g_flags_masks[j]) ? "YES" : "NO");
	if (arg->min_width_idx != 0 && arg->min_width == 0)
		printf(" Minimum field width index : %lu\n", arg->min_width_idx);
	else
		printf(" Minimum field width : %d\n", arg->min_width);
	if (arg->precision_idx != 0 && arg->precision == 0)
		printf(" Precision index : %lu\n", arg->precision_idx);
	else
		printf(" Precision : %d\n", arg->precision);
	printf(" Length modifier : %d (%c)\n", arg->length_modifier,
		" qjzZtlLhH"[arg->length_modifier]);
}

int				parse_conversion(const char **format, t_printf *data)
{
	t_arg		arg;
	int			i;

	arg.flags = 0;
	arg.flag_idx = 0;
	if (!data || (format && *format && **format && **format != '%'))
		return (ERROR);
	if ((i = parse_arg(format, data, &arg)) < 0)
		return (0);
	if (data->use_chain_format == FALSE)
		arg.flag_idx = ++data->arg_count;
	if (arg.conv.func != NULL)
		arg.conv.func(data, &arg);
	print_arg_data(&arg, data->use_chain_format);
	return (i);
}
