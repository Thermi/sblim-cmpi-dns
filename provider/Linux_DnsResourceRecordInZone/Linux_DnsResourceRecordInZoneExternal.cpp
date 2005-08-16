 /**
 * Linux_DnsResourceRecordInZoneExternal.cpp
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
#include "Linux_DnsResourceRecordInZoneExternal.h"

namespace genProvider{
	
  Linux_DnsResourceRecordInZoneExternal::Linux_DnsResourceRecordInZoneExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  Linux_DnsResourceRecordInZoneExternal::
   ~Linux_DnsResourceRecordInZoneExternal(){};
    
  void Linux_DnsResourceRecordInZoneExternal::enumInstanceNames(
   const char *nsp,
   Linux_DnsResourceRecordInZoneInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsResourceRecordInZone");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsResourceRecordInZoneInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsResourceRecordInZoneExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   Linux_DnsResourceRecordInZoneInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsResourceRecordInZone");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsResourceRecordInZoneInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsResourceRecordInZoneInstance
   Linux_DnsResourceRecordInZoneExternal::getInstance(
   const char* *properties,
   const Linux_DnsResourceRecordInZoneInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsResourceRecordInZoneInstance(inst,instanceName.getNamespace());
  }
      
  void Linux_DnsResourceRecordInZoneExternal::setInstance(
   const char* *properties,
   const Linux_DnsResourceRecordInZoneInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsResourceRecordInZoneExternal::createInstance(
   const Linux_DnsResourceRecordInZoneInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsResourceRecordInZoneExternal::deleteInstance(
   const Linux_DnsResourceRecordInZoneInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
      
    //Reference calls
    
    void Linux_DnsResourceRecordInZoneExternal::
     referencesGroupComponent( 
     const char *nsp,
     const char** properties,
     const Linux_DnsResourceRecordInstanceName& sourceInst,
     Linux_DnsResourceRecordInZoneInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsResourceRecord",
        "GroupComponent", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsResourceRecordInZoneInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsResourceRecordInZoneExternal::
     referenceNamesGroupComponent( 
     const char *nsp,
     const Linux_DnsResourceRecordInstanceName& sourceInst,
     Linux_DnsResourceRecordInZoneInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsResourceRecord",
        "GroupComponent");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsResourceRecordInZoneInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }

    void Linux_DnsResourceRecordInZoneExternal::
     referencesPartComponent( 
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsResourceRecordInZoneInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsZone",
        "PartComponent", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsResourceRecordInZoneInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsResourceRecordInZoneExternal::
     referenceNamesPartComponent( 
     const char *nsp,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsResourceRecordInZoneInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsZone",
        "PartComponent");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsResourceRecordInZoneInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }
     
    //Associator calls

    void Linux_DnsResourceRecordInZoneExternal::
     associatorsGroupComponent( 
     const char *nsp,
     const char** properties,
     const Linux_DnsResourceRecordInstanceName& sourceInst,
     Linux_DnsZoneInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.associators
       (context,op,0,0,0,0,properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsZoneInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsResourceRecordInZoneExternal::
     associatorNamesGroupComponent( 
     const char *nsp,
     const Linux_DnsResourceRecordInstanceName& sourceInst,
     Linux_DnsZoneInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.associatorNames
       (context,op,0,0,0,0);
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsZoneInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }

    void Linux_DnsResourceRecordInZoneExternal::
     associatorsPartComponent( 
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsResourceRecordInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.associators
       (context,op,0,0,0,0,properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsResourceRecordInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsResourceRecordInZoneExternal::
     associatorNamesPartComponent( 
     const char *nsp,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsResourceRecordInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.associatorNames
       (context,op,0,0,0,0);
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsResourceRecordInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }

      
}
