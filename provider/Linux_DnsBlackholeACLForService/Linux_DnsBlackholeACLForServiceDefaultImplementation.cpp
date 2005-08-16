 /**
 * Linux_DnsBlackholeACLForServiceDefaultImplementation.cpp
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
#include "Linux_DnsBlackholeACLForServiceDefaultImplementation.h"
#include <iostream>

using namespace std;

namespace genProvider {

  /* intrinsic methods */
  void Linux_DnsBlackholeACLForServiceDefaultImplementation::enumInstanceNames(
   const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
   Linux_DnsBlackholeACLForServiceInstanceNameEnumeration& instnames){
   	cout<<"enumInstances not supported for Linux_DnsBlackholeACLForService"<<endl;
   	throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "enumInstances not implemented for Linux_DnsBlackholeACLForService");   
  }
  	
  void Linux_DnsBlackholeACLForServiceDefaultImplementation::enumInstances(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char *nsp,
   const char* *properties,
   Linux_DnsBlackholeACLForServiceManualInstanceEnumeration& instances){
    
    cout<<"Using default enumInstances implementation for Linux_DnsBlackholeACLForService"<<endl;
    cout<<"LetŽs get the instanceNames"<<endl;
    Linux_DnsBlackholeACLForServiceInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(ctx, mbp,nsp,namesEnumeration);
    cout<<"Getting each instance"<<endl;
    while(namesEnumeration.hasNext()){
      Linux_DnsBlackholeACLForServiceInstanceName name=
    	  namesEnumeration.getNext();
    	cout<<"Getting an instance for instanceName"<<endl;
    	Linux_DnsBlackholeACLForServiceManualInstance instance=
    	  getInstance(ctx, mbp, properties, name);
    	cout<<"adding instance to enum"<<endl;
    	instances.addElement(instance);
    	cout<<"Added!"<<endl;
    };
  }
  	
  Linux_DnsBlackholeACLForServiceManualInstance 
   Linux_DnsBlackholeACLForServiceDefaultImplementation::getInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsBlackholeACLForServiceInstanceName&){
    cout<<"getInstance not supported for Linux_DnsBlackholeACLForService"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "getInstance not implemented for Linux_DnsBlackholeACLForService");
  }
  	
  void Linux_DnsBlackholeACLForServiceDefaultImplementation::setInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsBlackholeACLForServiceManualInstance&){
   	cout<<"setInstance not supported for Linux_DnsBlackholeACLForService"<<endl;
     throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "setInstance not implemented for Linux_DnsBlackholeACLForService");
  }
  	
  void Linux_DnsBlackholeACLForServiceDefaultImplementation::
   createInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsBlackholeACLForServiceManualInstance&){
   	cout<<"createInstance not supported for Linux_DnsBlackholeACLForService"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "createInstance not implemented for Linux_DnsBlackholeACLForService");
  }
  	
  void Linux_DnsBlackholeACLForServiceDefaultImplementation::
   deleteInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsBlackholeACLForServiceInstanceName&){
   	cout<<"deleteInstance not supported for Linux_DnsBlackholeACLForService"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "deleteInstance not implemented for Linux_DnsBlackholeACLForService");
  }
	
  
    /* Association Interface */

    void Linux_DnsBlackholeACLForServiceDefaultImplementation::
     referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsBlackholeACLForServiceManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getElementReferences between Linux_DnsService and Linux_DnsAddressMatchList not implemented for Linux_DnsBlackholeACLForService");
    }

    void Linux_DnsBlackholeACLForServiceDefaultImplementation::
     referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsBlackholeACLForServiceManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getSettingReferences between Linux_DnsService and Linux_DnsAddressMatchList not implemented for Linux_DnsBlackholeACLForService");
    }

    void Linux_DnsBlackholeACLForServiceDefaultImplementation::
     associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsServiceInstanceEnumeration& instances){
      
      std::cout<<"Linux_DnsBlackholeACLForService : associatorsLinux_DnsService() ... returns one instance"<<std::endl;
      
      Linux_DnsBlackholeACLForServiceManualInstanceEnumeration enumeration;
      
      referencesElement(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsServiceExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsBlackholeACLForServiceManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsBlackholeACLForServiceInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsServiceInstanceName Element = 
         instanceName.getElement();
         
        Linux_DnsServiceInstance inst = external.getInstance(properties,Element);
        
        instances.addElement(inst);
      }
    }

    void Linux_DnsBlackholeACLForServiceDefaultImplementation::
     associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration& instances){
     
      std::cout<<"Linux_DnsBlackholeACLForService : associatorsLinux_DnsAddressMatchList() ... returns one instance"<<std::endl;
      
      Linux_DnsBlackholeACLForServiceManualInstanceEnumeration enumeration;
      
      referencesSetting(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsAddressMatchListExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsBlackholeACLForServiceManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsBlackholeACLForServiceInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsAddressMatchListInstanceName Setting = 
         instanceName.getSetting();
         
        Linux_DnsAddressMatchListInstance inst = external.getInstance(properties,Setting);
        
        instances.addElement(inst);
      }
    }

   
  /* extrinsic methods */
	
}

