// =======================================================================
// Linux_DnsServiceConfigurationForServiceDefaultImplementation.cpp
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
// 
// Copyright (c) 2006, 2009, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Eclipse Public License from
// http://www.opensource.org/licenses/eclipse-1.0.php
//
// Author:        generated
//
// Contributors:
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 

#include "Linux_DnsServiceConfigurationForServiceDefaultImplementation.h"
#include "Linux_DnsServiceConfigurationForServiceRepositoryInstance.h"
#include <iostream>

namespace genProvider {

  /* intrinsic methods */
  //----------------------------------------------------------------------------	
  void
  Linux_DnsServiceConfigurationForServiceDefaultImplementation::enumInstanceNames(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {

#ifdef DEBUG
   	std::cout << "enumInstanceNames not supported for Linux_DnsServiceConfigurationForService" << std::endl;
#endif   	

   	throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::NOT_IMPLEMENTED,
   	  "enumInstanceEnumeration",
   	  "Linux_DnsServiceConfigurationForService");   

  }

  //----------------------------------------------------------------------------	
  void 
  Linux_DnsServiceConfigurationForServiceDefaultImplementation::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsServiceConfigurationForServiceManualInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
    std::cout << "Using default enumInstances implementation for Linux_DnsServiceConfigurationForService" << std::endl;
    std::cout << "Let's get the instanceNames" << std::endl;
#endif    

    Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(aContext,aBroker,aNameSpaceP,namesEnumeration);

#ifdef DEBUG
    std::cout << "Getting each instance" << std::endl;
#endif    
    
