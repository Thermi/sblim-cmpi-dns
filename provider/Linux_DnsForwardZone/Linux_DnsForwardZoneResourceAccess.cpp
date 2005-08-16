 /**
 * Linux_DnsForwardZoneResourceAccess.cpp
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
#include <string>
#include <iostream>

using namespace std;

#include "Linux_DnsForwardZoneResourceAccess.h"


namespace genProvider {

    //------------------------------------------------------------------------------------
    // Linux_DnsForwardZoneResourceAccess::setInstanceNameProperties()
    //------------------------------------------------------------------------------------
    void
    Linux_DnsForwardZoneResourceAccess::setInstanceNameProperties(const CmpiContext& ctx,
                                                           const CmpiBroker& mbp,
                                                           const char* nsp,
                                                           DNSZONE * zone,
                                                           Linux_DnsForwardZoneInstanceName& anInstanceName)
    {
        cout << "--- setInstanceNameProperties() called" << endl;
        anInstanceName.setNamespace(nsp);
        anInstanceName.setName(zone->zoneName);

        cout << "--- setInstanceNameProperties() exited" << endl;
    }

    //------------------------------------------------------------------------------------
    // Linux_DnsForwardZoneResourceAccess::setInstanceProperties()
    //------------------------------------------------------------------------------------
    void
    Linux_DnsForwardZoneResourceAccess::setInstanceProperties(const CmpiContext& ctx,
                                                       const CmpiBroker& mbp,
                                                       DNSZONE * zone,
                                                       const Linux_DnsForwardZoneInstanceName& anInstanceName,
                                                       Linux_DnsForwardZoneManualInstance& aManualInstance)
    {
        cout<<"--- setInstanceProperties() called"<<endl;


        aManualInstance.setInstanceName(anInstanceName);
        aManualInstance.setType(DNS_ZONETYPE_FORWARD);
//	aManualInstance.setResourceRecordFile(zone->zoneFileName);   
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
 
    }  
    //Linux_DnsForwardZoneResourceAccess::Linux_DnsForwardZoneResourceAccess();
    Linux_DnsForwardZoneResourceAccess::~Linux_DnsForwardZoneResourceAccess() { };
    
    /* intrinsic methods */
    
    void Linux_DnsForwardZoneResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsForwardZoneInstanceNameEnumeration& instnames){
 
	DNSZONE * zones, *all_zones;

        cout << "--- enumInstanceNames() called" << endl; 
        cout << "---- calling getZones() " << endl;

        zones = getZones();	//getZonesByType("forward");
	all_zones = zones;

        if (zones)
        {
            for (; zones->zoneName; zones++)
            {
                if ( strcmp(zones->zoneType, "forward") )
                        continue;

                Linux_DnsForwardZoneInstanceName instanceName;

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
    
  	
    void Linux_DnsForwardZoneResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsForwardZoneManualInstanceEnumeration& instances){
        cout << "--- enumInstances() called" << endl;

        DNSZONE * zones = NULL, *all_zones;

        cout << "---- calling getZones() " << endl;

        zones = getZones(); 	//getZonesByType("forward");
	all_zones = zones;

        if (zones)
        {
            for (; zones->zoneName != NULL ; zones++)
            {   
                if ( strcmp(zones->zoneType, "forward") )
                        continue;

                Linux_DnsForwardZoneManualInstance instance;
                Linux_DnsForwardZoneInstanceName instanceName;

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
  	
  	
    Linux_DnsForwardZoneManualInstance 
     Linux_DnsForwardZoneResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsForwardZoneInstanceName& anInstanceName){
     
	cout << "--- getInstance() called" << endl;

        DNSZONE *zones, *myZone;

        Linux_DnsForwardZoneManualInstance instance;

        cout << "---- calling getZones() " << endl;

        zones = getZones();	//getZonesByType("forward");
        myZone = findZone(zones,anInstanceName.getName());

        setInstanceProperties(ctx, mbp, myZone, anInstanceName, instance);

        cout << "--- getInstance() exited "  << endl;
	freeZones( zones );

        return instance;

    }
  	
  	
    void Linux_DnsForwardZoneResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsForwardZoneManualInstance& newInstance){

        cout << "--- setInstance() called" << endl;

        DNSZONE *zones, *myZone;

        zones = getZones();
        myZone = findZone(zones, newInstance.getInstanceName().getName());

        if ( ! myZone )
                throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");

        if ( strcmp(myZone->zoneType,"forward") != 0 )
                throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");

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

	// option 'file' is not allowed in 'forward' zone
        if ( newInstance.isResourceRecordFileSet() ) {
                free(myZone->zoneFileName);
                myZone->zoneFileName = strdup(newInstance.getResourceRecordFile());
        } 
	updateZones( zones );
	freeZones( zones );
    };
  	
  	
    void Linux_DnsForwardZoneResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsForwardZoneManualInstance& aManualInstance){

	cout << "--- createInstance() called" << endl;

        DNSZONE * newZone = NULL;
        Linux_DnsForwardZoneInstanceName anInstanceName = aManualInstance.getInstanceName();

        if (((anInstanceName.getName()) == NULL) || ((anInstanceName.getName()) == "" ) || ((anInstanceName.getName()) =="") )
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
                newZone->zoneName = (char *)anInstanceName.getName();

                newZone->zoneType = "forward";

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

                cout << "---- newZone->zoneType is "<<  newZone->zoneType << endl;
		//option 'file' is not allowed in 'forward' zone
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

    };
  	
  	
    void Linux_DnsForwardZoneResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsForwardZoneInstanceName& inst){

        deleteZone( inst.getName() );
    };
	
    
    /* extrinsic methods */
    /*
    virtual CMPIUint32 Linux_DnsForwardZoneResourceAccess::ApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsForwardZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsForwardZoneResourceAccess::ApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsForwardZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsForwardZoneResourceAccess::ApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsForwardZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsForwardZoneResourceAccess::ApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsForwardZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent) { };
    */
    /*
    virtual CMPIUint32 Linux_DnsForwardZoneResourceAccess::VerifyOKToApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsForwardZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsForwardZoneResourceAccess::VerifyOKToApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsForwardZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsForwardZoneResourceAccess::VerifyOKToApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsForwardZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsForwardZoneResourceAccess::VerifyOKToApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsForwardZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent) { };
    */

    
    CMPIUint32 Linux_DnsForwardZoneResourceAccess::disable(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsForwardZoneInstanceName& inst) {

        if ( inst.getName() == NULL )
                return 3;

        disableZone( inst.getName() );
    };
    
    
    CMPIUint32 Linux_DnsForwardZoneResourceAccess::enable(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsForwardZoneInstanceName& inst) {

        if ( inst.getName() == NULL )
                return 3;

        enableZone( inst.getName() );

    };
    	
}


