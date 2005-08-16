 /**
 * Linux_DnsAddressMatchListExternal.cpp
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
#include "Linux_DnsAddressMatchListExternal.h"

namespace genProvider{
	
  Linux_DnsAddressMatchListExternal::Linux_DnsAddressMatchListExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  Linux_DnsAddressMatchListExternal::
   ~Linux_DnsAddressMatchListExternal(){};
    
  void Linux_DnsAddressMatchListExternal::enumInstanceNames(
   const char *nsp,
   Linux_DnsAddressMatchListInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsAddressMatchList");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsAddressMatchListInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsAddressMatchListExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   Linux_DnsAddressMatchListInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsAddressMatchList");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsAddressMatchListInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsAddressMatchListInstance
   Linux_DnsAddressMatchListExternal::getInstance(
   const char* *properties,
   const Linux_DnsAddressMatchListInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsAddressMatchListInstance(inst,instanceName.getNamespace());
  }
      
  void Linux_DnsAddressMatchListExternal::setInstance(
   const char* *properties,
   const Linux_DnsAddressMatchListInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsAddressMatchListExternal::createInstance(
   const Linux_DnsAddressMatchListInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsAddressMatchListExternal::deleteInstance(
   const Linux_DnsAddressMatchListInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
    
}
