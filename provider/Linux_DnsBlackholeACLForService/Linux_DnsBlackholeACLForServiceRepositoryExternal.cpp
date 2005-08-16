 /**
 * Linux_DnsBlackholeACLForServiceRepositoryExternal.cpp
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
#include "Linux_DnsBlackholeACLForServiceRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsBlackholeACLForServiceRepositoryExternal::Linux_DnsBlackholeACLForServiceRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsBlackholeACLForServiceRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsBlackholeACLForServiceRepositoryExternal::
   ~Linux_DnsBlackholeACLForServiceRepositoryExternal(){};
    
  void Linux_DnsBlackholeACLForServiceRepositoryExternal::enumInstanceNames(
   Linux_DnsBlackholeACLForServiceInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsBlackholeACLForService");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsBlackholeACLForServiceInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsBlackholeACLForServiceRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsBlackholeACLForService");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsBlackholeACLForServiceRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsBlackholeACLForServiceRepositoryInstance
   Linux_DnsBlackholeACLForServiceRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsBlackholeACLForServiceInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsBlackholeACLForServiceRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsBlackholeACLForServiceRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsBlackholeACLForServiceRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsBlackholeACLForServiceInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsBlackholeACLForServiceRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsBlackholeACLForServiceRepositoryExternal::createInstance(
   const Linux_DnsBlackholeACLForServiceRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsBlackholeACLForServiceInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsBlackholeACLForServiceRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsBlackholeACLForServiceRepositoryExternal::deleteInstance(
   const Linux_DnsBlackholeACLForServiceInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
