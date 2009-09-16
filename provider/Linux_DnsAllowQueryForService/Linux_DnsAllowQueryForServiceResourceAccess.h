// =======================================================================
// Linux_DnsAllowQueryForServiceResourceAccess.h
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
#ifndef Linux_DnsAllowQueryForServiceResourceAccess_h
#define Linux_DnsAllowQueryForServiceResourceAccess_h

#include "Linux_DnsAllowQueryForServiceInstanceName.h"
#include "Linux_DnsAllowQueryForServiceManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsServiceInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "Linux_DnsServiceExternal.h"
#include "Linux_DnsAddressMatchListExternal.h"
#include "Linux_DnsAllowQueryForServiceDefaultImplementation.h"


namespace genProvider {

  class Linux_DnsAllowQueryForServiceResourceAccess:
   public Linux_DnsAllowQueryForServiceDefaultImplementation {
  	
    public:
    /*
    Linux_DnsAllowQueryForServiceResourceAccess();
    */    
    virtual ~Linux_DnsAllowQueryForServiceResourceAccess() ;
    
    /* intrinsic methods */
    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsAllowQueryForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
  	
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsAllowQueryForServiceManualInstanceEnumeration& aManualInstanceEnumeration);
  	
    virtual Linux_DnsAllowQueryForServiceManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsAllowQueryForServiceInstanceName& anInstanceName);
  	
    /*
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsAllowQueryForServiceManualInstance& aManualInstance);
    */
  	
    /*
    virtual Linux_DnsAllowQueryForServiceInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsAllowQueryForServiceManualInstance& aManualInstance);
    */
  	
    /*
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsAllowQueryForServiceInstanceName& anInstanceName);
    */
	
    
    /* Association Interface */

    virtual void referencesGroupComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsAllowQueryForServiceManualInstanceEnumeration& aManualInstanceEnumeration);

    virtual void referencesPartComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsAllowQueryForServiceManualInstanceEnumeration& aManualInstanceEnumeration);

    virtual void associatorsGroupComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration);

    virtual void associatorsPartComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration);

   
    
    /* extrinsic methods */
    
	
  };
  
}
#endif
