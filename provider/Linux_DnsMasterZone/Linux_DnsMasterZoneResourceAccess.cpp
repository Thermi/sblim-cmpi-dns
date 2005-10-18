 /**
 * Linux_DnsMasterZoneResourceAccess.cpp
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
 * author:      Tony Gargya <gargya@de.ibm.com>
 * 		Murillo Bernardes <bernarde@br.ibm.com>
 *
 * Contributors:
 *
 */
#include <string>
#include <iostream>

using namespace std;

#include "Linux_DnsMasterZoneResourceAccess.h"

namespace genProvider {

    //------------------------------------------------------------------------------------
    // Linux_DnsMasterZoneResourceAccess::setInstanceNameProperties()
    //------------------------------------------------------------------------------------
    void
    Linux_DnsMasterZoneResourceAccess::setInstanceNameProperties(const CmpiContext& ctx,
                                                           const CmpiBroker& mbp,
                                                           const char* nsp,
                                                           DNSZONE * zone,
                                                           Linux_DnsMasterZoneInstanceName& anInstanceName)
    {
        cout << "--- setInstanceNameProperties() called" << endl;
        anInstanceName.setNamespace(nsp);
        anInstanceName.setName(zone->zoneName);

        cout << "--- setInstanceNameProperties() exited" << endl;
    }

    //------------------------------------------------------------------------------------
    // Linux_DnsMasterZoneResourceAccess::setInstanceProperties()
    //------------------------------------------------------------------------------------



    void
    Linux_DnsMasterZoneResourceAccess::setInstanceProperties(const CmpiContext& ctx,
                                                       const CmpiBroker& mbp,
                                                       DNSZONE * zone,
                                                       const Linux_DnsMasterZoneInstanceName& anInstanceName,
                                                       Linux_DnsMasterZoneManualInstance& aManualInstance)
    {
        cout<<"--- setInstanceProperties() called"<<endl;

	//ZONEOPTS* zoneOpts;
	ZONEOPTS * forward = findOptsInZone( zone, "forward" );
	if ( forward )
	{
		if ( strcmp( forward->value, "first" ) )
			aManualInstance.setForward( DNS_FORWARD_FIRST );
		
		if ( strcmp( forward->value, "only" ) )
                        aManualInstance.setForward( DNS_FORWARD_ONLY );
	}	

	ZONEOPTS * forwarders = findOptsInZone( zone, "forwarders" );
	DnsArray da;

	if ( forwarders && forwarders->value )
	{
		da.populate( forwarders->value ); 
		aManualInstance.setForwarders( da.toArray(), da.size() );
	}
        aManualInstance.setInstanceName(anInstanceName);

        aManualInstance.setType(DNS_ZONETYPE_MASTER);

	aManualInstance.setResourceRecordFile(zone->zoneFileName);
	
	aManualInstance.setContact(zone->soaContact);

	char *val = (char *) malloc( 12*sizeof(char) );
	sprintf(val,"%lld", zone->soaSerialNumber );
	aManualInstance.setSerialNumber( val );
	free(val);

        aManualInstance.setRefresh( zone->soaRefresh );
        aManualInstance.setRetry( zone->soaRetry );
        aManualInstance.setExpire( zone->soaExpire );
	aManualInstance.setServer( zone->soaServer );
        aManualInstance.setNegativeCachingTTL( zone->soaNegativCachingTTL );
        
        cout << "--- setInstanceProperties() exited" << endl;
    }
 
    //Linux_DnsMasterZoneResourceAccess::Linux_DnsMasterZoneResourceAccess();
    Linux_DnsMasterZoneResourceAccess::~Linux_DnsMasterZoneResourceAccess() { };
    
    /* intrinsic methods */
    
