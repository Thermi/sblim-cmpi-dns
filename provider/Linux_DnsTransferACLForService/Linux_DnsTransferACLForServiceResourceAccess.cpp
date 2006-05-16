// =======================================================================
// Linux_DnsTransferACLForServiceResourceAccess.cpp
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
#include "Linux_DnsTransferACLForServiceResourceAccess.h"

#include <string>
#include <list>

using namespace std;

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

#define DNS_ATTR_STR	"allow-transfer"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsTransferACLForServiceResourceAccess::Linux_DnsTransferACLForServiceResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsTransferACLForServiceResourceAccess::~Linux_DnsTransferACLForServiceResourceAccess() { }
    
  // intrinsic methods

  //----------------------------------------------------------------------------
  void
  Linux_DnsTransferACLForServiceResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsTransferACLForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
    cout << "entering Linux_DnsTransferACLForService::enumInstanceNames" << endl;
#endif

    BINDOPTS *sopts = ReadOptions(); 
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( myoptvalue ) {
      DnsArray list = DnsArray(myoptvalue);
      DnsArrayConstIterator iter;
      
      for ( iter = list.begin(); iter != list.end(); ++iter) {
	Linux_DnsTransferACLForServiceInstanceName Inst;
	Linux_DnsAddressMatchListInstanceName addrList;
	Linux_DnsServiceInstanceName serviceInstanceName;
	
	Inst.setNamespace( aNameSpaceP );
	addrList.setNamespace( aNameSpaceP );
	
	serviceInstanceName.setNamespace( aNameSpaceP );
	serviceInstanceName.setName( DEFAULT_SERVICE_NAME );
	serviceInstanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
	serviceInstanceName.setSystemName( DEFAULT_SYSTEM_NAME );
	serviceInstanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );
	
	addrList.setName( (*iter).c_str() );
	addrList.setServiceName( DEFAULT_SERVICE_NAME );
	Inst.setSetting( addrList );
      Inst.setElement( serviceInstanceName );
      anInstanceNameEnumeration.addElement(Inst); 
      }
    }
    freeOptions( sopts );
    
#ifdef DEBUG
    cout << "exiting Linux_DnsTransferACLForService::enumInstanceNames" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsTransferACLForServiceResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsTransferACLForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsTransferACLForService::enumInstances" << endl;
#endif

    BINDOPTS *sopts = ReadOptions(); 
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if (  myoptvalue ) {
      DnsArray list = DnsArray( myoptvalue );
      DnsArrayConstIterator iter;
      
      for ( iter = list.begin(); iter != list.end(); ++iter) {
	Linux_DnsTransferACLForServiceInstanceName Inst;
	Linux_DnsAddressMatchListInstanceName addrList;
	Linux_DnsServiceInstanceName serviceInstanceName;
	
	Inst.setNamespace( aNameSpaceP );
	addrList.setNamespace( aNameSpaceP );
	
	serviceInstanceName.setNamespace( aNameSpaceP );
	serviceInstanceName.setName( DEFAULT_SERVICE_NAME );
	serviceInstanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
	serviceInstanceName.setSystemName( DEFAULT_SYSTEM_NAME );
	serviceInstanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );
	
	addrList.setName( (*iter).c_str() );
	addrList.setServiceName( DEFAULT_SERVICE_NAME, 1 );
	Inst.setSetting( addrList );
	Inst.setElement( serviceInstanceName );
	
	Linux_DnsTransferACLForServiceManualInstance manualInst;
	manualInst.setInstanceName( Inst );
	
	aManualInstanceEnumeration.addElement(manualInst); 
      }
    }
    freeOptions( sopts );

#ifdef DEBUG
    cout << "exiting Linux_DnsTransferACLForService::enumInstances" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  Linux_DnsTransferACLForServiceManualInstance 
  Linux_DnsTransferACLForServiceResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsTransferACLForServiceInstanceName& anInstanceName) {

#ifdef DEBUG
    cout << "entering Linux_DnsTransferACLForService::getInstance" << endl;
#endif
    Linux_DnsTransferACLForServiceManualInstance manualInst;
    manualInst.setInstanceName( anInstanceName );
    
#ifdef DEBUG
    cout << "exiting Linux_DnsTransferACLForService::getInstance" << endl;
#endif
    return manualInst;
  }

  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsTransferACLForServiceResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsTransferACLForServiceManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------

  Linux_DnsTransferACLForServiceInstanceName
  Linux_DnsTransferACLForServiceResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsTransferACLForServiceManualInstance& aManualInstance) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsTransferACLForService::createInstance" << endl;
#endif
    BINDOPTS* sopts = ReadOptions();
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    DnsArray list;
    
    if (myoptvalue)
      list.populate(myoptvalue);
    
    list.add( string(aManualInstance.getInstanceName().getSetting().getName()) );
    setOption(sopts, DNS_ATTR_STR,  list.toString().c_str());
    freeOptions( sopts );
    
#ifdef DEBUG
    cout << "exiting Linux_DnsTransferACLForService::createInstance" << endl;
#endif
    return aManualInstance.getInstanceName();
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsTransferACLForServiceResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsTransferACLForServiceInstanceName& anInstanceName) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsTransferACLForService::deleteInstance" << endl;
#endif

    BINDOPTS* sopts = ReadOptions();
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    DnsArray list;
    
    if (myoptvalue)
      list.populate(myoptvalue);
    
    list.remove( string(anInstanceName.getSetting().getName()) );
    setOption(sopts, DNS_ATTR_STR,  list.toString().c_str());
    freeOptions( sopts );

#ifdef DEBUG
    cout << "exiting Linux_DnsTransferACLForService::deleteInstance" << endl;
