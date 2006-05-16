// =======================================================================
// Linux_DnsAllowNotifyACLForZoneResourceAccess.cpp
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
#include "Linux_DnsAllowNotifyACLForZoneResourceAccess.h"

#include <string>
#include <list>

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

#define DNS_ATTR_STR	"allow-notify"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsAllowNotifyACLForZoneResourceAccess::Linux_DnsAllowNotifyACLForZoneResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyACLForZoneResourceAccess::~Linux_DnsAllowNotifyACLForZoneResourceAccess() { }
    
  // intrinsic methods

  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowNotifyACLForZoneResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration& anInstanceNameEnumeration) {

#ifdef DEBUG
    cout << "entering Linux_DnsAllowNotifyACLForZone::enumInstanceNames" << endl;
#endif

    DNSZONE * zones, *all_zones;
    
    zones = getZones();
    all_zones = zones;
    
    if ( ! zones) {
#ifdef DEBUG
    cout << "exiting Linux_DnsAllowNotifyACLForZone::enumInstanceNames" << endl;
#endif
      return;
    }
    
    for (; zones->zoneName ; zones++) {
      ZONEOPTS *zopts = findOptsInZone(zones,DNS_ATTR_STR);
      if ( ( ! zopts ) || ( !zopts->value ) ) 
	continue;
      
      DnsArray da = DnsArray( zopts->value );
      DnsArrayConstIterator iter;
      
      for ( iter = da.begin(); iter != da.end(); ++iter) {
	Linux_DnsAllowNotifyACLForZoneInstanceName AuInst;
	Linux_DnsAddressMatchListInstanceName addrList;
	Linux_DnsZoneInstanceName zoneInst;
	
	AuInst.setNamespace( aNameSpaceP );
	zoneInst.setNamespace( aNameSpaceP );	
	addrList.setNamespace( aNameSpaceP );
	
	zoneInst.setName( zones->zoneName );
	
	addrList.setName( (*iter).c_str() );
	addrList.setServiceName( DEFAULT_SERVICE_NAME );
	
	AuInst.setSetting( addrList );
	AuInst.setElement( zoneInst );
	
	anInstanceNameEnumeration.addElement(AuInst); 
      }
    }
    freeZones( all_zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsAllowNotifyACLForZone::enumInstanceNames" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsAllowNotifyACLForZoneResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsAllowNotifyACLForZone::enumInstanceNames" << endl;
#endif

    DNSZONE * zones, *all_zones;
    
    zones = getZones();
    all_zones = zones;
    
    if ( ! zones) {
#ifdef DEBUG
    cout << "exiting Linux_DnsAllowNotifyACLForZone::enumInstanceNames" << endl;
#endif
      return;
    }
    
    for (; zones->zoneName ; zones++) {
      ZONEOPTS *zopts = findOptsInZone(zones,DNS_ATTR_STR);
      if ( ( ! zopts ) || ( !zopts->value ) )
	continue;
      
      DnsArray da = DnsArray( zopts->value );
      DnsArrayConstIterator iter;
      
      for ( iter = da.begin(); iter != da.end(); ++iter) {
	Linux_DnsAllowNotifyACLForZoneInstanceName AuInstName;
	Linux_DnsAllowNotifyACLForZoneManualInstance AuInst;
	Linux_DnsAddressMatchListInstanceName addrList;
	Linux_DnsZoneInstanceName zoneInst;
	
	AuInstName.setNamespace( aNameSpaceP );
	zoneInst.setNamespace( aNameSpaceP );	
	addrList.setNamespace( aNameSpaceP );
	
	zoneInst.setName( zones->zoneName );
	
	addrList.setName( (*iter).c_str() );
	addrList.setServiceName( DEFAULT_SERVICE_NAME );
	
	AuInstName.setSetting( addrList );
	AuInstName.setElement( zoneInst );
	AuInst.setInstanceName( AuInstName );
	
	aManualInstanceEnumeration.addElement(AuInst); 
      }
    }
    freeZones( all_zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsAllowNotifyACLForZone::enumInstanceNames" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  Linux_DnsAllowNotifyACLForZoneManualInstance 
  Linux_DnsAllowNotifyACLForZoneResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsAllowNotifyACLForZoneInstanceName& anInstanceName) {

#ifdef DEBUG
    cout << "entering Linux_DnsAllowNotifyACLForZone::enumInstanceNames" << endl;
#endif

    Linux_DnsAllowNotifyACLForZoneManualInstance AuInst;
    AuInst.setInstanceName( anInstanceName );
    
#ifdef DEBUG
    cout << "exiting Linux_DnsAllowNotifyACLForZone::enumInstanceNames" << endl;
#endif

    return AuInst;
  }

  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsAllowNotifyACLForZoneResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsAllowNotifyACLForZoneManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------

  Linux_DnsAllowNotifyACLForZoneInstanceName
  Linux_DnsAllowNotifyACLForZoneResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAllowNotifyACLForZoneManualInstance& aManualInstance) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsAllowNotifyACLForZone::enumInstanceNames" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zone;
    
    // Find the requested zone. If that does not exist throw an exception
    zone = findZone(zones, aManualInstance.getInstanceName().getElement().getName() );
    if (!zone) {
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
    }
    /* Now zone points to the _desired_ zone */
    ZONEOPTS* zopts = findOptsInZone(zone,DNS_ATTR_STR);
    
    DnsArray iplist;
    // If already exist masters put them in the list.
    if (zopts && zopts->value) {
      iplist.populate(zopts->value);
      iplist.add( string( aManualInstance.getInstanceName().getSetting().getName() ) );
      
      free(zopts->value);
      zopts->value = strdup( iplist.toString().c_str() );
      
      updateZones( zones );
      freeZones( zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsAllowNotifyACLForZone::enumInstanceNames" << endl;
#endif
      return aManualInstance.getInstanceName();
    }
    
    iplist.add( string(aManualInstance.getInstanceName().getSetting().getName()) );
    addOptsToZone(zone, DNS_ATTR_STR,  iplist.toString().c_str());
    updateZones( zones );
    freeZones( zones );
    
#ifdef DEBUG
    cout << "exiting Linux_DnsAllowNotifyACLForZone::enumInstanceNames" << endl;
#endif

    return aManualInstance.getInstanceName();
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsAllowNotifyACLForZoneResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAllowNotifyACLForZoneInstanceName& anInstanceName) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsAllowNotifyACLForZone::deleteInstance" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zone;
    
    // Find the requested zone. If that does not exist throw an exception
    zone = findZone(zones, anInstanceName.getElement().getName() );
    if (!zone) {
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
    }
    /* Now zone points to the _desired_ zone */
    ZONEOPTS* zopts = findOptsInZone(zone,DNS_ATTR_STR);
    
    DnsArray iplist;
    // If already exist masters put them in the list.
    if (zopts && zopts->value) {
      iplist.populate(zopts->value);
      
      iplist.remove( string( anInstanceName.getSetting().getName() ) );
      free(zopts->value);
      zopts->value = strdup( iplist.toString().c_str() );
      
      updateZones( zones );
      freeZones( zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsAllowNotifyACLForZone::deleteInstance" << endl;
#endif
      return;
    }
#ifdef DEBUG
    cout << "exiting Linux_DnsAllowNotifyACLForZone::deleteInstance" << endl;
#endif
  }

	

  // Association Interface
  //----------------------------------------------------------------------------

  void Linux_DnsAllowNotifyACLForZoneResourceAccess::referencesSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsZoneInstanceName& aSourceInstanceName,
    Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsAllowNotifyACLForZone::referencesSetting" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *all_zones = zones;
    
    if ( ! zones)
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
    
    for (; zones->zoneName ; zones++) {
      if ( strcmp( zones->zoneName, aSourceInstanceName.getName() ) != 0 )
	continue;
      
      ZONEOPTS *zopts = findOptsInZone(zones,DNS_ATTR_STR);
      if ( ( ! zopts ) || ( !zopts->value ) )
	continue;
      
      DnsArray da = DnsArray( zopts->value );
      DnsArrayConstIterator iter;
      
      for ( iter = da.begin(); iter != da.end(); ++iter) {
	
	Linux_DnsAllowNotifyACLForZoneManualInstance AuInst;
	Linux_DnsAllowNotifyACLForZoneInstanceName AuInstName;
	
	// AddressMatchList -> Setting
	Linux_DnsAddressMatchListInstance addrList;
	Linux_DnsAddressMatchListInstanceName addrListName;
	addrListName.setNamespace( aNameSpaceP );
	addrListName.setName( (*iter).c_str() );
	addrListName.setServiceName( DEFAULT_SERVICE_NAME );
	/* addrList.setInstanceName( addrListName );
	   char *aclValue = getACL(list_acl, (*iter).c_str());
	   if ( ! aclValue )
	   continue;
	   
	   DnsArray aclArray = DnsArray( aclValue );
	   addrList.setAddressList( aclArray.toArray(), aclArray.size() ); */
	//
	
	// Zone -> Element
	AuInstName.setNamespace( aNameSpaceP );
	AuInstName.setElement( aSourceInstanceName );
	AuInstName.setSetting( addrListName );
	AuInst.setInstanceName( AuInstName );
	
	aManualInstanceEnumeration.addElement( AuInst );
      }
    }
    freeZones( all_zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsAllowNotifyACLForZone::referencesSetting" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsAllowNotifyACLForZoneResourceAccess::referencesElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsAllowNotifyACLForZone::referencesElement" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *all_zones = zones;
    
    if ( ! zones)
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
    
    for (; zones->zoneName ; zones++) {
      ZONEOPTS *zopts = findOptsInZone(zones,DNS_ATTR_STR);
      if ( ( ! zopts ) || ( !zopts->value ) )
	continue;
      
      DnsArray da = DnsArray( zopts->value );
      DnsArrayConstIterator iter;
      
      for ( iter = da.begin(); iter != da.end(); ++iter) {
	if ( strcmp( (*iter).c_str(), aSourceInstanceName.getName() ) != 0 )
	  continue;
	
	Linux_DnsAllowNotifyACLForZoneInstanceName AuInstName;
	Linux_DnsAllowNotifyACLForZoneManualInstance AuInst;
	
	// AddressMatchList -> Setting
	/*Linux_DnsAddressMatchListInstance addrList;
	  addrList.setInstanceName( aSourceInstanceName );
	  char *aclValue = getACL(list_acl, (*iter).c_str());
	  if ( ! aclValue )
	  continue;
	  
	  DnsArray aclArray = DnsArray( aclValue );
	  addrList.setAddressList( aclArray.toArray(), aclArray.size() );*/
	//
	
	// Zone -> Element
	Linux_DnsZoneInstance zoneInst;
	Linux_DnsZoneInstanceName zoneInstName;
	
	zoneInstName.setNamespace( aNameSpaceP );
	zoneInstName.setName( zones->zoneName );
	zoneInst.setInstanceName( zoneInstName );
	
	if ( strcmp(zones->zoneType, "master") == 0 )
	  zoneInst.setType( DNS_ZONETYPE_MASTER );
	else if (  strcmp(zones->zoneType, "slave") == 0 )
	  zoneInst.setType( DNS_ZONETYPE_SLAVE );
	else if (  strcmp(zones->zoneType, "forward") == 0 )
	  zoneInst.setType( DNS_ZONETYPE_FORWARD );
	else if (  strcmp(zones->zoneType, "hint") == 0 )
	  zoneInst.setType( DNS_ZONETYPE_HINT );
	else
	  zoneInst.setType( DNS_ZONETYPE_UNKNOWN );
	
	zoneInst.setResourceRecordFile( zones->zoneFileName );

	AuInstName.setNamespace( aNameSpaceP );
	AuInstName.setElement( zoneInstName );
	AuInstName.setSetting( aSourceInstanceName );
	AuInst.setInstanceName( AuInstName );
	
	aManualInstanceEnumeration.addElement( AuInst );
      }
    }
    freeZones( all_zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsAllowNotifyACLForZone::referencesElement" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsAllowNotifyACLForZoneResourceAccess::associatorsSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsZoneInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration) {
    
          
#ifdef DEBUG
    cout << "entering Linux_DnsAllowNotifyACLForZone::associatorsSetting" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *all_zones = zones;
    ACL *list_acl = ReadACL();
    
    if ( ! zones)
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
    
    for (; zones->zoneName && list_acl ; zones++) {
      if ( strcmp( zones->zoneName, aSourceInstanceName.getName() ) != 0 )
	continue;
      
      ZONEOPTS *zopts = findOptsInZone(zones,DNS_ATTR_STR);
      if ( ( ! zopts ) || ( !zopts->value ) )
	continue;
      
      DnsArray da = DnsArray( zopts->value );
      DnsArrayConstIterator iter;
      
      for ( iter = da.begin(); iter != da.end(); ++iter) {
	
	// AddressMatchList -> Setting
	Linux_DnsAddressMatchListInstance addrList;
	Linux_DnsAddressMatchListInstanceName addrListName;
	addrListName.setNamespace( aNameSpaceP );
	addrListName.setName( (*iter).c_str() );
	addrListName.setServiceName( DEFAULT_SERVICE_NAME );
	addrList.setInstanceName( addrListName );
	
	char *aclValue = getACL(list_acl, (*iter).c_str());
	if ( ! aclValue )
	  continue;
	
	DnsArray aclArray = DnsArray( aclValue );
	addrList.setAddressList( aclArray.toArray(), aclArray.size() );
	addrList.setAddressListType( DNS_AMLTYPE_AML );
	//
	
	anInstanceEnumeration.addElement( addrList );
      }
    }
    freeZones( all_zones );
    freeACL( list_acl );

#ifdef DEBUG
    cout << "exiting Linux_DnsAllowNotifyACLForZone::associatorsSetting" << endl;
#endif
  }
  
  
  //----------------------------------------------------------------------------

  void Linux_DnsAllowNotifyACLForZoneResourceAccess::associatorsElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration) {
    
     
#ifdef DEBUG
    cout << "entering Linux_DnsAllowNotifyACLForZone::associatorsElement" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *all_zones = zones;
    
    if ( ! zones)
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
    
    for (; zones->zoneName ; zones++) {
      ZONEOPTS *zopts = findOptsInZone(zones,DNS_ATTR_STR);
      if ( ( ! zopts ) || ( !zopts->value ) )
	continue;
      
      DnsArray da = DnsArray( zopts->value );
      DnsArrayConstIterator iter;
      
      for ( iter = da.begin(); iter != da.end(); ++iter) {
	if ( strcmp( (*iter).c_str(), aSourceInstanceName.getName() ) != 0 )
	  continue;
	
	// Zone -> Element
	Linux_DnsZoneInstance zoneInst;
	Linux_DnsZoneInstanceName zoneInstName;
	
	zoneInstName.setNamespace( aNameSpaceP );
	zoneInstName.setName( zones->zoneName );
	zoneInst.setInstanceName( zoneInstName );
	
	if ( strcmp(zones->zoneType, "master") == 0 )
	  zoneInst.setType( DNS_ZONETYPE_MASTER );
	else if (  strcmp(zones->zoneType, "slave") == 0 )
	  zoneInst.setType( DNS_ZONETYPE_SLAVE );
	else if (  strcmp(zones->zoneType, "forward") == 0 )
	  zoneInst.setType( DNS_ZONETYPE_FORWARD );
	else if (  strcmp(zones->zoneType, "hint") == 0 )
	  zoneInst.setType( DNS_ZONETYPE_HINT );
	else
	  zoneInst.setType( DNS_ZONETYPE_UNKNOWN );
	
	zoneInst.setResourceRecordFile( zones->zoneFileName );
	//
	
	anInstanceEnumeration.addElement( zoneInst );
      }
    }
    freeZones( all_zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsAllowNotifyACLForZone::associatorsElement" << endl;
#endif
  }

   
  
  // extrinsic methods

	
}


