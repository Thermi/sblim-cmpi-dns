 /**
 * Linux_DnsIPAddressResourceAccess.cpp
 *
 * (C) Copyright IBM Corp. 2005
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Common Public License from
 * http://www.opensource.org/licenses/cpl1.0.php
 *
 * author:     Murillo Bernardes <bernarde@br.ibm.com>
 *
 * Contributors:
 *
 */
#include <iostream>
#include <string>
#include <list>


#include "Linux_DnsIPAddressResourceAccess.h"

namespace genProvider {

    //Linux_DnsIPAddressResourceAccess::Linux_DnsIPAddressResourceAccess();
    Linux_DnsIPAddressResourceAccess::~Linux_DnsIPAddressResourceAccess() { };
    
    /* intrinsic methods */
    
    void Linux_DnsIPAddressResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsIPAddressInstanceNameEnumeration& instnames){
	
	DNSZONE *zones = getZones();

        while (zones && zones->zoneName)
        {
		if ( strcmp(zones->zoneType,"slave") )
		{
			zones++;
			continue;
		}

                ZONEOPTS *zopts = findOptsInZone(zones,"masters");

                if (zopts && zopts->key && zopts->value )
                {
			DnsArray iplist = DnsArray(zopts->value);
			DnsArrayConstIterator iter; 

                        for ( iter = iplist.begin(); iter != iplist.end(); ++iter )
                        {
                                Linux_DnsIPAddressInstanceName anInstanceName;

                                anInstanceName.setNamespace(nsp);
                                anInstanceName.setZoneName(zones->zoneName);
                                anInstanceName.setIPAddress( (*iter).c_str() );

                                instnames.addElement(anInstanceName);
                        }
                }
                zones++;
        }
  
    }
    
  	
    void Linux_DnsIPAddressResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsIPAddressManualInstanceEnumeration& instances){
		
	DNSZONE *zones = getZones();
	
	while (zones && zones->zoneName)
	{
		if ( strcmp(zones->zoneType,"slave") )
		{
			zones++;
                        continue;
		}

        	ZONEOPTS *zopts = findOptsInZone(zones,"masters");
        	
		if (zopts)
		{
			DnsArray iplist = DnsArray(zopts->value);
			DnsArrayConstIterator iter; 
                	
			for ( iter = iplist.begin(); iter != iplist.end(); ++iter )
                       	{
				Linux_DnsIPAddressInstanceName anInstanceName;
				Linux_DnsIPAddressManualInstance aManualInstance;
	
				anInstanceName.setNamespace(nsp);
				anInstanceName.setZoneName(zones->zoneName);
				anInstanceName.setIPAddress( (*iter).c_str() );
				aManualInstance.setInstanceName(anInstanceName);

				instances.addElement(aManualInstance);
			}
        	}
		zones++;
	}
    };
  	
  	
    /* Linux_DnsIPAddressManualInstance 
     Linux_DnsIPAddressResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsIPAddressInstanceName&){
      Linux_DnsIPAddressManualInstance instance;
      
    }*/
  	
  	/* We don't need that, because all the attributes we can modify are not supported by RA layer.
    void Linux_DnsIPAddressResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsIPAddressManualInstance& newInstance){
     
        DNSZONE *zones = getZonesByType("slave");
	
	while (zones && zones->zoneName)
	{
		if ( strcmp(zone->zoneName, newInstance.getName()) != 0)
			continue;
	
        	ZONEOPTS *zopts = findOptsInZone(zones,"masters");
        	
		if (zopts)
		{
			DnsArray iplist = DnsArray(zopts->value);
			
			if ( iplist.isPresent( string( anInstanceName.getIPAddress() ) )	)
                     		throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"This Master server already exist!");
			
			// put the just created in the list
			iplist.add( string(newInstance.getIPAddress()) );
	
			// Save them in the configuration file.
			addMasters(zones, anInstanceName.getZoneName(), iplist.toString().c_str() );
	
		}
		zones++;
	}
     
     }; */
  	
  	
    void Linux_DnsIPAddressResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsIPAddressManualInstance& aManualInstance){

	Linux_DnsIPAddressInstanceName anInstanceName = aManualInstance.getInstanceName();

	DNSZONE *zones = getZones();
	DNSZONE *zone;

	// Find the requested zone. If that does not exist throw an exception
	zone = findZone(zones,anInstanceName.getZoneName());
	if (!zone)
	{
		throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
	}
	/* Now zone points to the _desired_ zone */
	ZONEOPTS* zopts = findOptsInZone(zone,"masters");
	
	DnsArray iplist;	
	// If already exist masters put them in the list.
	if (zopts)
	{
		// If the indicated Master server already exist...
		iplist.populate(zopts->value);
	
		if ( iplist.isPresent( string( anInstanceName.getIPAddress() ) )	)
                     throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"This Master server already exist!");
	}
	// put the just created in the list
	iplist.add( string(anInstanceName.getIPAddress()) );
	
	// Save them in the configuration file.
	addMasters(zones, anInstanceName.getZoneName(), iplist.toString().c_str() );
    };
  	
  	
    void Linux_DnsIPAddressResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsIPAddressInstanceName& anInstanceName){

	
	DNSZONE *zones = getZones();
	DNSZONE *zone;

	// Find the requested zone. If that does not exist throw an exception
	zone = findZone(zones,anInstanceName.getZoneName());
	if (!zone)
	{
		throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
	}
	/* Now zone points to the _desired_ zone */
	ZONEOPTS* zopts = findOptsInZone(zone,"masters");
	
	DnsArray iplist;
	// If already exist masters put them in the list.
	if (zopts)
	{
		iplist.populate(zopts->value);
		
		iplist.remove( string(anInstanceName.getIPAddress()) );
	}
	// Save them in the configuration file.
	addMasters(zones, anInstanceName.getZoneName(), iplist.toString().c_str() );
    };
	
    
    /* extrinsic methods */
    /*
    virtual CMPIUint32 Linux_DnsIPAddressResourceAccess::ApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsIPAddressInstanceName&,
      const CIM_CollectionOfMSEsInstanceName &Collection,
      int isCollectionPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CMPIBoolean &ContinueOnError,
      int isContinueOnErrorPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent,
      char** &CanNotApply,
      CMPICount &CanNotApplySize) { };
    */
    /*
    virtual CMPIUint32 Linux_DnsIPAddressResourceAccess::ApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsIPAddressInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent) { };
    */
    /*
    virtual CMPIUint32 Linux_DnsIPAddressResourceAccess::ApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsIPAddressInstanceName&,
      const CIM_CollectionOfMSEsInstanceName &Collection,
      int isCollectionPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CMPIBoolean &ContinueOnError,
      int isContinueOnErrorPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      char** &CanNotApply,
      CMPICount &CanNotApplySize) { };
    */
    /*
    virtual CMPIUint32 Linux_DnsIPAddressResourceAccess::ApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsIPAddressInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent) { };
    */
    /*
    virtual CMPIUint32 Linux_DnsIPAddressResourceAccess::VerifyOKToApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsIPAddressInstanceName&,
      const CIM_CollectionOfMSEsInstanceName &Collection,
      int isCollectionPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent,
      char** &CanNotApply,
      CMPICount &CanNotApplySize) { };
    */
    /*
    virtual CMPIUint32 Linux_DnsIPAddressResourceAccess::VerifyOKToApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsIPAddressInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent) { };
    */
    /*
    virtual CMPIUint32 Linux_DnsIPAddressResourceAccess::VerifyOKToApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsIPAddressInstanceName&,
      const CIM_CollectionOfMSEsInstanceName &Collection,
      int isCollectionPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      char** &CanNotApply,
      CMPICount &CanNotApplySize) { };
    */
    /*
    virtual CMPIUint32 Linux_DnsIPAddressResourceAccess::VerifyOKToApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsIPAddressInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent) { };
    */
	
}
