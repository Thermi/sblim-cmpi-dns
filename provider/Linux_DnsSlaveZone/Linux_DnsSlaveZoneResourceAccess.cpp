// =======================================================================
// Linux_DnsSlaveZoneResourceAccess.cpp
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
#include "Linux_DnsSlaveZoneResourceAccess.h"

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
      Linux_DnsSlaveZoneInstanceName& anInstanceName) {

    anInstanceName.setNamespace(aNameSpaceP);
    anInstanceName.setName(zone->zoneName);
  }


  //----------------------------------------------------------------------------


  static void setInstanceProperties(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      DNSZONE * zone,
      const Linux_DnsSlaveZoneInstanceName& anInstanceName,
      Linux_DnsSlaveZoneManualInstance& aManualInstance) {
    
    ZONEOPTS* zoneOpts;
    
    aManualInstance.setInstanceName(anInstanceName);
    
    aManualInstance.setType(DNS_ZONETYPE_SLAVE);
    aManualInstance.setResourceRecordFile(zone->zoneFileName);
    
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
    
    /* if ( ( zoneOpts = findOptsInZone(zone,"resquest-ixfr")) )
       {
       if (strcmp(zoneOpts->value,"no") == 0)
       aManualInstance.setXferFormat(DNS_XFER_COMPLETE);
       else
       aManualInstance.setXferFormat(DNS_XFER_INCREMENTAL);
       } */
  }

  
  //----------------------------------------------------------------------------


  //----------------------------------------------------------------------------
  //Linux_DnsSlaveZoneResourceAccess::Linux_DnsSlaveZoneResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsSlaveZoneResourceAccess::~Linux_DnsSlaveZoneResourceAccess() { }
    
  // intrinsic methods

  //----------------------------------------------------------------------------
  void
  Linux_DnsSlaveZoneResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsSlaveZoneInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
    cout << "entering Linux_DnsSlaveZone::enumInstanceNames" << endl;
#endif

    DNSZONE * zones, *all_zones;
    
    zones = getZones();	//getZonesByType("slave");
    all_zones = zones;
    
    if (zones) {
      for (; zones->zoneName ; zones++) {	    
	if ( strcmp(zones->zoneType, "slave") )
	  continue;
	
	Linux_DnsSlaveZoneInstanceName instanceName;
	
	setInstanceNameProperties(aContext, aBroker, aNameSpaceP, zones, instanceName);
	anInstanceNameEnumeration.addElement(instanceName);
      }
    }
    freeZones( all_zones ); 

#ifdef DEBUG
    cout << "exiting Linux_DnsSlaveZone::enumInstanceNames" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsSlaveZoneResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsSlaveZoneManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsSlaveZone::enumInstances" << endl;
#endif
    DNSZONE * zones = NULL, *all_zones;
    
    zones = getZones();	//getZonesByType("slave");
    all_zones = zones;
    
    if (zones) {
      for (; zones->zoneName; zones++) {   
	if ( strcmp(zones->zoneType, "slave") )
	  continue;
	
	Linux_DnsSlaveZoneManualInstance instance;
	Linux_DnsSlaveZoneInstanceName instanceName;
	
	setInstanceNameProperties(aContext, aBroker, aNameSpaceP, zones, instanceName);
	setInstanceProperties(aContext, aBroker, zones, instanceName, instance);
	aManualInstanceEnumeration.addElement(instance);
      }
    }
    freeZones ( zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsSlaveZone::enumInstances" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  Linux_DnsSlaveZoneManualInstance 
  Linux_DnsSlaveZoneResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName) {

#ifdef DEBUG
    cout << "entering Linux_DnsSlaveZone::getInstance" << endl;
#endif

    DNSZONE * zones, *all_zones;
    Linux_DnsSlaveZoneManualInstance instance;
    
    zones = getZones();	//getZonesByType("slave");
    all_zones = zones;        
    
    if ( !zones)
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");
    
    for (; zones->zoneName; zones++) {		
      if ( strcmp(zones->zoneType, "slave") )
	continue;
      
      if ((strcmp(zones->zoneName, anInstanceName.getName())) == 0) {
	setInstanceProperties(aContext, aBroker, zones, anInstanceName, instance);
	
#ifdef DEBUG
    cout << "exiting Linux_DnsSlaveZone::getInstance" << endl;
#endif
	return instance; 
      }
    } // end for
    freeZones( zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsSlaveZone::getInstance" << endl;
#endif
  }

  //----------------------------------------------------------------------------

  void
  Linux_DnsSlaveZoneResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsSlaveZoneManualInstance& aManualInstance) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsSlaveZone::setInstance" << endl;
