// =======================================================================
// Linux_DnsResourceRecordsForZoneResourceAccess.cpp
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
#include "Linux_DnsResourceRecordsForZoneResourceAccess.h"

#include <string>
#include <list>

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

namespace genProvider {

  //----------------------------------------------------------------------------
  // manual written methods

  static void setInstanceNameProperties(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      DNSRECORD * record,
      DNSZONE * zone,
      Linux_DnsResourceRecordsForZoneInstanceName& anInstanceName) {

    Linux_DnsZoneInstanceName groupInst;
    Linux_DnsResourceRecordInstanceName partInst;
  
    anInstanceName.setNamespace(aNameSpaceP);
    groupInst.setNamespace(aNameSpaceP);
    partInst.setNamespace(aNameSpaceP);

    partInst.setName(record->recordName);
    partInst.setZoneName(zone->zoneName);
    partInst.setType(record->recordType);

    partInst.setValue(record->recordValue);
    partInst.setInstanceID(DEFAULT_INSTANCE_ID);
    

    groupInst.setName(zone->zoneName);
    groupInst.setInstanceID(DEFAULT_INSTANCE_ID); 

    anInstanceName.setGroupComponent(groupInst);
    anInstanceName.setPartComponent(partInst);
}


  //----------------------------------------------------------------------------


  static void setInstanceProperties(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      DNSRECORD * record,
      const Linux_DnsResourceRecordsForZoneInstanceName& anInstanceName,
      Linux_DnsResourceRecordsForZoneManualInstance& aManualInstance) {

    aManualInstance.setInstanceName(anInstanceName);
  }


  //----------------------------------------------------------------------------

  
  //----------------------------------------------------------------------------
  //Linux_DnsResourceRecordsForZoneResourceAccess::Linux_DnsResourceRecordsForZoneResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsResourceRecordsForZoneResourceAccess::~Linux_DnsResourceRecordsForZoneResourceAccess() { }
    
  // intrinsic methods
  
//----------------------------------------------------------------------------

