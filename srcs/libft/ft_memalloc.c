/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:46:10 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/30 23:50:41 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/libft.h"

void		*ft_memalloc(size_t size)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(size);
	while (ret && i < size)
		ret[i++] = 0;
	return (ret);
}
