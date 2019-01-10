/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:12:42 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/06 20:08:11 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_types.h"
#include "libft.h"

char		*insert_buffer(t_printf *const data, const char *str, size_t len)
{
	char	*res;

	/*printf("len = %lu\n", len);*/
	if (!len)
		return (data->buf);
	/*printf("allocating %lu bytes\n", data->len + len);*/
	if (!data || !str || !(res = ft_memalloc(data->len + len + 1)))
		return (NULL);
	/*printf("before concat : |%s|\n", data->buf);*/
	ft_memcpy(res, data->buf, data->len);
	ft_memcpy(res + data->len, str, len);
	/*printf("after concat  : |%s|\n", res);*/
	data->len += len;
	free(data->buf);
	data->buf = res;
	return (res);
}
