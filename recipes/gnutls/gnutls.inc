DESCRIPTION = "GNU Transport Layer Security Library"
HOMEPAGE = "http://www.gnu.org/software/gnutls/"

LICENSE = "GPLv3+ & LGPLv2.1+"
LICENSE_${PN} = "LGPLv2.1+"
LICENSE_${PN}-dev = "LGPLv2.1+"

RECIPE_TYPES = "machine native"

require conf/fetch/gnu.conf
SRC_URI = "${GNU_MIRROR}/gnutls/gnutls-${PV}.tar.bz2"

inherit autotools-autoreconf binconfig pkgconfig gettext c++

DEPENDS = "libz liblzo libtasn1 libgcrypt libcap2 libreadline"

EXTRA_OECONF="--disable-rpath \
	--with-included-opencdk \
	--with-included-libcfg \
        --with-libtasn1-prefix=${HOST_SYSROOT}${prefix} \
	--with-libgcrypt --with-libgcrypt-prefix=${HOST_SYSROOT}${prefix} \
	--with-libdl-prefix=${HOST_SYSROOT}${prefix} \
	--with-libpthread-prefix=${HOST_SYSROOT}${prefix} \
	--with-libreadline-prefix=${HOST_SYSROOT}${prefix} \
	--with-libz-prefix=${HOST_SYSROOT}${prefix} \
	--with-lzo \
	--disable-guile \
	--without-p11-kit \
	"

#do_configure_prepend() {
#	for dir in . lib libextra; do
#		rm -f ${dir}/aclocal.m4 ${dir}/m4/libtool.m4 ${dir}/m4/lt*.m4
#	done
#}

PACKAGES =+ "${PN}-openssl ${PN}-extra ${PN}-bin ${PN}-xx"

FILES_${PN} = "${libdir}/libgnutls.so.*"

inherit auto-package-utils
AUTO_PACKAGE_UTILS = "gnutls-serv gnutls-cli gnutls-srpcrypt \
	srptool psktool p11tool certtool"

#FILES_${PN}-dev += "${bindir}/*-config ${bindir}/gnutls-cli-debug"
FILES_${PN}-extra = "${libdir}/libgnutls-extra.so.*"
FILES_${PN}-openssl = "${libdir}/libgnutls-openssl.so.*"
FILES_${PN}-xx = "${libdir}/libgnutlsxx.so.*"