    void Linux_DnsMasterZoneResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsMasterZoneInstanceNameEnumeration& instnames)
     {
        DNSZONE * zones, *all_zones;

        cout << "--- enumInstanceNames() called" << endl; 
        cout << "---- calling getZones() " << endl;

        zones = getZones(); //getZonesByType("master");
	all_zones = zones;

        if (zones)
        {
            for (; zones->zoneName != NULL ; zones++)
            {  
		if ( strcmp(zones->zoneType, "master") )
			continue;
 
                //Linux_DnsZoneManualInstance instance;
                Linux_DnsMasterZoneInstanceName instanceName;

                cout << "--- Calling setInstanceNameProperties()" << endl; 

                printf ("Zone Name is %s \n", zones->zoneName);

                setInstanceNameProperties(ctx, mbp, nsp,
                                          zones, instanceName);

                instnames.addElement(instanceName);

                cout << "--- Added to enumeration"  << endl; 

            }
            freeZones( all_zones );
            cout << "--- enumInstanceNames () exited"  << endl; 
        }
    }
    
  
    void Linux_DnsMasterZoneResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsMasterZoneManualInstanceEnumeration& instances) 
    {
	cout << "Linux_DnsMasterZoneResourceAccess::enumInstances()" << endl;
        cout << "--- enumInstances() called" << endl;

        DNSZONE * zones = NULL, *all_zones;

        cout << "---- calling getZones() " << endl;

        zones = getZones(); 	//getZonesByType("master");
	all_zones = zones;

        if (zones)
        {
            for (; zones->zoneName != NULL ; zones++)
            {
		if ( strcmp(zones->zoneType, "master") )
                        continue;

                Linux_DnsMasterZoneManualInstance instance;
                Linux_DnsMasterZoneInstanceName instanceName;

                cout << "--- Calling setInstanceNameProperties() for zone" << endl;

                printf (" -----%s \n", zones->zoneName);

                setInstanceNameProperties(ctx, mbp, nsp,
                                          zones, instanceName);

                cout << "--- Calling setInstanceProperties()" << endl;

                setInstanceProperties(ctx, mbp, zones,
                                      instanceName, instance);

                instances.addElement(instance);
                
		cout << "--- Added to enumeration"  << endl;
            }
	    freeZones( all_zones );
        }
        else
        {
            cout << "--- No Zones Found"  << endl;
        }

        cout << "--- enumInstances() exited"  << endl;
    };
  	
  	
    Linux_DnsMasterZoneManualInstance 
     Linux_DnsMasterZoneResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsMasterZoneInstanceName& anInstanceName){
	
	cout << "--- getInstance() called" << endl; 

        DNSZONE *zones, *myZone;

	Linux_DnsMasterZoneManualInstance instance;

        cout << "---- calling getZones() " << endl;

        zones = getZones();
	myZone = findZone(zones,anInstanceName.getName());

	if ( ! myZone )
		throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");	

        setInstanceProperties(ctx, mbp, myZone, anInstanceName, instance);
        
	cout << "--- getInstance() exited "  << endl; 

	freeZones( zones );
        return instance;
    }
  	
  	
    void Linux_DnsMasterZoneResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsMasterZoneManualInstance& newInstance){
	cout << "Linux_DnsMasterZoneResourceAccess::setInstance()" << endl;
	cout << "--- setInstance() called" << endl; 

        DNSZONE *zones, *myZone;

        zones = getZones();
	myZone = findZone(zones, newInstance.getInstanceName().getName());
	
	if ( ! myZone )
		throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");

	if ( strcmp(myZone->zoneType,"master") != 0 )
		throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");
	
	if ( newInstance.isResourceRecordFileSet() ) {
		free(myZone->zoneFileName);
		myZone->zoneFileName = strdup(newInstance.getResourceRecordFile());
	}
            
	if (newInstance.isContactSet())
	{
		free(myZone->soaContact);
            	myZone->soaContact = strdup( newInstance.getContact() );
	}

        if ( newInstance.isForwardSet() )
        {
		ZONEOPTS *zopts = findOptsInZone( myZone, "forward" );

		if ( zopts )
		{
			free( zopts->value );
        		if ( newInstance.getForward() == DNS_FORWARD_ONLY )
                        	zopts->value = strdup( "only" );

                	if ( newInstance.getForward() == DNS_FORWARD_FIRST )
                        	zopts->value = strdup( "first" );

		} 
		else
		{
        		if ( newInstance.getForward() == DNS_FORWARD_ONLY )
                        	addOptsToZone( myZone, "forward", "only" );

                	if ( newInstance.getForward() == DNS_FORWARD_FIRST )
                        	addOptsToZone( myZone, "forward", "first" );
		}
		
        }

        unsigned int size = 0;
        if ( newInstance.isForwardersSet() )
        {
		ZONEOPTS *zopts = findOptsInZone( myZone, "forwarders" );

                const char **forwardersList = newInstance.getForwarders( size );
                DnsArray value_list;

                for (unsigned int i = 0; i < size; i++)
                if (! value_list.isPresent( string( forwardersList[i]) ) )
                        value_list.add( forwardersList[i] );

		if ( zopts )
		{
			free( zopts->value );
			zopts->value = strdup ( value_list.toString().c_str() );
		}
		else
                	addOptsToZone( myZone,"forwarders", strdup( value_list.toString().c_str() ) );
        }
	    
	    // SerialNumber
	if (newInstance.isSerialNumberSet())
		myZone->soaSerialNumber = atoi(newInstance.getSerialNumber());
	
	    // Refresh
	if (newInstance.isRefreshSet())
	    	myZone->soaRefresh = newInstance.getRefresh();

	    // Retry	
	if (newInstance.isRetrySet())
		myZone->soaRetry = newInstance.getRetry();
	
	    // Expire
        if (newInstance.isExpireSet())
                myZone->soaExpire = newInstance.getExpire();
	    
	    // NegativeCachingTTL
        if (newInstance.isNegativeCachingTTLSet())
                myZone->soaNegativCachingTTL = newInstance.getNegativeCachingTTL();

	if (newInstance.isServerSet())
                myZone->soaServer = strdup( newInstance.getServer() );


	updateZones(zones);
	freeZones( zones );
	
	cout << "--- setInstance() exited "  << endl; 
    };
  	
  	
    void Linux_DnsMasterZoneResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneManualInstance& aManualInstance)
     {
     	cout << "--- createInstance() called" << endl; 

        DNSZONE * newZone = NULL;
        Linux_DnsMasterZoneInstanceName anInstanceName = aManualInstance.getInstanceName();

        if (((anInstanceName.getName()) == NULL) || ((anInstanceName.getName()) == "" ) || ((anInstanceName.getName()) == " " ) )
        {
            // throw exception that invalid key 
            cout << "---- Zonename is invalid" << endl;
            throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"Zonename is invalid");

        }
	
	DNSZONE * all_zones = getZones();
	if ( findZone(all_zones,anInstanceName.getName()) )
	{
		freeZones(all_zones);
		throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The zone already exist");
	}
	freeZones(all_zones);
	
        newZone = (DNSZONE *)calloc(1+1,sizeof(DNSZONE));

        if (newZone)
        {
            // Take in value specified only at Dialog ??//

            newZone->zoneName = (char *)anInstanceName.getName();

            newZone->zoneType = "master";
	    
            cout << "---- newZone->zoneType is "<<  newZone->zoneType << endl;

	    if (aManualInstance.isResourceRecordFileSet()) {
		newZone->zoneFileName = strdup(aManualInstance.getResourceRecordFile());
	    }
	    else {
		char * buffer;
		buffer = (char *)calloc((strlen(newZone->zoneType)+strlen(newZone->zoneName)+2),sizeof(char));
		strcat(buffer, newZone->zoneType);
		strcat(buffer, "/");
		strcat(buffer, newZone->zoneName);
		newZone->zoneFileName = buffer;
	    }
            printf("---- zoneFileName  is %s \n", newZone->zoneFileName);
            
	    // Contact  
	    if (aManualInstance.isContactSet())
            	newZone->soaContact = (char *)aManualInstance.getContact();
	    else
		newZone->soaContact = "root";

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
	   
	    if ( aManualInstance.isForwardSet() )
            {
		if ( aManualInstance.getForward() == DNS_FORWARD_ONLY )
			addOptsToZone( newZone, "forward", "only" );
		
		if ( aManualInstance.getForward() == DNS_FORWARD_FIRST )
                        addOptsToZone( newZone, "forward", "first" );

	    }
 
	    unsigned int size = 0;
	    if ( aManualInstance.isForwardersSet() )
            {
                const char **forwardersList = aManualInstance.getForwarders( size );
		DnsArray value_list;
                for (unsigned int i = 0; i < size; i++)
                if (! value_list.isPresent( string( forwardersList[i]) ) )
                        value_list.add( forwardersList[i] );

                addOptsToZone( newZone,"forwarders", strdup( value_list.toString().c_str() ) );
            }

	    // NegativeCachingTTL
            if (aManualInstance.isNegativeCachingTTLSet())
                newZone->soaNegativCachingTTL = aManualInstance.getNegativeCachingTTL();
            else
    	        newZone->soaNegativCachingTTL = 0;

	    if (aManualInstance.isServerSet())
                newZone->soaServer = strdup( aManualInstance.getServer() );
	    else
	    	newZone->soaServer = "@";

            newZone->records = NULL;

            cout << "---- calling addZones() " << endl;

            DNSZONE * returnedZones = NULL;
            
	    returnedZones = addZone(newZone, NULL);
            if (!returnedZones)
            {
                cout <<"---- addZone() failed " << endl;
                cout <<"---- createInstance Zone exited " << endl;
                throw CmpiStatus(CMPI_RC_ERROR,"addZone() failed");
            }
	    freeZones( returnedZones );

            cout <<"---- createInstance Zone exited " << endl;
     }
   }
  	
    void Linux_DnsMasterZoneResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName& inst){

	deleteZone( inst.getName() );
    };
	
    
    /* extrinsic methods */
    /*
    virtual CMPIUint32 Linux_DnsMasterZoneResourceAccess::ApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsMasterZoneResourceAccess::ApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsMasterZoneResourceAccess::ApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsMasterZoneResourceAccess::ApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent) { };
    */
    /*
    virtual CMPIUint32 Linux_DnsMasterZoneResourceAccess::VerifyOKToApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsMasterZoneResourceAccess::VerifyOKToApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsMasterZoneResourceAccess::VerifyOKToApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsMasterZoneResourceAccess::VerifyOKToApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent) { };
    */

    
    CMPIUint32 Linux_DnsMasterZoneResourceAccess::disable(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName& inst) { 
	
	if ( inst.getName() == NULL )
		return 3;	
	return disableZone(inst.getName());
    };
    
    
    CMPIUint32 Linux_DnsMasterZoneResourceAccess::enable(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsMasterZoneInstanceName& inst) { 
   
	if ( inst.getName() == NULL )
                return 3;
	
	return enableZone(inst.getName());
    };
    
	
}


