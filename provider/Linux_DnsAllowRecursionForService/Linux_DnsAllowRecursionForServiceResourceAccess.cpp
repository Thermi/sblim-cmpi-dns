// =======================================================================
// Linux_DnsAllowRecursionForServiceResourceAccess.cpp
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
#include "Linux_DnsAllowRecursionForServiceResourceAccess.h"
#include <string>
#include <list>

#include "smt_dns_ra_support.h"
#include "smt_dns_ra_service.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"


namespace genProvider {
  
  static void setInstanceNameProperties(
      const char* aNameSpaceP,
      const char *optionName,
      Linux_DnsAllowRecursionForServiceInstanceName& anInstanceName) {

      Linux_DnsAddressMatchListInstanceName partComponent;
      Linux_DnsServiceInstanceName          groupComponent;

      //Forwarder
      partComponent.setNamespace(aNameSpaceP);
      partComponent.setName(optionName);
      partComponent.setInstanceID( DEFAULT_INSTANCE_ID );

      //Service
      groupComponent.setNamespace(aNameSpaceP);
      groupComponent.setName(DEFAULT_INSTANCE_ID);
      groupComponent.setSystemCreationClassName(DEFAULT_SYSTEM_CREATION_CLASS_NAME);
      groupComponent.setSystemName(DEFAULT_SYSTEM_NAME);
      groupComponent.setCreationClassName(DEFAULT_CREATION_CLASS_NAME);

      anInstanceName.setNamespace(aNameSpaceP);
      anInstanceName.setGroupComponent(groupComponent);
      anInstanceName.setPartComponent(partComponent);
  }


  static void setInstanceProperties(
      const Linux_DnsAllowRecursionForServiceInstanceName anInstanceName,
      Linux_DnsAllowRecursionForServiceManualInstance& aManualInstance) {

      aManualInstance.setInstanceName(anInstanceName);
  }

  //----------------------------------------------------------------------------
  //Linux_DnsAllowRecursionForServiceResourceAccess::Linux_DnsAllowRecursionForServiceResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsAllowRecursionForServiceResourceAccess::~Linux_DnsAllowRecursionForServiceResourceAccess() { }
    
  // intrinsic methods
  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowRecursionForServiceResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsAllowRecursionForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
     cout << "entering Linux_DnsAllowRecursionForService::enumInstanceNames" << endl;
#endif

    BINDOPTS *optionList = ReadOptions();
    BINDOPTS *optionListStart = optionList;

    if (optionList) {
      char* option = getOption(optionList, "allow-recursion");
      if (option) {
        string optionName = "options::allow-recursion";

        Linux_DnsAllowRecursionForServiceInstanceName anInstanceName;

        setInstanceNameProperties(aNameSpaceP, optionName.c_str(), anInstanceName);
        anInstanceNameEnumeration.addElement(anInstanceName);
      }
    }
    if (optionListStart) freeOptions( optionListStart );

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowRecursionForService::enumInstanceNames" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowRecursionForServiceResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsAllowRecursionForServiceManualInstanceEnumeration& aManualInstanceEnumeration) { 

#ifdef DEBUG
     cout << "entering Linux_DnsAllowRecursionForService::enumInstances" << endl;
#endif

    BINDOPTS *optionList = ReadOptions();
    BINDOPTS *optionListStart = optionList;

