/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:58:06 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/01 17:10:30 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>

# ifndef BONUS

/*
**	ft_printf.c
*/
int				ft_printf(const char *frm,
							...) __attribute__((format(printf,1,2)));
int				ft_dprintf(int fd, const char *frm,
							...) __attribute__((format(printf,2,3)));
int				ft_sprintf(char *str, const char *frm,
							...) __attribute__((format(printf,2,3)));
int				ft_asprintf(char **ret, const char *frm,
							...) __attribute__((format(printf,2,3)));
int				ft_snprintf(char *str, size_t size, const char *frm,
							...) __attribute__((format(printf,3,4)));

# else

#  include <stdio.h>

int				ft_printf(const char *frm, ...);
int				ft_dprintf(int fd, const char *frm, ...);
int				ft_sprintf(char *str, const char *frm, ...);
int				ft_fprintf(FILE *stream, const char *frm, ...);
int				ft_asprintf(char **ret, const char *frm, ...);
int				ft_snprintf(char *str, size_t size, const char *frm, ...);

int				ft_vfprintf(FILE *stream, const char *frm, va_list ap);

# endif

int				ft_vprintf(const char *frm, va_list ap);
int				ft_vdprintf(int fd, const char *frm, va_list ap);
int				ft_vsprintf(char *str, const char *frm, va_list ap);
int				ft_vasprintf(char **ret, const char *frm, va_list ap);
int				ft_vsnprintf(char *dst, size_t ln, const char *frm, va_list ap);

#endif
