 /**
 * Linux_DnsAllowTransferACLForZoneResourceAccess.h
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
#ifndef Linux_DnsAllowTransferACLForZoneResourceAccess_h
#define Linux_DnsAllowTransferACLForZoneResourceAccess_h

#include "Linux_DnsAllowTransferACLForZoneInstanceName.h"
#include "Linux_DnsAllowTransferACLForZoneManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsZoneInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "Linux_DnsZoneExternal.h"
#include "Linux_DnsAddressMatchListExternal.h"
#include "Linux_DnsAllowTransferACLForZoneDefaultImplementation.h"

#include <string>
#include <list>

using namespace std;

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

namespace genProvider {

  class Linux_DnsAllowTransferACLForZoneResourceAccess:
   public Linux_DnsAllowTransferACLForZoneDefaultImplementation {
  	
    public:
    /*Linux_DnsAllowTransferACLForZoneResourceAccess();*/    
    virtual ~Linux_DnsAllowTransferACLForZoneResourceAccess() ;
    
    /* intrinsic methods */
    virtual void enumInstanceNames(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     Linux_DnsAllowTransferACLForZoneInstanceNameEnumeration& instnames);
  	
    virtual void enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration& instances);
  	
    virtual Linux_DnsAllowTransferACLForZoneManualInstance getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsAllowTransferACLForZoneInstanceName&);
  	
    /*virtual void setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsAllowTransferACLForZoneManualInstance&);*/
  	
    virtual void createInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsAllowTransferACLForZoneManualInstance&);
  	
    virtual void deleteInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsAllowTransferACLForZoneInstanceName&);
	
    
    /* Association Interface */

    virtual void referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration& instances);

    virtual void referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration& instances);

    virtual void associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsZoneInstanceEnumeration& instances);

    virtual void associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration& instances);

   
    /* extrinsic methods */
	
  };
}
#endif

