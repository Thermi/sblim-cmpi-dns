// =======================================================================
// Linux_DnsAllowQueryForZoneDefaultImplementation.cpp
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

#include "Linux_DnsAllowQueryForZoneDefaultImplementation.h"
#include "Linux_DnsAllowQueryForZoneRepositoryInstance.h"
#include <iostream>

namespace genProvider {

  /* intrinsic methods */
  //----------------------------------------------------------------------------	
  void
  Linux_DnsAllowQueryForZoneDefaultImplementation::enumInstanceNames(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    Linux_DnsAllowQueryForZoneInstanceNameEnumeration& anInstanceNameEnumeration) {

#ifdef DEBUG
   	std::cout << "enumInstanceNames not supported for Linux_DnsAllowQueryForZone" << std::endl;
#endif   	

   	throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::NOT_IMPLEMENTED,
   	  "enumInstanceEnumeration",
   	  "Linux_DnsAllowQueryForZone");   

  }

  //----------------------------------------------------------------------------	
  void 
  Linux_DnsAllowQueryForZoneDefaultImplementation::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsAllowQueryForZoneManualInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
    std::cout << "Using default enumInstances implementation for Linux_DnsAllowQueryForZone" << std::endl;
    std::cout << "Let's get the instanceNames" << std::endl;
#endif    

    Linux_DnsAllowQueryForZoneInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(aContext,aBroker,aNameSpaceP,namesEnumeration);

#ifdef DEBUG
    std::cout << "Getting each instance" << std::endl;
