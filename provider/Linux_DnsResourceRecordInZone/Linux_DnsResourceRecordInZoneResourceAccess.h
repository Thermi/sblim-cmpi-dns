 /**
 * Linux_DnsResourceRecordInZoneResourceAccess.h
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
#ifndef Linux_DnsResourceRecordInZoneResourceAccess_h
#define Linux_DnsResourceRecordInZoneResourceAccess_h

#include "Linux_DnsResourceRecordInZoneInstanceName.h"
#include "Linux_DnsResourceRecordInZoneManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsZoneInstance.h"
#include "Linux_DnsResourceRecordInstance.h"
#include "Linux_DnsZoneExternal.h"
#include "Linux_DnsResourceRecordExternal.h"
#include "Linux_DnsResourceRecordInZoneDefaultImplementation.h"

#include <string>
#include <list>

#include "dnssupport.h"
#include "defaultvalues.h"
#include "DnsArray.h"
#include "DnsValueMap.h"

namespace genProvider {

  class Linux_DnsResourceRecordInZoneResourceAccess:
   public Linux_DnsResourceRecordInZoneDefaultImplementation {
  	
    public:
    /*Linux_DnsResourceRecordInZoneResourceAccess();*/    
    virtual ~Linux_DnsResourceRecordInZoneResourceAccess() ;
    
    /* intrinsic methods */
    /*virtual void enumInstanceNames(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     Linux_DnsResourceRecordInZoneInstanceNameEnumeration& instnames);*/
  	
    /*virtual void enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsResourceRecordInZoneManualInstanceEnumeration& instances);*/
  	
    /*virtual Linux_DnsResourceRecordInZoneManualInstance getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsResourceRecordInZoneInstanceName&);*/
  	
    /*virtual void setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsResourceRecordInZoneManualInstance&);*/
  	
    /*virtual void createInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsResourceRecordInZoneManualInstance&);*/
  	
    /*virtual void deleteInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsResourceRecordInZoneInstanceName&);*/
	
    
    /* Association Interface */

    virtual void referencesGroupComponent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsResourceRecordInstanceName& sourceInst,
     Linux_DnsResourceRecordInZoneManualInstanceEnumeration& instances);

    virtual void referencesPartComponent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsResourceRecordInZoneManualInstanceEnumeration& instances);

    virtual void associatorsGroupComponent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsResourceRecordInstanceName& sourceInst,
     Linux_DnsZoneInstanceEnumeration& instances);

    virtual void associatorsPartComponent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsResourceRecordInstanceEnumeration& instances);

   
    /* extrinsic methods */
	
  };
}
#endif

