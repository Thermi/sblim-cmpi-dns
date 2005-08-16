 /**
 * Linux_DnsResourceRecordInZoneResourceAccess.cpp
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
#include "Linux_DnsResourceRecordInZoneResourceAccess.h"

namespace genProvider {
  
    //Linux_DnsResourceRecordInZoneResourceAccess::Linux_DnsResourceRecordInZoneResourceAccess();
    Linux_DnsResourceRecordInZoneResourceAccess::~Linux_DnsResourceRecordInZoneResourceAccess() { };
    
    /* intrinsic methods */
    /*
    void Linux_DnsResourceRecordInZoneResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsResourceRecordInZoneInstanceNameEnumeration& instnames){
      
      int numInstanceNames=1;
      for(int i=0;i<numInstanceNames;i++){
      
        //place here the code retrieving your instanceName
      
        Linux_DnsResourceRecordInZoneInstanceName instanceName;
        
      }      
    }
    */
  	/*
    void Linux_DnsResourceRecordInZoneResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsResourceRecordInZoneManualInstanceEnumeration& instances){};
  	*/
  	/*
    Linux_DnsResourceRecordInZoneManualInstance 
     Linux_DnsResourceRecordInZoneResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsResourceRecordInZoneInstanceName&){
      Linux_DnsResourceRecordInZoneManualInstance instance;
      
    }
  	*/
  	/*
    void Linux_DnsResourceRecordInZoneResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsResourceRecordInZoneManualInstance&){};
  	*/
  	/*
    void Linux_DnsResourceRecordInZoneResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsResourceRecordInZoneManualInstance&){};
  	*/
  	/*
    void Linux_DnsResourceRecordInZoneResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsResourceRecordInZoneInstanceName&){};
	*/
    
    /* Association Interface */
    
    void Linux_DnsResourceRecordInZoneResourceAccess::referencesGroupComponent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsResourceRecordInstanceName& sourceInst,
     Linux_DnsResourceRecordInZoneManualInstanceEnumeration& instEnum) {
          
        DNSZONE * zones = NULL;

        zones = getZones();

        if (zones)
        {
            for (; ((zones->zoneName) != NULL) ; zones++)
            {
	    	if ( strcmp(zones->zoneName, sourceInst.getZoneName()) !=0 )
			continue;
	    
                if (zones->records)
                {
                    DNSRECORD * records = NULL;

                    for (records = zones->records; ((records->recordName) != NULL); ++records)
                    {
		    	if ( strcmp(records->recordName, sourceInst.getName() ) !=0 )
				continue;
				
			Linux_DnsZoneInstanceName zoneInstName;
   			zoneInstName.setNamespace(nsp);
			zoneInstName.setName(zones->zoneName);
			
			Linux_DnsResourceRecordInZoneManualInstance inst;
			Linux_DnsResourceRecordInZoneInstanceName instName;
			instName.setNamespace( nsp );
			instName.setGroupComponent( zoneInstName );
			instName.setPartComponent( sourceInst );
			inst.setInstanceName( instName );
			
                        instEnum.addElement(inst);
                    }
                }

            }
        }
     };
    
    void Linux_DnsResourceRecordInZoneResourceAccess::referencesPartComponent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsResourceRecordInZoneManualInstanceEnumeration& instEnum) {
          
        DNSZONE * zones = NULL;

        zones = getZones();

        if (zones)
        {
            for (; ((zones->zoneName) != NULL) ; zones++)
            {
	    	if ( strcmp(zones->zoneName, sourceInst.getName()) !=0 )
			continue;
	    
                if (zones->records)
                {
                    DNSRECORD * records = NULL;

                    for (records = zones->records; ((records->recordName) != NULL); ++records)
                    {				
		    	Linux_DnsResourceRecordInstanceName recordInstanceName;
			recordInstanceName.setNamespace(nsp);
			recordInstanceName.setName(records->recordName);
			recordInstanceName.setZoneName(zones->zoneName);
			
			if (strcmp(records->recordType,"NS") == 0)
			{
				recordInstanceName.setType(3);
			}
			else if (strcmp(records->recordType,"A") == 0)
			{
				recordInstanceName.setType(6);
			}
			else if (strcmp(records->recordType,"MX") == 0)
			{
				recordInstanceName.setType(4);
			}
			else
			{
				recordInstanceName.setType(6);  // = Type A 
			}
		
			recordInstanceName.setValue(records->recordValue); 
			
			Linux_DnsResourceRecordInZoneManualInstance inst;
			Linux_DnsResourceRecordInZoneInstanceName instName;
			instName.setNamespace( nsp );
			instName.setGroupComponent( sourceInst );
			instName.setPartComponent( recordInstanceName );
			inst.setInstanceName( instName );
			
                        instEnum.addElement(inst);
                    }
                }

            }
        }      
     };
    
    void Linux_DnsResourceRecordInZoneResourceAccess::associatorsGroupComponent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsResourceRecordInstanceName& sourceInst,
     Linux_DnsZoneInstanceEnumeration& instEnum) {
        DNSZONE * zones = NULL;

        zones = getZones();

        if (zones)
        {
            for (; ((zones->zoneName) != NULL) ; zones++)
            {
	    	if ( strcmp(zones->zoneName, sourceInst.getZoneName()) !=0 )
			continue;
	    
                if (zones->records)
                {
                    DNSRECORD * records = NULL;

                    for (records = zones->records; ((records->recordName) != NULL); ++records)
                    {
		    	if ( strcmp(records->recordName, sourceInst.getName() ) !=0 )
				continue;
				
			Linux_DnsZoneInstanceName zoneInstName;
   			zoneInstName.setNamespace(nsp);
			zoneInstName.setName(zones->zoneName);
			
			Linux_DnsZoneInstance inst;
			inst.setInstanceName( zoneInstName );
			
                        instEnum.addElement(inst);
                    }
                }

            }
        }
     };
    
    void Linux_DnsResourceRecordInZoneResourceAccess::associatorsPartComponent( 
     const CmpiContext& ctx,  
     const CmpiBroker &mbp,
     const char *nsp,
     const char** properties,
     const Linux_DnsZoneInstanceName& sourceInst,
     Linux_DnsResourceRecordInstanceEnumeration& instEnum) {
          
        DNSZONE * zones = NULL;

        zones = getZones();

        if (zones)
        {
            for (; ((zones->zoneName) != NULL) ; zones++)
            {
	    	if ( strcmp(zones->zoneName, sourceInst.getName()) !=0 )
			continue;
	    
                if (zones->records)
                {
                    DNSRECORD * records = NULL;

                    for (records = zones->records; ((records->recordName) != NULL); ++records)
                    {				
		    	Linux_DnsResourceRecordInstanceName recordInstanceName;
			recordInstanceName.setNamespace(nsp);
			recordInstanceName.setName(records->recordName);
			recordInstanceName.setZoneName(zones->zoneName);
			
			if (strcmp(records->recordType,"NS") == 0)
			{
				recordInstanceName.setType(3);
			}
			else if (strcmp(records->recordType,"A") == 0)
			{
				recordInstanceName.setType(6);
			}
			else if (strcmp(records->recordType,"MX") == 0)
			{
				recordInstanceName.setType(4);
			}
			else
			{
				recordInstanceName.setType(6);  // = Type A 
			}
		
			recordInstanceName.setValue(records->recordValue); 
			
			Linux_DnsResourceRecordInstance inst;
			inst.setInstanceName( recordInstanceName );
			inst.setFamily( DNS_RRFAMILY_INTERNET );
	
                        instEnum.addElement(inst);
                    }
                }

            }
        }      
     };
    
   
    /* extrinsic methods */
	
}


