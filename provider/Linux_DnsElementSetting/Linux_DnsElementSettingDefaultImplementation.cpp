 /**
 * Linux_DnsElementSettingDefaultImplementation.cpp
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
#include "Linux_DnsElementSettingDefaultImplementation.h"
#include <iostream>

using namespace std;

namespace genProvider {

  /* intrinsic methods */
  void Linux_DnsElementSettingDefaultImplementation::enumInstanceNames(
   const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
   Linux_DnsElementSettingInstanceNameEnumeration& instnames){
   	cout<<"enumInstances not supported for Linux_DnsElementSetting"<<endl;
   	throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "enumInstances not implemented for Linux_DnsElementSetting");   
  }
  	
  void Linux_DnsElementSettingDefaultImplementation::enumInstances(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char *nsp,
   const char* *properties,
   Linux_DnsElementSettingManualInstanceEnumeration& instances){
    
    cout<<"Using default enumInstances implementation for Linux_DnsElementSetting"<<endl;
    cout<<"LetŽs get the instanceNames"<<endl;
    Linux_DnsElementSettingInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(ctx, mbp,nsp,namesEnumeration);
    cout<<"Getting each instance"<<endl;
    while(namesEnumeration.hasNext()){
      Linux_DnsElementSettingInstanceName name=
    	  namesEnumeration.getNext();
    	cout<<"Getting an instance for instanceName"<<endl;
    	Linux_DnsElementSettingManualInstance instance=
    	  getInstance(ctx, mbp, properties, name);
    	cout<<"adding instance to enum"<<endl;
    	instances.addElement(instance);
    	cout<<"Added!"<<endl;
    };
  }
  	
  Linux_DnsElementSettingManualInstance 
   Linux_DnsElementSettingDefaultImplementation::getInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsElementSettingInstanceName&){
    cout<<"getInstance not supported for Linux_DnsElementSetting"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "getInstance not implemented for Linux_DnsElementSetting");
  }
  	
  void Linux_DnsElementSettingDefaultImplementation::setInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsElementSettingManualInstance&){
   	cout<<"setInstance not supported for Linux_DnsElementSetting"<<endl;
     throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "setInstance not implemented for Linux_DnsElementSetting");
  }
  	
  void Linux_DnsElementSettingDefaultImplementation::
   createInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsElementSettingManualInstance&){
   	cout<<"createInstance not supported for Linux_DnsElementSetting"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "createInstance not implemented for Linux_DnsElementSetting");
  }
  	
  void Linux_DnsElementSettingDefaultImplementation::
   deleteInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsElementSettingInstanceName&){
   	cout<<"deleteInstance not supported for Linux_DnsElementSetting"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "deleteInstance not implemented for Linux_DnsElementSetting");
  }
	
  
    /* Association Interface */

    void Linux_DnsElementSettingDefaultImplementation::
     referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsElementSettingManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getElementReferences between Linux_DnsService and Linux_DnsSetting not implemented for Linux_DnsElementSetting");
    }

    void Linux_DnsElementSettingDefaultImplementation::
     referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsElementSettingManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getSettingReferences between Linux_DnsService and Linux_DnsSetting not implemented for Linux_DnsElementSetting");
    }

    void Linux_DnsElementSettingDefaultImplementation::
     associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsServiceInstanceEnumeration& instances){
      
      std::cout<<"Linux_DnsElementSetting : associatorsLinux_DnsService() ... returns one instance"<<std::endl;
      
      Linux_DnsElementSettingManualInstanceEnumeration enumeration;
      
      referencesElement(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsServiceExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsElementSettingManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsElementSettingInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsServiceInstanceName Element = 
         instanceName.getElement();
         
        Linux_DnsServiceInstance inst = external.getInstance(properties,Element);
        
        instances.addElement(inst);
      }
    }

    void Linux_DnsElementSettingDefaultImplementation::
     associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsSettingInstanceEnumeration& instances){
     
      std::cout<<"Linux_DnsElementSetting : associatorsLinux_DnsSetting() ... returns one instance"<<std::endl;
      
      Linux_DnsElementSettingManualInstanceEnumeration enumeration;
      
      referencesSetting(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsSettingExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsElementSettingManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsElementSettingInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsSettingInstanceName Setting = 
         instanceName.getSetting();
         
        Linux_DnsSettingInstance inst = external.getInstance(properties,Setting);
        
        instances.addElement(inst);
      }
    }

   
  /* extrinsic methods */
	
}

