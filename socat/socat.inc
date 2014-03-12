DESCRIPTION = 'Socat is a relay for bidirectional data transfer between two independent data channels. Each of these data channels may be a file, pipe, device (serial line etc. or a pseudo terminal), a socket (UNIX, IP4, IP6 - raw, UDP, TCP), an SSL socket, proxy CONNECT connection, a file descriptor (stdin etc.), the GNU line editor (readline), a program, or a combination of two of these.  These modes include generation of "listening" sockets, named pipes, and pseudo terminals.'
SUMMARY = "Multipurpose relay for bidirectional data transfer between two independent data channels"
HOMEPAGE = "http://www.dest-unreach.org/socat/"

SRC_URI = "http://www.dest-unreach.org/socat/download/socat-${PV}.tar.gz"

inherit autotools make-vpath

inherit auto-package-utils
AUTO_PACKAGE_UTILS = 'socat filan procan'
