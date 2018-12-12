/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:47:03 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/12 19:47:55 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "ft_types.h"

# define UNUSED(x) ((void)(x))

/*
**	debug.c
*/
void		print_arg_data(t_arg *arg, t_bool idx_given);

#endif
