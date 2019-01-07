/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:58:06 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/07 21:17:18 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include "ft_types.h"
# include "ft_bigfloat.h"

# define LEN_MD			"qjzZtlLh"
# define LEN_MD_CHRS	" qjzZtlLhH"

/*
**	core.c
*/
int				get_non_arg(const char *format, t_printf *data);
int				parse_conversion(const char **format, t_printf *data);

/*
**	buffer.c
*/
char			*insert_buffer(t_printf *const data, const char *str,
								size_t len);

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
t_lst_elem		*get_arg_f(t_printf *data, const size_t idx);
int				get_arg(t_printf *data, size_t idx, long long int *val);

/*
**	printf_lltoa.c
*/
char			*printf_lltoa(long long int nb, const int min);
char			*padded_lltoa(long long nb, const int min_d, const int pad,
								char r);
char			*padded_ulltoa(unsigned long long nb, const int min_d,
								const int pad, char r);
char			*padded_ulltoa_bin(unsigned long long nb, const int min_d,
								const int pad, char r);
char			*padded_ulltoa_octal(unsigned long long nb, const int min_d,
									const int pad, char r);
char			*padded_ulltoa_hexa(unsigned long long nb, const int min_d,
									const int pad, char r);

/*
**	unicode.c
*/
size_t			ft_wstrlen(const wchar_t *wstr);
size_t			wchartochars(char *dst, wchar_t c);
char			*ft_wstrtostr(char *dst, const wchar_t *src);

/*
**	ft_ldtoa.c
*/
char			*ft_ldtoa(long double d);
char			*exp_dbl(long double d, size_t prec);
char			*exp_dbl_hex(long double d, size_t prec);

/*
**	floating_point.c
*/
t_bflt			*get_mantissa(t_float *f);
long double		dbl_abs(long double *d, char *sign);
t_float			get_float_components(long double d);

/*
**	float_round.c
*/
char			*round_tabflt(char *val, size_t prec, int *exp);

/*
**	big_num.c
*/
char			*to_hex(t_bflt *deci);
t_bflt			*new_ftobflt(long double d);

/*
**	double_floating.c
*/
char			*printf_ldbl(t_printf *const data, t_arg *const arg);

#endif
