 /**
 * Linux_DnsResourceRecordInZoneRepositoryExternal.cpp
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
#include "Linux_DnsResourceRecordInZoneRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsResourceRecordInZoneRepositoryExternal::Linux_DnsResourceRecordInZoneRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsResourceRecordInZoneRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsResourceRecordInZoneRepositoryExternal::
   ~Linux_DnsResourceRecordInZoneRepositoryExternal(){};
    
  void Linux_DnsResourceRecordInZoneRepositoryExternal::enumInstanceNames(
   Linux_DnsResourceRecordInZoneInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsResourceRecordInZone");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsResourceRecordInZoneInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsResourceRecordInZoneRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsResourceRecordInZone");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsResourceRecordInZoneRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsResourceRecordInZoneRepositoryInstance
   Linux_DnsResourceRecordInZoneRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsResourceRecordInZoneInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsResourceRecordInZoneRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsResourceRecordInZoneRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsResourceRecordInZoneRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsResourceRecordInZoneInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsResourceRecordInZoneRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsResourceRecordInZoneRepositoryExternal::createInstance(
   const Linux_DnsResourceRecordInZoneRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsResourceRecordInZoneInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsResourceRecordInZoneRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsResourceRecordInZoneRepositoryExternal::deleteInstance(
   const Linux_DnsResourceRecordInZoneInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
