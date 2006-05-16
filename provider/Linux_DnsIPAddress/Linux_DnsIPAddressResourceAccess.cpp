// =======================================================================
// Linux_DnsIPAddressResourceAccess.cpp
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
#include "Linux_DnsIPAddressResourceAccess.h"

#include <iostream>
#include <string>
#include <list>

using namespace std;

#include "smt_dns_ra_support.h"
#include "smt_dns_valuemap.h"
#include "smt_dns_array.h"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsIPAddressResourceAccess::Linux_DnsIPAddressResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsIPAddressResourceAccess::~Linux_DnsIPAddressResourceAccess() { }
    
  // intrinsic methods

  //----------------------------------------------------------------------------
  void
  Linux_DnsIPAddressResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsIPAddressInstanceNameEnumeration& anInstanceNameEnumeration) {

#ifdef DEBUG
    cout << "entering Linux_DnsIPAddress::enumInstanceNames" << endl;
#endif

    DNSZONE *zones = getZones();
    
    while (zones && zones->zoneName) {
      if ( strcmp(zones->zoneType,"slave") ) {
	zones++;
	continue;
      }
      
      ZONEOPTS *zopts = findOptsInZone(zones,"masters");
      
      if (zopts && zopts->key && zopts->value ) {
	DnsArray iplist = DnsArray(zopts->value);
	DnsArrayConstIterator iter; 
	
	for ( iter = iplist.begin(); iter != iplist.end(); ++iter ) {
	  Linux_DnsIPAddressInstanceName anInstanceName;
	  
	  anInstanceName.setNamespace(aNameSpaceP);
	  anInstanceName.setZoneName(zones->zoneName);
	  anInstanceName.setIPAddress( (*iter).c_str() );
	  
	  anInstanceNameEnumeration.addElement(anInstanceName);
	}
      }
      zones++;
    }

#ifdef DEBUG
    cout << "exiting Linux_DnsIPAddress::enumInstanceNames" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsIPAddressResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsIPAddressManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsIPAddress::enumInstances" << endl;
#endif

    DNSZONE *zones = getZones();
    
    while (zones && zones->zoneName) {
      if ( strcmp(zones->zoneType,"slave") ) {
	zones++;
	continue;
      }
      
      ZONEOPTS *zopts = findOptsInZone(zones,"masters");
      
      if (zopts) {
	DnsArray iplist = DnsArray(zopts->value);
	DnsArrayConstIterator iter; 
        
	for ( iter = iplist.begin(); iter != iplist.end(); ++iter ) {
	  Linux_DnsIPAddressInstanceName anInstanceName;
	  Linux_DnsIPAddressManualInstance aManualInstance;
	  
	  anInstanceName.setNamespace(aNameSpaceP);
	  anInstanceName.setZoneName(zones->zoneName);
	  anInstanceName.setIPAddress( (*iter).c_str() );
	  aManualInstance.setInstanceName(anInstanceName);
	  
	  aManualInstanceEnumeration.addElement(aManualInstance);
	}
      }
      zones++;
    }

#ifdef DEBUG
    cout << "exiting Linux_DnsIPAddress::enumInstances" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsIPAddressManualInstance 
  Linux_DnsIPAddressResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsIPAddressInstanceName& anInstanceName) {

    Linux_DnsIPAddressManualInstance manualInstance;

  
  }
  */
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsIPAddressResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsIPAddressManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------

  Linux_DnsIPAddressInstanceName
  Linux_DnsIPAddressResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsIPAddressManualInstance& aManualInstance) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsIPAddress::createInstance" << endl;
#endif

    Linux_DnsIPAddressInstanceName anInstanceName = aManualInstance.getInstanceName();
    
    DNSZONE *zones = getZones();
    DNSZONE *zone;
    
    // Find the requested zone. If that does not exist throw an exception
    zone = findZone(zones,anInstanceName.getZoneName());
    if (!zone) {
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
    }
    /* Now zone points to the _desired_ zone */
    ZONEOPTS* zopts = findOptsInZone(zone,"masters");
    
    DnsArray iplist;	
    // If already exist masters put them in the list.
    if (zopts) {
      // If the indicated Master server already exist...
      iplist.populate(zopts->value);
      
      if ( iplist.isPresent( string( anInstanceName.getIPAddress() ) )	)
	throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"This Master server already exist!");
    }
    // put the just created in the list
    iplist.add( string(anInstanceName.getIPAddress()) );
    
    // Save them in the configuration file.
    addMasters(zones, anInstanceName.getZoneName(), iplist.toString().c_str() );
    
#ifdef DEBUG
    cout << "exiting Linux_DnsIPAddress::createInstance" << endl;
#endif
    return aManualInstance.getInstanceName();
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsIPAddressResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsIPAddressInstanceName& anInstanceName) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsIPAddress::deleteInstance" << endl;
#endif
    DNSZONE *zones = getZones();
    DNSZONE *zone;
    
    // Find the requested zone. If that does not exist throw an exception
    zone = findZone(zones,anInstanceName.getZoneName());
    if (!zone) {
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
    }
    /* Now zone points to the _desired_ zone */
    ZONEOPTS* zopts = findOptsInZone(zone,"masters");
    
    DnsArray iplist;
    // If already exist masters put them in the list.
    if (zopts) {
      iplist.populate(zopts->value);
      
      iplist.remove( string(anInstanceName.getIPAddress()) );
    }
    // Save them in the configuration file.
    addMasters(zones, anInstanceName.getZoneName(), iplist.toString().c_str() );

#ifdef DEBUG
    cout << "exiting Linux_DnsIPAddress::deleteInstance" << endl;
#endif
  }

	

  
  // extrinsic methods

  /*
  CMPIUint32 Linux_DnsIPAddressResourceAccess::ApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsIPAddressInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsIPAddressResourceAccess::ApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsIPAddressInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsIPAddressResourceAccess::ApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsIPAddressInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsIPAddressResourceAccess::ApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsIPAddressInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) { }
  */

  /*
  CMPIUint32 Linux_DnsIPAddressResourceAccess::VerifyOKToApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsIPAddressInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsIPAddressResourceAccess::VerifyOKToApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsIPAddressInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsIPAddressResourceAccess::VerifyOKToApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsIPAddressInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsIPAddressResourceAccess::VerifyOKToApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsIPAddressInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) { }
  */

	
}


