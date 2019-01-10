/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:23:42 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/10 15:34:04 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_H
# define INTEGER_H

# include "core/ft_types.h"

/*
**	short.c
*/
char	*short_integer(t_printf *const data, t_arg *const arg);
char	*short_short_integer(t_printf *const data, t_arg *const arg);

/*
**	long.c
*/
char	*long_integer(t_printf *const data, t_arg *const arg);
char	*long_long_integer(t_printf *const data, t_arg *const arg);

/*
**	exotic.c
*/
char	*intmax_integer(t_printf *const data, t_arg *const arg);
char	*size_integer(t_printf *const data, t_arg *const arg);
char	*ssize_integer(t_printf *const data, t_arg *const arg);
char	*ptrdiff_integer(t_printf *const data, t_arg *const arg);
char	*quad_integer(t_printf *const data, t_arg *const arg);

#endif
