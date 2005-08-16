 /**
 * Linux_DnsAllowQueryACLForZoneRepositoryExternal.cpp
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
#include "Linux_DnsAllowQueryACLForZoneRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsAllowQueryACLForZoneRepositoryExternal::Linux_DnsAllowQueryACLForZoneRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsAllowQueryACLForZoneRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsAllowQueryACLForZoneRepositoryExternal::
   ~Linux_DnsAllowQueryACLForZoneRepositoryExternal(){};
    
  void Linux_DnsAllowQueryACLForZoneRepositoryExternal::enumInstanceNames(
   Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsAllowQueryACLForZone");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsAllowQueryACLForZoneInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsAllowQueryACLForZoneRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsAllowQueryACLForZone");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsAllowQueryACLForZoneRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsAllowQueryACLForZoneRepositoryInstance
   Linux_DnsAllowQueryACLForZoneRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsAllowQueryACLForZoneInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsAllowQueryACLForZoneRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsAllowQueryACLForZoneRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsAllowQueryACLForZoneRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsAllowQueryACLForZoneInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsAllowQueryACLForZoneRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsAllowQueryACLForZoneRepositoryExternal::createInstance(
   const Linux_DnsAllowQueryACLForZoneRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsAllowQueryACLForZoneInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsAllowQueryACLForZoneRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsAllowQueryACLForZoneRepositoryExternal::deleteInstance(
   const Linux_DnsAllowQueryACLForZoneInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
