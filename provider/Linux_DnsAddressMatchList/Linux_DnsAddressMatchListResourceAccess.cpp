// =======================================================================
// Linux_DnsAddressMatchListResourceAccess.cpp
//     created on Fri, 3 Mar 2006 using ECUTE
// 
// Copyright (c) 2006, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Common Public License from
// http://oss.software.ibm.com/developerworks/opensource/license-cpl.html
//
// Author:        generated
//
// Contributors:
//                Murillo Bernardes <bernarde@br.ibm.com>
//                Wolfgang Taphorn <taphorn@de.ibm.com>
//
// =======================================================================
//
// 
#include "Linux_DnsAddressMatchListResourceAccess.h"

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include <string>
#include <list>

#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsAddressMatchListResourceAccess::Linux_DnsAddressMatchListResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListResourceAccess::~Linux_DnsAddressMatchListResourceAccess() { }
    
  // intrinsic methods

  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsAddressMatchListInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
    cout << "entering Linux_DnsAddressMatchList::enumInstanceNames" << endl;
#endif

    ACL *list_acl = ReadACL();
    ACL *acls = list_acl;
    
    if (list_acl) {
      for (; list_acl->key; list_acl++) {
	Linux_DnsAddressMatchListInstanceName anInstanceName;
	
	anInstanceName.setNamespace(aNameSpaceP);
	anInstanceName.setName(list_acl->key);
	anInstanceName.setServiceName( DEFAULT_SERVICE_NAME );
	
	anInstanceNameEnumeration.addElement(anInstanceName);
      }
    }
    freeACL( acls );

#ifdef DEBUG
    cout << "exiting Linux_DnsAddressMatchList::enumInstanceNames" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsAddressMatchListResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsAddressMatchListManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsAddressMatchList::enumInstances" << endl;
#endif

    ACL *list_acl = ReadACL();
    ACL *acls = list_acl;
    
    if (list_acl) {
      for (; list_acl->key != NULL ; list_acl++) {
	Linux_DnsAddressMatchListInstanceName anInstanceName;
	Linux_DnsAddressMatchListManualInstance aManualInstance;
	
	anInstanceName.setNamespace( aNameSpaceP );
	anInstanceName.setName( list_acl->key );
	anInstanceName.setServiceName( DEFAULT_SERVICE_NAME );
	
	aManualInstance.setInstanceName( anInstanceName );
	
	DnsArray da = DnsArray( list_acl->value );
	aManualInstance.setAddressList( da.toArray(), da.size() );
	aManualInstance.setAddressListType( DNS_AMLTYPE_AML );
	
	aManualInstanceEnumeration.addElement( aManualInstance );
      }
    }
    freeACL( acls );

#ifdef DEBUG
    cout << "entering Linux_DnsAddressMatchList::enumInstances" << endl;
#endif
  }
  
  
  //----------------------------------------------------------------------------

  Linux_DnsAddressMatchListManualInstance 
  Linux_DnsAddressMatchListResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& anInstanceName) {

#ifdef DEBUG
    cout << "entering Linux_DnsAddressMatchList::getInstance" << endl;
#endif

    ACL *list_acl = ReadACL();
    ACL *acls = list_acl;
    
    if ( !list_acl )
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"ACL doesn't exist");	
    
    for (; list_acl->key; list_acl++) {
      if ( strcmp( list_acl->key, anInstanceName.getName() ) == 0 ) {
	Linux_DnsAddressMatchListManualInstance aManualInstance;
	
	aManualInstance.setInstanceName( anInstanceName );
	DnsArray da = DnsArray( list_acl->value );
	aManualInstance.setAddressList( da.toArray(), da.size() );
	aManualInstance.setAddressListType( DNS_AMLTYPE_AML );
	
	freeACL( acls );
	
#ifdef DEBUG
	cout << "exiting Linux_DnsAddressMatchList::getInstance" << endl;
#endif
	
	return aManualInstance;
      }
    }
    freeACL( acls );
    throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"ACL does not exist");
  }

  //----------------------------------------------------------------------------

  void
  Linux_DnsAddressMatchListResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsAddressMatchListManualInstance& aManualInstance) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsAddressMatchList::setInstance" << endl;
