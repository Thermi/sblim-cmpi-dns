 /**
 * Linux_DnsAddressMatchListResourceAccess.cpp
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
#include "Linux_DnsAddressMatchListResourceAccess.h"

using namespace std;

namespace genProvider {
     
    //Linux_DnsAddressMatchListResourceAccess::Linux_DnsAddressMatchListResourceAccess();
    Linux_DnsAddressMatchListResourceAccess::~Linux_DnsAddressMatchListResourceAccess() { };
    
    /* intrinsic methods */
    
    void Linux_DnsAddressMatchListResourceAccess::enumInstanceNames(
     const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
     Linux_DnsAddressMatchListInstanceNameEnumeration& instnames){
 
	ACL *list_acl = ReadACL();
	ACL *acls = list_acl;

	if (list_acl)
        {
            for (; list_acl->key; list_acl++)
            {
                Linux_DnsAddressMatchListInstanceName anInstanceName;

	        anInstanceName.setNamespace(nsp);
        	anInstanceName.setName(list_acl->key);
		anInstanceName.setServiceName( DEFAULT_SERVICE_NAME );

                instnames.addElement(anInstanceName);
            }
        }
	freeACL( acls );
    }
    
  	
    void Linux_DnsAddressMatchListResourceAccess::enumInstances(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char *nsp,
     const char* *properties,
  	 Linux_DnsAddressMatchListManualInstanceEnumeration& instances){

        ACL *list_acl = ReadACL();
        ACL *acls = list_acl;

        if (list_acl)
        {
            for (; list_acl->key != NULL ; list_acl++)
            {
                Linux_DnsAddressMatchListInstanceName anInstanceName;
		Linux_DnsAddressMatchListManualInstance aManualInstance;

                anInstanceName.setNamespace( nsp );
                anInstanceName.setName( list_acl->key );
		anInstanceName.setServiceName( DEFAULT_SERVICE_NAME );

		aManualInstance.setInstanceName( anInstanceName );

		DnsArray da = DnsArray( list_acl->value );
		aManualInstance.setAddressList( da.toArray(), da.size() );
		aManualInstance.setAddressListType( DNS_AMLTYPE_AML );

                instances.addElement( aManualInstance );
            }
        }
	freeACL( acls );
    };
  	
  	
    Linux_DnsAddressMatchListManualInstance 
     Linux_DnsAddressMatchListResourceAccess::getInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsAddressMatchListInstanceName& instanceName){
      Linux_DnsAddressMatchListManualInstance instance;
      
        ACL *list_acl = ReadACL();
        ACL *acls = list_acl;

        if ( !list_acl )
		throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"ACL doesn't exist");	

        for (; list_acl->key; list_acl++)
        {
		if ( strcmp( list_acl->key, instanceName.getName() ) == 0 )
		{
                	Linux_DnsAddressMatchListManualInstance aManualInstance;

                	aManualInstance.setInstanceName( instanceName );
			DnsArray da = DnsArray( list_acl->value );
			aManualInstance.setAddressList( da.toArray(), da.size() );
			aManualInstance.setAddressListType( DNS_AMLTYPE_AML );

			freeACL( acls );
			return aManualInstance;
		}
        }
        freeACL( acls );
	throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"ACL does not exist");
    }
  	
  	
    void Linux_DnsAddressMatchListResourceAccess::setInstance(
     const CmpiContext& ctx,
     const CmpiBroker &mbp,
     const char* *properties,
     const Linux_DnsAddressMatchListManualInstance& newInstance){
	cout << "Linux_DnsAddressMatchListResourceAccess::setInstance()" << endl;

        Linux_DnsAddressMatchListInstanceName anInstanceName = newInstance.getInstanceName();

        ACL *all_acl = ReadACL();
	char *acl_value = getACL(all_acl, anInstanceName.getName() );

        unsigned int size; //, len = 0;
        const char **addressList = newInstance.getAddressList( size );

        /*for (unsigned int i = 0; i < size; i++)
                len += strlen(addressList[i]);

        acl_value = (char *)realloc(acl_value, ( strlen(acl_value) + len + 2*size + 1)*sizeof(char) ); 
        char *p = strchr( acl_value, '}');
	*p = '\0';

        for (unsigned int i = 0; i < size; i++)
        {
                strcat( acl_value, addressList[i] );
                strcat( acl_value, "; " );
        }
        strcat( acl_value, "}" );
	*/
	DnsArray value_list;
        for (unsigned int i = 0; i < size; i++)
        	if (! value_list.isPresent( string( addressList[i]) ) )
        		value_list.add( addressList[i] );

	ACL *iter = all_acl;
        while ( iter && iter->key)
        {
                if ( strcmp( iter->key, anInstanceName.getName() ) == 0 )
                {
			free( iter->value );
			iter->value = strdup( value_list.toString().c_str() );
			break;
                }
		iter++;
        }

        WriteACL( all_acl );
	freeACL( all_acl );
    };
  	
  	
    void Linux_DnsAddressMatchListResourceAccess::createInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsAddressMatchListManualInstance& aManualInstance){
	cout << "Linux_DnsAddressMatchListResourceAccess::createInstance()" << endl;

	Linux_DnsAddressMatchListInstanceName anInstanceName = aManualInstance.getInstanceName();
	
	ACL *all_acls = ReadACL();
	if ( getACL(all_acls, anInstanceName.getName()) )
	{ 	
		freeACL( all_acls );
		throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"ACL already exist"); 
	}
	freeACL( all_acls );

	ACL *new_acl = (ACL *) malloc(sizeof(ACL));

	new_acl->key = strdup( anInstanceName.getName() );

	unsigned int size, len = 0;
	if ( aManualInstance.isAddressListSet() )
	{
		const char **addressList = aManualInstance.getAddressList( size );
		/*
		for (unsigned int i = 0; i < size; i++)
			len += strlen(addressList[i]);

		char *acl_value = (char *)malloc( (len + 3 + 2*size + 1)*sizeof(char) ); // len + { + } +  + size*( ;) + NULL
		strcpy( acl_value, "{ ");

		for (unsigned int i = 0; i < size; i++)
		{
			strcat( acl_value, addressList[i] );
			strcat( acl_value, "; " );
		}
		strcat( acl_value, "}" );
	
		new_acl->value = acl_value;
		*/
	       	DnsArray value_list;
	        for (unsigned int i = 0; i < size; i++)
                if (! value_list.isPresent( string( addressList[i]) ) )
                        value_list.add( addressList[i] );
		new_acl->value = strdup( value_list.toString().c_str() ); 
	}
	else
		new_acl->value = strdup("{ }");

	addACL( new_acl );

	free( new_acl->value );
	free( new_acl->key );
    };
  	
  	
    void Linux_DnsAddressMatchListResourceAccess::deleteInstance(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsAddressMatchListInstanceName& instanceName){

	deleteACL( instanceName.getName() );
    };
	
    
    /* extrinsic methods */
    /*
    virtual CMPIUint32 Linux_DnsAddressMatchListResourceAccess::ApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsAddressMatchListInstanceName&,
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
    virtual CMPIUint32 Linux_DnsAddressMatchListResourceAccess::ApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsAddressMatchListInstanceName&,
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
    virtual CMPIUint32 Linux_DnsAddressMatchListResourceAccess::ApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsAddressMatchListInstanceName&,
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
    virtual CMPIUint32 Linux_DnsAddressMatchListResourceAccess::ApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsAddressMatchListInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent) { };
    */
    /*
    virtual CMPIUint32 Linux_DnsAddressMatchListResourceAccess::VerifyOKToApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsAddressMatchListInstanceName&,
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
    virtual CMPIUint32 Linux_DnsAddressMatchListResourceAccess::VerifyOKToApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsAddressMatchListInstanceName&,
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
    virtual CMPIUint32 Linux_DnsAddressMatchListResourceAccess::VerifyOKToApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsAddressMatchListInstanceName&,
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
    virtual CMPIUint32 Linux_DnsAddressMatchListResourceAccess::VerifyOKToApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsAddressMatchListInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent) { };
    */
	
}


