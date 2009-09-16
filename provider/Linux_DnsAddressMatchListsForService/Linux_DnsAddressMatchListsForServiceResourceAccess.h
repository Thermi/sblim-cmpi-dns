// =======================================================================
// Linux_DnsAddressMatchListsForServiceResourceAccess.h
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
#ifndef Linux_DnsAddressMatchListsForServiceResourceAccess_h
#define Linux_DnsAddressMatchListsForServiceResourceAccess_h

#include "Linux_DnsAddressMatchListsForServiceInstanceName.h"
#include "Linux_DnsAddressMatchListsForServiceManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsServiceInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "Linux_DnsServiceExternal.h"
#include "Linux_DnsAddressMatchListExternal.h"
#include "Linux_DnsAddressMatchListsForServiceDefaultImplementation.h"


namespace genProvider {

  class Linux_DnsAddressMatchListsForServiceResourceAccess:
   public Linux_DnsAddressMatchListsForServiceDefaultImplementation {
  	
    public:
    /*
    Linux_DnsAddressMatchListsForServiceResourceAccess();
    */    
    virtual ~Linux_DnsAddressMatchListsForServiceResourceAccess() ;
    
    /* intrinsic methods */
    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsAddressMatchListsForServiceInstanceNameEnumeration& anInstanceNameEnumeration);
  	
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsAddressMatchListsForServiceManualInstanceEnumeration& aManualInstanceEnumeration);
  	
    virtual Linux_DnsAddressMatchListsForServiceManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListsForServiceInstanceName& anInstanceName);
  	
    /*
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListsForServiceManualInstance& aManualInstance);
    */
  	
    /*
    virtual Linux_DnsAddressMatchListsForServiceInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsAddressMatchListsForServiceManualInstance& aManualInstance);
    */
  	
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsAddressMatchListsForServiceInstanceName& anInstanceName);
	
    
    /* Association Interface */

    virtual void referencesGroupComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListsForServiceManualInstanceEnumeration& aManualInstanceEnumeration);

    virtual void referencesPartComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListsForServiceManualInstanceEnumeration& aManualInstanceEnumeration);

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
