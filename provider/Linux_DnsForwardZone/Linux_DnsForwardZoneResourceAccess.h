// =======================================================================
// Linux_DnsForwardZoneResourceAccess.h
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
#ifndef Linux_DnsForwardZoneResourceAccess_h
#define Linux_DnsForwardZoneResourceAccess_h

#include "Linux_DnsForwardZoneInstanceName.h"
#include "Linux_DnsForwardZoneManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsForwardZoneDefaultImplementation.h"


namespace genProvider {

  class Linux_DnsForwardZoneResourceAccess:
   public Linux_DnsForwardZoneDefaultImplementation {
  	
    public:
    /*
    Linux_DnsForwardZoneResourceAccess();
    */    
    virtual ~Linux_DnsForwardZoneResourceAccess() ;
    
    /* intrinsic methods */
    
    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsForwardZoneInstanceNameEnumeration& anInstanceNameEnumeration);
    
  	
    
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsForwardZoneManualInstanceEnumeration& aManualInstanceEnumeration);
  	
  	
    
    virtual Linux_DnsForwardZoneManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsForwardZoneInstanceName& anInstanceName);
    
  	
    
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsForwardZoneManualInstance& aManualInstance);
    
  	
    
    virtual Linux_DnsForwardZoneInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsForwardZoneManualInstance& aManualInstance);
    
  	
    
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsForwardZoneInstanceName& anInstanceName);
    
	
    
    
    /* extrinsic methods */
    
	
  };
  
}
#endif
