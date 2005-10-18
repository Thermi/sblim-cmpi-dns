 /**
 * Linux_DnsMasterZoneResourceAccess.h
 *
 * (C) Copyright IBM Corp. 2005
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Common Public License from
 * http://www.opensource.org/licenses/cpl1.0.php
 *
 * author:     Murillo Bernardes <bernarde@br.ibm.com>
 *
 * Contributors:
 *
 */
#ifndef Linux_DnsMasterZoneResourceAccess_h
#define Linux_DnsMasterZoneResourceAccess_h

#include "Linux_DnsMasterZoneInstanceName.h"
#include "Linux_DnsMasterZoneManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "CIM_CollectionOfMSEsInstanceName.h"
#include "CIM_ManagedSystemElementInstanceName.h"
#include "Linux_DnsMasterZoneDefaultImplementation.h"

#include <string>
#include <list>

#include "smt_dns_ra_support.h"
#include "smt_dns_valuemap.h"
#include "smt_dns_array.h"

namespace genProvider {

  class Linux_DnsMasterZoneResourceAccess:
   public Linux_DnsMasterZoneDefaultImplementation {

    private:

    virtual void setInstanceProperties(
        const CmpiContext& ctx,
        const CmpiBroker &mbp,
        DNSZONE * zone,
        const Linux_DnsMasterZoneInstanceName& anInstanceName,
        Linux_DnsMasterZoneManualInstance& aManualInstance);

    virtual void setInstanceNameProperties(
        const CmpiContext& ctx,
        const CmpiBroker& mbp,
        const char *nsp,
        DNSZONE * zone,
        Linux_DnsMasterZoneInstanceName& anInstanceName);
  
	
    public:
    /*Linux_DnsMasterZoneResourceAccess();*/    
    virtual ~Linux_DnsMasterZoneResourceAccess() ;
    
    /* intrinsic methods */
    virtual void enumInstanceNames(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     Linux_DnsMasterZoneInstanceNameEnumeration& instnames);
  	
    virtual void enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsMasterZoneManualInstanceEnumeration& instances);
  	
    virtual Linux_DnsMasterZoneManualInstance getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsMasterZoneInstanceName&);
  	
    virtual void setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsMasterZoneManualInstance&); 
       	
    virtual void createInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsMasterZoneManualInstance&);
  	
    virtual void deleteInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&);
	
    
    /* extrinsic methods */

    /*virtual CMPIUint32 ApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&,
      const CIM_CollectionOfMSEsInstanceName &Collection,
      int isCollectionPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CMPIBoolean &ContinueOnError,
      int isContinueOnErrorPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent,
      char** &CanNotApply,
      CMPICount &CanNotApplySize);*/

    /*virtual CMPIUint32 ApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent);*/

    /*virtual CMPIUint32 ApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&,
      const CIM_CollectionOfMSEsInstanceName &Collection,
      int isCollectionPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CMPIBoolean &ContinueOnError,
      int isContinueOnErrorPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      char** &CanNotApply,
      CMPICount &CanNotApplySize);*/

    /*virtual CMPIUint32 ApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent);*/

    /*virtual CMPIUint32 VerifyOKToApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&,
      const CIM_CollectionOfMSEsInstanceName &Collection,
      int isCollectionPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent,
      char** &CanNotApply,
      CMPICount &CanNotApplySize);*/

    /*virtual CMPIUint32 VerifyOKToApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent);*/

    /*virtual CMPIUint32 VerifyOKToApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&,
      const CIM_CollectionOfMSEsInstanceName &Collection,
      int isCollectionPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      char** &CanNotApply,
      CMPICount &CanNotApplySize);*/

    /*virtual CMPIUint32 VerifyOKToApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent);*/

    virtual CMPIUint32 disable(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&);

    virtual CMPIUint32 enable(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&);	
  };
}
#endif

