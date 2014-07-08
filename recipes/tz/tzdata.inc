SRC_URI = "ftp://ftp.iana.org/tz/releases/tzdata${PV}.tar.gz;subdir=${PN}-${PV}"
SRC_URI += "file://tzdata-only.patch"

inherit make

DEPENDS = "native:util/zic"

EXTRA_OEMAKE = '\
	DESTDIR="${D}" \
	TZDIR="${datadir}/\\$(TZDIR_BASENAME)" \
	zic="zic" \
'

PACKAGES = "${PN}"
FILES_${PN} = "${datadir}"