  void
  Linux_DnsResourceRecordsForZoneResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsResourceRecordsForZoneInstanceNameEnumeration& anInstanceNameEnumeration) {
      
    int instanceNameN = 1;
    for (int x=0; x < instanceNameN; ++x) {

    #ifdef DEBUG
     cout << "entering Linux_DnsResourceRecordsForZone::enumInstanceNames" << endl;
    #endif

    DNSZONE * zones = NULL, *all_zones;

    zones = getZones();
    all_zones = zones;
    
    if (zones) {
      for (; zones->zoneName; zones++) {
        if (zones->records) {
          DNSRECORD * records = NULL;

          for (records = zones->records; records->recordName; ++records) {
            Linux_DnsResourceRecordsForZoneInstanceName instanceName;
            setInstanceNameProperties(aContext, aBroker, aNameSpaceP, records, zones, instanceName);
            anInstanceNameEnumeration.addElement(instanceName);
          }
        }

      }
      freeZones( all_zones );
    }

    #ifdef DEBUG
     cout << "exiting Linux_DnsResourceRecordsForZone::enumInstanceNames" << endl;
    #endif
    }
 
  }
  
  //----------------------------------------------------------------------------
  
  void
  Linux_DnsResourceRecordsForZoneResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsResourceRecordsForZoneManualInstanceEnumeration& aManualInstanceEnumeration) {


    #ifdef DEBUG
     cout << "entering Linux_DnsResourceRecordsForZone::enumInstances" << endl;
    #endif

    DNSZONE * zones, *all_zones;

    zones = getZones();
    all_zones = zones;

    if (zones) {
      for (; zones->zoneName; zones++) {
        if (zones->records) {
          DNSRECORD * records = NULL;

          for (records= zones->records; records->recordName; ++records) {
            Linux_DnsResourceRecordsForZoneManualInstance instance;
            Linux_DnsResourceRecordsForZoneInstanceName instanceName;

            setInstanceNameProperties(aContext, aBroker, aNameSpaceP, records, zones, instanceName);
            setInstanceProperties(aContext, aBroker, records, instanceName, instance);
            aManualInstanceEnumeration.addElement(instance);
          }
        }
      }
      freeZones( all_zones );
    }

    #ifdef DEBUG
     cout << "exiting Linux_DnsResourceRecordsForZone::enumInstances" << endl;
    #endif


 }
  
  //----------------------------------------------------------------------------
  
  Linux_DnsResourceRecordsForZoneManualInstance 
  Linux_DnsResourceRecordsForZoneResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsResourceRecordsForZoneInstanceName& anInstanceName) {

   #ifdef DEBUG
    cout << "entering Linux_DnsResourceRecordsForZone::getInstance" << endl;
   #endif

   Linux_DnsResourceRecordsForZoneManualInstance manualInstance;

   DNSZONE * all_zones = NULL, * my_zone = NULL ;

   all_zones = getZones();

   if ( all_zones )
     my_zone = findZone(all_zones, anInstanceName.getGroupComponent().getName()) ;

   if ( !my_zone )
     throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER, "The specified Zone does not exist.");

   if ( ! my_zone->records ) {
     freeZones( all_zones ) ;
     throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER, "This ResourceRecord instance does not exist for the Zone specified.");
   }
   else {
     DNSRECORD * record = NULL ; 
  
     Linux_DnsResourceRecordInstanceName rrInstanceName = anInstanceName.getPartComponent(); 

     for ( record = my_zone->records; record->recordName; record++ ) { 
        
        if ( (strcmp(rrInstanceName.getName(),record->recordName) == 0 ) &&
             (strcmp(rrInstanceName.getZoneName(),record->recordZoneName) == 0 ) &&
             (strcmp(rrInstanceName.getValue(),record->recordValue) == 0 ) &&
             (strcmp(rrInstanceName.getType(),record->recordType) == 0) &&   
             (strcmp(rrInstanceName.getInstanceID(),DEFAULT_INSTANCE_ID) == 0 ) ) { 
           manualInstance.setInstanceName(anInstanceName); 
           freeZones(all_zones);
    #ifdef DEBUG
      cout << "exiting Linux_DnsResourceRecordsForZone::getInstance" << endl;
    #endif
           return manualInstance;  
        }
     }
   }  
   
   freeZones(all_zones);
   throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND, "The specified instance does not exist."); 
  
   return manualInstance; // this unreachable return statement is to remove compiler warning..
  
  }
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsResourceRecordsForZoneResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsResourceRecordsForZoneManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsResourceRecordsForZoneInstanceName
  Linux_DnsResourceRecordsForZoneResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsResourceRecordsForZoneManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsResourceRecordsForZoneResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsResourceRecordsForZoneInstanceName& anInstanceName) { }
	*/
	

  // Association Interface
  //----------------------------------------------------------------------------
  
  void Linux_DnsResourceRecordsForZoneResourceAccess::referencesGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsResourceRecordInstanceName& aSourceInstanceName,
    Linux_DnsResourceRecordsForZoneManualInstanceEnumeration& aManualInstanceEnumeration) {

#ifdef DEBUG
      cout << "entering Linux_DnsResourceRecordsForZone::referencesGroupComponent" << endl;
#endif

   DNSZONE * all_zones = NULL, * my_zone = NULL ;

   all_zones = getZones();

   if ( all_zones )
     my_zone = findZone(all_zones, aSourceInstanceName.getZoneName()) ;

   if ( !my_zone ) { 
     freeZones(all_zones);
//     return;
     throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER, "The specified ResourceRecord's Zone does not exist.");
   }

   if ( ! my_zone->records ) {
     freeZones( all_zones ) ;
//     return;
     throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER, "This ResourceRecord instance does not exist for the Zone specified.");
   }
   else {
     DNSRECORD * records = NULL; 

     for (records = my_zone->records; ((records->recordName) != NULL ); records++ ) { 
        if ( (strcmp(records->recordName,aSourceInstanceName.getName()) != 0) || 
             (strcmp(records->recordType,aSourceInstanceName.getType()) != 0) ||
             (strcmp(records->recordValue,aSourceInstanceName.getValue()) != 0) || 
             (strcmp(records->recordZoneName,aSourceInstanceName.getZoneName()) != 0) ) {
          continue; 
        } 
        else {
          Linux_DnsZoneInstanceName zoneInstName; 
          zoneInstName.setNamespace(aNameSpaceP);
          zoneInstName.setName(my_zone->zoneName);
          zoneInstName.setInstanceID(DEFAULT_INSTANCE_ID);

          Linux_DnsResourceRecordsForZoneManualInstance inst;
          Linux_DnsResourceRecordsForZoneInstanceName instName;
          instName.setNamespace( aNameSpaceP );
          instName.setGroupComponent( zoneInstName );
          instName.setPartComponent( aSourceInstanceName );
          inst.setInstanceName( instName );

          aManualInstanceEnumeration.addElement(inst);
          break;  
        }
     }
//     if (records->recordName == NULL) {
//       freeZones(all_zones);
//       throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND, "The ResourceRecord instance is not part of the Zone specified");
//     }
   }       
   freeZones(all_zones);

