/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/16 20:22:22 by abaurens         ###   ########.fr       */
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

#include <errno.h>
#include <locale.h>
#include <time.h>

int				main(void)
{
	int			i;
	int			j;

	setlocale(LC_ALL, "");
	i = 0;
	j = printf("   printf : LOL %p\n", 10);
	printf("Returned %d and i = %d\n\n", j, i);
	fflush(stdout);
	j = ft_printf("ft_printf : LOL %k\n", time(NULL));
	j = ft_printf("ft_printf : LOL %#k\n", time(NULL));
	j = ft_printf("ft_printf : LOL %#k\n", time(NULL) - 61 * 24 * 3600 - 3600);
	j = ft_printf("ft_printf : LOL %#k\n", time(NULL) + 60);
	j = ft_printf("ft_printf : LOL %#k\n", 15728400);
	j = ft_printf("ft_printf : LOL %#k\n", 1529258700);
	ft_printf("Returned %d and i = %d\n", j, i);
	return (0);
}
