#include <errno.h>

const char *sys_errlist[] = {
	"Argument list too long", // E2BIG
	"Permission denied", // EACCES
	"Address in use", // EADDRINUSE
	"Address not available", // EADDRNOTAVAIL
	"Address family not supported", // EAFNOSUPPORT
	"Resource temporarily unavailable", // EAGAIN
	"Connection already in progress", // EALREADY
	"Bad file descriptor", // EBADF
	"Bad message", // EBADMSG
	"Device or resource busy", // EBUSY
	"Operation canceled", // ECANCELED
	"No child processes", // ECHILD
	"Connection aborted", // ECONNABORTED
	"Connection refused", // ECONNREFUSED
	"Connection reset", // ECONNRESET
	"Resource deadlock avoided", // EDEADLK
	"Destination address required", // EDESTADDRREQ
	"Mathematics argument out of domain", // EDOM
	"Disk quota exceeded", // EDQUOT
	"File exists", // EEXIST
	"Bad address", // EFAULT
	"File too large", // EFBIG
	"Host is unreachable", // EHOSTUNREACH
	"Identifier removed", // EIDRM
	"Illegal byte sequence", // EILSEQ
	"Operation in progress", // EINPROGRESS
	"Interrupted function call", // EINTR
	"Invalid argument", // EINVAL
	"I/O error", // EIO
	"Socket is connected", // EISCONN
	"Is a directory", // EISDIR
	"Too many levels of symbolic links", // ELOOP
	"Too many open files", // EMFILE
	"Too many links", // EMLINK
	"Message too large", // EMSGSIZE
	"Multihop attempted", // EMULTIHOP
	"Filename too long", // ENAMETOOLONG
	"Network is down", // ENETDOWN
	"Network reset", // ENETRESET
	"Network unreachable", // ENETUNREACH
	"Too many open files in system", // ENFILE
	"No buffer space available", // ENOBUFS
	"No such device", // ENODEV
	"No such file or directory", // ENOENT
	"Exec format error", // ENOEXEC
	"No locks available", // ENOLCK
	"Link has been severed", // ENOLINK
	"Not enough memory", // ENOMEM
	"No message of the desired type", // ENOMSG
	"Protocol not available", // ENOPROTOOPT
	"No space left on device", // ENOSPC
	"Function not implemented", // ENOSYS
	"Socket is not connected", // ENOTCONN
	"Not a directory", // ENOTDIR
	"Directory not empty", // ENOTEMPTY
	"State not recoverable", // ENOTRECOVERABLE
	"Not a socket", // ENOTSOCK
	"Operation not supported", // ENOTSUP
	"Inappropriate I/O control operation", // ENOTTY
	"No such device or address", // ENXIO
	"Operation not supported on socket", // EOPNOTSUPP
	"Value too large to be stored in data type", // EOVERFLOW
	"Owner died", // EOWNERDEAD
	"Operation not permitted", // EPERM
	"Broken pipe", // EPIPE
	"Protocol error", // EPROTO
	"Protocol not supported", // EPROTONOSUPPORT
	"Protocol wrong type for socket", // EPROTOTYPE
	"Result too large", // ERANGE
	"Read-only file system", // EROFS
	"Socket type not supported", // ESOCKTNOSUPPORT
	"Invalid seek", // ESPIPE
	"No such process", // ESRCH
	"Stale file handle", // ESTALE
	"Connection timed out", // ETIMEDOUT
	"Text file busy", // ETXTBSY
	"Operation would block", // EWOULDBLOCK
	"Cross-device link", // EXDEV
};

int sys_nerr = EXDEV + 1;