#ifdef DEBUG
      cout << "exiting Linux_DnsResourceRecordsForZone::referencesGroupComponent" << endl;
#endif

 }
 
  //----------------------------------------------------------------------------
  
  void Linux_DnsResourceRecordsForZoneResourceAccess::referencesPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsZoneInstanceName& aSourceInstanceName,
    Linux_DnsResourceRecordsForZoneManualInstanceEnumeration& aManualInstanceEnumeration) {

#ifdef DEBUG
      cout << "entering Linux_DnsResourceRecordsForZone::referencesPartComponent" << endl;
#endif

   DNSZONE * all_zones = NULL, * my_zone = NULL ;

   all_zones = getZones();

   if ( all_zones )
     my_zone = findZone(all_zones, aSourceInstanceName.getName()) ;

   if ( !my_zone ) { 
     freeZones(all_zones);
//     return;
     throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER, "The specified Zone does not exist.");
   }

   if ( my_zone->records ) {
     DNSRECORD * records = NULL ; 
     
     for (records = my_zone->records ; ((records->recordName) != NULL); records++ ) { 
        Linux_DnsResourceRecordInstanceName recordInstanceName;
        recordInstanceName.setNamespace(aNameSpaceP);
        recordInstanceName.setName(records->recordName);
        recordInstanceName.setZoneName(records->recordZoneName);
        recordInstanceName.setValue(records->recordValue);
        recordInstanceName.setInstanceID(DEFAULT_INSTANCE_ID); 
        recordInstanceName.setType(records->recordType);
     
        Linux_DnsResourceRecordsForZoneManualInstance inst;
        Linux_DnsResourceRecordsForZoneInstanceName instName;
        instName.setNamespace( aNameSpaceP );
        instName.setGroupComponent( aSourceInstanceName );
        instName.setPartComponent( recordInstanceName );
        inst.setInstanceName( instName );

        aManualInstanceEnumeration.addElement(inst);
     } 
  }
  freeZones(all_zones);
#ifdef DEBUG
      cout << "exiting Linux_DnsResourceRecordsForZone::referencesPartComponent" << endl;
#endif

 }
  
  //----------------------------------------------------------------------------
  
  void Linux_DnsResourceRecordsForZoneResourceAccess::associatorsGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsResourceRecordInstanceName& aSourceInstanceName,
    Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
      cout << "entering Linux_DnsResourceRecordsForZone::associatorsGroupComponent" << endl;
