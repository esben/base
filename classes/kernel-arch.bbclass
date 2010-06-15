#
# set the KERNEL_ARCH environment variable for kernel compilation (including
# modules). return value must match one of the architecture directories
# in the kernel source "arch" directory
#

valid_kernel_archs = "alpha arm avr32 blackfin cris frv h8300 ia64 m32r m68k \
	m68knommu microblaze mips mn10300 parisc powerpc s390 score sh sparc \
	um x86 xtensa"

export KERNEL_ARCH = "${@map_kernel_arch(bb.data.getVar('TARGET_ARCH', d, 1), d)}"

def map_kernel_arch(arch, d):
	import bb, re

	arch = re.split('-', arch)[0]
	valid_archs = bb.data.getVar('valid_kernel_archs', d, 1).split()

	if   re.match('(i.86)$', arch):		return 'x86'
	elif re.match('armeb$', arch):		return 'arm'
	elif re.match('mipsel$', arch):		return 'mips'
	elif re.match('sh(3|4)$', arch):	return 'sh'
	elif re.match('bfin', arch):		return 'blackfin'
        elif arch in valid_archs:		return arch
	else:
		bb.error("cannot map '%s' to a linux kernel architecture" % a)

export UBOOT_ARCH = "${@map_uboot_arch(bb.data.getVar('ARCH', d, 1), d)}"

def map_uboot_arch(a, d):
	if a == "powerpc":
		return "ppc"
	return a
