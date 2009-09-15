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
    -I${srcdir}/../Linux_DnsMasters

################################################################################
provider_LTLIBRARIES = libcmpiLinux_DnsMasters.la

################################################################################
# Linux_DnsBlackholeACLForService
libcmpiLinux_DnsMasters_la_SOURCES = \
    Linux_DnsMastersInstanceName.cpp \
    Linux_DnsMastersInstance.cpp \
    Linux_DnsMastersExternal.cpp \
    Linux_DnsMastersRepositoryInstance.cpp \
    Linux_DnsMastersRepositoryExternal.cpp \
    Linux_DnsMastersManualInstance.cpp \
    Linux_DnsMastersDefaultImplementation.cpp \
    Linux_DnsMastersFactory.cpp \
    Linux_DnsMastersResourceAccess.cpp \
    CmpiLinux_DnsMastersProvider.cpp

libcmpiLinux_DnsMasters_la_LIBADD = \
    $(top_builddir)/resource-access/libRaToolsDns.la \
    $(top_builddir)/provider/libIBM_DnsProviderTooling.la \
    $(top_builddir)/provider/libLinux_DnsGeneralProviderBasic.la \
    $(top_builddir)/provider/CIM_ConcreteJob/libcmpiDnsCIM_ConcreteJob.la 

libcmpiLinux_DnsMasters_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
    Linux_DnsMastersInterface.h \
    Linux_DnsMastersInstanceName.h \
    Linux_DnsMastersInstance.h \
    Linux_DnsMastersExternal.h \
    Linux_DnsMastersRepositoryInstance.h \
    Linux_DnsMastersRepositoryExternal.h \
    Linux_DnsMastersManualInstance.h \
    Linux_DnsMastersDefaultImplementation.h \
    Linux_DnsMastersFactory.h \
    Linux_DnsMastersResourceAccess.h \
    CmpiLinux_DnsMastersProvider.h
