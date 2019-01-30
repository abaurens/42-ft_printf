/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:21:47 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/30 23:59:32 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include <unistd.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include "core/libft.h"
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
	ft_printf("%%f : %C\t%%g : %C\t%%e : %C\t%%a : %C\n", L'✔', L'✔', L'✔', L'🕓');
	ft_printf("%%F : %C\t%%G : %C\t%%E : %C\t%%A : %C\n", L'✔', L'✔', L'✔', L'🕓');
	ft_printf("\n");

	/*
	**	not tested yet
	*/
	ft_printf("%%m : %C\t%%b : %C\t%%r : %C\t%%k : %C\n", L'🚫', L'🚫', L'🚫', L'🚫');
	ft_printf("\n");

	/*
	**	BUG LIST
	**
	**	%a may infinite loop with 0.0 (corrected trough a special case)
	*/

	/*
	**	TOTO LIST
	**
	**	I should probably implement grisu3 to speed up even more the float conversions.
	**		80 times slower than system's printf is still a way too slow
	**		compared to the other conversion.
	**
	**	I should change the way to generate scientific notation to remove the
	**		need of bigfloats. this way increase the speed of %e, %g and %a conversions
	**		and allow me to remove the bignum library.
	*/

	printf("R: |%La|\n", LDBL_MAX);
	ft_printf("F: |%La|\n", LDBL_MAX);

	return (0);
}
