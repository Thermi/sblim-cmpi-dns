// =======================================================================
// CmpiLinux_DnsIPAddressProvider.cpp
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
#include "CmpiLinux_DnsIPAddressProvider.h"
#include "ArrayConverter.h"
#include "Linux_DnsIPAddressManualInstance.h"
#include "Linux_DnsIPAddressRepositoryInstance.h"


#include <iostream>
#include <strings.h>

namespace genProvider {

  //----------------------------------------------------------------------------
  CmpiLinux_DnsIPAddressProvider::CmpiLinux_DnsIPAddressProvider(
    const CmpiBroker& aBroker, 
    const CmpiContext& aContext)
    : CmpiBaseMI(aBroker,aContext), 
    CmpiInstanceMI(aBroker,aContext),
    CmpiMethodMI(aBroker,aContext),
    m_cmpiBroker(aBroker) {
      
    m_interfaceP = Linux_DnsIPAddressFactory::getImplementation();           

#ifdef DEBUG 
    std::cout << "Provider was constructed" << std::endl;
#endif    
  
  }
        
  //----------------------------------------------------------------------------
  CmpiLinux_DnsIPAddressProvider::~CmpiLinux_DnsIPAddressProvider() {
    delete m_interfaceP;
  }
  
  //----------------------------------------------------------------------------
  int 
  CmpiLinux_DnsIPAddressProvider::isUnloadable() const {
    return 0;
  }
	
  //----------------------------------------------------------------------------
  void 
  CmpiLinux_DnsIPAddressProvider::completeInstance(
    const Linux_DnsIPAddressInstanceName& anInstanceName,
    CmpiInstance& anInstance, 
    const CmpiContext& aContext) {
	  	
    Linux_DnsIPAddressInstanceName shadowInstanceName(anInstanceName);
    shadowInstanceName.setNamespace("IBMShadow/cimv2");
    CmpiObjectPath cmpiObjectPath = shadowInstanceName.getObjectPath();
	  
    try {
      const char* propertiesP = 0;
      CmpiInstance shadowInstance = m_cmpiBroker.getInstance(
        aContext, 
        cmpiObjectPath,
        &propertiesP);
      copyShadowData(&shadowInstance,&anInstance);
    } catch (const CmpiStatus& rc) {}                             
  
  }
	
  //----------------------------------------------------------------------------
  void 
  CmpiLinux_DnsIPAddressProvider::copyShadowData(
    const CmpiInstance* aSourceInstanceP, 
    CmpiInstance* aTargetInstanceP) {

    if (aSourceInstanceP && aTargetInstanceP) {
      
    }

  }

  //----------------------------------------------------------------------------
  CmpiInstance* 
  CmpiLinux_DnsIPAddressProvider::getShadowInstance(
    const CmpiInstance& anInstance,
    const Linux_DnsIPAddressInstanceName& anInstanceName) {
     
    Linux_DnsIPAddressInstanceName shadowInstanceName(anInstanceName);
    shadowInstanceName.setNamespace("IBMShadow/cimv2");
    CmpiObjectPath cmpiObjectPath = shadowInstanceName.getObjectPath();
      
    CmpiInstance* targetP = new CmpiInstance(cmpiObjectPath);
      
    if (targetP) {
      copyShadowData(&anInstance,targetP);
      if (0 == targetP->getPropertyCount()) {
        delete targetP;
        targetP = 0;
      }
    }
  
    return targetP;
  
  }

  //----------------------------------------------------------------------------
  void
  CmpiLinux_DnsIPAddressProvider::removeDanglingShadowInstances (
   const Linux_DnsIPAddressInstanceNameEnumeration& anInstanceNameEnumerations) {
	
    // TODO: enumerate shadow instance names and remove those not included
	  // in anInstanceNameEnumeration
	
  }
	
  //----------------------------------------------------------------------------
  //                          Provider Factory
  //----------------------------------------------------------------------------
  CMProviderBase(CmpiLinux_DnsIPAddressProvider);

  CMInstanceMIFactory(
    CmpiLinux_DnsIPAddressProvider, 
    CmpiLinux_DnsIPAddressProvider);

