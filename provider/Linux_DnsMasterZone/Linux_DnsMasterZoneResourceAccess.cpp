// =======================================================================
// Linux_DnsMasterZoneResourceAccess.cpp
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
#include "Linux_DnsMasterZoneResourceAccess.h"

#include <string>
#include <list>
#include <iostream>

using namespace std;

#include "smt_dns_ra_support.h"
#include "smt_dns_valuemap.h"
#include "smt_dns_array.h"

namespace genProvider {
  
  
  //----------------------------------------------------------------------------
  // manual written methods
  
  static void setInstanceNameProperties(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      DNSZONE * zone,
      Linux_DnsMasterZoneInstanceName& anInstanceName) {
    
    anInstanceName.setNamespace(aNameSpaceP);
    anInstanceName.setName(zone->zoneName);
  }


  //----------------------------------------------------------------------------


  static void setInstanceProperties(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      DNSZONE * zone,
      const Linux_DnsMasterZoneInstanceName& anInstanceName,
      Linux_DnsMasterZoneManualInstance& aManualInstance) {

    //ZONEOPTS* zoneOpts;
    ZONEOPTS * forward = findOptsInZone( zone, "forward" );
    if ( forward ) {
      if ( strcmp( forward->value, "first" ) )
	aManualInstance.setForward( DNS_FORWARD_FIRST );
      
      if ( strcmp( forward->value, "only" ) )
	aManualInstance.setForward( DNS_FORWARD_ONLY );
    }	
    
    ZONEOPTS * forwarders = findOptsInZone( zone, "forwarders" );
    DnsArray da;
    
    if ( forwarders && forwarders->value ) {
      da.populate( forwarders->value ); 
      aManualInstance.setForwarders( da.toArray(), da.size() );
    }
    aManualInstance.setInstanceName(anInstanceName);
    
    aManualInstance.setType(DNS_ZONETYPE_MASTER);
    
    aManualInstance.setResourceRecordFile(zone->zoneFileName);
    
    aManualInstance.setContact(zone->soaContact);
    
    char *val = (char *) malloc( 12*sizeof(char) );
    sprintf(val,"%lld", zone->soaSerialNumber );
    aManualInstance.setSerialNumber( val );
    free(val);
    
    aManualInstance.setRefresh( zone->soaRefresh );
    aManualInstance.setRetry( zone->soaRetry );
    aManualInstance.setExpire( zone->soaExpire );
    aManualInstance.setServer( zone->soaServer );
    aManualInstance.setNegativeCachingTTL( zone->soaNegativCachingTTL );
  }
  
  
  //----------------------------------------------------------------------------
  
  
  //----------------------------------------------------------------------------
  //Linux_DnsMasterZoneResourceAccess::Linux_DnsMasterZoneResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsMasterZoneResourceAccess::~Linux_DnsMasterZoneResourceAccess() { }
    
  // intrinsic methods

  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsMasterZoneInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
    cout << "entering Linux_DnsMasterZone::enumInstanceNames" << endl;
#endif

    DNSZONE * zones, *all_zones;
    
    zones = getZones(); //getZonesByType("master");
    all_zones = zones;
    
    if (zones) {
      for (; zones->zoneName != NULL ; zones++) {  
	if ( strcmp(zones->zoneType, "master") )
	  continue;
	
	//Linux_DnsZoneManualInstance instance;
	Linux_DnsMasterZoneInstanceName instanceName;
	
	setInstanceNameProperties(aContext, aBroker, aNameSpaceP, zones, instanceName);
	anInstanceNameEnumeration.addElement(instanceName);
      }
      freeZones( all_zones );
    }
#ifdef DEBUG
    cout << "exiting Linux_DnsMasterZone::enumInstanceNames" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsMasterZoneResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsMasterZoneManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsMasterZone::enumInstances" << endl;
#endif
    
    DNSZONE * zones = NULL, *all_zones;
    
    zones = getZones(); 	//getZonesByType("master");
    all_zones = zones;
    
