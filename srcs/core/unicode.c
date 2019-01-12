/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:02:45 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/12 17:22:30 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ft_types.h"
#include "libft.h"

size_t					ft_wchar_len(const wchar_t chr)
{
	size_t				l;

	l = 1;
	if (chr >= 0x80)
		l++;
	if (chr >= 0x800)
		l++;
	if (chr >= 0x10000)
		l++;
	return (l);
}

size_t					ft_wstrlen(const wchar_t *wstr)
{
	register wchar_t	*s;
	register size_t		l;

	l = 0;
	s = (wchar_t *)wstr;
	while (*s)
	{
		l += ft_wchar_len(*s);
		s++;
	}
	return (l);
}

size_t					wchartochars(char *dst, wchar_t c)
{
	char				u[4];
	size_t				len;

	len = 1;
	ft_bzero(u, 4);
	u[3] = (c & 0b01111111);
	if (c >= 0x80 && len++)
	{
		u[3] = 0b10000000 | (c & 0b00111111);
		u[2] = 0b11000000 | ((c >> 6) & 0b00011111);
		if (c >= 0x800 && len++)
		{
			u[2] = 0b10000000 | ((c >> 6) & 0b00111111);
			u[1] = 0b11100000 | ((c >> 12) & 0b00001111);
			if (c >= 0x10000 && len++)
			{
				u[1] = 0b10000000 | ((c >> 12) & 0b00111111);
				u[0] = 0b11110000 | ((c >> 18) & 0b00000111);
			}
		}
	}
	ft_memcpy(dst, u + (4 - len), len);
	return (len);
}

char					*ft_wstrtostr(char *dst, const wchar_t *src)
{
	size_t				l;
	char				*d;

	d = (char *)dst;
	while (*src)
	{
		if ((l = ft_wchar_len(*src)) > ft_strlen(d))
		{
			ft_bzero(d, ft_strlen(d));
			break ;
		}
		wchartochars(d, *src);
		d += l;
		src++;
	}
	return (dst);
}
