# -*- mode:python; -*-
RECIPE_TYPES = "machine native"

inherit autotools

require conf/fetch/gnu.conf
SRC_URI += "${GNU_MIRROR}/${PN}/${PN}-${PV}.tar.xz"

