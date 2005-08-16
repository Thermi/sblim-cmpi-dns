#
# Linux_DnsHintZoneResourceAccess.cpp
#
#  (C) Copyright IBM Corp. 2005
# 
#  THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
#  ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
#  CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
# 
#  You can obtain a current copy of the Common Public License from
#  http://www.opensource.org/licenses/cpl1.0.php
# 
#  author:     Murillo Bernardes <bernarde@br.ibm.com>
# 
#  Contributors:
# 
 
cimmofl -I. -aE -nroot/cimv2 Linux_DnsAddressMatchList.mof;
cimmofl -I. -aE -nroot/cimv2 CIM_CollectionOfMSEs.mof;
cimmofl -I. -aE -nroot/cimv2 CIM_ManagedSystemElement.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsAddressMatchListRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsAddressMatchListRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsService.mof;
cimmofl -I. -aE -nroot/cimv2 CIM_ConcreteJob.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsServiceRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsServiceRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsAddressMatchListOfService.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsAddressMatchListOfServiceRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsAddressMatchListOfServiceRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsZone.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsZoneRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsZoneRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsManagedSystemElementForSetting.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsManagedSystemElementForSettingRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsManagedSystemElementForSettingRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsAllowNotifyACLForZone.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsAllowNotifyACLForZoneRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsAllowNotifyACLForZoneRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsAllowQueryACLForZone.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsAllowQueryACLForZoneRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsAllowQueryACLForZoneRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsAllowTransferACLForZone.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsAllowTransferACLForZoneRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsAllowTransferACLForZoneRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsAllowUpdateACLForZone.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsAllowUpdateACLForZoneRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsAllowUpdateACLForZoneRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsBlackholeACLForService.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsBlackholeACLForServiceRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsBlackholeACLForServiceRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsBlackholeACLForZone.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsBlackholeACLForZoneRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsBlackholeACLForZoneRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsConfiguration.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsConfigurationRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsConfigurationRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsSetting.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsSettingRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsSettingRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsElementSetting.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsElementSettingRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsElementSettingRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsForwardZone.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsForwardZoneRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsForwardZoneRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsHintZone.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsHintZoneRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsHintZoneRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsIPAddress.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsIPAddressRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsIPAddressRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsMasterZone.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsMasterZoneRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsMasterZoneRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsSlaveZone.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsSlaveZoneRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsSlaveZoneRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsMastersOfSlaveZone.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsMastersOfSlaveZoneRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsMastersOfSlaveZoneRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsNotifyACLForService.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsNotifyACLForServiceRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsNotifyACLForServiceRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsQueryACLForService.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsQueryACLForServiceRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsQueryACLForServiceRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsRecursionACLForService.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsRecursionACLForServiceRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsRecursionACLForServiceRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsResourceRecord.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsResourceRecordRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsResourceRecordRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsResourceRecordInZone.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsResourceRecordInZoneRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsResourceRecordInZoneRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsServiceConfiguration.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsServiceConfigurationRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsServiceConfigurationRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsSettingContext.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsSettingContextRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsSettingContextRegister.mof;
cimmofl -I. -aE -nroot/cimv2 Linux_DnsTransferACLForService.mof;
cimmofl -I. -aE -nIBMShadow/cimv2 Linux_DnsTransferACLForServiceRepository.mof;
cimmofl -I. -aE -nroot/PG_InterOp Linux_DnsTransferACLForServiceRegister.mof;
