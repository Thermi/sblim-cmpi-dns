// =======================================================================
// Linux_DnsMastersForZoneResourceAccess.cpp
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
#include "Linux_DnsMastersForZoneResourceAccess.h"
#include <string>
#include <list>

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

namespace genProvider {
  
  static void setInstanceNameProperties(
      const char *aNameSpaceP,
      const char *mastersName,
      const char *zoneName,
      Linux_DnsMastersForZoneInstanceName& anInstanceName) {

      Linux_DnsMastersInstanceName  partComponent;
      Linux_DnsZoneInstanceName     groupComponent;

      //ACL
      partComponent.setNamespace(aNameSpaceP);
      partComponent.setName(mastersName);
      partComponent.setInstanceID( DEFAULT_INSTANCE_ID );

      //Service
      groupComponent.setNamespace(aNameSpaceP);
      groupComponent.setName(zoneName);
      groupComponent.setInstanceID( DEFAULT_INSTANCE_ID );

      anInstanceName.setNamespace(aNameSpaceP);
      anInstanceName.setGroupComponent(groupComponent);
      anInstanceName.setPartComponent(partComponent);
  }


  static void setInstanceProperties(
      const Linux_DnsMastersForZoneInstanceName anInstanceName,
      Linux_DnsMastersForZoneManualInstance& aManualInstance) {

      aManualInstance.setInstanceName(anInstanceName);
  }

  //----------------------------------------------------------------------------
  //Linux_DnsMastersForZoneResourceAccess::Linux_DnsMastersForZoneResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsMastersForZoneResourceAccess::~Linux_DnsMastersForZoneResourceAccess() { }
    
  // intrinsic methods
  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersForZoneResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsMastersForZoneInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
     cout << "entering Linux_DnsMastersForZone::enumInstanceNames" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      ZONEOPTS* zopts = findOptsInZone(zones,"masters");

      if (zopts) {
        string mastersName = "zone::";
        mastersName.append(zones->zoneName);
        mastersName.append("::masters");

        Linux_DnsMastersForZoneInstanceName anInstanceName;
        setInstanceNameProperties(aNameSpaceP, mastersName.c_str(), zones->zoneName, anInstanceName);
        anInstanceNameEnumeration.addElement(anInstanceName);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsMastersForZone::enumInstanceNames" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersForZoneResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsMastersForZoneManualInstanceEnumeration& aManualInstanceEnumeration) { 

#ifdef DEBUG
     cout << "entering Linux_DnsMastersForZone::enumInstances" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      ZONEOPTS* zopts = findOptsInZone(zones,"masters");

      if (zopts) {
        string mastersName = "zone::";
        mastersName.append(zones->zoneName);
        mastersName.append("::masters");

        Linux_DnsMastersForZoneInstanceName anInstanceName;
        Linux_DnsMastersForZoneManualInstance aManualInstance;

        setInstanceNameProperties(aNameSpaceP, mastersName.c_str(), zones->zoneName, anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);
        aManualInstanceEnumeration.addElement(aManualInstance);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsMastersForZone::enumInstances" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsMastersForZoneManualInstance 
  Linux_DnsMastersForZoneResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsMastersForZoneInstanceName& anInstanceName) {

#ifdef DEBUG
     cout << "entering Linux_DnsMastersForZone::getInstance" << endl;
#endif

    Linux_DnsMastersForZoneManualInstance aManualInstance;

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;
    int found = 0;
    
    zones = findZone(zones, anInstanceName.getGroupComponent().getName()) ; 

    if (zones) {
      ZONEOPTS* zopts = findOptsInZone(zones,"masters");
      if (zopts) {
//        for (; zones->zoneName; zones++) {
          string mastersName = "zone::";
          mastersName.append(zones->zoneName);
          mastersName.append("::masters");

          if (strcmp(mastersName.c_str(), anInstanceName.getPartComponent().getName()) == 0 &&
              strcmp(zones->zoneName, anInstanceName.getGroupComponent().getName()) == 0) {

              setInstanceProperties(anInstanceName, aManualInstance);
              found = 1;
          }
//        }
      }
    }
    if (zonesStart) freeZones( zonesStart );

    if(found == 0)
        throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"The specified instance does not exist!");

#ifdef DEBUG
     cout << "exiting Linux_DnsMastersForZone::getInstance" << endl;
#endif
     return aManualInstance;
  }
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsMastersForZoneResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsMastersForZoneManualInstance& aManualInstance) {

#ifdef DEBUG
     cout << "entering Linux_DnsMastersForZone::setInstance" << endl;
#endif

#ifdef DEBUG
     cout << "exiting Linux_DnsMastersForZone::setInstance" << endl;
#endif
  }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsMastersForZoneInstanceName
  Linux_DnsMastersForZoneResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMastersForZoneManualInstance& aManualInstance) {

#ifdef DEBUG
     cout << "entering Linux_DnsMastersForZone::createInstance" << endl;
#endif

#ifdef DEBUG
     cout << "exiting Linux_DnsMastersForZone::createInstance" << endl;
#endif
  }
  */
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersForZoneResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMastersForZoneInstanceName& anInstanceName) {

#ifdef DEBUG
     cout << "entering Linux_DnsMastersForZone::deleteInstance" << endl;
#endif

    string partName = anInstanceName.getPartComponent().getName();
    string groupName = anInstanceName.getGroupComponent().getName();
    int deleted = 0;

    if (!partName.c_str() || !groupName.c_str())
        throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER, "The submitted instance name is not valid!");

    string parentName = partName.substr(0, partName.find_first_of("::"));
    partName.erase(0,partName.find_first_of("::")+2);

    if (strcmp("zone", parentName.c_str()) == 0) {
        DNSZONE *zones = getZones();
        DNSZONE *zonesStart = zones;
        string zoneName = partName.substr(0, partName.find_first_of("::"));
        string mastersName = partName.substr(partName.find_first_of("::")+2, partName.length());

       if (strcmp(mastersName.c_str(), "masters") != 0)
         throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a masters instance!");

        while(zones && zones->zoneName) {
          if (strcmp(zones->zoneName, groupName.c_str()) == 0) {
            if (findOptsInZone(zones, mastersName.c_str())) {
              delOptsFromZone(zones, mastersName.c_str());
              deleted = 1;
            }
          }
          zones++;
        }
        if(zonesStart)freeZones(zonesStart);

    } else {
      throw CmpiStatus(CMPI_RC_ERR_FAILED,"The specified instance defines a not supported masters attribute!");
    }

    if (deleted == 0) {
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"An instance could not be found for the submitted instance name!");
    }

