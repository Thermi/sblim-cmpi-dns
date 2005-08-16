 /**
 * Linux_DnsAllowQueryACLForZoneResourceAccess.cpp
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
#include "Linux_DnsAllowQueryACLForZoneResourceAccess.h"

#define DNS_ATTR_STR	"allow-query"

namespace genProvider {
  
    //Linux_DnsAllowQueryACLForZoneResourceAccess::Linux_DnsAllowQueryACLForZoneResourceAccess();
    Linux_DnsAllowQueryACLForZoneResourceAccess::~Linux_DnsAllowQueryACLForZoneResourceAccess() { };
    
    /* intrinsic methods */
    
    void Linux_DnsAllowQueryACLForZoneResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsAllowQueryACLForZoneInstanceNameEnumeration& instnames){
      
      	DNSZONE * zones, all_zones;

        zones = getZones();

        if ( ! zones)
		return;
        
        for (; zones->zoneName  ; zones++)
        {
		ZONEOPTS *zopts = findOptsInZone(zones,DNS_ATTR_STR);
		if ( ( ! zopts ) || ( !zopts->value ) )
			continue;

		DnsArray da = DnsArray( zopts->value );
		DnsArrayConstIterator iter;

		for ( iter = da.begin(); iter != da.end(); ++iter)
		{
			Linux_DnsAllowQueryACLForZoneInstanceName AuInst;
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
	freeZones( zones );    
    }
    
  	
    void Linux_DnsAllowQueryACLForZoneResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration& instances){
	 
	DNSZONE * zones, *all_zones;
	
	zones = getZones();
	all_zones = zones;

        if ( ! zones)
		return;
        
        for (; zones->zoneName  ; zones++)
        {
		ZONEOPTS *zopts = findOptsInZone(zones,DNS_ATTR_STR);
		if ( ( ! zopts ) || ( !zopts->value ) )
			continue;

		DnsArray da = DnsArray( zopts->value );
		DnsArrayConstIterator iter;

		for ( iter = da.begin(); iter != da.end(); ++iter)
		{
			Linux_DnsAllowQueryACLForZoneInstanceName AuInstName;
			Linux_DnsAllowQueryACLForZoneManualInstance AuInst;
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
	freeZones( zones ); 
    };
  	
  	
    Linux_DnsAllowQueryACLForZoneManualInstance 
     Linux_DnsAllowQueryACLForZoneResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsAllowQueryACLForZoneInstanceName& instanceName){

     	Linux_DnsAllowQueryACLForZoneManualInstance AuInst;
        AuInst.setInstanceName( instanceName );
	return AuInst;
           
    }
  	
  	/*
    void Linux_DnsAllowQueryACLForZoneResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsAllowQueryACLForZoneManualInstance&){};
  	*/
  	
    void Linux_DnsAllowQueryACLForZoneResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsAllowQueryACLForZoneManualInstance& anInstance){
	cout << "Linux_DnsAllowQueryACLForZoneResourceAccess::createInstance()" << endl;

   	DNSZONE *zones = getZones();
	DNSZONE *zone;
     
     // Find the requested zone. If that does not exist throw an exception
	zone = findZone(zones, anInstance.getInstanceName().getElement().getName() );
	if ( ! zone )
	{
		throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
	}
	/* Now zone points to the _desired_ zone */
	ZONEOPTS* zopts = findOptsInZone(zone,DNS_ATTR_STR);
	
	DnsArray iplist;
	// If already exist masters put them in the list.
	if (zopts)
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
  	
  	
    void Linux_DnsAllowQueryACLForZoneResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsAllowQueryACLForZoneInstanceName& anInstanceName){
     
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
	if (zopts)
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
    
    void Linux_DnsAllowQueryACLForZoneResourceAccess::referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration& instEnum) {
     
	cout << "Linux_DnsAllowQueryACLForZoneResourceAccess::referencesElement()" << endl;

	DNSZONE *zones = getZones();
	DNSZONE *all_zones = zones;
	
        if ( ! zones)
		throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
        
        for (; zones->zoneName  ; zones++)
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
		
			Linux_DnsAllowQueryACLForZoneInstanceName AuInstName;
			Linux_DnsAllowQueryACLForZoneManualInstance AuInst;
			
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
    
    
    void Linux_DnsAllowQueryACLForZoneResourceAccess::referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration& instEnum) {

	cout << "Linux_DnsAllowQueryACLForZoneResourceAccess::referencesSetting()" << endl;
	
	// ACL *list_acl = ReadACL();
	DNSZONE *zones = getZones();
	DNSZONE *all_zones = zones;
	
        if ( ! zones)
		throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
        
        for (; zones->zoneName  ; zones++)
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
			
			Linux_DnsAllowQueryACLForZoneManualInstance AuInst;
			Linux_DnsAllowQueryACLForZoneInstanceName AuInstName;
			
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
			AuInstName.setElement( sourceInst );
			AuInstName.setSetting( addrListName );
			AuInst.setInstanceName( AuInstName );
			
			instEnum.addElement( AuInst );
		}
	}
	freeZones( all_zones );
   };
    
    
    void Linux_DnsAllowQueryACLForZoneResourceAccess::associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsZoneInstanceEnumeration& instEnum) {
      
	cout << "Linux_DnsAllowQueryACLForZoneResourceAccess::associatorsElement()" << endl;
 
      	DNSZONE *zones = getZones();
	DNSZONE *all_zones = zones;
	
	
        if ( ! zones)
		throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");
        
        for (; zones->zoneName  ; zones++)
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
    
    
    void Linux_DnsAllowQueryACLForZoneResourceAccess::associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration& instEnum) {
     	cout << "Linux_DnsAllowQueryACLForZoneResourceAccess::associatorsSetting()" << endl;
      
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
						
			instEnum.addElement( addrList );
		}
	}
	freeZones( all_zones );
     };
    
   
    /* extrinsic methods */
	
}


