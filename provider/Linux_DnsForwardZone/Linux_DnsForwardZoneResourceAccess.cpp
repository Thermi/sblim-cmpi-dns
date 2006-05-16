// =======================================================================
// Linux_DnsForwardZoneResourceAccess.cpp
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
#include "Linux_DnsForwardZoneResourceAccess.h"

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
      Linux_DnsForwardZoneInstanceName& anInstanceName) {

    anInstanceName.setNamespace(aNameSpaceP);
    anInstanceName.setName(zone->zoneName);
  }
  

  //----------------------------------------------------------------------------


  static void setInstanceProperties(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      DNSZONE * zone,
      const Linux_DnsForwardZoneInstanceName& anInstanceName,
      Linux_DnsForwardZoneManualInstance& aManualInstance) {

    aManualInstance.setInstanceName(anInstanceName);
    aManualInstance.setType(DNS_ZONETYPE_FORWARD);
    //	aManualInstance.setResourceRecordFile(zone->zoneFileName);   
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
    
  }  
  

  //----------------------------------------------------------------------------


  //----------------------------------------------------------------------------
  //Linux_DnsForwardZoneResourceAccess::Linux_DnsForwardZoneResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneResourceAccess::~Linux_DnsForwardZoneResourceAccess() { }
    
  // intrinsic methods

  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardZoneResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsForwardZoneInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
    cout << "entering Linux_DnsForwardZone::enumInstanceNames" << endl;
#endif

    DNSZONE * zones, *all_zones;
    
    zones = getZones();	//getZonesByType("forward");
    all_zones = zones;
    
    if (zones) {
      for (; zones->zoneName; zones++) {
	if ( strcmp(zones->zoneType, "forward") )
	  continue;
	
	Linux_DnsForwardZoneInstanceName instanceName;
	setInstanceNameProperties(aContext, aBroker, aNameSpaceP, zones, instanceName);
	anInstanceNameEnumeration.addElement(instanceName);
	
      }
      freeZones( all_zones );
    }
#ifdef DEBUG
    cout << "exiting Linux_DnsForwardZone::enumInstanceNames" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsForwardZoneResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsForwardZoneManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsForwardZone::enumInstances" << endl;
#endif

    DNSZONE * zones = NULL, *all_zones;
    
    zones = getZones(); 	//getZonesByType("forward");
    all_zones = zones;
    
    if (zones) {
      for (; zones->zoneName != NULL ; zones++) {   
	if ( strcmp(zones->zoneType, "forward") )
	  continue;
	
	Linux_DnsForwardZoneManualInstance instance;
	Linux_DnsForwardZoneInstanceName instanceName;
	
	setInstanceNameProperties(aContext, aBroker, aNameSpaceP, zones, instanceName);
	setInstanceProperties(aContext, aBroker, zones, instanceName, instance);
	aManualInstanceEnumeration.addElement(instance);
        
      }
      freeZones( all_zones );
    }

#ifdef DEBUG
    cout << "exiting Linux_DnsForwardZone::enumInstances" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  Linux_DnsForwardZoneManualInstance 
  Linux_DnsForwardZoneResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsForwardZoneInstanceName& anInstanceName) {

    
#ifdef DEBUG
    cout << "entering Linux_DnsForwardZone::getInstance" << endl;
#endif

    DNSZONE *zones, *myZone;
    
    Linux_DnsForwardZoneManualInstance instance;
    
    zones = getZones();	//getZonesByType("forward");
    myZone = findZone(zones,anInstanceName.getName());
    
    setInstanceProperties(aContext, aBroker, myZone, anInstanceName, instance);
    freeZones( zones );
    
#ifdef DEBUG
    cout << "exiting Linux_DnsForwardZone::getInstance" << endl;
#endif
    return instance;
  }

  //----------------------------------------------------------------------------

  void
  Linux_DnsForwardZoneResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsForwardZoneManualInstance& aManualInstance) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsForwardZone::setInstance" << endl;
#endif
    DNSZONE *zones, *myZone;
    
    zones = getZones();
    myZone = findZone(zones, aManualInstance.getInstanceName().getName());
    
    if ( ! myZone )
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");
    
    if ( strcmp(myZone->zoneType,"forward") != 0 )
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");
    
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
    
    // option 'file' is not allowed in 'forward' zone
    if ( aManualInstance.isResourceRecordFileSet() ) {
      free(myZone->zoneFileName);
      myZone->zoneFileName = strdup(aManualInstance.getResourceRecordFile());
    } 
    updateZones( zones );
    freeZones( zones );
      
#ifdef DEBUG
    cout << "exiting Linux_DnsForwardZone::setInstance" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  Linux_DnsForwardZoneInstanceName
  Linux_DnsForwardZoneResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsForwardZoneManualInstance& aManualInstance) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsForwardZone::createInstance" << endl;
#endif
    
    DNSZONE * newZone = NULL;
    Linux_DnsForwardZoneInstanceName anInstanceName = aManualInstance.getInstanceName();
    
    if (((anInstanceName.getName()) == NULL) || ((anInstanceName.getName()) == "" ) || ((anInstanceName.getName()) =="") ) {
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
      newZone->zoneName = (char *)anInstanceName.getName();
      
      newZone->zoneType = "forward";
      
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
      
      //option 'file' is not allowed in 'forward' zone
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
      
      newZone->records = NULL;
      
      DNSZONE * returnedZones = NULL;
      
      returnedZones = addZone(newZone, NULL);
      if (!returnedZones) {
	throw CmpiStatus(CMPI_RC_ERROR,"addZone() failed");
      }
      freeZones( returnedZones );
    }

#ifdef DEBUG
    cout << "exiting Linux_DnsForwardZone::createInstance" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsForwardZoneResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsForwardZoneInstanceName& anInstanceName) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsForwardZone::deleteInstance" << endl;
#endif

    deleteZone( anInstanceName.getName() );

#ifdef DEBUG
    cout << "exiting Linux_DnsForwardZone::deleteInstance" << endl;
#endif
  }

	

  
  // extrinsic methods

  /*
  CMPIUint32 Linux_DnsForwardZoneResourceAccess::ApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsForwardZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsForwardZoneResourceAccess::ApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsForwardZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsForwardZoneResourceAccess::ApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsForwardZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsForwardZoneResourceAccess::ApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsForwardZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) { }
  */

  /*
  CMPIUint32 Linux_DnsForwardZoneResourceAccess::VerifyOKToApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsForwardZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsForwardZoneResourceAccess::VerifyOKToApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsForwardZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsForwardZoneResourceAccess::VerifyOKToApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsForwardZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsForwardZoneResourceAccess::VerifyOKToApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsForwardZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) { }
  */

	
}


