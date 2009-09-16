// =======================================================================
// Linux_DnsMastersForServiceResourceAccess.cpp
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
#include "Linux_DnsMastersForServiceResourceAccess.h"
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
      const char *mastersName,
      Linux_DnsMastersForServiceInstanceName& anInstanceName) {
 
      Linux_DnsMastersInstanceName partComponent;
      Linux_DnsServiceInstanceName          groupComponent;

      //Masters
      partComponent.setNamespace(aNameSpaceP);
      partComponent.setName(mastersName);
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
      const Linux_DnsMastersForServiceInstanceName anInstanceName,
      Linux_DnsMastersForServiceManualInstance& aManualInstance) {

      aManualInstance.setInstanceName(anInstanceName);
  }

  //----------------------------------------------------------------------------
  //Linux_DnsMastersForServiceResourceAccess::Linux_DnsMastersForServiceResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsMastersForServiceResourceAccess::~Linux_DnsMastersForServiceResourceAccess() { }
    
  // intrinsic methods
  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersForServiceResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsMastersForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
    cout << "entering Linux_DnsMastersForService::enumInstanceNames" << endl;
#endif

    MASTERS *mastersList = ReadMasters();
    MASTERS *mastersListStart = mastersList;

    if (mastersList) {
      for (; mastersList->key; mastersList++) {
        string mastersName = "global::";
        mastersName.append(mastersList->key);
        mastersName.append("::masters");

        Linux_DnsMastersForServiceInstanceName anInstanceName;

        setInstanceNameProperties(aNameSpaceP, mastersName.c_str(), anInstanceName);
        anInstanceNameEnumeration.addElement(anInstanceName);
      }
    }
    if (mastersListStart) freeMasters( mastersListStart );

#ifdef DEBUG
    cout << "exiting Linux_DnsMastersForService::enumInstanceNames" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersForServiceResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsMastersForServiceManualInstanceEnumeration& aManualInstanceEnumeration) { 

#ifdef DEBUG
    cout << "entering Linux_DnsMastersForService::enumInstances" << endl;
#endif

    MASTERS *mastersList = ReadMasters();
    MASTERS *mastersListStart = mastersList;

    if (mastersList) {
      for (; mastersList->key; mastersList++) {
        string mastersName = "global::";
        mastersName.append(mastersList->key);
        mastersName.append("::masters");

        Linux_DnsMastersForServiceInstanceName anInstanceName;
        Linux_DnsMastersForServiceManualInstance aManualInstance;

        setInstanceNameProperties(aNameSpaceP, mastersName.c_str(), anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);

        aManualInstanceEnumeration.addElement(aManualInstance);
      }
    }
    if (mastersListStart) freeMasters( mastersListStart );

#ifdef DEBUG
    cout << "exiting Linux_DnsMastersForService::enumInstances" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsMastersForServiceManualInstance 
  Linux_DnsMastersForServiceResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsMastersForServiceInstanceName& anInstanceName) {

#ifdef DEBUG
    cout << "entering Linux_DnsMastersForService::getInstance" << endl;
#endif

    Linux_DnsMastersForServiceManualInstance aManualInstance;

    MASTERS *mastersList = ReadMasters();
    MASTERS *mastersListStart = mastersList;
    int found = 0;

    if (mastersList) {
      for (; mastersList->key; mastersList++) {
        string mastersName = "global::";
        mastersName.append(mastersList->key);
        mastersName.append("::masters");

        if (strcmp(mastersName.c_str(), anInstanceName.getPartComponent().getName()) == 0 && 
            strcmp(DEFAULT_SERVICE_NAME, anInstanceName.getGroupComponent().getName()) == 0) {

            setInstanceProperties(anInstanceName, aManualInstance);
            found = 1;
        }
      }
    }
    if (mastersListStart) freeMasters( mastersListStart );

    if(found == 0)
        throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"The specified instance does not exist!");

#ifdef DEBUG
    cout << "exiting Linux_DnsMastersForService::getInstance" << endl;
#endif
 
    return aManualInstance;
  }

  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsMastersForServiceResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsMastersForServiceManualInstance& aManualInstance) { 

#ifdef DEBUG
    cout << "entering Linux_DnsMastersForService::setInstance" << endl;
#endif
    
    throw CmpiStatus(CMPI_RC_ERR_NOT_SUPPORTED, "The requested operation is not supported!");

#ifdef DEBUG
    cout << "exiting Linux_DnsMastersForService::setInstance" << endl;
#endif
  }
  */

  //----------------------------------------------------------------------------
  /*
  Linux_DnsMastersForServiceInstanceName
  Linux_DnsMastersForServiceResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMastersForServiceManualInstance& aManualInstance) { 

#ifdef DEBUG
    cout << "entering Linux_DnsMastersForService::createInstance" << endl;
#endif
    
    throw CmpiStatus(CMPI_RC_ERR_NOT_SUPPORTED, "The requested operation is not supported!");

#ifdef DEBUG
    cout << "exiting Linux_DnsMastersForService::createInstance" << endl;
#endif
  }
  */

  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersForServiceResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMastersForServiceInstanceName& anInstanceName) { 

#ifdef DEBUG
    cout << "entering Linux_DnsMastersForService::deleteInstance" << endl;
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
      MASTERS *mastersList = ReadMasters();
      MASTERS *mastersListStart = mastersList;
      string mastersName = partName.substr(0,partName.find_first_of("::"));

      if (mastersList) {
        for (; mastersList->key && deleted == 0; mastersList++) {
          if (strcmp(mastersList->key, mastersName.c_str()) == 0) {
            deleteMasters(mastersName.c_str());
            deleted = 1;
          }
        }
      }
      if (mastersListStart) freeMasters( mastersListStart );

    } else {
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The submitted instance does not specify a global MASTERS!");
    }

    if (deleted == 0) {
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"The submitted instance could not be found!");
    }

