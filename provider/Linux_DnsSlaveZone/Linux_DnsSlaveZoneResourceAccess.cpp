// =======================================================================
// Linux_DnsSlaveZoneResourceAccess.cpp
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
#include "Linux_DnsSlaveZoneResourceAccess.h"

#include <iostream>

using namespace std;

#include "smt_dns_ra_support.h"
#include "smt_dns_valuemap.h"
#include "smt_dns_defaultvalues.h"


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
    anInstanceName.setInstanceID(DEFAULT_INSTANCE_ID);

  }

  //----------------------------------------------------------------------------

  static void setInstanceProperties(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      DNSZONE * zone,
      const Linux_DnsSlaveZoneInstanceName& anInstanceName,
      Linux_DnsSlaveZoneManualInstance& aManualInstance) {

    aManualInstance.setInstanceName(anInstanceName);

    //ZONEOPTS* zoneOpts;
    ZONEOPTS * forward = findOptsInZone( zone, "forward" );
    if ( forward ) {
      if ( strcmp( forward->value, "first" )==0 )
        aManualInstance.setForward( DNS_FORWARD_FIRST );
      else if ( strcmp( forward->value, "only" )==0 )
        aManualInstance.setForward( DNS_FORWARD_ONLY );
      else
        aManualInstance.setForward( DNS_FORWARD_UNKNOWN );
    }

    aManualInstance.setType(DNS_ZONETYPE_SLAVE);

    aManualInstance.setZoneFile(zone->zoneFileName);
    if (zone->zoneTTL && zone->zoneTTL >= 0)
      aManualInstance.setTTL(zone->zoneTTL);

/*    aManualInstance.setContact(zone->soaContact);

    char *val = (char *) malloc( 12*sizeof(char) );
    sprintf(val,"%lld", zone->soaSerialNumber );
    aManualInstance.setSerialNumber( val );
    free(val);

    aManualInstance.setRefresh( zone->soaRefresh );
    aManualInstance.setRetry( zone->soaRetry );
    aManualInstance.setExpire( zone->soaExpire );
    aManualInstance.setServer( zone->soaServer );
    aManualInstance.setNegativeCachingTTL( zone->soaNegativeCachingTTL ); */
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

     DNSZONE *zones = NULL, *all_zones = NULL;

     zones = getZones();
     all_zones = zones;

     if (zones) {
       for ( ;zones->zoneName != NULL; zones++) {
          if ( strcmp(zones->zoneType,"slave")!=0 )
            continue;

          Linux_DnsSlaveZoneInstanceName instanceName;

          setInstanceNameProperties(aContext, aBroker, aNameSpaceP, zones, instanceName);
          anInstanceNameEnumeration.addElement(instanceName);
       }
       free(all_zones);
     }

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

    DNSZONE * zones = NULL, *all_zones = NULL;

    zones = getZones();         //getZonesByType("slave");
    all_zones = zones;

    if (zones) {
      for (; zones->zoneName != NULL ; zones++) {
        if ( strcmp(zones->zoneType, "slave")!=0 )
          continue;

        Linux_DnsSlaveZoneManualInstance instance;
        Linux_DnsSlaveZoneInstanceName instanceName;

        setInstanceNameProperties(aContext, aBroker, aNameSpaceP, zones, instanceName);
        setInstanceProperties(aContext, aBroker, zones, instanceName, instance);
        aManualInstanceEnumeration.addElement(instance);
      }
      freeZones( all_zones );
    }

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

    DNSZONE *zones = NULL, *myZone = NULL;

    Linux_DnsSlaveZoneManualInstance instance;

    zones = getZones();
    if ( !zones ) {
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"There are no zones.");
    }

    myZone = findZone(zones,anInstanceName.getName());

    if ( ! myZone ) {
      freeZones(zones);
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");
    }

    if ( strcmp(myZone->zoneType,"slave")!= 0) {
      freeZones(zones);
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"The specified ZoneType is not a slave");
    }

    setInstanceProperties(aContext, aBroker, myZone, anInstanceName, instance);

    freeZones( zones );

