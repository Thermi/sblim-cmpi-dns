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
    -I${srcdir}/../CIM_ConcreteJob 

AM_LDFLAGS = \
    -L./../ \
    -L./../../resource-access \
    -L./../CIM_ConcreteJob 

################################################################################
provider_LTLIBRARIES = libcmpiLinux_DnsService.la

################################################################################
# Linux_DnsService
libcmpiLinux_DnsService_la_SOURCES = \
    Linux_DnsServiceInstanceName.cpp \
    Linux_DnsServiceInstance.cpp \
    Linux_DnsServiceExternal.cpp \
    Linux_DnsServiceRepositoryInstance.cpp \
    Linux_DnsServiceRepositoryExternal.cpp \
    Linux_DnsServiceManualInstance.cpp \
    Linux_DnsServiceDefaultImplementation.cpp \
    Linux_DnsServiceFactory.cpp \
    Linux_DnsServiceResourceAccess.cpp \
    CmpiLinux_DnsServiceProvider.cpp

#libcmpiLinux_DnsService_la_DEPENDENCIES = \
#    libIBM_DnsProviderTooling.la \
#    libLinux_DnsGeneralProviderBasic.la \
#    libcmpiDnsCIM_ConcreteJob.la 

libcmpiLinux_DnsService_la_LIBADD = \
    -L../../resource-access\
    -lRaToolsDns \
    -lIBM_DnsProviderTooling \
    -lLinux_DnsGeneralProviderBasic \
    -lcmpiDnsCIM_ConcreteJob 

libcmpiLinux_DnsService_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
    Linux_DnsServiceInterface.h \
    Linux_DnsServiceInstanceName.h \
    Linux_DnsServiceInstance.h \
    Linux_DnsServiceExternal.h \
    Linux_DnsServiceRepositoryInstance.h \
    Linux_DnsServiceRepositoryExternal.h \
    Linux_DnsServiceManualInstance.h \
    Linux_DnsServiceDefaultImplementation.h \
    Linux_DnsServiceFactory.h \
    Linux_DnsServiceResourceAccess.h \
    CmpiLinux_DnsServiceProvider.h
