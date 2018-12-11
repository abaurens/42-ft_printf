/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:58:06 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/11 16:31:11 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>
# include <stddef.h>
# include <inttypes.h>

# define ERROR -1

typedef enum e_bool		t_bool;
typedef struct s_arg	t_arg;
typedef struct s_printf	t_printf;

enum			e_bool
{
	FALSE,
	TRUE,
	MAYBE
};

# ifndef STRUCT_S_CONVERTER_DEFINED
#  define STRUCT_S_CONVERTER_DEFINED

typedef struct	s_converter
{
	char		c;
	int			id;
	void		(*func)(void);
}				t_converter;

# endif

struct			s_arg
{
	t_converter	conv;
	t_bool		w_arg;
	char		flags;
	char		conv_c;
	int			conv_id;
	int			flag_idx;
	int			min_width;
	int			precision;
	int			precision_idx;
	int			min_width_idx;
	int			length_modifier;
};

struct			s_printf
{
	t_bool		use_chain_format;
	char		*buf;
	va_list		lst;
};

/*
**	core.c
*/
int				get_arg(const char **format, t_printf *data);
int				get_non_arg(const char *format, t_printf *data);

/*
**	args.c
*/
int				parse_arg(const char **format, t_printf *data, t_arg *arg);

/*
**	ft_printf.c
*/
int				ft_printf(const char *format,
					...) __attribute__((format(printf,1,2)));

int				ft_bprintf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_fprintf(FILE *stream, const char *format, ...);
int				ft_snprintf(char *str, size_t size, const char *format, ...);

int				ft_asprintf(char **strp, const char *fmt, ...);

#endif
