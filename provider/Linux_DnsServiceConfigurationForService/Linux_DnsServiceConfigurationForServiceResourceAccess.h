// =======================================================================
// Linux_DnsServiceConfigurationForServiceResourceAccess.h
//     created on Thu, 26 Oct 2006 using ECUTE 2.2
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
#ifndef Linux_DnsServiceConfigurationForServiceResourceAccess_h
#define Linux_DnsServiceConfigurationForServiceResourceAccess_h

#include "Linux_DnsServiceConfigurationForServiceInstanceName.h"
#include "Linux_DnsServiceConfigurationForServiceManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsServiceInstance.h"
#include "Linux_DnsServiceConfigurationInstance.h"
#include "Linux_DnsServiceExternal.h"
#include "Linux_DnsServiceConfigurationExternal.h"
#include "Linux_DnsServiceConfigurationForServiceDefaultImplementation.h"


namespace genProvider {

  class Linux_DnsServiceConfigurationForServiceResourceAccess:
   public Linux_DnsServiceConfigurationForServiceDefaultImplementation {
  	
    public:
    /*
    Linux_DnsServiceConfigurationForServiceResourceAccess();
    */    
    virtual ~Linux_DnsServiceConfigurationForServiceResourceAccess() ;
    
    /* intrinsic methods */
    
    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
  	
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsServiceConfigurationForServiceManualInstanceEnumeration& aManualInstanceEnumeration);
  	
    virtual Linux_DnsServiceConfigurationForServiceManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName);
  	
    /*
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsServiceConfigurationForServiceManualInstance& aManualInstance);
    */
  	
    /*
    virtual Linux_DnsServiceConfigurationForServiceInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsServiceConfigurationForServiceManualInstance& aManualInstance);
    */
  	
    /*
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName);
    */
	
    
    /* Association Interface */

    virtual void referencesElement( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsServiceConfigurationForServiceManualInstanceEnumeration& aManualInstanceEnumeration);

    virtual void referencesConfiguration( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsServiceConfigurationForServiceManualInstanceEnumeration& aManualInstanceEnumeration);

    virtual void associatorsElement( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration);

    virtual void associatorsConfiguration( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsServiceConfigurationInstanceEnumeration& anInstanceEnumeration);

   
    
    /* extrinsic methods */
    
	
  };
  
}
#endif
