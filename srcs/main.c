/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/15 18:25:24 by abaurens         ###   ########.fr       */
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

int				main(void)
{
	int			i;
	int			j;

	setlocale(LC_ALL, "");
	errno = 0;
	i = 0;
	j = printf("   printf : LOL %010.5m\n");
	printf("Returned %d and i = %d\n\n", j, i);
	fflush(stdout);
	errno = 0;
	j = ft_printf("ft_printf : LOL %010.5m\n");
	ft_printf("Returned %d and i = %d\n", j, i);
	return (0);
}
