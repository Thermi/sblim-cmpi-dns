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
    -I${srcdir}/../Linux_DnsServiceSettingData

AM_LDFLAGS = \
    -L./../ \
    -L./../../resource-access \
    -L./../CIM_ConcreteJob \
    -L./../Linux_DnsServiceConfiguration \
    -L./../Linux_DnsServiceSettingData

################################################################################
provider_LTLIBRARIES = libcmpiLinux_DnsServiceSettingDataForServiceConfiguration.la

################################################################################
# Linux_DnsServiceSettingDataForServiceConfiguration
libcmpiLinux_DnsServiceSettingDataForServiceConfiguration_la_SOURCES = \
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceName.cpp \
    Linux_DnsServiceSettingDataForServiceConfigurationInstance.cpp \
    Linux_DnsServiceSettingDataForServiceConfigurationExternal.cpp \
    Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance.cpp \
    Linux_DnsServiceSettingDataForServiceConfigurationRepositoryExternal.cpp \
    Linux_DnsServiceSettingDataForServiceConfigurationManualInstance.cpp \
    Linux_DnsServiceSettingDataForServiceConfigurationDefaultImplementation.cpp \
    Linux_DnsServiceSettingDataForServiceConfigurationFactory.cpp \
    Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess.cpp \
    CmpiLinux_DnsServiceSettingDataForServiceConfigurationProvider.cpp

#libcmpiLinux_DnsServiceSettingDataForServiceConfiguration_la_DEPENDENCIES = \
#    libIBM_DnsProviderTooling.la \
#    libLinux_DnsGeneralProviderBasic.la \
#    libcmpiDnsCIM_ConcreteJob.la \
#    libcmpiLinux_DnsServiceSettingData.la \
#    libcmpiLinux_DnsServiceConfiguration.la

libcmpiLinux_DnsServiceSettingDataForServiceConfiguration_la_LIBADD = \
    -L../../resource-access\
    -lRaToolsDns \
    -lIBM_DnsProviderTooling \
    -lLinux_DnsGeneralProviderBasic \
    -lcmpiDnsCIM_ConcreteJob \
    -lcmpiLinux_DnsServiceSettingData \
    -lcmpiLinux_DnsServiceConfiguration

libcmpiLinux_DnsServiceSettingDataForServiceConfiguration_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
     Linux_DnsServiceSettingDataForServiceConfigurationInterface.h \
     Linux_DnsServiceSettingDataForServiceConfigurationInstanceName.h \
     Linux_DnsServiceSettingDataForServiceConfigurationInstance.h \
     Linux_DnsServiceSettingDataForServiceConfigurationExternal.h \
     Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance.h \
     Linux_DnsServiceSettingDataForServiceConfigurationRepositoryExternal.h \
     Linux_DnsServiceSettingDataForServiceConfigurationManualInstance.h \
     Linux_DnsServiceSettingDataForServiceConfigurationDefaultImplementation.h \
     Linux_DnsServiceSettingDataForServiceConfigurationFactory.h \
     Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess.h \
     CmpiLinux_DnsServiceSettingDataForServiceConfigurationProvider.h
