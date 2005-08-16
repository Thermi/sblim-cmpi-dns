 /**
 * Linux_DnsMasterZoneRepositoryExternal.cpp
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
#include "Linux_DnsMasterZoneRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsMasterZoneRepositoryExternal::Linux_DnsMasterZoneRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsMasterZoneRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsMasterZoneRepositoryExternal::
   ~Linux_DnsMasterZoneRepositoryExternal(){};
    
  void Linux_DnsMasterZoneRepositoryExternal::enumInstanceNames(
   Linux_DnsMasterZoneInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsMasterZone");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsMasterZoneInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsMasterZoneRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsMasterZoneRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsMasterZone");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsMasterZoneRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsMasterZoneRepositoryInstance
   Linux_DnsMasterZoneRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsMasterZoneInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsMasterZoneRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsMasterZoneRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsMasterZoneRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsMasterZoneInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsMasterZoneRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsMasterZoneRepositoryExternal::createInstance(
   const Linux_DnsMasterZoneRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsMasterZoneInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsMasterZoneRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsMasterZoneRepositoryExternal::deleteInstance(
   const Linux_DnsMasterZoneInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
