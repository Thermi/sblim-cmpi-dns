 /**
 * Linux_DnsSettingContextInterface.h
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
#ifndef Linux_DnsSettingContextInterface_h
#define Linux_DnsSettingContextInterface_h

#include "Linux_DnsSettingContextInstanceName.h"
#include "Linux_DnsSettingContextManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsConfigurationInstance.h"
#include "Linux_DnsSettingInstance.h"
#include "Linux_DnsConfigurationExternal.h"
#include "Linux_DnsSettingExternal.h"

namespace genProvider {

  class Linux_DnsSettingContextInterface {
  	
    public:    
    virtual ~Linux_DnsSettingContextInterface() { };
    
    /* intrinsic methods */
    virtual void enumInstanceNames(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     Linux_DnsSettingContextInstanceNameEnumeration& instnames) = 0;
  	
    virtual void enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsSettingContextManualInstanceEnumeration& instances) = 0;
  	
    virtual Linux_DnsSettingContextManualInstance getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsSettingContextInstanceName&) = 0;
  	
    virtual void setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsSettingContextManualInstance&) = 0;
  	
    virtual void createInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsSettingContextManualInstance&) = 0;
  	
    virtual void deleteInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const Linux_DnsSettingContextInstanceName&) = 0;
	
    
    /* Association Interface */

    virtual void referencesContext( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsSettingContextManualInstanceEnumeration& instances) = 0;

    virtual void referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsSettingContextManualInstanceEnumeration& instances) = 0;

    virtual void associatorsContext( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsSettingInstanceName& sourceInst,
     Linux_DnsConfigurationInstanceEnumeration& instances) = 0;

    virtual void associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsConfigurationInstanceName& sourceInst,
     Linux_DnsSettingInstanceEnumeration& instances) = 0;

   
    /* extrinsic methods */
	
  };
}
#endif

