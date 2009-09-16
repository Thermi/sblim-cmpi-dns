// =======================================================================
// Linux_DnsBlackholeForServiceDefaultImplementation.cpp
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

#include "Linux_DnsBlackholeForServiceDefaultImplementation.h"
#include "Linux_DnsBlackholeForServiceRepositoryInstance.h"
#include <iostream>

namespace genProvider {

  /* intrinsic methods */
  //----------------------------------------------------------------------------	
  void
  Linux_DnsBlackholeForServiceDefaultImplementation::enumInstanceNames(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    Linux_DnsBlackholeForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {

#ifdef DEBUG
   	std::cout << "enumInstanceNames not supported for Linux_DnsBlackholeForService" << std::endl;
#endif   	

   	throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::NOT_IMPLEMENTED,
   	  "enumInstanceEnumeration",
   	  "Linux_DnsBlackholeForService");   

  }

  //----------------------------------------------------------------------------	
  void 
  Linux_DnsBlackholeForServiceDefaultImplementation::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsBlackholeForServiceManualInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
    std::cout << "Using default enumInstances implementation for Linux_DnsBlackholeForService" << std::endl;
    std::cout << "Let's get the instanceNames" << std::endl;
#endif    

    Linux_DnsBlackholeForServiceInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(aContext,aBroker,aNameSpaceP,namesEnumeration);

#ifdef DEBUG
    std::cout << "Getting each instance" << std::endl;
#endif    
    
    while (namesEnumeration.hasNext()) {
    
      Linux_DnsBlackholeForServiceInstanceName instanceName = namesEnumeration.getNext();
    
      Linux_DnsBlackholeForServiceRepositoryInstance repositoryInstance;

      // try to fetch repository instance
      try {
        Linux_DnsBlackholeForServiceInstanceName repositoryInstanceName(instanceName);
        repositoryInstanceName.setNamespace("IBMShadow/cimv2");
        CmpiObjectPath repositoryCmpiObjectPath = repositoryInstanceName.getObjectPath();
        CmpiBroker cmpiBroker(aBroker);
        CmpiInstance repositoryCmpiInstance = cmpiBroker.getInstance(
            aContext,
            repositoryCmpiObjectPath,
            aPropertiesPP);
        Linux_DnsBlackholeForServiceRepositoryInstance localRepositoryInstance(
      	  repositoryCmpiInstance,
          "IBMShadow/cimv2");
        repositoryInstance = localRepositoryInstance;
      } catch (const CmpiStatus& rc) { }                             
    
#ifdef DEBUG
    	std::cout << "Getting an instance for instanceName" << std::endl;
#endif
    	
    	Linux_DnsBlackholeForServiceManualInstance instance = getInstance(
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
  Linux_DnsBlackholeForServiceManualInstance 
  Linux_DnsBlackholeForServiceDefaultImplementation::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsBlackholeForServiceInstanceName& anInstanceName) {

#ifdef DEBUG
    std::cout << "getInstance not supported for Linux_DnsBlackholeForService" << std::endl;
#endif
    	

    throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::NOT_IMPLEMENTED,
   	  "getInstance",
   	  "Linux_DnsBlackholeForService");

  }
  	
