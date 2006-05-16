// =======================================================================
// Linux_DnsSettingContextDefaultImplementation.h
//     created on Fri, 3 Mar 2006 using ECUTE
// 
// Copyright (c) 2006, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Common Public License from
// http://oss.software.ibm.com/developerworks/opensource/license-cpl.html
//
// Author:        generated
//
// Contributors:
//                Murillo Bernardes <bernarde@br.ibm.com>
//                Wolfgang Taphorn <taphorn@de.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsSettingContextDefaultImplementation_h
#define Linux_DnsSettingContextDefaultImplementation_h

#include "Linux_DnsSettingContextInstanceName.h"
#include "Linux_DnsSettingContextManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsSettingInstance.h"
#include "Linux_DnsConfigurationInstance.h"
#include "Linux_DnsSettingExternal.h"
#include "Linux_DnsConfigurationExternal.h"
#include "Linux_DnsSettingContextInterface.h"


namespace genProvider {

  class Linux_DnsSettingContextDefaultImplementation:
   public Linux_DnsSettingContextInterface {
  	
    public:    
    virtual ~Linux_DnsSettingContextDefaultImplementation() { };
    
    /* intrinsic methods */
    
    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsSettingContextInstanceNameEnumeration& anInstanceNameEnumeration);
    
  	
    
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsSettingContextManualInstanceEnumeration& aManualInstanceEnumeration);
  	
  	
    
    virtual Linux_DnsSettingContextManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsSettingContextInstanceName& anInstanceName);
    
  	
    
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsSettingContextManualInstance& aManualInstance);
    
  	
    
    virtual Linux_DnsSettingContextInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsSettingContextManualInstance& aManualInstance);
    
  	
    
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsSettingContextInstanceName& anInstanceName);
    
	
    
    /* Association Interface */

    
    virtual void referencesSetting( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsSettingContextManualInstanceEnumeration& aManualInstanceEnumeration);
    

    
    virtual void referencesContext( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsSettingInstanceName& aSourceInstanceName,
      Linux_DnsSettingContextManualInstanceEnumeration& aManualInstanceEnumeration);
    

    
    virtual void associatorsSetting( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsSettingInstanceEnumeration& anInstanceEnumeration);
    

    
    virtual void associatorsContext( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsSettingInstanceName& aSourceInstanceName,
      Linux_DnsConfigurationInstanceEnumeration& anInstanceEnumeration);
    

   
    
    /* extrinsic methods */
    
	
  };
  
}
#endif
