 /**
 * Linux_DnsIPAddressRepositoryExternal.cpp
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
#include "Linux_DnsIPAddressRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsIPAddressRepositoryExternal::Linux_DnsIPAddressRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsIPAddressRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsIPAddressRepositoryExternal::
   ~Linux_DnsIPAddressRepositoryExternal(){};
    
  void Linux_DnsIPAddressRepositoryExternal::enumInstanceNames(
   Linux_DnsIPAddressInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsIPAddress");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsIPAddressInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsIPAddressRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsIPAddressRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsIPAddress");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsIPAddressRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsIPAddressRepositoryInstance
   Linux_DnsIPAddressRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsIPAddressInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsIPAddressRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsIPAddressRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsIPAddressRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsIPAddressInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsIPAddressRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsIPAddressRepositoryExternal::createInstance(
   const Linux_DnsIPAddressRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsIPAddressInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsIPAddressRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsIPAddressRepositoryExternal::deleteInstance(
   const Linux_DnsIPAddressInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
