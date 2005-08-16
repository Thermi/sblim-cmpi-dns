 /**
 * Linux_DnsManagedSystemElementForSettingResourceAccess.cpp
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
#include "Linux_DnsManagedSystemElementForSettingResourceAccess.h"


namespace genProvider {
  
    //Linux_DnsManagedSystemElementForSettingResourceAccess::Linux_DnsManagedSystemElementForSettingResourceAccess();
    Linux_DnsManagedSystemElementForSettingResourceAccess::~Linux_DnsManagedSystemElementForSettingResourceAccess() { };
    
    /* intrinsic methods */
    /*
    void Linux_DnsManagedSystemElementForSettingResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration& instnames){
      
      int numInstanceNames=1;
      for(int i=0;i<numInstanceNames;i++){
      
        //place here the code retrieving your instanceName
      
        Linux_DnsManagedSystemElementForSettingInstanceName instanceName;
        
      }      
    }
    */
  	/*
    void Linux_DnsManagedSystemElementForSettingResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration& instances){};
  	*/
  	/*
    Linux_DnsManagedSystemElementForSettingManualInstance 
     Linux_DnsManagedSystemElementForSettingResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsManagedSystemElementForSettingInstanceName&){
      Linux_DnsManagedSystemElementForSettingManualInstance instance;
      
    }
  	*/
  	/*
    void Linux_DnsManagedSystemElementForSettingResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsManagedSystemElementForSettingManualInstance&){};
  	*/
  	/*
    void Linux_DnsManagedSystemElementForSettingResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsManagedSystemElementForSettingManualInstance&){};
  	*/
  	/*
    void Linux_DnsManagedSystemElementForSettingResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsManagedSystemElementForSettingInstanceName&){};
	*/
    
    /* Association Interface */
    
    void Linux_DnsManagedSystemElementForSettingResourceAccess::referencesElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration& instEnum) {
/*	cout << "Linux_DnsManagedSystemElementForSettingResourceAcces::referencesElement()" << endl;

        DNSZONE *zones = getZones();
	DNSZONE *zones_ptr = zones;

        if ( ! zones)
                throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The indicated Zone does not exist");

        for (; zones->zoneName ; zones++)
        {
               	ZONEOPTS *zopts = zones->zoneOpts;
	        while (zopts && zopts->key)
		{
        	        if ( 	strcmp(zopts->key, DNS_ALLOW_NOTIFY_STR)   &&
				strcmp(zopts->key, DNS_ALLOW_QUERY_STR)    &&
				strcmp(zopts->key, DNS_ALLOW_TRANSFER_STR) && 
				strcmp(zopts->key, DNS_ALLOW_UPDATE_STR )  
			 )
				continue;

			
                	DnsArray da = DnsArray( zopts->value );
                	DnsArrayConstIterator iter;

                	for ( iter = da.begin(); iter != da.end(); ++iter)
                	{
                        	if ( strcmp( (*iter).c_str(), sourceInst.getName() ) != 0 )
                                	continue;

                        	Linux_DnsManagedSystemElementForSettingInstanceName AuInstName;
                        	Linux_DnsManagedSystemElementForSettingManualInstance AuInst;
				Linux_DnsZoneInstance zoneInst;
                       		Linux_DnsZoneInstanceName zoneInstName;

                        	zoneInstName.setNamespace( nsp );
               		        zoneInstName.setName( zones->zoneName );
        	                zoneInst.setInstanceName( zoneInstName );
	
                        	if      ( strcmp(zones->zoneType, "master") == 0 )
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
*/
    };
    
    
    void Linux_DnsManagedSystemElementForSettingResourceAccess::referencesSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsManagedSystemElementForSettingManualInstanceEnumeration& instEnum) {

    };
    
    
    void Linux_DnsManagedSystemElementForSettingResourceAccess::associatorsElement( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsAddressMatchListInstanceName& sourceInst,
     Linux_DnsZoneInstanceEnumeration&) { };
    
    
    void Linux_DnsManagedSystemElementForSettingResourceAccess::associatorsSetting( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsAddressMatchListInstanceEnumeration&) {

    };
    
   
    /* extrinsic methods */
	
}


