// =======================================================================
// Linux_DnsResourceRecordResourceAccess.cpp
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
#include "Linux_DnsResourceRecordResourceAccess.h"

#include "smt_dns_ra_support.h"
#include "smt_dns_ra_rrhandle.h"
#include "smt_dns_valuemap.h"

using namespace std;

namespace genProvider {
  
  
  //----------------------------------------------------------------------------
  // manual written methods

  static void setInstanceNameProperties(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      DNSRECORD * record,
      DNSZONE * zone,
      Linux_DnsResourceRecordInstanceName& anInstanceName) {

    anInstanceName.setNamespace(aNameSpaceP);
    anInstanceName.setName(record->recordName);
    anInstanceName.setZoneName(zone->zoneName);
    
    if (strcmp(record->recordType,"NS") == 0) {
      anInstanceName.setType(3);

    } else if (strcmp(record->recordType,"A") == 0) {
      anInstanceName.setType(6);

    } else if (strcmp(record->recordType,"MX") == 0) {
      anInstanceName.setType(4);

    } else {
      anInstanceName.setType(6);  // = Type A 
    }
    
    anInstanceName.setValue(record->recordValue); 
  }
    

  //----------------------------------------------------------------------------


  static void setInstanceProperties(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      DNSRECORD * record,
      const Linux_DnsResourceRecordInstanceName& anInstanceName,
      Linux_DnsResourceRecordManualInstance& aManualInstance) {
    
    aManualInstance.setInstanceName(anInstanceName);
    aManualInstance.setTTL(60*60*24); 
    aManualInstance.setFamily( DNS_RRFAMILY_INTERNET );
  }   
  

  //----------------------------------------------------------------------------


  //----------------------------------------------------------------------------
  //Linux_DnsResourceRecordResourceAccess::Linux_DnsResourceRecordResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsResourceRecordResourceAccess::~Linux_DnsResourceRecordResourceAccess() { }
    
  // intrinsic methods

  //----------------------------------------------------------------------------
  void
  Linux_DnsResourceRecordResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsResourceRecordInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
    cout << "entering Linux_DnsResourceRecord::enumInstanceNames" << endl;
#endif

    DNSZONE * zones = NULL, *all_zones;
    
    zones = getZones();
    all_zones = zones;
    
    if (zones) {
      for (; zones->zoneName; zones++) {
	if (zones->records) {
	  DNSRECORD * records = NULL;
	  
	  for (records = zones->records; records->recordName; ++records) {
	    Linux_DnsResourceRecordInstanceName instanceName;
	    setInstanceNameProperties(aContext, aBroker, aNameSpaceP, records, zones, instanceName);
	    anInstanceNameEnumeration.addElement(instanceName);
	  }
	}
	
      }
      freeZones( all_zones );
    }

#ifdef DEBUG
    cout << "exiting Linux_DnsResourceRecord::enumInstanceNames" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsResourceRecordResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsResourceRecordManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsResourceRecord::enumInstances" << endl;
#endif

    DNSZONE * zones, *all_zones;
    
    zones = getZones();
    all_zones = zones;
    
    if (zones) {
      for (; zones->zoneName; zones++) {
	if (zones->records) {
	  DNSRECORD * records = NULL;
	  
	  for (records= zones->records; records->recordName; ++records) {
	    Linux_DnsResourceRecordManualInstance instance;
	    Linux_DnsResourceRecordInstanceName instanceName;
	    
	    setInstanceNameProperties(aContext, aBroker, aNameSpaceP, records, zones, instanceName);
	    setInstanceProperties(aContext, aBroker, records, instanceName, instance);
	    aManualInstanceEnumeration.addElement(instance);
	  }
	}
      } 
      freeZones( all_zones );
    }

#ifdef DEBUG
    cout << "exiting Linux_DnsResourceRecord::enumInstances" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  Linux_DnsResourceRecordManualInstance 
  Linux_DnsResourceRecordResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsResourceRecordInstanceName& anInstanceName) {

#ifdef DEBUG
    cout << "entering Linux_DnsResourceRecord::getInstance" << endl;
#endif

    DNSZONE * zones = NULL, *all_zones;
    Linux_DnsResourceRecordManualInstance instance;
    
    zones = getZones();
    all_zones = zones;
    
    if (zones) {
      for (; zones->zoneName ; zones++) {
	if (zones->records) {
	  DNSRECORD * records = NULL;
	  for (records = zones->records; records->recordName; ++records) {
	    if ((strcmp(records->recordName, anInstanceName.getName())) == 0) {
	      setInstanceProperties(aContext, aBroker, records, anInstanceName, instance);

#ifdef DEBUG
	      cout << "exiting Linux_DnsResourceRecord::getInstance" << endl;
#endif
	      return instance;
	    }
	  }
	}
      }
      freeZones( all_zones );
    }

#ifdef DEBUG
    cout << "exiting Linux_DnsResourceRecord::getInstance" << endl;
#endif
  }

  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsResourceRecordResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsResourceRecordManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------

  Linux_DnsResourceRecordInstanceName
  Linux_DnsResourceRecordResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsResourceRecordManualInstance& aManualInstance) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsResourceRecord::createInstance" << endl;
