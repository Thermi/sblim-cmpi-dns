 /**
 * Linux_DnsSettingExternal.cpp
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
#include "Linux_DnsSettingExternal.h"

namespace genProvider{
	
  Linux_DnsSettingExternal::Linux_DnsSettingExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  Linux_DnsSettingExternal::
   ~Linux_DnsSettingExternal(){};
    
  void Linux_DnsSettingExternal::enumInstanceNames(
   const char *nsp,
   Linux_DnsSettingInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsSetting");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsSettingInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsSettingExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   Linux_DnsSettingInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsSetting");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsSettingInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsSettingInstance
   Linux_DnsSettingExternal::getInstance(
   const char* *properties,
   const Linux_DnsSettingInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsSettingInstance(inst,instanceName.getNamespace());
  }
      
  void Linux_DnsSettingExternal::setInstance(
   const char* *properties,
   const Linux_DnsSettingInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsSettingExternal::createInstance(
   const Linux_DnsSettingInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsSettingExternal::deleteInstance(
   const Linux_DnsSettingInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
    
}