#endif
  }

	

  // Association Interface
  //----------------------------------------------------------------------------

  void Linux_DnsTransferACLForServiceResourceAccess::referencesSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsTransferACLForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsTransferACLForService::referencesSetting" << endl;
#endif

    BINDOPTS *sopts = ReadOptions(); 
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( myoptvalue ) {
      DnsArray list = DnsArray(myoptvalue);
      DnsArrayConstIterator iter;
      
      for ( iter = list.begin(); iter != list.end(); ++iter) {
	Linux_DnsTransferACLForServiceInstanceName Inst;
	Linux_DnsAddressMatchListInstanceName addrList;
	Linux_DnsServiceInstanceName serviceInstanceName;
	
	Inst.setNamespace( aNameSpaceP );
	addrList.setNamespace( aNameSpaceP );
	
	serviceInstanceName.setNamespace( aNameSpaceP );
	serviceInstanceName.setName( DEFAULT_SERVICE_NAME );
	serviceInstanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
	serviceInstanceName.setSystemName( DEFAULT_SYSTEM_NAME );
	serviceInstanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );
	
	addrList.setName( (*iter).c_str() );
	addrList.setServiceName( DEFAULT_SERVICE_NAME );
	Inst.setNamespace( aNameSpaceP );
	Inst.setSetting( addrList );
	Inst.setElement( serviceInstanceName );
	
	Linux_DnsTransferACLForServiceManualInstance manualInst;
	manualInst.setInstanceName( Inst );
	
	aManualInstanceEnumeration.addElement(manualInst); 
      }
    }
    freeOptions( sopts );

#ifdef DEBUG
    cout << "exiting Linux_DnsTransferACLForService::referencesSetting" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsTransferACLForServiceResourceAccess::referencesElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsTransferACLForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsTransferACLForService::referencesElement" << endl;
#endif

    Linux_DnsServiceInstanceName serviceInstanceName;
    
    BINDOPTS *sopts = ReadOptions();
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( myoptvalue ) {
      DnsArray list = DnsArray(myoptvalue);
      DnsArrayConstIterator iter;
      
      for ( iter = list.begin(); iter != list.end(); ++iter) {
	if ( strcmp( (*iter).c_str(), aSourceInstanceName.getName() ) )
	  continue;	
	
	serviceInstanceName.setNamespace( aNameSpaceP );
	serviceInstanceName.setName( DEFAULT_SERVICE_NAME );
	serviceInstanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
	serviceInstanceName.setSystemName( DEFAULT_SYSTEM_NAME );
	serviceInstanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );
	
	Linux_DnsTransferACLForServiceManualInstance inst;
	Linux_DnsTransferACLForServiceInstanceName instName;
	instName.setNamespace( aNameSpaceP );
	instName.setElement( serviceInstanceName );
	instName.setSetting( aSourceInstanceName );
	inst.setInstanceName( instName );
	aManualInstanceEnumeration.addElement(inst); 
      }
    }
    free(sopts);

#ifdef DEBUG
    cout << "exiting Linux_DnsTransferACLForService::referencesElement" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsTransferACLForServiceResourceAccess::associatorsSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsTransferACLForService::associatorsSetting" << endl;
#endif

    ACL *list_acl = ReadACL();
    
    if ( list_acl ) {
      BINDOPTS *sopts = ReadOptions(); 
      char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
      
      if ( myoptvalue ) {
	DnsArray list = DnsArray(myoptvalue);
	DnsArrayConstIterator iter;
	
	for ( iter = list.begin(); iter != list.end(); ++iter) {
	  Linux_DnsAddressMatchListInstance addrInst;
	  Linux_DnsAddressMatchListInstanceName addrInstName;
	  
	  addrInstName.setNamespace( aNameSpaceP );
	  addrInstName.setName( (*iter).c_str() );
	  addrInstName.setServiceName( DEFAULT_SERVICE_NAME );
	  
	  addrInst.setInstanceName( addrInstName );
	  char *aclValue = getACL(list_acl, (*iter).c_str());
	  if ( ! aclValue )
	    continue;
	  
	  DnsArray aclArray = DnsArray( aclValue );
	  addrInst.setAddressList( aclArray.toArray(), aclArray.size() );	
	  addrInst.setAddressListType( DNS_AMLTYPE_AML );			
	  anInstanceEnumeration.addElement(addrInst); 
	}
      }
      freeOptions( sopts );
    }
    freeACL( list_acl ); 

#ifdef DEBUG
    cout << "exiting Linux_DnsTransferACLForService::associatorsSetting" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsTransferACLForServiceResourceAccess::associatorsElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsTransferACLForService::associatorsElement" << endl;
#endif

    Linux_DnsServiceInstance inst;
    Linux_DnsServiceInstanceName instanceName;
    
    BINDOPTS *sopts = ReadOptions();
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( myoptvalue ) {
      DnsArray list = DnsArray(myoptvalue);
      DnsArrayConstIterator iter;
      
      for ( iter = list.begin(); iter != list.end(); ++iter) {
	if ( strcmp( (*iter).c_str(), aSourceInstanceName.getName() ) )
	  continue;	
	instanceName.setNamespace( aNameSpaceP );
	instanceName.setName( DEFAULT_SERVICE_NAME );
	instanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
	instanceName.setSystemName( DEFAULT_SYSTEM_NAME );
	instanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );
	
	inst.setInstanceName(instanceName);
	
	anInstanceEnumeration.addElement(inst);
      }
    }

#ifdef DEBUG
    cout << "exiting Linux_DnsTransferACLForService::associatorsElement" << endl;
#endif
  }

   
  
  // extrinsic methods

	
}


