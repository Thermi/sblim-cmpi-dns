 /**
 * Linux_DnsAllowNotifyACLForZoneRepositoryExternal.cpp
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
#include "Linux_DnsAllowNotifyACLForZoneRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsAllowNotifyACLForZoneRepositoryExternal::Linux_DnsAllowNotifyACLForZoneRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsAllowNotifyACLForZoneRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsAllowNotifyACLForZoneRepositoryExternal::
   ~Linux_DnsAllowNotifyACLForZoneRepositoryExternal(){};
    
  void Linux_DnsAllowNotifyACLForZoneRepositoryExternal::enumInstanceNames(
   Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsAllowNotifyACLForZone");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsAllowNotifyACLForZoneInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsAllowNotifyACLForZoneRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsAllowNotifyACLForZone");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsAllowNotifyACLForZoneRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsAllowNotifyACLForZoneRepositoryInstance
   Linux_DnsAllowNotifyACLForZoneRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsAllowNotifyACLForZoneInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsAllowNotifyACLForZoneRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsAllowNotifyACLForZoneRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsAllowNotifyACLForZoneInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsAllowNotifyACLForZoneRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsAllowNotifyACLForZoneRepositoryExternal::createInstance(
   const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsAllowNotifyACLForZoneInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsAllowNotifyACLForZoneRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsAllowNotifyACLForZoneRepositoryExternal::deleteInstance(
   const Linux_DnsAllowNotifyACLForZoneInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
