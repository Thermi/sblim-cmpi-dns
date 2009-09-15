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
    -I${srcdir}/../Linux_DnsService \
    -I${srcdir}/../Linux_DnsMasters

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

libcmpiLinux_DnsMastersForService_la_LIBADD = \
    $(top_builddir)/resource-access/libRaToolsDns.la \
    $(top_builddir)/provider/libIBM_DnsProviderTooling.la \
    $(top_builddir)/provider/libLinux_DnsGeneralProviderBasic.la \
    $(top_builddir)/provider/CIM_ConcreteJob/libcmpiDnsCIM_ConcreteJob.la \
    $(top_builddir)/provider/Linux_DnsService/libcmpiLinux_DnsService.la \
    $(top_builddir)/provider/Linux_DnsMasters/libcmpiLinux_DnsMasters.la

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
