/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:29:02 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/02 17:05:54 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# include <time.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stddef.h>
# include <inttypes.h>
# include <sys/types.h>

# define ERROR -1

# define F_MINS	0b00000001
# define F_ZERO	0b00000010
# define F_PLUS	0b00000100
# define F_SPAC 0b00001000
# define F_HASH 0b00010000
# define F_COLO 0b00100000
# define FLAGS_V "-0+ #'"
# define FLAG_C 6

/*
**	I = print the value with the locale digits if any (only used for i, u and d)
*/

typedef struct s_printf	t_printf;
typedef struct s_arg	t_arg;
typedef struct tm		t_tm;

typedef enum			e_bool
{
	FALSE,
	TRUE,
	MAYBE
}						t_bool;

typedef struct			s_float
{
	unsigned char		sign;
	int					exponent;
	unsigned long int	mantissa;
}						t_float;

typedef union			u_float_conv
{
	long double			value;
	unsigned char		bytes[sizeof(long double)];
}						t_float_conv;

typedef struct			s_converter
{
	char				c;
	t_bool				w_arg;
	char				*(*func)(t_printf *data, t_arg *arg);
}						t_converter;

typedef union			u_val
{
	void				*p;
	double				f;
	long double			lf;
	long long int		i;
}						t_val;

struct					s_arg
{
	t_converter			conv;
	t_val				val;
	size_t				flag_idx;
	size_t				prec_idx;
	size_t				min_idx;
	char				flags;
	int					min;
	int					prec;
	int					length_modifier;
};

typedef struct			s_lst_elem
{
	t_val				val;
	struct s_lst_elem	*next;
	struct s_lst_elem	*prev;
}						t_lst_elem;

typedef struct			s_ftlist
{
	t_lst_elem			*head;
	t_lst_elem			*tail;
	size_t				size;
}						t_ftlist;

struct					s_printf
{
	t_bool				use_chain_format;
	size_t				arg_count;
	size_t				len;
	t_ftlist			args;
	char				*buf;
	int					err;
	va_list				va_lst;
};

#endif
