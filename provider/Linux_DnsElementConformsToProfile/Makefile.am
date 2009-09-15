# ==================================================================
# © Copyright IBM Corp. 2007
#
# THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
# ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
# CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
#
# You can obtain a current copy of the Eclipse Public License from
# http://www.opensource.org/licenses/eclipse-1.0.php
#
# Author:       Sam Kannan <samkannan (at) us.ibm.com>
#
# ==================================================================

# providerdir defines where provider libraries will be installed 
# (@PROVIDERDIR@ is set by the configure script). 
providerdir = @PROVIDERDIR@

###############################################################################
AM_CFLAGS = -Wall

AM_CPPFLAGS = \
    -DDEBUG \
    -D_COMPILE_UNIX \
    -DCMPI_STANDALONE \
    -I${srcdir}/../include 
    

################################################################################
provider_LTLIBRARIES = \
    libcmpiLinux_DnsElementConformsToProfile.la 

libcmpiLinux_DnsElementConformsToProfile_la_LDFLAGS = \
    -avoid-version

libcmpiLinux_DnsElementConformsToProfile_la_SOURCES = \
    Linux_ElementConformsToProfile_Resource.c \
    Linux_DnsElementConformsToProfile.c
       
noinst_HEADERS = \
    Linux_ElementConformsToProfile_Resource.h

libcmpiLinux_DnsElementConformsToProfile_la_LIBADD = \
    ${top_builddir}/resource-access/libRaToolsDns.la
