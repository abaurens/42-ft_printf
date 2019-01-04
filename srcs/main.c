/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/04 18:53:22 by abaurens         ###   ########.fr       */
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

	d = (1.0 / 0.0);
	d = 42.84;
	printf("R : %.2Lg\n", d);
	ft_printf("F : %.2Lg\n", d);
	fflush(stdout);
	return (0);
}
