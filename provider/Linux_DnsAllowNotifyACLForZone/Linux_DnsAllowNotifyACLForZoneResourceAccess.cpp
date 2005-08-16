 /**
 * Linux_DnsAllowNotifyACLForZoneResourceAccess.cpp
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
#include "Linux_DnsAllowNotifyACLForZoneResourceAccess.h"

#define DNS_ATTR_STR	"allow-notify"

namespace genProvider {
  
    //Linux_DnsAllowNotifyACLForZoneResourceAccess::Linux_DnsAllowNotifyACLForZoneResourceAccess();
    Linux_DnsAllowNotifyACLForZoneResourceAccess::~Linux_DnsAllowNotifyACLForZoneResourceAccess() { };
    
    /* intrinsic methods */
    
    void Linux_DnsAllowNotifyACLForZoneResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration& instnames){
      
	DNSZONE * zones, *all_zones;

        zones = getZones();
	all_zones = zones;

        if ( ! zones)
		return;
        
        for (; zones->zoneName ; zones++)
        {
		ZONEOPTS *zopts = findOptsInZone(zones,DNS_ATTR_STR);
		if ( ( ! zopts ) || ( !zopts->value ) ) 
			continue;

		DnsArray da = DnsArray( zopts->value );
		DnsArrayConstIterator iter;

		for ( iter = da.begin(); iter != da.end(); ++iter)
		{
			Linux_DnsAllowNotifyACLForZoneInstanceName AuInst;
			Linux_DnsAddressMatchListInstanceName addrList;
			Linux_DnsZoneInstanceName zoneInst;

			AuInst.setNamespace( nsp );
			zoneInst.setNamespace( nsp );	
			addrList.setNamespace( nsp );
	
			zoneInst.setName( zones->zoneName );
	
			addrList.setName( (*iter).c_str() );
			addrList.setServiceName( DEFAULT_SERVICE_NAME );

			AuInst.setSetting( addrList );
			AuInst.setElement( zoneInst );

			instnames.addElement(AuInst); 
		}
      	}
       	freeZones( all_zones );
    }
    
  	
    void Linux_DnsAllowNotifyACLForZoneResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration& instances){
  	 
  	DNSZONE * zones, *all_zones;

        zones = getZones();
	all_zones = zones;

        if ( ! zones)
		return;
        
        for (; zones->zoneName ; zones++)
        {
		ZONEOPTS *zopts = findOptsInZone(zones,DNS_ATTR_STR);
		if ( ( ! zopts ) || ( !zopts->value ) )
			continue;

		DnsArray da = DnsArray( zopts->value );
		DnsArrayConstIterator iter;

		for ( iter = da.begin(); iter != da.end(); ++iter)
		{
			Linux_DnsAllowNotifyACLForZoneInstanceName AuInstName;
			Linux_DnsAllowNotifyACLForZoneManualInstance AuInst;
			Linux_DnsAddressMatchListInstanceName addrList;
			Linux_DnsZoneInstanceName zoneInst;

			AuInstName.setNamespace( nsp );
			zoneInst.setNamespace( nsp );	
			addrList.setNamespace( nsp );
	
			zoneInst.setName( zones->zoneName );
	
			addrList.setName( (*iter).c_str() );
			addrList.setServiceName( DEFAULT_SERVICE_NAME );

			AuInstName.setSetting( addrList );
			AuInstName.setElement( zoneInst );
			AuInst.setInstanceName( AuInstName );
			
			instances.addElement(AuInst); 
		}
      	}
	freeZones( all_zones );
   };
  	
  	
    Linux_DnsAllowNotifyACLForZoneManualInstance 
     Linux_DnsAllowNotifyACLForZoneResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsAllowNotifyACLForZoneInstanceName& instanceName){

	Linux_DnsAllowNotifyACLForZoneManualInstance AuInst;
        AuInst.setInstanceName( instanceName );
	return AuInst;
      
    }
  	
