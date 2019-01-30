/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 23:22:52 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/31 00:18:14 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define FT_LLMAX 9223372036854775807ull

char			fnan(long double d);
char			ft_isbase(const char *base);
char			ft_contains(char c, const char *str);

int				ft_isupper(int c);
int				ft_isprint(int c);
int				ft_atoi(const char *str);
int				ft_putchar_fd(int c, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

long			ft_atol_base(const char *str, const char *base);

void			*ft_memalloc(size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, const size_t len);

char			*ft_strupcase(char *str);
char			*ft_strdup(const char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strmcat(const char *s1, const char *s2, int n);
char			*ft_strncpy(char *dst, const char *src, size_t len);

void			ft_bzero(void *s, size_t n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char const *s, int fd);

size_t			ft_strlen(const char *str);
size_t			ft_idxof(char c, const char *str);
size_t			ft_numlen(long long int nb);
size_t			ft_unsignedlen(unsigned long long int nb);
size_t			ft_unsignedlen_base(unsigned long long int n, const char *base);

long long int	ft_abs(long long int nb);
long long int	ft_min(long long int a, long long int b);
long long int	ft_max(long long int a, long long int b);
long long int	ft_freturn(void *ptr, long long int ret);

#endif
