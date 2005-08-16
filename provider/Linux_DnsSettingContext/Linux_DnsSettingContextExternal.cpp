 /**
 * Linux_DnsSettingContextExternal.cpp
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
#include "Linux_DnsSettingContextExternal.h"

namespace genProvider{
	
  Linux_DnsSettingContextExternal::Linux_DnsSettingContextExternal(
   const CmpiBroker& brkr, const CmpiContext& ctx ) 
   : broker(brkr), context(ctx) {};
   
  Linux_DnsSettingContextExternal::
   ~Linux_DnsSettingContextExternal(){};
    
  void Linux_DnsSettingContextExternal::enumInstanceNames(
   const char *nsp,
   Linux_DnsSettingContextInstanceNameEnumeration& instnames) {

    CmpiObjectPath op(nsp,"Linux_DnsSettingContext");
    CmpiEnumeration en=broker.enumInstanceNames(context,op);
    while(en.hasNext()) {
      CmpiObjectPath opi = en.getNext();
      Linux_DnsSettingContextInstanceName iname(opi);
      instnames.addElement(iname);
    }
  };
  	  
  void Linux_DnsSettingContextExternal::enumInstances(
   const char *nsp,
   const char* *properties,
   Linux_DnsSettingContextInstanceEnumeration& instances) {
   		
    CmpiObjectPath op(nsp,"Linux_DnsSettingContext");
    CmpiEnumeration en=broker.enumInstances(context,op,properties);
    while(en.hasNext()) {
      CmpiInstance inst = en.getNext();
      Linux_DnsSettingContextInstance instance(inst,nsp);
      instances.addElement(instance);
    }
  };
  	  
  Linux_DnsSettingContextInstance
   Linux_DnsSettingContextExternal::getInstance(
   const char* *properties,
   const Linux_DnsSettingContextInstanceName& instanceName) {
    
    CmpiObjectPath op=instanceName.getObjectPath();
    CmpiInstance inst=broker.getInstance(context,op,properties);
    return Linux_DnsSettingContextInstance(inst,instanceName.getNamespace());
  }
      
  void Linux_DnsSettingContextExternal::setInstance(
   const char* *properties,
   const Linux_DnsSettingContextInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.setInstance(context,op,inst,properties);
  }
      
  void Linux_DnsSettingContextExternal::createInstance(
   const Linux_DnsSettingContextInstance& instance){
  
    CmpiObjectPath op=instance.getInstanceName().getObjectPath();
    CmpiInstance inst=instance.getCmpiInstance();
    broker.createInstance(context,op,inst);
  }
  
  void Linux_DnsSettingContextExternal::deleteInstance(
   const Linux_DnsSettingContextInstanceName& instanceName){
    
    CmpiObjectPath op=instanceName.getObjectPath();
    broker.deleteInstance(context,op);
  }
      
    //Reference calls
    
    void Linux_DnsSettingContextExternal::
     referencesContext( 
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsSettingContextInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsSetting",
        "Context", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsSettingContextInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsSettingContextExternal::
     referenceNamesContext( 
     const char *nsp,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsSettingContextInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsSetting",
        "Context");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsSettingContextInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }

    void Linux_DnsSettingContextExternal::
     referencesSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsSettingContextInstanceEnumeration& instances){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.references
       (context, op, "Linux_DnsConfiguration",
        "Setting", properties);
      while(en.hasNext()) {
        CmpiInstance inst = en.getNext();
        Linux_DnsSettingContextInstance instance(inst,nsp);
        instances.addElement(instance);
      }      
    }

    void Linux_DnsSettingContextExternal::
     referenceNamesSetting( 
     const char *nsp,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsSettingContextInstanceNameEnumeration& instanceNames){
      
      CmpiObjectPath op=sourceInst.getObjectPath();
      CmpiEnumeration en=broker.referenceNames
       (context, op, "Linux_DnsConfiguration",
        "Setting");
      while(en.hasNext()) {
        CmpiObjectPath instName = en.getNext();
        Linux_DnsSettingContextInstanceName instanceName(instName);
        instanceNames.addElement(instanceName);
      }      
    }
     
    //Associator calls

    void Linux_DnsSettingContextExternal::
     associatorsContext( 
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
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

    void Linux_DnsSettingContextExternal::
     associatorNamesContext( 
     const char *nsp,
     const Linux_DnsSettingInstanceName& sourceInst,
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

    void Linux_DnsSettingContextExternal::
     associatorsSetting( 
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
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

    void Linux_DnsSettingContextExternal::
     associatorNamesSetting( 
     const char *nsp,
     const Linux_DnsConfigurationInstanceName& sourceInst,
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
