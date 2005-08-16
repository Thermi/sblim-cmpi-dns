 /**
 * Linux_DnsTransferACLForServiceDefaultImplementation.cpp
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
#include "Linux_DnsTransferACLForServiceDefaultImplementation.h"
#include <iostream>

using namespace std;

namespace genProvider {

  /* intrinsic methods */
  void Linux_DnsTransferACLForServiceDefaultImplementation::enumInstanceNames(
   const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
   Linux_DnsTransferACLForServiceInstanceNameEnumeration& instnames){
   	cout<<"enumInstances not supported for Linux_DnsTransferACLForService"<<endl;
   	throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "enumInstances not implemented for Linux_DnsTransferACLForService");   
  }
  	
  void Linux_DnsTransferACLForServiceDefaultImplementation::enumInstances(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char *nsp,
   const char* *properties,
   Linux_DnsTransferACLForServiceManualInstanceEnumeration& instances){
    
    cout<<"Using default enumInstances implementation for Linux_DnsTransferACLForService"<<endl;
    cout<<"LetŽs get the instanceNames"<<endl;
    Linux_DnsTransferACLForServiceInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(ctx, mbp,nsp,namesEnumeration);
    cout<<"Getting each instance"<<endl;
    while(namesEnumeration.hasNext()){
      Linux_DnsTransferACLForServiceInstanceName name=
    	  namesEnumeration.getNext();
    	cout<<"Getting an instance for instanceName"<<endl;
    	Linux_DnsTransferACLForServiceManualInstance instance=
    	  getInstance(ctx, mbp, properties, name);
    	cout<<"adding instance to enum"<<endl;
    	instances.addElement(instance);
    	cout<<"Added!"<<endl;
    };
  }
  	
  Linux_DnsTransferACLForServiceManualInstance 
   Linux_DnsTransferACLForServiceDefaultImplementation::getInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsTransferACLForServiceInstanceName&){
    cout<<"getInstance not supported for Linux_DnsTransferACLForService"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "getInstance not implemented for Linux_DnsTransferACLForService");
  }
  	
  void Linux_DnsTransferACLForServiceDefaultImplementation::setInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsTransferACLForServiceManualInstance&){
   	cout<<"setInstance not supported for Linux_DnsTransferACLForService"<<endl;
     throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "setInstance not implemented for Linux_DnsTransferACLForService");
  }
  	
  void Linux_DnsTransferACLForServiceDefaultImplementation::
   createInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsTransferACLForServiceManualInstance&){
   	cout<<"createInstance not supported for Linux_DnsTransferACLForService"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "createInstance not implemented for Linux_DnsTransferACLForService");
  }
  	
  void Linux_DnsTransferACLForServiceDefaultImplementation::
   deleteInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsTransferACLForServiceInstanceName&){
   	cout<<"deleteInstance not supported for Linux_DnsTransferACLForService"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "deleteInstance not implemented for Linux_DnsTransferACLForService");
  }
	
  
    /* Association Interface */

    void Linux_DnsTransferACLForServiceDefaultImplementation::
     referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsTransferACLForServiceManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getElementReferences between Linux_DnsService and Linux_DnsAddressMatchList not implemented for Linux_DnsTransferACLForService");
    }

    void Linux_DnsTransferACLForServiceDefaultImplementation::
     referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsTransferACLForServiceManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getSettingReferences between Linux_DnsService and Linux_DnsAddressMatchList not implemented for Linux_DnsTransferACLForService");
    }

    void Linux_DnsTransferACLForServiceDefaultImplementation::
     associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsServiceInstanceEnumeration& instances){
      
      std::cout<<"Linux_DnsTransferACLForService : associatorsLinux_DnsService() ... returns one instance"<<std::endl;
      
      Linux_DnsTransferACLForServiceManualInstanceEnumeration enumeration;
      
      referencesElement(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsServiceExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsTransferACLForServiceManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsTransferACLForServiceInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsServiceInstanceName Element = 
         instanceName.getElement();
         
        Linux_DnsServiceInstance inst = external.getInstance(properties,Element);
        
        instances.addElement(inst);
      }
    }

    void Linux_DnsTransferACLForServiceDefaultImplementation::
     associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration& instances){
     
      std::cout<<"Linux_DnsTransferACLForService : associatorsLinux_DnsAddressMatchList() ... returns one instance"<<std::endl;
      
      Linux_DnsTransferACLForServiceManualInstanceEnumeration enumeration;
      
      referencesSetting(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsAddressMatchListExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsTransferACLForServiceManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsTransferACLForServiceInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsAddressMatchListInstanceName Setting = 
         instanceName.getSetting();
         
        Linux_DnsAddressMatchListInstance inst = external.getInstance(properties,Setting);
        
        instances.addElement(inst);
      }
    }

   
  /* extrinsic methods */
	
}

