/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 04:02:07 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/02 18:56:54 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "core/ft_error_vals.h"
#include "core/ft_error.h"
#include "core/libft.h"

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

	err = get_errno();
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

int		get_errno(void)
{
	if (g_get_errno[0] != NULL)
		return (g_get_errno[0]());
	return (0);
}
