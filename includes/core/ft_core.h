/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:53:12 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/29 19:01:54 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CORE_H
# define FT_CORE_H

# include "ft_types.h"
# include "ft_bigfloat.h"

# define LEN_MD			"qjzZtlLh"
# define LEN_MD_CHRS	" qjzZtlLhH"

# define DECI	"0123456789"
# define HEXA	"0123456789abcdef"

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
**	flags.c
*/
char			flag(t_arg *arg, char mask);

/*
**	args.c
*/
int				parse_arg(const char **format, t_printf *data, t_arg *arg);

/*
**	list_manager.c
*/
void			clear_list(t_ftlist *lst);

/*
**	argument_manager.c
*/
int				get_arg_a(t_printf *data, const size_t idx, t_arg *a);
int				get_arg_i(t_printf *data, const size_t idx, int *v);

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
size_t			ft_wchar_len(const wchar_t chr);
size_t			wchartochars(char *dst, wchar_t c);
char			*ft_wstrtostr(char *dst, const wchar_t *src);

/*
**	ft_ldtoa.c
*/
char			*ft_ldtoa(long double d);
char			*ft_ldtoa2(long double d);
char			*exp_dbl(long double d, size_t prec);
char			*exp_dbl_hex(long double d, int prec, t_bool lng);

/*
**	floating_point.c
*/
t_bflt			*get_mantissa(t_float *f);
long double		dbl_abs(long double *d, char *sign);
t_float			get_float_components(long double d);

/*
**	bankers_round.c
*/
char			*banker_round(char *val, const size_t prec, const char *base);

/*
**	float_round.c
*/
char			ldbl_num(long double d);
char			*round_hex(char *val, size_t prec, int *exp);
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
