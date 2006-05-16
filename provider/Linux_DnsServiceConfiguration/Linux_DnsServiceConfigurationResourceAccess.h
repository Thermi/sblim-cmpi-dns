// =======================================================================
// Linux_DnsServiceConfigurationResourceAccess.h
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
#ifndef Linux_DnsServiceConfigurationResourceAccess_h
#define Linux_DnsServiceConfigurationResourceAccess_h

#include "Linux_DnsServiceConfigurationInstanceName.h"
#include "Linux_DnsServiceConfigurationManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsConfigurationInstance.h"
#include "Linux_DnsServiceInstance.h"
#include "Linux_DnsConfigurationExternal.h"
#include "Linux_DnsServiceExternal.h"
#include "Linux_DnsServiceConfigurationDefaultImplementation.h"


namespace genProvider {

  class Linux_DnsServiceConfigurationResourceAccess:
   public Linux_DnsServiceConfigurationDefaultImplementation {
  	
    public:
    /*
    Linux_DnsServiceConfigurationResourceAccess();
    */    
    virtual ~Linux_DnsServiceConfigurationResourceAccess() ;
    
    /* intrinsic methods */
    /*
    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsServiceConfigurationInstanceNameEnumeration& anInstanceNameEnumeration);
    */
  	
    /*
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsServiceConfigurationManualInstanceEnumeration& aManualInstanceEnumeration);
  	*/
  	
    /*
    virtual Linux_DnsServiceConfigurationManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsServiceConfigurationInstanceName& anInstanceName);
    */
  	
    /*
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsServiceConfigurationManualInstance& aManualInstance);
    */
  	
    /*
    virtual Linux_DnsServiceConfigurationInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsServiceConfigurationManualInstance& aManualInstance);
    */
  	
    /*
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsServiceConfigurationInstanceName& anInstanceName);
    */
	
    
    /* Association Interface */


    virtual void referencesConfiguration( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsServiceConfigurationManualInstanceEnumeration& aManualInstanceEnumeration);



    virtual void referencesElement( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsServiceConfigurationManualInstanceEnumeration& aManualInstanceEnumeration);



    virtual void associatorsConfiguration( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsServiceInstanceName& aSourceInstanceName,
      Linux_DnsConfigurationInstanceEnumeration& anInstanceEnumeration);



    virtual void associatorsElement( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsConfigurationInstanceName& aSourceInstanceName,
      Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration);


   
    
    /* extrinsic methods */
    
	
  };
  
}
#endif
