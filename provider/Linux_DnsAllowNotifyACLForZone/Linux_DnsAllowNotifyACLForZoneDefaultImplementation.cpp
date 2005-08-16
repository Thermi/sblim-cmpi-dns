 /**
 * Linux_DnsAllowNotifyACLForZoneDefaultImplementation.cpp
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
#include "Linux_DnsAllowNotifyACLForZoneDefaultImplementation.h"
#include <iostream>

using namespace std;

namespace genProvider {

  /* intrinsic methods */
  void Linux_DnsAllowNotifyACLForZoneDefaultImplementation::enumInstanceNames(
   const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
   Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration& instnames){
   	cout<<"enumInstances not supported for Linux_DnsAllowNotifyACLForZone"<<endl;
   	throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "enumInstances not implemented for Linux_DnsAllowNotifyACLForZone");   
  }
  	
  void Linux_DnsAllowNotifyACLForZoneDefaultImplementation::enumInstances(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char *nsp,
   const char* *properties,
   Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration& instances){
    
    cout<<"Using default enumInstances implementation for Linux_DnsAllowNotifyACLForZone"<<endl;
    cout<<"LetŽs get the instanceNames"<<endl;
    Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(ctx, mbp,nsp,namesEnumeration);
    cout<<"Getting each instance"<<endl;
    while(namesEnumeration.hasNext()){
      Linux_DnsAllowNotifyACLForZoneInstanceName name=
    	  namesEnumeration.getNext();
    	cout<<"Getting an instance for instanceName"<<endl;
    	Linux_DnsAllowNotifyACLForZoneManualInstance instance=
    	  getInstance(ctx, mbp, properties, name);
    	cout<<"adding instance to enum"<<endl;
    	instances.addElement(instance);
    	cout<<"Added!"<<endl;
    };
  }
  	
  Linux_DnsAllowNotifyACLForZoneManualInstance 
   Linux_DnsAllowNotifyACLForZoneDefaultImplementation::getInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsAllowNotifyACLForZoneInstanceName&){
    cout<<"getInstance not supported for Linux_DnsAllowNotifyACLForZone"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "getInstance not implemented for Linux_DnsAllowNotifyACLForZone");
  }
  	
  void Linux_DnsAllowNotifyACLForZoneDefaultImplementation::setInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsAllowNotifyACLForZoneManualInstance&){
   	cout<<"setInstance not supported for Linux_DnsAllowNotifyACLForZone"<<endl;
     throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "setInstance not implemented for Linux_DnsAllowNotifyACLForZone");
  }
  	
  void Linux_DnsAllowNotifyACLForZoneDefaultImplementation::
   createInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsAllowNotifyACLForZoneManualInstance&){
   	cout<<"createInstance not supported for Linux_DnsAllowNotifyACLForZone"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "createInstance not implemented for Linux_DnsAllowNotifyACLForZone");
  }
  	
  void Linux_DnsAllowNotifyACLForZoneDefaultImplementation::
   deleteInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsAllowNotifyACLForZoneInstanceName&){
   	cout<<"deleteInstance not supported for Linux_DnsAllowNotifyACLForZone"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "deleteInstance not implemented for Linux_DnsAllowNotifyACLForZone");
  }
	
  
    /* Association Interface */

    void Linux_DnsAllowNotifyACLForZoneDefaultImplementation::
     referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getElementReferences between Linux_DnsZone and Linux_DnsAddressMatchList not implemented for Linux_DnsAllowNotifyACLForZone");
    }

    void Linux_DnsAllowNotifyACLForZoneDefaultImplementation::
     referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getSettingReferences between Linux_DnsZone and Linux_DnsAddressMatchList not implemented for Linux_DnsAllowNotifyACLForZone");
    }

    void Linux_DnsAllowNotifyACLForZoneDefaultImplementation::
     associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsZoneInstanceEnumeration& instances){
      
      std::cout<<"Linux_DnsAllowNotifyACLForZone : associatorsLinux_DnsZone() ... returns one instance"<<std::endl;
      
      Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration enumeration;
      
      referencesElement(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsZoneExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsAllowNotifyACLForZoneManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsAllowNotifyACLForZoneInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsZoneInstanceName Element = 
         instanceName.getElement();
         
        Linux_DnsZoneInstance inst = external.getInstance(properties,Element);
        
        instances.addElement(inst);
      }
    }

    void Linux_DnsAllowNotifyACLForZoneDefaultImplementation::
     associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration& instances){
     
      std::cout<<"Linux_DnsAllowNotifyACLForZone : associatorsLinux_DnsAddressMatchList() ... returns one instance"<<std::endl;
      
      Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration enumeration;
      
      referencesSetting(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsAddressMatchListExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsAllowNotifyACLForZoneManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsAllowNotifyACLForZoneInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsAddressMatchListInstanceName Setting = 
         instanceName.getSetting();
         
        Linux_DnsAddressMatchListInstance inst = external.getInstance(properties,Setting);
        
        instances.addElement(inst);
      }
    }

   
  /* extrinsic methods */
	
}

