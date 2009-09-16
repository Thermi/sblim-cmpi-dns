// =======================================================================
// Linux_DnsStubZoneResourceAccess.h
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
#ifndef Linux_DnsStubZoneResourceAccess_h
#define Linux_DnsStubZoneResourceAccess_h

#include "Linux_DnsStubZoneInstanceName.h"
#include "Linux_DnsStubZoneManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsStubZoneDefaultImplementation.h"


namespace genProvider {

  class Linux_DnsStubZoneResourceAccess:
   public Linux_DnsStubZoneDefaultImplementation {
  	
    public:
    /*
    Linux_DnsStubZoneResourceAccess();
    */    
    virtual ~Linux_DnsStubZoneResourceAccess() ;
    
    /* intrinsic methods */
    
    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsStubZoneInstanceNameEnumeration& anInstanceNameEnumeration);
    
  	
    
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsStubZoneManualInstanceEnumeration& aManualInstanceEnumeration);
  	
  	
    
    virtual Linux_DnsStubZoneManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsStubZoneInstanceName& anInstanceName);
    
  	
    
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsStubZoneManualInstance& aManualInstance);
    
  	
    
    virtual Linux_DnsStubZoneInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsStubZoneManualInstance& aManualInstance);
    
  	
    
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsStubZoneInstanceName& anInstanceName);
    
	
    
    
    /* extrinsic methods */
    
	
  };
  
}
#endif
