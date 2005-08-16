 /**
 * CIM_ConcreteJobExternal.cpp
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
#include "CIM_ConcreteJobExternal.h"

namespace genProvider{
	
  CIM_ConcreteJobExternal::CIM_ConcreteJobExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  CIM_ConcreteJobExternal::
   ~CIM_ConcreteJobExternal(){};
    
  void CIM_ConcreteJobExternal::enumInstanceNames(
   const char *nsp,
   CIM_ConcreteJobInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"CIM_ConcreteJob");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      CIM_ConcreteJobInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void CIM_ConcreteJobExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   CIM_ConcreteJobInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"CIM_ConcreteJob");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      CIM_ConcreteJobInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  CIM_ConcreteJobInstance
   CIM_ConcreteJobExternal::getInstance(
   const char* *properties,
   const CIM_ConcreteJobInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return CIM_ConcreteJobInstance(inst,instanceName.getNamespace());
  }
      
  void CIM_ConcreteJobExternal::setInstance(
   const char* *properties,
   const CIM_ConcreteJobInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void CIM_ConcreteJobExternal::createInstance(
   const CIM_ConcreteJobInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void CIM_ConcreteJobExternal::deleteInstance(
   const CIM_ConcreteJobInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
    
}
