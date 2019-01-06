/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/06 23:07:05 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include <fcntl.h>
#include <float.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "ft_printf.h"
#include "ft_error.h"
#include "libft.h"

int				main(void)
{
	int			l;
	long double	d;

	l = 0;
	d = 684351465.54513600000;
	setlocale(LC_ALL, "");
	printf("R : %.3Le\n", d);
	printf("R : %.3La\n\n", d);
	fflush(stdout);
	ft_printf("R : %.3Le\n", d);
	ft_printf("F : %.3La\n", d);
	return (0);
}
