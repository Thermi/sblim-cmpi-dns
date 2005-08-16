 /**
 * Linux_DnsForwardZoneExternal.cpp
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
#include "Linux_DnsForwardZoneExternal.h"

namespace genProvider{
	
  Linux_DnsForwardZoneExternal::Linux_DnsForwardZoneExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  Linux_DnsForwardZoneExternal::
   ~Linux_DnsForwardZoneExternal(){};
    
  void Linux_DnsForwardZoneExternal::enumInstanceNames(
   const char *nsp,
   Linux_DnsForwardZoneInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsForwardZone");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsForwardZoneInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsForwardZoneExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   Linux_DnsForwardZoneInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsForwardZone");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsForwardZoneInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsForwardZoneInstance
   Linux_DnsForwardZoneExternal::getInstance(
   const char* *properties,
   const Linux_DnsForwardZoneInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsForwardZoneInstance(inst,instanceName.getNamespace());
  }
      
  void Linux_DnsForwardZoneExternal::setInstance(
   const char* *properties,
   const Linux_DnsForwardZoneInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsForwardZoneExternal::createInstance(
   const Linux_DnsForwardZoneInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsForwardZoneExternal::deleteInstance(
   const Linux_DnsForwardZoneInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
    
}
