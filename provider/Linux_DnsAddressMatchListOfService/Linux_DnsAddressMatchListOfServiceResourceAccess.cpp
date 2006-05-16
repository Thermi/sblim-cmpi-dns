// =======================================================================
// Linux_DnsAddressMatchListOfServiceResourceAccess.cpp
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
#include "Linux_DnsAddressMatchListOfServiceResourceAccess.h"

#include <string>
#include <list>

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsAddressMatchListOfServiceResourceAccess::Linux_DnsAddressMatchListOfServiceResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListOfServiceResourceAccess::~Linux_DnsAddressMatchListOfServiceResourceAccess() { }
    
  // intrinsic methods
  /*
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListOfServiceResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
      
    int instanceNameN = 1;
    for (int x=0; x < instanceNameN; ++x) {
      
      //place here the code retrieving your instanceName
      
      Linux_DnsAddressMatchListOfServiceInstanceName instanceName;
      
    }      
  
  }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsAddressMatchListOfServiceResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration& aManualInstanceEnumeration) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsAddressMatchListOfServiceManualInstance 
  Linux_DnsAddressMatchListOfServiceResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListOfServiceInstanceName& anInstanceName) {

    Linux_DnsAddressMatchListOfServiceManualInstance manualInstance;

  
  }
  */
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsAddressMatchListOfServiceResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsAddressMatchListOfServiceManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsAddressMatchListOfServiceInstanceName
  Linux_DnsAddressMatchListOfServiceResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAddressMatchListOfServiceManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsAddressMatchListOfServiceResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAddressMatchListOfServiceInstanceName& anInstanceName) { }
	*/
	

  // Association Interface
  //----------------------------------------------------------------------------

  void Linux_DnsAddressMatchListOfServiceResourceAccess::referencesDependent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering DnsAddressMatchListOfService::referencesDependent" << endl;
#endif

    ACL *list_acl = ReadACL();
    ACL *all_acls = list_acl;
    
    if (list_acl) {
      for (; list_acl->key; list_acl++) {	    
	Linux_DnsAddressMatchListInstanceName aclInstanceName;
	
	aclInstanceName.setNamespace( aNameSpaceP );
	aclInstanceName.setName( list_acl->key );
	aclInstanceName.setServiceName( DEFAULT_SERVICE_NAME );
	
	Linux_DnsServiceInstanceName serviceInstanceName;
	
	serviceInstanceName.setNamespace( aNameSpaceP );
	serviceInstanceName.setName( DEFAULT_SERVICE_NAME );
	serviceInstanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
	serviceInstanceName.setSystemName( DEFAULT_SYSTEM_NAME );
	serviceInstanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );
	
	Linux_DnsAddressMatchListOfServiceManualInstance aManualInstance;
	Linux_DnsAddressMatchListOfServiceInstanceName anInstanceName;
	
	anInstanceName.setNamespace( aNameSpaceP );
	anInstanceName.setAntecedent( serviceInstanceName );
	anInstanceName.setDependent( aclInstanceName );
	
	aManualInstance.setInstanceName( anInstanceName );
	
	aManualInstanceEnumeration.addElement( aManualInstance );
      }
    }
    freeACL( all_acls );

#ifdef DEBUG
    cout << "exiting DnsAddressMatchListOfService::referencesDependent" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsAddressMatchListOfServiceResourceAccess::referencesAntecedent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering DnsAddressMatchListOfService::referencesAntecedent" << endl;
#endif

    ACL *list_acl = ReadACL();
    ACL *all_acls = list_acl;
    
    if (list_acl) {
      for (; list_acl->key; list_acl++) {
	if ( strcmp( list_acl->key, aSourceInstanceName.getName() ) != 0 )
	  continue;
	
	Linux_DnsAddressMatchListInstanceName aclInstanceName;
	
	aclInstanceName.setNamespace( aNameSpaceP );
	aclInstanceName.setName( list_acl->key );
	aclInstanceName.setServiceName( DEFAULT_SERVICE_NAME );
	
	Linux_DnsServiceInstanceName serviceInstanceName;
	
	serviceInstanceName.setNamespace( aNameSpaceP );
	serviceInstanceName.setName( DEFAULT_SERVICE_NAME );
	serviceInstanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
	serviceInstanceName.setSystemName( DEFAULT_SYSTEM_NAME );
	serviceInstanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );
	
	Linux_DnsAddressMatchListOfServiceManualInstance aManualInstance;
	Linux_DnsAddressMatchListOfServiceInstanceName anInstanceName;
	
	anInstanceName.setNamespace( aNameSpaceP );	
	anInstanceName.setAntecedent( serviceInstanceName );
	anInstanceName.setDependent( aclInstanceName );
	
	aManualInstance.setInstanceName( anInstanceName );
	
	aManualInstanceEnumeration.addElement( aManualInstance );
      }
    }
    freeACL( all_acls );

#ifdef DEBUG
    cout << "exiting DnsAddressMatchListOfService::referencesAntecedent" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsAddressMatchListOfServiceResourceAccess::associatorsDependent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering DnsAddressMatchListOfService::associatorsDependent" << endl;
#endif

    ACL *list_acl = ReadACL();
    ACL *all_acls = list_acl;
    
    if (list_acl) {
      for (; list_acl->key; list_acl++) {	    
	Linux_DnsAddressMatchListInstanceName aclInstanceName;
	
	aclInstanceName.setNamespace( aNameSpaceP );
	aclInstanceName.setName( list_acl->key );
	aclInstanceName.setServiceName( DEFAULT_SERVICE_NAME );
	
	Linux_DnsAddressMatchListInstance inst;
	inst.setInstanceName( aclInstanceName );
	
	anInstanceEnumeration.addElement( inst );
      }
    }
    freeACL( all_acls );

#ifdef DEBUG
    cout << "exiting DnsAddressMatchListOfService::associatorsDependent" << endl;
#endif
  }
  
  
  //----------------------------------------------------------------------------

  void Linux_DnsAddressMatchListOfServiceResourceAccess::associatorsAntecedent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering DnsAddressMatchListOfService::associatorsAntecedent" << endl;
#endif

    ACL *list_acl = ReadACL();
    ACL *all_acls = list_acl;
    
    if (list_acl) {
      for (; list_acl->key; list_acl++) {	    
	if ( strcmp( list_acl->key, aSourceInstanceName.getName() ) != 0 )
	  continue;
	
	Linux_DnsAddressMatchListInstanceName aclInstanceName;
	
	aclInstanceName.setNamespace( aNameSpaceP );
	aclInstanceName.setName( list_acl->key );
	aclInstanceName.setServiceName( DEFAULT_SERVICE_NAME );
	
	Linux_DnsServiceInstanceName instanceName;
	
	instanceName.setNamespace(aNameSpaceP);
	instanceName.setName(DEFAULT_SERVICE_NAME);
	instanceName.setSystemCreationClassName(DEFAULT_SYSTEM_CREATION_CLASS_NAME);
	instanceName.setSystemName(DEFAULT_SYSTEM_NAME);
	instanceName.setCreationClassName(DEFAULT_CREATION_CLASS_NAME);
	
	Linux_DnsServiceInstance inst;
	inst.setInstanceName( instanceName );
	
	anInstanceEnumeration.addElement( inst );
      }
    }
    freeACL( all_acls );

#ifdef DEBUG
    cout << "exiting DnsAddressMatchListOfService::associatorsAntecedent" << endl;
#endif
  }

   
  
  // extrinsic methods

	
}


