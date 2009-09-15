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
    -I${srcdir}/../Linux_DnsForwarders \
    -I${srcdir}/../Linux_DnsZone

################################################################################
provider_LTLIBRARIES = libcmpiLinux_DnsForwardersForZone.la

################################################################################
# Linux_DnsBlackholeACLForService
libcmpiLinux_DnsForwardersForZone_la_SOURCES = \
    Linux_DnsForwardersForZoneInstanceName.cpp \
    Linux_DnsForwardersForZoneInstance.cpp \
    Linux_DnsForwardersForZoneExternal.cpp \
    Linux_DnsForwardersForZoneRepositoryInstance.cpp \
    Linux_DnsForwardersForZoneRepositoryExternal.cpp \
    Linux_DnsForwardersForZoneManualInstance.cpp \
    Linux_DnsForwardersForZoneDefaultImplementation.cpp \
    Linux_DnsForwardersForZoneFactory.cpp \
    Linux_DnsForwardersForZoneResourceAccess.cpp \
    CmpiLinux_DnsForwardersForZoneProvider.cpp

libcmpiLinux_DnsForwardersForZone_la_LIBADD = \
    $(top_builddir)/resource-access/libRaToolsDns.la \
    $(top_builddir)/provider/libIBM_DnsProviderTooling.la \
    $(top_builddir)/provider/libLinux_DnsGeneralProviderBasic.la \
    $(top_builddir)/provider/CIM_ConcreteJob/libcmpiDnsCIM_ConcreteJob.la \
    $(top_builddir)/provider/Linux_DnsForwarders/libcmpiLinux_DnsForwarders.la \
    $(top_builddir)/provider//Linux_DnsZone/libcmpiLinux_DnsZone.la

libcmpiLinux_DnsForwardersForZone_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
    Linux_DnsForwardersForZoneInterface.h \
    Linux_DnsForwardersForZoneInstanceName.h \
    Linux_DnsForwardersForZoneInstance.h \
    Linux_DnsForwardersForZoneExternal.h \
    Linux_DnsForwardersForZoneRepositoryInstance.h \
    Linux_DnsForwardersForZoneRepositoryExternal.h \
    Linux_DnsForwardersForZoneManualInstance.h \
    Linux_DnsForwardersForZoneDefaultImplementation.h \
    Linux_DnsForwardersForZoneFactory.h \
    Linux_DnsForwardersForZoneResourceAccess.h \
    CmpiLinux_DnsForwardersForZoneProvider.h