#endif

   DNSZONE * all_zones = NULL, * my_zone = NULL ;

   all_zones = getZones();

   if ( all_zones )
     my_zone = findZone(all_zones, aSourceInstanceName.getZoneName()) ;

   if ( !my_zone ) { 
     freeZones(all_zones);
//     return;
     throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER, "The specified ResourceRecord's Zone does not exist.");
   }

   if ( ! my_zone->records ) {
     freeZones( all_zones ) ;
//     return;
     throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER, "This ResourceRecord instance does not exist for the Zone specified.");
   }
   else {
     DNSRECORD * records = NULL; 

     for (records = my_zone->records; ((records->recordName) != NULL ); records++ ) { 
        if ( (strcmp(records->recordName,aSourceInstanceName.getName()) != 0) || 
             (strcmp(records->recordType,aSourceInstanceName.getType()) != 0) ||
             (strcmp(records->recordValue,aSourceInstanceName.getValue()) != 0) || 
             (strcmp(records->recordZoneName,aSourceInstanceName.getZoneName()) != 0) ) {
          continue; 
        } 
        else {
          Linux_DnsZoneInstanceName zoneInstName; 
          zoneInstName.setNamespace(aNameSpaceP);
          zoneInstName.setName(my_zone->zoneName);
          zoneInstName.setInstanceID(DEFAULT_INSTANCE_ID);

          Linux_DnsZoneInstance zoneInst; 
          zoneInst.setInstanceName(zoneInstName);
           
          if (my_zone->zoneType) { 
          if (strcmp(my_zone->zoneType,"master") == 0) zoneInst.setType(1);
            else if (strcmp(my_zone->zoneType,"slave") == 0) zoneInst.setType(2);
            else if (strcmp(my_zone->zoneType,"stub") == 0) zoneInst.setType(3);
            else if (strcmp(my_zone->zoneType,"forward") == 0) zoneInst.setType(4);
            else if (strcmp(my_zone->zoneType,"hint") == 0) zoneInst.setType(5);
            else zoneInst.setType(0);
          } 
          else zoneInst.setType(0);

          anInstanceEnumeration.addElement(zoneInst);
          break;  
        }
     }
//     if (records->recordName == NULL) {
//       freeZones(all_zones);
//       throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND, "The ResourceRecord instance is not part of the Zone specified");
//     }
   }       
   freeZones(all_zones);

#ifdef DEBUG
      cout << "exiting Linux_DnsResourceRecordsForZone::associatorsGroupComponent" << endl;
#endif


 }
  
  //----------------------------------------------------------------------------
  
  void Linux_DnsResourceRecordsForZoneResourceAccess::associatorsPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsZoneInstanceName& aSourceInstanceName,
    Linux_DnsResourceRecordInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
      cout << "entering Linux_DnsResourceRecordsForZone::associatorsPartComponent" << endl;
#endif

   DNSZONE * all_zones = NULL, * my_zone = NULL ;

   all_zones = getZones();

   if ( all_zones )
     my_zone = findZone(all_zones, aSourceInstanceName.getName()) ;

   if ( !my_zone ) { 
     freeZones(all_zones);
//     return;
     throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER, "The specified Zone does not exist.");
   }

   if ( my_zone->records ) {
     DNSRECORD * records = NULL ; 
     
     for (records = my_zone->records ; ((records->recordName) != NULL); records++ ) { 
     
        Linux_DnsResourceRecordInstanceName recordInstanceName;

        recordInstanceName.setNamespace(aNameSpaceP);
        recordInstanceName.setName(records->recordName);
        recordInstanceName.setZoneName(records->recordZoneName);
        recordInstanceName.setValue(records->recordValue);
        recordInstanceName.setInstanceID(DEFAULT_INSTANCE_ID); 
        recordInstanceName.setType(records->recordType);
     
        Linux_DnsResourceRecordInstance inst;
        inst.setInstanceName( recordInstanceName );
       
        if (records->recordClass) { 
          if (strcmp(records->recordClass,"IN") == 0 ) inst.setFamily( DNS_RRFAMILY_INTERNET );
          else if (strcmp(records->recordClass,"HS") == 0 ) inst.setFamily( DNS_RRFAMILY_HESIOD ); 
          else if (strcmp(records->recordClass,"CH") == 0 ) inst.setFamily( DNS_RRFAMILY_CHAOS );
          else inst.setFamily( 0 ); 
        }
        else inst.setFamily( DNS_RRFAMILY_UNKNOWN ); 

        if (records->recordTTL && records->recordTTL >= 0)
            inst.setTTL(records->recordTTL);

        anInstanceEnumeration.addElement(inst);
     } 
  }
  freeZones(all_zones);

#ifdef DEBUG
      cout << "exiting Linux_DnsResourceRecordsForZone::associatorsPartComponent" << endl;
#endif


 }
   
  
  // extrinsic methods

	
}


