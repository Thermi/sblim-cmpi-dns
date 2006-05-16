// =======================================================================
// Linux_DnsSettingContextResourceAccess.cpp
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
#include "Linux_DnsSettingContextResourceAccess.h"

#include <iostream>

using namespace std;

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsSettingContextResourceAccess::Linux_DnsSettingContextResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsSettingContextResourceAccess::~Linux_DnsSettingContextResourceAccess() { }
    
  // intrinsic methods
  /*
  //----------------------------------------------------------------------------
  void
  Linux_DnsSettingContextResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsSettingContextInstanceNameEnumeration& anInstanceNameEnumeration) {
      
    int instanceNameN = 1;
    for (int x=0; x < instanceNameN; ++x) {
      
      //place here the code retrieving your instanceName
      
      Linux_DnsSettingContextInstanceName instanceName;
      
    }      
  
  }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsSettingContextResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsSettingContextManualInstanceEnumeration& aManualInstanceEnumeration) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsSettingContextManualInstance 
  Linux_DnsSettingContextResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsSettingContextInstanceName& anInstanceName) {

    Linux_DnsSettingContextManualInstance manualInstance;

  
  }
  */
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsSettingContextResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsSettingContextManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsSettingContextInstanceName
  Linux_DnsSettingContextResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingContextManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsSettingContextResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingContextInstanceName& anInstanceName) { }
	*/
	

  // Association Interface
  //----------------------------------------------------------------------------

  void Linux_DnsSettingContextResourceAccess::referencesSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsConfigurationInstanceName& aSourceInstanceName,
    Linux_DnsSettingContextManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsSettingContext::referencesSetting" << endl;
#endif

    Linux_DnsSettingInstanceName settingInstName;
    settingInstName.setNamespace(aNameSpaceP);
    settingInstName.setName(DEFAULT_SERVICE_NAME);
    
    Linux_DnsSettingContextManualInstance inst;
    Linux_DnsSettingContextInstanceName instName;
    instName.setNamespace( aNameSpaceP ); 
    instName.setContext( aSourceInstanceName );
    instName.setSetting( settingInstName );
    inst.setInstanceName( instName );
    
    aManualInstanceEnumeration.addElement( inst );

#ifdef DEBUG
    cout << "exiting Linux_DnsSettingContext::referencesSetting" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsSettingContextResourceAccess::referencesContext( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsSettingInstanceName& aSourceInstanceName,
    Linux_DnsSettingContextManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsSettingContext::referencesContext" << endl;
#endif

    Linux_DnsConfigurationInstanceName configInstName;
    configInstName.setNamespace( aNameSpaceP );
    configInstName.setName( DEFAULT_SERVICE_NAME );
    
    Linux_DnsSettingContextManualInstance inst;
    Linux_DnsSettingContextInstanceName instName;
    instName.setNamespace( aNameSpaceP );
    instName.setContext( configInstName );
    instName.setSetting( aSourceInstanceName );
    inst.setInstanceName( instName );
    
    aManualInstanceEnumeration.addElement( inst );

#ifdef DEBUG
    cout << "exiting Linux_DnsSettingContext::referencesContext" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsSettingContextResourceAccess::associatorsSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsConfigurationInstanceName& aSourceInstanceName,
    Linux_DnsSettingInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsSettingContext::associatorsSetting" << endl;
#endif

    Linux_DnsSettingInstance settingInst;
    Linux_DnsSettingInstanceName instanceName;
    
    instanceName.setNamespace(aNameSpaceP);
    instanceName.setName(DEFAULT_SERVICE_NAME);
    
    settingInst.setInstanceName(instanceName);
    
    BINDOPTS *bopts = ReadOptions();
    
    string directory = string( getOption(bopts,"directory") );
    if ( directory.length() ) {
      string::size_type pos = 0;
      while (pos != string::npos) {
	pos = directory.find("\"",pos);
	if (pos != string::npos)
	  directory.erase(pos,1);
      }
      
      settingInst.setConfigurationDirectory( directory.c_str() );
    }
    
    char *port = getOption(bopts,"port");
    if ( port != NULL ) {
      settingInst.setPortNumber( atoi( port ) );
      free( port );
    }
    
    char *tsig = getOption(bopts,"TSIG");
    if ( tsig != NULL ) {
      settingInst.setTSIG( atoi( tsig ) );
      free( tsig );
    }
    
    char *ttl = getOption(bopts,"TTL");
    if ( ttl != NULL ) {
      settingInst.setTTL( atoi( ttl ) );
      free( ttl );
    }
    
    anInstanceEnumeration.addElement(settingInst);

#ifdef DEBUG
    cout << "exiting Linux_DnsSettingContext::associatorsSetting" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsSettingContextResourceAccess::associatorsContext( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsSettingInstanceName& aSourceInstanceName,
    Linux_DnsConfigurationInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsSettingContext::associatorsContext" << endl;
#endif

    Linux_DnsConfigurationInstance configInst;
    Linux_DnsConfigurationInstanceName configInstName;
    
    configInstName.setNamespace( aNameSpaceP );
    configInstName.setName( DEFAULT_SERVICE_NAME );
    configInst.setInstanceName( configInstName );
    configInst.setConfigurationFile( get_bindconf() );
    
    anInstanceEnumeration.addElement( configInst );

#ifdef DEBUG
    cout << "exiting Linux_DnsSettingContext::associatorsContext" << endl;
#endif
  }

   
  
  // extrinsic methods

	
}


