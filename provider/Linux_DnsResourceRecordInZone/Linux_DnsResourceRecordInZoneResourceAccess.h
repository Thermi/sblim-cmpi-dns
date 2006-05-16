// =======================================================================
// Linux_DnsResourceRecordInZoneResourceAccess.h
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
#ifndef Linux_DnsResourceRecordInZoneResourceAccess_h
#define Linux_DnsResourceRecordInZoneResourceAccess_h

#include "Linux_DnsResourceRecordInZoneInstanceName.h"
#include "Linux_DnsResourceRecordInZoneManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsResourceRecordInstance.h"
#include "Linux_DnsZoneInstance.h"
#include "Linux_DnsResourceRecordExternal.h"
#include "Linux_DnsZoneExternal.h"
#include "Linux_DnsResourceRecordInZoneDefaultImplementation.h"


namespace genProvider {

  class Linux_DnsResourceRecordInZoneResourceAccess:
   public Linux_DnsResourceRecordInZoneDefaultImplementation {
  	
    public:
    /*
    Linux_DnsResourceRecordInZoneResourceAccess();
    */    
    virtual ~Linux_DnsResourceRecordInZoneResourceAccess() ;
    
    /* intrinsic methods */
    /*
    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsResourceRecordInZoneInstanceNameEnumeration& anInstanceNameEnumeration);
    */
  	
    /*
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsResourceRecordInZoneManualInstanceEnumeration& aManualInstanceEnumeration);
  	*/
  	
    /*
    virtual Linux_DnsResourceRecordInZoneManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordInZoneInstanceName& anInstanceName);
    */
  	
    /*
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordInZoneManualInstance& aManualInstance);
    */
  	
    /*
    virtual Linux_DnsResourceRecordInZoneInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsResourceRecordInZoneManualInstance& aManualInstance);
    */
  	
    /*
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsResourceRecordInZoneInstanceName& anInstanceName);
    */
	
    
    /* Association Interface */


    virtual void referencesPartComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsResourceRecordInZoneManualInstanceEnumeration& aManualInstanceEnumeration);



    virtual void referencesGroupComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordInstanceName& aSourceInstanceName,
      Linux_DnsResourceRecordInZoneManualInstanceEnumeration& aManualInstanceEnumeration);



    virtual void associatorsPartComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsResourceRecordInstanceEnumeration& anInstanceEnumeration);



    virtual void associatorsGroupComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsResourceRecordInstanceName& aSourceInstanceName,
      Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration);


   
    
    /* extrinsic methods */
    
	
  };
  
}
#endif
