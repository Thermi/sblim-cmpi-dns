// =======================================================================
// Linux_DnsResourceRecordResourceAccess.cpp
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
#include "Linux_DnsResourceRecordResourceAccess.h"

#include "smt_dns_defaultvalues.h"
#include "smt_dns_ra_support.h"
#include "smt_dns_ra_rrhandle.h"
#include "smt_dns_valuemap.h"

using namespace std;

namespace genProvider {


//-----------------------------------------------------------------------------

  // manual written methods

  void freeDNSRecord(DNSRECORD * record) { 
    if (record) { 
      if(record->recordName) free(record->recordName);
      if(record->recordZoneName) free(record->recordZoneName);
      if(record->recordType) free(record->recordType);
      if(record->recordValue) free(record->recordValue);
      if(record->recordClass) free(record->recordClass);
      free(record);
    }
  } 
  
  DNSRECORD * createDNSRecord (Linux_DnsResourceRecordInstanceName anInstanceName) {
    
    DNSRECORD * newRecord = (DNSRECORD *)calloc(1+1,sizeof(DNSRECORD));
    
    if (newRecord) {
      newRecord->recordName = strdup(anInstanceName.getName());
      newRecord->recordZoneName = strdup(anInstanceName.getZoneName());
      newRecord->recordType = strdup(anInstanceName.getType());
      newRecord->recordValue = strdup(anInstanceName.getValue());
      newRecord->recordClass = NULL;
      return newRecord;
    }
    return NULL;
  }
  
  static void setInstanceNameProperties(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      DNSRECORD * record,
      DNSZONE * zone,
      Linux_DnsResourceRecordInstanceName& anInstanceName) {
       
    anInstanceName.setNamespace(aNameSpaceP);
    anInstanceName.setInstanceID(DEFAULT_INSTANCE_ID);
    anInstanceName.setName(record->recordName);
    anInstanceName.setZoneName(record->recordZoneName);
    anInstanceName.setValue(record->recordValue);
    anInstanceName.setType(record->recordType);
    
  }

  //----------------------------------------------------------------------------
  
  static void setInstanceProperties(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      DNSRECORD * record,
      const Linux_DnsResourceRecordInstanceName& anInstanceName,
      Linux_DnsResourceRecordManualInstance& aManualInstance) {
    
    Linux_DnsResourceRecordInstanceName inst = anInstanceName; 
    inst.setType(record->recordType); 
    
    aManualInstance.setInstanceName(inst);
    if (record->recordTTL && record->recordTTL >= 0)
      aManualInstance.setTTL(record->recordTTL);
    
    if (record->recordClass) {
      if (strcmp(record->recordClass,"IN") == 0 ) aManualInstance.setFamily( DNS_RRFAMILY_INTERNET );
      else if (strcmp(record->recordClass,"HS") == 0 ) aManualInstance.setFamily( DNS_RRFAMILY_HESIOD );
      else if (strcmp(record->recordClass,"CH") == 0 ) aManualInstance.setFamily( DNS_RRFAMILY_CHAOS );
      else aManualInstance.setFamily( 0 );
    }
    else aManualInstance.setFamily( DNS_RRFAMILY_UNKNOWN );
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
    
    DNSZONE * zones = NULL, * all_zones = NULL ;
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
      freeZones(all_zones);
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
    
    DNSZONE * zones = NULL, * all_zones = NULL ;
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
      freeZones(all_zones); 
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

    DNSZONE * zones = NULL, * all_zones = NULL ;
    Linux_DnsResourceRecordManualInstance instance;
    
    DNSRECORD * newRecord = NULL; 
    
    if (!anInstanceName.isTypeSet() || CmpiData(anInstanceName.getType()).isNullValue()) 
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The specified Resource Record's Type is invalid."); 
    
    zones = getZones();
    all_zones = zones ;
    
    //############Error Handling#############
    if ( ! zones )
      throw CmpiStatus(CMPI_RC_ERR_FAILED,"No Zones defined");
    
    DNSZONE *myZone = findZone( zones, anInstanceName.getZoneName() );
    if ( ! myZone ) {
      freeZones(all_zones);
      throw CmpiStatus(CMPI_RC_ERR_FAILED,"The Zone of the Resource Record does not exist");
    }
    
    newRecord = createDNSRecord(anInstanceName);
    
    DNSRECORD *rec = findRecord( myZone, newRecord); 
    freeDNSRecord(newRecord); 
    
    if ( ! rec ) { 
      freeZones(all_zones);
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND, "The specified Resource Record instance does not exist."); 
    }
    
