// =======================================================================
// Linux_DnsAllowNotifyACLForZoneResourceAccess.h
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
#ifndef Linux_DnsAllowNotifyACLForZoneResourceAccess_h
#define Linux_DnsAllowNotifyACLForZoneResourceAccess_h

#include "Linux_DnsAllowNotifyACLForZoneInstanceName.h"
#include "Linux_DnsAllowNotifyACLForZoneManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "Linux_DnsZoneInstance.h"
#include "Linux_DnsAddressMatchListExternal.h"
#include "Linux_DnsZoneExternal.h"
#include "Linux_DnsAllowNotifyACLForZoneDefaultImplementation.h"


namespace genProvider {

  class Linux_DnsAllowNotifyACLForZoneResourceAccess:
   public Linux_DnsAllowNotifyACLForZoneDefaultImplementation {
  	
    public:
    /*
    Linux_DnsAllowNotifyACLForZoneResourceAccess();
    */    
    virtual ~Linux_DnsAllowNotifyACLForZoneResourceAccess() ;
    
    /* intrinsic methods */

    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration& anInstanceNameEnumeration);

  	

    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration& aManualInstanceEnumeration);

  	

    virtual Linux_DnsAllowNotifyACLForZoneManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsAllowNotifyACLForZoneInstanceName& anInstanceName);

  	
    /*
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsAllowNotifyACLForZoneManualInstance& aManualInstance);
    */
  	

    virtual Linux_DnsAllowNotifyACLForZoneInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsAllowNotifyACLForZoneManualInstance& aManualInstance);

  	

    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsAllowNotifyACLForZoneInstanceName& anInstanceName);

	
    
    /* Association Interface */


    virtual void referencesSetting( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration& aManualInstanceEnumeration);



    virtual void referencesElement( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration& aManualInstanceEnumeration);



    virtual void associatorsSetting( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration);



    virtual void associatorsElement( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration);


   
    
    /* extrinsic methods */
    
	
  };
  
}
#endif
