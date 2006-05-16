// =======================================================================
// Linux_DnsSettingDefaultImplementation.cpp
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

#include "Linux_DnsSettingDefaultImplementation.h"
#include "Linux_DnsSettingRepositoryInstance.h"
#include <iostream>

namespace genProvider {

  /* intrinsic methods */
  //----------------------------------------------------------------------------	
  void
  Linux_DnsSettingDefaultImplementation::enumInstanceNames(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    Linux_DnsSettingInstanceNameEnumeration& anInstanceNameEnumeration) {

#ifdef DEBUG
   	std::cout << "enumInstanceNames not supported for Linux_DnsSetting" << std::endl;
#endif   	

   	throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::METHOD_NOT_FOUND,
   	  "enumInstanceEnumeration",
   	  "Linux_DnsSetting");   

  }

  //----------------------------------------------------------------------------	
  void 
  Linux_DnsSettingDefaultImplementation::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsSettingManualInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
    std::cout << "Using default enumInstances implementation for Linux_DnsSetting" << std::endl;
    std::cout << "Let's get the instanceNames" << std::endl;
#endif    

    Linux_DnsSettingInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(aContext,aBroker,aNameSpaceP,namesEnumeration);

#ifdef DEBUG
    std::cout << "Getting each instance" << std::endl;
#endif    
    
    while (namesEnumeration.hasNext()) {
    
      Linux_DnsSettingInstanceName instanceName = namesEnumeration.getNext();
    
      Linux_DnsSettingRepositoryInstance repositoryInstance;

      // try to fetch repository instance
      try {
        Linux_DnsSettingInstanceName repositoryInstanceName(instanceName);
        repositoryInstanceName.setNamespace("IBMShadow/cimv2");
        CmpiObjectPath repositoryCmpiObjectPath = repositoryInstanceName.getObjectPath();
        CmpiBroker cmpiBroker(aBroker);
        CmpiInstance repositoryCmpiInstance = cmpiBroker.getInstance(
            aContext,
            repositoryCmpiObjectPath,
            aPropertiesPP);
        Linux_DnsSettingRepositoryInstance localRepositoryInstance(
      	  repositoryCmpiInstance,
          "IBMShadow/cimv2");
        repositoryInstance = localRepositoryInstance;
      } catch (const CmpiStatus& rc) { }                             
    
#ifdef DEBUG
    	std::cout << "Getting an instance for instanceName" << std::endl;
#endif
    	
    	Linux_DnsSettingManualInstance instance = getInstance(
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
  Linux_DnsSettingManualInstance 
  Linux_DnsSettingDefaultImplementation::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsSettingInstanceName& anInstanceName) {

#ifdef DEBUG
    std::cout << "getInstance not supported for Linux_DnsSetting" << std::endl;
#endif
    	

    throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::METHOD_NOT_FOUND,
   	  "getInstance",
   	  "Linux_DnsSetting");

  }
  	
  //----------------------------------------------------------------------------	
  void 
  Linux_DnsSettingDefaultImplementation::setInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsSettingManualInstance& aManualInstance) {
  
#ifdef DEBUG
    std::cout << "setInstance not supported for Linux_DnsSetting" << std::endl;
#endif
    	
   
    throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::METHOD_NOT_FOUND,
   	  "setInstance",
   	  "Linux_DnsSetting");
   	 
  }
  	
  //----------------------------------------------------------------------------	
  Linux_DnsSettingInstanceName  
  Linux_DnsSettingDefaultImplementation::createInstance(
    const CmpiContext& aContext, 
    const CmpiBroker& aBroker,
    const Linux_DnsSettingManualInstance& aManualInstance) {

#ifdef DEBUG
   	std::cout << "createInstance not supported for Linux_DnsSetting" << std::endl;
#endif

    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::METHOD_NOT_FOUND,
   	 "createInstance",
   	 "Linux_DnsSetting");

  }

  //----------------------------------------------------------------------------	
  void 
  Linux_DnsSettingDefaultImplementation::deleteInstance(
    const CmpiContext& aContext, 
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName) {

#ifdef DEBUG
   	std::cout << "deleteInstance not supported for Linux_DnsSetting" << std::endl;
#endif

    throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "deleteInstance",
      "Linux_DnsSetting");

  }

  

  /* extrinsic methods */
  
  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsSettingDefaultImplementation::ApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName,
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
    std::cout << "ApplyIncrementalChangeToCollection() not supported in Linux_DnsSetting" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "ApplyIncrementalChangeToCollection",
      "Linux_DnsSetting");
      
  }

  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsSettingDefaultImplementation::ApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName,
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
    std::cout << "ApplyIncrementalChangeToMSE() not supported in Linux_DnsSetting" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "ApplyIncrementalChangeToMSE",
      "Linux_DnsSetting");
      
  }

  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsSettingDefaultImplementation::ApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName,
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
    std::cout << "ApplyToCollection() not supported in Linux_DnsSetting" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "ApplyToCollection",
      "Linux_DnsSetting");
      
  }

  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsSettingDefaultImplementation::ApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) {

#ifdef DEBUG
    std::cout << "ApplyToMSE() not supported in Linux_DnsSetting" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "ApplyToMSE",
      "Linux_DnsSetting");
      
  }

  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsSettingDefaultImplementation::VerifyOKToApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName,
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
    std::cout << "VerifyOKToApplyIncrementalChangeToCollection() not supported in Linux_DnsSetting" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "VerifyOKToApplyIncrementalChangeToCollection",
      "Linux_DnsSetting");
      
  }

  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsSettingDefaultImplementation::VerifyOKToApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName,
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
    std::cout << "VerifyOKToApplyIncrementalChangeToMSE() not supported in Linux_DnsSetting" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "VerifyOKToApplyIncrementalChangeToMSE",
      "Linux_DnsSetting");
      
  }

  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsSettingDefaultImplementation::VerifyOKToApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName,
      const CIM_CollectionOfMSEsInstanceName& Collection,
      int isCollectionPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      char**& CanNotApply,
      CMPICount& CanNotApplySize) {

#ifdef DEBUG
    std::cout << "VerifyOKToApplyToCollection() not supported in Linux_DnsSetting" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "VerifyOKToApplyToCollection",
      "Linux_DnsSetting");
      
  }

  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsSettingDefaultImplementation::VerifyOKToApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) {

#ifdef DEBUG
    std::cout << "VerifyOKToApplyToMSE() not supported in Linux_DnsSetting" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "VerifyOKToApplyToMSE",
      "Linux_DnsSetting");
      
  }


}