  CMMethodMIFactory(
    CmpiLinux_DnsIPAddressProvider, 
    CmpiLinux_DnsIPAddressProvider);
	
	
  //----------------------------------------------------------------------------
  //                      Instance Provider Interface
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  CmpiStatus 
  CmpiLinux_DnsIPAddressProvider::enumInstanceNames(
    const CmpiContext& aContext, 
    CmpiResult& aResult,
    const CmpiObjectPath& aCop) {
      
#ifdef DEBUG 
    std::cout << "enumerating instanceNames" << std::endl;
#endif

    CmpiString nameSpace = aCop.getNameSpace();
    const char* nameSpaceP = nameSpace.charPtr();

    Linux_DnsIPAddressInstanceNameEnumeration enumeration;
    m_interfaceP->enumInstanceNames(
      aContext,
      m_cmpiBroker,
      nameSpaceP,
      enumeration);
                   
    while (enumeration.hasNext() ){
      const Linux_DnsIPAddressInstanceName& instanceName = enumeration.getNext();
      CmpiObjectPath objectPath = instanceName.getObjectPath();
      aResult.returnData(objectPath);
    }
      
    // we make housekeeping
    removeDanglingShadowInstances(enumeration);
      
    aResult.returnDone();
    return CmpiStatus(CMPI_RC_OK);

  }

  //----------------------------------------------------------------------------
  CmpiStatus 
  CmpiLinux_DnsIPAddressProvider::enumInstances(
    const CmpiContext& aContext,
    CmpiResult& aResult,
    const CmpiObjectPath& aCop, 
    const char** aPropertiesPP) {
     
#ifdef DEBUG 
    std::cout << "enumerating instances" << std::endl;
#endif

    CmpiString nameSpace = aCop.getNameSpace();
    const char* nameSpaceP = nameSpace.charPtr();
      
    Linux_DnsIPAddressManualInstanceEnumeration enumeration;
    m_interfaceP->enumInstances(
      aContext, 
      m_cmpiBroker, 
      nameSpaceP, 
      aPropertiesPP,
      enumeration);

#ifdef DEBUG 
    std::cout << "enumerated" << std::endl;
#endif
      
    while (enumeration.hasNext()) {
   	  const Linux_DnsIPAddressManualInstance& instance = enumeration.getNext();
      	
#ifdef DEBUG 
      std::cout << "enumerating getNext" << std::endl;
#endif
      	
      CmpiInstance cmpiInstance = instance.getCmpiInstance(aPropertiesPP);

#ifdef DEBUG 
      std::cout << "transformed" << std::endl;
#endif
      	
      //add the static data
      // MJ: No, this is done in the implementation (or DefaultImplementation)
      // completeInstance(instance.getInstanceName(),cmpiInstance,aContext);
      	
      aResult.returnData(cmpiInstance);
    
    }
      
    aResult.returnDone();
    return CmpiStatus(CMPI_RC_OK);
  
  }
    
  //----------------------------------------------------------------------------
  CmpiStatus 
  CmpiLinux_DnsIPAddressProvider::getInstance (
    const CmpiContext& aContext, 
    CmpiResult& aResult,
    const CmpiObjectPath& aCop,
    const char** aPropertiesPP) {
     	
    // convert to instanceName
    Linux_DnsIPAddressInstanceName instanceName(aCop);
    
    CmpiInstance* repositoryCmpiInstanceP = 0;
    
    // try to fetch repository instance
    try {
      Linux_DnsIPAddressInstanceName repositoryInstanceName(instanceName);
      repositoryInstanceName.setNamespace("IBMShadow/cimv2");
      CmpiObjectPath repositoryCmpiObjectPath = repositoryInstanceName.getObjectPath();
      repositoryCmpiInstanceP = new CmpiInstance(
        m_cmpiBroker.getInstance(
          aContext, 
          repositoryCmpiObjectPath,
          aPropertiesPP));
    } catch (const CmpiStatus& rc) { }                             
      
    // get instance for instanceName
    Linux_DnsIPAddressManualInstance instance;
    instance = m_interfaceP->getInstance(
      aContext,
      m_cmpiBroker,
      aPropertiesPP,
      instanceName);
      
    // convert the instance in a cmpiInstance
    CmpiInstance cmpiInstance = instance.getCmpiInstance(aPropertiesPP);
      
    // add the static data 
    copyShadowData(repositoryCmpiInstanceP,&cmpiInstance);
      
    if (repositoryCmpiInstanceP) {
      delete repositoryCmpiInstanceP;
    }

    aResult.returnData(cmpiInstance);
    aResult.returnDone();
    return CmpiStatus(CMPI_RC_OK);

  }
    