#ifdef DEBUG
     cout << "exiting Linux_DnsMastersForZone::deleteInstance" << endl;
#endif
  }
	

  // Association Interface
  //----------------------------------------------------------------------------
  void Linux_DnsMastersForZoneResourceAccess::referencesGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsMastersInstanceName& aSourceInstanceName,
    Linux_DnsMastersForZoneManualInstanceEnumeration& aManualInstanceEnumeration) {

#ifdef DEBUG
     cout << "entering Linux_DnsMastersForZone::referencesGroupComponent" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      ZONEOPTS* zopts = findOptsInZone(zones,"masters");

      if (zopts) {
        string mastersName = "zone::";
        mastersName.append(zones->zoneName);
        mastersName.append("::masters");

        if (strcmp(mastersName.c_str(), aSourceInstanceName.getName()) != 0) {
          zones++;
          continue;
        }

        Linux_DnsMastersForZoneInstanceName anInstanceName;
        Linux_DnsMastersForZoneManualInstance aManualInstance;
        setInstanceNameProperties(aNameSpaceP, mastersName.c_str(), zones->zoneName, anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);
        aManualInstanceEnumeration.addElement(aManualInstance);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsMastersForZone::referencesGroupComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsMastersForZoneResourceAccess::referencesPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsZoneInstanceName& aSourceInstanceName,
    Linux_DnsMastersForZoneManualInstanceEnumeration& aManualInstanceEnumeration) {

#ifdef DEBUG
     cout << "entering Linux_DnsMastersForZone::referencesPartComponent" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      if (strcmp(zones->zoneName, aSourceInstanceName.getName()) != 0) {
        zones++;
        continue;
      }

      ZONEOPTS* zopts = findOptsInZone(zones,"masters");

      if (zopts) {
        string mastersName = "zone::";
        mastersName.append(zones->zoneName);
        mastersName.append("::masters");

        Linux_DnsMastersForZoneInstanceName anInstanceName;
        Linux_DnsMastersForZoneManualInstance aManualInstance;
        setInstanceNameProperties(aNameSpaceP, mastersName.c_str(), zones->zoneName, anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);
        aManualInstanceEnumeration.addElement(aManualInstance);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);
#ifdef DEBUG
     cout << "exiting Linux_DnsMastersForZone::referencesPartComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsMastersForZoneResourceAccess::associatorsGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsMastersInstanceName& aSourceInstanceName,
    Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
     cout << "entering Linux_DnsMastersForZone::associatorsGroupComponent" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      ZONEOPTS* zopts = findOptsInZone(zones,"masters");

      if (zopts) {
        Linux_DnsZoneInstanceName anInstanceName;
        Linux_DnsZoneInstance     aManualInstance;

        string mastersName = "zone::";
        mastersName.append(zones->zoneName);
        mastersName.append("::masters");

        if (strcmp(mastersName.c_str(), aSourceInstanceName.getName()) != 0) {
          zones++;
          continue;
        }

        anInstanceName.setNamespace(aNameSpaceP);
        anInstanceName.setName(zones->zoneName);
        anInstanceName.setInstanceID(DEFAULT_INSTANCE_ID);

        aManualInstance.setInstanceName(anInstanceName);
        if (strcmp(zones->zoneType,"master") == 0) aManualInstance.setType(1);
        else if (strcmp(zones->zoneType,"slave") == 0) aManualInstance.setType(2);
        else if (strcmp(zones->zoneType,"stub") == 0) aManualInstance.setType(3);
        else if (strcmp(zones->zoneType,"forward") == 0) aManualInstance.setType(4);
        else if (strcmp(zones->zoneType,"hint") == 0) aManualInstance.setType(5);
        else aManualInstance.setType(0);

        anInstanceEnumeration.addElement(aManualInstance);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsMastersForZone::associatorsGroupComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsMastersForZoneResourceAccess::associatorsPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsZoneInstanceName& aSourceInstanceName,
    Linux_DnsMastersInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
     cout << "entering Linux_DnsMastersForZone::associatorsPartComponent" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      if (strcmp(zones->zoneName, aSourceInstanceName.getName()) != 0) {
        zones++;
        continue;
      }

      ZONEOPTS* zopts = findOptsInZone(zones,"masters");

      if (zopts) {
        Linux_DnsMastersInstanceName anInstanceName;
        Linux_DnsMastersInstance     aManualInstance;

        string mastersName = "zone::";
        mastersName.append(zones->zoneName);
        mastersName.append("::masters");

        anInstanceName.setNamespace(aNameSpaceP);
        anInstanceName.setName(mastersName.c_str());
        anInstanceName.setInstanceID(DEFAULT_INSTANCE_ID);

        aManualInstance.setInstanceName(anInstanceName);

        DnsArray da = DnsArray( zopts->value );
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
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsMastersForZone::associatorsPartComponent" << endl;
#endif
  }
   
  
  // extrinsic methods

	
}

