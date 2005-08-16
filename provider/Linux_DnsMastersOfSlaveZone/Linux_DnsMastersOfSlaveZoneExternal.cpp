 /**
 * Linux_DnsMastersOfSlaveZoneExternal.cpp
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
#include "Linux_DnsMastersOfSlaveZoneExternal.h"

namespace genProvider{
	
  Linux_DnsMastersOfSlaveZoneExternal::Linux_DnsMastersOfSlaveZoneExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  Linux_DnsMastersOfSlaveZoneExternal::
   ~Linux_DnsMastersOfSlaveZoneExternal(){};
    
  void Linux_DnsMastersOfSlaveZoneExternal::enumInstanceNames(
   const char *nsp,
   Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsMastersOfSlaveZone");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsMastersOfSlaveZoneInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsMastersOfSlaveZoneExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   Linux_DnsMastersOfSlaveZoneInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsMastersOfSlaveZone");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsMastersOfSlaveZoneInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsMastersOfSlaveZoneInstance
   Linux_DnsMastersOfSlaveZoneExternal::getInstance(
   const char* *properties,
   const Linux_DnsMastersOfSlaveZoneInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsMastersOfSlaveZoneInstance(inst,instanceName.getNamespace());
  }
      
  void Linux_DnsMastersOfSlaveZoneExternal::setInstance(
   const char* *properties,
   const Linux_DnsMastersOfSlaveZoneInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsMastersOfSlaveZoneExternal::createInstance(
   const Linux_DnsMastersOfSlaveZoneInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsMastersOfSlaveZoneExternal::deleteInstance(
   const Linux_DnsMastersOfSlaveZoneInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
      
    //Reference calls
    
    void Linux_DnsMastersOfSlaveZoneExternal::
     referencesElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsIPAddressInstanceName& sourceInst,
     Linux_DnsMastersOfSlaveZoneInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsIPAddress",
        "Element", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsMastersOfSlaveZoneInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsMastersOfSlaveZoneExternal::
     referenceNamesElement( 
     const char *nsp,
     const Linux_DnsIPAddressInstanceName& sourceInst,
     Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsIPAddress",
        "Element");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsMastersOfSlaveZoneInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }

    void Linux_DnsMastersOfSlaveZoneExternal::
     referencesSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsSlaveZoneInstanceName& sourceInst,
     Linux_DnsMastersOfSlaveZoneInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsSlaveZone",
        "Setting", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsMastersOfSlaveZoneInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsMastersOfSlaveZoneExternal::
     referenceNamesSetting( 
     const char *nsp,
     const Linux_DnsSlaveZoneInstanceName& sourceInst,
     Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsSlaveZone",
        "Setting");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsMastersOfSlaveZoneInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }
     
    //Associator calls

    void Linux_DnsMastersOfSlaveZoneExternal::
     associatorsElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsIPAddressInstanceName& sourceInst,
     Linux_DnsSlaveZoneInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.associators
       (context,op,0,0,0,0,properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsSlaveZoneInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsMastersOfSlaveZoneExternal::
     associatorNamesElement( 
     const char *nsp,
     const Linux_DnsIPAddressInstanceName& sourceInst,
     Linux_DnsSlaveZoneInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.associatorNames
       (context,op,0,0,0,0);
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsSlaveZoneInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }

    void Linux_DnsMastersOfSlaveZoneExternal::
     associatorsSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsSlaveZoneInstanceName& sourceInst,
     Linux_DnsIPAddressInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.associators
       (context,op,0,0,0,0,properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsIPAddressInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsMastersOfSlaveZoneExternal::
     associatorNamesSetting( 
     const char *nsp,
     const Linux_DnsSlaveZoneInstanceName& sourceInst,
     Linux_DnsIPAddressInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.associatorNames
       (context,op,0,0,0,0);
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsIPAddressInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }

      
}
