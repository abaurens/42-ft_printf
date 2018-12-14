/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:54:23 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/14 16:58:54 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_types.h"
#include "libft.h"

char		*convert_percent(t_printf *data, t_arg *arg)
{
	char	*buf;

	(void)arg;
	buf = ft_strmcat(data->buf, "%", -1);
	free(data->buf);
	data->buf = buf;
	return (NULL);
}
