// =======================================================================
// Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess.cpp
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
#include "Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess.h"

#include <iostream>

using namespace std;

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"

#define DNS_DIRECTORY "directory"
#define DNS_FORWARD "forward"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess::Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess::~Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess() { }
    
  // intrinsic methods
  
//----------------------------------------------------------------------------

  void
  Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration& anInstanceNameEnumeration) {
      
    int instanceNameN = 1;
    for (int x=0; x < instanceNameN; ++x) {


    #ifdef DEBUG
     cout << "entering Linux_DnsServiceSettingDataForServiceConfiguration::enumInstanceNames" << endl;
    #endif

      Linux_DnsServiceSettingDataForServiceConfigurationInstanceName instanceName;
      Linux_DnsServiceSettingDataInstanceName PartCompInst;
      Linux_DnsServiceConfigurationInstanceName GroupCompInst;

    instanceName.setNamespace(aNameSpaceP);
    PartCompInst.setNamespace(aNameSpaceP);
    GroupCompInst.setNamespace(aNameSpaceP);

    PartCompInst.setName(DEFAULT_SERVICE_NAME);
    PartCompInst.setInstanceID(DEFAULT_INSTANCE_ID);

    GroupCompInst.setName(DEFAULT_SERVICE_NAME);

    instanceName.setGroupComponent(GroupCompInst);
    instanceName.setPartComponent(PartCompInst);

    anInstanceNameEnumeration.addElement(instanceName);

    #ifdef DEBUG
     cout << "exiting Linux_DnsServiceSettingDataForServiceConfiguration::enumInstanceNames" << endl;
    #endif
    }
 }
  
  //----------------------------------------------------------------------------
  
  void
  Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration& aManualInstanceEnumeration) {


    int instanceNameN = 1;
    for (int x=0; x < instanceNameN; ++x) {


    #ifdef DEBUG
     cout << "entering Linux_DnsServiceSettingDataForServiceConfiguration::enumInstances" << endl;
    #endif
      Linux_DnsServiceSettingDataForServiceConfigurationManualInstance manualInst;
      Linux_DnsServiceSettingDataForServiceConfigurationInstanceName instanceName;
      Linux_DnsServiceSettingDataInstanceName PartCompInst;
      Linux_DnsServiceConfigurationInstanceName GroupCompInst;

    instanceName.setNamespace(aNameSpaceP);
    PartCompInst.setNamespace(aNameSpaceP);
    GroupCompInst.setNamespace(aNameSpaceP);

    PartCompInst.setName(DEFAULT_SERVICE_NAME);
    PartCompInst.setInstanceID(DEFAULT_INSTANCE_ID);

    GroupCompInst.setName(DEFAULT_SERVICE_NAME);

    instanceName.setGroupComponent(GroupCompInst);
    instanceName.setPartComponent(PartCompInst);

    manualInst.setInstanceName(instanceName);
    aManualInstanceEnumeration.addElement(manualInst);

    #ifdef DEBUG
     cout << "exiting Linux_DnsServiceSettingDataForServiceConfiguration::enumInstances" << endl;
    #endif
    }

}
  
  //----------------------------------------------------------------------------
  
  Linux_DnsServiceSettingDataForServiceConfigurationManualInstance 
  Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anInstanceName) {


    #ifdef DEBUG
     cout << "entering Linux_DnsServiceSettingDataForServiceConfiguration::getInstance" << endl;
    #endif


    Linux_DnsServiceSettingDataForServiceConfigurationManualInstance manualInstance;
    manualInstance.setInstanceName(anInstanceName);

    #ifdef DEBUG
     cout << "exiting Linux_DnsServiceSettingDataForServiceConfiguration::getInstance" << endl;
    #endif

    return manualInstance;

  
  }
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsServiceSettingDataForServiceConfigurationManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
/* 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName
  Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceSettingDataForServiceConfigurationManualInstance& aManualInstance) {

#ifdef DEBUG
    cout << "entering Linux_DnsServiceSettingDataForServiceConfiguration::createInstance" << endl;
#endif
    BINDOPTS* sopts = ReadOptions();
    char *dirvalue = getOption(sopts, 	DNS_DIRECTORY);
    char *forward = getOption(sopts, DNS_FORWARD);
   
   
    if (dirvalue)
    char* test =string(aManualInstance.getInstanceName().getPartComponent().getName())
    cout<<"The value of test is "<<test<<endl;

 }
  */
  //----------------------------------------------------------------------------
 /* void
  Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anInstanceName) {



 }
*/	

  // Association Interface
  //----------------------------------------------------------------------------
  
  void Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess::referencesGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceSettingDataInstanceName& aSourceInstanceName,
    Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration& aManualInstanceEnumeration) {

#ifdef DEBUG
    cout << "entering Linux_DnsServiceSettingDataForServiceConfiguration::referencesGroupComponent" << endl;
#endif

    Linux_DnsServiceConfigurationInstanceName configInstName;
    configInstName.setNamespace( aNameSpaceP );
    configInstName.setName( DEFAULT_SERVICE_NAME );

    Linux_DnsServiceSettingDataForServiceConfigurationManualInstance inst;
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceName instName;
    instName.setNamespace( aNameSpaceP );
    instName.setGroupComponent( configInstName );
    instName.setPartComponent( aSourceInstanceName );
    inst.setInstanceName( instName );

    aManualInstanceEnumeration.addElement( inst );

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceSettingDataForServiceConfiguration::referencesGroupComponent" << endl;
#endif


 }
  
  //----------------------------------------------------------------------------
  
  void Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess::referencesPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
    Linux_DnsServiceSettingDataForServiceConfigurationManualInstanceEnumeration& aManualInstanceEnumeration) {

#ifdef DEBUG
    cout << "entering Linux_DnsServiceSettingDataForServiceConfiguration::referencesPartComponent" << endl;
#endif

    Linux_DnsServiceSettingDataInstanceName settingInstName;
    settingInstName.setNamespace(aNameSpaceP);
    settingInstName.setName(DEFAULT_SERVICE_NAME);
    settingInstName.setInstanceID(DEFAULT_INSTANCE_ID);
 
    Linux_DnsServiceSettingDataForServiceConfigurationManualInstance inst;
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceName instName;
    instName.setNamespace( aNameSpaceP );
    instName.setGroupComponent( aSourceInstanceName );
    instName.setPartComponent( settingInstName );
    inst.setInstanceName( instName );

    aManualInstanceEnumeration.addElement( inst );

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceSettingDataForServiceConfiguration::referencesPartComponent" << endl;
#endif


 }
  
  //----------------------------------------------------------------------------
  
  void Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess::associatorsGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceSettingDataInstanceName& aSourceInstanceName,
    Linux_DnsServiceConfigurationInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
    cout << "entering Linux_DnsServiceSettingDataForServiceConfiguration::associatorsGroupComponent" << endl;
