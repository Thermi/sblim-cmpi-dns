 /**
 * Linux_DnsResourceRecordResourceAccess.cpp
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
 * author:      Tony Gargya >gargya@de.ibm.com>
 * 		Murillo Bernardes <bernarde@br.ibm.com>
 *
 * Contributors: 
 *
 */
#include "Linux_DnsResourceRecordResourceAccess.h"
#include <string>
#include <iostream>

using namespace std;

namespace genProvider {

    //------------------------------------------------------------------------------------
    // Linux_DnsResourceRecordResourceAccess::setInstanceNameProperties()
    //------------------------------------------------------------------------------------

    void
    Linux_DnsResourceRecordResourceAccess::setInstanceNameProperties(const CmpiContext& ctx,
                                                                     const CmpiBroker& mbp,
                                                                     const char* nsp,
                                                                     DNSRECORD * record,
                                                                     DNSZONE * zone,
                                                                     Linux_DnsResourceRecordInstanceName& anInstanceName)
    {
        cout << "--- setInstanceNameProperties() called" << endl;
        anInstanceName.setNamespace(nsp);
        anInstanceName.setName(record->recordName);
        anInstanceName.setZoneName(zone->zoneName);
	
	if (strcmp(record->recordType,"NS") == 0)
        {
            anInstanceName.setType(3);
        }
        else if (strcmp(record->recordType,"A") == 0)
        {
            anInstanceName.setType(6);
        }
        else if (strcmp(record->recordType,"MX") == 0)
        {
            anInstanceName.setType(4);
        }
        else
        {
            anInstanceName.setType(6);  // = Type A 
        }

        anInstanceName.setValue(record->recordValue); 

        cout << "--- setInstanceNameProperties() exited" << endl;
    }
    
    void
    Linux_DnsResourceRecordResourceAccess::setInstanceProperties(const CmpiContext& ctx,
                                                                 const CmpiBroker& mbp,
                                                                 DNSRECORD * record,
                                                                 const Linux_DnsResourceRecordInstanceName& anInstanceName,
                                                                 Linux_DnsResourceRecordManualInstance& aManualInstance)
    {
        cout<<"--- setInstanceProperties() called"<<endl;

        aManualInstance.setInstanceName(anInstanceName);
        aManualInstance.setTTL(60*60*24); 
	aManualInstance.setFamily( DNS_RRFAMILY_INTERNET );

        cout << "--- setInstanceProperties() exited" << endl;
    }   
    //Linux_DnsResourceRecordResourceAccess::Linux_DnsResourceRecordResourceAccess();
    Linux_DnsResourceRecordResourceAccess::~Linux_DnsResourceRecordResourceAccess() { };
    
    /* intrinsic methods */
    