#ifdef DEBUG
    cout << "exiting Linux_DnsSlaveZone::getInstance" << endl;
#endif
    return instance;
  
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

    DNSZONE *zones = NULL,  *myZone = NULL;

    zones = getZones();
    if ( ! zones ) {
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"There are no Zones.");
    }

    myZone = findZone(zones, aManualInstance.getInstanceName().getName());

    if ( ! myZone )
    {
      freeZones(zones);
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"The specified Zone does not exist");
    }

    if ( strcmp(myZone->zoneType,"slave") != 0 ) {
      freeZones(zones);
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The specified ZoneType is not a slave");
    }

    if ( aManualInstance.isZoneFileSet() ) {
      free(myZone->zoneFileName);
      myZone->zoneFileName = strdup(aManualInstance.getZoneFile());

      ZONEOPTS *zopts = findOptsInZone( myZone, "file" );

        char * buffer = NULL;
        buffer = (char *)calloc((strlen(myZone->zoneFileName)+3),sizeof(char));
        strcat(buffer,"\"");
        strcat(buffer,myZone->zoneFileName);
        strcat(buffer,"\"");

      if ( zopts ) {
        free( zopts->value );
        zopts->value =  strdup(buffer) ;
      }
      else {
        addOptsToZone(myZone, "file", buffer);
      }
      free(buffer);
    }

    if (aManualInstance.isTTLSet() && !CmpiData(aManualInstance.getTTL()).isNullValue() ) {
       myZone->zoneTTL = aManualInstance.getTTL();
    } else {
       myZone->zoneTTL = -1;
    }

/*    if (aManualInstance.isContactSet()) {
      free(myZone->soaContact);
      myZone->soaContact = strdup( aManualInstance.getContact() );
    }

    if (aManualInstance.isServerSet()) {
      free(myZone->soaServer);
      myZone->soaServer = strdup( aManualInstance.getServer() );
    }
*/
    ZONEOPTS *zopts = findOptsInZone( myZone, "forward" );
    if ( aManualInstance.isForwardSet() && !CmpiData(aManualInstance.getForward()).isNullValue() && aManualInstance.getForward()!=0) {
      if ( zopts ) {
        free( zopts->value );
        if ( aManualInstance.getForward() == DNS_FORWARD_ONLY )
          zopts->value = strdup( "only" );

        else if ( aManualInstance.getForward() == DNS_FORWARD_FIRST )
          zopts->value = strdup( "first" );

      } else {
        if ( aManualInstance.getForward() == DNS_FORWARD_ONLY )
          addOptsToZone( myZone, "forward", "only" );

        else if ( aManualInstance.getForward() == DNS_FORWARD_FIRST )
          addOptsToZone( myZone, "forward", "first" );
      }
    } else {
        if(zopts) {
            delOptsFromZone(myZone, "forward");
        }
    }
