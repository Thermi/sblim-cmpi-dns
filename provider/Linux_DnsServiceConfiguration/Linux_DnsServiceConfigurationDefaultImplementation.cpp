 /**
 * Linux_DnsServiceConfigurationDefaultImplementation.cpp
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
#include "Linux_DnsServiceConfigurationDefaultImplementation.h"
#include <iostream>

using namespace std;

namespace genProvider {

  /* intrinsic methods */
  void Linux_DnsServiceConfigurationDefaultImplementation::enumInstanceNames(
   const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
   Linux_DnsServiceConfigurationInstanceNameEnumeration& instnames){
   	cout<<"enumInstances not supported for Linux_DnsServiceConfiguration"<<endl;
   	throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "enumInstances not implemented for Linux_DnsServiceConfiguration");   
  }
  	
  void Linux_DnsServiceConfigurationDefaultImplementation::enumInstances(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char *nsp,
   const char* *properties,
   Linux_DnsServiceConfigurationManualInstanceEnumeration& instances){
    
    cout<<"Using default enumInstances implementation for Linux_DnsServiceConfiguration"<<endl;
    cout<<"LetŽs get the instanceNames"<<endl;
    Linux_DnsServiceConfigurationInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(ctx, mbp,nsp,namesEnumeration);
    cout<<"Getting each instance"<<endl;
    while(namesEnumeration.hasNext()){
      Linux_DnsServiceConfigurationInstanceName name=
    	  namesEnumeration.getNext();
    	cout<<"Getting an instance for instanceName"<<endl;
    	Linux_DnsServiceConfigurationManualInstance instance=
    	  getInstance(ctx, mbp, properties, name);
    	cout<<"adding instance to enum"<<endl;
    	instances.addElement(instance);
    	cout<<"Added!"<<endl;
    };
  }
  	
  Linux_DnsServiceConfigurationManualInstance 
   Linux_DnsServiceConfigurationDefaultImplementation::getInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsServiceConfigurationInstanceName&){
    cout<<"getInstance not supported for Linux_DnsServiceConfiguration"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "getInstance not implemented for Linux_DnsServiceConfiguration");
  }
  	
  void Linux_DnsServiceConfigurationDefaultImplementation::setInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsServiceConfigurationManualInstance&){
   	cout<<"setInstance not supported for Linux_DnsServiceConfiguration"<<endl;
     throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "setInstance not implemented for Linux_DnsServiceConfiguration");
  }
  	
  void Linux_DnsServiceConfigurationDefaultImplementation::
   createInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsServiceConfigurationManualInstance&){
   	cout<<"createInstance not supported for Linux_DnsServiceConfiguration"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "createInstance not implemented for Linux_DnsServiceConfiguration");
  }
  	
  void Linux_DnsServiceConfigurationDefaultImplementation::
   deleteInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsServiceConfigurationInstanceName&){
   	cout<<"deleteInstance not supported for Linux_DnsServiceConfiguration"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "deleteInstance not implemented for Linux_DnsServiceConfiguration");
  }
	
  
    /* Association Interface */

    void Linux_DnsServiceConfigurationDefaultImplementation::
     referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsServiceConfigurationManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getElementReferences between Linux_DnsService and Linux_DnsConfiguration not implemented for Linux_DnsServiceConfiguration");
    }

    void Linux_DnsServiceConfigurationDefaultImplementation::
     referencesConfiguration( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsServiceConfigurationManualInstanceEnumeration& instances){
      throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "getConfigurationReferences between Linux_DnsService and Linux_DnsConfiguration not implemented for Linux_DnsServiceConfiguration");
    }

    void Linux_DnsServiceConfigurationDefaultImplementation::
     associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsServiceInstanceEnumeration& instances){
      
      std::cout<<"Linux_DnsServiceConfiguration : associatorsLinux_DnsService() ... returns one instance"<<std::endl;
      
      Linux_DnsServiceConfigurationManualInstanceEnumeration enumeration;
      
      referencesElement(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsServiceExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsServiceConfigurationManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsServiceConfigurationInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsServiceInstanceName Element = 
         instanceName.getElement();
         
        Linux_DnsServiceInstance inst = external.getInstance(properties,Element);
        
        instances.addElement(inst);
      }
    }

    void Linux_DnsServiceConfigurationDefaultImplementation::
     associatorsConfiguration( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsConfigurationInstanceEnumeration& instances){
     
      std::cout<<"Linux_DnsServiceConfiguration : associatorsLinux_DnsConfiguration() ... returns one instance"<<std::endl;
      
      Linux_DnsServiceConfigurationManualInstanceEnumeration enumeration;
      
      referencesConfiguration(ctx, mbp, sourceInst.getNamespace(), 
       properties, sourceInst, enumeration);

      Linux_DnsConfigurationExternal external(mbp, ctx);

      while(enumeration.hasNext()) {
        const Linux_DnsServiceConfigurationManualInstance instance =
	     enumeration.getNext();
	     
        const Linux_DnsServiceConfigurationInstanceName instanceName = 
         instance.getInstanceName();
         
        const Linux_DnsConfigurationInstanceName Configuration = 
         instanceName.getConfiguration();
         
        Linux_DnsConfigurationInstance inst = external.getInstance(properties,Configuration);
        
        instances.addElement(inst);
      }
    }

   
  /* extrinsic methods */
	
}

