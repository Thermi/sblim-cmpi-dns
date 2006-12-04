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
    -I${srcdir}/../Linux_DnsService 

AM_LDFLAGS = \
    -L./../ \
    -L./../../resource-access \
    -L./../CIM_ConcreteJob \
    -L./../Linux_DnsAddressMatchList \
    -L./../Linux_DnsService 

################################################################################
provider_LTLIBRARIES = libcmpiLinux_DnsAddressMatchListsForService.la

################################################################################
# DnsAddressMatchListsForService
libcmpiLinux_DnsAddressMatchListsForService_la_SOURCES = \
    Linux_DnsAddressMatchListsForServiceInstanceName.cpp \
    Linux_DnsAddressMatchListsForServiceInstance.cpp \
    Linux_DnsAddressMatchListsForServiceExternal.cpp \
    Linux_DnsAddressMatchListsForServiceRepositoryInstance.cpp \
    Linux_DnsAddressMatchListsForServiceRepositoryExternal.cpp \
    Linux_DnsAddressMatchListsForServiceManualInstance.cpp \
    Linux_DnsAddressMatchListsForServiceDefaultImplementation.cpp \
    Linux_DnsAddressMatchListsForServiceFactory.cpp \
    Linux_DnsAddressMatchListsForServiceResourceAccess.cpp \
    CmpiLinux_DnsAddressMatchListsForServiceProvider.cpp

#libcmpiLinux_DnsAddressMatchListsForService_la_DEPENDENCIES = \
#    libIBM_DnsProviderTooling.la \
#    libLinux_DnsGeneralProviderBasic.la \
#    libcmpiDnsCIM_ConcreteJob.la \
#    libcmpiLinux_DnsService.la \
#    libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsAddressMatchListsForService_la_LIBADD = \
    -L../../resource-access\
    -lRaToolsDns \
    -lIBM_DnsProviderTooling \
    -lLinux_DnsGeneralProviderBasic \
    -lcmpiDnsCIM_ConcreteJob \
    -lcmpiLinux_DnsService \
    -lcmpiLinux_DnsAddressMatchList

libcmpiLinux_DnsAddressMatchListsForService_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
    Linux_DnsAddressMatchListsForServiceInterface.h \
    Linux_DnsAddressMatchListsForServiceInstanceName.h \
    Linux_DnsAddressMatchListsForServiceInstance.h \
    Linux_DnsAddressMatchListsForServiceExternal.h \
    Linux_DnsAddressMatchListsForServiceRepositoryInstance.h \
    Linux_DnsAddressMatchListsForServiceRepositoryExternal.h \
    Linux_DnsAddressMatchListsForServiceManualInstance.h \
    Linux_DnsAddressMatchListsForServiceDefaultImplementation.h \
    Linux_DnsAddressMatchListsForServiceFactory.h \
    Linux_DnsAddressMatchListsForServiceResourceAccess.h \
    CmpiLinux_DnsAddressMatchListsForServiceProvider.h

