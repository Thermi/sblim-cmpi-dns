// =======================================================================
// Linux_DnsElementSettingResourceAccess.cpp
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
#include "Linux_DnsElementSettingResourceAccess.h"

#include <string>
#include <list>

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsElementSettingResourceAccess::Linux_DnsElementSettingResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsElementSettingResourceAccess::~Linux_DnsElementSettingResourceAccess() { }
    
  // intrinsic methods
  /*
  //----------------------------------------------------------------------------
  void
  Linux_DnsElementSettingResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsElementSettingInstanceNameEnumeration& anInstanceNameEnumeration) {
      
    int instanceNameN = 1;
    for (int x=0; x < instanceNameN; ++x) {
      
      //place here the code retrieving your instanceName
      
      Linux_DnsElementSettingInstanceName instanceName;
      
    }      
  
  }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsElementSettingResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsElementSettingManualInstanceEnumeration& aManualInstanceEnumeration) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsElementSettingManualInstance 
  Linux_DnsElementSettingResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsElementSettingInstanceName& anInstanceName) {

    Linux_DnsElementSettingManualInstance manualInstance;

  
  }
  */
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsElementSettingResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsElementSettingManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsElementSettingInstanceName
  Linux_DnsElementSettingResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsElementSettingManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsElementSettingResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsElementSettingInstanceName& anInstanceName) { }
	*/
	

  // Association Interface
  //----------------------------------------------------------------------------

  void Linux_DnsElementSettingResourceAccess::referencesSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsElementSettingManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsElementSetting::referencesSetting" << endl;
#endif

    Linux_DnsSettingInstanceName settingInstName;
    
    settingInstName.setNamespace(aNameSpaceP);
    settingInstName.setName(DEFAULT_SERVICE_NAME);
    
    Linux_DnsElementSettingManualInstance inst;
    Linux_DnsElementSettingInstanceName instName;
    instName.setNamespace( aNameSpaceP );
    instName.setElement( aSourceInstanceName );
    instName.setSetting( settingInstName );
    inst.setInstanceName( instName );
    
    aManualInstanceEnumeration.addElement( inst );

#ifdef DEBUG
    cout << "exiting Linux_DnsElementSetting::referencesSetting" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsElementSettingResourceAccess::referencesElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsSettingInstanceName& aSourceInstanceName,
    Linux_DnsElementSettingManualInstanceEnumeration& aManualInstanceEnumeration) { 
    
#ifdef DEBUG
    cout << "entering Linux_DnsElementSetting::referencesElement" << endl;
#endif

    Linux_DnsServiceInstanceName serviceInstName;
    serviceInstName.setNamespace(aNameSpaceP);
    serviceInstName.setName(DEFAULT_SERVICE_NAME);
    serviceInstName.setSystemCreationClassName(DEFAULT_SYSTEM_CREATION_CLASS_NAME);
    serviceInstName.setSystemName(DEFAULT_SYSTEM_NAME);
    serviceInstName.setCreationClassName(DEFAULT_CREATION_CLASS_NAME);
    
    Linux_DnsElementSettingManualInstance inst;
    Linux_DnsElementSettingInstanceName instName;
    instName.setNamespace( aNameSpaceP );
    instName.setElement( serviceInstName );
    instName.setSetting( aSourceInstanceName );
    inst.setInstanceName( instName );
    
    aManualInstanceEnumeration.addElement( inst );

#ifdef DEBUG
    cout << "exiting Linux_DnsElementSetting::referencesElement" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsElementSettingResourceAccess::associatorsSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsSettingInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsElementSetting::associatorsSetting" << endl;
#endif

    Linux_DnsSettingInstance aManualInstance;
    Linux_DnsSettingInstanceName instanceName;
    
    instanceName.setNamespace(aNameSpaceP);
    instanceName.setName(DEFAULT_SERVICE_NAME);
    
    aManualInstance.setInstanceName(instanceName);
    
    BINDOPTS *bopts = ReadOptions();
    
    string directory = string( getOption(bopts,"directory") );
    if ( directory.length() ) {
      string::size_type pos = 0;
      while (pos != string::npos) {
	pos = directory.find("\"",pos);
	if (pos != string::npos)
	  directory.erase(pos,1);
      }
      
      aManualInstance.setConfigurationDirectory( directory.c_str() );
    }
    
    char *forward = getOption(bopts,"forward");
    if ( forward ) {
      if ( strcmp( forward, "first" ) )
	aManualInstance.setForward( DNS_FORWARD_FIRST  );
      
      if ( strcmp( forward, "only" ) )
	aManualInstance.setForward( DNS_FORWARD_ONLY );
      
      free( forward );
    }
    
    char* forwarders = getOption( bopts, "forwarders" );
    if ( forwarders ) {
      DnsArray da = DnsArray( forwarders );
      aManualInstance.setForwarders( da.toArray(), da.size() );
      free( forwarders );
    }
    
    char *port = getOption(bopts,"port");
    if ( port != NULL ) {
      aManualInstance.setPortNumber( atoi( port ) );
      free( port );
    }
    
    char *tsig = getOption(bopts,"TSIG");
    if ( tsig != NULL ) {
      aManualInstance.setTSIG( atoi( tsig ) );
      free( tsig );
    }
    
    char *ttl = getOption(bopts,"TTL");
    if ( ttl != NULL ) {
      aManualInstance.setTTL( atoi( ttl ) );
      free( ttl );
    }
    
   anInstanceEnumeration.addElement(aManualInstance);

#ifdef DEBUG
    cout << "exiting Linux_DnsElementSetting::associatorsSetting" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsElementSettingResourceAccess::associatorsElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsSettingInstanceName& aSourceInstanceName,
    Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsElementSetting::associatorsElement" << endl;
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
    cout << "exiting Linux_DnsElementSetting::associatorsElement" << endl;
#endif
  }

   
  
  // extrinsic methods

	
}


