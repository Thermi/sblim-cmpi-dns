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
    -I${srcdir}/../Linux_DnsServiceConfiguration \
    -I${srcdir}/../Linux_DnsService 

AM_LDFLAGS = \
    -L./../ \
    -L./../../resource-access \
    -L./../CIM_ConcreteJob \
    -L./../Linux_DnsServiceConfiguration \
    -L./../Linux_DnsService 

################################################################################
provider_LTLIBRARIES = libcmpiLinux_DnsServiceConfigurationForService.la

################################################################################
# Linux_DnsServiceConfigurationForService
libcmpiLinux_DnsServiceConfigurationForService_la_SOURCES = \
    Linux_DnsServiceConfigurationForServiceInstanceName.cpp \
    Linux_DnsServiceConfigurationForServiceInstance.cpp \
    Linux_DnsServiceConfigurationForServiceExternal.cpp \
    Linux_DnsServiceConfigurationForServiceRepositoryInstance.cpp \
    Linux_DnsServiceConfigurationForServiceRepositoryExternal.cpp \
    Linux_DnsServiceConfigurationForServiceManualInstance.cpp \
    Linux_DnsServiceConfigurationForServiceDefaultImplementation.cpp \
    Linux_DnsServiceConfigurationForServiceFactory.cpp \
    Linux_DnsServiceConfigurationForServiceResourceAccess.cpp \
    CmpiLinux_DnsServiceConfigurationForServiceProvider.cpp

#libcmpiLinux_DnsServiceConfigurationForService_la_DEPENDENCIES = \
#    libIBM_DnsProviderTooling.la \
#    libLinux_DnsGeneralProviderBasic.la \
#    libcmpiDnsCIM_ConcreteJob.la \
#    libcmpiLinux_DnsService.la \
#    libcmpiLinux_DnsServiceConfiguration.la

libcmpiLinux_DnsServiceConfigurationForService_la_LIBADD = \
    -L../../resource-access\
    -lRaToolsDns \
    -lIBM_DnsProviderTooling \
    -lLinux_DnsGeneralProviderBasic \
    -lcmpiDnsCIM_ConcreteJob \
    -lcmpiLinux_DnsService \
    -lcmpiLinux_DnsServiceConfiguration

libcmpiLinux_DnsServiceConfigurationForService_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
    Linux_DnsServiceConfigurationForServiceInterface.h \
    Linux_DnsServiceConfigurationForServiceInstanceName.h \
    Linux_DnsServiceConfigurationForServiceInstance.h \
    Linux_DnsServiceConfigurationForServiceExternal.h \
    Linux_DnsServiceConfigurationForServiceRepositoryInstance.h \
    Linux_DnsServiceConfigurationForServiceRepositoryExternal.h \
    Linux_DnsServiceConfigurationForServiceManualInstance.h \
    Linux_DnsServiceConfigurationForServiceDefaultImplementation.h \
    Linux_DnsServiceConfigurationForServiceFactory.h \
    Linux_DnsServiceConfigurationForServiceResourceAccess.h \
    CmpiLinux_DnsServiceConfigurationForServiceProvider.h

