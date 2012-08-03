HOMEPAGE = "http://www.wireshark.org"
LICENSE = "GPL"

require conf/fetch/sourceforge.conf
SRC_URI = "${SOURCEFORGE_MIRROR}/wireshark/wireshark-${PV}.tar.bz2"

DEPENDS = "native:perl libpcap libpcre libexpat libglib libsocket"
# "net-snmp"
# "gnutls"

inherit autotools-autoreconf

#do_compile_prepend() {
#	${BUILD_CC} ${BUILD_CFLAGS} -o rdps rdps.c
#	oe_runmake -C tools/lemon CC="${BUILD_CC} ${BUILD_CFLAGS}" LDFLAGS="${BUILD_LDFLAGS}"
#}
