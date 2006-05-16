// =======================================================================
// Linux_DnsServiceConfigurationResourceAccess.cpp
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
#include "Linux_DnsServiceConfigurationResourceAccess.h"

#include <string>
#include <list>
#include <iostream>

using namespace std;

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsServiceConfigurationResourceAccess::Linux_DnsServiceConfigurationResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationResourceAccess::~Linux_DnsServiceConfigurationResourceAccess() { }
    
  // intrinsic methods
  /*
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsServiceConfigurationInstanceNameEnumeration& anInstanceNameEnumeration) {
      
    int instanceNameN = 1;
    for (int x=0; x < instanceNameN; ++x) {
      
      //place here the code retrieving your instanceName
      
      Linux_DnsServiceConfigurationInstanceName instanceName;
      
    }      
  
  }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsServiceConfigurationResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsServiceConfigurationManualInstanceEnumeration& aManualInstanceEnumeration) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsServiceConfigurationManualInstance 
  Linux_DnsServiceConfigurationResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsServiceConfigurationInstanceName& anInstanceName) {

    Linux_DnsServiceConfigurationManualInstance manualInstance;

  
  }
  */
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsServiceConfigurationResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsServiceConfigurationManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsServiceConfigurationInstanceName
  Linux_DnsServiceConfigurationResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceConfigurationManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsServiceConfigurationResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceConfigurationInstanceName& anInstanceName) { }
	*/
	

  // Association Interface
  //----------------------------------------------------------------------------

  void Linux_DnsServiceConfigurationResourceAccess::referencesConfiguration( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsServiceConfigurationManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsServiceConfiguration::referencesConfiguration" << endl;
#endif

    Linux_DnsConfigurationInstanceName confInstanceName;
    confInstanceName.setNamespace(aNameSpaceP);
    confInstanceName.setName(DEFAULT_SERVICE_NAME);
    
    Linux_DnsServiceConfigurationManualInstance aManualInstance;
    Linux_DnsServiceConfigurationInstanceName instanceName;
    instanceName.setNamespace( aNameSpaceP );
    instanceName.setElement( aSourceInstanceName );
    instanceName.setConfiguration( confInstanceName );
    
    aManualInstance.setInstanceName(instanceName);
    
    aManualInstanceEnumeration.addElement(aManualInstance);

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceConfiguration::referencesConfiguration" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsServiceConfigurationResourceAccess::referencesElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsConfigurationInstanceName& aSourceInstanceName,
    Linux_DnsServiceConfigurationManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsServiceConfiguration::referencesElement" << endl;
#endif

    Linux_DnsServiceInstanceName serviceInstanceName;
    
    serviceInstanceName.setNamespace(aNameSpaceP);
    serviceInstanceName.setName(DEFAULT_SERVICE_NAME);
    serviceInstanceName.setSystemCreationClassName(DEFAULT_SYSTEM_CREATION_CLASS_NAME);
    serviceInstanceName.setSystemName(DEFAULT_SYSTEM_NAME);
    serviceInstanceName.setCreationClassName(DEFAULT_CREATION_CLASS_NAME);
    
    Linux_DnsServiceConfigurationManualInstance aManualInstance;
    Linux_DnsServiceConfigurationInstanceName instanceName;
    instanceName.setNamespace( aNameSpaceP );	
    instanceName.setElement( serviceInstanceName );
    instanceName.setConfiguration( aSourceInstanceName );
    
    aManualInstance.setInstanceName(instanceName);
    
    aManualInstanceEnumeration.addElement(aManualInstance);

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceConfiguration::referencesElement" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsServiceConfigurationResourceAccess::associatorsConfiguration( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsConfigurationInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsServiceConfiguration::associatorsConfiguration" << endl;
#endif

    Linux_DnsConfigurationInstanceName instanceName;
    Linux_DnsConfigurationInstance aManualInstance;
    
    instanceName.setNamespace(aNameSpaceP);
    instanceName.setName(DEFAULT_SERVICE_NAME);
    
    aManualInstance.setInstanceName(instanceName);
    aManualInstance.setConfigurationFile(get_bindconf());
    
    anInstanceEnumeration.addElement(aManualInstance);

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceConfiguration::associatorsConfiguration" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsServiceConfigurationResourceAccess::associatorsElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsConfigurationInstanceName& aSourceInstanceName,
    Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsServiceConfiguration::associatorsElement" << endl;
#endif

    Linux_DnsServiceInstance inst;
    Linux_DnsServiceInstanceName instanceName;
    
    instanceName.setNamespace(aNameSpaceP);
    instanceName.setName(DEFAULT_SERVICE_NAME);
    instanceName.setSystemCreationClassName(DEFAULT_SYSTEM_CREATION_CLASS_NAME);
    instanceName.setSystemName(DEFAULT_SYSTEM_NAME);
    instanceName.setCreationClassName(DEFAULT_CREATION_CLASS_NAME);
    inst.setInstanceName(instanceName);
    
    anInstanceEnumeration.addElement(inst);

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceConfiguration::associatorsElement" << endl;
#endif
  }

   
  
  // extrinsic methods

	
}


