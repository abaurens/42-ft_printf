/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 04:24:22 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/09 05:26:39 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include <errno.h>
# include <stdlib.h>

typedef struct	s_error_info
{
  int			value;
  const char	*name;
  const char	*msg;
}				t_error_info;

# define FT_SUCCESS 0

static const t_error_info g_error_table[] =
{
	{FT_SUCCESS, "FT_SUCCESS", "Success"},
# ifdef EPERM
	{EPERM, "EPERM", "Not owner"},
# endif
# ifdef ENOENT
	{ENOENT, "ENOENT", "No such file or directory"},
# endif
# ifdef ESRCH
	{ESRCH, "ESRCH", "No such process"},
# endif
# ifdef EINTR
	{EINTR, "EINTR", "Interrupted system call"},
# endif
# ifdef EIO
	{EIO, "EIO", "I/O error"},
# endif
# ifdef ENXIO
	{ENXIO, "ENXIO", "No such device or address"},
# endif
# ifdef E2BIG
	{E2BIG, "E2BIG", "Arg list too long"},
# endif
# ifdef ENOEXEC
	{ENOEXEC, "ENOEXEC", "Exec format error"},
# endif
# ifdef EBADF
	{EBADF, "EBADF", "Bad file number"},
# endif
# ifdef ECHILD
	{ECHILD, "ECHILD", "No child processes"},
# endif
# ifdef EWOULDBLOCK
	{EWOULDBLOCK, "EWOULDBLOCK", "Operation would block"},
# endif
# ifdef EAGAIN
	{EAGAIN, "EAGAIN", "No more processes"},
# endif
# ifdef ENOMEM
	{ENOMEM, "ENOMEM", "Not enough space"},
# endif
# ifdef EACCES
	{EACCES, "EACCES", "Permission denied"},
# endif
# ifdef EFAULT
	{EFAULT, "EFAULT", "Bad address"},
# endif
# ifdef ENOTBLK
	{ENOTBLK, "ENOTBLK", "Block device required"},
# endif
# ifdef EBUSY
	{EBUSY, "EBUSY", "Device busy"},
# endif
# ifdef EEXIST
	{EEXIST, "EEXIST", "File exists"},
# endif
# ifdef EXDEV
	{EXDEV, "EXDEV", "Cross-device link"},
# endif
# ifdef ENODEV
	{ENODEV, "ENODEV", "No such device"},
# endif
# ifdef ENOTDIR
	{ENOTDIR, "ENOTDIR", "Not a directory"},
# endif
# ifdef EISDIR
	{EISDIR, "EISDIR", "Is a directory"},
# endif
# ifdef EINVAL
	{EINVAL, "EINVAL", "Invalid argument"},
# endif
# ifdef ENFILE
	{ENFILE, "ENFILE", "File table overflow"},
# endif
# ifdef EMFILE
	{EMFILE, "EMFILE", "Too many open files"},
# endif
# ifdef ENOTTY
	{ENOTTY, "ENOTTY", "Not a typewriter"},
# endif
# ifdef ETXTBSY
	{ETXTBSY, "ETXTBSY", "Text file busy"},
# endif
# ifdef EFBIG
	{EFBIG, "EFBIG", "File too large"},
# endif
# ifdef ENOSPC
	{ENOSPC, "ENOSPC", "No space left on device"},
# endif
# ifdef ESPIPE
	{ESPIPE, "ESPIPE", "Illegal seek"},
# endif
# ifdef EROFS
	{EROFS, "EROFS", "Read-only file system"},
# endif
# ifdef EMLINK
	{EMLINK, "EMLINK", "Too many links"},
# endif
# ifdef EPIPE
	{EPIPE, "EPIPE", "Broken pipe"},
# endif
# ifdef EDOM
	{EDOM, "EDOM", "Math argument out of domain of func"},
# endif
# ifdef ERANGE
	{ERANGE, "ERANGE", "Math result not representable"},
# endif
# ifdef ENOMSG
	{ENOMSG, "ENOMSG", "No message of desired type"},
# endif
# ifdef EIDRM
	{EIDRM, "EIDRM", "Identifier removed"},
# endif
# ifdef ECHRNG
	{ECHRNG, "ECHRNG", "Channel number out of range"},
# endif
# ifdef EL2NSYNC
	{EL2NSYNC, "EL2NSYNC", "Level 2 not synchronized"},
# endif
# ifdef EL3HLT
	{EL3HLT, "EL3HLT", "Level 3 halted"},
# endif
# ifdef EL3RST
	{EL3RST, "EL3RST", "Level 3 reset"},
# endif
# ifdef ELNRNG
	{ELNRNG, "ELNRNG", "Link number out of range"},
# endif
# ifdef EUNATCH
	{EUNATCH, "EUNATCH", "Protocol driver not attached"},
# endif
# ifdef ENOCSI
	{ENOCSI, "ENOCSI", "No CSI structure available"},
# endif
# ifdef EL2HLT
	{EL2HLT, "EL2HLT", "Level 2 halted"},
# endif
# ifdef EDEADLK
	{EDEADLK, "EDEADLK", "Deadlock condition"},
# endif
# ifdef ENOLCK
	{ENOLCK, "ENOLCK", "No record locks available"},
# endif
# ifdef EBADE
	{EBADE, "EBADE", "Invalid exchange"},
# endif
# ifdef EBADR
	{EBADR, "EBADR", "Invalid request descriptor"},
# endif
# ifdef EXFULL
	{EXFULL, "EXFULL", "Exchange full"},
# endif
# ifdef ENOANO
	{ENOANO, "ENOANO", "No anode"},
# endif
# ifdef EBADRQC
	{EBADRQC, "EBADRQC", "Invalid request code"},
# endif
# ifdef EBADSLT
	{EBADSLT, "EBADSLT", "Invalid slot"},
# endif
# ifdef EDEADLOCK
	{EDEADLOCK, "EDEADLOCK", "File locking deadlock error"},
# endif
# ifdef EBFONT
	{EBFONT, "EBFONT", "Bad font file format"},
# endif
# ifdef ENOSTR
	{ENOSTR, "ENOSTR", "Device not a stream"},
# endif
# ifdef ENODATA
	{ENODATA, "ENODATA", "No data available"},
# endif
# ifdef ETIME
	{ETIME, "ETIME", "Timer expired"},
# endif
# ifdef ENOSR
	{ENOSR, "ENOSR", "Out of streams resources"},
# endif
# ifdef ENONET
	{ENONET, "ENONET", "Machine is not on the network"},
# endif
# ifdef ENOPKG
	{ENOPKG, "ENOPKG", "Package not installed"},
# endif
# ifdef EREMOTE
	{EREMOTE, "EREMOTE", "Object is remote"},
# endif
# ifdef ENOLINK
	{ENOLINK, "ENOLINK", "Link has been severed"},
# endif
# ifdef EADV
	{EADV, "EADV", "Advertise error"},
# endif
# ifdef ESRMNT
	{ESRMNT, "ESRMNT", "Srmount error"},
# endif
# ifdef ECOMM
	{ECOMM, "ECOMM", "Communication error on send"},
# endif
# ifdef EPROTO
	{EPROTO, "EPROTO", "Protocol error"},
# endif
# ifdef EMULTIHOP
	{EMULTIHOP, "EMULTIHOP", "Multihop attempted"},
# endif
# ifdef EDOTDOT
	{EDOTDOT, "EDOTDOT", "RFS specific error"},
# endif
# ifdef EBADMSG
	{EBADMSG, "EBADMSG", "Not a data message"},
# endif
# ifdef ENAMETOOLONG
	{ENAMETOOLONG, "ENAMETOOLONG", "File name too long"},
# endif
# ifdef EOVERFLOW
	{EOVERFLOW, "EOVERFLOW", "Value too large for defined data type"},
# endif
# ifdef ENOTUNIQ
	{ENOTUNIQ, "ENOTUNIQ", "Name not unique on network"},
# endif
# ifdef EBADFD
	{EBADFD, "EBADFD", "File descriptor in bad state"},
# endif
# ifdef EREMCHG
	{EREMCHG, "EREMCHG", "Remote address changed"},
# endif
# ifdef ELIBACC
	{ELIBACC, "ELIBACC", "Can not access a needed shared library"},
# endif
# ifdef ELIBBAD
	{ELIBBAD, "ELIBBAD", "Accessing a corrupted shared library"},
# endif
# ifdef ELIBSCN
	{ELIBSCN, "ELIBSCN", ".lib section in a.out corrupted"},
# endif
# ifdef ELIBMAX
	{ELIBMAX, "ELIBMAX", "Attempting to link in too many shared libraries"},
# endif
# ifdef ELIBEXEC
	{ELIBEXEC, "ELIBEXEC", "Cannot exec a shared library directly"},
# endif
# ifdef EILSEQ
	{EILSEQ, "EILSEQ", "Illegal byte sequence"},
# endif
# ifdef ENOSYS
	{ENOSYS, "ENOSYS", "Operation not applicable"},
# endif
# ifdef ELOOP
	{ELOOP, "ELOOP", "Too many symbolic links encountered"},
# endif
# ifdef ERESTART
	{ERESTART, "ERESTART", "Interrupted system call should be restarted"},
# endif
# ifdef ESTRPIPE
	{ESTRPIPE, "ESTRPIPE", "Streams pipe error"},
# endif
# ifdef ENOTEMPTY
	{ENOTEMPTY, "ENOTEMPTY", "Directory not empty"},
# endif
# ifdef EUSERS
	{EUSERS, "EUSERS", "Too many users"},
# endif
# ifdef ENOTSOCK
	{ENOTSOCK, "ENOTSOCK", "Socket operation on non-socket"},
# endif
# ifdef EDESTADDRREQ
	{EDESTADDRREQ, "EDESTADDRREQ", "Destination address required"},
# endif
# ifdef EMSGSIZE
	{EMSGSIZE, "EMSGSIZE", "Message too long"},
# endif
# ifdef EPROTOTYPE
	{EPROTOTYPE, "EPROTOTYPE", "Protocol wrong type for socket"},
# endif
# ifdef ENOPROTOOPT
	{ENOPROTOOPT, "ENOPROTOOPT", "Protocol not available"},
# endif
# ifdef EPROTONOSUPPORT
	{EPROTONOSUPPORT, "EPROTONOSUPPORT", "Protocol not supported"},
# endif
# ifdef ESOCKTNOSUPPORT
	{ESOCKTNOSUPPORT, "ESOCKTNOSUPPORT", "Socket type not supported"},
# endif
# ifdef EOPNOTSUPP
	{EOPNOTSUPP, "EOPNOTSUPP", "Operation not supported on transport endpoint"},
# endif
# ifdef EPFNOSUPPORT
	{EPFNOSUPPORT, "EPFNOSUPPORT", "Protocol family not supported"},
# endif
# ifdef EAFNOSUPPORT
	{EAFNOSUPPORT, "EAFNOSUPPORT", "Address family not supported by protocol"},
# endif
# ifdef EADDRINUSE
	{EADDRINUSE, "EADDRINUSE", "Address already in use"},
# endif
# ifdef EADDRNOTAVAIL
	{EADDRNOTAVAIL, "EADDRNOTAVAIL","Cannot assign requested address"},
# endif
# ifdef ENETDOWN
	{ENETDOWN, "ENETDOWN", "Network is down"},
# endif
# ifdef ENETUNREACH
	{ENETUNREACH, "ENETUNREACH", "Network is unreachable"},
# endif
# ifdef ENETRESET
	{ENETRESET, "ENETRESET", "Network dropped connection because of reset"},
# endif
# ifdef ECONNABORTED
	{ECONNABORTED, "ECONNABORTED", "Software caused connection abort"},
# endif
# ifdef ECONNRESET
	{ECONNRESET, "ECONNRESET", "Connection reset by peer"},
# endif
# ifdef ENOBUFS
	{ENOBUFS, "ENOBUFS", "No buffer space available"},
# endif
# ifdef EISCONN
	{EISCONN, "EISCONN", "Transport endpoint is already connected"},
# endif
# ifdef ENOTCONN
	{ENOTCONN, "ENOTCONN", "Transport endpoint is not connected"},
# endif
# ifdef ESHUTDOWN
	{ESHUTDOWN, "ESHUTDOWN", "Cannot send after transport endpoint shutdown"},
# endif
# ifdef ETOOMANYREFS
	{ETOOMANYREFS, "ETOOMANYREFS", "Too many references: cannot splice"},
# endif
# ifdef ETIMEDOUT
	{ETIMEDOUT, "ETIMEDOUT", "Connection timed out"},
# endif
# ifdef ECONNREFUSED
	{ECONNREFUSED, "ECONNREFUSED", "Connection refused"},
# endif
# ifdef EHOSTDOWN
	{EHOSTDOWN, "EHOSTDOWN", "Host is down"},
# endif
# ifdef EHOSTUNREACH
	{EHOSTUNREACH, "EHOSTUNREACH", "No route to host"},
# endif
# ifdef EALREADY
	{EALREADY, "EALREADY", "Operation already in progress"},
# endif
# ifdef EINPROGRESS
	{EINPROGRESS, "EINPROGRESS", "Operation now in progress"},
# endif
# ifdef ESTALE
	{ESTALE, "ESTALE", "Stale NFS file handle"},
# endif
# ifdef EUCLEAN
	{EUCLEAN, "EUCLEAN", "Structure needs cleaning"},
# endif
# ifdef ENOTNAM
	{ENOTNAM, "ENOTNAM", "Not a XENIX named type file"},
# endif
# ifdef ENAVAIL
	{ENAVAIL, "ENAVAIL", "No XENIX semaphores available"},
# endif
# ifdef EISNAM
	{EISNAM, "EISNAM", "Is a named type file"},
# endif
# ifdef EREMOTEIO
	{EREMOTEIO, "EREMOTEIO", "Remote I/O error"},
# endif
	{0, NULL, NULL},
};
/*
# define FT_E2BIG "Argument list too long."
# define FT_EACCES "Permission denied."
# define FT_EADDRINUSE "Address already in use."
# define FT_EADDRNOTAVAIL "Address not available."
# define FT_EAFNOSUPPORT "Address family not supported."
# define FT_EAGAIN "Resource temporarily unavailable."
# define FT_EALREADY "Connection already in progress."
# define FT_EBADE "Invalid exchange."
# define FT_EBADF "Bad file descriptor."
# define FT_EBADFD "File descriptor in bad state."
# define FT_EBADMSG "Bad message."
# define FT_EBADR "Invalid request descriptor."
# define FT_EBADRQC "Invalid request code."
# define FT_EBADSLT "Invalid slot."
# define FT_EBUSY "Device or resource busy."
# define FT_ECANCELED "Operation canceled."
# define FT_ECHILD "No child processes."
# define FT_ECHRNG "Channel number out of range."
# define FT_ECOMM "Communication error on send."
# define FT_ECONNABORTED "Connection aborted."
# define FT_ECONNREFUSED "Connection refused."
# define FT_ECONNRESET "Connection reset."
# define FT_EDEADLK "Resource deadlock avoided."
# define FT_EDEADLOCK "Synonym for EDEADLK."
# define FT_EDESTADDRREQ "Destination address required."
# define FT_EDOM "Mathematics argument out of domain of function."
# define FT_EDQUOT "Disk quota exceeded."
# define FT_EEXIST "File exists."
# define FT_EFAULT "Bad address."
# define FT_EFBIG "File too large."
# define FT_EHOSTDOWN "Host is down."
# define FT_EHOSTUNREACH "Host is unreachable."
# define FT_EHWPOISON "Memory page has hardware error."
# define FT_EIDRM "Identifier removed."
*/
/*
**	The text shown here is the glibc error description;
**	in POSIX.1, this error is described as "Illegal byte sequence".
*//*
# define FT_EILSEQ "Invalid or incomplete multibyte or wide character."
# define FT_EINPROGRESS "Operation in progress."
# define FT_EINTR "Interrupted function call."
# define FT_EINVAL "Invalid argument."
# define FT_EIO "Input/output error."
# define FT_EISCONN "Socket is connected."
# define FT_EISDIR "Is a directory."
# define FT_EISNAM "Is a named type file."
# define FT_EKEYEXPIRED "Key has expired."
# define FT_EKEYREJECTED "Key was rejected by service."
# define FT_EKEYREVOKED "Key has been revoked."
# define FT_EL2HLT "Level 2 halted."
# define FT_EL2NSYNC "Level 2 not synchronized."
# define FT_EL3HLT "Level 3 halted."
# define FT_EL3RST "Level 3 reset."
# define FT_ELIBACC "Cannot access a needed shared library."
# define FT_ELIBBAD "Accessing a corrupted shared library."
# define FT_ELIBMAX "Attempting to link in too many shared libraries."
# define FT_ELIBSCN ".lib section in a.out corrupted"
# define FT_ELIBEXEC "Cannot exec a shared library directly."
# define FT_ELNRANGE "Link number out of range."
# define FT_ELOOP "Too many levels of symbolic links."
# define FT_EMEDIUMTYPE "Wrong medium type."
# define FT_EMFILE "Too many open files."
# define FT_EMLINK "Too many links."
# define FT_EMSGSIZE "Message too long."
# define FT_EMULTIHOP "Multihop attempted."
# define FT_ENAMETOOLONG "Filename too long."
# define FT_ENETDOWN "Network is down."
# define FT_ENETRESET "Connection aborted by network."
# define FT_ENETUNREACH "Network unreachable."
# define FT_ENFILE "Too many open files in system."
# define FT_ENOANO "No anode."
# define FT_ENOBUFS "No buffer space available."
# define FT_ENODATA "No message is available on the STREAM head read queue."
# define FT_ENODEV "No such device."
# define FT_ENOENT "No such file or directory."
# define FT_ENOEXEC "Exec format error."
# define FT_ENOKEY "Required key not available."
# define FT_ENOLCK "No locks available."
# define FT_ENOLINK "Link has been severed."
# define FT_ENOMEDIUM "No medium found."
# define FT_ENOMEM "Not enough space/cannot allocate memory."
# define FT_ENOMSG "No message of the desired type."
# define FT_ENONET "Machine is not on the network."
# define FT_ENOPKG "Package not installed."
# define FT_ENOPROTOOPT "Protocol not available."
# define FT_ENOSPC "No space left on device."
# define FT_ENOSR "No STREAM resources."
# define FT_ENOSTR "Not a STREAM."
# define FT_ENOSYS "Function not implemented."
# define FT_ENOTBLK "Block device required."
# define FT_ENOTCONN "The socket is not connected."
# define FT_ENOTDIR "Not a directory."
# define FT_ENOTEMPTY "Directory not empty."
# define FT_ENOTRECOVERABLE "State not recoverable."
# define FT_ENOTSOCK "Not a socket."
# define FT_ENOTSUP "Operation not supported."
# define FT_ENOTTY "Inappropriate I/O control operation."
# define FT_ENOTUNIQ "Name not unique on network."
# define FT_ENXIO "No such device or address."
*/
/*
**	(ENOTSUP and EOPNOTSUPP have the same value on Linux, but according to
**	POSIX.1 these error values should be distinct.
*//*
# define FT_EOPNOTSUPP "Operation not supported on socket."
# define FT_EOVERFLOW "Value too large to be stored in data type."
# define FT_EOWNERDEAD "Owner died."
# define FT_EPERM "Operation not permitted."
# define FT_EPFNOSUPPORT "Protocol family not supported."
# define FT_EPIPE "Broken pipe."
# define FT_EPROTO "Protocol error."
# define FT_EPROTONOSUPPORT "Protocol not supported."
# define FT_EPROTOTYPE "Protocol wrong type for socket."
# define FT_ERANGE "Result too large."
# define FT_EREMCHG "Remote address changed."
# define FT_EREMOTE "Object is remote."
# define FT_EREMOTEIO "Remote I/O error."
# define FT_ERESTART "Interrupted system call should be restarted."
# define FT_ERFKILL "Operation not possible due to RF-kill."
# define FT_EROFS "Read-only filesystem."
# define FT_ESHUTDOWN "Cannot send after transport endpoint shutdown."
# define FT_ESPIPE "Invalid seek."
# define FT_ESOCKTNOSUPPORT "Socket type not supported."
# define FT_ESRCH "No such process."
# define FT_ESTALE "Stale file handle."
# define FT_ESTRPIPE "Streams pipe error."
*/
/*
**	(POSIX.1 says "STREAM ioctl(2) timeout".
*//*
# define FT_ETIME "Timer expired."
# define FT_ETIMEDOUT "Connection timed out."
# define FT_ETOOMANYREFS "Too many references: cannot splice."
# define FT_ETXTBSY "Text file busy."
# define FT_EUCLEAN "Structure needs cleaning."
# define FT_EUNATCH "Protocol driver not attached."
# define FT_EUSERS "Too many users."
# define FT_EWOULDBLOCK "Operation would block."
# define FT_EXDEV "Improper link."
# define FT_EXFULL "Exchange full."
*/
void	ft_perror(const char *str);
char	*ft_strerror(const int errnum);

#endif