    void Linux_DnsResourceRecordResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsResourceRecordInstanceNameEnumeration& instnames){
     
        DNSZONE * zones = NULL, *all_zones;

        zones = getZones();
	all_zones = zones;

        if (zones)
        {
            for (; zones->zoneName; zones++)
            {
                if (zones->records)
                {
                    DNSRECORD * records = NULL;

                    for (records = zones->records; records->recordName; ++records)
                    {
                        Linux_DnsResourceRecordInstanceName instanceName;
                        cout << "--- Calling setInstanceNameProperties()" << endl; 
                        printf ("%s %s\n", zones->zoneName, records->recordName);
                        setInstanceNameProperties(ctx, mbp, nsp, records,
                                                  zones, instanceName);

                        instnames.addElement(instanceName);
                        cout << "--- Added to enumeration"  << endl; 
                    }
                }

            }
	    freeZones( all_zones );
        }
        cout << "--- enumInstanceNames () exited"  << endl; 
    }

  	
    void Linux_DnsResourceRecordResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsResourceRecordManualInstanceEnumeration& instances){
	 
        cout << "--- enumInstances() called" << endl; 

        DNSZONE * zones, *all_zones;

        cout << "---- calling getZones() " << endl;

        zones = getZones();
	all_zones = zones;

        if (zones)
        {
            for (; zones->zoneName; zones++)
            {
                if (zones->records)
                {
                    DNSRECORD * records = NULL;

                    for (records= zones->records; records->recordName; ++records)
                    {
                        Linux_DnsResourceRecordManualInstance instance;
                        Linux_DnsResourceRecordInstanceName instanceName;

                        printf ("recordName= %s recordType= %s recordValue= %s recordZoneName= %s\n",
                                records->recordName, records->recordType,
                                records->recordValue, records->recordZoneName);

                        cout << "--- Calling setInstanceNameProperties() for record" << endl; 
                        printf (" -----%s \n", records->recordName);

                        setInstanceNameProperties(ctx, mbp, nsp, records,
                                                  zones, instanceName);

                        setInstanceProperties(ctx, mbp, records,
                                              instanceName, instance);

                        instances.addElement(instance);
                        cout << "--- Added to enumeration"  << endl; 
                    } 
                }
                else
                {
                    printf(" ---- Zone %s has no records \n", zones->zoneName);
                }
            } // end for loop for zones
	    freeZones( all_zones );
        }
        cout << "--- enumInstances() exited"  << endl; 
   }
     	
  	
    Linux_DnsResourceRecordManualInstance 
     Linux_DnsResourceRecordResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsResourceRecordInstanceName& anInstanceName ){
     	
      	cout << "--- getInstance() called" << endl; 

        DNSZONE * zones = NULL, *all_zones;
        Linux_DnsResourceRecordManualInstance instance;

        cout << "---- calling getZones() " << endl;

        zones = getZones();
	all_zones = zones;

        if (zones)
        {
            for (; zones->zoneName ; zones++)
            {
                if (zones->records)
                {
                    DNSRECORD * records = NULL;
                    for (records = zones->records; records->recordName; ++records)
                    {
                        printf ("--- records->recordName is %s\n", records->recordName);
                        printf ("--- records->recordValue is %s\n", records->recordValue);
                        printf ("--- Name of Instance is %s\n", anInstanceName.getName());
                        if ((strcmp(records->recordName, anInstanceName.getName())) == 0)
                        {
                            printf (" ------ record in zone found -----%s \n", zones->zoneName);
                            cout << "--- Calling setInstanceProperties()" << endl; 
                            // Linux_DnsResourceRecordManualInstance instance;
                            setInstanceProperties(ctx, mbp, records,
                                                  anInstanceName, instance);

                            cout << "--- getInstance() exited "  << endl; 
                            return instance;
                        }
                    }
                }
            }
	    freeZones( all_zones );
        }
    }
  	
  /*	
    void Linux_DnsResourceRecordResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsResourceRecordManualInstance& newInstance){

	DNSZONE *zones = getZones();
	if ( ! zones )
		throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");

	DNSZONE *myZone = findZone( zones, newInstance.getZoneName();
	if ( ! myZone )
		throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");
	
        DNSRECORD *rec = findRecord( myZone, newInstance.getName() );
	if ( ! rec )
		throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"RR does not exist");

    };
  */	
  	
    void Linux_DnsResourceRecordResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsResourceRecordManualInstance& aManualInstance){
     cout << "--- createRR Instance() called" << endl; 

        DNSZONE * zones = NULL;
        DNSZONE * origZones = NULL;
        DNSRECORD * records = NULL;
        DNSRECORD * newRecord = NULL;

        Linux_DnsResourceRecordInstanceName anInstanceName;
        anInstanceName = aManualInstance.getInstanceName();

        newRecord = (DNSRECORD *)calloc(1+1,sizeof(DNSRECORD));

        if (newRecord)
        {
            // Take in value specified only at Dialog ??//
            newRecord->recordName = (char *)anInstanceName.getName();
            newRecord->recordZoneName = (char *)anInstanceName.getZoneName(); 

            if (! (anInstanceName.isTypeSet()))
            {
                newRecord->recordType = "A";
                cout << "---- Type was not set - set to A" << endl;
            }
            else
            {
                switch (anInstanceName.getType())
                {
                case 3:
                    newRecord->recordType = "NS";
                    break;
                case 4:
                    newRecord->recordType = "MX";
                    break;
                case 6:
                    newRecord->recordType = "A";
                    break;
                default:
                    newRecord->recordType = "A";
                    break;
                }
            }
            cout << "----  newRecord->recordType is " << newRecord->recordType << endl;
            newRecord->recordValue = (char*)anInstanceName.getValue();
            printf("---- newRecord->recordValue is %s\n", newRecord->recordValue);
            
	    // if not at dialog then use following default required values (smt_dns_ra_support.h) for a Zone 
            // may need to get them from default section in Service 


            // list of mof attributes not in smt_dns_ra_support.h
            //class
            //enabled
            //TTL

        }

        cout << "---- calling getZones() " << endl;
        zones = getZones();
        origZones = zones;

        if ( ! zones )
        {
            // no zones defined at all - cannot create a record 
            cout << "---- no zones exists " << endl;
            throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"--- No zone defined - cannot create a RR");
        }
        else
        {
            // at least one zone already defined   
            for (; zones->zoneName; zones++)
            {
                // check to see if record already exists
                if ((strcmp(zones->zoneName, newRecord->recordZoneName)) == 0)
                {
                    cout << "---- zoneName found " << zones->zoneName << endl;

                    if (zones->records != NULL)
                    {
                        cout << "Zones has already records" << endl;

                        for (records = zones->records; ((records->recordName) != NULL); ++records)
                        {

                            cout << "records->recordName is " << records->recordName << endl; 

                            if (((strcmp(records->recordName, newRecord->recordName)) == 0) && 
                                ((strcmp(records->recordType, newRecord->recordType)) == 0) &&
                                ((strcmp(records->recordValue, newRecord->recordValue)) == 0))
                            {
                                cout << "--- Record already exists " << endl;
                                throw CmpiStatus(CMPI_RC_ERR_ALREADY_EXISTS," Record already exists");
                            }
                        }
                    }

                    cout << "---- calling addRecord() " << endl;

                    cout << "zones->zoneName is " << zones->zoneName << endl;
                    cout << "recordName= " << newRecord->recordName << endl;
                    cout << "recordZoneName= " << newRecord->recordZoneName << endl;
                    cout << "recordType= " << newRecord->recordType << endl;
                    cout << "recordValue = " << newRecord->recordValue << endl;
                    
		    records = addRecord(zones, newRecord);
                    updateZones(origZones);
		    freeZones( origZones );

                    cout << "new Record added to zone " << zones->zoneName << endl; 
                    cout << " ---- exiting RR creatInstance" << endl;
                    // what if it fails ?
                    return;
                }
            }
            cout << "---- no zone exists with given zoneName" << endl;
	    freeZones( origZones );
            throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"No zone exists with given zoneName");    
        }
        cout << " ---- exiting RR createInstance" << endl;
    }
  	
  	
    void Linux_DnsResourceRecordResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsResourceRecordInstanceName& inst){

	DNSZONE *zones = getZones();
	if ( ! zones )
		return ;

	DNSZONE *myZone = findZone( zones, inst.getZoneName() );
	if ( ! myZone )
		return ;
	
        DNSRECORD *rec = findRecord( myZone, inst.getName() );
	if ( ! rec )
		return ;

	freeZones( zones );
	deleteRR( inst.getName(), myZone->zoneFileName );

    };
	
    
    /* extrinsic methods */
    /*
    virtual CMPIUint32 Linux_DnsResourceRecordResourceAccess::ApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsResourceRecordInstanceName&,
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
    virtual CMPIUint32 Linux_DnsResourceRecordResourceAccess::ApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsResourceRecordInstanceName&,
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
    virtual CMPIUint32 Linux_DnsResourceRecordResourceAccess::ApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsResourceRecordInstanceName&,
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
    virtual CMPIUint32 Linux_DnsResourceRecordResourceAccess::ApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsResourceRecordInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent) { };
    */
    /*
    virtual CMPIUint32 Linux_DnsResourceRecordResourceAccess::VerifyOKToApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsResourceRecordInstanceName&,
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
    virtual CMPIUint32 Linux_DnsResourceRecordResourceAccess::VerifyOKToApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsResourceRecordInstanceName&,
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
    virtual CMPIUint32 Linux_DnsResourceRecordResourceAccess::VerifyOKToApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsResourceRecordInstanceName&,
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
    virtual CMPIUint32 Linux_DnsResourceRecordResourceAccess::VerifyOKToApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsResourceRecordInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent) { };
    */
    
    /* return values:
	1 -> resource record not found 
    */ 
    CMPIUint32 Linux_DnsResourceRecordResourceAccess::disable(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsResourceRecordInstanceName& inst) {

	DNSZONE *zones = getZones();
	if ( ! zones )
		return 1;

	DNSZONE *myZone = findZone( zones, inst.getZoneName() );
	if ( ! myZone )
		return 1;
	
        DNSRECORD *rec = findRecord( myZone, inst.getName() );
	if ( ! rec )
		return 1;

	return disableRR( inst.getName(), myZone->zoneFileName );

     };
    
    
    CMPIUint32 Linux_DnsResourceRecordResourceAccess::enable(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsResourceRecordInstanceName& inst) {

	DNSZONE *zones = getZones();
	if ( ! zones )
		return 1;

	DNSZONE *myZone = findZone( zones, inst.getZoneName() );
	if ( ! myZone )
		return 1;
	
        DNSRECORD *rec = findRecord( myZone, inst.getName() );
	if ( ! rec )
		return 1;

	return enableRR( inst.getName(), myZone->zoneFileName );

    };
    
	
}


