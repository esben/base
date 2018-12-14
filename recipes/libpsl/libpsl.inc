DESCRIPTION = "TODO"
HOMEPAGE = "TODO"

COMPATIBLE_HOST_ARCHS = ".*linux"
RECIPE_TYPES = "machine native sdk"
PROVIDES_${PN} = "libpsl"
AUTO_PACKAGE_UTILS = "libpsl"
LIBRARY_NAME = "libpsl"


SRC_URI = "git://github.com/rockdaboot/${PN}.git;commit=${RELEASE_COMMIT}"
SRC_URI += "file://public_suffix_list.dat"

S = "${SRCDIR}/${PN}"

inherit autotools-autoreconf pkgconfig library

inherit auto-package-libs
inherit auto-package-utils

do_autoreconf[prefuncs] += "do_autoreconf_pre"
do_autoreconf_pre() {
	# avoid the gtk-doc package
	echo "EXTRA_DIST =" >gtk-doc.make
	echo "CLEANFILES =" >>gtk-doc.make
	cp -p ../public_suffix_list.dat list
}

do_install[postfuncs] = "do_install_rm"

do_install_rm() {
  rm -rf ${D}/usr/bin/psl
}

