 /**
 * CIM_CollectionOfMSEsExternal.cpp
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
#include "CIM_CollectionOfMSEsExternal.h"

namespace genProvider{
	
  CIM_CollectionOfMSEsExternal::CIM_CollectionOfMSEsExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  CIM_CollectionOfMSEsExternal::
   ~CIM_CollectionOfMSEsExternal(){};
    
  void CIM_CollectionOfMSEsExternal::enumInstanceNames(
   const char *nsp,
   CIM_CollectionOfMSEsInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"CIM_CollectionOfMSEs");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      CIM_CollectionOfMSEsInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void CIM_CollectionOfMSEsExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   CIM_CollectionOfMSEsInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"CIM_CollectionOfMSEs");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      CIM_CollectionOfMSEsInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  CIM_CollectionOfMSEsInstance
   CIM_CollectionOfMSEsExternal::getInstance(
   const char* *properties,
   const CIM_CollectionOfMSEsInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return CIM_CollectionOfMSEsInstance(inst,instanceName.getNamespace());
  }
      
  void CIM_CollectionOfMSEsExternal::setInstance(
   const char* *properties,
   const CIM_CollectionOfMSEsInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void CIM_CollectionOfMSEsExternal::createInstance(
   const CIM_CollectionOfMSEsInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void CIM_CollectionOfMSEsExternal::deleteInstance(
   const CIM_CollectionOfMSEsInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
    
}
