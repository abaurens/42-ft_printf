/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/07 18:01:39 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int				main(void)
{
	int			l;
	intmax_t	i;
	ptrdiff_t	g;
	wchar_t		c;
	wint_t		wi;
	long double lf;
	const char	*test = " |%#'+- 01$#'+- 0*2$#'+- 0.*2$#'+- 0l#'+- 0l#'+- 0d\n";

	/**/
	l = 5;
	i = l;
	g = l;
	lf = 0.0;
	ft_printf("%lf\n", lf);
	exit(0);
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
