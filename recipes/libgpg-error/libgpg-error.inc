DESCRIPTION = "a small library that defines common error values for all GnuPG components"
HOMEPAGE = "http://www.gnupg.org/related_software/libgpg-error/"

LICENSE = "GPLv2+ & LGPLv2.1+"

RECIPE_TYPES = "machine native"

SRC_URI = "ftp://ftp.gnupg.org/gcrypt/libgpg-error/libgpg-error-${PV}.tar.bz2"

inherit autotools binconfig pkgconfig gettext library

do_install[postfuncs] += "do_install_fixup"
do_install_fixup() {
	# we don't have common lisp in OE
	rm -rf "${D}${datadir}/common-lisp/"
}

inherit auto-package-utils
AUTO_PACKAGE_UTILS = "gpg-error"