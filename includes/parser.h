/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:58:22 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/11 16:29:40 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ft_printf.h"

# define F_MINS	0b00000001
# define F_ZERO	0b00000010
# define F_PLUS	0b00000100
# define F_SPAC 0b00001000
# define F_HASH 0b00010000
# define F_COLO 0b00100000
# define F_CAPI 0b01000000
# define FLAGS_V "-0+ #'I"
# define FLAG_C 7

/*
**	I = print the value with the locale digits if any (only used for i, u and d)
*/

# define LEN_MD "qjzZtlLh"

extern int	(*const g_funcs[])(const char *, t_printf *, t_arg *);

static int const g_flags_masks[] =
{
	F_MINS,
	F_ZERO,
	F_PLUS,
	F_SPAC,
	F_HASH,
	F_COLO,
	F_CAPI
};

int			get_chain_format(const char *format, t_printf *data, int *val);

#endif
