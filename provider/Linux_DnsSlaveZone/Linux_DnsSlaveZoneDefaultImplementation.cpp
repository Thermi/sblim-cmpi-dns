// =======================================================================
// Linux_DnsSlaveZoneDefaultImplementation.cpp
//     created on Fri, 3 Mar 2006 using ECUTE
// 
// Copyright (c) 2006, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Common Public License from
// http://oss.software.ibm.com/developerworks/opensource/license-cpl.html
//
// Author:        generated
//
// Contributors:
//                Murillo Bernardes <bernarde@br.ibm.com>
//                Wolfgang Taphorn <taphorn@de.ibm.com>
//
// =======================================================================
//
// 

#include "Linux_DnsSlaveZoneDefaultImplementation.h"
#include "Linux_DnsSlaveZoneRepositoryInstance.h"
#include <iostream>

namespace genProvider {

  /* intrinsic methods */
  //----------------------------------------------------------------------------	
  void
  Linux_DnsSlaveZoneDefaultImplementation::enumInstanceNames(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    Linux_DnsSlaveZoneInstanceNameEnumeration& anInstanceNameEnumeration) {

#ifdef DEBUG
   	std::cout << "enumInstanceNames not supported for Linux_DnsSlaveZone" << std::endl;
#endif   	

   	throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::METHOD_NOT_FOUND,
   	  "enumInstanceEnumeration",
   	  "Linux_DnsSlaveZone");   

  }

  //----------------------------------------------------------------------------	
  void 
  Linux_DnsSlaveZoneDefaultImplementation::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsSlaveZoneManualInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
    std::cout << "Using default enumInstances implementation for Linux_DnsSlaveZone" << std::endl;
    std::cout << "Let's get the instanceNames" << std::endl;
#endif    

    Linux_DnsSlaveZoneInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(aContext,aBroker,aNameSpaceP,namesEnumeration);

#ifdef DEBUG
    std::cout << "Getting each instance" << std::endl;
