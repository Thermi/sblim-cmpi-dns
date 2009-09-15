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
#
# ==================================================================


# docdir defines where the documentation goes
docdir = $(datadir)/doc/$(PACKAGE)-$(VERSION)


######################################################################################
# Automake instructions for ./test subdir
EXTRA_DIST=README.test test-cmpi-dns.sh system cim $(testsuiteconf_DATA)

doc_DATA=README.test

testsuitedir=@TESTSUITEDIR@
testsuitesystemdir=@TESTSUITEDIR@/system/linux
testsuitecimdir=@TESTSUITEDIR@/cim
testsuiteconfdir=@TESTSUITEDIR@/

testsuite_SCRIPTS=test-cmpi-dns.sh named.conf
testsuitecim_DATA= \
	cim/Linux_DnsElementConformsToProfile.cim \
	cim/Linux_DnsRegisteredProfile.cim \
    cim/Linux_DnsAddressMatchList.cim \
    cim/Linux_DnsAddressMatchListsForService.cim \
    cim/Linux_DnsAllowNotifyForZone.cim \
    cim/Linux_DnsAllowQueryForZone.cim \
    cim/Linux_DnsAllowTransferForZone.cim \
    cim/Linux_DnsAllowUpdateForZone.cim \
    cim/Linux_DnsAllowNotifyForService.cim \
    cim/Linux_DnsAllowQueryForService.cim \
    cim/Linux_DnsAllowRecursionForService.cim \
    cim/Linux_DnsAllowTransferForService.cim \
    cim/Linux_DnsBlackholeForService.cim \
    cim/Linux_DnsForwarders.cim \
    cim/Linux_DnsForwardersForService.cim \
    cim/Linux_DnsForwardersForZone.cim \
    cim/Linux_DnsForwardZone.cim \
    cim/Linux_DnsHintZone.cim \
    cim/Linux_DnsMasters.cim \
    cim/Linux_DnsMastersForService.cim \
    cim/Linux_DnsMastersForZone.cim \
    cim/Linux_DnsMasterZone.cim \
    cim/Linux_DnsResourceRecord.cim \
    cim/Linux_DnsResourceRecordsForZone.cim \
    cim/Linux_DnsService.cim \
    cim/Linux_DnsServiceConfiguration.cim \
    cim/Linux_DnsServiceConfigurationForService.cim \
    cim/Linux_DnsServiceSettingData.cim \
    cim/Linux_DnsServiceSettingDataForServiceConfiguration.cim \
    cim/Linux_DnsSlaveZone.cim \
    cim/Linux_DnsStubZone.cim 

testsuitesystem_DATA= \
	system/linux/Linux_DnsElementConformsToProfile.system \
    system/linux/Linux_DnsAddressMatchList.system \
    system/linux/Linux_DnsForwarders.system \
    system/linux/Linux_DnsForwardZone.system \
    system/linux/Linux_DnsHintZone.system \
    system/linux/Linux_DnsMasters.system \
    system/linux/Linux_DnsMasterZone.system \
    system/linux/Linux_DnsResourceRecord.system \
    system/linux/Linux_DnsService.system \
    system/linux/Linux_DnsServiceConfiguration.system \
    system/linux/Linux_DnsServiceConfigurationForService.system \
    system/linux/Linux_DnsServiceSettingData.system \
    system/linux/Linux_DnsSlaveZone.system \
    system/linux/Linux_DnsStubZone.system


testsuiteconf_DATA= \
    named.conf\
    buffalo.example2.com.conf\
    elephant.example2.com.conf\
    rhino.example1.com.conf\
    testnamed.ca\
    testnamed.broadcast\
    testnamed.ip6.local\
    testnamed.local\
    testnamed.zero\
    testlocaldomain.zone\
    testlocalhost.zone\
    cobra.example1.com.conf

runtest: install
	cd $(DESTDIR)$(TESTSUITEDIR) && ./test-cmpi-dns.sh

