 /**
 * Linux_DnsIPAddressExternal.cpp
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
#include "Linux_DnsIPAddressExternal.h"

namespace genProvider{
	
  Linux_DnsIPAddressExternal::Linux_DnsIPAddressExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  Linux_DnsIPAddressExternal::
   ~Linux_DnsIPAddressExternal(){};
    
  void Linux_DnsIPAddressExternal::enumInstanceNames(
   const char *nsp,
   Linux_DnsIPAddressInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsIPAddress");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsIPAddressInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsIPAddressExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   Linux_DnsIPAddressInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsIPAddress");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsIPAddressInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsIPAddressInstance
   Linux_DnsIPAddressExternal::getInstance(
   const char* *properties,
   const Linux_DnsIPAddressInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsIPAddressInstance(inst,instanceName.getNamespace());
  }
      
  void Linux_DnsIPAddressExternal::setInstance(
   const char* *properties,
   const Linux_DnsIPAddressInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsIPAddressExternal::createInstance(
   const Linux_DnsIPAddressInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsIPAddressExternal::deleteInstance(
   const Linux_DnsIPAddressInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
    
}
