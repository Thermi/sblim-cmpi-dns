 /**
 * Linux_DnsResourceRecordExternal.cpp
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
#include "Linux_DnsResourceRecordExternal.h"

namespace genProvider{
	
  Linux_DnsResourceRecordExternal::Linux_DnsResourceRecordExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  Linux_DnsResourceRecordExternal::
   ~Linux_DnsResourceRecordExternal(){};
    
  void Linux_DnsResourceRecordExternal::enumInstanceNames(
   const char *nsp,
   Linux_DnsResourceRecordInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsResourceRecord");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsResourceRecordInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsResourceRecordExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   Linux_DnsResourceRecordInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsResourceRecord");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsResourceRecordInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsResourceRecordInstance
   Linux_DnsResourceRecordExternal::getInstance(
   const char* *properties,
   const Linux_DnsResourceRecordInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsResourceRecordInstance(inst,instanceName.getNamespace());
  }
      
  void Linux_DnsResourceRecordExternal::setInstance(
   const char* *properties,
   const Linux_DnsResourceRecordInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsResourceRecordExternal::createInstance(
   const Linux_DnsResourceRecordInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsResourceRecordExternal::deleteInstance(
   const Linux_DnsResourceRecordInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
    
}
