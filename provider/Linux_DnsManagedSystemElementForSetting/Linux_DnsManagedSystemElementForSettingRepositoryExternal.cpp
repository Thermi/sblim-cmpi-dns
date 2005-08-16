 /**
 * Linux_DnsManagedSystemElementForSettingRepositoryExternal.cpp
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
#include "Linux_DnsManagedSystemElementForSettingRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsManagedSystemElementForSettingRepositoryExternal::Linux_DnsManagedSystemElementForSettingRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsManagedSystemElementForSettingRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsManagedSystemElementForSettingRepositoryExternal::
   ~Linux_DnsManagedSystemElementForSettingRepositoryExternal(){};
    
  void Linux_DnsManagedSystemElementForSettingRepositoryExternal::enumInstanceNames(
   Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsManagedSystemElementForSetting");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsManagedSystemElementForSettingInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsManagedSystemElementForSettingRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsManagedSystemElementForSettingRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsManagedSystemElementForSetting");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsManagedSystemElementForSettingRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsManagedSystemElementForSettingRepositoryInstance
   Linux_DnsManagedSystemElementForSettingRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsManagedSystemElementForSettingInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsManagedSystemElementForSettingRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsManagedSystemElementForSettingRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsManagedSystemElementForSettingRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsManagedSystemElementForSettingInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsManagedSystemElementForSettingRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsManagedSystemElementForSettingRepositoryExternal::createInstance(
   const Linux_DnsManagedSystemElementForSettingRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsManagedSystemElementForSettingInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsManagedSystemElementForSettingRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsManagedSystemElementForSettingRepositoryExternal::deleteInstance(
   const Linux_DnsManagedSystemElementForSettingInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