/*
    void Linux_DnsAllowNotifyACLForZoneResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsAllowNotifyACLForZoneManualInstance&){};
*/
    void Linux_DnsAllowNotifyACLForZoneResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsAllowNotifyACLForZoneManualInstance& anInstance){
	DNSZONE *zones = getZones();
	DNSZONE *zone;
	
		// Find the requested zone. If that does not exist throw an exception
	zone = findZone(zones, anInstance.getInstanceName().getElement().getName() );
	if (!zone)
	{
		throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
	}
	/* Now zone points to the _desired_ zone */
	ZONEOPTS* zopts = findOptsInZone(zone,DNS_ATTR_STR);
	
	DnsArray iplist;
	// If already exist masters put them in the list.
	if (zopts && zopts->value)
	{
		iplist.populate(zopts->value);
		iplist.add( string( anInstance.getInstanceName().getSetting().getName() ) );
		
		free(zopts->value);
		zopts->value = strdup( iplist.toString().c_str() );
	
		updateZones( zones );
		freeZones( zones );
		return;
	}
		
	iplist.add( string(anInstance.getInstanceName().getSetting().getName()) );
	addOptsToZone(zone, DNS_ATTR_STR,  iplist.toString().c_str());
    	updateZones( zones );
	freeZones( zones ); 
     };

    void Linux_DnsAllowNotifyACLForZoneResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsAllowNotifyACLForZoneInstanceName& anInstanceName){
     
        DNSZONE *zones = getZones();
	DNSZONE *zone;
	
	// Find the requested zone. If that does not exist throw an exception
	zone = findZone(zones, anInstanceName.getElement().getName() );
	if (!zone)
	{
		throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
	}
	/* Now zone points to the _desired_ zone */
	ZONEOPTS* zopts = findOptsInZone(zone,DNS_ATTR_STR);
	
	DnsArray iplist;
	// If already exist masters put them in the list.
	if (zopts && zopts->value)
	{
		iplist.populate(zopts->value);
		
		iplist.remove( string( anInstanceName.getSetting().getName() ) );
		free(zopts->value);
		zopts->value = strdup( iplist.toString().c_str() );
	
		updateZones( zones );
		freeZones( zones );
		return;
	}
     };

    
    /* Association Interface */
	void Linux_DnsAllowNotifyACLForZoneResourceAccess::referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration& instEnum) {
    
	cout << "Linux_DnsAllowNotifyACLForZoneResourceAccess::referencesElement()" << endl;

	DNSZONE *zones = getZones();
	DNSZONE *all_zones = zones;
	
        if ( ! zones)
		throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
        
        for (; zones->zoneName ; zones++)
        {
		ZONEOPTS *zopts = findOptsInZone(zones,DNS_ATTR_STR);
		if ( ( ! zopts ) || ( !zopts->value ) )
			continue;

		DnsArray da = DnsArray( zopts->value );
		DnsArrayConstIterator iter;

		for ( iter = da.begin(); iter != da.end(); ++iter)
		{
			if ( strcmp( (*iter).c_str(), sourceInst.getName() ) != 0 )
				continue;
		
			Linux_DnsAllowNotifyACLForZoneInstanceName AuInstName;
			Linux_DnsAllowNotifyACLForZoneManualInstance AuInst;
			
			// AddressMatchList -> Setting
			/*Linux_DnsAddressMatchListInstance addrList;
			addrList.setInstanceName( sourceInst );
			char *aclValue = getACL(list_acl, (*iter).c_str());
			if ( ! aclValue )
				continue;
				
			DnsArray aclArray = DnsArray( aclValue );
			addrList.setAddressList( aclArray.toArray(), aclArray.size() );*/
			//
			
			// Zone -> Element
			Linux_DnsZoneInstance zoneInst;
			Linux_DnsZoneInstanceName zoneInstName;
			
			zoneInstName.setNamespace( nsp );
                	zoneInstName.setName( zones->zoneName );
			zoneInst.setInstanceName( zoneInstName );
			
			if 	( strcmp(zones->zoneType, "master") == 0 )
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
			//
			AuInstName.setNamespace( nsp );
			AuInstName.setElement( zoneInstName );
			AuInstName.setSetting( sourceInst );
			AuInst.setInstanceName( AuInstName );
			
			instEnum.addElement( AuInst );
		}
      	}
	freeZones( all_zones );
    };


	void Linux_DnsAllowNotifyACLForZoneResourceAccess::referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration& instEnum) {
     
     	cout << "Linux_DnsAllowNotifyACLForZoneResourceAccess::referencesSetting()" << endl;
	
	DNSZONE *zones = getZones();
	DNSZONE *all_zones = zones;
	
        if ( ! zones)
		throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
        
        for (; zones->zoneName ; zones++)
        {
		if ( strcmp( zones->zoneName, sourceInst.getName() ) != 0 )
			continue;
	
		ZONEOPTS *zopts = findOptsInZone(zones,DNS_ATTR_STR);
		if ( ( ! zopts ) || ( !zopts->value ) )
			continue;

		DnsArray da = DnsArray( zopts->value );
		DnsArrayConstIterator iter;
	
		for ( iter = da.begin(); iter != da.end(); ++iter)
		{
				
			Linux_DnsAllowNotifyACLForZoneManualInstance AuInst;
			Linux_DnsAllowNotifyACLForZoneInstanceName AuInstName;
				
			// AddressMatchList -> Setting
			Linux_DnsAddressMatchListInstance addrList;
			Linux_DnsAddressMatchListInstanceName addrListName;
			addrListName.setNamespace( nsp );
			addrListName.setName( (*iter).c_str() );
			addrListName.setServiceName( DEFAULT_SERVICE_NAME );
			/* addrList.setInstanceName( addrListName );
			char *aclValue = getACL(list_acl, (*iter).c_str());
			if ( ! aclValue )
				continue;
					
			DnsArray aclArray = DnsArray( aclValue );
			addrList.setAddressList( aclArray.toArray(), aclArray.size() ); */
			//
				
			// Zone -> Element
			AuInstName.setNamespace( nsp );
			AuInstName.setElement( sourceInst );
			AuInstName.setSetting( addrListName );
			AuInst.setInstanceName( AuInstName );
			
			instEnum.addElement( AuInst );
		}
	}
	freeZones( all_zones );
          
     };
    
	void Linux_DnsAllowNotifyACLForZoneResourceAccess::associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsZoneInstanceEnumeration& instEnum) { 
     
     	cout << "Linux_DnsAllowNotifyACLForZoneResourceAccess::associatorsElement()" << endl;
 
      	DNSZONE *zones = getZones();
	DNSZONE *all_zones = zones;
	
        if ( ! zones)
		throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
        
        for (; zones->zoneName ; zones++)
        {
		ZONEOPTS *zopts = findOptsInZone(zones,DNS_ATTR_STR);
		if ( ( ! zopts ) || ( !zopts->value ) )
			continue;

		DnsArray da = DnsArray( zopts->value );
		DnsArrayConstIterator iter;

		for ( iter = da.begin(); iter != da.end(); ++iter)
		{
			if ( strcmp( (*iter).c_str(), sourceInst.getName() ) != 0 )
				continue;
				
			// Zone -> Element
			Linux_DnsZoneInstance zoneInst;
			Linux_DnsZoneInstanceName zoneInstName;
			
			zoneInstName.setNamespace( nsp );
                	zoneInstName.setName( zones->zoneName );
			zoneInst.setInstanceName( zoneInstName );
			
			if 	( strcmp(zones->zoneType, "master") == 0 )
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
			//
					
			instEnum.addElement( zoneInst );
		}
	}
	freeZones( all_zones );
     
     };
    

	void Linux_DnsAllowNotifyACLForZoneResourceAccess::associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration& instEnum) {
     
     cout << "Linux_DnsAllowNotifyACLForZoneResourceAccess::associatorsSetting()" << endl;
      
      	DNSZONE *zones = getZones();
	DNSZONE *all_zones = zones;
	ACL *list_acl = ReadACL();
	
        if ( ! zones)
		throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
        
        for (; zones->zoneName && list_acl ; zones++)
        {
		if ( strcmp( zones->zoneName, sourceInst.getName() ) != 0 )
				continue;
		
		ZONEOPTS *zopts = findOptsInZone(zones,DNS_ATTR_STR);
		if ( ( ! zopts ) || ( !zopts->value ) )
			continue;

		DnsArray da = DnsArray( zopts->value );
		DnsArrayConstIterator iter;

		for ( iter = da.begin(); iter != da.end(); ++iter)
		{
			
			// AddressMatchList -> Setting
			Linux_DnsAddressMatchListInstance addrList;
			Linux_DnsAddressMatchListInstanceName addrListName;
			addrListName.setNamespace( nsp );
			addrListName.setName( (*iter).c_str() );
			addrListName.setServiceName( DEFAULT_SERVICE_NAME );
			addrList.setInstanceName( addrListName );
			
			char *aclValue = getACL(list_acl, (*iter).c_str());
			if ( ! aclValue )
				continue;
				
			DnsArray aclArray = DnsArray( aclValue );
			addrList.setAddressList( aclArray.toArray(), aclArray.size() );
			addrList.setAddressListType( DNS_AMLTYPE_AML );
			//
						
			instEnum.addElement( addrList );
		}
	}
	freeZones( all_zones );
	freeACL( list_acl );
     };
    

    /* extrinsic methods */
	
}


