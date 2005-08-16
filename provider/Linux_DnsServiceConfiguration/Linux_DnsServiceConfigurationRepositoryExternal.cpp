 /**
 * Linux_DnsServiceConfigurationRepositoryExternal.cpp
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
#include "Linux_DnsServiceConfigurationRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsServiceConfigurationRepositoryExternal::Linux_DnsServiceConfigurationRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsServiceConfigurationRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsServiceConfigurationRepositoryExternal::
   ~Linux_DnsServiceConfigurationRepositoryExternal(){};
    
  void Linux_DnsServiceConfigurationRepositoryExternal::enumInstanceNames(
   Linux_DnsServiceConfigurationInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsServiceConfiguration");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsServiceConfigurationInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsServiceConfigurationRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsServiceConfigurationRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsServiceConfiguration");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsServiceConfigurationRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsServiceConfigurationRepositoryInstance
   Linux_DnsServiceConfigurationRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsServiceConfigurationInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsServiceConfigurationRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsServiceConfigurationRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsServiceConfigurationRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsServiceConfigurationInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsServiceConfigurationRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsServiceConfigurationRepositoryExternal::createInstance(
   const Linux_DnsServiceConfigurationRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsServiceConfigurationInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsServiceConfigurationRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsServiceConfigurationRepositoryExternal::deleteInstance(
   const Linux_DnsServiceConfigurationInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
