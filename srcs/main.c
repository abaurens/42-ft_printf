/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:25:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/08 18:04:38 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include <fcntl.h>
#include <float.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "ft_printf.h"
#include "ft_error.h"
#include "libft.h"

int				main(void)
{
	setlocale(LC_ALL, "");
	printf("%5$s%2$c%4$s%2$c%3$s%6$s%1$c", '\n', ' ', "alone", "am", "i", "!", "?");
	ft_printf("%5$s%2$c%4$s%2$c%3$s%6$s%1$c", '\n', ' ', "alone", "am", "i", "!", "?");
	fflush(stdout);
	return (0);
}
