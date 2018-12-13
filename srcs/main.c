/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/13 22:18:04 by abaurens         ###   ########.fr       */
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

int				main(void)
{
	int			i;

	i = printf("   printf : LOL % +-20.15ld\n", (long)UINT_MAX);
	printf("Returned %d\n\n", i);
	fflush(stdout);
	i = ft_printf("ft_printf : LOL % +-20.15ld\n", (long)UINT_MAX);
	ft_printf("Returned %d\n", i);
	return (0);
}
