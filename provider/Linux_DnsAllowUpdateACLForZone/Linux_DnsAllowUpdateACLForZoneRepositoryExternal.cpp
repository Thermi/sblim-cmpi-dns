 /**
 * Linux_DnsAllowUpdateACLForZoneRepositoryExternal.cpp
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
#include "Linux_DnsAllowUpdateACLForZoneRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsAllowUpdateACLForZoneRepositoryExternal::Linux_DnsAllowUpdateACLForZoneRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsAllowUpdateACLForZoneRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsAllowUpdateACLForZoneRepositoryExternal::
   ~Linux_DnsAllowUpdateACLForZoneRepositoryExternal(){};
    
  void Linux_DnsAllowUpdateACLForZoneRepositoryExternal::enumInstanceNames(
   Linux_DnsAllowUpdateACLForZoneInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsAllowUpdateACLForZone");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsAllowUpdateACLForZoneInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsAllowUpdateACLForZoneRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsAllowUpdateACLForZone");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsAllowUpdateACLForZoneRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsAllowUpdateACLForZoneRepositoryInstance
   Linux_DnsAllowUpdateACLForZoneRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsAllowUpdateACLForZoneInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsAllowUpdateACLForZoneRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsAllowUpdateACLForZoneRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsAllowUpdateACLForZoneInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsAllowUpdateACLForZoneRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsAllowUpdateACLForZoneRepositoryExternal::createInstance(
   const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsAllowUpdateACLForZoneInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsAllowUpdateACLForZoneRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsAllowUpdateACLForZoneRepositoryExternal::deleteInstance(
   const Linux_DnsAllowUpdateACLForZoneInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
