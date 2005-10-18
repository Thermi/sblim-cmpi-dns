 /**
 * Linux_DnsMastersOfSlaveZoneResourceAccess.h
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
#ifndef Linux_DnsMastersOfSlaveZoneResourceAccess_h
#define Linux_DnsMastersOfSlaveZoneResourceAccess_h

#include "Linux_DnsMastersOfSlaveZoneInstanceName.h"
#include "Linux_DnsMastersOfSlaveZoneManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsSlaveZoneInstance.h"
#include "Linux_DnsIPAddressInstance.h"
#include "Linux_DnsSlaveZoneExternal.h"
#include "Linux_DnsIPAddressExternal.h"
#include "Linux_DnsMastersOfSlaveZoneDefaultImplementation.h"

#include <string>
#include <list>

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

namespace genProvider {

  class Linux_DnsMastersOfSlaveZoneResourceAccess:
   public Linux_DnsMastersOfSlaveZoneDefaultImplementation {
  	
    public:
    /*Linux_DnsMastersOfSlaveZoneResourceAccess();*/    
    virtual ~Linux_DnsMastersOfSlaveZoneResourceAccess() ;
    
    /* intrinsic methods */
    /*virtual void enumInstanceNames(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& instnames);*/
  	
    /*virtual void enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& instances);*/
  	
    /*virtual Linux_DnsMastersOfSlaveZoneManualInstance getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsMastersOfSlaveZoneInstanceName&);*/
  	
    /*virtual void setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsMastersOfSlaveZoneManualInstance&);*/
  	
    /*virtual void createInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsMastersOfSlaveZoneManualInstance&);*/
  	
    /*virtual void deleteInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsMastersOfSlaveZoneInstanceName&);*/
	
    
    /* Association Interface */

    virtual void referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsIPAddressInstanceName& sourceInst,
     Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& instances);

    virtual void referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsSlaveZoneInstanceName& sourceInst,
     Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& instances);

    virtual void associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsIPAddressInstanceName& sourceInst,
     Linux_DnsSlaveZoneInstanceEnumeration& instances);

    virtual void associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsSlaveZoneInstanceName& sourceInst,
     Linux_DnsIPAddressInstanceEnumeration& instances);

   
    /* extrinsic methods */
	
  };
}
#endif

