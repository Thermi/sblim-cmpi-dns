// =======================================================================
// Linux_DnsSettingResourceAccess.h
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
#ifndef Linux_DnsSettingResourceAccess_h
#define Linux_DnsSettingResourceAccess_h

#include "Linux_DnsSettingInstanceName.h"
#include "Linux_DnsSettingManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "CIM_CollectionOfMSEsInstanceName.h"
#include "CIM_ManagedSystemElementInstanceName.h"
#include "Linux_DnsSettingDefaultImplementation.h"


namespace genProvider {

  class Linux_DnsSettingResourceAccess:
   public Linux_DnsSettingDefaultImplementation {
  	
    public:
    /*
    Linux_DnsSettingResourceAccess();
    */    
    virtual ~Linux_DnsSettingResourceAccess() ;
    
    /* intrinsic methods */

    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsSettingInstanceNameEnumeration& anInstanceNameEnumeration);

  	

    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsSettingManualInstanceEnumeration& aManualInstanceEnumeration);

  	

    virtual Linux_DnsSettingManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsSettingInstanceName& anInstanceName);

  	

    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsSettingManualInstance& aManualInstance);

  	
    /*
    virtual Linux_DnsSettingInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsSettingManualInstance& aManualInstance);
    */
  	
    /*
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsSettingInstanceName& anInstanceName);
    */
	
    
    
    /* extrinsic methods */
    
    /*
    virtual CMPIUint32 ApplyIncrementalChangeToCollection(
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
      CMPICount& CanNotApplySize);
    */

    /*
    virtual CMPIUint32 ApplyIncrementalChangeToMSE(
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
      int isPropertiesToApplyPresent);
    */

    /*
    virtual CMPIUint32 ApplyToCollection(
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
      CMPICount& CanNotApplySize);
    */

    /*
    virtual CMPIUint32 ApplyToMSE(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsSettingInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent);
    */

    /*
    virtual CMPIUint32 VerifyOKToApplyIncrementalChangeToCollection(
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
      CMPICount& CanNotApplySize);
    */

    /*
    virtual CMPIUint32 VerifyOKToApplyIncrementalChangeToMSE(
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
      int isPropertiesToApplyPresent);
    */

    /*
    virtual CMPIUint32 VerifyOKToApplyToCollection(
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
      CMPICount& CanNotApplySize);
    */

    /*
    virtual CMPIUint32 VerifyOKToApplyToMSE(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsSettingInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent);
    */

	
  };
  
}
#endif
