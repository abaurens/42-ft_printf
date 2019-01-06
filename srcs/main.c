/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/06 18:22:04 by abaurens         ###   ########.fr       */
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
	long double	d;

	d = 684351465.54513600000;
	printf("R : %-2.5Lg\n", d);
	fflush(stdout);
	ft_printf("F : %-2.5Lg\n", d);
	return (0);
}
