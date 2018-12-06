/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/06 16:45:29 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int			i;
	const char	*test = "%1$*.5d\n";//"\t|%#'+- 01$#'+- 0*2$#'+- 0.*2$#'+- 0l#'+- 0l#'+- 0%\n";

	printf("Testing printf with format %s\n", test);
	fflush(stdout);
	i = printf(test, 5, 42, 10);
	fflush(stdout);
	printf("returned : %d\n\n", i);
	fflush(stdout);
	i = ft_printf(test, 5, 42);
	printf("returned : %d\n", i);
	fflush(stdout);
	return (0);
}
