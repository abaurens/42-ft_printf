/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_mgr.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:22:04 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/18 19:42:39 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENT_MGR_H
# define ARGUMENT_MGR_H

# include "core/ft_types.h"

t_val	get_pointer(va_list ap, const char t, const int l);
t_val	get_double(va_list ap, const char t, const int l);
t_val	get_integer(va_list ap, const char t, const int l);

#endif
