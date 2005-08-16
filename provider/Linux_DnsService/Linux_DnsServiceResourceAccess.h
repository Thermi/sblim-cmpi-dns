 /**
 * Linux_DnsServiceResourceAccess.h
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
#ifndef Linux_DnsServiceResourceAccess_h
#define Linux_DnsServiceResourceAccess_h

#include "Linux_DnsServiceInstanceName.h"
#include "Linux_DnsServiceManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "CIM_ConcreteJobInstanceName.h"
#include "Linux_DnsServiceDefaultImplementation.h"

#include "dnssupport.h" 
#include "defaultvalues.h"

namespace genProvider {

  class Linux_DnsServiceResourceAccess:
   public Linux_DnsServiceDefaultImplementation {
  	
    public:
    /*Linux_DnsServiceResourceAccess();*/    
    virtual ~Linux_DnsServiceResourceAccess() ;
    
    /* intrinsic methods */
    virtual void enumInstanceNames(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     Linux_DnsServiceInstanceNameEnumeration& instnames);
  	
    virtual void enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsServiceManualInstanceEnumeration& instances);
  	
    virtual Linux_DnsServiceManualInstance getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsServiceInstanceName&);
  	
    /*virtual void setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsServiceManualInstance&);*/
  	
    /*virtual void createInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsServiceManualInstance&);*/
  	
    /*virtual void deleteInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsServiceInstanceName&);*/
	
    
    /* extrinsic methods */

    /*virtual CMPIUint32 RequestStateChange(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsServiceInstanceName&,
      const CMPIUint16 &RequestedState,
      int isRequestedStatePresent,
      CIM_ConcreteJobInstanceName &Job,
      const CmpiDateTime &TimeoutPeriod,
      int isTimeoutPeriodPresent);*/

    virtual CMPIUint32 StartService(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsServiceInstanceName&);

    virtual CMPIUint32 StopService(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsServiceInstanceName&);
	
  };
}
#endif

