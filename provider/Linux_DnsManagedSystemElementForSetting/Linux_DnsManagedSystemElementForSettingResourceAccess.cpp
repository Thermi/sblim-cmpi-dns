// =======================================================================
// Linux_DnsManagedSystemElementForSettingResourceAccess.cpp
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
#include "Linux_DnsManagedSystemElementForSettingResourceAccess.h"

#include <string>
#include <list>

using namespace std;

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

#define DNS_ALLOW_NOTIFY_STR	"allow-notify"
#define DNS_ALLOW_QUERY_STR	"allow-query"
#define DNS_ALLOW_TRANSFER_STR	"allow-transfer"
#define DNS_ALLOW_UPDATE_STR	"allow-update"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsManagedSystemElementForSettingResourceAccess::Linux_DnsManagedSystemElementForSettingResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsManagedSystemElementForSettingResourceAccess::~Linux_DnsManagedSystemElementForSettingResourceAccess() { }
    
  // intrinsic methods
  /*
  //----------------------------------------------------------------------------
  void
  Linux_DnsManagedSystemElementForSettingResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration& anInstanceNameEnumeration) {
      
    int instanceNameN = 1;
    for (int x=0; x < instanceNameN; ++x) {
      
      //place here the code retrieving your instanceName
      
      Linux_DnsManagedSystemElementForSettingInstanceName instanceName;
      
    }      
  
  }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsManagedSystemElementForSettingResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration& aManualInstanceEnumeration) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsManagedSystemElementForSettingManualInstance 
  Linux_DnsManagedSystemElementForSettingResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsManagedSystemElementForSettingInstanceName& anInstanceName) {

    Linux_DnsManagedSystemElementForSettingManualInstance manualInstance;

  
  }
  */
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsManagedSystemElementForSettingResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsManagedSystemElementForSettingManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsManagedSystemElementForSettingInstanceName
  Linux_DnsManagedSystemElementForSettingResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsManagedSystemElementForSettingManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsManagedSystemElementForSettingResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsManagedSystemElementForSettingInstanceName& anInstanceName) { }
	*/
	

  // Association Interface
  //----------------------------------------------------------------------------
  /*
  void Linux_DnsManagedSystemElementForSettingResourceAccess::referencesSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsZoneInstanceName& aSourceInstanceName,
    Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration& aManualInstanceEnumeration) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  void Linux_DnsManagedSystemElementForSettingResourceAccess::referencesElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration& aManualInstanceEnumeration) { 
    
    DNSZONE *zones = getZones();
    DNSZONE *zones_ptr = zones;
    
    if ( ! zones)
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
    
    for (; zones->zoneName ; zones++) {
      ZONEOPTS *zopts = zones->zoneOpts;
      while (zopts && zopts->key) {
	if (strcmp(zopts->key, DNS_ALLOW_NOTIFY_STR)   &&
	    strcmp(zopts->key, DNS_ALLOW_QUERY_STR)    &&
	    strcmp(zopts->key, DNS_ALLOW_TRANSFER_STR) && 
	    strcmp(zopts->key, DNS_ALLOW_UPDATE_STR ) )
	  continue;
	
	
	DnsArray da = DnsArray( zopts->value );
	DnsArrayConstIterator iter;
	
	for ( iter = da.begin(); iter != da.end(); ++iter) {
	  if ( strcmp( (*iter).c_str(), sourceInst.getName() ) != 0 )
	    continue;
	  
	  Linux_DnsManagedSystemElementForSettingInstanceName AuInstName;
	  Linux_DnsManagedSystemElementForSettingManualInstance AuInst;
	  Linux_DnsZoneInstance zoneInst;
	  Linux_DnsZoneInstanceName zoneInstName;
	  
	  zoneInstName.setNamespace( nsp );
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
	  
	  AuInstName.setElement( zoneInstName );
	  AuInstName.setSetting( sourceInst );
	  AuInst.setInstanceName( AuInstName );
	  
	  instEnum.addElement( AuInst );
	}
	zopts++;
      }
    }
    freeZones( zones_ptr );
  }
  */

  
  //----------------------------------------------------------------------------
  /*
  void Linux_DnsManagedSystemElementForSettingResourceAccess::associatorsSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsZoneInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  void Linux_DnsManagedSystemElementForSettingResourceAccess::associatorsElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration) { }
  */
   
  
  // extrinsic methods

	
}


