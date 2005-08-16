 /**
 * Linux_DnsAllowNotifyACLForZoneExternal.cpp
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
#include "Linux_DnsAllowNotifyACLForZoneExternal.h"

namespace genProvider{
	
  Linux_DnsAllowNotifyACLForZoneExternal::Linux_DnsAllowNotifyACLForZoneExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  Linux_DnsAllowNotifyACLForZoneExternal::
   ~Linux_DnsAllowNotifyACLForZoneExternal(){};
    
  void Linux_DnsAllowNotifyACLForZoneExternal::enumInstanceNames(
   const char *nsp,
   Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsAllowNotifyACLForZone");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsAllowNotifyACLForZoneInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsAllowNotifyACLForZoneExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   Linux_DnsAllowNotifyACLForZoneInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsAllowNotifyACLForZone");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsAllowNotifyACLForZoneInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsAllowNotifyACLForZoneInstance
   Linux_DnsAllowNotifyACLForZoneExternal::getInstance(
   const char* *properties,
   const Linux_DnsAllowNotifyACLForZoneInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsAllowNotifyACLForZoneInstance(inst,instanceName.getNamespace());
  }
      
  void Linux_DnsAllowNotifyACLForZoneExternal::setInstance(
   const char* *properties,
   const Linux_DnsAllowNotifyACLForZoneInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsAllowNotifyACLForZoneExternal::createInstance(
   const Linux_DnsAllowNotifyACLForZoneInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsAllowNotifyACLForZoneExternal::deleteInstance(
   const Linux_DnsAllowNotifyACLForZoneInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
      
    //Reference calls
    
    void Linux_DnsAllowNotifyACLForZoneExternal::
     referencesElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsAllowNotifyACLForZoneInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsAddressMatchList",
        "Element", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsAllowNotifyACLForZoneInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsAllowNotifyACLForZoneExternal::
     referenceNamesElement( 
     const char *nsp,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsAddressMatchList",
        "Element");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsAllowNotifyACLForZoneInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }

    void Linux_DnsAllowNotifyACLForZoneExternal::
     referencesSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAllowNotifyACLForZoneInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsZone",
        "Setting", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsAllowNotifyACLForZoneInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsAllowNotifyACLForZoneExternal::
     referenceNamesSetting( 
     const char *nsp,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsZone",
        "Setting");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsAllowNotifyACLForZoneInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }
     
    //Associator calls

    void Linux_DnsAllowNotifyACLForZoneExternal::
     associatorsElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
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

    void Linux_DnsAllowNotifyACLForZoneExternal::
     associatorNamesElement( 
     const char *nsp,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
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

    void Linux_DnsAllowNotifyACLForZoneExternal::
     associatorsSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.associators
       (context,op,0,0,0,0,properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsAddressMatchListInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsAllowNotifyACLForZoneExternal::
     associatorNamesSetting( 
     const char *nsp,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.associatorNames
       (context,op,0,0,0,0);
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsAddressMatchListInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }

      
}
