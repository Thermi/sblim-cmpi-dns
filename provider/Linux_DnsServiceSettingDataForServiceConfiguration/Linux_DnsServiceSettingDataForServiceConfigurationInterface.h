// =======================================================================
// Linux_DnsServiceSettingDataForServiceConfigurationInterface.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
// 
// Copyright (c) 2006, 2009, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Eclipse Public License from
// http://www.opensource.org/licenses/eclipse-1.0.php
//
// Author:        generated
//
// Contributors:
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsServiceSettingDataForServiceConfigurationInterface_h
#define Linux_DnsServiceSettingDataForServiceConfigurationInterface_h

#include "Linux_DnsServiceSettingDataForServiceConfigurationInstanceName.h"
#include "Linux_DnsServiceSettingDataForServiceConfigurationManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsServiceConfigurationInstance.h"
#include "Linux_DnsServiceSettingDataInstance.h"
#include "Linux_DnsServiceConfigurationExternal.h"
#include "Linux_DnsServiceSettingDataExternal.h"


namespace genProvider {

  class Linux_DnsServiceSettingDataForServiceConfigurationInterface {
  	
    public:    
    virtual ~Linux_DnsServiceSettingDataForServiceConfigurationInterface() { };
    
    /* intrinsic methods */
    
    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration& anInstanceNameEnumeration) = 0;
    
  	
    
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration& aManualInstanceEnumeration) = 0;
  	
  	
    
    virtual Linux_DnsServiceSettingDataForServiceConfigurationManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anInstanceName) = 0;
    
  	
    
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsServiceSettingDataForServiceConfigurationManualInstance& aManualInstance) = 0;
    
  	
    
    virtual Linux_DnsServiceSettingDataForServiceConfigurationInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsServiceSettingDataForServiceConfigurationManualInstance& aManualInstance) = 0;
    
  	
    
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anInstanceName) = 0;
    
	
    
    /* Association Interface */

    
    virtual void referencesGroupComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceSettingDataInstanceName& aSourceInstanceName,
      Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration& aManualInstanceEnumeration) = 0;
    

    
    virtual void referencesPartComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration& aManualInstanceEnumeration) = 0;
    

    
    virtual void associatorsGroupComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceSettingDataInstanceName& aSourceInstanceName,
      Linux_DnsServiceConfigurationInstanceEnumeration& anInstanceEnumeration) = 0;
    

    
    virtual void associatorsPartComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsServiceSettingDataInstanceEnumeration& anInstanceEnumeration) = 0;
    

   
    
    /* extrinsic methods */
    
	
  };
  
}
#endif
