 /**
 * Linux_DnsAddressMatchListOfServiceRepositoryExternal.cpp
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
#include "Linux_DnsAddressMatchListOfServiceRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsAddressMatchListOfServiceRepositoryExternal::Linux_DnsAddressMatchListOfServiceRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsAddressMatchListOfServiceRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsAddressMatchListOfServiceRepositoryExternal::
   ~Linux_DnsAddressMatchListOfServiceRepositoryExternal(){};
    
  void Linux_DnsAddressMatchListOfServiceRepositoryExternal::enumInstanceNames(
   Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsAddressMatchListOfService");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsAddressMatchListOfServiceInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsAddressMatchListOfServiceRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsAddressMatchListOfService");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsAddressMatchListOfServiceRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsAddressMatchListOfServiceRepositoryInstance
   Linux_DnsAddressMatchListOfServiceRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsAddressMatchListOfServiceInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsAddressMatchListOfServiceRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsAddressMatchListOfServiceRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsAddressMatchListOfServiceRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsAddressMatchListOfServiceInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsAddressMatchListOfServiceRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsAddressMatchListOfServiceRepositoryExternal::createInstance(
   const Linux_DnsAddressMatchListOfServiceRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsAddressMatchListOfServiceInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsAddressMatchListOfServiceRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsAddressMatchListOfServiceRepositoryExternal::deleteInstance(
   const Linux_DnsAddressMatchListOfServiceInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