    setInstanceProperties(aContext, aBroker, rec, anInstanceName, instance);
    freeZones(all_zones); 
    
#ifdef DEBUG
    cout << "exiting Linux_DnsResourceRecord::getInstance" << endl;
#endif

    return instance;
}

//----------------------------------------------------------------------------
  
  void
  Linux_DnsResourceRecordResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsResourceRecordManualInstance& aManualInstance) {

#ifdef DEBUG
    cout << "entering Linux_DnsResourceRecord::setInstance" << endl;
#endif
    
    DNSZONE * zones = NULL, * all_zones = NULL ;
    DNSRECORD * newRecord = NULL; 
    
    Linux_DnsResourceRecordInstanceName anInstanceName = aManualInstance.getInstanceName(); 
    
    if (!aManualInstance.getInstanceName().isTypeSet() || CmpiData(aManualInstance.getInstanceName().getType()).isNullValue()) 
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The specified Resource Record's Type is invalid."); 
    
    zones = getZones();
    all_zones = zones ;
    
    //############Error Handling#############
    if ( ! zones )
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"No Zones defined");
    
    DNSZONE *myZone = findZone( zones, anInstanceName.getZoneName() );
    if ( ! myZone ) {
      freeZones(all_zones);
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");
    }
    
    newRecord = createDNSRecord(anInstanceName);
    
    if (newRecord) {
      
      if (! (aManualInstance.isFamilySet())) {
        newRecord->recordClass = strdup("IN");
      } else {
	switch (aManualInstance.getFamily()) {
        case 1:
          newRecord->recordClass = strdup("IN"); // if unknown set to Internet as default
          break;
        case 2:
          newRecord->recordClass = strdup("HS");
          break;
        case 3:
          newRecord->recordClass = strdup("CH");
          break;
        default:
          newRecord->recordClass = strdup("IN");
          break;
        }
      }
      
      if (aManualInstance.isTTLSet() && !CmpiData(aManualInstance.getTTL()).isNullValue()) {
        newRecord->recordTTL = (unsigned long) aManualInstance.getTTL();
      } else {
        newRecord->recordTTL = -1;
      }
    }
    
    DNSRECORD *rec = findRecord( myZone, newRecord); 
    
    if ( ! rec ) {
      freeDNSRecord(newRecord); 
      freeZones(all_zones);
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND, "The specified Resource Record instance does not exist.");
    }
    
    modifyRecordTTL((char *)anInstanceName.getZoneName(), newRecord, newRecord->recordTTL);
    
    if (aManualInstance.isFamilySet() && CmpiData(aManualInstance.getFamily()).isNullValue()) { 
      switch (aManualInstance.getFamily()) {
      case 1:
	modifyRecordClass( (char *)anInstanceName.getZoneName(), newRecord, "IN");
	break;
      case 2:
	modifyRecordClass( (char *)anInstanceName.getZoneName(), newRecord, "HS");
	break;
      case 3:
	modifyRecordClass( (char *)anInstanceName.getZoneName(), newRecord, "CH");
	break;
      default:
	modifyRecordClass( (char *)anInstanceName.getZoneName(), newRecord, "IN");
	break;
      }
    } else {
      modifyRecordClass( (char *)anInstanceName.getZoneName(), newRecord, "IN");
    }
    
    freeDNSRecord(newRecord); 
    freeZones(all_zones); 
    
#ifdef DEBUG
    cout << "exiting Linux_DnsResourceRecord::setInstance" << endl;
