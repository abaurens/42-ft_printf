/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/03 20:24:03 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"
#include "ft_error.h"
#include "libft.h"

#include <float.h>
#include <math.h>

#include <errno.h>
#include <locale.h>
#include <time.h>

int				main(void)
{
	long double	d;

	d = -99.99;
	printf("%d\n", -0.0 == 0.0);
	ft_printf("F : %#0.1Le\n", d);
	printf("R : %#0.1Le\n", d);
	fflush(stdout);
	return (0);
}
