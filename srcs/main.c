/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/17 16:00:05 by abaurens         ###   ########.fr       */
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
	j = printf("   printf : LOL %s\n", "Test\rtest");
	printf("Returned %d and i = %d\n\n", j, i);
	fflush(stdout);
	j = ft_printf("ft_printf : LOL %#r\n", "Test\rtest\n");
	ft_printf("Returned %d and i = %d\n", j, i);
	return (0);
}
