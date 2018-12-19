/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:22:26 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/19 21:21:37 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

char			*bignum_add_dot(const char *n1, const char *n2)
{
	size_t		i;
	size_t		l1;
	size_t		l2;
	size_t		len;
	char		*res;

	if (!n1 || !n2)
		return (NULL);
	l1 = ft_strlen(n1);
	l2 = ft_strlen(n2);
	len = ft_max(l1, l2);
	if (!(res = (char *)malloc(len + 2)))
		return (NULL);
	ft_memset(res++, 0, len + 2 + (i = 0));
	while (++i <= len)
	{
		res[len - i] += (len - i < l1) * (n1[len - i] - '0')\
		+ ((len - i < l2) * (n2[len - i] - '0'));
		if (res[len - i] > 9)
			res[len - i - 1] += res[len - i] / 10;
		res[len - i] = (res[len - i] % 10) + '0';
	}
	if ((*--res += '0') == '0')
		ft_memmove(res, res + 1, len + 1);
	return (res);
}

char			*bignum_mul_digit(const int v, const char *n)
{
	size_t		i;
	size_t		ln;
	char		*res;

	ln = ft_strlen(n);
	if (!(res = malloc(ln + 2)))
		return (NULL);
	ft_memset(res, 0, ln + 1);
	i = 0;
	while (++i <= ln)
	{
		if (n[ln - i] == '.')
			continue ;
		res[(ln + 1) - i] += (v * (n[ln - i] - '0'));
		if (res[(ln + 1) - i] > 9)
			res[(ln + 1) - i - 1] += res[(ln + 1) - i] / 10;
		res[(ln + 1) - i] = (res[(ln + 1) - i] % 10) + '0';
	}
	if ((*res += '0') == '0')
		ft_memmove(res, res + 1, ln + 1);
	return (res);
}

char			*add_post_mul(char **nums)
{
	int			i;
	char		*res;

	i = 1;
	if (!nums || !*nums || !(res = *nums))
		return (NULL);
	printf("%s\n", res);
	while (nums[i])
	{
		printf("%s\n", nums[i]);
		free(nums[i]);
		i++;
	}
	if (i > 1)
		exit(0);
	free(nums);
	return (res);
}

char			*bignum_mul(const char *n1, const char *n2)
{
	ssize_t		i;
	size_t		l1;
	size_t		l2;
	char		**n;

	i = -1;
	if (!n1 || !n2)
		return (NULL);
	l1 = ft_strlen(n1);
	l2 = ft_strlen(n2);
	if (!(n = malloc(sizeof(char *) * (l1 + 1))))
		return (NULL);
	n[l2] = NULL;
	printf("%s * %s\n", n1, n2);
	while (n1[++i])
	{
		if (n1[i] == '.')
			continue ;
		n[i] = bignum_mul_digit(n1[i] - '0', n2);
	}
	return (add_post_mul(n));
}

char			*bignum_two_power(int pow)
{
	char		*p;

	if (!(p = malloc(2)))
		return (NULL);
	ft_memcpy(p, "1", 2);
	while (pow)
	{
		/*printf("2 * %s = ", p);*/
		if (pow > 0)
		{
			p = (char *)ft_freturn(p, (long long)bignum_mul("2", p));
			--pow;
		}
		else
		{
			p = (char *)ft_freturn(p, (long long)bignum_mul("2", p));
			++pow;
		}
		if (!p)
			return (NULL);
		/*printf("%s\n", p);*/
	}
	return (p);
}
