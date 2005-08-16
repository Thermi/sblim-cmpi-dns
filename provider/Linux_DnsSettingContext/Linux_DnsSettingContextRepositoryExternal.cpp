 /**
 * Linux_DnsSettingContextRepositoryExternal.cpp
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
#include "Linux_DnsSettingContextRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsSettingContextRepositoryExternal::Linux_DnsSettingContextRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsSettingContextRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsSettingContextRepositoryExternal::
   ~Linux_DnsSettingContextRepositoryExternal(){};
    
  void Linux_DnsSettingContextRepositoryExternal::enumInstanceNames(
   Linux_DnsSettingContextInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsSettingContext");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsSettingContextInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsSettingContextRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsSettingContextRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsSettingContext");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsSettingContextRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsSettingContextRepositoryInstance
   Linux_DnsSettingContextRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsSettingContextInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsSettingContextRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsSettingContextRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsSettingContextRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsSettingContextInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsSettingContextRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsSettingContextRepositoryExternal::createInstance(
   const Linux_DnsSettingContextRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsSettingContextInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsSettingContextRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsSettingContextRepositoryExternal::deleteInstance(
   const Linux_DnsSettingContextInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
