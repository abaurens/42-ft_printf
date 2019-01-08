/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/08 01:01:26 by abaurens         ###   ########.fr       */
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
	d = 0.9;
	d = 3.99999;
	setlocale(LC_ALL, "");
	/*while (d <= 1.001)
	{
		printf("num : %Lf\n", d);
		ft_printf("%La\n", d);
		printf("R : %La\n=======================\n", d);
		fflush(stdout);
		d += 0.001;
	}*/
	printf("num : %Lf\n", d);
	ft_printf("%.3La\n", d);
	printf("R : %.3La\n=======================\n", d);
	fflush(stdout);
	return (0);
}
