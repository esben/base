DESCRIPTION = "GNU Screen"

SRC_URI = "http://ftp.gnu.org/gnu/screen/screen-${PV}.tar.gz"

DEPENDS = "libncurses libcrypt"

inherit autotools-autoreconf

SRC_URI += "file://linux-gnu.site"
SRC_HOST_SITEFILES = "${SRCDIR}/${HOST_OS}.site"
SRC_HOST_SITEFILES:HOST_OS_linux-gnueabi = "${SRCDIR}/linux-gnu.site"

EXTRA_OECONF = "--with-pty-mode=0620 --with-pty-group=5"
