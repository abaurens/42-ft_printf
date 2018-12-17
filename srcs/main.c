/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/17 21:39:48 by abaurens         ###   ########.fr       */
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
	/*
	int			i;
	int			j;

	setlocale(LC_ALL, "");
	i = 0;
	j = printf("   printf : LOL %s\n", "Test\rtest");
	printf("Returned %d and i = %d\n\n", j, i);
	fflush(stdout);
	j = ft_printf("ft_printf : LOL %#r\n", "Test\rtest\n");
	ft_printf("Returned %d and i = %d\n", j, i);
	printf("sizeof(double) = %lu, sizeof(long double) = %lu\n",
			sizeof(long long int), sizeof(long double));*/
	fflush(stdout);
	get_float_components(-1.0);
	return (0);
}
