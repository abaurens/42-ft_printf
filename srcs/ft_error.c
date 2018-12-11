/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 04:02:07 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/11 15:48:45 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include "ft_error.h"
#include "libft.h"

char		*ft_strerror(const int errnum)
{
	int		i;

	i = 0;
	while (g_error_table[i].value >= 0 && g_error_table[i].value != errnum)
		i++;
	return ((char *)g_error_table[i].msg);
}

void		ft_perror(const char *str)
{
	int		i;
	int		err;

	err = errno;
	if (str)
		ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	i = 0;
	while (g_error_table[i].value >= 0 && g_error_table[i].value != err)
		i++;
	ft_putstr_fd(g_error_table[i].msg, 2);
	if (g_error_table[i].value < 0)
		ft_putnbr_fd(err, 2);
	write(2, "\n", 1);
}
