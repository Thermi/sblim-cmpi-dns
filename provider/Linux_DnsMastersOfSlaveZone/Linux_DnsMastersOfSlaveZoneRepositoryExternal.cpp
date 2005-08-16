 /**
 * Linux_DnsMastersOfSlaveZoneRepositoryExternal.cpp
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
#include "Linux_DnsMastersOfSlaveZoneRepositoryExternal.h"

namespace genProvider{
	
  Linux_DnsMastersOfSlaveZoneRepositoryExternal::Linux_DnsMastersOfSlaveZoneRepositoryExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
  
  const char * Linux_DnsMastersOfSlaveZoneRepositoryExternal::
   nsp="IBMShadow/cimv2";
   
  Linux_DnsMastersOfSlaveZoneRepositoryExternal::
   ~Linux_DnsMastersOfSlaveZoneRepositoryExternal(){};
    
  void Linux_DnsMastersOfSlaveZoneRepositoryExternal::enumInstanceNames(
   Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsMastersOfSlaveZone");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsMastersOfSlaveZoneInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsMastersOfSlaveZoneRepositoryExternal::enumInstances(
   const char* *properties,
   Linux_DnsMastersOfSlaveZoneRepositoryInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsMastersOfSlaveZone");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsMastersOfSlaveZoneRepositoryInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsMastersOfSlaveZoneRepositoryInstance
   Linux_DnsMastersOfSlaveZoneRepositoryExternal::getInstance(
   const char* *properties,
   const Linux_DnsMastersOfSlaveZoneInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsMastersOfSlaveZoneRepositoryInstance(inst,nsp);
  }
      
  void Linux_DnsMastersOfSlaveZoneRepositoryExternal::setInstance(
   const char* *properties,
   const Linux_DnsMastersOfSlaveZoneRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsMastersOfSlaveZoneInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsMastersOfSlaveZoneRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsMastersOfSlaveZoneRepositoryExternal::createInstance(
   const Linux_DnsMastersOfSlaveZoneRepositoryInstance& instance){
  
    //make a copy of the given instance and set it to the right nameSpace
    Linux_DnsMastersOfSlaveZoneInstanceName instanceName(instance.getInstanceName());
    instanceName.setNamespace(nsp,1);
    Linux_DnsMastersOfSlaveZoneRepositoryInstance copiedInstance(instance);
    copiedInstance.setInstanceName(instanceName);
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=copiedInstance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsMastersOfSlaveZoneRepositoryExternal::deleteInstance(
   const Linux_DnsMastersOfSlaveZoneInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    op.setNameSpace(nsp);
    broker.deleteInstance(context,op);
  }  
}
