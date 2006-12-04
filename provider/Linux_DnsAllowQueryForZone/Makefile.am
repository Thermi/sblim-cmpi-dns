# ==================================================================
# (C) Copyright IBM Corp. 2005
#
# THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
# ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
# CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
#
# You can obtain a current copy of the Common Public License from
# http://www.opensource.org/licenses/cpl1.0.php
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

AM_LDFLAGS = \
    -L./../ \
    -L./../../resource-access \
    -L./../CIM_ConcreteJob \
    -L./../Linux_DnsAddressMatchList \
    -L./../Linux_DnsZone

################################################################################
provider_LTLIBRARIES = libcmpiLinux_DnsAllowQueryForZone.la

################################################################################
# Linux_DnsAllowQueryForZone
libcmpiLinux_DnsAllowQueryForZone_la_SOURCES = \
    Linux_DnsAllowQueryForZoneInstanceName.cpp \
    Linux_DnsAllowQueryForZoneInstance.cpp \
    Linux_DnsAllowQueryForZoneExternal.cpp \
    Linux_DnsAllowQueryForZoneRepositoryInstance.cpp \
    Linux_DnsAllowQueryForZoneRepositoryExternal.cpp \
    Linux_DnsAllowQueryForZoneManualInstance.cpp \
    Linux_DnsAllowQueryForZoneDefaultImplementation.cpp \
    Linux_DnsAllowQueryForZoneFactory.cpp \
    Linux_DnsAllowQueryForZoneResourceAccess.cpp \
    CmpiLinux_DnsAllowQueryForZoneProvider.cpp

#libcmpiLinux_DnsAllowQueryForZone_la_DEPENDENCIES = \
#    libIBM_DnsProviderTooling.la \
#    libLinux_DnsGeneralProviderBasic.la \
#    libcmpiDnsCIM_ConcreteJob.la \
#    libcmpiLinux_DnsZone.la \
#    libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsAllowQueryForZone_la_LIBADD = \
    -L../../resource-access\
    -lRaToolsDns \
    -lIBM_DnsProviderTooling \
    -lLinux_DnsGeneralProviderBasic \
    -lcmpiDnsCIM_ConcreteJob \
    -lcmpiLinux_DnsZone \
    -lcmpiLinux_DnsAddressMatchList


libcmpiLinux_DnsAllowQueryForZone_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
    Linux_DnsAllowQueryForZoneInterface.h \
    Linux_DnsAllowQueryForZoneInstanceName.h \
    Linux_DnsAllowQueryForZoneInstance.h \
    Linux_DnsAllowQueryForZoneExternal.h \
    Linux_DnsAllowQueryForZoneRepositoryInstance.h \
    Linux_DnsAllowQueryForZoneRepositoryExternal.h \
    Linux_DnsAllowQueryForZoneManualInstance.h \
    Linux_DnsAllowQueryForZoneDefaultImplementation.h \
    Linux_DnsAllowQueryForZoneFactory.h \
    Linux_DnsAllowQueryForZoneResourceAccess.h \
    CmpiLinux_DnsAllowQueryForZoneProvider.h

