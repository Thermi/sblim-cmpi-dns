// =======================================================================
// Linux_DnsResourceRecordInZoneResourceAccess.cpp
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
#include "Linux_DnsResourceRecordInZoneResourceAccess.h"

#include <string>
#include <list>

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsResourceRecordInZoneResourceAccess::Linux_DnsResourceRecordInZoneResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsResourceRecordInZoneResourceAccess::~Linux_DnsResourceRecordInZoneResourceAccess() { }
    
  // intrinsic methods
  /*
  //----------------------------------------------------------------------------
  void
  Linux_DnsResourceRecordInZoneResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsResourceRecordInZoneInstanceNameEnumeration& anInstanceNameEnumeration) {
      
    int instanceNameN = 1;
    for (int x=0; x < instanceNameN; ++x) {
      
      //place here the code retrieving your instanceName
      
      Linux_DnsResourceRecordInZoneInstanceName instanceName;
      
    }      
  
  }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsResourceRecordInZoneResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsResourceRecordInZoneManualInstanceEnumeration& aManualInstanceEnumeration) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsResourceRecordInZoneManualInstance 
  Linux_DnsResourceRecordInZoneResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsResourceRecordInZoneInstanceName& anInstanceName) {

    Linux_DnsResourceRecordInZoneManualInstance manualInstance;

  
  }
  */
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsResourceRecordInZoneResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsResourceRecordInZoneManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsResourceRecordInZoneInstanceName
  Linux_DnsResourceRecordInZoneResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsResourceRecordInZoneManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsResourceRecordInZoneResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsResourceRecordInZoneInstanceName& anInstanceName) { }
	*/
	

  // Association Interface
  //----------------------------------------------------------------------------

  void Linux_DnsResourceRecordInZoneResourceAccess::referencesPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsZoneInstanceName& aSourceInstanceName,
    Linux_DnsResourceRecordInZoneManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
      cout << "entering Linux_DnsResourceRecordInZone::referencesPartComponent" << endl;
#endif

    DNSZONE * zones = NULL;
    
    zones = getZones();
    
    if (zones) {
      for (; ((zones->zoneName) != NULL) ; zones++) {
	if ( strcmp(zones->zoneName, aSourceInstanceName.getName()) !=0 )
	  continue;
	
	if (zones->records) {
	  DNSRECORD * records = NULL;
	  
	  for (records = zones->records; ((records->recordName) != NULL); ++records) {				
	    Linux_DnsResourceRecordInstanceName recordInstanceName;
	    recordInstanceName.setNamespace(aNameSpaceP);
	    recordInstanceName.setName(records->recordName);
	    recordInstanceName.setZoneName(zones->zoneName);
	    
	    if (strcmp(records->recordType,"NS") == 0) {
	      recordInstanceName.setType(3);

	    } else if (strcmp(records->recordType,"A") == 0) {
	      recordInstanceName.setType(6);

	    } else if (strcmp(records->recordType,"MX") == 0) {
	      recordInstanceName.setType(4);
	      
	    } else {
	      recordInstanceName.setType(6);  // = Type A 
	    }
	    
	    recordInstanceName.setValue(records->recordValue); 
	    
	    Linux_DnsResourceRecordInZoneManualInstance inst;
	    Linux_DnsResourceRecordInZoneInstanceName instName;
	    instName.setNamespace( aNameSpaceP );
	    instName.setGroupComponent( aSourceInstanceName );
	    instName.setPartComponent( recordInstanceName );
	    inst.setInstanceName( instName );
	    
	    aManualInstanceEnumeration.addElement(inst);
	  }
	}
      }
    }

