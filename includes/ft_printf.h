/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:58:06 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/11 20:06:50 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include "ft_types.h"

/*
**	core.c
*/
int				get_non_arg(const char *format, t_printf *data);
int				parse_conversion(const char **format, t_printf *data);

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

/*
**	argument_manager.c
*/
void			clear_list(t_ftlist *lst);
void			get_arg(t_printf *data, size_t idx);

#endif
