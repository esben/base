RECIPE_FLAGS = "avahi_autoipd avahi_daemon"

inherit autotools pkgconfig gettext sysvinit

SRC_URI = "http://avahi.org/download/avahi-${PV}.tar.gz"

DEPENDS = "libpthread"

DEPENDS += "${DEPENDS_DAEMON}"
DEPENDS_DAEMON = ""

DEPENDS += "${DEPENDS_EXPAT}"
DEPENDS_EXPAT = ""

DEPENDS += "${DEPENDS_GLIB}"
DEPENDS_GLIB = ""

DEPENDS += "${DEPENDS_DBUS}"
DEPENDS_DBUS = ""

# FIXME: this is broken, and should be replaced with proper patch
# so that localedir is used instead of avahilocaledir
export DATADIRNAME = "share"

EXTRA_OECONF = "--with-distro=none \
	--disable-introspection \
	--disable-stack-protector \
	--disable-gdbm \
	--disable-qt3 --disable-qt4 \
	--disable-gtk --disable-gtk3 \
	--disable-mono --disable-monodoc \
	--disable-python \
	--disable-doxygen-doc \
"

EXTRA_OECONF += "${EXTRA_OECONF_DAEMON}"
EXTRA_OECONF_DAEMON = "--disable-libdaemon"

EXTRA_OECONF += "${EXTRA_OECONF_AUTOIPD}"
EXTRA_OECONF_AUTOIPD = "--disable-autoipd"

EXTRA_OECONF += "${EXTRA_OECONF_XML}"
EXTRA_OECONF_XML = "--with-xml=none"

EXTRA_OECONF += "${EXTRA_OECONF_GLIB}"
EXTRA_OECONF_GLIB = "--disable-glib --disable-gobject"

EXTRA_OECONF += "${EXTRA_OECONF_DBUS}"
EXTRA_OECONF_DBUS = "--disable-dbus"

EXTRA_OECONF_AUTOIPD:USE_avahi_autoipd = "--enable-autoipd"
DEPENDS_DAEMON:USE_avahi_autoipd = "libdaemon"
EXTRA_OECONF_DAEMON:USE_avahi_autoipd = "--enable-libdaemon"

DEPENDS_DAEMON:USE_avahi_daemon = "libdaemon"
EXTRA_OECONF_DAEMON:USE_avahi_daemon = "--enable-libdaemon"
DEPENDS_EXPAT:USE_avahi_daemon = "libexpat"
EXTRA_OECONF_EXPAT:USE_avahi_daemon = ""

DEPENDS_GLIB:USE_avahi_glib = "libglib libgobject"
EXTRA_OECONF_GLIB:USE_avahi_glib = ""

DEPENDS_DBUS:USE_avahi_dbus = "libdbus"
EXTRA_OECONF_DBUS:USE_avahi_dbus = ""

# breaks because of error in server.c:
#        struct sockaddr_in6 lsa;
# which is because ipv6 being disabled in uclibc.
# avahi should probably be fixed to allow non-ipv6 builds also.

inherit auto-package-libs
AUTO_PACKAGE_LIBS = "avahi-common avahi-core"
FILES_${PN}-libavahi-common = "${includedir}/avahi-common"
FILES_${PN}-libavahi-core = "${includedir}/avahi-core"
