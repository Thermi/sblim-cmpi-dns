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
    -I${srcdir}/../Linux_DnsService 

################################################################################
provider_LTLIBRARIES = libcmpiLinux_DnsBlackholeForService.la

################################################################################
# Linux_DnsBlackholeACLForService
libcmpiLinux_DnsBlackholeForService_la_SOURCES = \
    Linux_DnsBlackholeForServiceInstanceName.cpp \
    Linux_DnsBlackholeForServiceInstance.cpp \
    Linux_DnsBlackholeForServiceExternal.cpp \
    Linux_DnsBlackholeForServiceRepositoryInstance.cpp \
    Linux_DnsBlackholeForServiceRepositoryExternal.cpp \
    Linux_DnsBlackholeForServiceManualInstance.cpp \
    Linux_DnsBlackholeForServiceDefaultImplementation.cpp \
    Linux_DnsBlackholeForServiceFactory.cpp \
    Linux_DnsBlackholeForServiceResourceAccess.cpp \
    CmpiLinux_DnsBlackholeForServiceProvider.cpp

libcmpiLinux_DnsBlackholeForService_la_LIBADD = \
    $(top_builddir)/resource-access/libRaToolsDns.la \
    $(top_builddir)/provider/libIBM_DnsProviderTooling.la \
    $(top_builddir)/provider/libLinux_DnsGeneralProviderBasic.la \
    $(top_builddir)/provider/CIM_ConcreteJob/libcmpiDnsCIM_ConcreteJob.la \
    $(top_builddir)/provider/Linux_DnsService/libcmpiLinux_DnsService.la \
    $(top_builddir)/provider/Linux_DnsAddressMatchList/libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsBlackholeForService_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
    Linux_DnsBlackholeForServiceInterface.h \
    Linux_DnsBlackholeForServiceInstanceName.h \
    Linux_DnsBlackholeForServiceInstance.h \
    Linux_DnsBlackholeForServiceExternal.h \
    Linux_DnsBlackholeForServiceRepositoryInstance.h \
    Linux_DnsBlackholeForServiceRepositoryExternal.h \
    Linux_DnsBlackholeForServiceManualInstance.h \
    Linux_DnsBlackholeForServiceDefaultImplementation.h \
    Linux_DnsBlackholeForServiceFactory.h \
    Linux_DnsBlackholeForServiceResourceAccess.h \
    CmpiLinux_DnsBlackholeForServiceProvider.h
