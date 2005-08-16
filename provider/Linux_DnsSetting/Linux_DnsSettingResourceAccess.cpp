 /**
 * Linux_DnsSettingResourceAccess.cpp
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
#include <iostream>

using namespace std;

#include "Linux_DnsSettingResourceAccess.h"

#include "defaultvalues.h"

namespace genProvider {
  
    //Linux_DnsSettingResourceAccess::Linux_DnsSettingResourceAccess();
    Linux_DnsSettingResourceAccess::~Linux_DnsSettingResourceAccess() { };
    
    /* intrinsic methods */
    
    void Linux_DnsSettingResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsSettingInstanceNameEnumeration& instnames){
	
	Linux_DnsSettingInstanceName instanceName;

        instanceName.setNamespace(nsp);
        instanceName.setName(DEFAULT_SERVICE_NAME);

        instnames.addElement(instanceName);
    }
    
  	
    void Linux_DnsSettingResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsSettingManualInstanceEnumeration& instances){

	Linux_DnsSettingManualInstance aManualInstance;
	Linux_DnsSettingInstanceName instanceName;

        instanceName.setNamespace(nsp);
        instanceName.setName(DEFAULT_SERVICE_NAME);
	
	aManualInstance.setInstanceName(instanceName);

        BINDOPTS *bopts = ReadOptions();

	char *forward = getOption(bopts,"forward");
        if ( forward )
        {
		if ( strcmp( forward, "first" ) )
                	aManualInstance.setForward( DNS_FORWARD_FIRST  );

		if ( strcmp( forward, "only" ) )
                        aManualInstance.setForward( DNS_FORWARD_ONLY );

                free( forward );
        }

	char* forwarders = getOption( bopts, "forwarders" );
        if ( forwarders )
        {
        	DnsArray da = DnsArray( forwarders );
                aManualInstance.setForwarders( da.toArray(), da.size() );
		free( forwarders );
        }

        char *directory = getOption(bopts,"directory");
        if ( directory )
        {
                aManualInstance.setConfigurationDirectory( directory );
                free( directory );
        }

        char *port = getOption(bopts,"port");
        if ( port )
        {
                aManualInstance.setPortNumber( atoi( port ) );
                free( port );
        }

        char *tsig = getOption(bopts,"TSIG");
        if ( tsig )
        {
                aManualInstance.setTSIG( atoi( tsig ) );
                free( tsig );
        }

        char *ttl = getOption(bopts,"TTL");
        if ( ttl )
        {
                aManualInstance.setTTL( atoi( ttl ) );
                free( ttl );
        }
	
	instances.addElement(aManualInstance);
    };
  
  	
    Linux_DnsSettingManualInstance 
     Linux_DnsSettingResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsSettingInstanceName& instance){

	Linux_DnsSettingManualInstance aManualInstance;
        aManualInstance.setInstanceName(instance);
	
	BINDOPTS *bopts = ReadOptions();

	char *directory = getOption(bopts,"directory");
	if ( directory != NULL ) 
	{	
		aManualInstance.setConfigurationDirectory( directory );
		free( directory );
	}

        char *forward = getOption(bopts,"forward");
        if ( forward )
        {
                if ( strcmp( forward, "first" ) )
                        aManualInstance.setForward( DNS_FORWARD_FIRST  );

                if ( strcmp( forward, "only" ) )
                        aManualInstance.setForward( DNS_FORWARD_ONLY );

                free( forward );
        }

        char* forwarders = getOption( bopts, "forwarders" );
        if ( forwarders )
        {
                DnsArray da = DnsArray( forwarders );
                aManualInstance.setForwarders( da.toArray(), da.size() );
                free( forwarders );
        }

	char *port = getOption(bopts,"port");
	if ( port != NULL ) 
	{
        	aManualInstance.setPortNumber( atoi( port ) );
		free( port );
        }
	
	char *tsig = getOption(bopts,"TSIG");
	if ( tsig != NULL )
	{
		aManualInstance.setTSIG( atoi( tsig ) );
		free( tsig );
	} 

	char *ttl = getOption(bopts,"TTL");	
	if ( ttl != NULL )
	{
        	aManualInstance.setTTL( atoi( ttl ) );
        	free( ttl );
	}
	return aManualInstance; 
    }
  	
  	
    void Linux_DnsSettingResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsSettingManualInstance& newInstance){
	BINDOPTS *bopt = ReadOptions();

	if ( newInstance.isConfigurationDirectorySet() )
		setOption(bopt, "directory", newInstance.getConfigurationDirectory() );

        if ( newInstance.isForwardSet() )
        {
                if ( newInstance.getForward() == DNS_FORWARD_ONLY )
                	setOption(bopt, "forward", strdup( "only" ) );

                if ( newInstance.getForward() == DNS_FORWARD_FIRST )
                	setOption(bopt, "forward", strdup( "first" ) );
        }

        unsigned int size = 0;
        if ( newInstance.isForwardersSet() )
        {
                const char **forwardersList = newInstance.getForwarders( size );
                DnsArray value_list;

                for (unsigned int i = 0; i < size; i++)
                if (! value_list.isPresent( string( forwardersList[i]) ) )
                        value_list.add( forwardersList[i] );

                setOption( bopt, "forwarders", strdup ( value_list.toString().c_str() ) );
        }

	if ( newInstance.isPortNumberSet() )
	{
		char *port = (char *) malloc(6*sizeof(char));
		sprintf( port, "%lu", newInstance.getPortNumber() );
		setOption(bopt, "port", port ); 
		free(port);
	}
	if ( newInstance.isTSIGSet() )
	{
		char *tsig = (char *) malloc(6*sizeof(char));
                sprintf( tsig, "%d", newInstance.getTSIG() );
        	setOption(bopt, "TSIG", tsig );
		free(tsig);	
	}
        if ( newInstance.isTTLSet() )
	{
                char *ttl = (char *) malloc(20*sizeof(char));
                sprintf( ttl, "%lu", newInstance.getTTL() );
                setOption(bopt, "TTL", ttl );
		free(ttl);
	}
    };
  	
  	/*
    void Linux_DnsSettingResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSettingManualInstance&){};
  	*/
  	/*
    void Linux_DnsSettingResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSettingInstanceName&){};
	*/
    
    /* extrinsic methods */
    /*
    virtual CMPIUint32 Linux_DnsSettingResourceAccess::ApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSettingInstanceName&,
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
    virtual CMPIUint32 Linux_DnsSettingResourceAccess::ApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSettingInstanceName&,
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
    virtual CMPIUint32 Linux_DnsSettingResourceAccess::ApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSettingInstanceName&,
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
    virtual CMPIUint32 Linux_DnsSettingResourceAccess::ApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSettingInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent) { };
    */
    /*
    virtual CMPIUint32 Linux_DnsSettingResourceAccess::VerifyOKToApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSettingInstanceName&,
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
    virtual CMPIUint32 Linux_DnsSettingResourceAccess::VerifyOKToApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSettingInstanceName&,
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
    virtual CMPIUint32 Linux_DnsSettingResourceAccess::VerifyOKToApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSettingInstanceName&,
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
    virtual CMPIUint32 Linux_DnsSettingResourceAccess::VerifyOKToApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsSettingInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent) { };
    */
	
}


