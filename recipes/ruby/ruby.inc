DESCRIPTION = "A dynamic, open source programming language with a focus on simplicity and productivity. It has an elegant syntax that is natural to read and easy to write."
LICENSE = "GPL"

RECIPE_TYPES = "machine native"

DEPENDS = "libdl librt libm libcrypt libz libssl libcrypto"

DEPENDS += "${DEPENDS_SELF}"
DEPENDS_SELF = "native:ruby"
DEPENDS_SELF:native = ""

SHRT_VER = "${@'.'.join(d.get('PV').split('.')[:2])}"
SRC_URI = "ftp://ftp.ruby-lang.org/pub/ruby/${SHRT_VER}/ruby-${PV}.tar.gz"

inherit autotools-autoreconf

# fix building of socket extension
EXTRA_OECONF = "--enable-wide-getaddrinfo"

# This snippet lets compiled extensions which rely on external libraries,
# such as zlib, compile properly.  If we don't do this, then when extmk.rb
# runs, it uses the native libraries instead of the target libraries, and so
# none of the linking operations succeed -- which makes extconf.rb think
# that the libraries aren't available and hence that the extension can't be
# built.

do_configure[prefuncs] += "do_configure_flags_fixup"
do_configure_flags_fixup() {
	sed -i "s#%%TARGET_CFLAGS%%#$TARGET_CFLAGS#; s#%%TARGET_LDFLAGS%%#$TARGET_LDFLAGS#" ${S}/common.mk
	rm -rf ${S}/ruby/
}