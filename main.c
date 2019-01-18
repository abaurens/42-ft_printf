/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:21:47 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/18 16:04:40 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include <unistd.h>
#include <float.h>
#include <math.h>

#include <stdio.h> ///
#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_unwarn.h"

int			main(void)
{
	double	d;
	char	t[5];

	*t = 'A';
	t[1] = 0;
	t[2] = 0;
	t[3] = 0;
	t[4] = 0;
	/*
	**	validated
	*/
	setlocale(LC_ALL, "");
	ft_printf("%%i : %C\t%%o : %C\t%%u : %C\t%%x : %C\t%%c : %C\t%%s : %C\t%%p : %C\n", L'✅', L'✅', L'✅', L'✅', L'✅', L'✅', L'✅');
	ft_printf("%%d : %C\t%%O : %C\t%%U : %C\t%%X : %C\t%%C : %C\t%%S : %C\n", L'✅', L'✅', L'✅', L'✅', L'✅', L'✅', L'✅');
	ft_printf("%%D : %C\n", L'✅');
	ft_printf("\n");

	/*
	**	to be tested
	**	test %a with 0 (possible inf loop)
	*/
	ft_printf("%%f : %C\t%%g : %C\t%%e : %C\t%%a : %C\n", L'🕓', L'🕓', L'🕓', L'💥');
	ft_printf("%%F : %C\t%%G : %C\t%%E : %C\t%%A : %C\n", L'🕓', L'🕓', L'🕓', L'💥');
	ft_printf("\n");

	/*
	**	not tested yet
	*/
	ft_printf("%%m : %C\t%%b : %C\t%%r : %C\t%%k : %C\n", L'🚫', L'🚫', L'🚫', L'🚫');
	ft_printf("\n");

	return (0);
}
