 /**
 * Linux_DnsTransferACLForServiceExternal.cpp
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
#include "Linux_DnsTransferACLForServiceExternal.h"

namespace genProvider{
	
  Linux_DnsTransferACLForServiceExternal::Linux_DnsTransferACLForServiceExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  Linux_DnsTransferACLForServiceExternal::
   ~Linux_DnsTransferACLForServiceExternal(){};
    
  void Linux_DnsTransferACLForServiceExternal::enumInstanceNames(
   const char *nsp,
   Linux_DnsTransferACLForServiceInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsTransferACLForService");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsTransferACLForServiceInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsTransferACLForServiceExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   Linux_DnsTransferACLForServiceInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsTransferACLForService");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsTransferACLForServiceInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsTransferACLForServiceInstance
   Linux_DnsTransferACLForServiceExternal::getInstance(
   const char* *properties,
   const Linux_DnsTransferACLForServiceInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsTransferACLForServiceInstance(inst,instanceName.getNamespace());
  }
      
  void Linux_DnsTransferACLForServiceExternal::setInstance(
   const char* *properties,
   const Linux_DnsTransferACLForServiceInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsTransferACLForServiceExternal::createInstance(
   const Linux_DnsTransferACLForServiceInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsTransferACLForServiceExternal::deleteInstance(
   const Linux_DnsTransferACLForServiceInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
      
    //Reference calls
    
    void Linux_DnsTransferACLForServiceExternal::
     referencesElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsTransferACLForServiceInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsAddressMatchList",
        "Element", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsTransferACLForServiceInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsTransferACLForServiceExternal::
     referenceNamesElement( 
     const char *nsp,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsTransferACLForServiceInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsAddressMatchList",
        "Element");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsTransferACLForServiceInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }

    void Linux_DnsTransferACLForServiceExternal::
     referencesSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsTransferACLForServiceInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsService",
        "Setting", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsTransferACLForServiceInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsTransferACLForServiceExternal::
     referenceNamesSetting( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsTransferACLForServiceInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsService",
        "Setting");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsTransferACLForServiceInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }
     
    //Associator calls

    void Linux_DnsTransferACLForServiceExternal::
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

    void Linux_DnsTransferACLForServiceExternal::
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

    void Linux_DnsTransferACLForServiceExternal::
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

    void Linux_DnsTransferACLForServiceExternal::
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