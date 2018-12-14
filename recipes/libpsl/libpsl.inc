DESCRIPTION = "TODO"
HOMEPAGE = "TODO"

RECIPE_TYPES = "machine"

SRC_URI = "git://github.com/rockdaboot/${PN}.git;${SRC_REV}"
SRC_REV ?= "tag=libpsl-${PV}"
S = "${SRCDIR}/${PN}"

SRC_URI += "git://github.com/publicsuffix/list.git;${SRC_REV_LIST}"
SRC_REV_LIST = "5af964eadf5b6baaf5f612746837cb154e1f73b1"

inherit autotools-autoreconf pkgconfig library

inherit auto-package-utils
AUTO_PACKAGE_UTILS = "psl"

do_autoreconf[prefuncs] += "do_autoreconf_pre"
do_autoreconf_pre() {
	# avoid the gtk-doc package
	echo "EXTRA_DIST =" >gtk-doc.make
	echo "CLEANFILES =" >>gtk-doc.make
	cp ${SRCDIR}/list/public_suffix_list.dat list/
}
