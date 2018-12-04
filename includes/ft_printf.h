/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:58:06 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/04 18:31:02 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# define ERROR -1

# define FLAGS_V "-0+ #"

# define F_MINS	0b10000
# define F_ZERO	0b01000
# define F_PLUS	0b00100
# define F_SPAC 0b00010
# define F_HASH 0b00001

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct	s_arg
{
	char		flags;
}				t_arg;

/*
**	core.c
*/
int		get_format(const char *format, char **buffer);
int		get_args(const char *format, char **buffer, va_list *lst);

int		ft_printf(const char *format, ...);
int		ft_bprintf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_sprintf(char *str, const char *format, ...);
int		ft_fprintf(FILE *stream, const char *format, ...);
int		ft_snprintf(char *str, size_t size, const char *format, ...);

int		ft_asprintf(char **strp, const char *fmt, ...);

#endif
