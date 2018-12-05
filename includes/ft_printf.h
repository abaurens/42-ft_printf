/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:58:06 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/05 20:21:22 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>

# define ERROR -1

# define FLAGS_V "-0+ #'"

# define FLAG_C 6
# define F_MINS	0b00000001
# define F_ZERO	0b00000010
# define F_PLUS	0b00000100
# define F_SPAC 0b00001000
# define F_HASH 0b00010000
# define F_COLO 0b00100000

# define CONV_V "dioxXucsfeEgGpn%"

typedef const char	t_char;

typedef enum	e_bool
{
	FALSE,
	TRUE,
	MAYBE
}				t_bool;

typedef struct	s_arg
{
	char		flags;
	int			conv_id;
	int			min_width;
	int			precision;
	int			flag_idx;
	int			precision_idx;
	int			min_width_idx;
}				t_arg;

typedef struct	s_printf
{
	t_bool		use_chain_format;
	char		*buf;
	va_list		lst;
}				t_printf;

/*
**	core.c
*/
int				get_args(const char *format, t_printf *data);
int				get_format(const char *format, t_printf *data);

int				ft_printf(const char *format, ...);
int				ft_bprintf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_fprintf(FILE *stream, const char *format, ...);
int				ft_snprintf(char *str, size_t size, const char *format, ...);

int				ft_asprintf(char **strp, const char *fmt, ...);

#endif
