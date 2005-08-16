 /**
 * Linux_DnsHintZoneResourceAccess.cpp
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

#include "Linux_DnsHintZoneResourceAccess.h"

namespace genProvider {
    //------------------------------------------------------------------------------------
    // Linux_DnsMasterZoneResourceAccess::setInstanceNameProperties()
    //------------------------------------------------------------------------------------
    void
    Linux_DnsHintZoneResourceAccess::setInstanceNameProperties(const CmpiContext& ctx,
                                                           const CmpiBroker& mbp,
                                                           const char* nsp,
                                                           DNSZONE * zone,
                                                           Linux_DnsHintZoneInstanceName& anInstanceName)
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
    Linux_DnsHintZoneResourceAccess::setInstanceProperties(const CmpiContext& ctx,
                                                       const CmpiBroker& mbp,
                                                       DNSZONE * zone,
                                                       const Linux_DnsHintZoneInstanceName& anInstanceName,
                                                       Linux_DnsHintZoneManualInstance& aManualInstance)
    {
        cout<<"--- setInstanceProperties() called"<<endl;

        aManualInstance.setInstanceName(anInstanceName);
        aManualInstance.setType(DNS_ZONETYPE_HINT);
	aManualInstance.setResourceRecordFile(zone->zoneFileName);
       
        cout << "--- setInstanceProperties() exited" << endl;
    }  
    //Linux_DnsHintZoneResourceAccess::Linux_DnsHintZoneResourceAccess();
    Linux_DnsHintZoneResourceAccess::~Linux_DnsHintZoneResourceAccess() { };
    
    /* intrinsic methods */
    
    void Linux_DnsHintZoneResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsHintZoneInstanceNameEnumeration& instnames){
	cout << "Linux_DnsHintZoneResourceAccess::enumInstanceNames()" << endl;	
	DNSZONE * zones, *all_zones;

        cout << "--- enumInstanceNames() called" << endl; 
        cout << "---- calling getZones() " << endl;
        zones = getZones();	//getZonesByType("hint");
	all_zones = zones;
        if (zones)
        {
            for (; zones->zoneName != NULL ; zones++)
            {	
                if ( strcmp(zones->zoneType, "hint") )
                        continue;

                Linux_DnsHintZoneInstanceName instanceName;

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
    
  	
    void Linux_DnsHintZoneResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsHintZoneManualInstanceEnumeration& instances){
	cout << "Linux_DnsHintZoneResourceAccess::enumInstances()" << endl;
	cout << "--- enumInstances() called" << endl;

        DNSZONE * zones = NULL, *all_zones;

        cout << "---- calling getZones() " << endl;

        zones = getZones();	//getZonesByType("hint");
	all_zones = zones;

        if (zones)
        {
            for (; zones->zoneName != NULL ; zones++)
            {	    
                if ( strcmp(zones->zoneType, "hint") )
                        continue;

                Linux_DnsHintZoneManualInstance instance;
                Linux_DnsHintZoneInstanceName instanceName;

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
    }
  	
	
    Linux_DnsHintZoneManualInstance 
     Linux_DnsHintZoneResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsHintZoneInstanceName& anInstanceName){
	cout << "--- getInstance() called" << endl; 

        DNSZONE * zones, *all_zones;
	Linux_DnsHintZoneManualInstance instance;

        cout << "---- calling getZones() " << endl;

        zones = getZones();	//getZonesByType("hint");
	all_zones = zones;
        if (zones)
        {
            for (; zones->zoneName != NULL ; zones++)
            {
                if ( strcmp(zones->zoneType, "hint") )
                        continue;

                cout << "--- zones->zoneName is "  << endl;
                printf ("%s \n", zones->zoneName);

                cout << "--- Name of Instance is "  << endl;
                printf ("%s \n", anInstanceName.getName());

                if ((strcmp(zones->zoneName, anInstanceName.getName())) == 0)
                {
                    cout << "--- Calling setInstanceProperties()" << endl; 
                    setInstanceProperties(ctx, mbp, zones,
                                          anInstanceName, instance);

                    cout << "--- getInstance() exited "  << endl; 

                    return instance; 
                }
            } // end for
	    freeZones( all_zones );
        }  // end if             
    }
  	
  	
    void Linux_DnsHintZoneResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsHintZoneManualInstance& newInstance){

	cout << "--- setInstance() called" << endl;

        DNSZONE *zones, *myZone;

        zones = getZones();
        myZone = findZone(zones, newInstance.getInstanceName().getName());

        if ( ! myZone )
                throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");

        if ( strcmp(myZone->zoneType,"forward") != 0 )
                throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"Zone does not exist");

        if ( newInstance.isResourceRecordFileSet() ) {
                free(myZone->zoneFileName);
                myZone->zoneFileName = strdup(newInstance.getResourceRecordFile());
        }
        updateZones(zones);
	freeZones( zones );
    };
  	
  	
    void Linux_DnsHintZoneResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneManualInstance& aManualInstance){
	
	cout << "--- createInstance() called" << endl;

	DNSZONE * newZone = NULL;
	Linux_DnsHintZoneInstanceName anInstanceName = aManualInstance.getInstanceName();
	
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

		newZone->zoneType = "hint"; 

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
  	
  	
    void Linux_DnsHintZoneResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName& inst){

        deleteZone( inst.getName() );

    };
	
    
    /* extrinsic methods */
    /*
    virtual CMPIUint32 Linux_DnsHintZoneResourceAccess::ApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsHintZoneResourceAccess::ApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsHintZoneResourceAccess::ApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsHintZoneResourceAccess::ApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent) { };
    */
    /*
    virtual CMPIUint32 Linux_DnsHintZoneResourceAccess::VerifyOKToApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsHintZoneResourceAccess::VerifyOKToApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsHintZoneResourceAccess::VerifyOKToApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&,
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
    virtual CMPIUint32 Linux_DnsHintZoneResourceAccess::VerifyOKToApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent) { };
    */
    
    CMPIUint32 Linux_DnsHintZoneResourceAccess::disable(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName& inst) {

        if ( inst.getName() == NULL )
                return 3;

        disableZone( inst.getName() );
    };
    
    
    CMPIUint32 Linux_DnsHintZoneResourceAccess::enable(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName& inst) {

        if ( inst.getName() == NULL )
                return 3;

        enableZone( inst.getName() );

     };
    
	
}