    while (namesEnumeration.hasNext()) {
    
      Linux_DnsServiceConfigurationForServiceInstanceName instanceName = namesEnumeration.getNext();
    
      Linux_DnsServiceConfigurationForServiceRepositoryInstance repositoryInstance;

      // try to fetch repository instance
      try {
        Linux_DnsServiceConfigurationForServiceInstanceName repositoryInstanceName(instanceName);
        repositoryInstanceName.setNamespace("IBMShadow/cimv2");
        CmpiObjectPath repositoryCmpiObjectPath = repositoryInstanceName.getObjectPath();
        CmpiBroker cmpiBroker(aBroker);
        CmpiInstance repositoryCmpiInstance = cmpiBroker.getInstance(
            aContext,
            repositoryCmpiObjectPath,
            aPropertiesPP);
        Linux_DnsServiceConfigurationForServiceRepositoryInstance localRepositoryInstance(
      	  repositoryCmpiInstance,
          "IBMShadow/cimv2");
        repositoryInstance = localRepositoryInstance;
      } catch (const CmpiStatus& rc) { }                             
    
#ifdef DEBUG
    	std::cout << "Getting an instance for instanceName" << std::endl;
#endif
    	
    	Linux_DnsServiceConfigurationForServiceManualInstance instance = getInstance(
    	  aContext,
    	  aBroker,
    	  aPropertiesPP,
    	  instanceName);

      // add the static data


#ifdef DEBUG
    	std::cout << "adding instance to enum" << std::endl;
#endif
    	
    	anInstanceEnumeration.addElement(instance);

#ifdef DEBUG
    	std::cout << "Added!" << std::endl;
#endif
    	
    }

  }

  //----------------------------------------------------------------------------	
  Linux_DnsServiceConfigurationForServiceManualInstance 
  Linux_DnsServiceConfigurationForServiceDefaultImplementation::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName) {

#ifdef DEBUG
    std::cout << "getInstance not supported for Linux_DnsServiceConfigurationForService" << std::endl;
#endif
    	

    throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::NOT_IMPLEMENTED,
   	  "getInstance",
   	  "Linux_DnsServiceConfigurationForService");

  }
  	
  //----------------------------------------------------------------------------	
  void 
  Linux_DnsServiceConfigurationForServiceDefaultImplementation::setInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsServiceConfigurationForServiceManualInstance& aManualInstance) {
  
#ifdef DEBUG
    std::cout << "setInstance not supported for Linux_DnsServiceConfigurationForService" << std::endl;
#endif
    	
   
    throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::NOT_IMPLEMENTED,
   	  "setInstance",
   	  "Linux_DnsServiceConfigurationForService");
   	 
  }
  	
  //----------------------------------------------------------------------------	
  Linux_DnsServiceConfigurationForServiceInstanceName  
  Linux_DnsServiceConfigurationForServiceDefaultImplementation::createInstance(
    const CmpiContext& aContext, 
    const CmpiBroker& aBroker,
    const Linux_DnsServiceConfigurationForServiceManualInstance& aManualInstance) {

#ifdef DEBUG
   	std::cout << "createInstance not supported for Linux_DnsServiceConfigurationForService" << std::endl;
#endif

    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "createInstance",
   	 "Linux_DnsServiceConfigurationForService");

  }

  //----------------------------------------------------------------------------	
  void 
  Linux_DnsServiceConfigurationForServiceDefaultImplementation::deleteInstance(
    const CmpiContext& aContext, 
    const CmpiBroker& aBroker,
    const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName) {

#ifdef DEBUG
   	std::cout << "deleteInstance not supported for Linux_DnsServiceConfigurationForService" << std::endl;
#endif

    throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::NOT_IMPLEMENTED,
      "deleteInstance",
      "Linux_DnsServiceConfigurationForService");

  }

  
  // Association Interface

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceDefaultImplementation::referencesElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceConfigurationInstanceName& aSourceInstance,
    Linux_DnsServiceConfigurationForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
    throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::NOT_IMPLEMENTED,
      "References(Element)",
      "Linux_DnsServiceConfigurationForService");

  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceDefaultImplementation::referencesConfiguration( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstance,
    Linux_DnsServiceConfigurationForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
    throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::NOT_IMPLEMENTED,
      "References(Configuration)",
      "Linux_DnsServiceConfigurationForService");

  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceDefaultImplementation::associatorsElement(
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceConfigurationInstanceName& aSourceInstance,
    Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration) {
      
#ifdef DEBUG
    std::cout<<"Linux_DnsServiceConfigurationForService : associatorsLinux_DnsService() ... returns one instance"<<std::endl;
#endif    
      
    Linux_DnsServiceConfigurationForServiceManualInstanceEnumeration manualInstanceEnumeration;
      
    referencesElement(
      aContext,
      aBroker,
      aSourceInstance.getNamespace(), 
      aPropertiesPP,
      aSourceInstance,
      manualInstanceEnumeration);

    Linux_DnsServiceExternal external(aBroker,aContext);

    while (manualInstanceEnumeration.hasNext()) {
      const Linux_DnsServiceConfigurationForServiceManualInstance manualInstance = manualInstanceEnumeration.getNext();
      const Linux_DnsServiceConfigurationForServiceInstanceName instanceName = manualInstance.getInstanceName();
      const Linux_DnsServiceInstanceName Element = instanceName.getElement();
      Linux_DnsServiceInstance instance = external.getInstance(aPropertiesPP,Element);
      anInstanceEnumeration.addElement(instance);
    }
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceDefaultImplementation::associatorsConfiguration( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstance,
    Linux_DnsServiceConfigurationInstanceEnumeration& anInstanceEnumeration) {
     
#ifdef DEBUG
    std::cout << "Linux_DnsServiceConfigurationForService : associatorsLinux_DnsServiceConfiguration() ... returns one instance" << std::endl;
#endif    
      
    Linux_DnsServiceConfigurationForServiceManualInstanceEnumeration manualInstanceEnumeration;
      
    referencesConfiguration(
      aContext,
      aBroker,
      aSourceInstance.getNamespace(), 
      aPropertiesPP,
      aSourceInstance,
      manualInstanceEnumeration);

    Linux_DnsServiceConfigurationExternal external(aBroker,aContext);

    while(manualInstanceEnumeration.hasNext()) {
      const Linux_DnsServiceConfigurationForServiceManualInstance manualInstance = manualInstanceEnumeration.getNext();
      const Linux_DnsServiceConfigurationForServiceInstanceName instanceName = manualInstance.getInstanceName();
      const Linux_DnsServiceConfigurationInstanceName Configuration = instanceName.getConfiguration();
      Linux_DnsServiceConfigurationInstance instance = external.getInstance(aPropertiesPP,Configuration);
      anInstanceEnumeration.addElement(instance);
    }

  }

  /* extrinsic methods */
  

}
