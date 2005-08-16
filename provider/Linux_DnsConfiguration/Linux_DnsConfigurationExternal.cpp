 /**
 * Linux_DnsConfigurationExternal.cpp
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
#include "Linux_DnsConfigurationExternal.h"

namespace genProvider{
	
  Linux_DnsConfigurationExternal::Linux_DnsConfigurationExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  Linux_DnsConfigurationExternal::
   ~Linux_DnsConfigurationExternal(){};
    
  void Linux_DnsConfigurationExternal::enumInstanceNames(
   const char *nsp,
   Linux_DnsConfigurationInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsConfiguration");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsConfigurationInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsConfigurationExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   Linux_DnsConfigurationInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsConfiguration");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsConfigurationInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsConfigurationInstance
   Linux_DnsConfigurationExternal::getInstance(
   const char* *properties,
   const Linux_DnsConfigurationInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsConfigurationInstance(inst,instanceName.getNamespace());
  }
      
  void Linux_DnsConfigurationExternal::setInstance(
   const char* *properties,
   const Linux_DnsConfigurationInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsConfigurationExternal::createInstance(
   const Linux_DnsConfigurationInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsConfigurationExternal::deleteInstance(
   const Linux_DnsConfigurationInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
    
}
