/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:21:47 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/15 19:52:12 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include <unistd.h>
#include <float.h>
#include <math.h>

#include <stdio.h> ///
#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_unwarn.h"

int			main(void)
{
	double	d;

	ft_printf("%%i validated\n");
	ft_printf("%%d validated\n");
	ft_printf("%%D validated\n");
	ft_printf("%%o validated\n");
	ft_printf("%%O validated\n");
	ft_printf("%%u validated\n");
	ft_printf("%%U validated\n");
	ft_printf("%%x validated\n");
	ft_printf("%%X validated\n");
	ft_printf("%%c validated\n");
	ft_printf("%%C validated\n");
	ft_printf("%%s validated\n");
	ft_printf("%%S validated\n");
	ft_printf("%%p validated\n");
	ft_printf("%%f validated\n");
	ft_printf("%%F validated\n");

	ft_printf("\n");

	/*
	d = 1.385239e-309;
	ft_printf("F:>------------<%10.42la>------------<\n", d);
	printf("R:>------------<%10.42la>------------<\n\n", d);
	fflush(stdout);

	ft_printf("F:>------------<%10.42La>------------<\n", (long double)d);
	printf("R:>------------<%10.42La>------------<\n\n", (long double)d);
	fflush(stdout);

	d = 2.500000e+00;
	ft_printf("F:!%17.45la!\n", d);
	printf("R:!%17.45la!\n\n", d);
	fflush(stdout);

	d = 2.500000e+00;
	ft_printf("F:!%17.45la!\n", (long double)d);
	printf("R:!%17.45la!\n\n", (long double)d);
	fflush(stdout);

	d = 5.419477e-315;
	ft_printf("F:%-52.2a\n", d);
	printf("R:%-52.2a\n", d);
	fflush(stdout);

	ft_printf("F:%-52a\n", d);
	printf("R:%-52a\n\n", d);
	fflush(stdout);

	ft_printf("F:%-52.6La\n", (long double)d);
	printf("R:%-52.6La\n", (long double)d);
	fflush(stdout);
	*/

	d = 0x1.4b0cada8p-1042;
	ft_printf("F:%-52La\n", (long double)d);
	printf("R:%-52La\n\n", (long double)d);
	fflush(stdout);

	d = 0x1.4b0cada8p-1042;
	printf("R:%-52a\n", d);

	return (0);
}
