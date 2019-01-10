/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:31:58 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/10 15:36:37 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LENGHT_H
# define LENGHT_H

# include "core/ft_types.h"

/*
**	short.c
*/
char			*short_length(t_printf *const data, t_arg *const arg);
char			*short_short_length(t_printf *const data, t_arg *const arg);

/*
**	long.c
*/
char			*long_length(t_printf *const data, t_arg *const arg);
char			*long_long_length(t_printf *const data, t_arg *const arg);

/*
**	exotic.h
*/
char			*intmax_length(t_printf *const data, t_arg *const arg);
char			*size_length(t_printf *const data, t_arg *const arg);
char			*ssize_length(t_printf *const data, t_arg *const arg);
char			*ptrdiff_length(t_printf *const data, t_arg *const arg);
char			*quad_length(t_printf *const data, t_arg *const arg);

#endif