/*
    // SerialNumber
    if (aManualInstance.isSerialNumberSet())
      myZone->soaSerialNumber = atoi(aManualInstance.getSerialNumber());

    // Refresh
    if (aManualInstance.isRefreshSet())
      myZone->soaRetry = aManualInstance.getRetry();

    // Expire
    if (aManualInstance.isExpireSet())
      myZone->soaExpire = aManualInstance.getExpire();

    // NegativeCachingTTL
    if (aManualInstance.isNegativeCachingTTLSet())
      myZone->soaNegativeCachingTTL = aManualInstance.getNegativeCachingTTL();
*/
    updateZones(zones);

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

    if (aManualInstance.isTypeSet() && aManualInstance.getType() != DNS_ZONETYPE_SLAVE) {
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"Zone Type is invalid");
    }

    DNSZONE * all_zones = getZones();

    if (all_zones) {
      if ( findZone(all_zones,anInstanceName.getName()) ) {
        freeZones(all_zones);
        throw CmpiStatus(CMPI_RC_ERR_ALREADY_EXISTS,"The zone already exist");
      }
      freeZones(all_zones);
    }

    newZone = (DNSZONE *)calloc(1+1,sizeof(DNSZONE));

    if (newZone) {
      // Take in value specified only at Dialog ??//

      newZone->zoneName = strdup((char *)anInstanceName.getName());

      newZone->zoneType = strdup("slave");
      addOptsToZone( newZone, "type", "slave" );

      if (aManualInstance.isZoneFileSet()) {
        newZone->zoneFileName = strdup(aManualInstance.getZoneFile());
      } else {
        char * buffer;
        buffer = (char *)calloc((strlen(newZone->zoneType)+strlen(newZone->zoneName)+2),sizeof(char));
        strcat(buffer, newZone->zoneType);
        strcat(buffer, "/");
        strcat(buffer, newZone->zoneName);
        newZone->zoneFileName = buffer;
      }
      if (newZone->zoneFileName) {
        char * buffer = NULL ;
        buffer = (char *)calloc((strlen(newZone->zoneFileName)+3),sizeof(char));
        strcat(buffer,"\"");
        strcat(buffer,newZone->zoneFileName);
        strcat(buffer,"\"");
        addOptsToZone( newZone, "file", buffer );
        free(buffer);
      }

      if (aManualInstance.isTTLSet())
        newZone->zoneTTL = aManualInstance.getTTL();

/*
      // Contact
      if (aManualInstance.isContactSet())
        newZone->soaContact = strdup((char *)aManualInstance.getContact());
      else
        newZone->soaContact = strdup("root");

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
*/
      if ( aManualInstance.isForwardSet() ) {
        if ( aManualInstance.getForward() == DNS_FORWARD_ONLY )
          addOptsToZone( newZone, "forward", "only" );

        else if ( aManualInstance.getForward() == DNS_FORWARD_FIRST )
          addOptsToZone( newZone, "forward", "first" );
      }
/*
      // NegativeCachingTTL
      if (aManualInstance.isNegativeCachingTTLSet())
        newZone->soaNegativeCachingTTL = aManualInstance.getNegativeCachingTTL();
      else
        newZone->soaNegativeCachingTTL = 0;

      if (aManualInstance.isServerSet())
        newZone->soaServer = strdup( aManualInstance.getServer() );
      else
        newZone->soaServer = strdup("@");
*/
      newZone->records = NULL;

      DNSZONE * returnedZones = NULL;

      returnedZones = addZone(newZone, NULL);

      if (!returnedZones) {
        freeZones(newZone);
        throw CmpiStatus(CMPI_RC_ERR_FAILED,"addZone() failed");
      }

      freeZones( returnedZones );
      freeZones(newZone);
    }
    else {
       throw CmpiStatus(CMPI_RC_ERR_FAILED,"Failed to create the specified zone.");
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

    DNSZONE * all_zones = NULL, * zone = NULL ;

    all_zones = getZones();
    if ( !all_zones )  {
      throw CmpiStatus(CMPI_RC_ERR_FAILED,"There are no zones.");
    }

    zone = findZone(all_zones,anInstanceName.getName());

    if ( ! zone ) {
      freeZones(all_zones);
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");
    }

    if ( strcmp(zone->zoneType,"slave")==0 ) {
      if (deleteZone( anInstanceName.getName() )) {
        freeZones(all_zones);
        throw CmpiStatus(CMPI_RC_ERR_FAILED,"An error occured while trying to delete the zone");
      }
      freeZones(all_zones);
    }
    else {
      freeZones(all_zones);
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"The specified ZoneType is not a slave");
    }

#ifdef DEBUG
    cout << "exiting Linux_DnsSlaveZone::deleteInstance" << endl;
#endif

  }
	
	

  
  // extrinsic methods

	
}


