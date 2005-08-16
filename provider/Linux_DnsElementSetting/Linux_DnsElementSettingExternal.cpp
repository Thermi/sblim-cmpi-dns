 /**
 * Linux_DnsElementSettingExternal.cpp
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
#include "Linux_DnsElementSettingExternal.h"

namespace genProvider{
	
  Linux_DnsElementSettingExternal::Linux_DnsElementSettingExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  Linux_DnsElementSettingExternal::
   ~Linux_DnsElementSettingExternal(){};
    
  void Linux_DnsElementSettingExternal::enumInstanceNames(
   const char *nsp,
   Linux_DnsElementSettingInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsElementSetting");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsElementSettingInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsElementSettingExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   Linux_DnsElementSettingInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsElementSetting");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsElementSettingInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsElementSettingInstance
   Linux_DnsElementSettingExternal::getInstance(
   const char* *properties,
   const Linux_DnsElementSettingInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsElementSettingInstance(inst,instanceName.getNamespace());
  }
      
  void Linux_DnsElementSettingExternal::setInstance(
   const char* *properties,
   const Linux_DnsElementSettingInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsElementSettingExternal::createInstance(
   const Linux_DnsElementSettingInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsElementSettingExternal::deleteInstance(
   const Linux_DnsElementSettingInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
      
    //Reference calls
    
    void Linux_DnsElementSettingExternal::
     referencesElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsElementSettingInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsSetting",
        "Element", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsElementSettingInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsElementSettingExternal::
     referenceNamesElement( 
     const char *nsp,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsElementSettingInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsSetting",
        "Element");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsElementSettingInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }

    void Linux_DnsElementSettingExternal::
     referencesSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsElementSettingInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsService",
        "Setting", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsElementSettingInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsElementSettingExternal::
     referenceNamesSetting( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsElementSettingInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsService",
        "Setting");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsElementSettingInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }
     
    //Associator calls

    void Linux_DnsElementSettingExternal::
     associatorsElement( 
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
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

    void Linux_DnsElementSettingExternal::
     associatorNamesElement( 
     const char *nsp,
     const Linux_DnsSettingInstanceName& sourceInst,
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

    void Linux_DnsElementSettingExternal::
     associatorsSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsSettingInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.associators
       (context,op,0,0,0,0,properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsSettingInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsElementSettingExternal::
     associatorNamesSetting( 
     const char *nsp,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsSettingInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.associatorNames
       (context,op,0,0,0,0);
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsSettingInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }

      
}
