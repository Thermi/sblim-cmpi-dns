 /**
 * CIM_ManagedSystemElementExternal.cpp
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
#include "CIM_ManagedSystemElementExternal.h"

namespace genProvider{
	
  CIM_ManagedSystemElementExternal::CIM_ManagedSystemElementExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  CIM_ManagedSystemElementExternal::
   ~CIM_ManagedSystemElementExternal(){};
    
  void CIM_ManagedSystemElementExternal::enumInstanceNames(
   const char *nsp,
   CIM_ManagedSystemElementInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"CIM_ManagedSystemElement");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      CIM_ManagedSystemElementInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void CIM_ManagedSystemElementExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   CIM_ManagedSystemElementInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"CIM_ManagedSystemElement");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      CIM_ManagedSystemElementInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  CIM_ManagedSystemElementInstance
   CIM_ManagedSystemElementExternal::getInstance(
   const char* *properties,
   const CIM_ManagedSystemElementInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return CIM_ManagedSystemElementInstance(inst,instanceName.getNamespace());
  }
      
  void CIM_ManagedSystemElementExternal::setInstance(
   const char* *properties,
   const CIM_ManagedSystemElementInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void CIM_ManagedSystemElementExternal::createInstance(
   const CIM_ManagedSystemElementInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void CIM_ManagedSystemElementExternal::deleteInstance(
   const CIM_ManagedSystemElementInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
    
}
