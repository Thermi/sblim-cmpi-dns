 /**
 * Linux_DnsAllowTransferACLForZoneRepositoryExternal.cpp
 *
 * (C) Copyright IBM Corp. 2005
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Common Public License from
 * http://www.opensource.org/licenses/cpl1.0.php
 *
 * author:     Murillo Bernardes <bernarde@br.ibm.com>
 *
 * Contributors:
 *
 */
#include "Linux_DnsAllowTransferACLForZoneRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsAllowTransferACLForZoneRepositoryExternal::Linux_DnsAllowTransferACLForZoneRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsAllowTransferACLForZoneRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsAllowTransferACLForZoneRepositoryExternal::
   ~Linux_DnsAllowTransferACLForZoneRepositoryExternal(){};
    
  void Linux_DnsAllowTransferACLForZoneRepositoryExternal::enumInstanceNames(
   Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsAllowTransferACLForZone");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsAllowTransferACLForZoneInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsAllowTransferACLForZoneRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsAllowTransferACLForZone");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsAllowTransferACLForZoneRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsAllowTransferACLForZoneRepositoryInstance
   Linux_DnsAllowTransferACLForZoneRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsAllowTransferACLForZoneInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsAllowTransferACLForZoneRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsAllowTransferACLForZoneRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsAllowTransferACLForZoneRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsAllowTransferACLForZoneInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsAllowTransferACLForZoneRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsAllowTransferACLForZoneRepositoryExternal::createInstance(
   const Linux_DnsAllowTransferACLForZoneRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsAllowTransferACLForZoneInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsAllowTransferACLForZoneRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsAllowTransferACLForZoneRepositoryExternal::deleteInstance(
   const Linux_DnsAllowTransferACLForZoneInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
