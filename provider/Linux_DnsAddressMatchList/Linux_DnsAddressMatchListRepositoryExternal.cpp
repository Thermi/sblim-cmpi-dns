 /**
 * Linux_DnsAddressMatchListRepositoryExternal.cpp
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
#include "Linux_DnsAddressMatchListRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsAddressMatchListRepositoryExternal::Linux_DnsAddressMatchListRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsAddressMatchListRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsAddressMatchListRepositoryExternal::
   ~Linux_DnsAddressMatchListRepositoryExternal(){};
    
  void Linux_DnsAddressMatchListRepositoryExternal::enumInstanceNames(
   Linux_DnsAddressMatchListInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsAddressMatchList");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsAddressMatchListInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsAddressMatchListRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsAddressMatchListRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsAddressMatchList");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsAddressMatchListRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsAddressMatchListRepositoryInstance
   Linux_DnsAddressMatchListRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsAddressMatchListInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsAddressMatchListRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsAddressMatchListRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsAddressMatchListRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsAddressMatchListInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsAddressMatchListRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsAddressMatchListRepositoryExternal::createInstance(
   const Linux_DnsAddressMatchListRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsAddressMatchListInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsAddressMatchListRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsAddressMatchListRepositoryExternal::deleteInstance(
   const Linux_DnsAddressMatchListInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
