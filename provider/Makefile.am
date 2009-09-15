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

AM_CPPFLAGS = \
    -DDEBUG \
    -D_COMPILE_UNIX \
    -DCMPI_STANDALONE \
    -I${srcdir}/include \
    -I$(srcdir)/../resource-access \
    -I$(srcdir)/CIM_ConcreteJob \
    -I$(srcdir)/Linux_DnsAddressMatchList \
    -I$(srcdir)/Linux_DnsForwarders \
    -I$(srcdir)/Linux_DnsForwardZone \
    -I$(srcdir)/Linux_DnsHintZone \
    -I$(srcdir)/Linux_DnsMasters \
    -I$(srcdir)/Linux_DnsMasterZone \
    -I$(srcdir)/Linux_DnsRegisteredProfile \
    -I$(srcdir)/Linux_DnsResourceRecord \
    -I$(srcdir)/Linux_DnsService \
    -I$(srcdir)/Linux_DnsServiceConfiguration \
    -I$(srcdir)/Linux_DnsServiceSettingData \
    -I$(srcdir)/Linux_DnsSlaveZone \
    -I$(srcdir)/Linux_DnsStubZone \
    -I$(srcdir)/Linux_DnsZone

################################################################################
#
lib_LTLIBRARIES += \
    libIBM_DnsProviderTooling.la \
    libLinux_DnsGeneralProviderBasic.la


################################################################################
# General required provider parts
libIBM_DnsProviderTooling_la_SOURCES = \
    support/ArrayConverter.cpp \
    support/CmpiErrorFormater.cpp

noinst_HEADERS += \
    include/ArrayConverter.h \
    include/CmpiErrorFormater.h

libIBM_DnsProviderTooling_la_LIBADD = \
    -L../resource-access\
    -lRaToolsDns



################################################################################
# General Dns required parts
libLinux_DnsGeneralProviderBasic_la_SOURCES = \
    support/smt_dns_array.cpp

sbliminc_HEADERS += \
    include/smt_dns_array.h \
    include/smt_dns_defaultvalues.h \
    include/smt_dns_valuemap.h

libLinux_DnsGeneralProviderBasic_la_LIBADD   = \
    -L../resource-access\
    -lRaToolsDns



################################################################################
# *The* library build config...
SUBDIRS = . \
          CIM_ConcreteJob \
          Linux_DnsZone \
          Linux_DnsAddressMatchList \
          Linux_DnsForwarders \
          Linux_DnsForwardZone \
          Linux_DnsHintZone \
          Linux_DnsMasters \
          Linux_DnsMasterZone \
          Linux_DnsRegisteredProfile \
          Linux_DnsResourceRecord \
          Linux_DnsService \
          Linux_DnsServiceConfiguration \
          Linux_DnsServiceSettingData \
          Linux_DnsSlaveZone \
          Linux_DnsStubZone \
          Linux_DnsAddressMatchListsForService \
          Linux_DnsAllowNotifyForZone \
          Linux_DnsAllowQueryForZone \
          Linux_DnsAllowTransferForZone \
          Linux_DnsAllowUpdateForZone \
          Linux_DnsAllowNotifyForService \
          Linux_DnsAllowQueryForService \
          Linux_DnsAllowRecursionForService \
          Linux_DnsAllowTransferForService \
          Linux_DnsBlackholeForService \
          Linux_DnsForwardersForService \
          Linux_DnsForwardersForZone \
          Linux_DnsMastersForService \
          Linux_DnsMastersForZone \
          Linux_DnsResourceRecordsForZone \
          Linux_DnsServiceConfigurationForService \
          Linux_DnsElementConformsToProfile \
          Linux_DnsServiceSettingDataForServiceConfiguration

