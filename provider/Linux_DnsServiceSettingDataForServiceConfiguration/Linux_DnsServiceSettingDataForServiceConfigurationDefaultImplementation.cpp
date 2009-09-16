// =======================================================================
// Linux_DnsServiceSettingDataForServiceConfigurationDefaultImplementation.cpp
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

#include "Linux_DnsServiceSettingDataForServiceConfigurationDefaultImplementation.h"
#include "Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance.h"
#include <iostream>

namespace genProvider {

  /* intrinsic methods */
  //----------------------------------------------------------------------------	
  void
  Linux_DnsServiceSettingDataForServiceConfigurationDefaultImplementation::enumInstanceNames(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration& anInstanceNameEnumeration) {

#ifdef DEBUG
   	std::cout << "enumInstanceNames not supported for Linux_DnsServiceSettingDataForServiceConfiguration" << std::endl;
#endif   	

   	throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::NOT_IMPLEMENTED,
   	  "enumInstanceEnumeration",
   	  "Linux_DnsServiceSettingDataForServiceConfiguration");   

  }

  //----------------------------------------------------------------------------	
  void 
  Linux_DnsServiceSettingDataForServiceConfigurationDefaultImplementation::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
    std::cout << "Using default enumInstances implementation for Linux_DnsServiceSettingDataForServiceConfiguration" << std::endl;
    std::cout << "Let's get the instanceNames" << std::endl;
#endif    

    Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(aContext,aBroker,aNameSpaceP,namesEnumeration);

#ifdef DEBUG
    std::cout << "Getting each instance" << std::endl;
