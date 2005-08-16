 /**
 * Linux_DnsManagedSystemElementForSettingResourceAccess.h
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
#ifndef Linux_DnsManagedSystemElementForSettingResourceAccess_h
#define Linux_DnsManagedSystemElementForSettingResourceAccess_h

#include "Linux_DnsManagedSystemElementForSettingInstanceName.h"
#include "Linux_DnsManagedSystemElementForSettingManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsZoneInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "Linux_DnsZoneExternal.h"
#include "Linux_DnsAddressMatchListExternal.h"
#include "Linux_DnsManagedSystemElementForSettingDefaultImplementation.h"

#include <string>
#include <list>

using namespace std;

#include "dnssupport.h"
#include "defaultvalues.h"
#include "DnsArray.h"
#include "DnsValueMap.h"

#define DNS_ALLOW_NOTIFY_STR	"allow-notify"
#define DNS_ALLOW_QUERY_STR	"allow-query"
#define DNS_ALLOW_TRANSFER_STR	"allow-transfer"
#define DNS_ALLOW_UPDATE_STR	"allow-update"

namespace genProvider {

  class Linux_DnsManagedSystemElementForSettingResourceAccess:
   public Linux_DnsManagedSystemElementForSettingDefaultImplementation {
  	
    public:
    /*Linux_DnsManagedSystemElementForSettingResourceAccess();*/    
    virtual ~Linux_DnsManagedSystemElementForSettingResourceAccess() ;
    
    /* intrinsic methods */
    /*virtual void enumInstanceNames(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration& instnames);*/
  	
    /*virtual void enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration& instances);*/
  	
    /*virtual Linux_DnsManagedSystemElementForSettingManualInstance getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsManagedSystemElementForSettingInstanceName&);*/
  	
    /*virtual void setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsManagedSystemElementForSettingManualInstance&);*/
  	
    /*virtual void createInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsManagedSystemElementForSettingManualInstance&);*/
  	
    /*virtual void deleteInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsManagedSystemElementForSettingInstanceName&);*/
	
    
    /* Association Interface */

    virtual void referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration& instances);

    virtual void referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration& instances);

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

