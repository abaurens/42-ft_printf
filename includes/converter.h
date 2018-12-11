/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:53:50 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/11 16:01:02 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# define NO_ARG "%"
# define CONV_V "diuoxXfFeEgGaAcCsSpnmbrk"

# ifndef STRUCT_S_CONVERTER_DEFINED
#  define STRUCT_S_CONVERTER_DEFINED

typedef struct	s_converter
{
	char		c;
	int			id;
	void		(*func)(void);
}				t_converter;

# endif

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
void			convert_percent(void);
void			convert_integer(void);
void			convert_integer(void);
void			convert_u_integer(void);
void			convert_u_integer_octal(void);
void			convert_u_integer_hexa(void);
void			convert_u_integer_hexa(void);
void			convert_double_floating(void);
void			convert_double_floating(void);
void			convert_double_scientific(void);
void			convert_double_scientific(void);
void			convert_double_compact(void);
void			convert_double_compact(void);
void			convert_double_hexa(void);
void			convert_double_hexa(void);
void			convert_char(void);
void			convert_wide_char(void);
void			convert_string(void);
void			convert_wide_char_string(void);
void			convert_pointer(void);
void			convert_length(void);
void			convert_strerror(void);
void			convert_u_integer_binary(void);
void			convert_non_printable_string(void);
void			convert_iso_date(void);

static const t_converter	g_no_arg_conv[] =
{
	{'%', 0, convert_percent},
	{0, 0, (void *)0x0}
};

static const t_converter	g_converters[] =
{
	{'d', 0, convert_integer},
	{'i', 1, convert_integer},
	{'u', 2, convert_u_integer},
	{'o', 3, convert_u_integer_octal},
	{'x', 4, convert_u_integer_hexa},
	{'X', 5, convert_u_integer_hexa},
	{'f', 6, convert_double_floating},
	{'F', 7, convert_double_floating},
	{'e', 8, convert_double_scientific},
	{'E', 9, convert_double_scientific},
	{'g', 10, convert_double_compact},
	{'G', 11, convert_double_compact},
	{'a', 12, convert_double_hexa},
	{'A', 13, convert_double_hexa},
	{'c', 14, convert_char},
	{'C', 15, convert_wide_char},
	{'s', 16, convert_string},
	{'S', 17, convert_wide_char_string},
	{'p', 18, convert_pointer},
	{'n', 19, convert_length},
	{'m', 20, convert_strerror},
	{'b', 21, convert_u_integer_binary},
	{'r', 22, convert_non_printable_string},
	{'k', 23, convert_iso_date},
	{0, 0, (void *)0x0}
};

#endif
