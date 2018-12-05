/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/05 09:50:00 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int	i;
	const char	*test = "LOL%2$#' -+01.*d\n";
	printf("Testing printf with format %s\n", test);

	i = printf(test, 5, 42);
	printf("returned : %d\n\n", i);

	i = ft_printf(test, 5, 42);
	printf("returned : %d\n", i);
	return (0);
}
