# ==================================================================
# (C) Copyright IBM Corp. 2005
#
# THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
# ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
# CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
#
# You can obtain a current copy of the Eclipse Public License from
# http://www.opensource.org/licenses/eclipse-1.0.php
#
# Author:       Wolfgang Taphorn <taphorn@de.ibm.com>
# Description:  Automake input file for cmpi provider.
# ==================================================================

# SBLIM Include Directory
sblimincdir = $(includedir)/sblim

# SBLIM Headers to be installed
sbliminc_HEADERS =

# docdir defines where the documentation goes
docdir = $(datadir)/doc/$(PACKAGE)-$(VERSION)

# Non-Installable Header Files
noinst_HEADERS =

# Configuration files
sysconf_DATA =

# Scripts that are used in the libraries
pkgdata_SCRIPTS =

# System wide libraries
lib_LTLIBRARIES =

# providerdir defines where provider libraries will be installed (@PROVIDERDIR@ is set by the configure script).
providerdir = @PROVIDERDIR@

AM_CFLAGS = -Wall

AM_CPPFLAGS = \
    -DDEBUG \
    -D_COMPILE_UNIX \
    -DCMPI_STANDALONE \
    -I${srcdir}/../include \
    -I${srcdir}/../../resource-access \
    -I${srcdir}/../CIM_ConcreteJob \
    -I${srcdir}/../Linux_DnsAddressMatchList \
    -I${srcdir}/../Linux_DnsZone

################################################################################
provider_LTLIBRARIES = libcmpiLinux_DnsAllowUpdateForZone.la

################################################################################
# Linux_DnsAllowUpdateForZone
libcmpiLinux_DnsAllowUpdateForZone_la_SOURCES = \
    Linux_DnsAllowUpdateForZoneInstanceName.cpp \
    Linux_DnsAllowUpdateForZoneInstance.cpp \
    Linux_DnsAllowUpdateForZoneExternal.cpp \
    Linux_DnsAllowUpdateForZoneRepositoryInstance.cpp \
    Linux_DnsAllowUpdateForZoneRepositoryExternal.cpp \
    Linux_DnsAllowUpdateForZoneManualInstance.cpp \
    Linux_DnsAllowUpdateForZoneDefaultImplementation.cpp \
    Linux_DnsAllowUpdateForZoneFactory.cpp \
    Linux_DnsAllowUpdateForZoneResourceAccess.cpp \
    CmpiLinux_DnsAllowUpdateForZoneProvider.cpp

libcmpiLinux_DnsAllowUpdateForZone_la_LIBADD = \
    $(top_builddir)/resource-access/libRaToolsDns.la \
    $(top_builddir)/provider/libIBM_DnsProviderTooling.la \
    $(top_builddir)/provider/libLinux_DnsGeneralProviderBasic.la \
    $(top_builddir)/provider/CIM_ConcreteJob/libcmpiDnsCIM_ConcreteJob.la \
    $(top_builddir)/provider/Linux_DnsZone/libcmpiLinux_DnsZone.la \
    $(top_builddir)/provider/Linux_DnsAddressMatchList/libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsAllowUpdateForZone_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
    Linux_DnsAllowUpdateForZoneInterface.h \
    Linux_DnsAllowUpdateForZoneInstanceName.h \
    Linux_DnsAllowUpdateForZoneInstance.h \
    Linux_DnsAllowUpdateForZoneExternal.h \
    Linux_DnsAllowUpdateForZoneRepositoryInstance.h \
    Linux_DnsAllowUpdateForZoneRepositoryExternal.h \
    Linux_DnsAllowUpdateForZoneManualInstance.h \
    Linux_DnsAllowUpdateForZoneDefaultImplementation.h \
    Linux_DnsAllowUpdateForZoneFactory.h \
    Linux_DnsAllowUpdateForZoneResourceAccess.h \
    CmpiLinux_DnsAllowUpdateForZoneProvider.h
