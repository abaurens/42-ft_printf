/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:21:47 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/17 20:33:01 by abaurens         ###   ########.fr       */
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
	ft_printf("%%g validated\n");
	ft_printf("%%G validated\n");


	ft_printf("%%e validated\n");
	ft_printf("%%E validated\n");

	/*to test with 0 (possible inf loop)*/
	ft_printf("%%a validated\n");
	ft_printf("%%A validated\n");

	ft_printf("\n");

	d = 0.0;
	ft_printf("F:%-o\n", -592920303);
	printf("F:%-o\n", -592920303);
	fflush(stdout);

	ft_printf("%%m to be validated\n");
	ft_printf("%%b to be validated\n");
	ft_printf("%%r to be validated\n");
	ft_printf("%%k to be validated\n");

	return (0);
}
