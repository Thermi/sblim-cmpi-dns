 /**
 * Linux_DnsAllowQueryACLForZoneResourceAccess.h
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
#ifndef Linux_DnsAllowQueryACLForZoneResourceAccess_h
#define Linux_DnsAllowQueryACLForZoneResourceAccess_h

#include "Linux_DnsAllowQueryACLForZoneInstanceName.h"
#include "Linux_DnsAllowQueryACLForZoneManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsZoneInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "Linux_DnsZoneExternal.h"
#include "Linux_DnsAddressMatchListExternal.h"
#include "Linux_DnsAllowQueryACLForZoneDefaultImplementation.h"

#include <string>
#include <list>

using namespace std;

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

namespace genProvider {

  class Linux_DnsAllowQueryACLForZoneResourceAccess:
   public Linux_DnsAllowQueryACLForZoneDefaultImplementation {
  	
    public:
    /*Linux_DnsAllowQueryACLForZoneResourceAccess();*/    
    virtual ~Linux_DnsAllowQueryACLForZoneResourceAccess() ;
    
    /* intrinsic methods */
    virtual void enumInstanceNames(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration& instnames);
  	
    virtual void enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration& instances);
  	
    virtual Linux_DnsAllowQueryACLForZoneManualInstance getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsAllowQueryACLForZoneInstanceName&);
  	
    /*virtual void setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsAllowQueryACLForZoneManualInstance&);*/
  	
    virtual void createInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsAllowQueryACLForZoneManualInstance&);
  	
    virtual void deleteInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsAllowQueryACLForZoneInstanceName&);
	
    
    /* Association Interface */

    virtual void referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration& instances);

    virtual void referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration& instances);

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

