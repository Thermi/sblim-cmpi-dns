// =======================================================================
// Linux_DnsMasterZoneInterface.h
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
#ifndef Linux_DnsMasterZoneInterface_h
#define Linux_DnsMasterZoneInterface_h

#include "Linux_DnsMasterZoneInstanceName.h"
#include "Linux_DnsMasterZoneManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "CIM_CollectionOfMSEsInstanceName.h"
#include "CIM_ManagedSystemElementInstanceName.h"


namespace genProvider {

  class Linux_DnsMasterZoneInterface {
  	
    public:    
    virtual ~Linux_DnsMasterZoneInterface() { };
    
    /* intrinsic methods */
    
    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsMasterZoneInstanceNameEnumeration& anInstanceNameEnumeration) = 0;
    
  	
    
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsMasterZoneManualInstanceEnumeration& aManualInstanceEnumeration) = 0;
  	
  	
    
    virtual Linux_DnsMasterZoneManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsMasterZoneInstanceName& anInstanceName) = 0;
    
  	
    
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsMasterZoneManualInstance& aManualInstance) = 0;
    
  	
    
    virtual Linux_DnsMasterZoneInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsMasterZoneManualInstance& aManualInstance) = 0;
    
  	
    
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsMasterZoneInstanceName& anInstanceName) = 0;
    
	
    
    
    /* extrinsic methods */
    
    
    virtual CMPIUint32 ApplyIncrementalChangeToCollection(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsMasterZoneInstanceName& anInstanceName,
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
      CMPICount& CanNotApplySize) = 0;
    

    
    virtual CMPIUint32 ApplyIncrementalChangeToMSE(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsMasterZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent) = 0;
    

    
    virtual CMPIUint32 ApplyToCollection(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsMasterZoneInstanceName& anInstanceName,
      const CIM_CollectionOfMSEsInstanceName& Collection,
      int isCollectionPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CMPIBoolean& ContinueOnError,
      int isContinueOnErrorPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      char**& CanNotApply,
      CMPICount& CanNotApplySize) = 0;
    

    
    virtual CMPIUint32 ApplyToMSE(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsMasterZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) = 0;
    

    
    virtual CMPIUint32 VerifyOKToApplyIncrementalChangeToCollection(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsMasterZoneInstanceName& anInstanceName,
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
      CMPICount& CanNotApplySize) = 0;
    

    
    virtual CMPIUint32 VerifyOKToApplyIncrementalChangeToMSE(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsMasterZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent) = 0;
    

    
    virtual CMPIUint32 VerifyOKToApplyToCollection(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsMasterZoneInstanceName& anInstanceName,
      const CIM_CollectionOfMSEsInstanceName& Collection,
      int isCollectionPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      char**& CanNotApply,
      CMPICount& CanNotApplySize) = 0;
    

    
    virtual CMPIUint32 VerifyOKToApplyToMSE(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsMasterZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) = 0;
    

	
  };
  
}
#endif
