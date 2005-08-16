 /**
 * Linux_DnsRecursionACLForServiceRepositoryExternal.cpp
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
#include "Linux_DnsRecursionACLForServiceRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsRecursionACLForServiceRepositoryExternal::Linux_DnsRecursionACLForServiceRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsRecursionACLForServiceRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsRecursionACLForServiceRepositoryExternal::
   ~Linux_DnsRecursionACLForServiceRepositoryExternal(){};
    
  void Linux_DnsRecursionACLForServiceRepositoryExternal::enumInstanceNames(
   Linux_DnsRecursionACLForServiceInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsRecursionACLForService");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsRecursionACLForServiceInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsRecursionACLForServiceRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsRecursionACLForService");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsRecursionACLForServiceRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsRecursionACLForServiceRepositoryInstance
   Linux_DnsRecursionACLForServiceRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsRecursionACLForServiceInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsRecursionACLForServiceRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsRecursionACLForServiceRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsRecursionACLForServiceRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsRecursionACLForServiceInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsRecursionACLForServiceRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsRecursionACLForServiceRepositoryExternal::createInstance(
   const Linux_DnsRecursionACLForServiceRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsRecursionACLForServiceInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsRecursionACLForServiceRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsRecursionACLForServiceRepositoryExternal::deleteInstance(
   const Linux_DnsRecursionACLForServiceInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
