 /**
 * Linux_DnsMastersOfSlaveZoneResourceAccess.cpp
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
#include "Linux_DnsMastersOfSlaveZoneResourceAccess.h"

namespace genProvider {
  
    //Linux_DnsMastersOfSlaveZoneResourceAccess::Linux_DnsMastersOfSlaveZoneResourceAccess();
    Linux_DnsMastersOfSlaveZoneResourceAccess::~Linux_DnsMastersOfSlaveZoneResourceAccess() { };
    
    /* intrinsic methods */
    /*
    void Linux_DnsMastersOfSlaveZoneResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& instnames){
      
      int numInstanceNames=1;
      for(int i=0;i<numInstanceNames;i++){
      
        //place here the code retrieving your instanceName
      
        Linux_DnsMastersOfSlaveZoneInstanceName instanceName;
        
      }      
    }
    */
  	/*
    void Linux_DnsMastersOfSlaveZoneResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& instances){};
  	*/
  	/*
    Linux_DnsMastersOfSlaveZoneManualInstance 
     Linux_DnsMastersOfSlaveZoneResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsMastersOfSlaveZoneInstanceName&){
      Linux_DnsMastersOfSlaveZoneManualInstance instance;
      
    }
  	*/
  	/*
    void Linux_DnsMastersOfSlaveZoneResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsMastersOfSlaveZoneManualInstance&){};
  	*/
  	/*
    void Linux_DnsMastersOfSlaveZoneResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMastersOfSlaveZoneManualInstance&){};
  	*/
  	/*
    void Linux_DnsMastersOfSlaveZoneResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMastersOfSlaveZoneInstanceName&){};
	*/
    
    /* Association Interface */
    
    void Linux_DnsMastersOfSlaveZoneResourceAccess::referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsIPAddressInstanceName& sourceInst,
     Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& instEnum) {

	DNSZONE *zones = getZones();
	DNSZONE *all_zones = zones;

        for (;zones && zones->zoneName; zones++)
        {
		if ( strcmp( zones->zoneType, "slave") )
			continue;

                ZONEOPTS *zopts = findOptsInZone(zones,"masters");

                if (zopts && zopts->key && zopts->value )
                {
			DnsArray iplist = DnsArray(zopts->value);
			DnsArrayConstIterator iter; 

                        for ( iter = iplist.begin(); iter != iplist.end(); ++iter )
                        {
				if ( strcmp((*iter).c_str(), sourceInst.getIPAddress() ) != 0 )
					continue;
				
				Linux_DnsSlaveZoneInstanceName zoneInstName;
				zoneInstName.setName( zones->zoneName );

				Linux_DnsMastersOfSlaveZoneManualInstance manualInstance;
				Linux_DnsMastersOfSlaveZoneInstanceName instanceName;
				instanceName.setNamespace( nsp );	
				instanceName.setElement( zoneInstName );
				instanceName.setSetting( sourceInst);
				manualInstance.setInstanceName( instanceName );
				
				instEnum.addElement( manualInstance );
                        }
                }
        }
	freeZones( all_zones );
     };
    
    void Linux_DnsMastersOfSlaveZoneResourceAccess::referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsSlaveZoneInstanceName& sourceInst,
     Linux_DnsMastersOfSlaveZoneManualInstanceEnumeration& instEnum) {

     	DNSZONE *zones = getZones();
	DNSZONE *all_zones = zones;

        for (;zones && zones->zoneName; zones++)
        {
		if ( strcmp( zones->zoneName, sourceInst.getName() ) )
			continue;
		
                ZONEOPTS *zopts = findOptsInZone(zones,"masters");

                if (zopts && zopts->key && zopts->value )
                {
			DnsArray iplist = DnsArray(zopts->value);
			DnsArrayConstIterator iter; 

                        for ( iter = iplist.begin(); iter != iplist.end(); ++iter )
                        {
                                Linux_DnsIPAddressInstanceName ipInstanceName;
                                ipInstanceName.setNamespace(nsp);
                                ipInstanceName.setZoneName(zones->zoneName);
                                ipInstanceName.setIPAddress( (*iter).c_str() );

				Linux_DnsMastersOfSlaveZoneManualInstance manualInstance;
				Linux_DnsMastersOfSlaveZoneInstanceName instanceName;
				instanceName.setNamespace( nsp );
				instanceName.setElement( sourceInst );
				instanceName.setSetting( ipInstanceName );
				manualInstance.setInstanceName( instanceName );
				
				instEnum.addElement( manualInstance );
                        }
                }
        }
     	freeZones( all_zones );
     };
    
    void Linux_DnsMastersOfSlaveZoneResourceAccess::associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsIPAddressInstanceName& sourceInst,
     Linux_DnsSlaveZoneInstanceEnumeration& instEnum) {
	DNSZONE *zones = getZones();
	DNSZONE *all_zones = zones;

        for (;zones && zones->zoneName; zones++)
        {
		if ( strcmp( zones->zoneType, "slave" ) )
			continue;

                ZONEOPTS *zopts = findOptsInZone(zones,"masters");

                if (zopts && zopts->key && zopts->value )
                {
			DnsArray iplist = DnsArray(zopts->value);
			DnsArrayConstIterator iter; 

                        for ( iter = iplist.begin(); iter != iplist.end(); ++iter )
                        {
				if ( strcmp((*iter).c_str(), sourceInst.getIPAddress() ) != 0 )
					continue;
				
				Linux_DnsSlaveZoneInstanceName zoneInstName;
				zoneInstName.setName( zones->zoneName );

				Linux_DnsSlaveZoneInstance zoneInst;
				zoneInst.setInstanceName( zoneInstName );

				zoneInst.setType(DNS_ZONETYPE_SLAVE);
				zoneInst.setResourceRecordFile(zones->zoneFileName);
				
				instEnum.addElement( zoneInst );
                        }
                }
        }
	freeZones( all_zones );    
     };
    
    void Linux_DnsMastersOfSlaveZoneResourceAccess::associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsSlaveZoneInstanceName& sourceInst,
     Linux_DnsIPAddressInstanceEnumeration& instEnum) {
     	DNSZONE *zones = getZones();
	DNSZONE *all_zones = zones;

        for (;zones && zones->zoneName;zones++)
        {
		if ( strcmp( zones->zoneName, sourceInst.getName() ) != 0)
			continue;
		
                ZONEOPTS *zopts = findOptsInZone(zones,"masters");

                if (zopts && zopts->key && zopts->value )
                {
			DnsArray iplist = DnsArray(zopts->value);
			DnsArrayConstIterator iter; 

                        for ( iter = iplist.begin(); iter != iplist.end(); ++iter )
                        {
                                Linux_DnsIPAddressInstanceName ipInstanceName;
                                ipInstanceName.setNamespace(nsp);
                                ipInstanceName.setZoneName(zones->zoneName);
                                ipInstanceName.setIPAddress( (*iter).c_str() );

				Linux_DnsIPAddressInstance ipInstance;
				
				instEnum.addElement( ipInstance );
                        }
                }
        }
        freeZones( all_zones );
     };

   
    /* extrinsic methods */
	
}