#endif 
  }
  
  //----------------------------------------------------------------------------
  
  Linux_DnsResourceRecordInstanceName
  Linux_DnsResourceRecordResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsResourceRecordManualInstance& aManualInstance) {

#ifdef DEBUG
    cout << "entering Linux_DnsResourceRecord::createInstance" << endl;
#endif
    
    DNSZONE * zones = NULL , * all_zones = NULL , * my_zone = NULL;
    DNSRECORD * newRecord = NULL;
    
    Linux_DnsResourceRecordInstanceName anInstanceName = aManualInstance.getInstanceName();
    
    if (!aManualInstance.getInstanceName().isTypeSet() || CmpiData(aManualInstance.getInstanceName().getType()).isNullValue()) 
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The specified Resource Record's Type is invalid."); 
    
    newRecord = createDNSRecord(anInstanceName); 
    
    if (newRecord) {
      
      if (! (aManualInstance.isFamilySet())) {
	newRecord->recordClass = strdup("IN");
      } else {
	switch (aManualInstance.getFamily()) {
	case 1:
	  newRecord->recordClass = strdup("IN"); // if unknown set to Internet as default
	  break;
	case 2:
	  newRecord->recordClass = strdup("HS");
	  break;
	case 3:
	  newRecord->recordClass = strdup("CH");
	  break;
	default:
	  newRecord->recordClass = strdup("IN");
	  break;
	}
      }
      
      if (aManualInstance.isTTLSet() && !CmpiData(aManualInstance.getTTL()).isNullValue()) {
	newRecord->recordTTL = (unsigned long) aManualInstance.getTTL();
      } else {
	newRecord->recordTTL = -1;
      }
    }
    
    zones = getZones();
    all_zones = zones;
    
    if ( ! zones ) {
      freeDNSRecord(newRecord);
      throw CmpiStatus(CMPI_RC_ERR_FAILED,"There are no Zones defined. Cannot create Resource Record");
    }
    else {
      my_zone = findZone(zones, newRecord->recordZoneName);
      
      if ( ! my_zone ) {
        freeZones(all_zones);
        freeDNSRecord(newRecord);
        throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The specified Zone does not exist.");
      }
      
      DNSRECORD *rec = findRecord( my_zone, newRecord);
      
      if ( rec ) { 
	freeZones(all_zones);
	freeDNSRecord(newRecord);
	throw CmpiStatus(CMPI_RC_ERR_ALREADY_EXISTS, "The specified Resource Record instance already exists.");

      } else {
	addRecord(my_zone, newRecord);
	updateZones(all_zones);
      }
    }
    
    freeDNSRecord(newRecord);
    freeZones(all_zones);
    
#ifdef DEBUG
    cout << "exiting Linux_DnsResourceRecord::createInstance" << endl;
#endif
    
    return anInstanceName;
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

    DNSZONE * zones = NULL, * all_zones = NULL ;
    Linux_DnsResourceRecordManualInstance instance;
    DNSRECORD * newRecord = NULL; 
    
    if (!anInstanceName.isTypeSet() || CmpiData(anInstanceName.getType()).isNullValue()) 
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The specified Resource Record's Type is invalid."); 
    
    zones = getZones();
    all_zones = zones ;
    
    //############Error Handling#############
    if ( ! zones )
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"No Zones defined");
    
    DNSZONE *myZone = findZone( zones, anInstanceName.getZoneName() );
    if ( ! myZone ) {
      freeZones(all_zones);
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");
    }
    
    newRecord = createDNSRecord(anInstanceName); 
    
    DNSRECORD *rec = findRecord( myZone, newRecord );
    
    if ( ! rec ) { 
      freeZones(all_zones);
      freeDNSRecord(newRecord); 
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"The Resource Record with the specified name does not exist");
    }
    
    deleteRecord(myZone->zoneName, newRecord); 
    freeDNSRecord(newRecord); 
    freeZones(all_zones); 
    
#ifdef DEBUG
    cout << "exiting Linux_DnsResourceRecord::deleteInstance" << endl;
#endif
  }
  
 // extrinsic methods

	
}


