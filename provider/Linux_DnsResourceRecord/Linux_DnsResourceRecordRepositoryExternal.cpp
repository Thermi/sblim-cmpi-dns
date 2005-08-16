 /**
 * Linux_DnsResourceRecordRepositoryExternal.cpp
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
#include "Linux_DnsResourceRecordRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsResourceRecordRepositoryExternal::Linux_DnsResourceRecordRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsResourceRecordRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsResourceRecordRepositoryExternal::
   ~Linux_DnsResourceRecordRepositoryExternal(){};
    
  void Linux_DnsResourceRecordRepositoryExternal::enumInstanceNames(
   Linux_DnsResourceRecordInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsResourceRecord");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsResourceRecordInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsResourceRecordRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsResourceRecordRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsResourceRecord");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsResourceRecordRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsResourceRecordRepositoryInstance
   Linux_DnsResourceRecordRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsResourceRecordInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsResourceRecordRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsResourceRecordRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsResourceRecordRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsResourceRecordInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsResourceRecordRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsResourceRecordRepositoryExternal::createInstance(
   const Linux_DnsResourceRecordRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsResourceRecordInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsResourceRecordRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsResourceRecordRepositoryExternal::deleteInstance(
   const Linux_DnsResourceRecordInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
