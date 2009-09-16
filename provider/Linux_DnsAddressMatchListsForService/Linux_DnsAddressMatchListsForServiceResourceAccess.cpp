// =======================================================================
// Linux_DnsAddressMatchListsForServiceResourceAccess.cpp
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
#include "Linux_DnsAddressMatchListsForServiceResourceAccess.h"
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
      const char *aclName,
      Linux_DnsAddressMatchListsForServiceInstanceName& anInstanceName) {
 
      Linux_DnsAddressMatchListInstanceName partComponent;
      Linux_DnsServiceInstanceName          groupComponent;

      //ACL
      partComponent.setNamespace(aNameSpaceP);
      partComponent.setName(aclName);
      partComponent.setInstanceID( DEFAULT_INSTANCE_ID );

      //Service
      groupComponent.setNamespace(aNameSpaceP);
      groupComponent.setName(DEFAULT_SERVICE_NAME);
      groupComponent.setSystemCreationClassName(DEFAULT_SYSTEM_CREATION_CLASS_NAME);
      groupComponent.setSystemName(DEFAULT_SYSTEM_NAME);
      groupComponent.setCreationClassName(DEFAULT_CREATION_CLASS_NAME);

      anInstanceName.setNamespace(aNameSpaceP);
      anInstanceName.setGroupComponent(groupComponent);
      anInstanceName.setPartComponent(partComponent);
  }


  static void setInstanceProperties(
      const Linux_DnsAddressMatchListsForServiceInstanceName anInstanceName,
      Linux_DnsAddressMatchListsForServiceManualInstance& aManualInstance) {

      aManualInstance.setInstanceName(anInstanceName);
  }

  //----------------------------------------------------------------------------
  //Linux_DnsAddressMatchListsForServiceResourceAccess::Linux_DnsAddressMatchListsForServiceResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListsForServiceResourceAccess::~Linux_DnsAddressMatchListsForServiceResourceAccess() { }
    
  // intrinsic methods
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListsForServiceResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsAddressMatchListsForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
    cout << "entering Linux_DnsAddressMatchListsForService::enumInstanceNames" << endl;
#endif

    ACL *list_acl = ReadACL();
    ACL *list_aclStart = list_acl;

    if (list_acl) {
      for (; list_acl->key; list_acl++) {
        string aclName = "global::";
        aclName.append(list_acl->key);
        aclName.append("::acl");

        Linux_DnsAddressMatchListsForServiceInstanceName anInstanceName;

        setInstanceNameProperties(aNameSpaceP, aclName.c_str(), anInstanceName);
        anInstanceNameEnumeration.addElement(anInstanceName);
      }
    }
    if (list_aclStart) freeACL( list_aclStart );

#ifdef DEBUG
    cout << "exiting Linux_DnsAddressMatchListsForService::enumInstanceNames" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListsForServiceResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsAddressMatchListsForServiceManualInstanceEnumeration& aManualInstanceEnumeration) { 

#ifdef DEBUG
    cout << "entering Linux_DnsAddressMatchListsForService::enumInstances" << endl;
#endif

    ACL *list_acl = ReadACL();
    ACL *list_aclStart = list_acl;

    if (list_acl) {
      for (; list_acl->key; list_acl++) {
        string aclName = "global::";
        aclName.append(list_acl->key);
        aclName.append("::acl");

        Linux_DnsAddressMatchListsForServiceInstanceName anInstanceName;
        Linux_DnsAddressMatchListsForServiceManualInstance aManualInstance;

        setInstanceNameProperties(aNameSpaceP, aclName.c_str(), anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);

        aManualInstanceEnumeration.addElement(aManualInstance);
      }
    }
    if (list_aclStart) freeACL( list_aclStart );

#ifdef DEBUG
    cout << "exiting Linux_DnsAddressMatchListsForService::enumInstances" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListsForServiceManualInstance 
  Linux_DnsAddressMatchListsForServiceResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListsForServiceInstanceName& anInstanceName) {

#ifdef DEBUG
    cout << "entering Linux_DnsAddressMatchListsForService::getInstance" << endl;
#endif

    Linux_DnsAddressMatchListsForServiceManualInstance aManualInstance;

    ACL *list_acl = ReadACL();
    ACL *list_aclStart = list_acl;
    int found = 0;

    if (list_acl) {
      for (; list_acl->key; list_acl++) {
        string aclName = "global::";
        aclName.append(list_acl->key);
        aclName.append("::acl");

        if (strcmp(aclName.c_str(), anInstanceName.getPartComponent().getName()) == 0 && 
            strcmp(DEFAULT_SERVICE_NAME, anInstanceName.getGroupComponent().getName()) == 0) {

            setInstanceProperties(anInstanceName, aManualInstance);
            found = 1;
        }
      }
    }
    if (list_aclStart) freeACL( list_aclStart );

    if(found == 0)
        throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"The specified instance does not exist!");

