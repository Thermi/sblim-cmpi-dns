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
    -I${srcdir}/../Linux_DnsMasters \
    -I${srcdir}/../Linux_DnsZone 

################################################################################
provider_LTLIBRARIES = libcmpiLinux_DnsMastersForZone.la

################################################################################
# Linux_DnsBlackholeACLForService
libcmpiLinux_DnsMastersForZone_la_SOURCES = \
    Linux_DnsMastersForZoneInstanceName.cpp \
    Linux_DnsMastersForZoneInstance.cpp \
    Linux_DnsMastersForZoneExternal.cpp \
    Linux_DnsMastersForZoneRepositoryInstance.cpp \
    Linux_DnsMastersForZoneRepositoryExternal.cpp \
    Linux_DnsMastersForZoneManualInstance.cpp \
    Linux_DnsMastersForZoneDefaultImplementation.cpp \
    Linux_DnsMastersForZoneFactory.cpp \
    Linux_DnsMastersForZoneResourceAccess.cpp \
    CmpiLinux_DnsMastersForZoneProvider.cpp

libcmpiLinux_DnsMastersForZone_la_LIBADD = \
    $(top_builddir)/resource-access/libRaToolsDns.la \
    $(top_builddir)/provider/libIBM_DnsProviderTooling.la \
    $(top_builddir)/provider/libLinux_DnsGeneralProviderBasic.la \
    $(top_builddir)/provider/CIM_ConcreteJob/libcmpiDnsCIM_ConcreteJob.la \
    $(top_builddir)/provider/Linux_DnsMasters/libcmpiLinux_DnsMasters.la \
    $(top_builddir)/provider/Linux_DnsZone/libcmpiLinux_DnsZone.la

libcmpiLinux_DnsMastersForZone_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
    Linux_DnsMastersForZoneInterface.h \
    Linux_DnsMastersForZoneInstanceName.h \
    Linux_DnsMastersForZoneInstance.h \
    Linux_DnsMastersForZoneExternal.h \
    Linux_DnsMastersForZoneRepositoryInstance.h \
    Linux_DnsMastersForZoneRepositoryExternal.h \
    Linux_DnsMastersForZoneManualInstance.h \
    Linux_DnsMastersForZoneDefaultImplementation.h \
    Linux_DnsMastersForZoneFactory.h \
    Linux_DnsMastersForZoneResourceAccess.h \
    CmpiLinux_DnsMastersForZoneProvider.h
