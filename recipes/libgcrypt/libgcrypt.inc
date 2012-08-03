DESCRIPTION = "A general purpose cryptographic library based on the code from GnuPG"
HOMEPAGE = "http://directory.fsf.org/project/libgcrypt/"

# helper program gcryptrnd and getrandom are under GPL, rest LGPL
LICENSE = "GPLv2+ & LGPLv2.1+"

RECIPE_TYPES = "machine native"

SRC_URI = "ftp://ftp.gnupg.org/gcrypt/libgcrypt/libgcrypt-${PV}.tar.gz"

DEPENDS = "libgpg-error libcap2"

inherit autotools-autoreconf binconfig pkgconfig library

EXTRA_OECONF = "--without-pth --disable-asm --with-capabilities"

do_install[postfuncs] += "do_install_fixup"
do_install_fixup() {
	# libgcrypt.pc is added locally and thus installed here
	install -d ${D}/${libdir}/pkgconfig
	install -m 0644 ${S}/src/libgcrypt.pc ${D}/${libdir}/pkgconfig/

	# Remove empty sbin directory since we don't build the daemon
        # that would install there
	rmdir ${D}${sbindir}
}

#ARM_INSTRUCTION_SET = "arm"

DEPENDS_${PN} += "libgpg-error libcap2"

inherit auto-package-utils
AUTO_PACKAGE_UTILS = "cryptrnd getrandom dumpsexp hmac256"