#endif

    DNSZONE *zones, *myZone;
    
    zones = getZones();
    myZone = findZone(zones, aManualInstance.getInstanceName().getName());
    
    if ( ! myZone )
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");
    
    if ( strcmp(myZone->zoneType,"slave") != 0 )
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
    
    if ( aManualInstance.isResourceRecordFileSet() ) {
      free(myZone->zoneFileName);
      myZone->zoneFileName = strdup(aManualInstance.getResourceRecordFile());
    }
    /*
      if ( aManualInstance.isXferFormatSet() )
      {
      int xfmt = aManualInstance.getXferFormat();
      
      ZONEOPTS* zopts = findOptsInZone(myZone,"provide-ixfr");
      if ( zopts )
      {
      free(zopts->value);
      if ( xfmt == DNS_XFER_COMPLETE )
      zopts->value = strdup("no");
      else
      zopts->value = strdup("yes");
      }
      else
      {
      if ( xfmt == DNS_XFER_COMPLETE)
      addOptsToZone(myZone,"provide-ixfr","no");
      else
      addOptsToZone(myZone,"provide-ixfr","yes");
      }
      } */
    
    updateZones( zones ); 
    freeZones( zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsSlaveZone::setInstance" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  Linux_DnsSlaveZoneInstanceName
  Linux_DnsSlaveZoneResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneManualInstance& aManualInstance) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsSlaveZone::createInstance" << endl;
#endif

    DNSZONE * newZone = NULL;
    Linux_DnsSlaveZoneInstanceName anInstanceName = aManualInstance.getInstanceName();
    
    if (((anInstanceName.getName()) == NULL) || ((anInstanceName.getName()) == "" ) || ((anInstanceName.getName()) == " " ) ) {
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"Zonename is invalid");
    }
    
    DNSZONE * all_zones = getZones();
    if ( findZone(all_zones,anInstanceName.getName()) ) {
      freeZones(all_zones);
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The zone already exists");
    }
    freeZones(all_zones);
    
    newZone = (DNSZONE *)calloc(1+1,sizeof(DNSZONE));
    
    if (newZone) {
      // Take in value specified only at Dialog ??//
      
      newZone->zoneName = (char *)anInstanceName.getName();
      newZone->zoneType = "slave";
      
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
      
      // XferFormat (request-ixfr)
      /*if (aManualInstance.isXferFormatSet())
	{
	if (aManualInstance.getXferFormat() == DNS_XFER_COMPLETE)
	addOptsToZone(newZone,"request-ixfr","no");
	else
	addOptsToZone(newZone,"request-ixfr","yes"); 
	}*/
      
      DNSZONE * returnedZones = NULL;
      
      returnedZones = addZone(newZone, NULL);
      if (!returnedZones) {
	throw CmpiStatus(CMPI_RC_ERROR,"addZone() failed");
      }
      freeZones( returnedZones );
    }
    
#ifdef DEBUG
    cout << "exiting Linux_DnsSlaveZone::createInstance" << endl;
#endif

    return aManualInstance.getInstanceName();
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsSlaveZoneResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsSlaveZone::deleteInstance" << endl;
#endif

    deleteZone( anInstanceName.getName() );

#ifdef DEBUG
    cout << "exiting Linux_DnsSlaveZone::deleteInstance" << endl;
#endif
  }

	

  
  // extrinsic methods

  /*
  CMPIUint32 Linux_DnsSlaveZoneResourceAccess::ApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsSlaveZoneResourceAccess::ApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsSlaveZoneResourceAccess::ApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsSlaveZoneResourceAccess::ApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) { }
  */

  /*
  CMPIUint32 Linux_DnsSlaveZoneResourceAccess::VerifyOKToApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsSlaveZoneResourceAccess::VerifyOKToApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsSlaveZoneResourceAccess::VerifyOKToApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsSlaveZoneResourceAccess::VerifyOKToApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsSlaveZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) { }
  */

	
}


