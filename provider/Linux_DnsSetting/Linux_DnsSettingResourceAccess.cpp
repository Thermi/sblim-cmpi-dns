// =======================================================================
// Linux_DnsSettingResourceAccess.cpp
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
#include "Linux_DnsSettingResourceAccess.h"

#include <string>
#include <list>
#include <iostream>

using namespace std;

#include "smt_dns_defaultvalues.h"
#include "smt_dns_ra_support.h"
#include "smt_dns_valuemap.h"
#include "smt_dns_array.h"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsSettingResourceAccess::Linux_DnsSettingResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsSettingResourceAccess::~Linux_DnsSettingResourceAccess() { }
    
  // intrinsic methods

  //----------------------------------------------------------------------------
  void
  Linux_DnsSettingResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsSettingInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
    cout << "entering Linux_DnsSetting::enumInstanceNames" << endl;
#endif

    Linux_DnsSettingInstanceName instanceName;
    
    instanceName.setNamespace(aNameSpaceP);
    instanceName.setName(DEFAULT_SERVICE_NAME);
    
    anInstanceNameEnumeration.addElement(instanceName);

#ifdef DEBUG
    cout << "exiting Linux_DnsSetting::enumInstanceNames" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsSettingResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsSettingManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsSetting::enumInstances" << endl;
#endif

    Linux_DnsSettingManualInstance aManualInstance;
    Linux_DnsSettingInstanceName instanceName;
    
    instanceName.setNamespace(aNameSpaceP);
    instanceName.setName(DEFAULT_SERVICE_NAME);
    
    aManualInstance.setInstanceName(instanceName);
    
    BINDOPTS *bopts = ReadOptions();

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
    
    char *port = getOption(bopts,"port");
    if ( port ) {
      aManualInstance.setPortNumber( atoi( port ) );
      free( port );
    }
    
    char *tsig = getOption(bopts,"TSIG");
    if ( tsig ) {
      aManualInstance.setTSIG( atoi( tsig ) );
      free( tsig );
    }
    
    char *ttl = getOption(bopts,"TTL");
    if ( ttl ) {
      aManualInstance.setTTL( atoi( ttl ) );
      free( ttl );
    }
    
    aManualInstanceEnumeration.addElement(aManualInstance);

#ifdef DEBUG
    cout << "exiting Linux_DnsSetting::enumInstances" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  Linux_DnsSettingManualInstance 
  Linux_DnsSettingResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsSettingInstanceName& anInstanceName) {

#ifdef DEBUG
    cout << "entering Linux_DnsSetting::getInstance" << endl;
#endif

    Linux_DnsSettingManualInstance aManualInstance;
    aManualInstance.setInstanceName(anInstanceName);
    
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

#ifdef DEBUG
    cout << "exiting Linux_DnsSetting::getInstance" << endl;
#endif
    return aManualInstance; 
  }

  //----------------------------------------------------------------------------

  void
  Linux_DnsSettingResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsSettingManualInstance& aManualInstance) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsSetting::setInstance" << endl;
#endif

    BINDOPTS *bopt = ReadOptions();
    
    if ( aManualInstance.isConfigurationDirectorySet() )
      setOption(bopt, "directory", aManualInstance.getConfigurationDirectory() );
    
    if ( aManualInstance.isForwardSet() ) {
      if ( aManualInstance.getForward() == DNS_FORWARD_ONLY )
	setOption(bopt, "forward", strdup( "only" ) );
      
      if ( aManualInstance.getForward() == DNS_FORWARD_FIRST )
	setOption(bopt, "forward", strdup( "first" ) );
    }
    
    unsigned int size = 0;
    if ( aManualInstance.isForwardersSet() ) {
      const char **forwardersList = aManualInstance.getForwarders( size );
      DnsArray value_list;
      
      for (unsigned int i = 0; i < size; i++)
	if (! value_list.isPresent( string( forwardersList[i]) ) )
	  value_list.add( forwardersList[i] );
      
      setOption( bopt, "forwarders", strdup ( value_list.toString().c_str() ) );
    }
    
    if ( aManualInstance.isPortNumberSet() ) {
      char *port = (char *) malloc(6*sizeof(char));
      sprintf( port, "%lu", aManualInstance.getPortNumber() );
      setOption(bopt, "port", port ); 
      free(port);
    }
    if ( aManualInstance.isTSIGSet() ) {
      char *tsig = (char *) malloc(6*sizeof(char));
      sprintf( tsig, "%d", aManualInstance.getTSIG() );
      setOption(bopt, "TSIG", tsig );
      free(tsig);	
    }
    if ( aManualInstance.isTTLSet() ) {
      char *ttl = (char *) malloc(20*sizeof(char));
      sprintf( ttl, "%lu", aManualInstance.getTTL() );
      setOption(bopt, "TTL", ttl );
      free(ttl);
    }

#ifdef DEBUG
    cout << "exiting Linux_DnsSetting::setInstance" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsSettingInstanceName
  Linux_DnsSettingResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsSettingResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName) { }
	*/
	

  
  // extrinsic methods

  /*
  CMPIUint32 Linux_DnsSettingResourceAccess::ApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName,
      const CIM_CollectionOfMSEsInstanceName& Collection,
      int isCollectionPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CMPIBoolean& ContinueOnError,
      int isContinueOnErrorPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent,
      char**& CanNotApply,
      CMPICount& CanNotApplySize) { }
  */

  /*
  CMPIUint32 Linux_DnsSettingResourceAccess::ApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent) { }
  */

  /*
  CMPIUint32 Linux_DnsSettingResourceAccess::ApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName,
      const CIM_CollectionOfMSEsInstanceName& Collection,
      int isCollectionPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CMPIBoolean& ContinueOnError,
      int isContinueOnErrorPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      char**& CanNotApply,
      CMPICount& CanNotApplySize) { }
  */

  /*
  CMPIUint32 Linux_DnsSettingResourceAccess::ApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) { }
  */

  /*
  CMPIUint32 Linux_DnsSettingResourceAccess::VerifyOKToApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName,
      const CIM_CollectionOfMSEsInstanceName& Collection,
      int isCollectionPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent,
      char**& CanNotApply,
      CMPICount& CanNotApplySize) { }
  */

  /*
  CMPIUint32 Linux_DnsSettingResourceAccess::VerifyOKToApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent) { }
  */

  /*
  CMPIUint32 Linux_DnsSettingResourceAccess::VerifyOKToApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName,
      const CIM_CollectionOfMSEsInstanceName& Collection,
      int isCollectionPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      char**& CanNotApply,
      CMPICount& CanNotApplySize) { }
  */

  /*
  CMPIUint32 Linux_DnsSettingResourceAccess::VerifyOKToApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSettingInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) { }
  */

	
}


