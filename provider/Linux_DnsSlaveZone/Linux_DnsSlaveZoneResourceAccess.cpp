 /**
 * Linux_DnsSlaveZoneResourceAccess.cpp
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

#include "Linux_DnsSlaveZoneResourceAccess.h"

namespace genProvider {

    //------------------------------------------------------------------------------------
    // Linux_DnsSlaveZoneResourceAccess::setInstanceNameProperties()
    //------------------------------------------------------------------------------------
    void
    Linux_DnsSlaveZoneResourceAccess::setInstanceNameProperties(const CmpiContext& ctx,
                                                           const CmpiBroker& mbp,
                                                           const char* nsp,
                                                           DNSZONE * zone,
                                                           Linux_DnsSlaveZoneInstanceName& anInstanceName)
    {
        cout << "--- setInstanceNameProperties() called" << endl;
        anInstanceName.setNamespace(nsp);
        anInstanceName.setName(zone->zoneName);

        cout << "--- setInstanceNameProperties() exited" << endl;
    }

    //------------------------------------------------------------------------------------
    // Linux_DnsSlaveZoneResourceAccess::setInstanceProperties()
    //------------------------------------------------------------------------------------



    void
    Linux_DnsSlaveZoneResourceAccess::setInstanceProperties(const CmpiContext& ctx,
                                                       const CmpiBroker& mbp,
                                                       DNSZONE * zone,
                                                       const Linux_DnsSlaveZoneInstanceName& anInstanceName,
                                                       Linux_DnsSlaveZoneManualInstance& aManualInstance)
    {
        cout<<"--- setInstanceProperties() called"<<endl;
	
	ZONEOPTS* zoneOpts;

        aManualInstance.setInstanceName(anInstanceName);

        aManualInstance.setType(DNS_ZONETYPE_SLAVE);
	aManualInstance.setResourceRecordFile(zone->zoneFileName);

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

        /* if ( ( zoneOpts = findOptsInZone(zone,"resquest-ixfr")) )
        {
                if (strcmp(zoneOpts->value,"no") == 0)
                        aManualInstance.setXferFormat(DNS_XFER_COMPLETE);
                else
                        aManualInstance.setXferFormat(DNS_XFER_INCREMENTAL);
        } */

    }
      
    //Linux_DnsSlaveZoneResourceAccess::Linux_DnsSlaveZoneResourceAccess();
    Linux_DnsSlaveZoneResourceAccess::~Linux_DnsSlaveZoneResourceAccess() { };
    
    /* intrinsic methods */
    
    void Linux_DnsSlaveZoneResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsSlaveZoneInstanceNameEnumeration& instnames){
	DNSZONE * zones, *all_zones;

        cout << "--- enumInstanceNames() called" << endl; 
        cout << "---- calling getZones() " << endl;

        zones = getZones();	//getZonesByType("slave");
	all_zones = zones;

        if (zones)
        {
            for (; zones->zoneName ; zones++)
            {	    
                if ( strcmp(zones->zoneType, "slave") )
                        continue;

                Linux_DnsSlaveZoneInstanceName instanceName;

                cout << "--- Calling setInstanceNameProperties()" << endl; 

                printf ("Zone Name is %s \n", zones->zoneName);

                setInstanceNameProperties(ctx, mbp, nsp,
                                          zones, instanceName);

                instnames.addElement(instanceName);

                cout << "--- Added to enumeration"  << endl; 
            }
            cout << "--- enumInstanceNames () exited"  << endl; 
        }
	freeZones( all_zones ); 
    }
    
      	

    void Linux_DnsSlaveZoneResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsSlaveZoneManualInstanceEnumeration& instances){

	cout << "Linux_DnsSlaveZoneResourceAccess::enumInstances()" << endl;

        DNSZONE * zones = NULL, *all_zones;

        cout << "---- calling getZones() " << endl;

        zones = getZones();	//getZonesByType("slave");
	all_zones = zones;

        if (zones)
        {
            for (; zones->zoneName; zones++)
            {   
		if ( strcmp(zones->zoneType, "slave") )
                        continue;

                Linux_DnsSlaveZoneManualInstance instance;
                Linux_DnsSlaveZoneInstanceName instanceName;

                printf (" -----%s \n", zones->zoneName);

                setInstanceNameProperties(ctx, mbp, nsp,
                                          zones, instanceName);

                setInstanceProperties(ctx, mbp, zones,
                                      instanceName, instance);

                instances.addElement(instance);
            }
        }
        else
        {
            cout << "--- No Zones Found"  << endl;
        }
	freeZones ( zones );
        cout << "--- enumInstances() exited"  << endl;	 
    };
  	
	
    Linux_DnsSlaveZoneManualInstance 
     Linux_DnsSlaveZoneResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsSlaveZoneInstanceName& anInstanceName){
	
	cout << "---  Linux_DnsSlaveZoneResourceAccess::getInstance() called" << endl; 

        DNSZONE * zones, *all_zones;
	Linux_DnsSlaveZoneManualInstance instance;

        cout << "---- calling getZones() " << endl;

        zones = getZones();	//getZonesByType("slave");
	all_zones = zones;        

	if ( !zones)
        	throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");

        for (; zones->zoneName; zones++)
        {		
                if ( strcmp(zones->zoneType, "slave") )
                        continue;

                cout << "--- zones->zoneName is "  << endl;
                printf ("%s \n", zones->zoneName);

                printf ("%s \n", anInstanceName.getName());

                if ((strcmp(zones->zoneName, anInstanceName.getName())) == 0)
                {
                    setInstanceProperties(ctx, mbp, zones,
                                          anInstanceName, instance);

                    cout << "--- getInstance() exited "  << endl; 

                    return instance; 
                }
        } // end for
	freeZones( zones );
    }
  	
  	
    void Linux_DnsSlaveZoneResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsSlaveZoneManualInstance& newInstance){
	
	cout << "---  Linux_DnsSlaveZoneResourceAccess::setInstance() called" << endl;

        DNSZONE *zones, *myZone;

        zones = getZones();
        myZone = findZone(zones, newInstance.getInstanceName().getName());

        if ( ! myZone )
                throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");
	
        if ( strcmp(myZone->zoneType,"slave") != 0 )
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

	if ( newInstance.isResourceRecordFileSet() ) {
		free(myZone->zoneFileName);
                myZone->zoneFileName = strdup(newInstance.getResourceRecordFile());
        }
	/*
	if ( newInstance.isXferFormatSet() )
        {
                int xfmt = newInstance.getXferFormat();

                ZONEOPTS* zopts = findOptsInZone(myZone,"provide-ixfr");
                if ( zopts )
                {
                        free(zopts->value);
                        if ( xfmt == DNS_XFER_COMPLETE )
                                zopts->value = strdup("no");
                        else
                                zopts->value = strdup("yes");
                }
                else
                {
                        if ( xfmt == DNS_XFER_COMPLETE)
                                addOptsToZone(myZone,"provide-ixfr","no");
                         else
                                addOptsToZone(myZone,"provide-ixfr","yes");
                }
         } */

	updateZones( zones ); 
	freeZones( zones );
    };
  	
  	
    void Linux_DnsSlaveZoneResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneManualInstance& aManualInstance){
     cout << "---  Linux_DnsSlaveZoneResourceAccess::createInstance() called" << endl; 

        DNSZONE * newZone = NULL;
        Linux_DnsSlaveZoneInstanceName anInstanceName = aManualInstance.getInstanceName();

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
                throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"The zone already exists");
        }
        freeZones(all_zones);

        newZone = (DNSZONE *)calloc(1+1,sizeof(DNSZONE));

        if (newZone)
        {
            // Take in value specified only at Dialog ??//

            newZone->zoneName = (char *)anInstanceName.getName();

	    newZone->zoneType = "slave";
	    
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
           
            newZone->records = NULL;
	    
	    // XferFormat (request-ixfr)
            /*if (aManualInstance.isXferFormatSet())
            {
                if (aManualInstance.getXferFormat() == DNS_XFER_COMPLETE)
                        addOptsToZone(newZone,"request-ixfr","no");
                 else
                        addOptsToZone(newZone,"request-ixfr","yes"); 
            }*/
	    
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
  	
    void Linux_DnsSlaveZoneResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneInstanceName& inst){

        deleteZone( inst.getName() );
    };
	
    
    /* extrinsic methods */
    /*
    virtual CMPIUint32 Linux_DnsSlaveZoneResourceAccess::ApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsSlaveZoneResourceAccess::ApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsSlaveZoneResourceAccess::ApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsSlaveZoneResourceAccess::ApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent) { };
    */
    /*
    virtual CMPIUint32 Linux_DnsSlaveZoneResourceAccess::VerifyOKToApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsSlaveZoneResourceAccess::VerifyOKToApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsSlaveZoneResourceAccess::VerifyOKToApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsSlaveZoneResourceAccess::VerifyOKToApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent) { };
    */

    
    CMPIUint32 Linux_DnsSlaveZoneResourceAccess::disable(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneInstanceName& inst) {

        if ( inst.getName() == NULL )
                return 3;

	return disableZone( inst.getName());

    };
    
    
    CMPIUint32 Linux_DnsSlaveZoneResourceAccess::enable(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSlaveZoneInstanceName& inst) { 

        if ( inst.getName() == NULL )
                return 3;

	enableZone( inst.getName());

    };
    
	
}


