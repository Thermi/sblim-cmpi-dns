 /**
 * Linux_DnsNotifyACLForServiceExternal.cpp
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
#include "Linux_DnsNotifyACLForServiceExternal.h"

namespace genProvider{
	
  Linux_DnsNotifyACLForServiceExternal::Linux_DnsNotifyACLForServiceExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  Linux_DnsNotifyACLForServiceExternal::
   ~Linux_DnsNotifyACLForServiceExternal(){};
    
  void Linux_DnsNotifyACLForServiceExternal::enumInstanceNames(
   const char *nsp,
   Linux_DnsNotifyACLForServiceInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsNotifyACLForService");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsNotifyACLForServiceInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsNotifyACLForServiceExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   Linux_DnsNotifyACLForServiceInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsNotifyACLForService");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsNotifyACLForServiceInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsNotifyACLForServiceInstance
   Linux_DnsNotifyACLForServiceExternal::getInstance(
   const char* *properties,
   const Linux_DnsNotifyACLForServiceInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsNotifyACLForServiceInstance(inst,instanceName.getNamespace());
  }
      
  void Linux_DnsNotifyACLForServiceExternal::setInstance(
   const char* *properties,
   const Linux_DnsNotifyACLForServiceInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsNotifyACLForServiceExternal::createInstance(
   const Linux_DnsNotifyACLForServiceInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsNotifyACLForServiceExternal::deleteInstance(
   const Linux_DnsNotifyACLForServiceInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
      
    //Reference calls
    
    void Linux_DnsNotifyACLForServiceExternal::
     referencesElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsNotifyACLForServiceInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsAddressMatchList",
        "Element", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsNotifyACLForServiceInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsNotifyACLForServiceExternal::
     referenceNamesElement( 
     const char *nsp,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsNotifyACLForServiceInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsAddressMatchList",
        "Element");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsNotifyACLForServiceInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }

    void Linux_DnsNotifyACLForServiceExternal::
     referencesSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsNotifyACLForServiceInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsService",
        "Setting", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsNotifyACLForServiceInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsNotifyACLForServiceExternal::
     referenceNamesSetting( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsNotifyACLForServiceInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsService",
        "Setting");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsNotifyACLForServiceInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }
     
    //Associator calls

    void Linux_DnsNotifyACLForServiceExternal::
     associatorsElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsServiceInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.associators
       (context,op,0,0,0,0,properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsServiceInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsNotifyACLForServiceExternal::
     associatorNamesElement( 
     const char *nsp,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsServiceInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.associatorNames
       (context,op,0,0,0,0);
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsServiceInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }

    void Linux_DnsNotifyACLForServiceExternal::
     associatorsSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
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

    void Linux_DnsNotifyACLForServiceExternal::
     associatorNamesSetting( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
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