    if (zones) {
      for (; zones->zoneName != NULL ; zones++) {
	if ( strcmp(zones->zoneType, "master") )
	  continue;
	
	Linux_DnsMasterZoneManualInstance instance;
	Linux_DnsMasterZoneInstanceName instanceName;
	
	setInstanceNameProperties(aContext, aBroker, aNameSpaceP, zones, instanceName);
	setInstanceProperties(aContext, aBroker, zones, instanceName, instance);
	aManualInstanceEnumeration.addElement(instance);
      }
      freeZones( all_zones );
    }
#ifdef DEBUG
    cout << "exiting Linux_DnsMasterZone::enumInstances" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  Linux_DnsMasterZoneManualInstance 
  Linux_DnsMasterZoneResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsMasterZoneInstanceName& anInstanceName) {

#ifdef DEBUG
    cout << "entering Linux_DnsMasterZone::getInstance" << endl;
#endif

    DNSZONE *zones, *myZone;
    
    Linux_DnsMasterZoneManualInstance instance;
    
    zones = getZones();
    myZone = findZone(zones,anInstanceName.getName());
    
    if ( ! myZone )
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");	
    
    setInstanceProperties(aContext, aBroker, myZone, anInstanceName, instance);
    
    freeZones( zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsMasterZone::getInstance" << endl;
#endif
    return instance;
  }

  //----------------------------------------------------------------------------

  void
  Linux_DnsMasterZoneResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsMasterZoneManualInstance& aManualInstance) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsMasterZone::setInstance" << endl;
#endif

    DNSZONE *zones, *myZone;
    
    zones = getZones();
    myZone = findZone(zones, aManualInstance.getInstanceName().getName());
    
    if ( ! myZone )
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");
    
    if ( strcmp(myZone->zoneType,"master") != 0 )
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");
    
    if ( aManualInstance.isResourceRecordFileSet() ) {
      free(myZone->zoneFileName);
      myZone->zoneFileName = strdup(aManualInstance.getResourceRecordFile());
    }
    
    if (aManualInstance.isContactSet()) {
      free(myZone->soaContact);
      myZone->soaContact = strdup( aManualInstance.getContact() );
    }
    
    if ( aManualInstance.isForwardSet() ) {
      ZONEOPTS *zopts = findOptsInZone( myZone, "forward" );
      
      if ( zopts ) {
	free( zopts->value );
	if ( aManualInstance.getForward() == DNS_FORWARD_ONLY )
	  zopts->value = strdup( "only" );
	
	if ( aManualInstance.getForward() == DNS_FORWARD_FIRST )
	  zopts->value = strdup( "first" );
	
      } else {
	if ( aManualInstance.getForward() == DNS_FORWARD_ONLY )
	  addOptsToZone( myZone, "forward", "only" );
	
	if ( aManualInstance.getForward() == DNS_FORWARD_FIRST )
	  addOptsToZone( myZone, "forward", "first" );
      }
    }
    
    unsigned int size = 0;
    if ( aManualInstance.isForwardersSet() ) {
      ZONEOPTS *zopts = findOptsInZone( myZone, "forwarders" );
      
      const char **forwardersList = aManualInstance.getForwarders( size );
      DnsArray value_list;
      
      for (unsigned int i = 0; i < size; i++)
	if (! value_list.isPresent( string( forwardersList[i]) ) )
	  value_list.add( forwardersList[i] );
      
      if ( zopts ) {
	free( zopts->value );
	zopts->value = strdup ( value_list.toString().c_str() );
	
      } else
	addOptsToZone( myZone,"forwarders", strdup( value_list.toString().c_str() ) );
    }
    
    // SerialNumber
    if (aManualInstance.isSerialNumberSet())
      myZone->soaSerialNumber = atoi(aManualInstance.getSerialNumber());
    
    // Refresh
    if (aManualInstance.isRefreshSet())
      myZone->soaRefresh = aManualInstance.getRefresh();
    
    // Retry	
    if (aManualInstance.isRetrySet())
      myZone->soaRetry = aManualInstance.getRetry();
    
    // Expire
    if (aManualInstance.isExpireSet())
      myZone->soaExpire = aManualInstance.getExpire();
    
    // NegativeCachingTTL
    if (aManualInstance.isNegativeCachingTTLSet())
      myZone->soaNegativCachingTTL = aManualInstance.getNegativeCachingTTL();
    
    if (aManualInstance.isServerSet())
      myZone->soaServer = strdup( aManualInstance.getServer() );
    
    updateZones(zones);
    freeZones( zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsMasterZone::setInstance" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  Linux_DnsMasterZoneInstanceName
  Linux_DnsMasterZoneResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMasterZoneManualInstance& aManualInstance) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsMasterZone::createInstance" << endl;
