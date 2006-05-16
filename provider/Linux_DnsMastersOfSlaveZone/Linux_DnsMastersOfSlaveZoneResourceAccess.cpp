// =======================================================================
// Linux_DnsMastersOfSlaveZoneResourceAccess.cpp
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
#include "Linux_DnsMastersOfSlaveZoneResourceAccess.h"

#include <string>
#include <list>

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsMastersOfSlaveZoneResourceAccess::Linux_DnsMastersOfSlaveZoneResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsMastersOfSlaveZoneResourceAccess::~Linux_DnsMastersOfSlaveZoneResourceAccess() { }
    
  // intrinsic methods
  /*
  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersOfSlaveZoneResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& anInstanceNameEnumeration) {
      
    int instanceNameN = 1;
    for (int x=0; x < instanceNameN; ++x) {
      
      //place here the code retrieving your instanceName
      
      Linux_DnsMastersOfSlaveZoneInstanceName instanceName;
      
    }      
  
  }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsMastersOfSlaveZoneResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& aManualInstanceEnumeration) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsMastersOfSlaveZoneManualInstance 
  Linux_DnsMastersOfSlaveZoneResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName) {

    Linux_DnsMastersOfSlaveZoneManualInstance manualInstance;

  
  }
  */
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsMastersOfSlaveZoneResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsMastersOfSlaveZoneManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsMastersOfSlaveZoneInstanceName
  Linux_DnsMastersOfSlaveZoneResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMastersOfSlaveZoneManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsMastersOfSlaveZoneResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName) { }
	*/
	

  // Association Interface
  //----------------------------------------------------------------------------

  void Linux_DnsMastersOfSlaveZoneResourceAccess::referencesSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsSlaveZoneInstanceName& aSourceInstanceName,
    Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsMastersOfSlaveZone::referencesSetting" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *all_zones = zones;
    
    for (;zones && zones->zoneName; zones++) {
      if ( strcmp( zones->zoneName, aSourceInstanceName.getName() ) )
	continue;
      
      ZONEOPTS *zopts = findOptsInZone(zones,"masters");
      
      if (zopts && zopts->key && zopts->value ) {
	DnsArray iplist = DnsArray(zopts->value);
	DnsArrayConstIterator iter; 
	
	for ( iter = iplist.begin(); iter != iplist.end(); ++iter ) {
	  Linux_DnsIPAddressInstanceName ipInstanceName;
	  ipInstanceName.setNamespace(aNameSpaceP);
	  ipInstanceName.setZoneName(zones->zoneName);
	  ipInstanceName.setIPAddress( (*iter).c_str() );
	  
	  Linux_DnsMastersOfSlaveZoneManualInstance manualInstance;
	  Linux_DnsMastersOfSlaveZoneInstanceName instanceName;
	  instanceName.setNamespace( aNameSpaceP );
	  instanceName.setElement( aSourceInstanceName );
	  instanceName.setSetting( ipInstanceName );
	  manualInstance.setInstanceName( instanceName );
	  
	  aManualInstanceEnumeration.addElement( manualInstance );
	}
      }
    }
    freeZones( all_zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsMastersOfSlaveZone::referencesSetting" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsMastersOfSlaveZoneResourceAccess::referencesElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsIPAddressInstanceName& aSourceInstanceName,
    Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& aManualInstanceEnumeration) {
    
    
#ifdef DEBUG
    cout << "entering Linux_DnsMastersOfSlaveZone::referencesElement" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *all_zones = zones;
    
    for (;zones && zones->zoneName; zones++) {
      if ( strcmp( zones->zoneType, "slave") )
	continue;
      
      ZONEOPTS *zopts = findOptsInZone(zones,"masters");
      
      if (zopts && zopts->key && zopts->value ) {
	DnsArray iplist = DnsArray(zopts->value);
	DnsArrayConstIterator iter; 
	
	for ( iter = iplist.begin(); iter != iplist.end(); ++iter ) {
	  if ( strcmp((*iter).c_str(), aSourceInstanceName.getIPAddress() ) != 0 )
	    continue;
	  
	  Linux_DnsSlaveZoneInstanceName zoneInstName;
	  zoneInstName.setName( zones->zoneName );
	  
	  Linux_DnsMastersOfSlaveZoneManualInstance manualInstance;
	  Linux_DnsMastersOfSlaveZoneInstanceName instanceName;
	  instanceName.setNamespace( aNameSpaceP );	
	  instanceName.setElement( zoneInstName );
	  instanceName.setSetting( aSourceInstanceName);
	  manualInstance.setInstanceName( instanceName );
	  
	  aManualInstanceEnumeration.addElement( manualInstance );
	}
      }
    }
    freeZones( all_zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsMastersOfSlaveZone::referencesElement" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsMastersOfSlaveZoneResourceAccess::associatorsSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsSlaveZoneInstanceName& aSourceInstanceName,
    Linux_DnsIPAddressInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsMastersOfSlaveZone::associatorsSetting" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *all_zones = zones;
    
    for (;zones && zones->zoneName;zones++) {
      if ( strcmp( zones->zoneName, aSourceInstanceName.getName() ) != 0)
	continue;
      
      ZONEOPTS *zopts = findOptsInZone(zones,"masters");
      
      if (zopts && zopts->key && zopts->value ) {
	DnsArray iplist = DnsArray(zopts->value);
	DnsArrayConstIterator iter; 
	
	for ( iter = iplist.begin(); iter != iplist.end(); ++iter ) {
	  Linux_DnsIPAddressInstanceName ipInstanceName;
	  ipInstanceName.setNamespace(aNameSpaceP);
	  ipInstanceName.setZoneName(zones->zoneName);
	  ipInstanceName.setIPAddress( (*iter).c_str() );
	  
	  Linux_DnsIPAddressInstance ipInstance;
	  ipInstance.setInstanceName(ipInstanceName);
	  
	  anInstanceEnumeration.addElement( ipInstance );
	}
      }
    }
    freeZones( all_zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsMastersOfSlaveZone::associatorsSetting" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsMastersOfSlaveZoneResourceAccess::associatorsElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsIPAddressInstanceName& aSourceInstanceName,
    Linux_DnsSlaveZoneInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsMastersOfSlaveZone::associatorsElement" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *all_zones = zones;
    
    for (;zones && zones->zoneName; zones++) {
      if ( strcmp( zones->zoneType, "slave" ) )
	continue;
      
      ZONEOPTS *zopts = findOptsInZone(zones,"masters");
      
      if (zopts && zopts->key && zopts->value ) {
	DnsArray iplist = DnsArray(zopts->value);
	DnsArrayConstIterator iter; 
	
	for ( iter = iplist.begin(); iter != iplist.end(); ++iter ) {
	  if ( strcmp((*iter).c_str(), aSourceInstanceName.getIPAddress() ) != 0 )
	    continue;
	  
	  Linux_DnsSlaveZoneInstanceName zoneInstName;
	  zoneInstName.setName( zones->zoneName );
	  
	  Linux_DnsSlaveZoneInstance zoneInst;
	  zoneInst.setInstanceName( zoneInstName );
	  
	  zoneInst.setType(DNS_ZONETYPE_SLAVE);
	  zoneInst.setResourceRecordFile(zones->zoneFileName);
	  
	  anInstanceEnumeration.addElement( zoneInst );
	}
      }
    }
    freeZones( all_zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsMastersOfSlaveZone::associatorsElement" << endl;
#endif
  }

   
  
  // extrinsic methods

	
}