#ifdef DEBUG
      cout << "exiting Linux_DnsResourceRecordInZone::referencesPartComponent" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsResourceRecordInZoneResourceAccess::referencesGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsResourceRecordInstanceName& aSourceInstanceName,
    Linux_DnsResourceRecordInZoneManualInstanceEnumeration& aManualInstanceEnumeration) {
    
              
#ifdef DEBUG
      cout << "entering Linux_DnsResourceRecordInZone::referencesGroupComponent" << endl;
#endif

    DNSZONE * zones = NULL;
    
    zones = getZones();
    
    if (zones) {
      for (; ((zones->zoneName) != NULL) ; zones++) {
	if ( strcmp(zones->zoneName, aSourceInstanceName.getZoneName()) !=0 )
	  continue;
	
	if (zones->records) {
	  DNSRECORD * records = NULL;
	  
	  for (records = zones->records; ((records->recordName) != NULL); ++records) {
	    if ( strcmp(records->recordName, aSourceInstanceName.getName() ) !=0 )
	      continue;
	    
	    Linux_DnsZoneInstanceName zoneInstName;
	    zoneInstName.setNamespace(aNameSpaceP);
	    zoneInstName.setName(zones->zoneName);
	    
	    Linux_DnsResourceRecordInZoneManualInstance inst;
	    Linux_DnsResourceRecordInZoneInstanceName instName;
	    instName.setNamespace( aNameSpaceP );
	    instName.setGroupComponent( zoneInstName );
	    instName.setPartComponent( aSourceInstanceName );
	    inst.setInstanceName( instName );
	    
	    aManualInstanceEnumeration.addElement(inst);
	  }
	}
      }
    }

#ifdef DEBUG
      cout << "exiting Linux_DnsResourceRecordInZone::referencesGroupComponent" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsResourceRecordInZoneResourceAccess::associatorsPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsZoneInstanceName& aSourceInstanceName,
    Linux_DnsResourceRecordInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
      cout << "entering Linux_DnsResourceRecordInZone::associatorsPartComponent" << endl;
#endif

    DNSZONE * zones = NULL;
    
    zones = getZones();
    
    if (zones) {
      for (; ((zones->zoneName) != NULL) ; zones++) {
	if ( strcmp(zones->zoneName, aSourceInstanceName.getName()) !=0 )
	  continue;
	
	if (zones->records) {
	  DNSRECORD * records = NULL;
	  
	  for (records = zones->records; ((records->recordName) != NULL); ++records) {				
	    Linux_DnsResourceRecordInstanceName recordInstanceName;
	    recordInstanceName.setNamespace(aNameSpaceP);
	    recordInstanceName.setName(records->recordName);
	    recordInstanceName.setZoneName(zones->zoneName);
	    
	    if (strcmp(records->recordType,"NS") == 0) {
	      recordInstanceName.setType(3);

	    } else if (strcmp(records->recordType,"A") == 0) {
	      recordInstanceName.setType(6);
	      
	    } else if (strcmp(records->recordType,"MX") == 0) {
	      recordInstanceName.setType(4);
	      
	    } else {
	      recordInstanceName.setType(6);  // = Type A 
	    }
	    
	    recordInstanceName.setValue(records->recordValue); 
	    
	    Linux_DnsResourceRecordInstance inst;
	    inst.setInstanceName( recordInstanceName );
	    inst.setFamily( DNS_RRFAMILY_INTERNET );
	    
	    anInstanceEnumeration.addElement(inst);
	  }
	}
      }
    }

#ifdef DEBUG
      cout << "exiting Linux_DnsResourceRecordInZone::associatorsPartComponent" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsResourceRecordInZoneResourceAccess::associatorsGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsResourceRecordInstanceName& aSourceInstanceName,
    Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
      cout << "entering Linux_DnsResourceRecordInZone::associatorsGroupComponent" << endl;
#endif

    DNSZONE * zones = NULL;
    
    zones = getZones();
    
    if (zones) {
      for (; ((zones->zoneName) != NULL) ; zones++) {
	if ( strcmp(zones->zoneName, aSourceInstanceName.getZoneName()) !=0 )
	  continue;
	
	if (zones->records) {
	  DNSRECORD * records = NULL;
	  
	  for (records = zones->records; ((records->recordName) != NULL); ++records) {
	    if ( strcmp(records->recordName, aSourceInstanceName.getName() ) !=0 )
	      continue;
	    
	    Linux_DnsZoneInstanceName zoneInstName;
	    zoneInstName.setNamespace(aNameSpaceP);
	    zoneInstName.setName(zones->zoneName);
	    
	    Linux_DnsZoneInstance inst;
	    inst.setInstanceName( zoneInstName );
	    
	    anInstanceEnumeration.addElement(inst);
	  }
	}
      }
    }
#ifdef DEBUG
      cout << "exiting Linux_DnsResourceRecordInZone::associatorsGroupComponent" << endl;
#endif
  }

   
  
  // extrinsic methods

	
}


