 /**
 * Linux_DnsNotifyACLForServiceRepositoryExternal.cpp
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
#include "Linux_DnsNotifyACLForServiceRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsNotifyACLForServiceRepositoryExternal::Linux_DnsNotifyACLForServiceRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsNotifyACLForServiceRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsNotifyACLForServiceRepositoryExternal::
   ~Linux_DnsNotifyACLForServiceRepositoryExternal(){};
    
  void Linux_DnsNotifyACLForServiceRepositoryExternal::enumInstanceNames(
   Linux_DnsNotifyACLForServiceInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsNotifyACLForService");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsNotifyACLForServiceInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsNotifyACLForServiceRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsNotifyACLForService");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsNotifyACLForServiceRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsNotifyACLForServiceRepositoryInstance
   Linux_DnsNotifyACLForServiceRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsNotifyACLForServiceInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsNotifyACLForServiceRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsNotifyACLForServiceRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsNotifyACLForServiceRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsNotifyACLForServiceInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsNotifyACLForServiceRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsNotifyACLForServiceRepositoryExternal::createInstance(
   const Linux_DnsNotifyACLForServiceRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsNotifyACLForServiceInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsNotifyACLForServiceRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsNotifyACLForServiceRepositoryExternal::deleteInstance(
   const Linux_DnsNotifyACLForServiceInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
