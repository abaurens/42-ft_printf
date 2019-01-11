/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uoctal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:26:28 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/11 21:28:52 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UOCTAL_H
# define UOCTAL_H

# include "core/ft_types.h"

/*
**	long.c
*/
char			*long_uoctal(t_printf *const data, t_arg *const arg);
char			*long_long_uoctal(t_printf *const data, t_arg *const arg);

/*
**	short.c
*/
char			*short_uoctal(t_printf *const data, t_arg *const arg);
char			*short_short_uoctal(t_printf *const data, t_arg *const arg);

/*
**	exotic.c
*/
char			*intmax_uoctal(t_printf *const data, t_arg *const arg);
char			*size_uoctal(t_printf *const data, t_arg *const arg);
char			*ssize_uoctal(t_printf *const data, t_arg *const arg);
char			*ptrdiff_uoctal(t_printf *const data, t_arg *const arg);
char			*quad_uoctal(t_printf *const data, t_arg *const arg);

#endif
