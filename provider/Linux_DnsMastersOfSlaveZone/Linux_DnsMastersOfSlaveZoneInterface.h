// =======================================================================
// Linux_DnsMastersOfSlaveZoneInterface.h
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
#ifndef Linux_DnsMastersOfSlaveZoneInterface_h
#define Linux_DnsMastersOfSlaveZoneInterface_h

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


namespace genProvider {

  class Linux_DnsMastersOfSlaveZoneInterface {
  	
    public:    
    virtual ~Linux_DnsMastersOfSlaveZoneInterface() { };
    
    /* intrinsic methods */
    
    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& anInstanceNameEnumeration) = 0;
    
  	
    
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& aManualInstanceEnumeration) = 0;
  	
  	
    
    virtual Linux_DnsMastersOfSlaveZoneManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName) = 0;
    
  	
    
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsMastersOfSlaveZoneManualInstance& aManualInstance) = 0;
    
  	
    
    virtual Linux_DnsMastersOfSlaveZoneInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsMastersOfSlaveZoneManualInstance& aManualInstance) = 0;
    
  	
    
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName) = 0;
    
	
    
    /* Association Interface */

    
    virtual void referencesSetting( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsSlaveZoneInstanceName& aSourceInstanceName,
      Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& aManualInstanceEnumeration) = 0;
    

    
    virtual void referencesElement( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsIPAddressInstanceName& aSourceInstanceName,
      Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& aManualInstanceEnumeration) = 0;
    

    
    virtual void associatorsSetting( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsSlaveZoneInstanceName& aSourceInstanceName,
      Linux_DnsIPAddressInstanceEnumeration& anInstanceEnumeration) = 0;
    

    
    virtual void associatorsElement( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsIPAddressInstanceName& aSourceInstanceName,
      Linux_DnsSlaveZoneInstanceEnumeration& anInstanceEnumeration) = 0;
    

   
    
    /* extrinsic methods */
    
	
  };
  
}
#endif