  //----------------------------------------------------------------------------	
  void 
  Linux_DnsBlackholeForServiceDefaultImplementation::setInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsBlackholeForServiceManualInstance& aManualInstance) {
  
#ifdef DEBUG
    std::cout << "setInstance not supported for Linux_DnsBlackholeForService" << std::endl;
#endif
    	
   
    throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::NOT_IMPLEMENTED,
   	  "setInstance",
   	  "Linux_DnsBlackholeForService");
   	 
  }
  	
  //----------------------------------------------------------------------------	
  Linux_DnsBlackholeForServiceInstanceName  
  Linux_DnsBlackholeForServiceDefaultImplementation::createInstance(
    const CmpiContext& aContext, 
    const CmpiBroker& aBroker,
    const Linux_DnsBlackholeForServiceManualInstance& aManualInstance) {

#ifdef DEBUG
   	std::cout << "createInstance not supported for Linux_DnsBlackholeForService" << std::endl;
#endif

    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "createInstance",
   	 "Linux_DnsBlackholeForService");

  }

  //----------------------------------------------------------------------------	
  void 
  Linux_DnsBlackholeForServiceDefaultImplementation::deleteInstance(
    const CmpiContext& aContext, 
    const CmpiBroker& aBroker,
    const Linux_DnsBlackholeForServiceInstanceName& anInstanceName) {

#ifdef DEBUG
   	std::cout << "deleteInstance not supported for Linux_DnsBlackholeForService" << std::endl;
#endif

    throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::NOT_IMPLEMENTED,
      "deleteInstance",
      "Linux_DnsBlackholeForService");

  }

  
  // Association Interface

  //----------------------------------------------------------------------------
  void
  Linux_DnsBlackholeForServiceDefaultImplementation::referencesGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstance,
    Linux_DnsBlackholeForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
    throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::NOT_IMPLEMENTED,
      "References(GroupComponent)",
      "Linux_DnsBlackholeForService");

  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsBlackholeForServiceDefaultImplementation::referencesPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstance,
    Linux_DnsBlackholeForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
    throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::NOT_IMPLEMENTED,
      "References(PartComponent)",
      "Linux_DnsBlackholeForService");

  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsBlackholeForServiceDefaultImplementation::associatorsGroupComponent(
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstance,
    Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration) {
      
#ifdef DEBUG
    std::cout<<"Linux_DnsBlackholeForService : associatorsLinux_DnsService() ... returns one instance"<<std::endl;
#endif    
      
    Linux_DnsBlackholeForServiceManualInstanceEnumeration manualInstanceEnumeration;
      
    referencesGroupComponent(
      aContext,
      aBroker,
      aSourceInstance.getNamespace(), 
      aPropertiesPP,
      aSourceInstance,
      manualInstanceEnumeration);

    Linux_DnsServiceExternal external(aBroker,aContext);

    while (manualInstanceEnumeration.hasNext()) {
      const Linux_DnsBlackholeForServiceManualInstance manualInstance = manualInstanceEnumeration.getNext();
      const Linux_DnsBlackholeForServiceInstanceName instanceName = manualInstance.getInstanceName();
      const Linux_DnsServiceInstanceName GroupComponent = instanceName.getGroupComponent();
      Linux_DnsServiceInstance instance = external.getInstance(aPropertiesPP,GroupComponent);
      anInstanceEnumeration.addElement(instance);
    }
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsBlackholeForServiceDefaultImplementation::associatorsPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstance,
    Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration) {
     
#ifdef DEBUG
    std::cout << "Linux_DnsBlackholeForService : associatorsLinux_DnsAddressMatchList() ... returns one instance" << std::endl;
#endif    
      
    Linux_DnsBlackholeForServiceManualInstanceEnumeration manualInstanceEnumeration;
      
    referencesPartComponent(
      aContext,
      aBroker,
      aSourceInstance.getNamespace(), 
      aPropertiesPP,
      aSourceInstance,
      manualInstanceEnumeration);

    Linux_DnsAddressMatchListExternal external(aBroker,aContext);

    while(manualInstanceEnumeration.hasNext()) {
      const Linux_DnsBlackholeForServiceManualInstance manualInstance = manualInstanceEnumeration.getNext();
      const Linux_DnsBlackholeForServiceInstanceName instanceName = manualInstance.getInstanceName();
      const Linux_DnsAddressMatchListInstanceName PartComponent = instanceName.getPartComponent();
      Linux_DnsAddressMatchListInstance instance = external.getInstance(aPropertiesPP,PartComponent);
      anInstanceEnumeration.addElement(instance);
    }

  }

  /* extrinsic methods */
  

}