#endif

    Linux_DnsAddressMatchListInstanceName anInstanceName = aManualInstance.getInstanceName();
    
    ACL *all_acl = ReadACL();
    char *acl_value = getACL(all_acl, anInstanceName.getName() );
    
    unsigned int size; //, len = 0;
    const char **addressList = aManualInstance.getAddressList( size );
    
    /*for (unsigned int i = 0; i < size; i++)
      len += strlen(addressList[i]);
      
      acl_value = (char *)realloc(acl_value, ( strlen(acl_value) + len + 2*size + 1)*sizeof(char) ); 
      char *p = strchr( acl_value, '}');
      *p = '\0';
      
      for (unsigned int i = 0; i < size; i++) {
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
    while ( iter && iter->key) {
      if ( strcmp( iter->key, anInstanceName.getName() ) == 0 ) {
	free( iter->value );
	iter->value = strdup( value_list.toString().c_str() );
	break;
      }
      iter++;
    }
    
    WriteACL( all_acl );
    freeACL( all_acl );

#ifdef DEBUG
    cout << "eexiting Linux_DnsAddressMatchList::setInstance" << endl;
#endif
  }
  
  
  //----------------------------------------------------------------------------

  Linux_DnsAddressMatchListInstanceName
  Linux_DnsAddressMatchListResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAddressMatchListManualInstance& aManualInstance) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsAddressMatchList::createInstance" << endl;
#endif

    Linux_DnsAddressMatchListInstanceName anInstanceName = aManualInstance.getInstanceName();
    
    ACL *all_acls = ReadACL();
    if ( getACL(all_acls, anInstanceName.getName()) ) { 	
      freeACL( all_acls );
      throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER,"ACL already exist"); 
    }
    freeACL( all_acls );
    
    ACL *new_acl = (ACL *) malloc(sizeof(ACL));
    
    new_acl->key = strdup( anInstanceName.getName() );
    
    unsigned int size, len = 0;
    if ( aManualInstance.isAddressListSet() ) {
      const char **addressList = aManualInstance.getAddressList( size );
      DnsArray value_list;
      for (unsigned int i = 0; i < size; i++)
	if (! value_list.isPresent( string( addressList[i]) ) )
	  value_list.add( addressList[i] );
      new_acl->value = strdup( value_list.toString().c_str() ); 
      
    } else
      new_acl->value = strdup("{ }");
    
    addACL( new_acl );
    
    free( new_acl->value );
    free( new_acl->key );
    
#ifdef DEBUG
    cout << "exiting Linux_DnsAddressMatchList::createInstance" << endl;
#endif

    return aManualInstance.getInstanceName();
  }
  
  
  //----------------------------------------------------------------------------

  void
  Linux_DnsAddressMatchListResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAddressMatchListInstanceName& anInstanceName) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsAddressMatchList::deleteInstance" << endl;
#endif

    deleteACL( anInstanceName.getName() );

#ifdef DEBUG
    cout << "exiting Linux_DnsAddressMatchList::deleteInstance" << endl;
#endif
  }

	

  
  // extrinsic methods

  /*
  CMPIUint32 Linux_DnsAddressMatchListResourceAccess::ApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAddressMatchListInstanceName& anInstanceName,
      const CIM_CollectionOfMSEsInstanceName& Collection,
      int isCollectionPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CMPIBoolean& ContinueOnError,
      int isContinueOnErrorPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent,
      char**& CanNotApply,
      CMPICount& CanNotApplySize) { }
  */

  /*
  CMPIUint32 Linux_DnsAddressMatchListResourceAccess::ApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAddressMatchListInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent) { }
  */

  /*
  CMPIUint32 Linux_DnsAddressMatchListResourceAccess::ApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAddressMatchListInstanceName& anInstanceName,
      const CIM_CollectionOfMSEsInstanceName& Collection,
      int isCollectionPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CMPIBoolean& ContinueOnError,
      int isContinueOnErrorPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      char**& CanNotApply,
      CMPICount& CanNotApplySize) { }
  */

  /*
  CMPIUint32 Linux_DnsAddressMatchListResourceAccess::ApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAddressMatchListInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) { }
  */

  /*
  CMPIUint32 Linux_DnsAddressMatchListResourceAccess::VerifyOKToApplyIncrementalChangeToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAddressMatchListInstanceName& anInstanceName,
      const CIM_CollectionOfMSEsInstanceName& Collection,
      int isCollectionPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent,
      char**& CanNotApply,
      CMPICount& CanNotApplySize) { }
  */

  /*
  CMPIUint32 Linux_DnsAddressMatchListResourceAccess::VerifyOKToApplyIncrementalChangeToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAddressMatchListInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent) { }
  */

  /*
  CMPIUint32 Linux_DnsAddressMatchListResourceAccess::VerifyOKToApplyToCollection(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAddressMatchListInstanceName& anInstanceName,
      const CIM_CollectionOfMSEsInstanceName& Collection,
      int isCollectionPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      char**& CanNotApply,
      CMPICount& CanNotApplySize) { }
  */

  /*
  CMPIUint32 Linux_DnsAddressMatchListResourceAccess::VerifyOKToApplyToMSE(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAddressMatchListInstanceName& anInstanceName,
      const CIM_ManagedSystemElementInstanceName& MSE,
      int isMSEPresent,
      const CmpiDateTime& TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime& MustBeCompletedBy,
      int isMustBeCompletedByPresent) { }
  */

	
}