#endif

    DNSZONE * zones = NULL;
    DNSZONE * origZones = NULL;
    DNSRECORD * records = NULL;
    DNSRECORD * newRecord = NULL;
    
    Linux_DnsResourceRecordInstanceName anInstanceName = aManualInstance.getInstanceName();
    
    newRecord = (DNSRECORD *)calloc(1+1,sizeof(DNSRECORD));
    
    if (newRecord) {
      // Take in value specified only at Dialog ??//
      newRecord->recordName = (char *)anInstanceName.getName();
      newRecord->recordZoneName = (char *)anInstanceName.getZoneName(); 
      
      if (! (anInstanceName.isTypeSet())) {
	newRecord->recordType = "A";
	
      } else {
       
#ifdef DEBUG
        cout << "\tType of the new record is: "<< anInstanceName.getType() << endl;
#endif
	switch (anInstanceName.getType()) {
	case 3:
	  newRecord->recordType = "NS";
	  break;
	case 4:
	  newRecord->recordType = "MX";
	  break;
	case 6:
	  newRecord->recordType = "A";
	  break;
	default:
	  newRecord->recordType = "A";
	  break;
	}
      }
      newRecord->recordValue = (char*)anInstanceName.getValue();
      
      // if not at dialog then use following default required values (smt_dns_ra_support.h) for a Zone 
      // may need to get them from default section in Service 
      
      // list of mof attributes not in smt_dns_ra_support.h
      //class
      //enabled
      //TTL
      
    }
    
    zones = getZones();
    origZones = zones;
    
    if ( ! zones ) {
      // no zones defined at all - cannot create a record 
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"--- No zone defined - cannot create a RR");
      
    } else {
      // at least one zone already defined   
      for (; zones->zoneName; zones++) {
	// check to see if record already exists
	if ((strcmp(zones->zoneName, newRecord->recordZoneName)) == 0) {
	  if (zones->records != NULL) {
	    for (records = zones->records; ((records->recordName) != NULL); ++records) {
	      if (((strcmp(records->recordName, newRecord->recordName)) == 0) && 
		  ((strcmp(records->recordType, newRecord->recordType)) == 0) &&
		  ((strcmp(records->recordValue, newRecord->recordValue)) == 0)) {
		throw CmpiStatus(CMPI_RC_ERR_ALREADY_EXISTS," Record already exists");
	      }
	    }
	  }
	  
	  records = addRecord(zones, newRecord);
	  updateZones(origZones);
	  freeZones( origZones );
	  
#ifdef DEBUG
	  cout << "exiting Linux_DnsResourceRecord::createInstance" << endl;
#endif
	  return aManualInstance.getInstanceName();
	}
      }

      freeZones( origZones );
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"No zone exists with given zoneName");    
    }
    
#ifdef DEBUG
    cout << "exiting Linux_DnsResourceRecord::createInstance" << endl;
#endif
    return aManualInstance.getInstanceName();
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsResourceRecordResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsResourceRecordInstanceName& anInstanceName) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsResourceRecord::deleteInstance" << endl;
#endif
    DNSZONE *zones = getZones();

    if ( ! zones ) {
#ifdef DEBUG
      cout << "exiting Linux_DnsResourceRecord::deleteInstance" << endl;
#endif
      return ;
    }
    
    DNSZONE *myZone = findZone( zones, anInstanceName.getZoneName() );
    if ( ! myZone ) {
#ifdef DEBUG
      cout << "exiting Linux_DnsResourceRecord::deleteInstance" << endl;
#endif
      return ;
    }
    
    DNSRECORD *rec = findRecord( myZone, anInstanceName.getName() );
    if ( ! rec ) {
#ifdef DEBUG
      cout << "exiting Linux_DnsResourceRecord::deleteInstance" << endl;
#endif
      return ;
    }
    
    freeZones( zones );
    deleteRR( anInstanceName.getName(), myZone->zoneFileName );

#ifdef DEBUG
    cout << "exiting Linux_DnsResourceRecord::deleteInstance" << endl;
#endif
  }

	

  
  // extrinsic methods

  /*
  CMPIUint32 Linux_DnsResourceRecordResourceAccess::ApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsResourceRecordInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsResourceRecordResourceAccess::ApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsResourceRecordInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsResourceRecordResourceAccess::ApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsResourceRecordInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsResourceRecordResourceAccess::ApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsResourceRecordInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) { }
  */

  /*
  CMPIUint32 Linux_DnsResourceRecordResourceAccess::VerifyOKToApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsResourceRecordInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsResourceRecordResourceAccess::VerifyOKToApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsResourceRecordInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsResourceRecordResourceAccess::VerifyOKToApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsResourceRecordInstanceName& anInstanceName,
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
  CMPIUint32 Linux_DnsResourceRecordResourceAccess::VerifyOKToApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsResourceRecordInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) { }
  */

	
}


