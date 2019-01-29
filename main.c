/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:21:47 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/29 21:23:06 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include <unistd.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include "libft.h"
#include "core/ft_types.h"
#include "core/ft_core.h"
#include "core/dragon.h"
#include "ft_printf.h"
#include "ft_printf_unwarn.h"

int			main(void)
{
	/*
	**	validated
	*/
	setlocale(LC_ALL, "");
	ft_printf("%%i : %lc\t%%o : %C\t%%u : %C\t%%x : %C\t%%c : %C\t%%s : %C\t%%p : %C\n",
		L'✔', /* i */
		L'✔', /* o */
		L'✔', /* u */
		L'✔', /* x */
		L'✔', /* c */
		L'✔', /* s */
		L'✔' /* p */
	);
	ft_printf("%%d : %C\t%%O : %C\t%%U : %C\t%%X : %C\t%%C : %C\t%%S : %C\n",
		L'✔', /* d */
		L'✔', /* O */
		L'✔', /* U */
		L'✔', /* X */
		L'✔', /* C */
		L'✔' /* S */
	);
	ft_printf("%%D : %C\n", L'✔'); /* D */
	ft_printf("\n");

	/*
	**	to be tested
	**	test %a with 0 (possible inf loop)
	*/
	ft_printf("%%f : %C\t%%g : %C\t%%e : %C\t%%a : %C\n", L'✔', L'✔', L'🕓', L'💥');
	ft_printf("%%F : %C\t%%G : %C\t%%E : %C\t%%A : %C\n", L'✔', L'✔', L'🕓', L'💥');
	ft_printf("\n");

	/*
	**	not tested yet
	*/
	ft_printf("%%m : %C\t%%b : %C\t%%r : %C\t%%k : %C\n", L'🚫', L'🚫', L'🚫', L'🚫');
	ft_printf("\n");

	/*
	**	%g has to switch to %e when the exponent is greater or equals to the DISPLAYED exponent.
	**		this means the value of the exponent after rounding !
	**	%a may infinite loop with 0.0
	*/

	ft_printf("F: |%26.2g|\n", 1.385239e-309);
	printf("R: |%26.2g|\n\n", 1.385239e-309);

	ft_printf("F: |%-26g|\n", 1.385239e-309);
	printf("R: |%-26g|\n\n", 1.385239e-309);
	fflush(stdout);

	ft_printf("F: |% .3lg|\n", 99.562182840363405489370052237063646316528320312);
	printf("R: |% .3lg|\n\n", 99.562182840363405489370052237063646316528320312);
	fflush(stdout);

	return (0);
}
