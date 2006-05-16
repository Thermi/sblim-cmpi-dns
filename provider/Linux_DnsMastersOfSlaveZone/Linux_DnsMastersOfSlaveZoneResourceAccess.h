// =======================================================================
// Linux_DnsMastersOfSlaveZoneResourceAccess.h
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
#ifndef Linux_DnsMastersOfSlaveZoneResourceAccess_h
#define Linux_DnsMastersOfSlaveZoneResourceAccess_h

#include "Linux_DnsMastersOfSlaveZoneInstanceName.h"
#include "Linux_DnsMastersOfSlaveZoneManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsIPAddressInstance.h"
#include "Linux_DnsSlaveZoneInstance.h"
#include "Linux_DnsIPAddressExternal.h"
#include "Linux_DnsSlaveZoneExternal.h"
#include "Linux_DnsMastersOfSlaveZoneDefaultImplementation.h"


namespace genProvider {

  class Linux_DnsMastersOfSlaveZoneResourceAccess:
   public Linux_DnsMastersOfSlaveZoneDefaultImplementation {
  	
    public:
    /*
    Linux_DnsMastersOfSlaveZoneResourceAccess();
    */    
    virtual ~Linux_DnsMastersOfSlaveZoneResourceAccess() ;
    
    /* intrinsic methods */
    /*
    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& anInstanceNameEnumeration);
    */
  	
    /*
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& aManualInstanceEnumeration);
  	*/
  	
    /*
    virtual Linux_DnsMastersOfSlaveZoneManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName);
    */
  	
    /*
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsMastersOfSlaveZoneManualInstance& aManualInstance);
    */
  	
    /*
    virtual Linux_DnsMastersOfSlaveZoneInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsMastersOfSlaveZoneManualInstance& aManualInstance);
    */
  	
    /*
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName);
    */
	
    
    /* Association Interface */


    virtual void referencesSetting( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsSlaveZoneInstanceName& aSourceInstanceName,
      Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& aManualInstanceEnumeration);



    virtual void referencesElement( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsIPAddressInstanceName& aSourceInstanceName,
      Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& aManualInstanceEnumeration);



    virtual void associatorsSetting( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsSlaveZoneInstanceName& aSourceInstanceName,
      Linux_DnsIPAddressInstanceEnumeration& anInstanceEnumeration);



    virtual void associatorsElement( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsIPAddressInstanceName& aSourceInstanceName,
      Linux_DnsSlaveZoneInstanceEnumeration& anInstanceEnumeration);


   
    
    /* extrinsic methods */
    
	
  };
  
}
#endif