#ifdef DEBUG
    cout << "exiting Linux_DnsAddressMatchListsForService::getInstance" << endl;
#endif
 
    return aManualInstance;
  }

  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsAddressMatchListsForServiceResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsAddressMatchListsForServiceManualInstance& aManualInstance) { 

#ifdef DEBUG
    cout << "entering Linux_DnsAddressMatchListsForService::setInstance" << endl;
#endif
    
    throw CmpiStatus(CMPI_RC_ERR_NOT_SUPPORTED, "The requested operation is not supported!");

#ifdef DEBUG
    cout << "exiting Linux_DnsAddressMatchListsForService::setInstance" << endl;
#endif
  }
  */

  //----------------------------------------------------------------------------
  /*
  Linux_DnsAddressMatchListsForServiceInstanceName
  Linux_DnsAddressMatchListsForServiceResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAddressMatchListsForServiceManualInstance& aManualInstance) { 

#ifdef DEBUG
    cout << "entering Linux_DnsAddressMatchListsForService::createInstance" << endl;
#endif
    
    throw CmpiStatus(CMPI_RC_ERR_NOT_SUPPORTED, "The requested operation is not supported!");

#ifdef DEBUG
    cout << "exiting Linux_DnsAddressMatchListsForService::createInstance" << endl;
#endif
  }
  */

  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListsForServiceResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAddressMatchListsForServiceInstanceName& anInstanceName) { 

#ifdef DEBUG
    cout << "entering Linux_DnsAddressMatchListsForService::deleteInstance" << endl;
#endif

    string partName = anInstanceName.getPartComponent().getName();
    string groupName = anInstanceName.getGroupComponent().getName();
    int deleted = 0;

    if (!partName.c_str() || !groupName.c_str())
        throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER, "The submitted instance name is not valid!");
 
    if (strcmp(groupName.c_str(), DEFAULT_SERVICE_NAME))
        throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER, "The submitted group component is an unknown service!");

    string parentName = partName.substr(0, partName.find_first_of("::"));
    partName.erase(0,partName.find_first_of("::")+2);

    if (strcmp("global", parentName.c_str()) == 0) {
      ACL *list_acl = ReadACL();
      ACL *list_aclStart = list_acl;
      string aclName = partName.substr(0,partName.find_first_of("::"));

      if (list_acl) {
        for (; list_acl->key && deleted == 0; list_acl++) {
          if (strcmp(list_acl->key, aclName.c_str()) == 0) {
            deleteACL(aclName.c_str());
            deleted = 1;
          }
        }
      }
      if (list_aclStart) freeACL( list_aclStart );

    } else {
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The submitted instance does not specify a global ACL!");
    }

    if (deleted == 0) {
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"The submitted instance could not be found!");
    }

#ifdef DEBUG
    cout << "exiting Linux_DnsAddressMatchListsForService::deleteInstance" << endl;