#endif    
    
    while (namesEnumeration.hasNext()) {
    
      Linux_DnsSlaveZoneInstanceName instanceName = namesEnumeration.getNext();
    
      Linux_DnsSlaveZoneRepositoryInstance repositoryInstance;

      // try to fetch repository instance
      try {
        Linux_DnsSlaveZoneInstanceName repositoryInstanceName(instanceName);
        repositoryInstanceName.setNamespace("IBMShadow/cimv2");
        CmpiObjectPath repositoryCmpiObjectPath = repositoryInstanceName.getObjectPath();
        CmpiBroker cmpiBroker(aBroker);
        CmpiInstance repositoryCmpiInstance = cmpiBroker.getInstance(
            aContext,
            repositoryCmpiObjectPath,
            aPropertiesPP);
        Linux_DnsSlaveZoneRepositoryInstance localRepositoryInstance(
      	  repositoryCmpiInstance,
          "IBMShadow/cimv2");
        repositoryInstance = localRepositoryInstance;
      } catch (const CmpiStatus& rc) { }                             
    
#ifdef DEBUG
    	std::cout << "Getting an instance for instanceName" << std::endl;
#endif
    	
    	Linux_DnsSlaveZoneManualInstance instance = getInstance(
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
  Linux_DnsSlaveZoneManualInstance 
  Linux_DnsSlaveZoneDefaultImplementation::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName) {

#ifdef DEBUG
    std::cout << "getInstance not supported for Linux_DnsSlaveZone" << std::endl;
#endif
    	

    throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::METHOD_NOT_FOUND,
   	  "getInstance",
   	  "Linux_DnsSlaveZone");

  }
  	
  //----------------------------------------------------------------------------	
  void 
  Linux_DnsSlaveZoneDefaultImplementation::setInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsSlaveZoneManualInstance& aManualInstance) {
  
#ifdef DEBUG
    std::cout << "setInstance not supported for Linux_DnsSlaveZone" << std::endl;
#endif
    	
   
    throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::METHOD_NOT_FOUND,
   	  "setInstance",
   	  "Linux_DnsSlaveZone");
   	 
  }
  	
  //----------------------------------------------------------------------------	
  Linux_DnsSlaveZoneInstanceName  
  Linux_DnsSlaveZoneDefaultImplementation::createInstance(
    const CmpiContext& aContext, 
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneManualInstance& aManualInstance) {

#ifdef DEBUG
   	std::cout << "createInstance not supported for Linux_DnsSlaveZone" << std::endl;
#endif

    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::METHOD_NOT_FOUND,
   	 "createInstance",
   	 "Linux_DnsSlaveZone");

  }

  //----------------------------------------------------------------------------	
  void 
  Linux_DnsSlaveZoneDefaultImplementation::deleteInstance(
    const CmpiContext& aContext, 
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName) {

#ifdef DEBUG
   	std::cout << "deleteInstance not supported for Linux_DnsSlaveZone" << std::endl;
#endif

    throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "deleteInstance",
      "Linux_DnsSlaveZone");

  }

  

  /* extrinsic methods */
  
  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsSlaveZoneDefaultImplementation::ApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName,
      const CIM_CollectionOfMSEsInstanceName& Collection,
      int isCollectionPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CMPIBoolean& ContinueOnError,
      int isContinueOnErrorPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent,
      char**& CanNotApply,
      CMPICount& CanNotApplySize) {

#ifdef DEBUG
    std::cout << "ApplyIncrementalChangeToCollection() not supported in Linux_DnsSlaveZone" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "ApplyIncrementalChangeToCollection",
      "Linux_DnsSlaveZone");
      
  }

  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsSlaveZoneDefaultImplementation::ApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent) {

#ifdef DEBUG
    std::cout << "ApplyIncrementalChangeToMSE() not supported in Linux_DnsSlaveZone" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "ApplyIncrementalChangeToMSE",
      "Linux_DnsSlaveZone");
      
  }

  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsSlaveZoneDefaultImplementation::ApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName,
      const CIM_CollectionOfMSEsInstanceName& Collection,
      int isCollectionPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CMPIBoolean& ContinueOnError,
      int isContinueOnErrorPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      char**& CanNotApply,
      CMPICount& CanNotApplySize) {

#ifdef DEBUG
    std::cout << "ApplyToCollection() not supported in Linux_DnsSlaveZone" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "ApplyToCollection",
      "Linux_DnsSlaveZone");
      
  }

  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsSlaveZoneDefaultImplementation::ApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) {

#ifdef DEBUG
    std::cout << "ApplyToMSE() not supported in Linux_DnsSlaveZone" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "ApplyToMSE",
      "Linux_DnsSlaveZone");
      
  }

  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsSlaveZoneDefaultImplementation::VerifyOKToApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName,
      const CIM_CollectionOfMSEsInstanceName& Collection,
      int isCollectionPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent,
      char**& CanNotApply,
      CMPICount& CanNotApplySize) {

#ifdef DEBUG
    std::cout << "VerifyOKToApplyIncrementalChangeToCollection() not supported in Linux_DnsSlaveZone" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "VerifyOKToApplyIncrementalChangeToCollection",
      "Linux_DnsSlaveZone");
      
  }

  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsSlaveZoneDefaultImplementation::VerifyOKToApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent) {

#ifdef DEBUG
    std::cout << "VerifyOKToApplyIncrementalChangeToMSE() not supported in Linux_DnsSlaveZone" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "VerifyOKToApplyIncrementalChangeToMSE",
      "Linux_DnsSlaveZone");
      
  }

  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsSlaveZoneDefaultImplementation::VerifyOKToApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName,
      const CIM_CollectionOfMSEsInstanceName& Collection,
      int isCollectionPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      char**& CanNotApply,
      CMPICount& CanNotApplySize) {

#ifdef DEBUG
    std::cout << "VerifyOKToApplyToCollection() not supported in Linux_DnsSlaveZone" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "VerifyOKToApplyToCollection",
      "Linux_DnsSlaveZone");
      
  }

  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsSlaveZoneDefaultImplementation::VerifyOKToApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) {

#ifdef DEBUG
    std::cout << "VerifyOKToApplyToMSE() not supported in Linux_DnsSlaveZone" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "VerifyOKToApplyToMSE",
      "Linux_DnsSlaveZone");
      
  }


}
