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
    -I${srcdir}/../Linux_DnsHintZone 

################################################################################
provider_LTLIBRARIES = libcmpiLinux_DnsHintZone.la

################################################################################
# Linux_DnsHintZone
libcmpiLinux_DnsHintZone_la_SOURCES = \
    Linux_DnsHintZoneInstanceName.cpp \
    Linux_DnsHintZoneInstance.cpp \
    Linux_DnsHintZoneExternal.cpp \
    Linux_DnsHintZoneRepositoryInstance.cpp \
    Linux_DnsHintZoneRepositoryExternal.cpp \
    Linux_DnsHintZoneManualInstance.cpp \
    Linux_DnsHintZoneDefaultImplementation.cpp \
    Linux_DnsHintZoneFactory.cpp \
    Linux_DnsHintZoneResourceAccess.cpp \
    CmpiLinux_DnsHintZoneProvider.cpp

libcmpiLinux_DnsHintZone_la_LIBADD = \
    $(top_builddir)/resource-access/libRaToolsDns.la \
    $(top_builddir)/provider/libIBM_DnsProviderTooling.la \
    $(top_builddir)/provider/libLinux_DnsGeneralProviderBasic.la \
    $(top_builddir)/provider/CIM_ConcreteJob/libcmpiDnsCIM_ConcreteJob.la 

libcmpiLinux_DnsHintZone_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
    Linux_DnsHintZoneInterface.h \
    Linux_DnsHintZoneInstanceName.h \
    Linux_DnsHintZoneInstance.h \
    Linux_DnsHintZoneExternal.h \
    Linux_DnsHintZoneRepositoryInstance.h \
    Linux_DnsHintZoneRepositoryExternal.h \
    Linux_DnsHintZoneManualInstance.h \
    Linux_DnsHintZoneDefaultImplementation.h \
    Linux_DnsHintZoneFactory.h \
    Linux_DnsHintZoneResourceAccess.h \
    CmpiLinux_DnsHintZoneProvider.h
