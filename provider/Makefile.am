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

AM_FLAGS = -Wall

AM_CPPFLAGS = \
	-D_COMPILE_UNIX \
	-DCMPI_STANDALONE \
	-I$(srcdir)/include \
	-I$(srcdir)/../resource-access \
	-I$(srcdir)/CIM_CollectionOfMSEs \
        -I$(srcdir)/CIM_ConcreteJob \
        -I$(srcdir)/CIM_ManagedSystemElement \
        -I$(srcdir)/Linux_DnsAddressMatchList \
	-I$(srcdir)/Linux_DnsIPAddress \
	-I$(srcdir)/Linux_DnsConfiguration \
	-I$(srcdir)/Linux_DnsService \
	-I$(srcdir)/Linux_DnsSetting \
	-I$(srcdir)/Linux_DnsSlaveZone \
	-I$(srcdir)/Linux_DnsResourceRecord \
	-I$(srcdir)/Linux_DnsZone 

################################################################################
#
lib_LTLIBRARIES += \
	libIBM_DnsProviderTooling.la \
	libLinux_DnsGeneralProviderBasic.la 


################################################################################
# General required provider parts
libIBM_DnsProviderTooling_la_SOURCES = \
	$(srcdir)/support/ArrayConverter.cpp \
	$(srcdir)/support/CmpiErrorFormater.cpp

noinst_HEADERS+= \
	$(srcdir)/include/ArrayConverter.h \
	$(srcdir)/include/CmpiErrorFormater.h 

libIBM_DnsProviderTooling_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns


################################################################################
# General Dns required parts
libLinux_DnsGeneralProviderBasic_la_SOURCES = \
	$(srcdir)/include/smt_dns_defaultvalues.h \
	$(srcdir)/support/smt_dns_array.cpp 

sbliminc_HEADERS+= \
	$(srcdir)/include/smt_dns_array.h \
	$(srcdir)/include/smt_dns_defaultvalues.h \
	$(srcdir)/include/smt_dns_valuemap.h

libLinux_DnsGeneralProviderBasic_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns
        

################################################################################
# *The* library build config...
provider_LTLIBRARIES = \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsService.la \
	libcmpiLinux_DnsAddressMatchList.la \
	libcmpiLinux_DnsAddressMatchListOfService.la \
	libcmpiLinux_DnsZone.la \
	libcmpiLinux_DnsAllowNotifyACLForZone.la \
	libcmpiLinux_DnsAllowQueryACLForZone.la \
	libcmpiLinux_DnsAllowTransferACLForZone.la \
	libcmpiLinux_DnsAllowUpdateACLForZone.la \
	libcmpiLinux_DnsBlackholeACLForService.la \
	libcmpiLinux_DnsBlackholeACLForZone.la \
	libcmpiLinux_DnsConfiguration.la \
	libcmpiLinux_DnsSetting.la \
	libcmpiLinux_DnsSettingContext.la \
	libcmpiLinux_DnsElementSetting.la \
	libcmpiLinux_DnsForwardZone.la \
	libcmpiLinux_DnsHintZone.la \
	libcmpiLinux_DnsIPAddress.la \
	libcmpiLinux_DnsManagedSystemElementForSetting.la \
	libcmpiLinux_DnsSlaveZone.la \
	libcmpiLinux_DnsMastersOfSlaveZone.la \
	libcmpiLinux_DnsMasterZone.la \
	libcmpiLinux_DnsNotifyACLForService.la \
	libcmpiLinux_DnsQueryACLForService.la \
	libcmpiLinux_DnsRecursionACLForService.la \
	libcmpiLinux_DnsResourceRecord.la \
	libcmpiLinux_DnsResourceRecordInZone.la \
	libcmpiLinux_DnsServiceConfiguration.la \
	libcmpiLinux_DnsTransferACLForService.la 


################################################################################
# CIM_CollectionOfMSEs
libcmpiDnsCIM_CollectionOfMSEs_la_SOURCES = \
	$(srcdir)/CIM_CollectionOfMSEs/CIM_CollectionOfMSEsExternal.cpp \
	$(srcdir)/CIM_CollectionOfMSEs/CIM_CollectionOfMSEsInstance.cpp \
	$(srcdir)/CIM_CollectionOfMSEs/CIM_CollectionOfMSEsInstanceName.cpp 

libcmpiDnsCIM_CollectionOfMSEs_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
	libLinux_DnsGeneralProviderBasic.la

libcmpiDnsCIM_CollectionOfMSEs_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic
        
libcmpiDnsCIM_CollectionOfMSEs_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
	$(srcdir)/CIM_CollectionOfMSEs/CIM_CollectionOfMSEsExternal.h \
	$(srcdir)/CIM_CollectionOfMSEs/CIM_CollectionOfMSEsInstance.h \
	$(srcdir)/CIM_CollectionOfMSEs/CIM_CollectionOfMSEsInstanceName.h 



################################################################################
# CIM_ConcreteJob
libcmpiDnsCIM_ConcreteJob_la_SOURCES = \
	$(srcdir)/CIM_ConcreteJob/CIM_ConcreteJobExternal.cpp \
	$(srcdir)/CIM_ConcreteJob/CIM_ConcreteJobInstance.cpp \
	$(srcdir)/CIM_ConcreteJob/CIM_ConcreteJobInstanceName.cpp 

libcmpiDnsCIM_ConcreteJob_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la

libcmpiDnsCIM_ConcreteJob_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic
        
libcmpiDnsCIM_ConcreteJob_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
	$(srcdir)/CIM_ConcreteJob/CIM_ConcreteJobExternal.h \
	$(srcdir)/CIM_ConcreteJob/CIM_ConcreteJobInstance.h \
	$(srcdir)/CIM_ConcreteJob/CIM_ConcreteJobInstanceName.h 



