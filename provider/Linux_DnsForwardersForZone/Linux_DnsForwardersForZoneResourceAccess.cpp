// =======================================================================
// Linux_DnsForwardersForZoneResourceAccess.cpp
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
#include "Linux_DnsForwardersForZoneResourceAccess.h"
#include <string>
#include <list>

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

namespace genProvider {
  
  static void setInstanceNameProperties(
      const char *aNameSpaceP,
      const char *forwardersName,
      const char *zoneName,
      Linux_DnsForwardersForZoneInstanceName& anInstanceName) {

      Linux_DnsForwardersInstanceName  partComponent;
      Linux_DnsZoneInstanceName     groupComponent;

      //ACL
      partComponent.setNamespace(aNameSpaceP);
      partComponent.setName(forwardersName);
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
      const Linux_DnsForwardersForZoneInstanceName anInstanceName,
      Linux_DnsForwardersForZoneManualInstance& aManualInstance) {

      aManualInstance.setInstanceName(anInstanceName);
  }

  //----------------------------------------------------------------------------
  //Linux_DnsForwardersForZoneResourceAccess::Linux_DnsForwardersForZoneResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsForwardersForZoneResourceAccess::~Linux_DnsForwardersForZoneResourceAccess() { }
    
  // intrinsic methods
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersForZoneResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsForwardersForZoneInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
     cout << "entering Linux_DnsForwardersForZone::enumInstanceNames" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      ZONEOPTS* zopts = findOptsInZone(zones,"forwarders");
      cout << "Adding a forwarders ä1" << endl;

      if (zopts) {
        cout << "Adding a forwarders " << endl;
        string forwardersName = "zone::";
        forwardersName.append(zones->zoneName);
        forwardersName.append("::forwarders");

        Linux_DnsForwardersForZoneInstanceName anInstanceName;
        setInstanceNameProperties(aNameSpaceP, forwardersName.c_str(), zones->zoneName, anInstanceName);
        anInstanceNameEnumeration.addElement(anInstanceName);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsForwardersForZone::enumInstanceNames" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersForZoneResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsForwardersForZoneManualInstanceEnumeration& aManualInstanceEnumeration) { 

#ifdef DEBUG
     cout << "entering Linux_DnsForwardersForZone::enumInstances" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      ZONEOPTS* zopts = findOptsInZone(zones,"forwarders");

      if (zopts) {
        string forwardersName = "zone::";
        forwardersName.append(zones->zoneName);
        forwardersName.append("::forwarders");

        Linux_DnsForwardersForZoneInstanceName anInstanceName;
        Linux_DnsForwardersForZoneManualInstance aManualInstance;

        setInstanceNameProperties(aNameSpaceP, forwardersName.c_str(), zones->zoneName, anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);
        aManualInstanceEnumeration.addElement(aManualInstance);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsForwardersForZone::enumInstances" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsForwardersForZoneManualInstance 
  Linux_DnsForwardersForZoneResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsForwardersForZoneInstanceName& anInstanceName) {

#ifdef DEBUG
     cout << "entering Linux_DnsForwardersForZone::getInstance" << endl;
#endif

    Linux_DnsForwardersForZoneManualInstance aManualInstance;

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;
    int found = 0;

    zones = findZone(zones,anInstanceName.getGroupComponent().getName()); 

    if (zones) {
      ZONEOPTS* zopts = findOptsInZone(zones,"forwarders");
      if (zopts) {
//      for (; zones->zoneName; zones++) {
          string forwardersName = "zone::";
          forwardersName.append(zones->zoneName);
          forwardersName.append("::forwarders");

          if (strcmp(forwardersName.c_str(), anInstanceName.getPartComponent().getName()) == 0 &&
              strcmp(zones->zoneName, anInstanceName.getGroupComponent().getName()) == 0) {

              setInstanceProperties(anInstanceName, aManualInstance);
              found = 1;
          }
//      }
      }
    }
    if (zonesStart) freeZones( zonesStart );

    if(found == 0)
        throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"The specified instance does not exist!");

#ifdef DEBUG
     cout << "exiting Linux_DnsForwardersForZone::getInstance" << endl;
#endif
     return aManualInstance;
  }
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsForwardersForZoneResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsForwardersForZoneManualInstance& aManualInstance) {

#ifdef DEBUG
     cout << "entering Linux_DnsForwardersForZone::setInstance" << endl;
#endif

#ifdef DEBUG
     cout << "exiting Linux_DnsForwardersForZone::setInstance" << endl;
#endif
  }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsForwardersForZoneInstanceName
  Linux_DnsForwardersForZoneResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsForwardersForZoneManualInstance& aManualInstance) {

#ifdef DEBUG
     cout << "entering Linux_DnsForwardersForZone::createInstance" << endl;
#endif

#ifdef DEBUG
     cout << "exiting Linux_DnsForwardersForZone::createInstance" << endl;
#endif
  }
  */
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersForZoneResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsForwardersForZoneInstanceName& anInstanceName) {

#ifdef DEBUG
     cout << "entering Linux_DnsForwardersForZone::deleteInstance" << endl;
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
        string forwardersName = partName.substr(partName.find_first_of("::")+2, partName.length());

       if (strcmp(forwardersName.c_str(), "forwarders") != 0)
         throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a forwarders instance!");

        while(zones && zones->zoneName) {
          if (strcmp(zones->zoneName, groupName.c_str()) == 0) {
            if (findOptsInZone(zones, forwardersName.c_str())) {
              delOptsFromZone(zones, forwardersName.c_str());
              deleted = 1;
            }
          }
          zones++;
        }
        if(zonesStart)freeZones(zonesStart);

    } else {
      throw CmpiStatus(CMPI_RC_ERR_FAILED,"The specified instance defines a not supported forwarders attribute!");
    }

    if (deleted == 0) {
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"An instance could not be found for the submitted instance name!");
    }

