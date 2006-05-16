// =======================================================================
// Linux_DnsHintZoneResourceAccess.cpp
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
#include "Linux_DnsHintZoneResourceAccess.h"

#include <string>
#include <iostream>

using namespace std;

#include "smt_dns_ra_support.h"
#include "smt_dns_valuemap.h"

namespace genProvider {
  
  
  //----------------------------------------------------------------------------
  // manual written methods

 
  static void setInstanceNameProperties(
      const CmpiContext& aContext,
      const CmpiBroker& mbp,
      const char* aNameSpaceP,
      DNSZONE * zone,
      Linux_DnsHintZoneInstanceName& anInstanceName) {

    anInstanceName.setNamespace(aNameSpaceP);
    anInstanceName.setName(zone->zoneName);
  }


  //----------------------------------------------------------------------------


  static void setInstanceProperties(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      DNSZONE * zone,
      const Linux_DnsHintZoneInstanceName& anInstanceName,
      Linux_DnsHintZoneManualInstance& aManualInstance) {
    
    aManualInstance.setInstanceName(anInstanceName);
    aManualInstance.setType(DNS_ZONETYPE_HINT);
    aManualInstance.setResourceRecordFile(zone->zoneFileName);
  }  

  //----------------------------------------------------------------------------


  //----------------------------------------------------------------------------
  //Linux_DnsHintZoneResourceAccess::Linux_DnsHintZoneResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsHintZoneResourceAccess::~Linux_DnsHintZoneResourceAccess() { }
    
  // intrinsic methods

  //----------------------------------------------------------------------------
  void
  Linux_DnsHintZoneResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsHintZoneInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
    cout << "entering Linux_DnsHintZone::enumInstanceNames" << endl;
#endif

    DNSZONE * zones, *all_zones;
    
    zones = getZones();	//getZonesByType("hint");
    all_zones = zones;
    if (zones) {
      for (; zones->zoneName != NULL ; zones++) {	
	if ( strcmp(zones->zoneType, "hint") )
	  continue;
	
	Linux_DnsHintZoneInstanceName instanceName;
	
	setInstanceNameProperties(aContext, aBroker, aNameSpaceP, zones, instanceName);
	anInstanceNameEnumeration.addElement(instanceName);
      }
      freeZones( all_zones );
    } 

#ifdef DEBUG
    cout << "exiting Linux_DnsHintZone::enumInstanceNames" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsHintZoneResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsHintZoneManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsHintZone::enumInstances" << endl;
#endif

    DNSZONE * zones = NULL, *all_zones;
    
    zones = getZones();	//getZonesByType("hint");
    all_zones = zones;
    
    if (zones) {
      for (; zones->zoneName != NULL ; zones++) {	    
	if ( strcmp(zones->zoneType, "hint") )
	  continue;
	
	Linux_DnsHintZoneManualInstance instance;
	Linux_DnsHintZoneInstanceName instanceName;
	
	setInstanceNameProperties(aContext, aBroker, aNameSpaceP, zones, instanceName);
	setInstanceProperties(aContext, aBroker, zones, instanceName, instance);
	aManualInstanceEnumeration.addElement(instance);
      }
      freeZones( all_zones );
    }

#ifdef DEBUG
    cout << "exiting Linux_DnsHintZone::enumInstances" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  Linux_DnsHintZoneManualInstance 
  Linux_DnsHintZoneResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsHintZoneInstanceName& anInstanceName) {

#ifdef DEBUG
    cout << "entering Linux_DnsHintZone::getInstance" << endl;
#endif

    DNSZONE * zones, *all_zones;
    Linux_DnsHintZoneManualInstance instance;
    
    zones = getZones();	//getZonesByType("hint");
    all_zones = zones;
    if (zones) {
      for (; zones->zoneName != NULL ; zones++) {
	if ( strcmp(zones->zoneType, "hint") )
	  continue;
	
	if ((strcmp(zones->zoneName, anInstanceName.getName())) == 0) {
	  setInstanceProperties(aContext, aBroker, zones, anInstanceName, instance);
	  
#ifdef DEBUG
    cout << "exiting Linux_DnsHintZone::getInstance" << endl;
#endif
	  return instance; 
	}
      }
      freeZones( all_zones );
    }

#ifdef DEBUG
    cout << "exiting Linux_DnsHintZone::getInstance" << endl;
#endif
  }

  //----------------------------------------------------------------------------

  void
  Linux_DnsHintZoneResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsHintZoneManualInstance& aManualInstance) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsHintZone::setInstance" << endl;
#endif

    DNSZONE *zones, *myZone;
    
    zones = getZones();
    myZone = findZone(zones, aManualInstance.getInstanceName().getName());
    
    if ( ! myZone )
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");
    
    if ( strcmp(myZone->zoneType,"forward") != 0 )
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");
    
    if ( aManualInstance.isResourceRecordFileSet() ) {
      free(myZone->zoneFileName);
      myZone->zoneFileName = strdup(aManualInstance.getResourceRecordFile());
    }
    updateZones(zones);
    freeZones( zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsHintZone::setInstance" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  Linux_DnsHintZoneInstanceName
  Linux_DnsHintZoneResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsHintZoneManualInstance& aManualInstance) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsHintZone::createInstance" << endl;
#endif

    DNSZONE * newZone = NULL;
    Linux_DnsHintZoneInstanceName anInstanceName = aManualInstance.getInstanceName();
    
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
      
      newZone->zoneType = "hint"; 
      
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
    cout << "exiting Linux_DnsHintZone::createInstance" << endl;
#endif
    return aManualInstance.getInstanceName();
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsHintZoneResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsHintZoneInstanceName& anInstanceName) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsHintZone::deleteInstance" << endl;
#endif

    deleteZone( anInstanceName.getName() );

#ifdef DEBUG
    cout << "exiting Linux_DnsHintZone::deleteInstance" << endl;
#endif
  }

	

  
  // extrinsic methods

  /*
  CMPIUint32 Linux_DnsHintZoneResourceAccess::ApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsHintZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsHintZoneResourceAccess::ApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsHintZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsHintZoneResourceAccess::ApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsHintZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsHintZoneResourceAccess::ApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsHintZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) { }
  */

  /*
  CMPIUint32 Linux_DnsHintZoneResourceAccess::VerifyOKToApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsHintZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsHintZoneResourceAccess::VerifyOKToApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsHintZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsHintZoneResourceAccess::VerifyOKToApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsHintZoneInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsHintZoneResourceAccess::VerifyOKToApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsHintZoneInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) { }
  */

	
}