#endif
  }
	

  // Association Interface
  //----------------------------------------------------------------------------
  void Linux_DnsAddressMatchListsForServiceResourceAccess::referencesGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListsForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {

#ifdef DEBUG
    cout << "entering Linux_DnsAddressMatchListsForService::referencesGroupComponent" << endl;
#endif

    ACL *list_acl = ReadACL();
    ACL *list_aclStart = list_acl;

    if (list_acl) {
      for (; list_acl->key; list_acl++) {
        string aclName = "global::";
        aclName.append(list_acl->key);
        aclName.append("::acl");

        if (strcmp(aclName.c_str(), aSourceInstanceName.getName()) != 0) continue;

        Linux_DnsAddressMatchListsForServiceInstanceName anInstanceName;
        Linux_DnsAddressMatchListsForServiceManualInstance aManualInstance;

        setInstanceNameProperties(aNameSpaceP, aclName.c_str(), anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);

        aManualInstanceEnumeration.addElement(aManualInstance);
      }
    }
    if (list_aclStart) freeACL( list_aclStart );

#ifdef DEBUG
    cout << "exiting Linux_DnsAddressMatchListsForService::referencesGroupComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsAddressMatchListsForServiceResourceAccess::referencesPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListsForServiceManualInstanceEnumeration& aManualInstanceEnumeration) { 

#ifdef DEBUG
    cout << "entering Linux_DnsAddressMatchListsForService::referencesPartComponent" << endl;
#endif

    ACL *list_acl = ReadACL();
    ACL *list_aclStart = list_acl;

    if (list_acl) {
      for (; list_acl->key; list_acl++) {
        string aclName = "global::";
        aclName.append(list_acl->key);
        aclName.append("::acl");

        if (strcmp(DEFAULT_SERVICE_NAME, aSourceInstanceName.getName()) != 0) continue;

        Linux_DnsAddressMatchListsForServiceInstanceName anInstanceName;
        Linux_DnsAddressMatchListsForServiceManualInstance aManualInstance;

        setInstanceNameProperties(aNameSpaceP, aclName.c_str(), anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);

        aManualInstanceEnumeration.addElement(aManualInstance);
      }
    }
    if (list_aclStart) freeACL( list_aclStart );

#ifdef DEBUG
    cout << "exiting Linux_DnsAddressMatchListsForService::referencesPartComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsAddressMatchListsForServiceResourceAccess::associatorsGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
    cout << "entering Linux_DnsAddressMatchListsForService::associatorsGroupComponent" << endl;
#endif

    Linux_DnsServiceInstance inst;
    Linux_DnsServiceInstanceName instanceName;

    instanceName.setNamespace(aNameSpaceP);
    instanceName.setName(DEFAULT_SERVICE_NAME);
    instanceName.setSystemCreationClassName(DEFAULT_SYSTEM_CREATION_CLASS_NAME);
    instanceName.setSystemName(DEFAULT_SYSTEM_NAME);
    instanceName.setCreationClassName(DEFAULT_CREATION_CLASS_NAME);
    inst.setInstanceName(instanceName);

    inst.setStarted( status_service() );

    anInstanceEnumeration.addElement(inst);

#ifdef DEBUG
    cout << "exiting Linux_DnsAddressMatchListsForService::associatorsGroupComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsAddressMatchListsForServiceResourceAccess::associatorsPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
    cout << "entering Linux_DnsAddressMatchListsForService::associatorsPartComponent" << endl;
#endif

    ACL *list_acl = ReadACL();
    ACL *list_aclStart = list_acl;

    if (list_acl) {
      for (; list_acl->key; list_acl++) {
        string aclName = "global::";
        aclName.append(list_acl->key);
        aclName.append("::acl");

        Linux_DnsAddressMatchListInstanceName anInstanceName;
        Linux_DnsAddressMatchListInstance aManualInstance;

        anInstanceName.setNamespace(aNameSpaceP);
        anInstanceName.setName(aclName.c_str());
        anInstanceName.setInstanceID( DEFAULT_INSTANCE_ID );

        aManualInstance.setInstanceName(anInstanceName);

        DnsArray da = DnsArray( list_acl->value );
        aManualInstance.setAddressMatchListElement( da.toArray(), da.size() );

        CMPIUint8* aclType = new CMPIUint8[da.size()];
        DnsArrayConstIterator iter;
        int i = 0;

        for ( iter = da.begin(); iter != da.end(); ++iter) {
           aclType[i++] = getACLType((*iter).c_str());
        }
        aManualInstance.setAddressMatchListElementType (aclType, da.size() );

        anInstanceEnumeration.addElement(aManualInstance);
      }
    }
    if (list_aclStart) freeACL( list_aclStart );

#ifdef DEBUG
    cout << "exiting Linux_DnsAddressMatchListsForService::associatorsPartComponent" << endl;
#endif
  }
   
  
  // extrinsic methods

	
}