#ifdef DEBUG
     cout << "exiting Linux_DnsForwardersForZone::deleteInstance" << endl;
#endif
  }
	

  // Association Interface
  //----------------------------------------------------------------------------
  void Linux_DnsForwardersForZoneResourceAccess::referencesGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsForwardersInstanceName& aSourceInstanceName,
    Linux_DnsForwardersForZoneManualInstanceEnumeration& aManualInstanceEnumeration) {

#ifdef DEBUG
     cout << "entering Linux_DnsForwardersForZone::referencesGroupComponent" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      ZONEOPTS* zopts = findOptsInZone(zones,"forwarders");

      if (zopts) {
        string forwardersName = "zone::";
        forwardersName.append(zones->zoneName);
        forwardersName.append("::forwarders");

        if (strcmp(forwardersName.c_str(), aSourceInstanceName.getName()) != 0) {
          zones++;
          continue;
        }

        Linux_DnsForwardersForZoneInstanceName anInstanceName;
        Linux_DnsForwardersForZoneManualInstance aManualInstance;
        setInstanceNameProperties(aNameSpaceP, forwardersName.c_str(), zones->zoneName, anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);
        aManualInstanceEnumeration.addElement(aManualInstance);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsForwardersForZone::referencesGroupComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsForwardersForZoneResourceAccess::referencesPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsZoneInstanceName& aSourceInstanceName,
    Linux_DnsForwardersForZoneManualInstanceEnumeration& aManualInstanceEnumeration) {

#ifdef DEBUG
     cout << "entering Linux_DnsForwardersForZone::referencesPartComponent" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      if (strcmp(zones->zoneName, aSourceInstanceName.getName()) != 0) {
        zones++;
        continue;
      }

      ZONEOPTS* zopts = findOptsInZone(zones,"forwarders");

      if (zopts) {
        string forwardersName = "zone::";
        forwardersName.append(zones->zoneName);
        forwardersName.append("::forwarders");

        Linux_DnsForwardersForZoneInstanceName anInstanceName;
        Linux_DnsForwardersForZoneManualInstance aManualInstance;
        setInstanceNameProperties(aNameSpaceP, forwardersName.c_str(), zones->zoneName, anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);
        aManualInstanceEnumeration.addElement(aManualInstance);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);
#ifdef DEBUG
     cout << "exiting Linux_DnsForwardersForZone::referencesPartComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsForwardersForZoneResourceAccess::associatorsGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsForwardersInstanceName& aSourceInstanceName,
    Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
     cout << "entering Linux_DnsForwardersForZone::associatorsGroupComponent" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      ZONEOPTS* zopts = findOptsInZone(zones,"forwarders");

      if (zopts) {
        Linux_DnsZoneInstanceName anInstanceName;
        Linux_DnsZoneInstance     aManualInstance;

        string forwardersName = "zone::";
        forwardersName.append(zones->zoneName);
        forwardersName.append("::forwarders");

        if (strcmp(forwardersName.c_str(), aSourceInstanceName.getName()) != 0) {
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
     cout << "exiting Linux_DnsForwardersForZone::associatorsGroupComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsForwardersForZoneResourceAccess::associatorsPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsZoneInstanceName& aSourceInstanceName,
    Linux_DnsForwardersInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
     cout << "entering Linux_DnsForwardersForZone::associatorsPartComponent" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      if (strcmp(zones->zoneName, aSourceInstanceName.getName()) != 0) {
        zones++;
        continue;
      }

      ZONEOPTS* zopts = findOptsInZone(zones,"forwarders");

      if (zopts) {
        Linux_DnsForwardersInstanceName anInstanceName;
        Linux_DnsForwardersInstance     aManualInstance;

        string forwardersName = "zone::";
        forwardersName.append(zones->zoneName);
        forwardersName.append("::forwarders");

        anInstanceName.setNamespace(aNameSpaceP);
        anInstanceName.setName(forwardersName.c_str());
        anInstanceName.setInstanceID(DEFAULT_INSTANCE_ID);

        aManualInstance.setInstanceName(anInstanceName);

        DnsArray da = DnsArray( zopts->value );
        aManualInstance.setForwardersElement( da.toArray(), da.size() );

        CMPIUint8* forwardersType = new CMPIUint8[da.size()];
        DnsArrayConstIterator iter;
        int i = 0;

        for ( iter = da.begin(); iter != da.end(); ++iter) {
            forwardersType[i++] = getForwardersType((*iter).c_str());
        }
        aManualInstance.setForwardersElementType (forwardersType, da.size() );
        anInstanceEnumeration.addElement(aManualInstance);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsForwardersForZone::associatorsPartComponent" << endl;
#endif
  }
   
  
  // extrinsic methods

	
}