#endif

    DNSZONE * newZone = NULL;
    Linux_DnsMasterZoneInstanceName anInstanceName = aManualInstance.getInstanceName();
    
    if (((anInstanceName.getName()) == NULL) || ((anInstanceName.getName()) == "" ) || ((anInstanceName.getName()) == " " ) ) {
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"Zonename is invalid");
    }
    
    DNSZONE * all_zones = getZones();
    if ( findZone(all_zones,anInstanceName.getName()) ) {
      freeZones(all_zones);
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The zone already exist");
    }
    freeZones(all_zones);
    
    newZone = (DNSZONE *)calloc(1+1,sizeof(DNSZONE));
    
    if (newZone) {
      // Take in value specified only at Dialog ??//
      
      newZone->zoneName = (char *)anInstanceName.getName();
      
      newZone->zoneType = "master";
      
      if (aManualInstance.isResourceRecordFileSet()) {
	newZone->zoneFileName = strdup(aManualInstance.getResourceRecordFile());
	
      } else {
	char * buffer;
	buffer = (char *)calloc((strlen(newZone->zoneType)+strlen(newZone->zoneName)+2),sizeof(char));
	strcat(buffer, newZone->zoneType);
	strcat(buffer, "/");
	strcat(buffer, newZone->zoneName);
	newZone->zoneFileName = buffer;
      }
      
      
      // Contact  
      if (aManualInstance.isContactSet())
	newZone->soaContact = (char *)aManualInstance.getContact();
      else
	newZone->soaContact = "root";
      
      // if not at dialog then use following default required values (smt_dns_ra_support.h) for a Zone 
      // may need to get them from default section in Service 
      
      // SerialNumber
      if (aManualInstance.isSerialNumberSet())
	newZone->soaSerialNumber = atoi(aManualInstance.getSerialNumber());
      else
	newZone->soaSerialNumber = 2005040000;
      
      // Refresh
      if (aManualInstance.isRefreshSet())
	newZone->soaRefresh = aManualInstance.getRefresh();
      else
	newZone->soaRefresh = 60*60;
      
      // Retry	
      if (aManualInstance.isRetrySet())
	newZone->soaRetry = aManualInstance.getRetry();
      else
	newZone->soaRetry = 3*60*60;
      
      // Expire
      if (aManualInstance.isExpireSet())
	newZone->soaExpire = aManualInstance.getExpire();
      else
	newZone->soaExpire = 2*60*60;
      
      if ( aManualInstance.isForwardSet() ) {
	if ( aManualInstance.getForward() == DNS_FORWARD_ONLY )
	  addOptsToZone( newZone, "forward", "only" );
	
	if ( aManualInstance.getForward() == DNS_FORWARD_FIRST )
	  addOptsToZone( newZone, "forward", "first" );
      }
      
      unsigned int size = 0;
      if ( aManualInstance.isForwardersSet() ) {
	const char **forwardersList = aManualInstance.getForwarders( size );
	DnsArray value_list;
	for (unsigned int i = 0; i < size; i++)
	  if (! value_list.isPresent( string( forwardersList[i]) ) )
	    value_list.add( forwardersList[i] );
	
	addOptsToZone( newZone,"forwarders", strdup( value_list.toString().c_str() ) );
      }
      
      // NegativeCachingTTL
      if (aManualInstance.isNegativeCachingTTLSet())
	newZone->soaNegativCachingTTL = aManualInstance.getNegativeCachingTTL();
      else
	newZone->soaNegativCachingTTL = 0;
      
      if (aManualInstance.isServerSet())
	newZone->soaServer = strdup( aManualInstance.getServer() );
      else
	newZone->soaServer = "@";

      newZone->records = NULL;
      
      DNSZONE * returnedZones = NULL;
      
      returnedZones = addZone(newZone, NULL);
      if (!returnedZones) {
	throw CmpiStatus(CMPI_RC_ERROR,"addZone() failed");
      }
      freeZones( returnedZones );
    }
    
#ifdef DEBUG
    cout << "exiting Linux_DnsMasterZone::createInstance" << endl;
#endif
    return aManualInstance.getInstanceName();
  }
    
  
  //----------------------------------------------------------------------------

  void
  Linux_DnsMasterZoneResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMasterZoneInstanceName& anInstanceName) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsMasterZone::deleteInstance" << endl;
#endif

    deleteZone( anInstanceName.getName() );

#ifdef DEBUG
    cout << "exiting Linux_DnsMasterZone::deleteInstance" << endl;
#endif
  }

	

  
  // extrinsic methods

  /*
  CMPIUint32 Linux_DnsMasterZoneResourceAccess::ApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMasterZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsMasterZoneResourceAccess::ApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMasterZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsMasterZoneResourceAccess::ApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMasterZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsMasterZoneResourceAccess::ApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMasterZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) { }
  */

  /*
  CMPIUint32 Linux_DnsMasterZoneResourceAccess::VerifyOKToApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMasterZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsMasterZoneResourceAccess::VerifyOKToApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMasterZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsMasterZoneResourceAccess::VerifyOKToApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMasterZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsMasterZoneResourceAccess::VerifyOKToApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsMasterZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) { }
  */

	
}