  //----------------------------------------------------------------------------
  CmpiStatus 
  CmpiLinux_DnsIPAddressProvider::createInstance (
    const CmpiContext& aContext,
    CmpiResult& aResult,
    const CmpiObjectPath& aCop,
    const CmpiInstance& aCmpiInstance) {
   	
   	Linux_DnsIPAddressManualInstance manualInstance(
      aCmpiInstance,
      aCop.getNameSpace().charPtr());
    
    //REPOSITORY DATA    
//    CmpiInstance* backupShadowInstanceP = 0;
//   	CmpiInstance shadowInstance = 
//   	  Linux_DnsIPAddressRepositoryInstance(aCmpiInstance,"IBMShadow/cimv2").getCmpiInstance(0);     
//     
//   	//We keep a backup of the existing data for recovering previous
//   	//state if the resource access raise an exception
//   	CmpiObjectPath shadowOp = shadowInstance.getObjectPath();
//    try {
//   	  backupShadowInstanceP = new CmpiInstance(
//        m_cmpiBroker.getInstance(aContext,shadowOp,0));
//   	  //if the shadow instance exist we delete it
//   	  m_cmpiBroker.deleteInstance(aContext,shadowOp);   	    
//   	} catch (CmpiStatus& rc) {}   	
//    m_cmpiBroker.createInstance(aContext,shadowOp,shadowInstance);     
//    
//    // resource access data (manual instance)   
    try { 
        aResult.returnData(m_interfaceP->createInstance(aContext, m_cmpiBroker, manualInstance).
			getObjectPath());
    } catch (CmpiStatus& rc) {
//      //If something went wrong we recover the previous state
//      m_cmpiBroker.deleteInstance(aContext,shadowOp);
//      if (backupShadowInstanceP) {
//        m_cmpiBroker.createInstance(aContext,shadowOp,*backupShadowInstanceP);
//      }
      throw rc;
    }
    
//    if (backupShadowInstanceP) {
//      delete(backupShadowInstanceP);
//    }
    
    aResult.returnDone();
    return CmpiStatus(CMPI_RC_OK);
  
  }
    
  //----------------------------------------------------------------------------
  CmpiStatus 
  CmpiLinux_DnsIPAddressProvider::setInstance (
    const CmpiContext& aContext,
    CmpiResult& aResult,
    const CmpiObjectPath& aCop,
    const CmpiInstance& aCmpiInstance,
    const char** aPropertiesPP) {
   	
   	Linux_DnsIPAddressManualInstance manualInstance(
      aCmpiInstance,
      aCop.getNameSpace().charPtr());
    
    //REPOSITORY DATA    
//    CmpiInstance* backupShadowInstanceP = 0;
//    CmpiInstance shadowInstance =
//      Linux_DnsIPAddressRepositoryInstance(aCmpiInstance,"IBMShadow/cimv2").getCmpiInstance(0);     
//     
//   	//We keep a backup of the existing data for recovering previous
//   	//state if the resource access raise an exception
//   	CmpiObjectPath shadowOp = shadowInstance.getObjectPath();
//    try {
//   	  backupShadowInstanceP = new CmpiInstance(
//   	   m_cmpiBroker.getInstance(aContext,shadowOp,0));
//   	} catch (CmpiStatus& rc) {}   	
//    
//    //if the instance existed before we delete it
//    //(setInstance is buggy in Pegasus)
//    if (backupShadowInstanceP) {
//      m_cmpiBroker.setInstance(aContext,shadowOp,shadowInstance,aPropertiesPP);
//    } else {
//      m_cmpiBroker.createInstance(aContext,shadowOp,shadowInstance);
//    }
    
    // resource access data (manual instance)   
    try {
      m_interfaceP->setInstance(aContext,m_cmpiBroker,aPropertiesPP,manualInstance);
    } catch (CmpiStatus& rc) {
      //If something went wrong we recover the previous state
//      m_cmpiBroker.deleteInstance(aContext,shadowOp);
//      if (backupShadowInstanceP) {
//        m_cmpiBroker.createInstance(aContext,shadowOp,*backupShadowInstanceP);
//      }
      throw rc;
    }
      
//    if (backupShadowInstanceP) {
//      delete backupShadowInstanceP;
//    }
        
    aResult.returnDone();
    return CmpiStatus(CMPI_RC_OK);
    
  }
    
  //----------------------------------------------------------------------------
  CmpiStatus
  CmpiLinux_DnsIPAddressProvider::deleteInstance(
    const CmpiContext& aContext,
    CmpiResult& aResult,
    const CmpiObjectPath& aCop) {
      
    Linux_DnsIPAddressInstanceName instanceName = Linux_DnsIPAddressInstanceName(aCop);
    m_interfaceP->deleteInstance(aContext,m_cmpiBroker,instanceName);

    instanceName.setNamespace("IBMShadow/cimv2");
    CmpiObjectPath op = instanceName.getObjectPath();
      
    try { // The instance could not have static data
      m_cmpiBroker.deleteInstance(aContext,op);
    } catch (CmpiStatus& rc) {}
      
    aResult.returnDone();
    return CmpiStatus(CMPI_RC_OK);
  
  }
    
