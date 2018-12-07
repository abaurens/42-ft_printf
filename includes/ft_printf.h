/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:58:06 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/08 00:54:22 by abaurens         ###   ########.fr       */
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

# define F_MINS	0b00000001
# define F_ZERO	0b00000010
# define F_PLUS	0b00000100
# define F_SPAC 0b00001000
# define F_HASH 0b00010000
# define F_COLO 0b00100000
# define FLAGS_V "-0+ #'I"
# define FLAG_C 6

extern int const g_flags_masks[];

# define LEN_MD "hlLqjzZtq"
# define CONV_V "diouxXeEfFgGaAcCsSpnmbrk%"
/*
**	b = nombre binaire
**	r = string avec caracteres non imprimable
**	k = date au format ISO
*/

typedef enum e_bool		t_bool;
typedef struct s_arg	t_arg;
typedef struct s_printf	t_printf;

enum		e_bool
{
	FALSE,
	TRUE,
	MAYBE
};

struct		s_arg
{
	char	flags;
	char	conv_c;
	int		conv_id;
	int		flag_idx;
	int		min_width;
	int		precision;
	int		precision_idx;
	int		min_width_idx;
};

struct		s_printf
{
	t_bool	use_chain_format;
	char	*buf;
	va_list	lst;
};

/*
**	core.c
*/
int			get_arg(const char **format, t_printf *data);
int			get_non_arg(const char *format, t_printf *data);

/*
**	args.c
*/
int			parse_arg(const char **format, t_printf *data, t_arg *arg);

/*
**	ft_printf.c
*/
int			ft_printf(const char *format,
	...) __attribute__((format(printf,1,2)));

int			ft_bprintf(const char *format, ...);
int			ft_dprintf(int fd, const char *format, ...);
int			ft_sprintf(char *str, const char *format, ...);
int			ft_fprintf(FILE *stream, const char *format, ...);
int			ft_snprintf(char *str, size_t size, const char *format, ...);

int			ft_asprintf(char **strp, const char *fmt, ...);

#endif