    if (optionList) {
      char* option = getOption(optionList, "allow-recursion");
      if (option) {
        string optionName = "options::allow-recursion";

        Linux_DnsAllowRecursionForServiceInstanceName anInstanceName;
        Linux_DnsAllowRecursionForServiceManualInstance aManualInstance;

        setInstanceNameProperties(aNameSpaceP, optionName.c_str(), anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);
        aManualInstanceEnumeration.addElement(aManualInstance);
      }
    }
    if (optionListStart) freeOptions( optionListStart );

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowRecursionForService::enumInstances" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAllowRecursionForServiceManualInstance 
  Linux_DnsAllowRecursionForServiceResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsAllowRecursionForServiceInstanceName& anInstanceName) {

#ifdef DEBUG
     cout << "entering Linux_DnsAllowRecursionForService::getInstance" << endl;
#endif

    Linux_DnsAllowRecursionForServiceManualInstance aManualInstance;

    BINDOPTS *optionList = ReadOptions();
    BINDOPTS *optionListStart = optionList;
    int found = 0;

    if (optionList) {
      char* option = getOption(optionList, "allow-recursion");
      if (option) {
          string optionName = "options::allow-recursion";

          if (strcmp(optionName.c_str(), anInstanceName.getPartComponent().getName()) == 0 &&
              strcmp(DEFAULT_SERVICE_NAME, anInstanceName.getGroupComponent().getName()) == 0) {

              setInstanceProperties(anInstanceName, aManualInstance);
              found = 1;
          }
      }
    }
    if (optionListStart) freeOptions( optionListStart );

    if(found == 0)
        throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"The specified instance does not exist!");

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowRecursionForService::getInstance" << endl;
#endif
    return aManualInstance;
  }

  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsAllowRecursionForServiceResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsAllowRecursionForServiceManualInstance& aManualInstance) { 

#ifdef DEBUG
     cout << "entering Linux_DnsAllowRecursionForService::setInstance" << endl;
#endif

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowRecursionForService::setInstance" << endl;
#endif
  }
  */

  //----------------------------------------------------------------------------
  /*
  Linux_DnsAllowRecursionForServiceInstanceName
  Linux_DnsAllowRecursionForServiceResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAllowRecursionForServiceManualInstance& aManualInstance) { 

#ifdef DEBUG
     cout << "entering Linux_DnsAllowRecursionForService::createInstance" << endl;
#endif

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowRecursionForService::createInstance" << endl;
#endif
  }
  */

  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsAllowRecursionForServiceResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAllowRecursionForServiceInstanceName& anInstanceName) { 

#ifdef DEBUG
     cout << "entering Linux_DnsAllowRecursionForService::deleteInstance" << endl;
#endif

    string partName = anInstanceName.getPartComponent().getName();
    string groupName = anInstanceName.getGroupComponent().getName();
    int deleted = 0;

    if (!partName.c_str() || !groupName.c_str())
        throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER, "The submitted instance name is not valid!");

    string parentName = partName.substr(0, partName.find_first_of("::"));
    partName.erase(0,partName.find_first_of("::")+2);

    if (strcmp("option", parentName.c_str()) == 0) {
        BINDOPTS *optionsList = ReadOptions();
        BINDOPTS *optionsListStart = optionsList;
        string optionName = partName.substr(0, partName.find_first_of("::"));

        if (strcmp(optionName.c_str(), "allow-recursion") != 0)
          throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a allow-recursion instance!");

        if (strcmp(DEFAULT_SERVICE_NAME, groupName.c_str()) == 0) {
          if (getOption(optionsList,"allow-recursion")) {
            deleteOption("allow-recursion");
            deleted = 1;
          }
        }
        if(optionsListStart)freeOptions(optionsListStart);

    } else {
      throw CmpiStatus(CMPI_RC_ERR_FAILED,"The specified instance defines a not supported allow-recursion attribute!");
    }

    if (deleted == 0) {
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"An instance could not be found for the submitted instance name!");
    }

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowRecursionForService::deleteInstance" << endl;
#endif
  }
  */

  // Association Interface
  //----------------------------------------------------------------------------
  void Linux_DnsAllowRecursionForServiceResourceAccess::referencesGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsAllowRecursionForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {

#ifdef DEBUG
     cout << "entering Linux_DnsAllowRecursionForService::referencesGroupComponent" << endl;
#endif

    BINDOPTS *optionList = ReadOptions();
    BINDOPTS *optionListStart = optionList;

    if (optionList) {
      char* option = getOption(optionList, "allow-recursion");
      if (option) {
        string optionName = "options::allow-recursion";

        if (strcmp (optionName.c_str(), aSourceInstanceName.getName()) != 0) return;

        Linux_DnsAllowRecursionForServiceInstanceName anInstanceName;
        Linux_DnsAllowRecursionForServiceManualInstance aManualInstance;

        setInstanceNameProperties(aNameSpaceP, optionName.c_str(), anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);
        aManualInstanceEnumeration.addElement(aManualInstance);
      }
    }
    if (optionListStart) freeOptions( optionListStart );

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowRecursionForService::referencesGroupComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsAllowRecursionForServiceResourceAccess::referencesPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsAllowRecursionForServiceManualInstanceEnumeration& aManualInstanceEnumeration) { 

#ifdef DEBUG
     cout << "entering Linux_DnsAllowRecursionForService::referencesPartComponent" << endl;
#endif

    if (strcmp (DEFAULT_SERVICE_NAME, aSourceInstanceName.getName()) != 0) return;

    BINDOPTS *optionList = ReadOptions();
    BINDOPTS *optionListStart = optionList;

    if (optionList) {
      char* option = getOption(optionList, "allow-recursion");
      if (option) {
        string optionName = "options::allow-recursion";

        Linux_DnsAllowRecursionForServiceInstanceName anInstanceName;
        Linux_DnsAllowRecursionForServiceManualInstance aManualInstance;

        setInstanceNameProperties(aNameSpaceP, optionName.c_str(), anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);
        aManualInstanceEnumeration.addElement(aManualInstance);
      }
    }
    if (optionListStart) freeOptions( optionListStart );

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowRecursionForService::referencesPartComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsAllowRecursionForServiceResourceAccess::associatorsGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
     cout << "entering Linux_DnsAllowRecursionForService::associatorsGroupComponent" << endl;
#endif

    BINDOPTS *optionList = ReadOptions();
    BINDOPTS *optionListStart = optionList;

    if (optionList) {
      char* option = getOption(optionList, "allow-recursion");
      if (option) {
        string optionName = "options::allow-recursion";
        if (strcmp(optionName.c_str(), aSourceInstanceName.getName()) != 0) return;

        Linux_DnsServiceInstanceName anInstanceName;
        Linux_DnsServiceInstance aManualInstance;

        anInstanceName.setNamespace(aNameSpaceP);
        anInstanceName.setName(DEFAULT_SERVICE_NAME);
        anInstanceName.setSystemCreationClassName(DEFAULT_SYSTEM_CREATION_CLASS_NAME);
        anInstanceName.setSystemName(DEFAULT_SYSTEM_NAME);
        anInstanceName.setCreationClassName(DEFAULT_CREATION_CLASS_NAME);
        aManualInstance.setInstanceName(anInstanceName);
        aManualInstance.setStarted( status_service() );

        anInstanceEnumeration.addElement(aManualInstance);
      }
    }
    if (optionListStart) freeOptions( optionListStart );

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowRecursionForService::associatorsGroupComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsAllowRecursionForServiceResourceAccess::associatorsPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
     cout << "entering Linux_DnsAllowRecursionForService::associatorsPartComponent" << endl;
#endif

    BINDOPTS *optionList = ReadOptions();
    BINDOPTS *optionListStart = optionList;

    if (strcmp(DEFAULT_SERVICE_NAME, aSourceInstanceName.getName()) != 0) return;

    if (optionList) {
      char* option = getOption(optionList, "allow-recursion");
      if (option) {
        string optionName = "options::allow-recursion";

        Linux_DnsAddressMatchListInstanceName anInstanceName;
        Linux_DnsAddressMatchListInstance aManualInstance;

        anInstanceName.setNamespace(aNameSpaceP);
        anInstanceName.setName(optionName.c_str());
        anInstanceName.setInstanceID( DEFAULT_INSTANCE_ID );
        aManualInstance.setInstanceName(anInstanceName);

        DnsArray da = DnsArray( option );
        aManualInstance.setAddressMatchListElement( da.toArray(), da.size() );

        CMPIUint8* optionType = new CMPIUint8[da.size()];
        DnsArrayConstIterator iter;
        int i = 0;

        for ( iter = da.begin(); iter != da.end(); ++iter) {
           optionType[i++] = getACLType((*iter).c_str());
        }
        aManualInstance.setAddressMatchListElementType (optionType, da.size() );
        anInstanceEnumeration.addElement(aManualInstance);
      }
    }
    if (optionListStart) freeOptions( optionListStart );

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowRecursionForService::associatorsPartComponent" << endl;
#endif
  }
   
  
  // extrinsic methods

	
}


