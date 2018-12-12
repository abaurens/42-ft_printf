/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/12 23:47:42 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "ft_error.h"
#include "libft.h"

int				main(void)
{
	printf("   printf : LOL %*.*d\n", 5, 10, 42);
	fflush(stdout);
	/*
	printf("returned : %d\n\n", i);
	fflush(stdout);*/
	ft_printf("ft_printf : LOL %*.*d\n", 5, 10, 42);
	/*printf("returned : %d\n", i);
	fflush(stdout);*/
	return (0);
}
