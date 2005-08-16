 /**
 * Linux_DnsConfigurationRepositoryExternal.cpp
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
#include "Linux_DnsConfigurationRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsConfigurationRepositoryExternal::Linux_DnsConfigurationRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsConfigurationRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsConfigurationRepositoryExternal::
   ~Linux_DnsConfigurationRepositoryExternal(){};
    
  void Linux_DnsConfigurationRepositoryExternal::enumInstanceNames(
   Linux_DnsConfigurationInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsConfiguration");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsConfigurationInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsConfigurationRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsConfigurationRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsConfiguration");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsConfigurationRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsConfigurationRepositoryInstance
   Linux_DnsConfigurationRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsConfigurationInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsConfigurationRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsConfigurationRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsConfigurationRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsConfigurationInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsConfigurationRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsConfigurationRepositoryExternal::createInstance(
   const Linux_DnsConfigurationRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsConfigurationInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsConfigurationRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsConfigurationRepositoryExternal::deleteInstance(
   const Linux_DnsConfigurationInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