#ifdef DEBUG
    cout << "exiting Linux_DnsMastersForService::deleteInstance" << endl;
#endif
  }
	

  // Association Interface
  //----------------------------------------------------------------------------
  void Linux_DnsMastersForServiceResourceAccess::referencesGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsMastersInstanceName& aSourceInstanceName,
    Linux_DnsMastersForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {

#ifdef DEBUG
    cout << "entering Linux_DnsMastersForService::referencesGroupComponent" << endl;
#endif

    MASTERS *mastersList = ReadMasters();
    MASTERS *mastersListStart = mastersList;

    if (mastersList) {
      for (; mastersList->key; mastersList++) {
        string mastersName = "global::";
        mastersName.append(mastersList->key);
        mastersName.append("::masters");

        if (strcmp(mastersName.c_str(), aSourceInstanceName.getName()) != 0) continue;

        Linux_DnsMastersForServiceInstanceName anInstanceName;
        Linux_DnsMastersForServiceManualInstance aManualInstance;

        setInstanceNameProperties(aNameSpaceP, mastersName.c_str(), anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);

        aManualInstanceEnumeration.addElement(aManualInstance);
      }
    }
    if (mastersListStart) freeMasters( mastersListStart );

#ifdef DEBUG
    cout << "exiting Linux_DnsMastersForService::referencesGroupComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsMastersForServiceResourceAccess::referencesPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsMastersForServiceManualInstanceEnumeration& aManualInstanceEnumeration) { 

#ifdef DEBUG
    cout << "entering Linux_DnsMastersForService::referencesPartComponent" << endl;
#endif

    MASTERS *mastersList = ReadMasters();
    MASTERS *mastersListStart = mastersList;

    if (mastersList) {
      for (; mastersList->key; mastersList++) {
        string mastersName = "global::";
        mastersName.append(mastersList->key);
        mastersName.append("::masters");

        if (strcmp(DEFAULT_SERVICE_NAME, aSourceInstanceName.getName()) != 0) continue;

        Linux_DnsMastersForServiceInstanceName anInstanceName;
        Linux_DnsMastersForServiceManualInstance aManualInstance;

        setInstanceNameProperties(aNameSpaceP, mastersName.c_str(), anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);

        aManualInstanceEnumeration.addElement(aManualInstance);
      }
    }
    if (mastersListStart) freeMasters( mastersListStart );

#ifdef DEBUG
    cout << "exiting Linux_DnsMastersForService::referencesPartComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsMastersForServiceResourceAccess::associatorsGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsMastersInstanceName& aSourceInstanceName,
    Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
    cout << "entering Linux_DnsMastersForService::associatorsGroupComponent" << endl;
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
    cout << "exiting Linux_DnsMastersForService::associatorsGroupComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsMastersForServiceResourceAccess::associatorsPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsMastersInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
    cout << "entering Linux_DnsMastersForService::associatorsPartComponent" << endl;
#endif

    MASTERS *mastersList = ReadMasters();
    MASTERS *mastersListStart = mastersList;

    if (mastersList) {
      for (; mastersList->key; mastersList++) {
        string mastersName = "global::";
        mastersName.append(mastersList->key);
        mastersName.append("::masters");

        Linux_DnsMastersInstanceName anInstanceName;
        Linux_DnsMastersInstance aManualInstance;

        anInstanceName.setNamespace(aNameSpaceP);
        anInstanceName.setName(mastersName.c_str());
        anInstanceName.setInstanceID( DEFAULT_INSTANCE_ID );

        aManualInstance.setInstanceName(anInstanceName);

        DnsArray da = DnsArray( mastersList->value );
        aManualInstance.setMasterElement( da.toArray(), da.size() );

        CMPIUint8* mastersType = new CMPIUint8[da.size()];
        DnsArrayConstIterator iter;
        int i = 0;

        for ( iter = da.begin(); iter != da.end(); ++iter) {
           mastersType[i++] = getMastersType((*iter).c_str());
        }
        aManualInstance.setMasterElementType (mastersType, da.size() );

        anInstanceEnumeration.addElement(aManualInstance);
      }
    }
    if (mastersListStart) freeMasters( mastersListStart );

#ifdef DEBUG
    cout << "exiting Linux_DnsMastersForService::associatorsPartComponent" << endl;
#endif
  }
   
  
  // extrinsic methods

	
}


