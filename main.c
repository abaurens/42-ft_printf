/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:21:47 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/29 20:48:40 by abaurens         ###   ########.fr       */
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
	printf("R: % 48e\n", 0.0 / 0.0);
	ft_printf("F: % 48e\n\n", 0.0 / 0.0);

	printf("R: %048e\n", 0.0 / 0.0);
	ft_printf("F: %048e\n\n", 0.0 / 0.0);

	printf("R: %-48e\n", 0.0 / 0.0);
	ft_printf("F: %-48e\n\n", 0.0 / 0.0);

	printf("R: % 48.1e\n", 42.0);
	ft_printf("F: % 48.1e\n\n", 42.0);

	ft_printf("F: % 48.1e\n", 2.5);
	printf("R: % 48.1e\n\n", 2.5);
	fflush(stdout);

	ft_printf("F: % 48.1e\n", 2.0);
	printf("R: % 48.1e\n\n", 2.0);
	fflush(stdout);

	ft_printf("F: % 48.1e\n", 0.5);
	printf("R: % 48.1e\n\n", 0.5);
	fflush(stdout);

	ft_printf("F: % 48.1e\n", 0.05);
	printf("R: % 48.1e\n\n", 0.05);
	fflush(stdout);

	ft_printf("F: % 48.1e\n", 0.52);
	printf("R: % 48.1e\n\n", 0.52);
	fflush(stdout);


	printf("R: % 48.1e\n", 0.0);
	ft_printf("F: % 48.1e\n\n", 0.0);

	printf("R: |%.4e|\n", 2.176286e+02);
	ft_printf("F: |%.4e|\n\n", 2.176286e+02);

	printf("R: |%.4e|\n", DBL_MAX);
	ft_printf("F: |%.4e|\n\n", DBL_MAX);

	ft_printf("F: |%022e|\n", -0x1.fe0001fep-1027);
	printf("R: |%022e|\n\n", -0x1.fe0001fep-1027);
	fflush(stdout);

	ft_printf("F: |%052.2e|\n", 1.385239e-309);
	printf("R: |%052.2e|\n\n", 1.385239e-309);
	fflush(stdout);

	ft_printf("F: |%020e|\n", 1.385239e-309);
	printf("R: |%020e|\n\n", 1.385239e-309);
	fflush(stdout);
*/
	return (0);
}
