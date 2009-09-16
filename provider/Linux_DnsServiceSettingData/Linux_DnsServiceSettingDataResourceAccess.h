// =======================================================================
// Linux_DnsServiceSettingDataResourceAccess.h
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
#ifndef Linux_DnsServiceSettingDataResourceAccess_h
#define Linux_DnsServiceSettingDataResourceAccess_h

#include "Linux_DnsServiceSettingDataInstanceName.h"
#include "Linux_DnsServiceSettingDataManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsServiceSettingDataDefaultImplementation.h"


namespace genProvider {

  class Linux_DnsServiceSettingDataResourceAccess:
   public Linux_DnsServiceSettingDataDefaultImplementation {
  	
    public:
    /*
    Linux_DnsServiceSettingDataResourceAccess();
    */    
    virtual ~Linux_DnsServiceSettingDataResourceAccess() ;
    
    /* intrinsic methods */
    
    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsServiceSettingDataInstanceNameEnumeration& anInstanceNameEnumeration);
  	
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsServiceSettingDataManualInstanceEnumeration& aManualInstanceEnumeration);
  	
    virtual Linux_DnsServiceSettingDataManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsServiceSettingDataInstanceName& anInstanceName);
  	
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsServiceSettingDataManualInstance& aManualInstance);
  	
    /*
    virtual Linux_DnsServiceSettingDataInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsServiceSettingDataManualInstance& aManualInstance);
    */
  	
    /*
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsServiceSettingDataInstanceName& anInstanceName);
    */	
    
    
    /* extrinsic methods */
    
	
  };
  
}
#endif
