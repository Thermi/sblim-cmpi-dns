 /**
 * Linux_DnsServiceConfigurationExternal.cpp
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
#include "Linux_DnsServiceConfigurationExternal.h"

namespace genProvider{
	
  Linux_DnsServiceConfigurationExternal::Linux_DnsServiceConfigurationExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  Linux_DnsServiceConfigurationExternal::
   ~Linux_DnsServiceConfigurationExternal(){};
    
  void Linux_DnsServiceConfigurationExternal::enumInstanceNames(
   const char *nsp,
   Linux_DnsServiceConfigurationInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsServiceConfiguration");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsServiceConfigurationInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsServiceConfigurationExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   Linux_DnsServiceConfigurationInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsServiceConfiguration");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsServiceConfigurationInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsServiceConfigurationInstance
   Linux_DnsServiceConfigurationExternal::getInstance(
   const char* *properties,
   const Linux_DnsServiceConfigurationInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsServiceConfigurationInstance(inst,instanceName.getNamespace());
  }
      
  void Linux_DnsServiceConfigurationExternal::setInstance(
   const char* *properties,
   const Linux_DnsServiceConfigurationInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsServiceConfigurationExternal::createInstance(
   const Linux_DnsServiceConfigurationInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsServiceConfigurationExternal::deleteInstance(
   const Linux_DnsServiceConfigurationInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
      
    //Reference calls
    
    void Linux_DnsServiceConfigurationExternal::
     referencesElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsServiceConfigurationInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsConfiguration",
        "Element", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsServiceConfigurationInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsServiceConfigurationExternal::
     referenceNamesElement( 
     const char *nsp,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsServiceConfigurationInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsConfiguration",
        "Element");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsServiceConfigurationInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }

    void Linux_DnsServiceConfigurationExternal::
     referencesConfiguration( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsServiceConfigurationInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsService",
        "Configuration", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsServiceConfigurationInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsServiceConfigurationExternal::
     referenceNamesConfiguration( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsServiceConfigurationInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsService",
        "Configuration");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsServiceConfigurationInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }
     
    //Associator calls

    void Linux_DnsServiceConfigurationExternal::
     associatorsElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
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

    void Linux_DnsServiceConfigurationExternal::
     associatorNamesElement( 
     const char *nsp,
     const Linux_DnsConfigurationInstanceName& sourceInst,
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

    void Linux_DnsServiceConfigurationExternal::
     associatorsConfiguration( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsConfigurationInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.associators
       (context,op,0,0,0,0,properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsConfigurationInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsServiceConfigurationExternal::
     associatorNamesConfiguration( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsConfigurationInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.associatorNames
       (context,op,0,0,0,0);
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsConfigurationInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }

      
}
