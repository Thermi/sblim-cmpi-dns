 /**
 * Linux_DnsForwardZoneRepositoryExternal.cpp
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
#include "Linux_DnsForwardZoneRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsForwardZoneRepositoryExternal::Linux_DnsForwardZoneRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsForwardZoneRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsForwardZoneRepositoryExternal::
   ~Linux_DnsForwardZoneRepositoryExternal(){};
    
  void Linux_DnsForwardZoneRepositoryExternal::enumInstanceNames(
   Linux_DnsForwardZoneInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsForwardZone");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsForwardZoneInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsForwardZoneRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsForwardZoneRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsForwardZone");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsForwardZoneRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsForwardZoneRepositoryInstance
   Linux_DnsForwardZoneRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsForwardZoneInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsForwardZoneRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsForwardZoneRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsForwardZoneRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsForwardZoneInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsForwardZoneRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsForwardZoneRepositoryExternal::createInstance(
   const Linux_DnsForwardZoneRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsForwardZoneInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsForwardZoneRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsForwardZoneRepositoryExternal::deleteInstance(
   const Linux_DnsForwardZoneInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
