DESCRIPTION = "Library for ASN.1 and DER manipulation"
HOMEPAGE = "http://www.gnu.org/software/libtasn1/"

LICENSE = "GPLv3+ & LGPLv2.1+"
LICENSE_${PN} = "LGPLv2.1+"
LICENSE_${PN}-dev = "LGPLv2.1+"

RECIPE_TYPES = "machine native"

require conf/fetch/gnu.conf
SRC_URI = "${GNU_MIRROR}/libtasn1/libtasn1-${PV}.tar.gz"

inherit autotools-autoreconf binconfig library

inherit auto-package-utils
AUTO_PACKAGE_UTILS = "asn1Coding asn1Parser asn1Decoding"
LICENSE_${PN}-asn1coding = "GPLv3+"
LICENSE_${PN}-asn1parser = "GPLv3+"
LICENSE_${PN}-asn1decoding = "GPLv3+"
