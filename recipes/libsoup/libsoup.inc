RECIPE_TYPES = "machine"
COMPATIBLE_HOST_ARCHS = ".*linux"

require conf/fetch/gnome.conf
SRC_URI_SUBDIR = "${@'.'.join(d.getVar('PV', True).split('.')[:2])}"
SRC_URI = "${GNOME_MIRROR}/${PN}/${SRC_URI_SUBDIR}/${PN}-${PV}.tar.xz"

inherit autotools library pkgconfig

DEPENDS = "libglib-2.0 libgobject-2.0 libgio-2.0 native:glib-utils"
DEPENDS += "libxml2 libsqlite3 libpsl"

EXTRA_OECONF += "--without-gnome"

do_configure[prefuncs] += "do_configure_pre"
do_configure_pre() {
	pkg-config --list-all 
}

FILES_${PN}-doc += "${datadir}/gtk-doc"
