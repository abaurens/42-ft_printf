/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/09 05:23:02 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_error.h"
#include "ft_printf.h"

int				main(void)
{
	int			i;
	const char	*test = " |%1$#'+- 0*2$.*2$lld\n";

	/**/
	i = 0;
	/*open("lol", O_RDONLY);*/
	printf("error : %m\n");
	/*open("lol", O_RDONLY);*/
	ft_perror("error ");
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