#endif    
    
    while (namesEnumeration.hasNext()) {
    
      Linux_DnsServiceSettingDataForServiceConfigurationInstanceName instanceName = namesEnumeration.getNext();
    
      Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance repositoryInstance;

      // try to fetch repository instance
      try {
        Linux_DnsServiceSettingDataForServiceConfigurationInstanceName repositoryInstanceName(instanceName);
        repositoryInstanceName.setNamespace("IBMShadow/cimv2");
        CmpiObjectPath repositoryCmpiObjectPath = repositoryInstanceName.getObjectPath();
        CmpiBroker cmpiBroker(aBroker);
        CmpiInstance repositoryCmpiInstance = cmpiBroker.getInstance(
            aContext,
            repositoryCmpiObjectPath,
            aPropertiesPP);
        Linux_DnsServiceSettingDataForServiceConfigurationRepositoryInstance localRepositoryInstance(
      	  repositoryCmpiInstance,
          "IBMShadow/cimv2");
        repositoryInstance = localRepositoryInstance;
      } catch (const CmpiStatus& rc) { }                             
    
#ifdef DEBUG
    	std::cout << "Getting an instance for instanceName" << std::endl;
#endif
    	
    	Linux_DnsServiceSettingDataForServiceConfigurationManualInstance instance = getInstance(
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
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstance 
  Linux_DnsServiceSettingDataForServiceConfigurationDefaultImplementation::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anInstanceName) {

#ifdef DEBUG
    std::cout << "getInstance not supported for Linux_DnsServiceSettingDataForServiceConfiguration" << std::endl;
#endif
    	

    throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::NOT_IMPLEMENTED,
   	  "getInstance",
   	  "Linux_DnsServiceSettingDataForServiceConfiguration");

  }
  	
  //----------------------------------------------------------------------------	
  void 
  Linux_DnsServiceSettingDataForServiceConfigurationDefaultImplementation::setInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsServiceSettingDataForServiceConfigurationManualInstance& aManualInstance) {
  
#ifdef DEBUG
    std::cout << "setInstance not supported for Linux_DnsServiceSettingDataForServiceConfiguration" << std::endl;
#endif
    	
   
    throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::NOT_IMPLEMENTED,
   	  "setInstance",
   	  "Linux_DnsServiceSettingDataForServiceConfiguration");
   	 
  }
  	
  //----------------------------------------------------------------------------	
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName  
  Linux_DnsServiceSettingDataForServiceConfigurationDefaultImplementation::createInstance(
    const CmpiContext& aContext, 
    const CmpiBroker& aBroker,
    const Linux_DnsServiceSettingDataForServiceConfigurationManualInstance& aManualInstance) {

#ifdef DEBUG
   	std::cout << "createInstance not supported for Linux_DnsServiceSettingDataForServiceConfiguration" << std::endl;
#endif

    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "createInstance",
   	 "Linux_DnsServiceSettingDataForServiceConfiguration");

  }

  //----------------------------------------------------------------------------	
  void 
  Linux_DnsServiceSettingDataForServiceConfigurationDefaultImplementation::deleteInstance(
    const CmpiContext& aContext, 
    const CmpiBroker& aBroker,
    const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anInstanceName) {

#ifdef DEBUG
   	std::cout << "deleteInstance not supported for Linux_DnsServiceSettingDataForServiceConfiguration" << std::endl;
#endif

    throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::NOT_IMPLEMENTED,
      "deleteInstance",
      "Linux_DnsServiceSettingDataForServiceConfiguration");

  }

  
  // Association Interface

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceSettingDataForServiceConfigurationDefaultImplementation::referencesGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceSettingDataInstanceName& aSourceInstance,
    Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration& aManualInstanceEnumeration) {
    
    throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::NOT_IMPLEMENTED,
      "References(GroupComponent)",
      "Linux_DnsServiceSettingDataForServiceConfiguration");

  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceSettingDataForServiceConfigurationDefaultImplementation::referencesPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceConfigurationInstanceName& aSourceInstance,
    Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration& aManualInstanceEnumeration) {
    
    throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::NOT_IMPLEMENTED,
      "References(PartComponent)",
      "Linux_DnsServiceSettingDataForServiceConfiguration");

  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceSettingDataForServiceConfigurationDefaultImplementation::associatorsGroupComponent(
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceSettingDataInstanceName& aSourceInstance,
    Linux_DnsServiceConfigurationInstanceEnumeration& anInstanceEnumeration) {
      
#ifdef DEBUG
    std::cout<<"Linux_DnsServiceSettingDataForServiceConfiguration : associatorsLinux_DnsServiceConfiguration() ... returns one instance"<<std::endl;
#endif    
      
    Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration manualInstanceEnumeration;
      
    referencesGroupComponent(
      aContext,
      aBroker,
      aSourceInstance.getNamespace(), 
      aPropertiesPP,
      aSourceInstance,
      manualInstanceEnumeration);

    Linux_DnsServiceConfigurationExternal external(aBroker,aContext);

    while (manualInstanceEnumeration.hasNext()) {
      const Linux_DnsServiceSettingDataForServiceConfigurationManualInstance manualInstance = manualInstanceEnumeration.getNext();
      const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName instanceName = manualInstance.getInstanceName();
      const Linux_DnsServiceConfigurationInstanceName GroupComponent = instanceName.getGroupComponent();
      Linux_DnsServiceConfigurationInstance instance = external.getInstance(aPropertiesPP,GroupComponent);
      anInstanceEnumeration.addElement(instance);
    }
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceSettingDataForServiceConfigurationDefaultImplementation::associatorsPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceConfigurationInstanceName& aSourceInstance,
    Linux_DnsServiceSettingDataInstanceEnumeration& anInstanceEnumeration) {
     
#ifdef DEBUG
    std::cout << "Linux_DnsServiceSettingDataForServiceConfiguration : associatorsLinux_DnsServiceSettingData() ... returns one instance" << std::endl;
#endif    
      
    Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration manualInstanceEnumeration;
      
    referencesPartComponent(
      aContext,
      aBroker,
      aSourceInstance.getNamespace(), 
      aPropertiesPP,
      aSourceInstance,
      manualInstanceEnumeration);

    Linux_DnsServiceSettingDataExternal external(aBroker,aContext);

    while(manualInstanceEnumeration.hasNext()) {
      const Linux_DnsServiceSettingDataForServiceConfigurationManualInstance manualInstance = manualInstanceEnumeration.getNext();
      const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName instanceName = manualInstance.getInstanceName();
      const Linux_DnsServiceSettingDataInstanceName PartComponent = instanceName.getPartComponent();
      Linux_DnsServiceSettingDataInstance instance = external.getInstance(aPropertiesPP,PartComponent);
      anInstanceEnumeration.addElement(instance);
    }

  }

  /* extrinsic methods */
  

}
