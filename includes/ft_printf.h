/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:58:06 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/11 21:48:23 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <wchar.h>
# include <stdarg.h>

/*
**	ft_printf.c
*/
int				ft_printf(const char *format,
					...) __attribute__((format(printf,1,2)));

int				ft_fprintf(FILE *stream, const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_snprintf(char *str, size_t size, const char *format, ...);
int				ft_asprintf(char **ret, const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

int				ft_vprintf(const char *format, va_list ap);
int				ft_vfprintf(FILE *stream, const char *format, va_list ap);
int				ft_vsprintf(char *str, const char *format, va_list ap);
int				ft_vsnprintf(char *str, size_t size, const char *format,
								va_list ap);
int				ft_vasprintf(char **ret, const char *format, va_list ap);
int				ft_vdprintf(int fd, const char *format, va_list ap);

#endif
