/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/08 19:51:57 by abaurens         ###   ########.fr       */
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
	setlocale(LC_ALL, "");
	printf("r : %La\n", (long double)10.5);
	fflush(stdout);
	ft_printf("f : %La\n", (long double)10.5);
	return (0);
}
