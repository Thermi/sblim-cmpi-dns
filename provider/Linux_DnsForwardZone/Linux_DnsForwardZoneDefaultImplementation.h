// =======================================================================
// Linux_DnsForwardZoneDefaultImplementation.h
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
#ifndef Linux_DnsForwardZoneDefaultImplementation_h
#define Linux_DnsForwardZoneDefaultImplementation_h

#include "Linux_DnsForwardZoneInstanceName.h"
#include "Linux_DnsForwardZoneManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "CIM_CollectionOfMSEsInstanceName.h"
#include "CIM_ManagedSystemElementInstanceName.h"
#include "Linux_DnsForwardZoneInterface.h"


namespace genProvider {

  class Linux_DnsForwardZoneDefaultImplementation:
   public Linux_DnsForwardZoneInterface {
  	
    public:    
    virtual ~Linux_DnsForwardZoneDefaultImplementation() { };
    
    /* intrinsic methods */
    
    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsForwardZoneInstanceNameEnumeration& anInstanceNameEnumeration);
    
  	
    
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsForwardZoneManualInstanceEnumeration& aManualInstanceEnumeration);
  	
  	
    
    virtual Linux_DnsForwardZoneManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsForwardZoneInstanceName& anInstanceName);
    
  	
    
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsForwardZoneManualInstance& aManualInstance);
    
  	
    
    virtual Linux_DnsForwardZoneInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsForwardZoneManualInstance& aManualInstance);
    
  	
    
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsForwardZoneInstanceName& anInstanceName);
    
	
    
    
    /* extrinsic methods */
    
    
    virtual CMPIUint32 ApplyIncrementalChangeToCollection(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsForwardZoneInstanceName& anInstanceName,
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
      CMPICount& CanNotApplySize);
    

    
    virtual CMPIUint32 ApplyIncrementalChangeToMSE(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsForwardZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent);
    

    
    virtual CMPIUint32 ApplyToCollection(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsForwardZoneInstanceName& anInstanceName,
      const CIM_CollectionOfMSEsInstanceName& Collection,
      int isCollectionPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CMPIBoolean& ContinueOnError,
      int isContinueOnErrorPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      char**& CanNotApply,
      CMPICount& CanNotApplySize);
    

    
    virtual CMPIUint32 ApplyToMSE(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsForwardZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent);
    

    
    virtual CMPIUint32 VerifyOKToApplyIncrementalChangeToCollection(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsForwardZoneInstanceName& anInstanceName,
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
      CMPICount& CanNotApplySize);
    

    
    virtual CMPIUint32 VerifyOKToApplyIncrementalChangeToMSE(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsForwardZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent);
    

    
    virtual CMPIUint32 VerifyOKToApplyToCollection(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsForwardZoneInstanceName& anInstanceName,
      const CIM_CollectionOfMSEsInstanceName& Collection,
      int isCollectionPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      char**& CanNotApply,
      CMPICount& CanNotApplySize);
    

    
    virtual CMPIUint32 VerifyOKToApplyToMSE(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsForwardZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent);
    

	
  };
  
}
#endif
