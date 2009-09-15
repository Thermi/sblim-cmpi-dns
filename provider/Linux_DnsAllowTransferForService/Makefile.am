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
provider_LTLIBRARIES = libcmpiLinux_DnsAllowTransferForService.la

################################################################################
# Linux_DnsLinux_DnsAllowTransferForServiceTransferForService
libcmpiLinux_DnsAllowTransferForService_la_SOURCES = \
    Linux_DnsAllowTransferForServiceInstanceName.cpp \
    Linux_DnsAllowTransferForServiceInstance.cpp \
    Linux_DnsAllowTransferForServiceExternal.cpp \
    Linux_DnsAllowTransferForServiceRepositoryInstance.cpp \
    Linux_DnsAllowTransferForServiceRepositoryExternal.cpp \
    Linux_DnsAllowTransferForServiceManualInstance.cpp \
    Linux_DnsAllowTransferForServiceDefaultImplementation.cpp \
    Linux_DnsAllowTransferForServiceFactory.cpp \
    Linux_DnsAllowTransferForServiceResourceAccess.cpp \
    CmpiLinux_DnsAllowTransferForServiceProvider.cpp

libcmpiLinux_DnsAllowTransferForService_la_LIBADD = \
    $(top_builddir)/resource-access/libRaToolsDns.la \
    $(top_builddir)/provider/libIBM_DnsProviderTooling.la \
    $(top_builddir)/provider/libLinux_DnsGeneralProviderBasic.la \
    $(top_builddir)/provider/CIM_ConcreteJob/libcmpiDnsCIM_ConcreteJob.la \
    $(top_builddir)/provider/Linux_DnsService/libcmpiLinux_DnsService.la \
    $(top_builddir)/provider/Linux_DnsAddressMatchList/libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsAllowTransferForService_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
    Linux_DnsAllowTransferForServiceInterface.h \
    Linux_DnsAllowTransferForServiceInstanceName.h \
    Linux_DnsAllowTransferForServiceInstance.h \
    Linux_DnsAllowTransferForServiceExternal.h \
    Linux_DnsAllowTransferForServiceRepositoryInstance.h \
    Linux_DnsAllowTransferForServiceRepositoryExternal.h \
    Linux_DnsAllowTransferForServiceManualInstance.h \
    Linux_DnsAllowTransferForServiceDefaultImplementation.h \
    Linux_DnsAllowTransferForServiceFactory.h \
    Linux_DnsAllowTransferForServiceResourceAccess.h \
    CmpiLinux_DnsAllowTransferForServiceProvider.h
