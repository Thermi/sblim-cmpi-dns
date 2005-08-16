 /**
 * Linux_DnsNotifyACLForServiceDefaultImplementation.h
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
#ifndef Linux_DnsNotifyACLForServiceDefaultImplementation_h
#define Linux_DnsNotifyACLForServiceDefaultImplementation_h

#include "Linux_DnsNotifyACLForServiceInstanceName.h"
#include "Linux_DnsNotifyACLForServiceManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsServiceInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "Linux_DnsServiceExternal.h"
#include "Linux_DnsAddressMatchListExternal.h"
#include "Linux_DnsNotifyACLForServiceInterface.h"

namespace genProvider {

  class Linux_DnsNotifyACLForServiceDefaultImplementation:
   public Linux_DnsNotifyACLForServiceInterface {
  	
    public:    
    virtual ~Linux_DnsNotifyACLForServiceDefaultImplementation() { };
    
    /* intrinsic methods */
    virtual void enumInstanceNames(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     Linux_DnsNotifyACLForServiceInstanceNameEnumeration& instnames);
  	
    virtual void enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsNotifyACLForServiceManualInstanceEnumeration& instances);
  	
    virtual Linux_DnsNotifyACLForServiceManualInstance getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsNotifyACLForServiceInstanceName&);
  	
    virtual void setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsNotifyACLForServiceManualInstance&);
  	
    virtual void createInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsNotifyACLForServiceManualInstance&);
  	
    virtual void deleteInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsNotifyACLForServiceInstanceName&);
	
    
    /* Association Interface */

    virtual void referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsNotifyACLForServiceManualInstanceEnumeration& instances);

    virtual void referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsServiceInstanceName& sourceInst,
     Linux_DnsNotifyACLForServiceManualInstanceEnumeration& instances);

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
