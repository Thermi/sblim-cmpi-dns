// =======================================================================
// Linux_DnsServiceConfigurationForServiceResourceAccess.cpp
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
#include "Linux_DnsServiceConfigurationForServiceResourceAccess.h"

#include <string>
#include <list>
#include <iostream>

using namespace std;

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsServiceConfigurationForServiceResourceAccess::Linux_DnsServiceConfigurationForServiceResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationForServiceResourceAccess::~Linux_DnsServiceConfigurationForServiceResourceAccess() { }
    
  // intrinsic methods
  
//----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
      
    int instanceNameN = 1;
    for (int x=0; x < instanceNameN; ++x) {

      Linux_DnsServiceConfigurationForServiceInstanceName instanceName;
      Linux_DnsServiceInstanceName serviceInstanceName;
      Linux_DnsServiceConfigurationInstanceName confInstName;

      instanceName.setNamespace(aNameSpaceP);

      serviceInstanceName.setNamespace(aNameSpaceP);
      serviceInstanceName.setName( DEFAULT_SERVICE_NAME );
      serviceInstanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
      serviceInstanceName.setSystemName( DEFAULT_SYSTEM_NAME );
      serviceInstanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );

      confInstName.setNamespace(aNameSpaceP);
      confInstName.setName(DEFAULT_SERVICE_NAME);

      instanceName.setConfiguration( confInstName );
      instanceName.setElement( serviceInstanceName );
      anInstanceNameEnumeration.addElement(instanceName);
    }
 
  }
  
  //----------------------------------------------------------------------------
  
  void
  Linux_DnsServiceConfigurationForServiceResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsServiceConfigurationForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {

      int instanceNameN = 1;
      for (int x=0; x < instanceNameN; ++x) {

      Linux_DnsServiceConfigurationForServiceManualInstance manualInstance;
      Linux_DnsServiceConfigurationForServiceInstanceName instanceName;
      Linux_DnsServiceInstanceName serviceInstanceName;
      Linux_DnsServiceConfigurationInstanceName confInstName;

      instanceName.setNamespace(aNameSpaceP);

      serviceInstanceName.setNamespace(aNameSpaceP);
      serviceInstanceName.setName( DEFAULT_SERVICE_NAME );
      serviceInstanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
      serviceInstanceName.setSystemName( DEFAULT_SYSTEM_NAME );
      serviceInstanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );

      confInstName.setNamespace(aNameSpaceP);
      confInstName.setName(DEFAULT_SERVICE_NAME);


      instanceName.setConfiguration(confInstName );
      instanceName.setElement(serviceInstanceName );

      manualInstance.setInstanceName(instanceName);
      aManualInstanceEnumeration.addElement(manualInstance);
    }


 }
  
  //----------------------------------------------------------------------------
  
  Linux_DnsServiceConfigurationForServiceManualInstance 
  Linux_DnsServiceConfigurationForServiceResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName) {

    Linux_DnsServiceConfigurationForServiceManualInstance manualInstance;
    manualInstance.setInstanceName(anInstanceName);

    return(manualInstance);

  }
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsServiceConfigurationForServiceResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsServiceConfigurationForServiceManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsServiceConfigurationForServiceInstanceName
  Linux_DnsServiceConfigurationForServiceResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceConfigurationForServiceManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsServiceConfigurationForServiceResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName) { }
	*/
	

  // Association Interface
  //----------------------------------------------------------------------------
  
  void Linux_DnsServiceConfigurationForServiceResourceAccess::referencesElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
    Linux_DnsServiceConfigurationForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {

#ifdef DEBUG
    cout << "entering Linux_DnsServiceConfigurationForService::referencesElement" << endl;
#endif

    Linux_DnsServiceInstanceName serviceInstanceName;

    serviceInstanceName.setNamespace(aNameSpaceP);
    serviceInstanceName.setName(DEFAULT_SERVICE_NAME);
    serviceInstanceName.setSystemCreationClassName(DEFAULT_SYSTEM_CREATION_CLASS_NAME);
    serviceInstanceName.setSystemName(DEFAULT_SYSTEM_NAME);
    serviceInstanceName.setCreationClassName(DEFAULT_CREATION_CLASS_NAME);

    Linux_DnsServiceConfigurationForServiceManualInstance aManualInstance;
    Linux_DnsServiceConfigurationForServiceInstanceName instanceName;
    instanceName.setNamespace( aNameSpaceP );
    instanceName.setElement( serviceInstanceName );
    instanceName.setConfiguration( aSourceInstanceName );

    aManualInstance.setInstanceName(instanceName);

    aManualInstanceEnumeration.addElement(aManualInstance);

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceConfigurationForService::referencesElement" << endl;
#endif


 }
  
  //----------------------------------------------------------------------------
  
  void Linux_DnsServiceConfigurationForServiceResourceAccess::referencesConfiguration( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsServiceConfigurationForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {


#ifdef DEBUG
    cout << "entering Linux_DnsServiceConfigurationForService::referencesConfiguration" << endl;
#endif

    Linux_DnsServiceConfigurationInstanceName confInstanceName;
    confInstanceName.setNamespace(aNameSpaceP);
    confInstanceName.setName(DEFAULT_SERVICE_NAME);

    Linux_DnsServiceConfigurationForServiceManualInstance aManualInstance;
    Linux_DnsServiceConfigurationForServiceInstanceName instanceName;
    instanceName.setNamespace( aNameSpaceP );
    instanceName.setElement( aSourceInstanceName );
    instanceName.setConfiguration( confInstanceName );

    aManualInstance.setInstanceName(instanceName);

    aManualInstanceEnumeration.addElement(aManualInstance);

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceConfigurationForService::referencesConfiguration" << endl;
#endif


 }
  
  //----------------------------------------------------------------------------
  
  void Linux_DnsServiceConfigurationForServiceResourceAccess::associatorsElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
    Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
    cout << "entering Linux_DnsServiceConfigurationForService::associatorsElement" << endl;
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
    cout << "exiting Linux_DnsServiceConfigurationForService::associatorsElement" << endl;
#endif


 }
  
  //----------------------------------------------------------------------------
  
  void Linux_DnsServiceConfigurationForServiceResourceAccess::associatorsConfiguration( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsServiceConfigurationInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
    cout << "entering Linux_DnsServiceConfigurationForService::associatorsConfiguration" << endl;
#endif

    Linux_DnsServiceConfigurationInstanceName instanceName;
    Linux_DnsServiceConfigurationInstance aManualInstance;

    instanceName.setNamespace(aNameSpaceP);
    instanceName.setName(DEFAULT_SERVICE_NAME);

    aManualInstance.setInstanceName(instanceName);
    aManualInstance.setConfigurationFile(get_bindconf());

    anInstanceEnumeration.addElement(aManualInstance);

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceConfigurationForService::associatorsConfiguration" << endl;
#endif


 }
   
  
  // extrinsic methods

	
}


