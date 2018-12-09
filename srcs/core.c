/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:17:43 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/09 17:46:27 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

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

static void		print_arg_data(t_arg *arg, t_bool use_chain_format)
{
	int			j;

	j = -1;
	printf("Conversion type : %d (%c)\n", arg->conv_id, arg->conv_c);
	printf(" consume argument ? : %s\n", arg->w_arg == TRUE ? "Yes" : "No");
	printf(" Using $ style ? : %s\n", use_chain_format == TRUE ? "Yes" : "No");
	if (use_chain_format == TRUE)
		printf(" Value index : %d\n", arg->flag_idx);
	while (FLAGS_V[++j])
		printf(" Flag '%c' : %d\n", FLAGS_V[j],
			(arg->flags & g_flags_masks[j]) != 0);
	if (use_chain_format == TRUE && arg->precision == 0)
		printf(" Precision index : %d\n", arg->precision_idx);
	else
		printf(" Precision : %d\n", arg->precision);
	if (use_chain_format == TRUE && arg->min_width == 0)
		printf(" Minimum field width index : %d\n", arg->min_width_idx);
	else
		printf(" Minimum field width : %d\n", arg->min_width);
	printf(" Length modifier : %d (%c)\n", arg->length_modifier,
		" qjzZtlLhH"[arg->length_modifier]);
}

int				get_arg(const char **format, t_printf *data)
{
	t_arg		arg;
	int			i;

	if (!data || (format && *format && **format && **format != '%'))
		return (ERROR);
	if ((i = parse_arg(format, data, &arg)) < 0)
		return (0);
	print_arg_data(&arg, data->use_chain_format);
	return (i);
}