#endif    
    
    while (namesEnumeration.hasNext()) {
    
      Linux_DnsAllowQueryForZoneInstanceName instanceName = namesEnumeration.getNext();
    
      Linux_DnsAllowQueryForZoneRepositoryInstance repositoryInstance;

      // try to fetch repository instance
      try {
        Linux_DnsAllowQueryForZoneInstanceName repositoryInstanceName(instanceName);
        repositoryInstanceName.setNamespace("IBMShadow/cimv2");
        CmpiObjectPath repositoryCmpiObjectPath = repositoryInstanceName.getObjectPath();
        CmpiBroker cmpiBroker(aBroker);
        CmpiInstance repositoryCmpiInstance = cmpiBroker.getInstance(
            aContext,
            repositoryCmpiObjectPath,
            aPropertiesPP);
        Linux_DnsAllowQueryForZoneRepositoryInstance localRepositoryInstance(
      	  repositoryCmpiInstance,
          "IBMShadow/cimv2");
        repositoryInstance = localRepositoryInstance;
      } catch (const CmpiStatus& rc) { }                             
    
#ifdef DEBUG
    	std::cout << "Getting an instance for instanceName" << std::endl;
#endif
    	
    	Linux_DnsAllowQueryForZoneManualInstance instance = getInstance(
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
  Linux_DnsAllowQueryForZoneManualInstance 
  Linux_DnsAllowQueryForZoneDefaultImplementation::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsAllowQueryForZoneInstanceName& anInstanceName) {

#ifdef DEBUG
    std::cout << "getInstance not supported for Linux_DnsAllowQueryForZone" << std::endl;
#endif
    	

    throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::NOT_IMPLEMENTED,
   	  "getInstance",
   	  "Linux_DnsAllowQueryForZone");

  }
  	
  //----------------------------------------------------------------------------	
  void 
  Linux_DnsAllowQueryForZoneDefaultImplementation::setInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsAllowQueryForZoneManualInstance& aManualInstance) {
  
#ifdef DEBUG
    std::cout << "setInstance not supported for Linux_DnsAllowQueryForZone" << std::endl;
#endif
    	
   
    throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::NOT_IMPLEMENTED,
   	  "setInstance",
   	  "Linux_DnsAllowQueryForZone");
   	 
  }
  	
  //----------------------------------------------------------------------------	
  Linux_DnsAllowQueryForZoneInstanceName  
  Linux_DnsAllowQueryForZoneDefaultImplementation::createInstance(
    const CmpiContext& aContext, 
    const CmpiBroker& aBroker,
    const Linux_DnsAllowQueryForZoneManualInstance& aManualInstance) {

#ifdef DEBUG
   	std::cout << "createInstance not supported for Linux_DnsAllowQueryForZone" << std::endl;
#endif

    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "createInstance",
   	 "Linux_DnsAllowQueryForZone");

  }

  //----------------------------------------------------------------------------	
  void 
  Linux_DnsAllowQueryForZoneDefaultImplementation::deleteInstance(
    const CmpiContext& aContext, 
    const CmpiBroker& aBroker,
    const Linux_DnsAllowQueryForZoneInstanceName& anInstanceName) {

#ifdef DEBUG
   	std::cout << "deleteInstance not supported for Linux_DnsAllowQueryForZone" << std::endl;
#endif

    throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::NOT_IMPLEMENTED,
      "deleteInstance",
      "Linux_DnsAllowQueryForZone");

  }

  
  // Association Interface

  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowQueryForZoneDefaultImplementation::referencesGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstance,
    Linux_DnsAllowQueryForZoneManualInstanceEnumeration& aManualInstanceEnumeration) {
    
    throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::NOT_IMPLEMENTED,
      "References(GroupComponent)",
      "Linux_DnsAllowQueryForZone");

  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowQueryForZoneDefaultImplementation::referencesPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsZoneInstanceName& aSourceInstance,
    Linux_DnsAllowQueryForZoneManualInstanceEnumeration& aManualInstanceEnumeration) {
    
    throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::NOT_IMPLEMENTED,
      "References(PartComponent)",
      "Linux_DnsAllowQueryForZone");

  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowQueryForZoneDefaultImplementation::associatorsGroupComponent(
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstance,
    Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration) {
      
#ifdef DEBUG
    std::cout<<"Linux_DnsAllowQueryForZone : associatorsLinux_DnsZone() ... returns one instance"<<std::endl;
#endif    
      
    Linux_DnsAllowQueryForZoneManualInstanceEnumeration manualInstanceEnumeration;
      
    referencesGroupComponent(
      aContext,
      aBroker,
      aSourceInstance.getNamespace(), 
      aPropertiesPP,
      aSourceInstance,
      manualInstanceEnumeration);

    Linux_DnsZoneExternal external(aBroker,aContext);

    while (manualInstanceEnumeration.hasNext()) {
      const Linux_DnsAllowQueryForZoneManualInstance manualInstance = manualInstanceEnumeration.getNext();
      const Linux_DnsAllowQueryForZoneInstanceName instanceName = manualInstance.getInstanceName();
      const Linux_DnsZoneInstanceName GroupComponent = instanceName.getGroupComponent();
      Linux_DnsZoneInstance instance = external.getInstance(aPropertiesPP,GroupComponent);
      anInstanceEnumeration.addElement(instance);
    }
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowQueryForZoneDefaultImplementation::associatorsPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsZoneInstanceName& aSourceInstance,
    Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration) {
     
#ifdef DEBUG
    std::cout << "Linux_DnsAllowQueryForZone : associatorsLinux_DnsAddressMatchList() ... returns one instance" << std::endl;
#endif    
      
    Linux_DnsAllowQueryForZoneManualInstanceEnumeration manualInstanceEnumeration;
      
    referencesPartComponent(
      aContext,
      aBroker,
      aSourceInstance.getNamespace(), 
      aPropertiesPP,
      aSourceInstance,
      manualInstanceEnumeration);

    Linux_DnsAddressMatchListExternal external(aBroker,aContext);

    while(manualInstanceEnumeration.hasNext()) {
      const Linux_DnsAllowQueryForZoneManualInstance manualInstance = manualInstanceEnumeration.getNext();
      const Linux_DnsAllowQueryForZoneInstanceName instanceName = manualInstance.getInstanceName();
      const Linux_DnsAddressMatchListInstanceName PartComponent = instanceName.getPartComponent();
      Linux_DnsAddressMatchListInstance instance = external.getInstance(aPropertiesPP,PartComponent);
      anInstanceEnumeration.addElement(instance);
    }

  }

  /* extrinsic methods */
  

}
