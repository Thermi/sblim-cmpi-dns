 /**
 * Linux_DnsAllowQueryACLForZoneInterface.h
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
#ifndef Linux_DnsAllowQueryACLForZoneInterface_h
#define Linux_DnsAllowQueryACLForZoneInterface_h

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

namespace genProvider {

  class Linux_DnsAllowQueryACLForZoneInterface {
  	
    public:    
    virtual ~Linux_DnsAllowQueryACLForZoneInterface() { };
    
    /* intrinsic methods */
    virtual void enumInstanceNames(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration& instnames) = 0;
  	
    virtual void enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration& instances) = 0;
  	
    virtual Linux_DnsAllowQueryACLForZoneManualInstance getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsAllowQueryACLForZoneInstanceName&) = 0;
  	
    virtual void setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsAllowQueryACLForZoneManualInstance&) = 0;
  	
    virtual void createInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsAllowQueryACLForZoneManualInstance&) = 0;
  	
    virtual void deleteInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsAllowQueryACLForZoneInstanceName&) = 0;
	
    
    /* Association Interface */

    virtual void referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration& instances) = 0;

    virtual void referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration& instances) = 0;

    virtual void associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsZoneInstanceEnumeration& instances) = 0;

    virtual void associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration& instances) = 0;

   
    /* extrinsic methods */
	
  };
}
#endif
