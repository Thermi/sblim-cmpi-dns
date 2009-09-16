// =======================================================================
// Linux_DnsResourceRecordsForZoneResourceAccess.h
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
#ifndef Linux_DnsResourceRecordsForZoneResourceAccess_h
#define Linux_DnsResourceRecordsForZoneResourceAccess_h

#include "Linux_DnsResourceRecordsForZoneInstanceName.h"
#include "Linux_DnsResourceRecordsForZoneManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsZoneInstance.h"
#include "Linux_DnsResourceRecordInstance.h"
#include "Linux_DnsZoneExternal.h"
#include "Linux_DnsResourceRecordExternal.h"
#include "Linux_DnsResourceRecordsForZoneDefaultImplementation.h"


namespace genProvider {

  class Linux_DnsResourceRecordsForZoneResourceAccess:
   public Linux_DnsResourceRecordsForZoneDefaultImplementation {
  	
    public:
    /*
    Linux_DnsResourceRecordsForZoneResourceAccess();
    */    
    virtual ~Linux_DnsResourceRecordsForZoneResourceAccess() ;
    
    /* intrinsic methods */
    
   virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsResourceRecordsForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
  	
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsResourceRecordsForZoneManualInstanceEnumeration& aManualInstanceEnumeration);
  	
    virtual Linux_DnsResourceRecordsForZoneManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordsForZoneInstanceName& anInstanceName);
  	
    /*
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordsForZoneManualInstance& aManualInstance);
    */
  	
    /*
    virtual Linux_DnsResourceRecordsForZoneInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsResourceRecordsForZoneManualInstance& aManualInstance);
    */
  	
    /*
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsResourceRecordsForZoneInstanceName& anInstanceName);
    */
	
    
    /* Association Interface */

    virtual void referencesGroupComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordInstanceName& aSourceInstanceName,
      Linux_DnsResourceRecordsForZoneManualInstanceEnumeration& aManualInstanceEnumeration);

    virtual void referencesPartComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsResourceRecordsForZoneManualInstanceEnumeration& aManualInstanceEnumeration);

    virtual void associatorsGroupComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordInstanceName& aSourceInstanceName,
      Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration);

    virtual void associatorsPartComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsResourceRecordInstanceEnumeration& anInstanceEnumeration);

   
    
    /* extrinsic methods */
    
	
  };
  
}
#endif
