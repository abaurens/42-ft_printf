/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:58:06 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/04 00:46:25 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# define ERROR -1

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

int		ft_printf(const char *format, ...);
int		ft_bprintf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_sprintf(char *str, const char *format, ...);
int		ft_fprintf(FILE *stream, const char *format, ...);
int		ft_snprintf(char *str, size_t size, const char *format, ...);

int		ft_asprintf(char **strp, const char *fmt, ...);

#endif
