/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/14 20:03:30 by abaurens         ###   ########.fr       */
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

#include <locale.h>

int				main(void)
{
	int			i;

	setlocale(LC_ALL, "");
	i = printf("   printf : LOL %lc\n", L'¢');
	printf("Returned %d\n\n", i);
	fflush(stdout);
	i = ft_printf("ft_printf : LOL %lc\n", L'¢');
	ft_printf("Returned %d\n", i);
	return (0);
}
