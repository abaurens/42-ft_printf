/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:21:47 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/16 20:28:03 by abaurens         ###   ########.fr       */
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

	/*d = 0x1.fe0001fep-1027;
	ft_printf("F:% 027.17la\n", d);
	printf("R:% 027.17la\n", d);
	fflush(stdout);*/

	d = 0x1.fe0001fep-1027;
	ft_printf("F:% 015.2la\n", d);
	printf("R:% 015.2la\n", d);
	fflush(stdout);

	d = 0x1.fe0001fep-1027;
	ft_printf("F:% 15.2la\n", d);
	printf("R:% 15.2la\n", d);
	fflush(stdout);

	d = 0x1.fe0001fep-1027;
	ft_printf("F:%+032a\n", d);
	printf("R:%+032a\n", d);
	fflush(stdout);

	d = 0x1.fe0001fep-1027;
	ft_printf("F:%060la\n", d);
	printf("R:%060la\n", d);
	fflush(stdout);
	return (0);
}
