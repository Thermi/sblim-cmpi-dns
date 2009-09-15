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
    -I${srcdir}/../CIM_ConcreteJob 

################################################################################
provider_LTLIBRARIES = libcmpiLinux_DnsAddressMatchList.la

################################################################################
# DnsAddressMatchList
libcmpiLinux_DnsAddressMatchList_la_SOURCES = \
    Linux_DnsAddressMatchListInstanceName.cpp \
    Linux_DnsAddressMatchListInstance.cpp \
    Linux_DnsAddressMatchListExternal.cpp \
    Linux_DnsAddressMatchListRepositoryInstance.cpp \
    Linux_DnsAddressMatchListRepositoryExternal.cpp \
    Linux_DnsAddressMatchListManualInstance.cpp \
    Linux_DnsAddressMatchListDefaultImplementation.cpp \
    Linux_DnsAddressMatchListFactory.cpp \
    Linux_DnsAddressMatchListResourceAccess.cpp \
    CmpiLinux_DnsAddressMatchListProvider.cpp

libcmpiLinux_DnsAddressMatchList_la_LIBADD = \
    $(top_builddir)/resource-access/libRaToolsDns.la \
    $(top_builddir)/provider/libIBM_DnsProviderTooling.la \
    $(top_builddir)/provider/libLinux_DnsGeneralProviderBasic.la \
    $(top_builddir)/provider/CIM_ConcreteJob/libcmpiDnsCIM_ConcreteJob.la 

libcmpiLinux_DnsAddressMatchList_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
    Linux_DnsAddressMatchListInterface.h \
    Linux_DnsAddressMatchListInstanceName.h \
    Linux_DnsAddressMatchListInstance.h \
    Linux_DnsAddressMatchListExternal.h \
    Linux_DnsAddressMatchListRepositoryInstance.h \
    Linux_DnsAddressMatchListRepositoryExternal.h \
    Linux_DnsAddressMatchListManualInstance.h \
    Linux_DnsAddressMatchListDefaultImplementation.h \
    Linux_DnsAddressMatchListFactory.h \
    Linux_DnsAddressMatchListResourceAccess.h \
    CmpiLinux_DnsAddressMatchListProvider.h
