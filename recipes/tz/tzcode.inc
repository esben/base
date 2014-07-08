SRC_URI = "ftp://ftp.iana.org/tz/releases/tzcode${PV}.tar.gz;subdir=${PN}-${PV}"
SRC_URI += "ftp://ftp.iana.org/tz/releases/tzdata${PV}.tar.gz;subdir=${PN}-${PV}"
SRC_URI += "file://tzcode-only.patch"

RECIPE_TYPES = "native machine"

inherit c make

EXTRA_OEMAKE = '\
	cc="${CC}" \
	CFLAGS="${CFLAGS}" \
	LDFLAGS="${LDFLAGS}" \
	BINDIR="${bindir}" \
	MANDIR="${mandir}" \
	LIBDIR="${libdir}" \
	TZDIR="${datadir}/\\$(TZDIR_BASENAME)" \
'

EXTRA_OEMAKE_COMPILE = "ALL"
EXTRA_OEMAKE_INSTALL = "INSTALL"

inherit auto-package-utils
AUTO_PACKAGE_UTILS = "tzselect zdump zic date"

inherit auto-package-libs
AUTO_PACKAGE_LIBS = "tz"
PROVIDES_${PN}-libtz[qa] = "allow-missing-soname:libtz"

DEPENDS_${PN} = "${AUTO_PACKAGE_UTILS_PROVIDES}"

# Prefer these utils instead of the ones from toolchain recipe
DEFAULT_PREFERENCE = "10"
