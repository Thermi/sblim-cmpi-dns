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
    -I${srcdir}/../Linux_DnsService \
    -I${srcdir}/../Linux_DnsMasters

AM_LDFLAGS = \
    -L./../ \
    -L./../../resource-access \
    -L./../CIM_ConcreteJob \
    -L./../Linux_DnsService \
    -L./../Linux_DnsMasters

################################################################################
provider_LTLIBRARIES = libcmpiLinux_DnsMastersForService.la

################################################################################
# Linux_DnsBlackholeACLForService
libcmpiLinux_DnsMastersForService_la_SOURCES = \
    Linux_DnsMastersForServiceInstanceName.cpp \
    Linux_DnsMastersForServiceInstance.cpp \
    Linux_DnsMastersForServiceExternal.cpp \
    Linux_DnsMastersForServiceRepositoryInstance.cpp \
    Linux_DnsMastersForServiceRepositoryExternal.cpp \
    Linux_DnsMastersForServiceManualInstance.cpp \
    Linux_DnsMastersForServiceDefaultImplementation.cpp \
    Linux_DnsMastersForServiceFactory.cpp \
    Linux_DnsMastersForServiceResourceAccess.cpp \
    CmpiLinux_DnsMastersForServiceProvider.cpp

#libcmpiLinux_DnsMastersForService_la_DEPENDENCIES = \
#    libIBM_DnsProviderTooling.la \
#    libLinux_DnsGeneralProviderBasic.la \
#    libcmpiDnsCIM_ConcreteJob.la \
#    libcmpiLinux_DnsService.la \
#    libcmpiLinux_DnsMasters.la

libcmpiLinux_DnsMastersForService_la_LIBADD = \
    -L../../resource-access\
    -lRaToolsDns \
    -lIBM_DnsProviderTooling \
    -lLinux_DnsGeneralProviderBasic \
    -lcmpiDnsCIM_ConcreteJob \
    -lcmpiLinux_DnsService \
    -lcmpiLinux_DnsMasters 

libcmpiLinux_DnsMastersForService_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
    Linux_DnsMastersForServiceInterface.h \
    Linux_DnsMastersForServiceInstanceName.h \
    Linux_DnsMastersForServiceInstance.h \
    Linux_DnsMastersForServiceExternal.h \
    Linux_DnsMastersForServiceRepositoryInstance.h \
    Linux_DnsMastersForServiceRepositoryExternal.h \
    Linux_DnsMastersForServiceManualInstance.h \
    Linux_DnsMastersForServiceDefaultImplementation.h \
    Linux_DnsMastersForServiceFactory.h \
    Linux_DnsMastersForServiceResourceAccess.h \
    CmpiLinux_DnsMastersForServiceProvider.h
