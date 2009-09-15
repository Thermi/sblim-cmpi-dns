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
    -I${srcdir}/../Linux_DnsResourceRecord 

################################################################################
provider_LTLIBRARIES = libcmpiLinux_DnsResourceRecord.la

################################################################################
# Linux_DnsResourceRecord
libcmpiLinux_DnsResourceRecord_la_SOURCES = \
    Linux_DnsResourceRecordInstanceName.cpp \
    Linux_DnsResourceRecordInstance.cpp \
    Linux_DnsResourceRecordExternal.cpp \
    Linux_DnsResourceRecordRepositoryInstance.cpp \
    Linux_DnsResourceRecordRepositoryExternal.cpp \
    Linux_DnsResourceRecordManualInstance.cpp \
    Linux_DnsResourceRecordDefaultImplementation.cpp \
    Linux_DnsResourceRecordFactory.cpp \
    Linux_DnsResourceRecordResourceAccess.cpp \
    CmpiLinux_DnsResourceRecordProvider.cpp

libcmpiLinux_DnsResourceRecord_la_LIBADD = \
    $(top_builddir)/resource-access/libRaToolsDns.la \
    $(top_builddir)/provider/libIBM_DnsProviderTooling.la \
    $(top_builddir)/provider/libLinux_DnsGeneralProviderBasic.la \
    $(top_builddir)/provider/CIM_ConcreteJob/libcmpiDnsCIM_ConcreteJob.la

libcmpiLinux_DnsResourceRecord_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
    Linux_DnsResourceRecordInterface.h \
    Linux_DnsResourceRecordInstanceName.h \
    Linux_DnsResourceRecordInstance.h \
    Linux_DnsResourceRecordExternal.h \
    Linux_DnsResourceRecordRepositoryInstance.h \
    Linux_DnsResourceRecordRepositoryExternal.h \
    Linux_DnsResourceRecordManualInstance.h \
    Linux_DnsResourceRecordDefaultImplementation.h \
    Linux_DnsResourceRecordFactory.h \
    Linux_DnsResourceRecordResourceAccess.h \
    CmpiLinux_DnsResourceRecordProvider.h
