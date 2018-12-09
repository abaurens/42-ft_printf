/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/09 02:23:06 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int				main(void)
{
	int			i;
	const char	*test = " |%1$#'+- 0*2$.*2$lld\n";

	/**/
	i = 0;
	ft_printf("A%-2.5mB\n");
	exit(i);
	/**
	printf("Testing printf with format %s\n", test);
	fflush(stdout);
	i = printf("%hld", 5l);
	fflush(stdout);
	printf("returned : %d\n\n", i);
	fflush(stdout);
	i = ft_printf("%hld", 5l);
	printf("returned : %d\n", i);
	fflush(stdout);
	*/
	return (0);
}
