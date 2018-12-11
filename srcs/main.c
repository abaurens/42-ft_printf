/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/11 19:21:47 by abaurens         ###   ########.fr       */
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
	int			i;

	i = printf("%*.*lld\n", 10, 5, 5ll);
	fflush(stdout);
	printf("returned : %d\n\n", i);
	fflush(stdout);
	i = ft_printf("%*.*lld%2d\n", 10, 5, 5ll, 42);
	printf("returned : %d\n", i);
	fflush(stdout);
	return (0);
}
