/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:58:22 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/02 17:02:49 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "core/ft_types.h"
# include "ft_printf.h"

static int const g_flags_masks[] =
{
	F_MINS,
	F_ZERO,
	F_PLUS,
	F_SPAC,
	F_HASH,
	F_COLO
};

int			get_min_width(const char *format, t_printf *data, t_arg *arg);
int			get_precision(const char *format, t_printf *data, t_arg *arg);
int			get_chain_format(const char *format, t_printf *data, size_t *v);
int			get_length_modifier(const char *frm, t_printf *data, t_arg *arg);

static int		(*const g_funcs[])(const char *, t_printf *, t_arg *) =
{
	get_min_width,
	get_precision,
	get_length_modifier
};

#endif
