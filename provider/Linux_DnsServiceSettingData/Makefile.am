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
    -I${srcdir}/../Linux_DnsServiceSettingData 

################################################################################
provider_LTLIBRARIES = libcmpiLinux_DnsServiceSettingData.la

################################################################################
# Linux_DnsServiceSettingData
libcmpiLinux_DnsServiceSettingData_la_SOURCES = \
    Linux_DnsServiceSettingDataInstanceName.cpp \
    Linux_DnsServiceSettingDataInstance.cpp \
    Linux_DnsServiceSettingDataExternal.cpp \
    Linux_DnsServiceSettingDataRepositoryInstance.cpp \
    Linux_DnsServiceSettingDataRepositoryExternal.cpp \
    Linux_DnsServiceSettingDataManualInstance.cpp \
    Linux_DnsServiceSettingDataDefaultImplementation.cpp \
    Linux_DnsServiceSettingDataFactory.cpp \
    Linux_DnsServiceSettingDataResourceAccess.cpp \
    CmpiLinux_DnsServiceSettingDataProvider.cpp

libcmpiLinux_DnsServiceSettingData_la_LIBADD = \
    $(top_builddir)/resource-access/libRaToolsDns.la \
    $(top_builddir)/provider/libIBM_DnsProviderTooling.la \
    $(top_builddir)/provider/libLinux_DnsGeneralProviderBasic.la \
    $(top_builddir)/provider/CIM_ConcreteJob/libcmpiDnsCIM_ConcreteJob.la

libcmpiLinux_DnsServiceSettingData_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
    Linux_DnsServiceSettingDataInterface.h \
    Linux_DnsServiceSettingDataInstanceName.h \
    Linux_DnsServiceSettingDataInstance.h \
    Linux_DnsServiceSettingDataExternal.h \
    Linux_DnsServiceSettingDataRepositoryInstance.h \
    Linux_DnsServiceSettingDataRepositoryExternal.h \
    Linux_DnsServiceSettingDataManualInstance.h \
    Linux_DnsServiceSettingDataDefaultImplementation.h \
    Linux_DnsServiceSettingDataFactory.h \
    Linux_DnsServiceSettingDataResourceAccess.h \
    CmpiLinux_DnsServiceSettingDataProvider.h