  //----------------------------------------------------------------------------
  CmpiStatus
  CmpiLinux_DnsIPAddressProvider::invokeMethod(
    const CmpiContext& aContext,
    CmpiResult& aResult,
    const CmpiObjectPath& aCop,
    const char* aMethodNameP,
    const CmpiArgs& in,
    CmpiArgs& out) {
     	
    Linux_DnsIPAddressInstanceName instanceName = Linux_DnsIPAddressInstanceName(aCop);
     
    if (0 == strcasecmp(aMethodNameP,"ApplyIncrementalChangeToCollection")) {

#ifdef DEBUG
      std::cout << "executing method ApplyIncrementalChangeToCollection" << std::endl;
#endif      

      int isCollectionPresent = 0;
      CIM_CollectionOfMSEsInstanceName  Collection;
      try {
        CmpiData CollectionCmpiData = in.getArg("Collection");
        isCollectionPresent = ! CollectionCmpiData.isNullValue();
        if (isCollectionPresent) {
          CmpiObjectPath CollectionCmpi = CollectionCmpiData;
          Collection = CIM_CollectionOfMSEsInstanceName(CollectionCmpi);
        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isTimeToApplyPresent = 0;
      CmpiDateTime TimeToApply;
      try {
        CmpiData TimeToApplyCmpiData = in.getArg("TimeToApply");
        isTimeToApplyPresent = ! TimeToApplyCmpiData.isNullValue();
        if (isTimeToApplyPresent) {
           TimeToApply = TimeToApplyCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isContinueOnErrorPresent = 0;
      CMPIBoolean ContinueOnError;
      try {
        CmpiData ContinueOnErrorCmpiData = in.getArg("ContinueOnError");
        isContinueOnErrorPresent = ! ContinueOnErrorCmpiData.isNullValue();
        if (isContinueOnErrorPresent) {
           ContinueOnError = ContinueOnErrorCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isMustBeCompletedByPresent = 0;
      CmpiDateTime MustBeCompletedBy;
      try {
        CmpiData MustBeCompletedByCmpiData = in.getArg("MustBeCompletedBy");
        isMustBeCompletedByPresent = ! MustBeCompletedByCmpiData.isNullValue();
        if (isMustBeCompletedByPresent) {
           MustBeCompletedBy = MustBeCompletedByCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isPropertiesToApplyPresent = 0;
      char** PropertiesToApply=0;
      CMPICount PropertiesToApplySize = 0;
      try {
        CmpiData PropertiesToApplyCmpiData = in.getArg("PropertiesToApply");
        isPropertiesToApplyPresent = ! PropertiesToApplyCmpiData.isNullValue();
        if (isPropertiesToApplyPresent) {
          CmpiArray PropertiesToApplyCmpi = PropertiesToApplyCmpiData;
          PropertiesToApplySize = PropertiesToApplyCmpi.size();
          ArrayConverter::makeArray(
            PropertiesToApplyCmpi,
            &PropertiesToApply,
            PropertiesToApplySize);
        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      char** CanNotApply;

      CMPICount CanNotApplySize;
        
      aResult.returnData(CmpiData(m_interfaceP->ApplyIncrementalChangeToCollection(
        aContext,
        m_cmpiBroker,
        instanceName,
        Collection,
        isCollectionPresent,
        TimeToApply,
        isTimeToApplyPresent,
        ContinueOnError,
        isContinueOnErrorPresent,
        MustBeCompletedBy,
        isMustBeCompletedByPresent,
        (const char**) PropertiesToApply,
        PropertiesToApplySize,
        isPropertiesToApplyPresent,
        CanNotApply,
        CanNotApplySize)));

      out.setArg("CanNotApply",CmpiData(ArrayConverter::makeCmpiArray((const char**) CanNotApply, CanNotApplySize)));

      if (PropertiesToApply) {
        ArrayConverter::destructArray(
          PropertiesToApply,
          PropertiesToApplySize);
      }
      if (CanNotApply) {
        ArrayConverter::destructArray(
          CanNotApply,
          CanNotApplySize);
      }

#ifdef DEBUG
      std::cout << "end of method ApplyIncrementalChangeToCollection" << std::endl;
#endif      
           
    } else if (0 == strcasecmp(aMethodNameP,"ApplyIncrementalChangeToMSE")) {

#ifdef DEBUG
      std::cout << "executing method ApplyIncrementalChangeToMSE" << std::endl;
#endif      

      int isMSEPresent = 0;
      CIM_ManagedSystemElementInstanceName  MSE;
      try {
        CmpiData MSECmpiData = in.getArg("MSE");
        isMSEPresent = ! MSECmpiData.isNullValue();
        if (isMSEPresent) {
          CmpiObjectPath MSECmpi = MSECmpiData;
          MSE = CIM_ManagedSystemElementInstanceName(MSECmpi);
        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isTimeToApplyPresent = 0;
      CmpiDateTime TimeToApply;
      try {
        CmpiData TimeToApplyCmpiData = in.getArg("TimeToApply");
        isTimeToApplyPresent = ! TimeToApplyCmpiData.isNullValue();
        if (isTimeToApplyPresent) {
           TimeToApply = TimeToApplyCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isMustBeCompletedByPresent = 0;
      CmpiDateTime MustBeCompletedBy;
      try {
        CmpiData MustBeCompletedByCmpiData = in.getArg("MustBeCompletedBy");
        isMustBeCompletedByPresent = ! MustBeCompletedByCmpiData.isNullValue();
        if (isMustBeCompletedByPresent) {
           MustBeCompletedBy = MustBeCompletedByCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isPropertiesToApplyPresent = 0;
      char** PropertiesToApply=0;
      CMPICount PropertiesToApplySize = 0;
      try {
        CmpiData PropertiesToApplyCmpiData = in.getArg("PropertiesToApply");
        isPropertiesToApplyPresent = ! PropertiesToApplyCmpiData.isNullValue();
        if (isPropertiesToApplyPresent) {
          CmpiArray PropertiesToApplyCmpi = PropertiesToApplyCmpiData;
          PropertiesToApplySize = PropertiesToApplyCmpi.size();
          ArrayConverter::makeArray(
            PropertiesToApplyCmpi,
            &PropertiesToApply,
            PropertiesToApplySize);
        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }
        
      aResult.returnData(CmpiData(m_interfaceP->ApplyIncrementalChangeToMSE(
        aContext,
        m_cmpiBroker,
        instanceName,
        MSE,
        isMSEPresent,
        TimeToApply,
        isTimeToApplyPresent,
        MustBeCompletedBy,
        isMustBeCompletedByPresent,
        (const char**) PropertiesToApply,
        PropertiesToApplySize,
        isPropertiesToApplyPresent)));


      if (PropertiesToApply) {
        ArrayConverter::destructArray(
          PropertiesToApply,
          PropertiesToApplySize);
      }

#ifdef DEBUG
      std::cout << "end of method ApplyIncrementalChangeToMSE" << std::endl;
#endif      
           
    } else if (0 == strcasecmp(aMethodNameP,"ApplyToCollection")) {

#ifdef DEBUG
      std::cout << "executing method ApplyToCollection" << std::endl;
#endif      

      int isCollectionPresent = 0;
      CIM_CollectionOfMSEsInstanceName  Collection;
      try {
        CmpiData CollectionCmpiData = in.getArg("Collection");
        isCollectionPresent = ! CollectionCmpiData.isNullValue();
        if (isCollectionPresent) {
          CmpiObjectPath CollectionCmpi = CollectionCmpiData;
          Collection = CIM_CollectionOfMSEsInstanceName(CollectionCmpi);
        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isTimeToApplyPresent = 0;
      CmpiDateTime TimeToApply;
      try {
        CmpiData TimeToApplyCmpiData = in.getArg("TimeToApply");
        isTimeToApplyPresent = ! TimeToApplyCmpiData.isNullValue();
        if (isTimeToApplyPresent) {
           TimeToApply = TimeToApplyCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isContinueOnErrorPresent = 0;
      CMPIBoolean ContinueOnError;
      try {
        CmpiData ContinueOnErrorCmpiData = in.getArg("ContinueOnError");
        isContinueOnErrorPresent = ! ContinueOnErrorCmpiData.isNullValue();
        if (isContinueOnErrorPresent) {
           ContinueOnError = ContinueOnErrorCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isMustBeCompletedByPresent = 0;
      CmpiDateTime MustBeCompletedBy;
      try {
        CmpiData MustBeCompletedByCmpiData = in.getArg("MustBeCompletedBy");
        isMustBeCompletedByPresent = ! MustBeCompletedByCmpiData.isNullValue();
        if (isMustBeCompletedByPresent) {
           MustBeCompletedBy = MustBeCompletedByCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      char** CanNotApply;

      CMPICount CanNotApplySize;
        
      aResult.returnData(CmpiData(m_interfaceP->ApplyToCollection(
        aContext,
        m_cmpiBroker,
        instanceName,
        Collection,
        isCollectionPresent,
        TimeToApply,
        isTimeToApplyPresent,
        ContinueOnError,
        isContinueOnErrorPresent,
        MustBeCompletedBy,
        isMustBeCompletedByPresent,
        CanNotApply,
        CanNotApplySize)));

      out.setArg("CanNotApply",CmpiData(ArrayConverter::makeCmpiArray((const char**) CanNotApply, CanNotApplySize)));

      if (CanNotApply) {
        ArrayConverter::destructArray(
          CanNotApply,
          CanNotApplySize);
      }

#ifdef DEBUG
      std::cout << "end of method ApplyToCollection" << std::endl;
#endif      
           
    } else if (0 == strcasecmp(aMethodNameP,"ApplyToMSE")) {

#ifdef DEBUG
      std::cout << "executing method ApplyToMSE" << std::endl;
#endif      

      int isMSEPresent = 0;
      CIM_ManagedSystemElementInstanceName  MSE;
      try {
        CmpiData MSECmpiData = in.getArg("MSE");
        isMSEPresent = ! MSECmpiData.isNullValue();
        if (isMSEPresent) {
          CmpiObjectPath MSECmpi = MSECmpiData;
          MSE = CIM_ManagedSystemElementInstanceName(MSECmpi);
        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isTimeToApplyPresent = 0;
      CmpiDateTime TimeToApply;
      try {
        CmpiData TimeToApplyCmpiData = in.getArg("TimeToApply");
        isTimeToApplyPresent = ! TimeToApplyCmpiData.isNullValue();
        if (isTimeToApplyPresent) {
           TimeToApply = TimeToApplyCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isMustBeCompletedByPresent = 0;
      CmpiDateTime MustBeCompletedBy;
      try {
        CmpiData MustBeCompletedByCmpiData = in.getArg("MustBeCompletedBy");
        isMustBeCompletedByPresent = ! MustBeCompletedByCmpiData.isNullValue();
        if (isMustBeCompletedByPresent) {
           MustBeCompletedBy = MustBeCompletedByCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }
        
      aResult.returnData(CmpiData(m_interfaceP->ApplyToMSE(
        aContext,
        m_cmpiBroker,
        instanceName,
        MSE,
        isMSEPresent,
        TimeToApply,
        isTimeToApplyPresent,
        MustBeCompletedBy,
        isMustBeCompletedByPresent)));



#ifdef DEBUG
      std::cout << "end of method ApplyToMSE" << std::endl;
#endif      
           
    } else if (0 == strcasecmp(aMethodNameP,"VerifyOKToApplyIncrementalChangeToCollection")) {

#ifdef DEBUG
      std::cout << "executing method VerifyOKToApplyIncrementalChangeToCollection" << std::endl;
#endif      

      int isCollectionPresent = 0;
      CIM_CollectionOfMSEsInstanceName  Collection;
      try {
        CmpiData CollectionCmpiData = in.getArg("Collection");
        isCollectionPresent = ! CollectionCmpiData.isNullValue();
        if (isCollectionPresent) {
          CmpiObjectPath CollectionCmpi = CollectionCmpiData;
          Collection = CIM_CollectionOfMSEsInstanceName(CollectionCmpi);
        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isTimeToApplyPresent = 0;
      CmpiDateTime TimeToApply;
      try {
        CmpiData TimeToApplyCmpiData = in.getArg("TimeToApply");
        isTimeToApplyPresent = ! TimeToApplyCmpiData.isNullValue();
        if (isTimeToApplyPresent) {
           TimeToApply = TimeToApplyCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isMustBeCompletedByPresent = 0;
      CmpiDateTime MustBeCompletedBy;
      try {
        CmpiData MustBeCompletedByCmpiData = in.getArg("MustBeCompletedBy");
        isMustBeCompletedByPresent = ! MustBeCompletedByCmpiData.isNullValue();
        if (isMustBeCompletedByPresent) {
           MustBeCompletedBy = MustBeCompletedByCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isPropertiesToApplyPresent = 0;
      char** PropertiesToApply=0;
      CMPICount PropertiesToApplySize = 0;
      try {
        CmpiData PropertiesToApplyCmpiData = in.getArg("PropertiesToApply");
        isPropertiesToApplyPresent = ! PropertiesToApplyCmpiData.isNullValue();
        if (isPropertiesToApplyPresent) {
          CmpiArray PropertiesToApplyCmpi = PropertiesToApplyCmpiData;
          PropertiesToApplySize = PropertiesToApplyCmpi.size();
          ArrayConverter::makeArray(
            PropertiesToApplyCmpi,
            &PropertiesToApply,
            PropertiesToApplySize);
        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      char** CanNotApply;

      CMPICount CanNotApplySize;
        
      aResult.returnData(CmpiData(m_interfaceP->VerifyOKToApplyIncrementalChangeToCollection(
        aContext,
        m_cmpiBroker,
        instanceName,
        Collection,
        isCollectionPresent,
        TimeToApply,
        isTimeToApplyPresent,
        MustBeCompletedBy,
        isMustBeCompletedByPresent,
        (const char**) PropertiesToApply,
        PropertiesToApplySize,
        isPropertiesToApplyPresent,
        CanNotApply,
        CanNotApplySize)));

      out.setArg("CanNotApply",CmpiData(ArrayConverter::makeCmpiArray((const char**) CanNotApply, CanNotApplySize)));

      if (PropertiesToApply) {
        ArrayConverter::destructArray(
          PropertiesToApply,
          PropertiesToApplySize);
      }
      if (CanNotApply) {
        ArrayConverter::destructArray(
          CanNotApply,
          CanNotApplySize);
      }

#ifdef DEBUG
      std::cout << "end of method VerifyOKToApplyIncrementalChangeToCollection" << std::endl;
#endif      
           
    } else if (0 == strcasecmp(aMethodNameP,"VerifyOKToApplyIncrementalChangeToMSE")) {

#ifdef DEBUG
      std::cout << "executing method VerifyOKToApplyIncrementalChangeToMSE" << std::endl;
#endif      

      int isMSEPresent = 0;
      CIM_ManagedSystemElementInstanceName  MSE;
      try {
        CmpiData MSECmpiData = in.getArg("MSE");
        isMSEPresent = ! MSECmpiData.isNullValue();
        if (isMSEPresent) {
          CmpiObjectPath MSECmpi = MSECmpiData;
          MSE = CIM_ManagedSystemElementInstanceName(MSECmpi);
        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isTimeToApplyPresent = 0;
      CmpiDateTime TimeToApply;
      try {
        CmpiData TimeToApplyCmpiData = in.getArg("TimeToApply");
        isTimeToApplyPresent = ! TimeToApplyCmpiData.isNullValue();
        if (isTimeToApplyPresent) {
           TimeToApply = TimeToApplyCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isMustBeCompletedByPresent = 0;
      CmpiDateTime MustBeCompletedBy;
      try {
        CmpiData MustBeCompletedByCmpiData = in.getArg("MustBeCompletedBy");
        isMustBeCompletedByPresent = ! MustBeCompletedByCmpiData.isNullValue();
        if (isMustBeCompletedByPresent) {
           MustBeCompletedBy = MustBeCompletedByCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isPropertiesToApplyPresent = 0;
      char** PropertiesToApply=0;
      CMPICount PropertiesToApplySize = 0;
      try {
        CmpiData PropertiesToApplyCmpiData = in.getArg("PropertiesToApply");
        isPropertiesToApplyPresent = ! PropertiesToApplyCmpiData.isNullValue();
        if (isPropertiesToApplyPresent) {
          CmpiArray PropertiesToApplyCmpi = PropertiesToApplyCmpiData;
          PropertiesToApplySize = PropertiesToApplyCmpi.size();
          ArrayConverter::makeArray(
            PropertiesToApplyCmpi,
            &PropertiesToApply,
            PropertiesToApplySize);
        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }
        
      aResult.returnData(CmpiData(m_interfaceP->VerifyOKToApplyIncrementalChangeToMSE(
        aContext,
        m_cmpiBroker,
        instanceName,
        MSE,
        isMSEPresent,
        TimeToApply,
        isTimeToApplyPresent,
        MustBeCompletedBy,
        isMustBeCompletedByPresent,
        (const char**) PropertiesToApply,
        PropertiesToApplySize,
        isPropertiesToApplyPresent)));


      if (PropertiesToApply) {
        ArrayConverter::destructArray(
          PropertiesToApply,
          PropertiesToApplySize);
      }

#ifdef DEBUG
      std::cout << "end of method VerifyOKToApplyIncrementalChangeToMSE" << std::endl;
#endif      
           
    } else if (0 == strcasecmp(aMethodNameP,"VerifyOKToApplyToCollection")) {

#ifdef DEBUG
      std::cout << "executing method VerifyOKToApplyToCollection" << std::endl;
#endif      

      int isCollectionPresent = 0;
      CIM_CollectionOfMSEsInstanceName  Collection;
      try {
        CmpiData CollectionCmpiData = in.getArg("Collection");
        isCollectionPresent = ! CollectionCmpiData.isNullValue();
        if (isCollectionPresent) {
          CmpiObjectPath CollectionCmpi = CollectionCmpiData;
          Collection = CIM_CollectionOfMSEsInstanceName(CollectionCmpi);
        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isTimeToApplyPresent = 0;
      CmpiDateTime TimeToApply;
      try {
        CmpiData TimeToApplyCmpiData = in.getArg("TimeToApply");
        isTimeToApplyPresent = ! TimeToApplyCmpiData.isNullValue();
        if (isTimeToApplyPresent) {
           TimeToApply = TimeToApplyCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isMustBeCompletedByPresent = 0;
      CmpiDateTime MustBeCompletedBy;
      try {
        CmpiData MustBeCompletedByCmpiData = in.getArg("MustBeCompletedBy");
        isMustBeCompletedByPresent = ! MustBeCompletedByCmpiData.isNullValue();
        if (isMustBeCompletedByPresent) {
           MustBeCompletedBy = MustBeCompletedByCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      char** CanNotApply;

      CMPICount CanNotApplySize;
        
      aResult.returnData(CmpiData(m_interfaceP->VerifyOKToApplyToCollection(
        aContext,
        m_cmpiBroker,
        instanceName,
        Collection,
        isCollectionPresent,
        TimeToApply,
        isTimeToApplyPresent,
        MustBeCompletedBy,
        isMustBeCompletedByPresent,
        CanNotApply,
        CanNotApplySize)));

      out.setArg("CanNotApply",CmpiData(ArrayConverter::makeCmpiArray((const char**) CanNotApply, CanNotApplySize)));

      if (CanNotApply) {
        ArrayConverter::destructArray(
          CanNotApply,
          CanNotApplySize);
      }

#ifdef DEBUG
      std::cout << "end of method VerifyOKToApplyToCollection" << std::endl;
#endif      
           
    } else if (0 == strcasecmp(aMethodNameP,"VerifyOKToApplyToMSE")) {

#ifdef DEBUG
      std::cout << "executing method VerifyOKToApplyToMSE" << std::endl;
#endif      

      int isMSEPresent = 0;
      CIM_ManagedSystemElementInstanceName  MSE;
      try {
        CmpiData MSECmpiData = in.getArg("MSE");
        isMSEPresent = ! MSECmpiData.isNullValue();
        if (isMSEPresent) {
          CmpiObjectPath MSECmpi = MSECmpiData;
          MSE = CIM_ManagedSystemElementInstanceName(MSECmpi);
        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isTimeToApplyPresent = 0;
      CmpiDateTime TimeToApply;
      try {
        CmpiData TimeToApplyCmpiData = in.getArg("TimeToApply");
        isTimeToApplyPresent = ! TimeToApplyCmpiData.isNullValue();
        if (isTimeToApplyPresent) {
           TimeToApply = TimeToApplyCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }

      int isMustBeCompletedByPresent = 0;
      CmpiDateTime MustBeCompletedBy;
      try {
        CmpiData MustBeCompletedByCmpiData = in.getArg("MustBeCompletedBy");
        isMustBeCompletedByPresent = ! MustBeCompletedByCmpiData.isNullValue();
        if (isMustBeCompletedByPresent) {
           MustBeCompletedBy = MustBeCompletedByCmpiData;

        }
      } catch (const CmpiStatus& rc) {
        // parameter not present
        
      }
        
      aResult.returnData(CmpiData(m_interfaceP->VerifyOKToApplyToMSE(
        aContext,
        m_cmpiBroker,
        instanceName,
        MSE,
        isMSEPresent,
        TimeToApply,
        isTimeToApplyPresent,
        MustBeCompletedBy,
        isMustBeCompletedByPresent)));



#ifdef DEBUG
      std::cout << "end of method VerifyOKToApplyToMSE" << std::endl;
#endif      
           
    } else  {

      aResult.returnDone();
      return CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::METHOD_NOT_FOUND,
        aMethodNameP,
        "Linux_DnsIPAddress");

    }
      
    aResult.returnDone();
    return CmpiStatus(CMPI_RC_OK);      

  }

 
}	

