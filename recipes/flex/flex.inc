# -*- mode:python; -*-
RECIPE_TYPES = "machine native"

inherit autotools-autoreconf gettext

DEPENDS += "native:texinfo"

require conf/fetch/sourceforge.conf
SRC_URI += "${SOURCEFORGE_MIRROR}/${PN}/${PN}-${PV}.tar.xz"

DEPENDS_${PN} += "libintl"
RDEPENDS_${PN} += "libintl"
