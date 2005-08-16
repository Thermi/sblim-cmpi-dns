 /**
 * Linux_DnsRecursionACLForServiceExternal.cpp
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
#include "Linux_DnsRecursionACLForServiceExternal.h"

namespace genProvider{
	
  Linux_DnsRecursionACLForServiceExternal::Linux_DnsRecursionACLForServiceExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  Linux_DnsRecursionACLForServiceExternal::
   ~Linux_DnsRecursionACLForServiceExternal(){};
    
  void Linux_DnsRecursionACLForServiceExternal::enumInstanceNames(
   const char *nsp,
   Linux_DnsRecursionACLForServiceInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsRecursionACLForService");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsRecursionACLForServiceInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsRecursionACLForServiceExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   Linux_DnsRecursionACLForServiceInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsRecursionACLForService");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsRecursionACLForServiceInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsRecursionACLForServiceInstance
   Linux_DnsRecursionACLForServiceExternal::getInstance(
   const char* *properties,
   const Linux_DnsRecursionACLForServiceInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsRecursionACLForServiceInstance(inst,instanceName.getNamespace());
  }
      
  void Linux_DnsRecursionACLForServiceExternal::setInstance(
   const char* *properties,
   const Linux_DnsRecursionACLForServiceInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsRecursionACLForServiceExternal::createInstance(
   const Linux_DnsRecursionACLForServiceInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsRecursionACLForServiceExternal::deleteInstance(
   const Linux_DnsRecursionACLForServiceInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
      
    //Reference calls
    
    void Linux_DnsRecursionACLForServiceExternal::
     referencesElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsRecursionACLForServiceInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsAddressMatchList",
        "Element", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsRecursionACLForServiceInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsRecursionACLForServiceExternal::
     referenceNamesElement( 
     const char *nsp,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsRecursionACLForServiceInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsAddressMatchList",
        "Element");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsRecursionACLForServiceInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }

    void Linux_DnsRecursionACLForServiceExternal::
     referencesSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsRecursionACLForServiceInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsService",
        "Setting", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsRecursionACLForServiceInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsRecursionACLForServiceExternal::
     referenceNamesSetting( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsRecursionACLForServiceInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsService",
        "Setting");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsRecursionACLForServiceInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }
     
    //Associator calls

    void Linux_DnsRecursionACLForServiceExternal::
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

    void Linux_DnsRecursionACLForServiceExternal::
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

    void Linux_DnsRecursionACLForServiceExternal::
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

    void Linux_DnsRecursionACLForServiceExternal::
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
