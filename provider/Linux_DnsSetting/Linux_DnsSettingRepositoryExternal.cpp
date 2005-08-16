 /**
 * Linux_DnsSettingRepositoryExternal.cpp
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
#include "Linux_DnsSettingRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsSettingRepositoryExternal::Linux_DnsSettingRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsSettingRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsSettingRepositoryExternal::
   ~Linux_DnsSettingRepositoryExternal(){};
    
  void Linux_DnsSettingRepositoryExternal::enumInstanceNames(
   Linux_DnsSettingInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsSetting");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsSettingInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsSettingRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsSettingRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsSetting");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsSettingRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsSettingRepositoryInstance
   Linux_DnsSettingRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsSettingInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsSettingRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsSettingRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsSettingRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsSettingInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsSettingRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsSettingRepositoryExternal::createInstance(
   const Linux_DnsSettingRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsSettingInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsSettingRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsSettingRepositoryExternal::deleteInstance(
   const Linux_DnsSettingInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
