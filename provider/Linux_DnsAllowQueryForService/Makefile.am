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
provider_LTLIBRARIES = libcmpiLinux_DnsAllowQueryForService.la

################################################################################
# Linux_DnsAllowQueryForService
libcmpiLinux_DnsAllowQueryForService_la_SOURCES = \
    Linux_DnsAllowQueryForServiceInstanceName.cpp \
    Linux_DnsAllowQueryForServiceInstance.cpp \
    Linux_DnsAllowQueryForServiceExternal.cpp \
    Linux_DnsAllowQueryForServiceRepositoryInstance.cpp \
    Linux_DnsAllowQueryForServiceRepositoryExternal.cpp \
    Linux_DnsAllowQueryForServiceManualInstance.cpp \
    Linux_DnsAllowQueryForServiceDefaultImplementation.cpp \
    Linux_DnsAllowQueryForServiceFactory.cpp \
    Linux_DnsAllowQueryForServiceResourceAccess.cpp \
    CmpiLinux_DnsAllowQueryForServiceProvider.cpp

#libcmpiLinux_DnsAllowQueryForService_la_DEPENDENCIES = \
#    libIBM_DnsProviderTooling.la \
#    libLinux_DnsGeneralProviderBasic.la \
#    libcmpiDnsCIM_ConcreteJob.la \
#    libcmpiLinux_DnsService.la \
#    libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsAllowQueryForService_la_LIBADD = \
    -L../../resource-access\
    -lRaToolsDns \
    -lIBM_DnsProviderTooling \
    -lLinux_DnsGeneralProviderBasic \
    -lcmpiDnsCIM_ConcreteJob \
    -lcmpiLinux_DnsService \
    -lcmpiLinux_DnsAddressMatchList

libcmpiLinux_DnsAllowQueryForService_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
    Linux_DnsAllowQueryForServiceInterface.h \
    Linux_DnsAllowQueryForServiceInstanceName.h \
    Linux_DnsAllowQueryForServiceInstance.h \
    Linux_DnsAllowQueryForServiceExternal.h \
    Linux_DnsAllowQueryForServiceRepositoryInstance.h \
    Linux_DnsAllowQueryForServiceRepositoryExternal.h \
    Linux_DnsAllowQueryForServiceManualInstance.h \
    Linux_DnsAllowQueryForServiceDefaultImplementation.h \
    Linux_DnsAllowQueryForServiceFactory.h \
    Linux_DnsAllowQueryForServiceResourceAccess.h \
    CmpiLinux_DnsAllowQueryForServiceProvider.h

