 /**
 * Linux_DnsBlackholeACLForServiceResourceAccess.h
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
#ifndef Linux_DnsBlackholeACLForServiceResourceAccess_h
#define Linux_DnsBlackholeACLForServiceResourceAccess_h

#include "Linux_DnsBlackholeACLForServiceInstanceName.h"
#include "Linux_DnsBlackholeACLForServiceManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsServiceInstance.h"
#include "Linux_DnsServiceInstanceName.h"
#include "Linux_DnsServiceManualInstance.h"
#include "Linux_DnsAddressMatchListInstanceName.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "Linux_DnsAddressMatchListManualInstance.h"
#include "Linux_DnsServiceExternal.h"
#include "Linux_DnsAddressMatchListExternal.h"
#include "Linux_DnsBlackholeACLForServiceDefaultImplementation.h"

#include <string>
#include <list>

using namespace std;

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

namespace genProvider {

  class Linux_DnsBlackholeACLForServiceResourceAccess:
   public Linux_DnsBlackholeACLForServiceDefaultImplementation {
  	
    public:
    /*Linux_DnsBlackholeACLForServiceResourceAccess();*/    
    virtual ~Linux_DnsBlackholeACLForServiceResourceAccess() ;
    
    /* intrinsic methods */
    virtual void enumInstanceNames(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     Linux_DnsBlackholeACLForServiceInstanceNameEnumeration& instnames);
  	
    virtual void enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsBlackholeACLForServiceManualInstanceEnumeration& instances);
  	
    virtual Linux_DnsBlackholeACLForServiceManualInstance getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsBlackholeACLForServiceInstanceName&);
  	
    /*virtual void setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsBlackholeACLForServiceManualInstance&);*/
  	
    virtual void createInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsBlackholeACLForServiceManualInstance&);
  	
    virtual void deleteInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsBlackholeACLForServiceInstanceName&);
	
    
    /* Association Interface */

    virtual void referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsBlackholeACLForServiceManualInstanceEnumeration& instances);

    virtual void referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsBlackholeACLForServiceManualInstanceEnumeration& instances);

    virtual void associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsServiceInstanceEnumeration& instances);

    virtual void associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration& instances);

   
    /* extrinsic methods */
	
  };
}
#endif

