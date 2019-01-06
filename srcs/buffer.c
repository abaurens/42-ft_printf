/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:12:42 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/06 18:13:10 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "libft.h"

char		*insert_buffer(t_printf *const data, char *str)
{
	if (!str)
		return (NULL);
	if (!(str = (char *)ft_freturn(str, (long)ft_strmcat(data->buf, str, -1))))
		return (NULL);
	return (data->buf = (char *)ft_freturn(data->buf, (long)str));
}
