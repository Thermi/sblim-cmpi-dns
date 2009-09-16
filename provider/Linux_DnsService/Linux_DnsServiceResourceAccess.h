// =======================================================================
// Linux_DnsServiceResourceAccess.h
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
#ifndef Linux_DnsServiceResourceAccess_h
#define Linux_DnsServiceResourceAccess_h

#include "Linux_DnsServiceInstanceName.h"
#include "Linux_DnsServiceManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "CIM_ConcreteJobInstanceName.h"
#include "Linux_DnsServiceDefaultImplementation.h"


namespace genProvider {

  class Linux_DnsServiceResourceAccess:
   public Linux_DnsServiceDefaultImplementation {
  	
    public:
    /*
    Linux_DnsServiceResourceAccess();
    */    
    virtual ~Linux_DnsServiceResourceAccess() ;
    
    /* intrinsic methods */

    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsServiceInstanceNameEnumeration& anInstanceNameEnumeration);
  	
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsServiceManualInstanceEnumeration& aManualInstanceEnumeration);
  	
    virtual Linux_DnsServiceManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& anInstanceName);
 
    /* 	
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsServiceManualInstance& aManualInstance);
    */
	
    /*
    virtual Linux_DnsServiceInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsServiceManualInstance& aManualInstance);
    */
  	
    /*
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsServiceInstanceName& anInstanceName);
    */
	
    
    
    /* extrinsic methods */
    
    /*
    virtual CMPIUint32 RequestStateChange(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsServiceInstanceName& anInstanceName,
      const CMPIUint16& RequestedState,
      int isRequestedStatePresent,
      CIM_ConcreteJobInstanceName& Job,
      int isJobPresent,
      const CmpiDateTime& TimeoutPeriod,
      int isTimeoutPeriodPresent);
    */

    virtual CMPIUint32 StartService(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsServiceInstanceName& anInstanceName);

    virtual CMPIUint32 StopService(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsServiceInstanceName& anInstanceName);

	
  };
  
}
#endif
