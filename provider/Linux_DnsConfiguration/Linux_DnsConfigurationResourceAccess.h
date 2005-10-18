 /**
 * Linux_DnsConfigurationResourceAccess.h
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
#ifndef Linux_DnsConfigurationResourceAccess_h
#define Linux_DnsConfigurationResourceAccess_h

#include "Linux_DnsConfigurationInstanceName.h"
#include "Linux_DnsConfigurationManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsConfigurationDefaultImplementation.h"

#include "smt_dns_defaultvalues.h"
#include "smt_dns_ra_support.h"

namespace genProvider {

  class Linux_DnsConfigurationResourceAccess:
   public Linux_DnsConfigurationDefaultImplementation {
  	
    public:
    /*Linux_DnsConfigurationResourceAccess();*/    
    virtual ~Linux_DnsConfigurationResourceAccess() ;
    
    /* intrinsic methods */
    virtual void enumInstanceNames(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     Linux_DnsConfigurationInstanceNameEnumeration& instnames);
  	
    virtual void enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsConfigurationManualInstanceEnumeration& instances);
  	
    virtual Linux_DnsConfigurationManualInstance getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsConfigurationInstanceName&);
  	
    /*virtual void setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsConfigurationManualInstance&);*/
  	
    /*virtual void createInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsConfigurationManualInstance&);*/
  	
    /*virtual void deleteInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsConfigurationInstanceName&);*/
	
    
    /* extrinsic methods */
	
  };
}
#endif

