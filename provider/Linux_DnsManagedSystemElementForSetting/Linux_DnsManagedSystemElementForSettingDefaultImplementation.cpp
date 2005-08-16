 /**
 * Linux_DnsManagedSystemElementForSettingDefaultImplementation.cpp
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
#include "Linux_DnsManagedSystemElementForSettingDefaultImplementation.h"
#include <iostream>

using namespace std;

namespace genProvider {

  /* intrinsic methods */
  void Linux_DnsManagedSystemElementForSettingDefaultImplementation::enumInstanceNames(
   const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
   Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration& instnames){
   	cout<<"enumInstances not supported for Linux_DnsManagedSystemElementForSetting"<<endl;
   	throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "enumInstances not implemented for Linux_DnsManagedSystemElementForSetting");   
  }
  	
  void Linux_DnsManagedSystemElementForSettingDefaultImplementation::enumInstances(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char *nsp,
   const char* *properties,
   Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration& instances){
    
    cout<<"Using default enumInstances implementation for Linux_DnsManagedSystemElementForSetting"<<endl;
    cout<<"LetŽs get the instanceNames"<<endl;
    Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(ctx, mbp,nsp,namesEnumeration);
    cout<<"Getting each instance"<<endl;
    while(namesEnumeration.hasNext()){
      Linux_DnsManagedSystemElementForSettingInstanceName name=
    	  namesEnumeration.getNext();
    	cout<<"Getting an instance for instanceName"<<endl;
    	Linux_DnsManagedSystemElementForSettingManualInstance instance=
    	  getInstance(ctx, mbp, properties, name);
    	cout<<"adding instance to enum"<<endl;
    	instances.addElement(instance);
    	cout<<"Added!"<<endl;
    };
  }
  	
  Linux_DnsManagedSystemElementForSettingManualInstance 
   Linux_DnsManagedSystemElementForSettingDefaultImplementation::getInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsManagedSystemElementForSettingInstanceName&){
    cout<<"getInstance not supported for Linux_DnsManagedSystemElementForSetting"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "getInstance not implemented for Linux_DnsManagedSystemElementForSetting");
  }
  	
  void Linux_DnsManagedSystemElementForSettingDefaultImplementation::setInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsManagedSystemElementForSettingManualInstance&){
   	cout<<"setInstance not supported for Linux_DnsManagedSystemElementForSetting"<<endl;
     throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "setInstance not implemented for Linux_DnsManagedSystemElementForSetting");
  }
  	
  void Linux_DnsManagedSystemElementForSettingDefaultImplementation::
   createInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsManagedSystemElementForSettingManualInstance&){
   	cout<<"createInstance not supported for Linux_DnsManagedSystemElementForSetting"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "createInstance not implemented for Linux_DnsManagedSystemElementForSetting");
  }
  	
  void Linux_DnsManagedSystemElementForSettingDefaultImplementation::
   deleteInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsManagedSystemElementForSettingInstanceName&){
   	cout<<"deleteInstance not supported for Linux_DnsManagedSystemElementForSetting"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "deleteInstance not implemented for Linux_DnsManagedSystemElementForSetting");
  }
	
  
    /* Association Interface */

    void Linux_DnsManagedSystemElementForSettingDefaultImplementation::
     referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getElementReferences between Linux_DnsZone and Linux_DnsAddressMatchList not implemented for Linux_DnsManagedSystemElementForSetting");
    }

    void Linux_DnsManagedSystemElementForSettingDefaultImplementation::
     referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getSettingReferences between Linux_DnsZone and Linux_DnsAddressMatchList not implemented for Linux_DnsManagedSystemElementForSetting");
    }

    void Linux_DnsManagedSystemElementForSettingDefaultImplementation::
     associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsZoneInstanceEnumeration& instances){
      
      std::cout<<"Linux_DnsManagedSystemElementForSetting : associatorsLinux_DnsZone() ... returns one instance"<<std::endl;
      
      Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration enumeration;
      
      referencesElement(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsZoneExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsManagedSystemElementForSettingManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsManagedSystemElementForSettingInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsZoneInstanceName Element = 
         instanceName.getElement();
         
        Linux_DnsZoneInstance inst = external.getInstance(properties,Element);
        
        instances.addElement(inst);
      }
    }

    void Linux_DnsManagedSystemElementForSettingDefaultImplementation::
     associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration& instances){
     
      std::cout<<"Linux_DnsManagedSystemElementForSetting : associatorsLinux_DnsAddressMatchList() ... returns one instance"<<std::endl;
      
      Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration enumeration;
      
      referencesSetting(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsAddressMatchListExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsManagedSystemElementForSettingManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsManagedSystemElementForSettingInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsAddressMatchListInstanceName Setting = 
         instanceName.getSetting();
         
        Linux_DnsAddressMatchListInstance inst = external.getInstance(properties,Setting);
        
        instances.addElement(inst);
      }
    }

   
  /* extrinsic methods */
	
}