#endif

    Linux_DnsServiceConfigurationInstance configInst;
    Linux_DnsServiceConfigurationInstanceName configInstName;

    configInstName.setNamespace( aNameSpaceP );
    configInstName.setName( DEFAULT_SERVICE_NAME );
    configInst.setInstanceName( configInstName );
    configInst.setConfigurationFile( get_bindconf() );

    anInstanceEnumeration.addElement( configInst );

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceSettingDataForServiceConfiguration::associatorsGroupCompoment" << endl;
#endif


 }
  
  //----------------------------------------------------------------------------
  
  void Linux_DnsServiceSettingDataForServiceConfigurationResourceAccess::associatorsPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
    Linux_DnsServiceSettingDataInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
    cout << "entering Linux_DnsServiceSettingDataForServiceConfiguration::associatorsPartComponent" << endl;
#endif

    Linux_DnsServiceSettingDataInstance settingInst;
    Linux_DnsServiceSettingDataInstanceName instanceName;

    instanceName.setNamespace(aNameSpaceP);
    instanceName.setName(DEFAULT_SERVICE_NAME);
    instanceName.setInstanceID(DEFAULT_INSTANCE_ID);

    settingInst.setInstanceName(instanceName);

    BINDOPTS *bopts = ReadOptions();
    
    char* directory = getOption(bopts, "directory");

    if ( directory ) {
      string directoryS = string( directory );
      if (directoryS.length() ) {
        string::size_type pos = 0;
        while (pos != string::npos) {
          pos = directoryS.find("\"",pos);
          if (pos != string::npos)
            directoryS.erase(pos,1);
        }
        settingInst.setConfigurationDirectory( directoryS.c_str() );
      }
    }


    anInstanceEnumeration.addElement(settingInst);

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceSettingDataForServiceConfiguration::associatorsPartComponent" << endl;
#endif


 }
   
  
  // extrinsic methods

	
}


