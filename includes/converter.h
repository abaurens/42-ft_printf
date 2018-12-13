/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:53:50 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/13 20:44:12 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# include "ft_types.h"

# define NO_ARG "%"
# define CONV_V "diuoxXfFeEgGaAcCsSpnmbrk"

/*
**	i, d = signed decimal
**	o = unsigned octal
**	u = unsigned decimal
**	x, X = unsigned hexadecimal (low and up case)
**	f = double (and floats casted to double)
**	F = double (and floats casted to double) but NAN and INFINITY are upcase
**	e = double (and floats casted to double) but printd in the form xxxxe+-yyy
**	E = same as e but the exposant letter 'e' is upcase
**	g = the most compact between f and e
**	G = same as g but between f and E
**	a = double (and floats casted to double) in lowcase hexadecimal
**		with the form [-]0xh.hhhhp+-dd
**	A = double (and floats casted to double) in upcase hexadecimal
**		with the form [-]0Xh.hhhhP+-dd (same as a, but X and P are upcase)
**	c = 1 byte character
**	C = wide character (wchar)
**	s = 1 byte character string
**	S = wide character string
**	p = pointer address (in hexadecimal format)
**	n = place the number of character writed by this printf until this
**		convertion into an int pointer
**	m = prints the value of strerror(errno) (NO ARG)
**	% = only print a percent char
**		(because % is used to escape conversions) (NO ARG)
**
**	b = nombre binaire
**	r = string avec caracteres non imprimable
**	k = date au format ISO
*/

/*
**	convert/
*/
char			*convert_percent(t_printf *data, t_arg *arg);
char			*convert_integer(t_printf *const data, t_arg *const arg);
char			*convert_u_integer(t_printf *data, t_arg *arg);
char			*convert_u_integer_octal(t_printf *data, t_arg *arg);
char			*convert_u_integer_hexa(t_printf *data, t_arg *arg);
char			*convert_double_floating(t_printf *data, t_arg *arg);
char			*convert_double_scientific(t_printf *data, t_arg *arg);
char			*convert_double_compact(t_printf *data, t_arg *arg);
char			*convert_double_hexa(t_printf *data, t_arg *arg);
char			*convert_char(t_printf *data, t_arg *arg);
char			*convert_wide_char(t_printf *data, t_arg *arg);
char			*convert_string(t_printf *data, t_arg *arg);
char			*convert_wide_char_string(t_printf *data, t_arg *arg);
char			*convert_pointer(t_printf *data, t_arg *arg);
char			*convert_length(t_printf *data, t_arg *arg);
char			*convert_strerror(t_printf *data, t_arg *arg);
char			*convert_u_integer_binary(t_printf *data, t_arg *arg);
char			*convert_non_printable_string(t_printf *data, t_arg *arg);
char			*convert_iso_date(t_printf *data, t_arg *arg);

static const t_converter	g_converters[] =
{
	{'%', FALSE, convert_percent},
	{'d', TRUE, convert_integer},
	{'i', TRUE, convert_integer},
	{'u', TRUE, convert_u_integer},
	{'o', TRUE, convert_u_integer_octal},
	{'x', TRUE, convert_u_integer_hexa},
	{'X', TRUE, convert_u_integer_hexa},
	{'f', TRUE, convert_double_floating},
	{'F', TRUE, convert_double_floating},
	{'e', TRUE, convert_double_scientific},
	{'E', TRUE, convert_double_scientific},
	{'g', TRUE, convert_double_compact},
	{'G', TRUE, convert_double_compact},
	{'a', TRUE, convert_double_hexa},
	{'A', TRUE, convert_double_hexa},
	{'c', TRUE, convert_char},
	{'C', TRUE, convert_wide_char},
	{'s', TRUE, convert_string},
	{'S', TRUE, convert_wide_char_string},
	{'p', TRUE, convert_pointer},
	{'n', TRUE, convert_length},
	{'m', FALSE, convert_strerror},
	{'b', TRUE, convert_u_integer_binary},
	{'r', TRUE, convert_non_printable_string},
	{'k', TRUE, convert_iso_date},
	{'\0', MAYBE, (void *)0x0}
};

#endif
