 /**
 * Linux_DnsSlaveZoneExternal.cpp
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
#include "Linux_DnsSlaveZoneExternal.h"

namespace genProvider{
	
  Linux_DnsSlaveZoneExternal::Linux_DnsSlaveZoneExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  Linux_DnsSlaveZoneExternal::
   ~Linux_DnsSlaveZoneExternal(){};
    
  void Linux_DnsSlaveZoneExternal::enumInstanceNames(
   const char *nsp,
   Linux_DnsSlaveZoneInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsSlaveZone");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsSlaveZoneInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsSlaveZoneExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   Linux_DnsSlaveZoneInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsSlaveZone");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsSlaveZoneInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsSlaveZoneInstance
   Linux_DnsSlaveZoneExternal::getInstance(
   const char* *properties,
   const Linux_DnsSlaveZoneInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsSlaveZoneInstance(inst,instanceName.getNamespace());
  }
      
  void Linux_DnsSlaveZoneExternal::setInstance(
   const char* *properties,
   const Linux_DnsSlaveZoneInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsSlaveZoneExternal::createInstance(
   const Linux_DnsSlaveZoneInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsSlaveZoneExternal::deleteInstance(
   const Linux_DnsSlaveZoneInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
    
}
