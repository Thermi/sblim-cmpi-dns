 /**
 * Linux_DnsElementSettingRepositoryExternal.cpp
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
#include "Linux_DnsElementSettingRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsElementSettingRepositoryExternal::Linux_DnsElementSettingRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsElementSettingRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsElementSettingRepositoryExternal::
   ~Linux_DnsElementSettingRepositoryExternal(){};
    
  void Linux_DnsElementSettingRepositoryExternal::enumInstanceNames(
   Linux_DnsElementSettingInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsElementSetting");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsElementSettingInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsElementSettingRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsElementSettingRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsElementSetting");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsElementSettingRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsElementSettingRepositoryInstance
   Linux_DnsElementSettingRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsElementSettingInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsElementSettingRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsElementSettingRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsElementSettingRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsElementSettingInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsElementSettingRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsElementSettingRepositoryExternal::createInstance(
   const Linux_DnsElementSettingRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsElementSettingInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsElementSettingRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsElementSettingRepositoryExternal::deleteInstance(
   const Linux_DnsElementSettingInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
