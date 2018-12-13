/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:29:02 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/13 20:27:11 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# include <wchar.h>
# include <string.h>
# include <stdarg.h>
# include <stddef.h>
# include <inttypes.h>

# define ERROR -1

# define F_MINS	0b00000001
# define F_ZERO	0b00000010
# define F_PLUS	0b00000100
# define F_SPAC 0b00001000
# define F_HASH 0b00010000
# define F_COLO 0b00100000
# define F_CAPI 0b01000000
# define FLAGS_V "-0+ #'I"
# define FLAG_C 7

/*
**	I = print the value with the locale digits if any (only used for i, u and d)
*/

typedef struct s_arg	t_arg;
typedef struct s_printf	t_printf;

typedef enum			e_bool
{
	FALSE,
	TRUE,
	MAYBE
}						t_bool;

typedef struct			s_converter
{
	char				c;
	t_bool				w_arg;
	char				*(*func)(t_printf *data, t_arg *arg);
}						t_converter;

struct					s_arg
{
	t_converter			conv;
	long long			value;
	size_t				precision_idx;
	size_t				flag_idx;
	size_t				min_width_idx;
	char				flags;
	int					min_width;
	int					precision;
	int					length_modifier;
};

typedef struct			s_lst_elem
{
	long long int		value;
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
	t_ftlist			args;
	char				*buf;
	va_list				va_lst;
};

#endif
