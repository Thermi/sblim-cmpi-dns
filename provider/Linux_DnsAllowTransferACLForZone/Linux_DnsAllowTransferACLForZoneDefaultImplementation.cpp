 /**
 * Linux_DnsAllowTransferACLForZoneDefaultImplementation.cpp
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
#include "Linux_DnsAllowTransferACLForZoneDefaultImplementation.h"
#include <iostream>

using namespace std;

namespace genProvider {

  /* intrinsic methods */
  void Linux_DnsAllowTransferACLForZoneDefaultImplementation::enumInstanceNames(
   const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
   Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration& instnames){
   	cout<<"enumInstances not supported for Linux_DnsAllowTransferACLForZone"<<endl;
   	throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "enumInstances not implemented for Linux_DnsAllowTransferACLForZone");   
  }
  	
  void Linux_DnsAllowTransferACLForZoneDefaultImplementation::enumInstances(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char *nsp,
   const char* *properties,
   Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration& instances){
    
    cout<<"Using default enumInstances implementation for Linux_DnsAllowTransferACLForZone"<<endl;
    cout<<"LetŽs get the instanceNames"<<endl;
    Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(ctx, mbp,nsp,namesEnumeration);
    cout<<"Getting each instance"<<endl;
    while(namesEnumeration.hasNext()){
      Linux_DnsAllowTransferACLForZoneInstanceName name=
    	  namesEnumeration.getNext();
    	cout<<"Getting an instance for instanceName"<<endl;
    	Linux_DnsAllowTransferACLForZoneManualInstance instance=
    	  getInstance(ctx, mbp, properties, name);
    	cout<<"adding instance to enum"<<endl;
    	instances.addElement(instance);
    	cout<<"Added!"<<endl;
    };
  }
  	
  Linux_DnsAllowTransferACLForZoneManualInstance 
   Linux_DnsAllowTransferACLForZoneDefaultImplementation::getInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsAllowTransferACLForZoneInstanceName&){
    cout<<"getInstance not supported for Linux_DnsAllowTransferACLForZone"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "getInstance not implemented for Linux_DnsAllowTransferACLForZone");
  }
  	
  void Linux_DnsAllowTransferACLForZoneDefaultImplementation::setInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsAllowTransferACLForZoneManualInstance&){
   	cout<<"setInstance not supported for Linux_DnsAllowTransferACLForZone"<<endl;
     throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "setInstance not implemented for Linux_DnsAllowTransferACLForZone");
  }
  	
  void Linux_DnsAllowTransferACLForZoneDefaultImplementation::
   createInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsAllowTransferACLForZoneManualInstance&){
   	cout<<"createInstance not supported for Linux_DnsAllowTransferACLForZone"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "createInstance not implemented for Linux_DnsAllowTransferACLForZone");
  }
  	
  void Linux_DnsAllowTransferACLForZoneDefaultImplementation::
   deleteInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsAllowTransferACLForZoneInstanceName&){
   	cout<<"deleteInstance not supported for Linux_DnsAllowTransferACLForZone"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "deleteInstance not implemented for Linux_DnsAllowTransferACLForZone");
  }
	
  
    /* Association Interface */

    void Linux_DnsAllowTransferACLForZoneDefaultImplementation::
     referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getElementReferences between Linux_DnsZone and Linux_DnsAddressMatchList not implemented for Linux_DnsAllowTransferACLForZone");
    }

    void Linux_DnsAllowTransferACLForZoneDefaultImplementation::
     referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getSettingReferences between Linux_DnsZone and Linux_DnsAddressMatchList not implemented for Linux_DnsAllowTransferACLForZone");
    }

    void Linux_DnsAllowTransferACLForZoneDefaultImplementation::
     associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsZoneInstanceEnumeration& instances){
      
      std::cout<<"Linux_DnsAllowTransferACLForZone : associatorsLinux_DnsZone() ... returns one instance"<<std::endl;
      
      Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration enumeration;
      
      referencesElement(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsZoneExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsAllowTransferACLForZoneManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsAllowTransferACLForZoneInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsZoneInstanceName Element = 
         instanceName.getElement();
         
        Linux_DnsZoneInstance inst = external.getInstance(properties,Element);
        
        instances.addElement(inst);
      }
    }

    void Linux_DnsAllowTransferACLForZoneDefaultImplementation::
     associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration& instances){
     
      std::cout<<"Linux_DnsAllowTransferACLForZone : associatorsLinux_DnsAddressMatchList() ... returns one instance"<<std::endl;
      
      Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration enumeration;
      
      referencesSetting(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsAddressMatchListExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsAllowTransferACLForZoneManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsAllowTransferACLForZoneInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsAddressMatchListInstanceName Setting = 
         instanceName.getSetting();
         
        Linux_DnsAddressMatchListInstance inst = external.getInstance(properties,Setting);
        
        instances.addElement(inst);
      }
    }

   
  /* extrinsic methods */
	
}

