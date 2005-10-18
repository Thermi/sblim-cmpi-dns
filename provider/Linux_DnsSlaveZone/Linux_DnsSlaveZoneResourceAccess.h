 /**
 * Linux_DnsSlaveZoneResourceAccess.h
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
#ifndef Linux_DnsSlaveZoneResourceAccess_h
#define Linux_DnsSlaveZoneResourceAccess_h

#include "Linux_DnsSlaveZoneInstanceName.h"
#include "Linux_DnsSlaveZoneManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "CIM_CollectionOfMSEsInstanceName.h"
#include "CIM_ManagedSystemElementInstanceName.h"
#include "Linux_DnsSlaveZoneDefaultImplementation.h"

#include <string>
#include <list>

#include "smt_dns_ra_support.h"
#include "smt_dns_valuemap.h"
#include "smt_dns_array.h"

namespace genProvider {

  class Linux_DnsSlaveZoneResourceAccess:
   public Linux_DnsSlaveZoneDefaultImplementation {
    
    private:

      virtual void setInstanceProperties(
        const CmpiContext& ctx,
        const CmpiBroker &mbp,
        DNSZONE * zone,
        const Linux_DnsSlaveZoneInstanceName& anInstanceName,
        Linux_DnsSlaveZoneManualInstance& aManualInstance);

      virtual void setInstanceNameProperties(
        const CmpiContext& ctx,
        const CmpiBroker& mbp,
        const char *nsp,
        DNSZONE * zone,
        Linux_DnsSlaveZoneInstanceName& anInstanceName);  	
    public:
    /*Linux_DnsSlaveZoneResourceAccess();*/    
    virtual ~Linux_DnsSlaveZoneResourceAccess() ;
    
    /* intrinsic methods */
    virtual void enumInstanceNames(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     Linux_DnsSlaveZoneInstanceNameEnumeration& instnames);
  	
    virtual void enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsSlaveZoneManualInstanceEnumeration& instances);
  	
    virtual Linux_DnsSlaveZoneManualInstance getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsSlaveZoneInstanceName&);
  	
    virtual void setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsSlaveZoneManualInstance&);
  	
    virtual void createInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneManualInstance&);
  	
    virtual void deleteInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneInstanceName&);
	
    
    /* extrinsic methods */

    /*virtual CMPIUint32 ApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneInstanceName&,
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
     const Linux_DnsSlaveZoneInstanceName&,
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
     const Linux_DnsSlaveZoneInstanceName&,
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
     const Linux_DnsSlaveZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent);*/

    /*virtual CMPIUint32 VerifyOKToApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneInstanceName&,
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
     const Linux_DnsSlaveZoneInstanceName&,
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
     const Linux_DnsSlaveZoneInstanceName&,
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
     const Linux_DnsSlaveZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent);*/

    virtual CMPIUint32 disable(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneInstanceName&);

    virtual CMPIUint32 enable(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneInstanceName&);
	
  };
}
#endif

