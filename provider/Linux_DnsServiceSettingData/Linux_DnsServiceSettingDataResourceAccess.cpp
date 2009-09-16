// =======================================================================
// Linux_DnsServiceSettingDataResourceAccess.cpp
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
#include "Linux_DnsServiceSettingDataResourceAccess.h"

#include <string>
#include <list>
#include <iostream>

using namespace std;

#include "smt_dns_defaultvalues.h"
#include "smt_dns_ra_support.h"
#include "smt_dns_valuemap.h"
#include "smt_dns_array.h"

#define DNS_DIRECTORY "directory"
#define DNS_FORWARD "forward"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsServiceSettingDataResourceAccess::Linux_DnsServiceSettingDataResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsServiceSettingDataResourceAccess::~Linux_DnsServiceSettingDataResourceAccess() { }
    
  // intrinsic methods
  
//----------------------------------------------------------------------------
  void
  Linux_DnsServiceSettingDataResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsServiceSettingDataInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
    cout << "entering Linux_DnsServiceSettingData::enumInstanceNames" << endl;
#endif

    Linux_DnsServiceSettingDataInstanceName instanceName;

    instanceName.setNamespace(aNameSpaceP);
    instanceName.setName(DEFAULT_SERVICE_NAME);
    instanceName.setInstanceID(DEFAULT_INSTANCE_ID);
 
    anInstanceNameEnumeration.addElement(instanceName);

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceSettingData::enumInstanceNames" << endl;
#endif
}
  
  //----------------------------------------------------------------------------
  
  void
  Linux_DnsServiceSettingDataResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsServiceSettingDataManualInstanceEnumeration& aManualInstanceEnumeration) {

#ifdef DEBUG
    cout << "entering Linux_DnsServiceSettingData::enumInstances" << endl;
#endif

    Linux_DnsServiceSettingDataManualInstance aManualInstance;
    Linux_DnsServiceSettingDataInstanceName instanceName;

    instanceName.setNamespace(aNameSpaceP);
    instanceName.setName(DEFAULT_SERVICE_NAME);
    instanceName.setInstanceID(DEFAULT_INSTANCE_ID);

    aManualInstance.setInstanceName(instanceName);

    BINDOPTS *bopts = ReadOptions();

   char *forward = getOption(bopts, DNS_FORWARD);
    if ( forward ) {

     if ( strcmp( forward, "first" ) == 0 )
	{
        aManualInstance.setForward( DNS_FORWARD_FIRST  );
        }

     else if ( strcmp( forward, "only" ) == 0 )
        {
        aManualInstance.setForward( DNS_FORWARD_ONLY );
        }
      else
        aManualInstance.setForward( DNS_FORWARD_UNKNOWN );

      free( forward );
    }

    char *directory = getOption(bopts, DNS_DIRECTORY);
    if ( directory )
     {
	aManualInstance.setConfigurationDirectory( directory );
     }
   free (directory);

    aManualInstanceEnumeration.addElement(aManualInstance);

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceSettingData::enumInstances" << endl;
#endif

 }
  
  //----------------------------------------------------------------------------
  
  Linux_DnsServiceSettingDataManualInstance 
  Linux_DnsServiceSettingDataResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsServiceSettingDataInstanceName& anInstanceName) {

#ifdef DEBUG
    cout << "entering Linux_DnsServiceSettingData::getInstance" << endl;
#endif

    Linux_DnsServiceSettingDataManualInstance aManualInstance;
    aManualInstance.setInstanceName(anInstanceName);

    BINDOPTS *bopts = NULL ; 
    bopts = ReadOptions();
    
    if (!bopts) { 
      throw CmpiStatus(CMPI_RC_ERR_FAILED, "Could not read Options.");
    } 

    char *forward = getOption(bopts,"forward");
    if ( forward ) {
      if ( strcmp( forward, "first" ) == 0 )
        aManualInstance.setForward( DNS_FORWARD_FIRST  );
      else if ( strcmp( forward, "only" ) == 0)
        aManualInstance.setForward( DNS_FORWARD_ONLY );
    }
      

    char *directory = getOption(bopts, DNS_DIRECTORY);
    if ( directory ) { 
        aManualInstance.setConfigurationDirectory( directory );
    }
     
//    if (!directory && !forward) 
//    { 
//      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The specified Instance could not be found"); 
//    }    
     
    if (directory) free(directory);
    if (forward) free(forward); 

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceSettingData::getInstance" << endl;
#endif
    return aManualInstance;
  
}
  
//----------------------------------------------------------------------------
  
  void
  Linux_DnsServiceSettingDataResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsServiceSettingDataManualInstance& aManualInstance) {

#ifdef DEBUG
    cout << "entering Linux_DnsServiceSettingData::setInstance" << endl;
#endif

     //check whether the said instance exists, else throw exception.
    if (strcasecmp(aManualInstance.getInstanceName().getName(),DEFAULT_SERVICE_NAME)!=0) {
       throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Instance does not exist!");
    }

    BINDOPTS *bopt = ReadOptions();

    if ( aManualInstance.isConfigurationDirectorySet() && !CmpiData(aManualInstance.getConfigurationDirectory()).isNullValue()) {
      cout << "--- Setting Option directory" << endl;
      setOption(bopt, "directory", aManualInstance.getConfigurationDirectory() );
    }
    else {
      cout << "--- Deleting Option directory" << endl;
      deleteOption("directory");
    }

    if ( aManualInstance.isForwardSet() && !CmpiData(aManualInstance.getForward()).isNullValue() && aManualInstance.getForward()!=0 ) {
      if ( aManualInstance.getForward() == DNS_FORWARD_ONLY )
        setOption(bopt, "forward", strdup( "only" ) );
      else if ( aManualInstance.getForward() == DNS_FORWARD_FIRST )
        setOption(bopt, "forward", strdup( "first" ) );
    } else
      deleteOption("forward");

#ifdef DEBUG
    cout << "exiting Linux_DnsServiceSettingData::setInstance" << endl;
#endif

}
  
//----------------------------------------------------------------------------
  /*
  Linux_DnsServiceSettingDataInstanceName
  Linux_DnsServiceSettingDataResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceSettingDataManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /* 
  void
  Linux_DnsServiceSettingDataResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsServiceSettingDataInstanceName& anInstanceName) { 

#ifdef DEBUG
      cout << "entering Linux_DnsServiceSettingData::deleteInstance" << endl;
#endif

     //check if the said instance exists, else throw exception.
     if (strcasecmp(anInstanceName.getName(),DEFAULT_SERVICE_NAME)!=0) {
        throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Instance does not exist!");
     }

    BINDOPTS* sopts = NULL ; 
    char * confdirvalue = NULL ; 
    char * forwardvalue = NULL ; 
    
    sopts = ReadOptions();
    
    if (sopts ) { 
        confdirvalue = getOption(sopts,DNS_DIRECTORY);
        forwardvalue = getOption(sopts,DNS_FORWARD);
   
        if (confdirvalue) {
            deleteOption( DNS_DIRECTORY );
            free ( confdirvalue );
        }
      
        if (!forwardvalue) {
            deleteOption( DNS_FORWARD );    
            free ( forwardvalue );
        }
    } 

#ifdef DEBUG
      cout << "exiting Linux_DnsNotifyACLForService::deleteInstance" << endl;
#endif
}
  */	
// extrinsic methods
	
}