################################################################################
# CIM_ManagedSystemElement
libcmpiDnsCIM_ManagedSystemElement_la_SOURCES = \
	$(srcdir)/CIM_ManagedSystemElement/CIM_ManagedSystemElementExternal.cpp \
	$(srcdir)/CIM_ManagedSystemElement/CIM_ManagedSystemElementInstance.cpp \
	$(srcdir)/CIM_ManagedSystemElement/CIM_ManagedSystemElementInstanceName.cpp 

libcmpiDnsCIM_ManagedSystemElement_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la

libcmpiDnsCIM_ManagedSystemElement_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic
        
libcmpiDnsCIM_ManagedSystemElement_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
	$(srcdir)/CIM_ManagedSystemElement/CIM_ManagedSystemElementExternal.h \
	$(srcdir)/CIM_ManagedSystemElement/CIM_ManagedSystemElementInstance.h \
	$(srcdir)/CIM_ManagedSystemElement/CIM_ManagedSystemElementInstanceName.h



################################################################################
# DnsAddressMatchList
libcmpiLinux_DnsAddressMatchList_la_SOURCES = \
	$(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListInstanceName.cpp \
        $(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListInstance.cpp \
        $(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListExternal.cpp \
        $(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListManualInstance.cpp \
        $(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListFactory.cpp \
	$(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListResourceAccess.cpp \
	$(srcdir)/Linux_DnsAddressMatchList/CmpiLinux_DnsAddressMatchListProvider.cpp 

libcmpiLinux_DnsAddressMatchList_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la

libcmpiLinux_DnsAddressMatchList_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement
                                               
libcmpiLinux_DnsAddressMatchList_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
	$(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListInterface.h \
	$(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListInstanceName.h \
        $(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListInstance.h \
        $(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListExternal.h \
        $(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListRepositoryInstance.h \
        $(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListRepositoryExternal.h \
        $(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListManualInstance.h \
        $(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListDefaultImplementation.h \
	$(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListFactory.h \
	$(srcdir)/Linux_DnsAddressMatchList/Linux_DnsAddressMatchListResourceAccess.h \
	$(srcdir)/Linux_DnsAddressMatchList/CmpiLinux_DnsAddressMatchListProvider.h 



################################################################################
# DnsAddressMatchListOfService
libcmpiLinux_DnsAddressMatchListOfService_la_SOURCES = \
	$(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceInstanceName.cpp \
        $(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceInstance.cpp \
        $(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceExternal.cpp \
        $(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceManualInstance.cpp \
        $(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceFactory.cpp \
	$(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceResourceAccess.cpp \
	$(srcdir)/Linux_DnsAddressMatchListOfService/CmpiLinux_DnsAddressMatchListOfServiceProvider.cpp

libcmpiLinux_DnsAddressMatchListOfService_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsService.la \
	libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsAddressMatchListOfService_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement \
        -lcmpiLinux_DnsService \
        -lcmpiLinux_DnsAddressMatchList
        
libcmpiLinux_DnsAddressMatchListOfService_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceInterface.h \
	$(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceInstanceName.h \
        $(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceInstance.h \
        $(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceExternal.h \
        $(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceRepositoryInstance.h \
        $(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceRepositoryExternal.h \
        $(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceManualInstance.h \
        $(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceDefaultImplementation.h \
	$(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceFactory.h \
	$(srcdir)/Linux_DnsAddressMatchListOfService/Linux_DnsAddressMatchListOfServiceResourceAccess.h \
	$(srcdir)/Linux_DnsAddressMatchListOfService/CmpiLinux_DnsAddressMatchListOfServiceProvider.h



################################################################################
# Linux_DnsAllowNotifyACLForZone
libcmpiLinux_DnsAllowNotifyACLForZone_la_SOURCES = \
	$(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneInstanceName.cpp \
        $(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneInstance.cpp \
        $(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneExternal.cpp \
        $(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneManualInstance.cpp \
        $(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneFactory.cpp \
	$(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneResourceAccess.cpp \
	$(srcdir)/Linux_DnsAllowNotifyACLForZone/CmpiLinux_DnsAllowNotifyACLForZoneProvider.cpp

libcmpiLinux_DnsAllowNotifyACLForZone_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsZone.la \
	libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsAllowNotifyACLForZone_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement \
        -lcmpiLinux_DnsZone \
        -lcmpiLinux_DnsAddressMatchList
        
libcmpiLinux_DnsAllowNotifyACLForZone_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneInterface.h \
	$(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneInstanceName.h \
        $(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneInstance.h \
        $(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneExternal.h \
        $(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneRepositoryInstance.h \
        $(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneRepositoryExternal.h \
        $(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneManualInstance.h \
        $(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneDefaultImplementation.h \
	$(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneFactory.h \
	$(srcdir)/Linux_DnsAllowNotifyACLForZone/Linux_DnsAllowNotifyACLForZoneResourceAccess.h \
	$(srcdir)/Linux_DnsAllowNotifyACLForZone/CmpiLinux_DnsAllowNotifyACLForZoneProvider.h



################################################################################
# Linux_DnsAllowQueryACLForZone
libcmpiLinux_DnsAllowQueryACLForZone_la_SOURCES = \
	$(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneInstanceName.cpp \
        $(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneInstance.cpp \
        $(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneExternal.cpp \
        $(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneManualInstance.cpp \
        $(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneFactory.cpp \
	$(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneResourceAccess.cpp \
	$(srcdir)/Linux_DnsAllowQueryACLForZone/CmpiLinux_DnsAllowQueryACLForZoneProvider.cpp

libcmpiLinux_DnsAllowQueryACLForZone_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsZone.la \
	libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsAllowQueryACLForZone_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement \
        -lcmpiLinux_DnsZone \
        -lcmpiLinux_DnsAddressMatchList
        
        
libcmpiLinux_DnsAllowQueryACLForZone_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneInterface.h \
	$(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneInstanceName.h \
        $(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneInstance.h \
        $(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneExternal.h \
        $(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneRepositoryInstance.h \
        $(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneRepositoryExternal.h \
        $(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneManualInstance.h \
        $(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneDefaultImplementation.h \
	$(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneFactory.h \
	$(srcdir)/Linux_DnsAllowQueryACLForZone/Linux_DnsAllowQueryACLForZoneResourceAccess.h \
	$(srcdir)/Linux_DnsAllowQueryACLForZone/CmpiLinux_DnsAllowQueryACLForZoneProvider.h



################################################################################
# Linux_DnsAllowTransferACLForZone
libcmpiLinux_DnsAllowTransferACLForZone_la_SOURCES = \
	$(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneInstanceName.cpp \
        $(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneInstance.cpp \
        $(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneExternal.cpp \
        $(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneManualInstance.cpp \
        $(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneFactory.cpp \
	$(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneResourceAccess.cpp \
	$(srcdir)/Linux_DnsAllowTransferACLForZone/CmpiLinux_DnsAllowTransferACLForZoneProvider.cpp

libcmpiLinux_DnsAllowTransferACLForZone_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsZone.la \
	libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsAllowTransferACLForZone_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement \
        -lcmpiLinux_DnsZone \
        -lcmpiLinux_DnsAddressMatchList

libcmpiLinux_DnsAllowTransferACLForZone_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneInterface.h \
	$(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneInstanceName.h \
        $(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneInstance.h \
        $(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneExternal.h \
        $(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneRepositoryInstance.h \
        $(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneRepositoryExternal.h \
        $(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneManualInstance.h \
        $(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneDefaultImplementation.h \
	$(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneFactory.h \
	$(srcdir)/Linux_DnsAllowTransferACLForZone/Linux_DnsAllowTransferACLForZoneResourceAccess.h \
	$(srcdir)/Linux_DnsAllowTransferACLForZone/CmpiLinux_DnsAllowTransferACLForZoneProvider.h



################################################################################
# Linux_DnsAllowUpdateACLForZone
libcmpiLinux_DnsAllowUpdateACLForZone_la_SOURCES = \
	$(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneInstanceName.cpp \
        $(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneInstance.cpp \
        $(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneExternal.cpp \
        $(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneManualInstance.cpp \
        $(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneFactory.cpp \
	$(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneResourceAccess.cpp \
	$(srcdir)/Linux_DnsAllowUpdateACLForZone/CmpiLinux_DnsAllowUpdateACLForZoneProvider.cpp

libcmpiLinux_DnsAllowUpdateACLForZone_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsZone.la \
	libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsAllowUpdateACLForZone_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement \
        -lcmpiLinux_DnsZone \
        -lcmpiLinux_DnsAddressMatchList
        
libcmpiLinux_DnsAllowUpdateACLForZone_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneInterface.h \
	$(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneInstanceName.h \
        $(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneInstance.h \
        $(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneExternal.h \
        $(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneRepositoryInstance.h \
        $(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneRepositoryExternal.h \
        $(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneManualInstance.h \
        $(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneDefaultImplementation.h \
	$(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneFactory.h \
	$(srcdir)/Linux_DnsAllowUpdateACLForZone/Linux_DnsAllowUpdateACLForZoneResourceAccess.h \
	$(srcdir)/Linux_DnsAllowUpdateACLForZone/CmpiLinux_DnsAllowUpdateACLForZoneProvider.h



################################################################################
# Linux_DnsBlackholeACLForService
libcmpiLinux_DnsBlackholeACLForService_la_SOURCES = \
	$(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceInstanceName.cpp \
        $(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceInstance.cpp \
        $(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceExternal.cpp \
        $(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceManualInstance.cpp \
        $(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceFactory.cpp \
	$(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceResourceAccess.cpp \
	$(srcdir)/Linux_DnsBlackholeACLForService/CmpiLinux_DnsBlackholeACLForServiceProvider.cpp

libcmpiLinux_DnsBlackholeACLForService_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsService.la \
	libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsBlackholeACLForService_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement \
        -lcmpiLinux_DnsService \
        -lcmpiLinux_DnsAddressMatchList
        
libcmpiLinux_DnsBlackholeACLForService_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceInterface.h \
	$(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceInstanceName.h \
        $(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceInstance.h \
        $(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceExternal.h \
        $(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceRepositoryInstance.h \
        $(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceRepositoryExternal.h \
        $(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceManualInstance.h \
        $(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceDefaultImplementation.h \
	$(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceFactory.h \
	$(srcdir)/Linux_DnsBlackholeACLForService/Linux_DnsBlackholeACLForServiceResourceAccess.h \
	$(srcdir)/Linux_DnsBlackholeACLForService/CmpiLinux_DnsBlackholeACLForServiceProvider.h



################################################################################
# Linux_DnsBlackholeACLForZone
libcmpiLinux_DnsBlackholeACLForZone_la_SOURCES = \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneInstanceName.cpp \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneInstance.cpp \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneExternal.cpp \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneManualInstance.cpp \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneDefaultImplementation.cpp \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneFactory.cpp \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneResourceAccess.cpp \
        $(srcdir)/Linux_DnsBlackholeACLForZone/CmpiLinux_DnsBlackholeACLForZoneProvider.cpp

libcmpiLinux_DnsBlackholeACLForZone_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsService.la \
	libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsBlackholeACLForZone_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement \
        -lcmpiLinux_DnsService \
        -lcmpiLinux_DnsAddressMatchList

libcmpiLinux_DnsBlackholeACLForZone_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneInterface.h \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneInstanceName.h \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneInstance.h \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneExternal.h \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneRepositoryInstance.h \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneRepositoryExternal.h \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneManualInstance.h \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneDefaultImplementation.h \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneFactory.h \
        $(srcdir)/Linux_DnsBlackholeACLForZone/Linux_DnsBlackholeACLForZoneResourceAccess.h \
        $(srcdir)/Linux_DnsBlackholeACLForZone/CmpiLinux_DnsBlackholeACLForZoneProvider.h



################################################################################
# Linux_DnsConfiguration
libcmpiLinux_DnsConfiguration_la_SOURCES = \
	$(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationInstanceName.cpp \
        $(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationInstance.cpp \
        $(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationExternal.cpp \
        $(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationManualInstance.cpp \
        $(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationFactory.cpp \
	$(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationResourceAccess.cpp \
	$(srcdir)/Linux_DnsConfiguration/CmpiLinux_DnsConfigurationProvider.cpp

libcmpiLinux_DnsConfiguration_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la

libcmpiLinux_DnsConfiguration_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement
        
libcmpiLinux_DnsConfiguration_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationInterface.h \
	$(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationInstanceName.h \
        $(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationInstance.h \
        $(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationExternal.h \
        $(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationRepositoryInstance.h \
        $(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationRepositoryExternal.h \
        $(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationManualInstance.h \
        $(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationDefaultImplementation.h \
	$(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationFactory.h \
	$(srcdir)/Linux_DnsConfiguration/Linux_DnsConfigurationResourceAccess.h \
	$(srcdir)/Linux_DnsConfiguration/CmpiLinux_DnsConfigurationProvider.h



################################################################################
# Linux_DnsElementSetting
libcmpiLinux_DnsElementSetting_la_SOURCES = \
	$(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingInstanceName.cpp \
        $(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingInstance.cpp \
        $(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingExternal.cpp \
        $(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingManualInstance.cpp \
        $(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingFactory.cpp \
	$(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingResourceAccess.cpp \
	$(srcdir)/Linux_DnsElementSetting/CmpiLinux_DnsElementSettingProvider.cpp

libcmpiLinux_DnsElementSetting_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsService.la \
	libcmpiLinux_DnsSetting.la

libcmpiLinux_DnsElementSetting_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement \
        -lcmpiLinux_DnsService \
        -lcmpiLinux_DnsSetting
        
libcmpiLinux_DnsElementSetting_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingInterface.h \
	$(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingInstanceName.h \
        $(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingInstance.h \
        $(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingExternal.h \
        $(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingRepositoryInstance.h \
        $(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingRepositoryExternal.h \
        $(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingManualInstance.h \
        $(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingDefaultImplementation.h \
	$(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingFactory.h \
	$(srcdir)/Linux_DnsElementSetting/Linux_DnsElementSettingResourceAccess.h \
	$(srcdir)/Linux_DnsElementSetting/CmpiLinux_DnsElementSettingProvider.h



################################################################################
# Linux_DnsForwardZone
libcmpiLinux_DnsForwardZone_la_SOURCES = \
		$(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneInstanceName.cpp \
        $(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneInstance.cpp \
        $(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneExternal.cpp \
        $(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneManualInstance.cpp \
        $(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneFactory.cpp \
	$(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneResourceAccess.cpp \
	$(srcdir)/Linux_DnsForwardZone/CmpiLinux_DnsForwardZoneProvider.cpp

libcmpiLinux_DnsForwardZone_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la

libcmpiLinux_DnsForwardZone_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement
        
libcmpiLinux_DnsForwardZone_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneInterface.h \
	$(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneInstanceName.h \
        $(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneInstance.h \
        $(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneExternal.h \
        $(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneRepositoryInstance.h \
        $(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneRepositoryExternal.h \
        $(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneManualInstance.h \
        $(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneDefaultImplementation.h \
	$(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneFactory.h \
	$(srcdir)/Linux_DnsForwardZone/Linux_DnsForwardZoneResourceAccess.h \
	$(srcdir)/Linux_DnsForwardZone/CmpiLinux_DnsForwardZoneProvider.h



################################################################################
# Linux_DnsHintZone
libcmpiLinux_DnsHintZone_la_SOURCES = \
	$(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneInstanceName.cpp \
        $(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneInstance.cpp \
        $(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneExternal.cpp \
        $(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneManualInstance.cpp \
        $(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneFactory.cpp \
	$(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneResourceAccess.cpp \
	$(srcdir)/Linux_DnsHintZone/CmpiLinux_DnsHintZoneProvider.cpp

libcmpiLinux_DnsHintZone_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la

libcmpiLinux_DnsHintZone_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement
        
libcmpiLinux_DnsHintZone_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneInterface.h \
	$(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneInstanceName.h \
        $(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneInstance.h \
        $(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneExternal.h \
        $(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneRepositoryInstance.h \
        $(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneRepositoryExternal.h \
        $(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneManualInstance.h \
        $(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneDefaultImplementation.h \
	$(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneFactory.h \
	$(srcdir)/Linux_DnsHintZone/Linux_DnsHintZoneResourceAccess.h \
	$(srcdir)/Linux_DnsHintZone/CmpiLinux_DnsHintZoneProvider.h



################################################################################
# Linux_DnsIPAddress
libcmpiLinux_DnsIPAddress_la_SOURCES = \
	$(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressInstanceName.cpp \
        $(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressInstance.cpp \
        $(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressExternal.cpp \
        $(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressManualInstance.cpp \
        $(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressFactory.cpp \
	$(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressResourceAccess.cpp \
	$(srcdir)/Linux_DnsIPAddress/CmpiLinux_DnsIPAddressProvider.cpp

libcmpiLinux_DnsIPAddress_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la

libcmpiLinux_DnsIPAddress_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement
        
libcmpiLinux_DnsIPAddress_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressInterface.h \
	$(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressInstanceName.h \
        $(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressInstance.h \
        $(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressExternal.h \
        $(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressRepositoryInstance.h \
        $(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressRepositoryExternal.h \
        $(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressManualInstance.h \
        $(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressDefaultImplementation.h \
	$(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressFactory.h \
	$(srcdir)/Linux_DnsIPAddress/Linux_DnsIPAddressResourceAccess.h \
	$(srcdir)/Linux_DnsIPAddress/CmpiLinux_DnsIPAddressProvider.h



################################################################################
# Linux_DnsManagedSystemElementForSetting
libcmpiLinux_DnsManagedSystemElementForSetting_la_SOURCES = \
	$(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingInstanceName.cpp \
        $(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingInstance.cpp \
        $(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingExternal.cpp \
        $(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingManualInstance.cpp \
        $(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingFactory.cpp \
	$(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingResourceAccess.cpp \
	$(srcdir)/Linux_DnsManagedSystemElementForSetting/CmpiLinux_DnsManagedSystemElementForSettingProvider.cpp

libcmpiLinux_DnsManagedSystemElementForSetting_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsZone.la \
	libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsManagedSystemElementForSetting_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement \
        -lcmpiLinux_DnsZone \
        -lcmpiLinux_DnsAddressMatchList
        
libcmpiLinux_DnsManagedSystemElementForSetting_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingInterface.h \
	$(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingInstanceName.h \
        $(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingInstance.h \
        $(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingExternal.h \
        $(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingRepositoryInstance.h \
        $(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingRepositoryExternal.h \
        $(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingManualInstance.h \
        $(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingDefaultImplementation.h \
	$(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingFactory.h \
	$(srcdir)/Linux_DnsManagedSystemElementForSetting/Linux_DnsManagedSystemElementForSettingResourceAccess.h \
	$(srcdir)/Linux_DnsManagedSystemElementForSetting/CmpiLinux_DnsManagedSystemElementForSettingProvider.h



################################################################################
# Linux_DnsMastersOfSlaveZone
libcmpiLinux_DnsMastersOfSlaveZone_la_SOURCES = \
	$(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneInstanceName.cpp \
        $(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneInstance.cpp \
        $(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneExternal.cpp \
        $(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneManualInstance.cpp \
        $(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneFactory.cpp \
	$(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneResourceAccess.cpp \
	$(srcdir)/Linux_DnsMastersOfSlaveZone/CmpiLinux_DnsMastersOfSlaveZoneProvider.cpp

libcmpiLinux_DnsMastersOfSlaveZone_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsSlaveZone.la \
	libcmpiLinux_DnsIPAddress.la

libcmpiLinux_DnsMastersOfSlaveZone_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement \
        -lcmpiLinux_DnsSlaveZone \
        -lcmpiLinux_DnsIPAddress
        
libcmpiLinux_DnsMastersOfSlaveZone_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneInterface.h \
	$(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneInstanceName.h \
        $(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneInstance.h \
        $(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneExternal.h \
        $(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneRepositoryInstance.h \
        $(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneRepositoryExternal.h \
        $(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneManualInstance.h \
        $(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneDefaultImplementation.h \
	$(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneFactory.h \
	$(srcdir)/Linux_DnsMastersOfSlaveZone/Linux_DnsMastersOfSlaveZoneResourceAccess.h \
	$(srcdir)/Linux_DnsMastersOfSlaveZone/CmpiLinux_DnsMastersOfSlaveZoneProvider.h



################################################################################
# Linux_DnsMasterZone
libcmpiLinux_DnsMasterZone_la_SOURCES = \
	$(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneInstanceName.cpp \
        $(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneInstance.cpp \
        $(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneExternal.cpp \
        $(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneManualInstance.cpp \
        $(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneFactory.cpp \
	$(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneResourceAccess.cpp \
	$(srcdir)/Linux_DnsMasterZone/CmpiLinux_DnsMasterZoneProvider.cpp

libcmpiLinux_DnsMasterZone_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la

libcmpiLinux_DnsMasterZone_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement
        
libcmpiLinux_DnsMasterZone_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneInterface.h \
	$(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneInstanceName.h \
        $(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneInstance.h \
        $(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneExternal.h \
        $(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneRepositoryInstance.h \
        $(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneRepositoryExternal.h \
        $(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneManualInstance.h \
        $(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneDefaultImplementation.h \
	$(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneFactory.h \
	$(srcdir)/Linux_DnsMasterZone/Linux_DnsMasterZoneResourceAccess.h \
	$(srcdir)/Linux_DnsMasterZone/CmpiLinux_DnsMasterZoneProvider.h



################################################################################
# Linux_DnsNotifyACLForService
libcmpiLinux_DnsNotifyACLForService_la_SOURCES = \
	$(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceInstanceName.cpp \
        $(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceInstance.cpp \
        $(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceExternal.cpp \
        $(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceManualInstance.cpp \
        $(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceFactory.cpp \
	$(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceResourceAccess.cpp \
	$(srcdir)/Linux_DnsNotifyACLForService/CmpiLinux_DnsNotifyACLForServiceProvider.cpp

libcmpiLinux_DnsNotifyACLForService_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsService.la \
	libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsNotifyACLForService_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement \
        -lcmpiLinux_DnsService \
        -lcmpiLinux_DnsAddressMatchList
        
libcmpiLinux_DnsNotifyACLForService_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceInterface.h \
	$(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceInstanceName.h \
        $(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceInstance.h \
        $(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceExternal.h \
        $(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceRepositoryInstance.h \
        $(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceRepositoryExternal.h \
        $(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceManualInstance.h \
        $(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceDefaultImplementation.h \
	$(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceFactory.h \
	$(srcdir)/Linux_DnsNotifyACLForService/Linux_DnsNotifyACLForServiceResourceAccess.h \
	$(srcdir)/Linux_DnsNotifyACLForService/CmpiLinux_DnsNotifyACLForServiceProvider.h



################################################################################
# Linux_DnsQueryACLForService
libcmpiLinux_DnsQueryACLForService_la_SOURCES = \
	$(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceInstanceName.cpp \
        $(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceInstance.cpp \
        $(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceExternal.cpp \
        $(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceManualInstance.cpp \
        $(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceFactory.cpp \
	$(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceResourceAccess.cpp \
	$(srcdir)/Linux_DnsQueryACLForService/CmpiLinux_DnsQueryACLForServiceProvider.cpp

libcmpiLinux_DnsQueryACLForService_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsService.la \
	libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsQueryACLForService_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement \
        -lcmpiLinux_DnsService \
        -lcmpiLinux_DnsAddressMatchList
        
libcmpiLinux_DnsQueryACLForService_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceInterface.h \
	$(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceInstanceName.h \
        $(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceInstance.h \
        $(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceExternal.h \
        $(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceRepositoryInstance.h \
        $(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceRepositoryExternal.h \
        $(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceManualInstance.h \
        $(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceDefaultImplementation.h \
	$(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceFactory.h \
	$(srcdir)/Linux_DnsQueryACLForService/Linux_DnsQueryACLForServiceResourceAccess.h \
	$(srcdir)/Linux_DnsQueryACLForService/CmpiLinux_DnsQueryACLForServiceProvider.h



################################################################################
# Linux_DnsRecursionACLForService
libcmpiLinux_DnsRecursionACLForService_la_SOURCES = \
	$(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceInstanceName.cpp \
        $(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceInstance.cpp \
        $(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceExternal.cpp \
        $(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceManualInstance.cpp \
        $(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceFactory.cpp \
	$(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceResourceAccess.cpp \
	$(srcdir)/Linux_DnsRecursionACLForService/CmpiLinux_DnsRecursionACLForServiceProvider.cpp

libcmpiLinux_DnsRecursionACLForService_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsService.la \
	libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsRecursionACLForService_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement \
        -lcmpiLinux_DnsService \
        -lcmpiLinux_DnsAddressMatchList

libcmpiLinux_DnsRecursionACLForService_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceInterface.h \
	$(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceInstanceName.h \
        $(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceInstance.h \
        $(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceExternal.h \
        $(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceRepositoryInstance.h \
        $(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceRepositoryExternal.h \
        $(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceManualInstance.h \
        $(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceDefaultImplementation.h \
	$(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceFactory.h \
	$(srcdir)/Linux_DnsRecursionACLForService/Linux_DnsRecursionACLForServiceResourceAccess.h \
	$(srcdir)/Linux_DnsRecursionACLForService/CmpiLinux_DnsRecursionACLForServiceProvider.h



################################################################################
# Linux_DnsResourceRecord
libcmpiLinux_DnsResourceRecord_la_SOURCES = \
	$(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordInstanceName.cpp \
        $(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordInstance.cpp \
        $(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordExternal.cpp \
        $(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordManualInstance.cpp \
        $(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordFactory.cpp \
	$(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordResourceAccess.cpp \
	$(srcdir)/Linux_DnsResourceRecord/CmpiLinux_DnsResourceRecordProvider.cpp

libcmpiLinux_DnsResourceRecord_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la

libcmpiLinux_DnsResourceRecord_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement
        
libcmpiLinux_DnsResourceRecord_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordInterface.h \
	$(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordInstanceName.h \
        $(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordInstance.h \
        $(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordExternal.h \
        $(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordRepositoryInstance.h \
        $(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordRepositoryExternal.h \
        $(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordManualInstance.h \
        $(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordDefaultImplementation.h \
	$(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordFactory.h \
	$(srcdir)/Linux_DnsResourceRecord/Linux_DnsResourceRecordResourceAccess.h \
	$(srcdir)/Linux_DnsResourceRecord/CmpiLinux_DnsResourceRecordProvider.h



################################################################################
# Linux_DnsResourceRecordInZone
libcmpiLinux_DnsResourceRecordInZone_la_SOURCES = \
	$(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneInstanceName.cpp \
        $(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneInstance.cpp \
        $(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneExternal.cpp \
        $(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneManualInstance.cpp \
        $(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneFactory.cpp \
	$(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneResourceAccess.cpp \
	$(srcdir)/Linux_DnsResourceRecordInZone/CmpiLinux_DnsResourceRecordInZoneProvider.cpp

libcmpiLinux_DnsResourceRecordInZone_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsZone.la \
	libcmpiLinux_DnsResourceRecord.la

libcmpiLinux_DnsResourceRecordInZone_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement \
        -lcmpiLinux_DnsZone \
        -lcmpiLinux_DnsResourceRecord
        
libcmpiLinux_DnsResourceRecordInZone_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneInterface.h \
	$(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneInstanceName.h \
        $(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneInstance.h \
        $(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneExternal.h \
        $(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneRepositoryInstance.h \
        $(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneRepositoryExternal.h \
        $(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneManualInstance.h \
        $(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneDefaultImplementation.h \
	$(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneFactory.h \
	$(srcdir)/Linux_DnsResourceRecordInZone/Linux_DnsResourceRecordInZoneResourceAccess.h \
	$(srcdir)/Linux_DnsResourceRecordInZone/CmpiLinux_DnsResourceRecordInZoneProvider.h



################################################################################
# Linux_DnsService
libcmpiLinux_DnsService_la_SOURCES = \
	$(srcdir)/Linux_DnsService/Linux_DnsServiceInstanceName.cpp \
        $(srcdir)/Linux_DnsService/Linux_DnsServiceInstance.cpp \
        $(srcdir)/Linux_DnsService/Linux_DnsServiceExternal.cpp \
        $(srcdir)/Linux_DnsService/Linux_DnsServiceRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsService/Linux_DnsServiceRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsService/Linux_DnsServiceManualInstance.cpp \
        $(srcdir)/Linux_DnsService/Linux_DnsServiceDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsService/Linux_DnsServiceFactory.cpp \
	$(srcdir)/Linux_DnsService/Linux_DnsServiceResourceAccess.cpp \
	$(srcdir)/Linux_DnsService/CmpiLinux_DnsServiceProvider.cpp

libcmpiLinux_DnsService_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la

libcmpiLinux_DnsService_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement
        
libcmpiLinux_DnsService_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsService/Linux_DnsServiceInterface.h \
	$(srcdir)/Linux_DnsService/Linux_DnsServiceInstanceName.h \
        $(srcdir)/Linux_DnsService/Linux_DnsServiceInstance.h \
        $(srcdir)/Linux_DnsService/Linux_DnsServiceExternal.h \
        $(srcdir)/Linux_DnsService/Linux_DnsServiceRepositoryInstance.h \
        $(srcdir)/Linux_DnsService/Linux_DnsServiceRepositoryExternal.h \
        $(srcdir)/Linux_DnsService/Linux_DnsServiceManualInstance.h \
        $(srcdir)/Linux_DnsService/Linux_DnsServiceDefaultImplementation.h \
	$(srcdir)/Linux_DnsService/Linux_DnsServiceFactory.h \
	$(srcdir)/Linux_DnsService/Linux_DnsServiceResourceAccess.h \
	$(srcdir)/Linux_DnsService/CmpiLinux_DnsServiceProvider.h



################################################################################
# Linux_DnsServiceConfiguration
libcmpiLinux_DnsServiceConfiguration_la_SOURCES = \
	$(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationInstanceName.cpp \
        $(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationInstance.cpp \
        $(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationExternal.cpp \
        $(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationManualInstance.cpp \
        $(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationFactory.cpp \
	$(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationResourceAccess.cpp \
	$(srcdir)/Linux_DnsServiceConfiguration/CmpiLinux_DnsServiceConfigurationProvider.cpp

libcmpiLinux_DnsServiceConfiguration_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsService.la \
	libcmpiLinux_DnsConfiguration.la

libcmpiLinux_DnsServiceConfiguration_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement \
        -lcmpiLinux_DnsService \
        -lcmpiLinux_DnsConfiguration
        
libcmpiLinux_DnsServiceConfiguration_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationInterface.h \
	$(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationInstanceName.h \
        $(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationInstance.h \
        $(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationExternal.h \
        $(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationRepositoryInstance.h \
        $(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationRepositoryExternal.h \
        $(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationManualInstance.h \
        $(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationDefaultImplementation.h \
	$(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationFactory.h \
	$(srcdir)/Linux_DnsServiceConfiguration/Linux_DnsServiceConfigurationResourceAccess.h \
	$(srcdir)/Linux_DnsServiceConfiguration/CmpiLinux_DnsServiceConfigurationProvider.h



################################################################################
# Linux_DnsSetting
libcmpiLinux_DnsSetting_la_SOURCES = \
	$(srcdir)/Linux_DnsSetting/Linux_DnsSettingInstanceName.cpp \
        $(srcdir)/Linux_DnsSetting/Linux_DnsSettingInstance.cpp \
        $(srcdir)/Linux_DnsSetting/Linux_DnsSettingExternal.cpp \
        $(srcdir)/Linux_DnsSetting/Linux_DnsSettingRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsSetting/Linux_DnsSettingRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsSetting/Linux_DnsSettingManualInstance.cpp \
        $(srcdir)/Linux_DnsSetting/Linux_DnsSettingDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsSetting/Linux_DnsSettingFactory.cpp \
	$(srcdir)/Linux_DnsSetting/Linux_DnsSettingResourceAccess.cpp \
	$(srcdir)/Linux_DnsSetting/CmpiLinux_DnsSettingProvider.cpp

libcmpiLinux_DnsSetting_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la

libcmpiLinux_DnsSetting_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement
        
libcmpiLinux_DnsSetting_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsSetting/Linux_DnsSettingInterface.h \
	$(srcdir)/Linux_DnsSetting/Linux_DnsSettingInstanceName.h \
        $(srcdir)/Linux_DnsSetting/Linux_DnsSettingInstance.h \
        $(srcdir)/Linux_DnsSetting/Linux_DnsSettingExternal.h \
        $(srcdir)/Linux_DnsSetting/Linux_DnsSettingRepositoryInstance.h \
        $(srcdir)/Linux_DnsSetting/Linux_DnsSettingRepositoryExternal.h \
        $(srcdir)/Linux_DnsSetting/Linux_DnsSettingManualInstance.h \
        $(srcdir)/Linux_DnsSetting/Linux_DnsSettingDefaultImplementation.h \
	$(srcdir)/Linux_DnsSetting/Linux_DnsSettingFactory.h \
	$(srcdir)/Linux_DnsSetting/Linux_DnsSettingResourceAccess.h \
	$(srcdir)/Linux_DnsSetting/CmpiLinux_DnsSettingProvider.h



################################################################################
# Linux_DnsSettingContext
libcmpiLinux_DnsSettingContext_la_SOURCES = \
	$(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextInstanceName.cpp \
        $(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextInstance.cpp \
        $(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextExternal.cpp \
        $(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextManualInstance.cpp \
        $(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextFactory.cpp \
	$(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextResourceAccess.cpp \
	$(srcdir)/Linux_DnsSettingContext/CmpiLinux_DnsSettingContextProvider.cpp

libcmpiLinux_DnsSettingContext_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsSetting.la \
	libcmpiLinux_DnsConfiguration.la

libcmpiLinux_DnsSettingContext_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement \
        -lcmpiLinux_DnsSetting \
        -lcmpiLinux_DnsConfiguration
        
libcmpiLinux_DnsSettingContext_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextInterface.h \
	$(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextInstanceName.h \
        $(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextInstance.h \
        $(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextExternal.h \
        $(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextRepositoryInstance.h \
        $(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextRepositoryExternal.h \
        $(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextManualInstance.h \
        $(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextDefaultImplementation.h \
	$(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextFactory.h \
	$(srcdir)/Linux_DnsSettingContext/Linux_DnsSettingContextResourceAccess.h \
	$(srcdir)/Linux_DnsSettingContext/CmpiLinux_DnsSettingContextProvider.h



################################################################################
# Linux_DnsSlaveZone
libcmpiLinux_DnsSlaveZone_la_SOURCES = \
	$(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneInstanceName.cpp \
        $(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneInstance.cpp \
        $(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneExternal.cpp \
        $(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneManualInstance.cpp \
        $(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneFactory.cpp \
	$(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneResourceAccess.cpp \
	$(srcdir)/Linux_DnsSlaveZone/CmpiLinux_DnsSlaveZoneProvider.cpp

libcmpiLinux_DnsSlaveZone_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la

libcmpiLinux_DnsSlaveZone_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement
        
libcmpiLinux_DnsSlaveZone_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneInterface.h \
	$(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneInstanceName.h \
        $(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneInstance.h \
        $(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneExternal.h \
        $(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneRepositoryInstance.h \
        $(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneRepositoryExternal.h \
        $(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneManualInstance.h \
        $(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneDefaultImplementation.h \
	$(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneFactory.h \
	$(srcdir)/Linux_DnsSlaveZone/Linux_DnsSlaveZoneResourceAccess.h \
	$(srcdir)/Linux_DnsSlaveZone/CmpiLinux_DnsSlaveZoneProvider.h



################################################################################
# Linux_DnsTransferACLForService
libcmpiLinux_DnsTransferACLForService_la_SOURCES = \
	$(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceInstanceName.cpp \
        $(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceInstance.cpp \
        $(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceExternal.cpp \
        $(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceRepositoryInstance.cpp \
        $(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceRepositoryExternal.cpp \
        $(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceManualInstance.cpp \
        $(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceDefaultImplementation.cpp \
	$(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceFactory.cpp \
	$(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceResourceAccess.cpp \
	$(srcdir)/Linux_DnsTransferACLForService/CmpiLinux_DnsTransferACLForServiceProvider.cpp

libcmpiLinux_DnsTransferACLForService_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la \
	libcmpiLinux_DnsService.la \
	libcmpiLinux_DnsAddressMatchList.la

libcmpiLinux_DnsTransferACLForService_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement \
        -lcmpiLinux_DnsService \
        -lcmpiLinux_DnsAddressMatchList
        
libcmpiLinux_DnsTransferACLForService_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
        $(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceInterface.h \
	$(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceInstanceName.h \
        $(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceInstance.h \
        $(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceExternal.h \
        $(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceRepositoryInstance.h \
        $(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceRepositoryExternal.h \
        $(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceManualInstance.h \
        $(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceDefaultImplementation.h \
	$(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceFactory.h \
	$(srcdir)/Linux_DnsTransferACLForService/Linux_DnsTransferACLForServiceResourceAccess.h \
	$(srcdir)/Linux_DnsTransferACLForService/CmpiLinux_DnsTransferACLForServiceProvider.h



################################################################################
# Linux_DnsZone
libcmpiLinux_DnsZone_la_SOURCES = \
	$(srcdir)/Linux_DnsZone/Linux_DnsZoneInstanceName.cpp \
        $(srcdir)/Linux_DnsZone/Linux_DnsZoneInstance.cpp \
        $(srcdir)/Linux_DnsZone/Linux_DnsZoneExternal.cpp 

libcmpiLinux_DnsZone_la_DEPENDENCIES = \
        libIBM_DnsProviderTooling.la \
        libLinux_DnsGeneralProviderBasic.la \
	libcmpiDnsCIM_CollectionOfMSEs.la \
	libcmpiDnsCIM_ConcreteJob.la \
	libcmpiDnsCIM_ManagedSystemElement.la

libcmpiLinux_DnsZone_la_LIBADD = \
        -L../resource-access\
        -lRaToolsDns \
        -lIBM_DnsProviderTooling \
        -lLinux_DnsGeneralProviderBasic \
        -lcmpiDnsCIM_CollectionOfMSEs \
        -lcmpiDnsCIM_ConcreteJob \
        -lcmpiDnsCIM_ManagedSystemElement
        
libcmpiLinux_DnsZone_la_LDFLAGS  = -avoid-version

noinst_HEADERS+= \
	$(srcdir)/Linux_DnsZone/Linux_DnsZoneInstanceName.h \
        $(srcdir)/Linux_DnsZone/Linux_DnsZoneInstance.h \
        $(srcdir)/Linux_DnsZone/Linux_DnsZoneExternal.h 
