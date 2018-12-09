/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 04:02:07 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/09 05:22:09 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include "ft_error.h"
/*
static const char	*const g_errors[] =
{
	FT_SUCCESS,
	FT_E2BIG,
	FT_EACCES,
	FT_EADDRINUSE,
	FT_EADDRNOTAVAIL,
	FT_EAFNOSUPPORT,
	FT_EAGAIN,
	FT_EALREADY,
	FT_EBADE,
	FT_EBADF,
	FT_EBADFD,
	FT_EBADMSG,
	FT_EBADR,
	FT_EBADRQC,
	FT_EBADSLT,
	FT_EBUSY,
	FT_ECANCELED,
	FT_ECHILD,
	FT_ECHRNG,
	FT_ECOMM,
	FT_ECONNABORTED,
	FT_ECONNREFUSED,
	FT_ECONNRESET,
	FT_EDEADLK,
	FT_EDEADLOCK,
	FT_EDESTADDRREQ,
	FT_EDOM,
	FT_EDQUOT,
	FT_EEXIST,
	FT_EFAULT,
	FT_EFBIG,
	FT_EHOSTDOWN,
	FT_EHOSTUNREACH,
	FT_EHWPOISON,
	FT_EIDRM,
	FT_EILSEQ,
	FT_EINPROGRESS,
	FT_EINTR,
	FT_EINVAL,
	FT_EIO,
	FT_EISCONN,
	FT_EISDIR,
	FT_EISNAM,
	FT_EKEYEXPIRED,
	FT_EKEYREJECTED,
	FT_EKEYREVOKED,
	FT_EL2HLT,
	FT_EL2NSYNC,
	FT_EL3HLT,
	FT_EL3RST,
	FT_ELIBACC,
	FT_ELIBBAD,
	FT_ELIBMAX,
	FT_ELIBSCN,
	FT_ELIBEXEC,
	FT_ELNRANGE,
	FT_ELOOP,
	FT_EMEDIUMTYPE,
	FT_EMFILE,
	FT_EMLINK,
	FT_EMSGSIZE,
	FT_EMULTIHOP,
	FT_ENAMETOOLONG,
	FT_ENETDOWN,
	FT_ENETRESET,
	FT_ENETUNREACH,
	FT_ENFILE,
	FT_ENOANO,
	FT_ENOBUFS,
	FT_ENODATA,
	FT_ENODEV,
	FT_ENOENT,
	FT_ENOEXEC,
	FT_ENOKEY,
	FT_ENOLCK,
	FT_ENOLINK,
	FT_ENOMEDIUM,
	FT_ENOMEM,
	FT_ENOMSG,
	FT_ENONET,
	FT_ENOPKG,
	FT_ENOPROTOOPT,
	FT_ENOSPC,
	FT_ENOSR,
	FT_ENOSTR,
	FT_ENOSYS,
	FT_ENOTBLK,
	FT_ENOTCONN,
	FT_ENOTDIR,
	FT_ENOTEMPTY,
	FT_ENOTRECOVERABLE,
	FT_ENOTSOCK,
	FT_ENOTSUP,
	FT_ENOTTY,
	FT_ENOTUNIQ,
	FT_ENXIO,
	FT_EOPNOTSUPP,
	FT_EOVERFLOW,
	FT_EOWNERDEAD,
	FT_EPERM,
	FT_EPFNOSUPPORT,
	FT_EPIPE,
	FT_EPROTO,
	FT_EPROTONOSUPPORT,
	FT_EPROTOTYPE,
	FT_ERANGE,
	FT_EREMCHG,
	FT_EREMOTE,
	FT_EREMOTEIO,
	FT_ERESTART,
	FT_ERFKILL,
	FT_EROFS,
	FT_ESHUTDOWN,
	FT_ESPIPE,
	FT_ESOCKTNOSUPPORT,
	FT_ESRCH,
	FT_ESTALE,
	FT_ESTRPIPE,
	FT_ETIME,
	FT_ETIMEDOUT,
	FT_ETOOMANYREFS,
	FT_ETXTBSY,
	FT_EUCLEAN,
	FT_EUNATCH,
	FT_EUSERS,
	FT_EWOULDBLOCK,
	FT_EXDEV,
	FT_EXFULL
};
*/
char					*ft_strerror(const int errnum)
{
	int					i;

	i = 0;
	if (errnum == 0)
		return ((char *)g_error_table[0].msg);
	while (g_error_table[i].name && g_error_table[i].value != errnum)
		i++;
	if (g_error_table[i].value == 0)
		return (NULL);
	return ((char *)g_error_table[i].msg);
}

void					ft_perror(const char *str)
{
	register const char	*s;

	s = str;
	while (s && *s)
		s++;
	if (s && str != s)
		write(2, str, s - str);
	write(2, ": ", 2);
	str = ft_strerror(errno);
	s = str;
	while (s && *s)
		s++;
	if (s && str != s)
		write(2, str, s - str);
	write(2, "\n", 1);
}
