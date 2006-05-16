// =======================================================================
// Linux_DnsServiceDefaultImplementation.cpp
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

#include "Linux_DnsServiceDefaultImplementation.h"
#include "Linux_DnsServiceRepositoryInstance.h"
#include <iostream>

namespace genProvider {

  /* intrinsic methods */
  //----------------------------------------------------------------------------	
  void
  Linux_DnsServiceDefaultImplementation::enumInstanceNames(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    Linux_DnsServiceInstanceNameEnumeration& anInstanceNameEnumeration) {

#ifdef DEBUG
   	std::cout << "enumInstanceNames not supported for Linux_DnsService" << std::endl;
#endif   	

   	throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::METHOD_NOT_FOUND,
   	  "enumInstanceEnumeration",
   	  "Linux_DnsService");   

  }

  //----------------------------------------------------------------------------	
  void 
  Linux_DnsServiceDefaultImplementation::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsServiceManualInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
    std::cout << "Using default enumInstances implementation for Linux_DnsService" << std::endl;
    std::cout << "Let's get the instanceNames" << std::endl;
#endif    

    Linux_DnsServiceInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(aContext,aBroker,aNameSpaceP,namesEnumeration);

#ifdef DEBUG
    std::cout << "Getting each instance" << std::endl;
#endif    
    
    while (namesEnumeration.hasNext()) {
    
      Linux_DnsServiceInstanceName instanceName = namesEnumeration.getNext();
    
      Linux_DnsServiceRepositoryInstance repositoryInstance;

      // try to fetch repository instance
      try {
        Linux_DnsServiceInstanceName repositoryInstanceName(instanceName);
        repositoryInstanceName.setNamespace("IBMShadow/cimv2");
        CmpiObjectPath repositoryCmpiObjectPath = repositoryInstanceName.getObjectPath();
        CmpiBroker cmpiBroker(aBroker);
        CmpiInstance repositoryCmpiInstance = cmpiBroker.getInstance(
            aContext,
            repositoryCmpiObjectPath,
            aPropertiesPP);
        Linux_DnsServiceRepositoryInstance localRepositoryInstance(
      	  repositoryCmpiInstance,
          "IBMShadow/cimv2");
        repositoryInstance = localRepositoryInstance;
      } catch (const CmpiStatus& rc) { }                             
    
#ifdef DEBUG
    	std::cout << "Getting an instance for instanceName" << std::endl;
#endif
    	
    	Linux_DnsServiceManualInstance instance = getInstance(
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
  Linux_DnsServiceManualInstance 
  Linux_DnsServiceDefaultImplementation::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& anInstanceName) {

#ifdef DEBUG
    std::cout << "getInstance not supported for Linux_DnsService" << std::endl;
#endif
    	

    throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::METHOD_NOT_FOUND,
   	  "getInstance",
   	  "Linux_DnsService");

  }
  	
  //----------------------------------------------------------------------------	
  void 
  Linux_DnsServiceDefaultImplementation::setInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsServiceManualInstance& aManualInstance) {
  
#ifdef DEBUG
    std::cout << "setInstance not supported for Linux_DnsService" << std::endl;
#endif
    	
   
    throw CmpiErrorFormater::getErrorException(
   	  CmpiErrorFormater::METHOD_NOT_FOUND,
   	  "setInstance",
   	  "Linux_DnsService");
   	 
  }
  	
  //----------------------------------------------------------------------------	
  Linux_DnsServiceInstanceName  
  Linux_DnsServiceDefaultImplementation::createInstance(
    const CmpiContext& aContext, 
    const CmpiBroker& aBroker,
    const Linux_DnsServiceManualInstance& aManualInstance) {

#ifdef DEBUG
   	std::cout << "createInstance not supported for Linux_DnsService" << std::endl;
#endif

    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::METHOD_NOT_FOUND,
   	 "createInstance",
   	 "Linux_DnsService");

  }

  //----------------------------------------------------------------------------	
  void 
  Linux_DnsServiceDefaultImplementation::deleteInstance(
    const CmpiContext& aContext, 
    const CmpiBroker& aBroker,
    const Linux_DnsServiceInstanceName& anInstanceName) {

#ifdef DEBUG
   	std::cout << "deleteInstance not supported for Linux_DnsService" << std::endl;
#endif

    throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "deleteInstance",
      "Linux_DnsService");

  }

  

  /* extrinsic methods */
  
  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsServiceDefaultImplementation::RequestStateChange(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceInstanceName& anInstanceName,
      const CMPIUint16& RequestedState,
      int isRequestedStatePresent,
      CIM_ConcreteJobInstanceName& Job,
      const CmpiDateTime& TimeoutPeriod,
      int isTimeoutPeriodPresent) {

#ifdef DEBUG
    std::cout << "RequestStateChange() not supported in Linux_DnsService" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "RequestStateChange",
      "Linux_DnsService");
      
  }

  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsServiceDefaultImplementation::StartService(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceInstanceName& anInstanceName) {

#ifdef DEBUG
    std::cout << "StartService() not supported in Linux_DnsService" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "StartService",
      "Linux_DnsService");
      
  }

  //----------------------------------------------------------------------------  
  CMPIUint32
  Linux_DnsServiceDefaultImplementation::StopService(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceInstanceName& anInstanceName) {

#ifdef DEBUG
    std::cout << "StopService() not supported in Linux_DnsService" << std::endl;
#endif    
    
 	  throw CmpiErrorFormater::getErrorException(
      CmpiErrorFormater::METHOD_NOT_FOUND,
      "StopService",
      "Linux_DnsService");
      
  }


}
