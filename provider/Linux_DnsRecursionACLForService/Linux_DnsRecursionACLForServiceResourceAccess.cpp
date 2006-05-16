// =======================================================================
// Linux_DnsRecursionACLForServiceResourceAccess.cpp
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
#include "Linux_DnsRecursionACLForServiceResourceAccess.h"

#include <string>
#include <list>

using namespace std;

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

#define DNS_ATTR_STR	"allow-recursion"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsRecursionACLForServiceResourceAccess::Linux_DnsRecursionACLForServiceResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsRecursionACLForServiceResourceAccess::~Linux_DnsRecursionACLForServiceResourceAccess() { }
    
  // intrinsic methods

  //----------------------------------------------------------------------------
  void
  Linux_DnsRecursionACLForServiceResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsRecursionACLForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsRecursionACLForService::enumInstanceNames" << endl;
#endif

    BINDOPTS *sopts = ReadOptions(); 
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
    cout << "exiting Linux_DnsRecursionACLForService::enumInstanceNames" << endl;
#endif
      return;
    }
    
    DnsArray list = DnsArray(myoptvalue);
    DnsArrayConstIterator iter;
    
    for ( iter = list.begin(); iter != list.end(); ++iter) {
      Linux_DnsRecursionACLForServiceInstanceName Inst;
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
    freeOptions( sopts ); 

#ifdef DEBUG
    cout << "exiting Linux_DnsRecursionACLForService::enumInstanceNames" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsRecursionACLForServiceResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsRecursionACLForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsRecursionACLForService::enumInstances" << endl;
#endif

    BINDOPTS *sopts = ReadOptions(); 
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
    cout << "exiting Linux_DnsRecursionACLForService::enumInstances" << endl;
#endif
      return;
    }
    
    DnsArray list = DnsArray( myoptvalue );
    DnsArrayConstIterator iter;
    
    for ( iter = list.begin(); iter != list.end(); ++iter) {
      Linux_DnsRecursionACLForServiceInstanceName Inst;
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
      
      Linux_DnsRecursionACLForServiceManualInstance manualInst;
      manualInst.setInstanceName( Inst );
      
      aManualInstanceEnumeration.addElement(manualInst); 
    }
    freeOptions( sopts );

#ifdef DEBUG
    cout << "exiting Linux_DnsRecursionACLForService::enumInstances" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  Linux_DnsRecursionACLForServiceManualInstance 
  Linux_DnsRecursionACLForServiceResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsRecursionACLForServiceInstanceName& anInstanceName) {

#ifdef DEBUG
    cout << "entering Linux_DnsRecursionACLForService::getInstance" << endl;
#endif
    Linux_DnsRecursionACLForServiceManualInstance manualInst;
    manualInst.setInstanceName( anInstanceName );
    
#ifdef DEBUG
    cout << "exiting Linux_DnsRecursionACLForService::getInstance" << endl;
#endif
    return manualInst;
  }

  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsRecursionACLForServiceResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsRecursionACLForServiceManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------

  Linux_DnsRecursionACLForServiceInstanceName
  Linux_DnsRecursionACLForServiceResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsRecursionACLForServiceManualInstance& aManualInstance) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsRecursionACLForService::createInstance" << endl;
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
    cout << "exiting Linux_DnsRecursionACLForService::createInstance" << endl;
#endif
    return aManualInstance.getInstanceName();
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsRecursionACLForServiceResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsRecursionACLForServiceInstanceName& anInstanceName) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsRecursionACLForService::deleteInstance" << endl;
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
    cout << "exiting Linux_DnsRecursionACLForService::deleteInstance" << endl;
#endif
  }

	

  // Association Interface
  //----------------------------------------------------------------------------

  void Linux_DnsRecursionACLForServiceResourceAccess::referencesSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsRecursionACLForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsRecursionACLForService::referencesSetting" << endl;
#endif
    BINDOPTS *sopts = ReadOptions(); 
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
    cout << "exiting Linux_DnsRecursionACLForService::referencesSetting" << endl;
#endif
      return;
    }
    
    DnsArray list = DnsArray(myoptvalue);
    DnsArrayConstIterator iter;
    
    for ( iter = list.begin(); iter != list.end(); ++iter) {
      Linux_DnsRecursionACLForServiceInstanceName Inst;
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
      
      Linux_DnsRecursionACLForServiceManualInstance manualInst;
      manualInst.setInstanceName( Inst );
      
      aManualInstanceEnumeration.addElement(manualInst); 
    } 
    freeOptions( sopts );

#ifdef DEBUG
    cout << "exiting Linux_DnsRecursionACLForService::referencesSetting" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsRecursionACLForServiceResourceAccess::referencesElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsRecursionACLForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
  
#ifdef DEBUG
    cout << "entering Linux_DnsRecursionACLForService::referencesElement" << endl;
#endif
    BINDOPTS *sopts = ReadOptions();
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
    cout << "exiting Linux_DnsRecursionACLForService::referencesElement" << endl;
#endif
      return;
    }
    
    DnsArray list = DnsArray(myoptvalue);
    DnsArrayConstIterator iter;
    
    for ( iter = list.begin(); iter != list.end(); ++iter) {
      if ( strcmp( (*iter).c_str(), aSourceInstanceName.getName() ) )
	continue;
      
      Linux_DnsServiceInstanceName serviceInstanceName;
      
      serviceInstanceName.setNamespace( aNameSpaceP );
      serviceInstanceName.setName( DEFAULT_SERVICE_NAME );
      serviceInstanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
      serviceInstanceName.setSystemName( DEFAULT_SYSTEM_NAME );
      serviceInstanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );
      
      Linux_DnsRecursionACLForServiceManualInstance inst;
      Linux_DnsRecursionACLForServiceInstanceName instName;
      instName.setNamespace( aNameSpaceP );
      instName.setElement( serviceInstanceName );
      instName.setSetting( aSourceInstanceName );
      inst.setInstanceName( instName );
      aManualInstanceEnumeration.addElement(inst); 
    }

#ifdef DEBUG
    cout << "exiting Linux_DnsRecursionACLForService::referencesElement" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsRecursionACLForServiceResourceAccess::associatorsSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsRecursionACLForService::associatorsSetting" << endl;
#endif
    ACL *list_acl = ReadACL();
    
    BINDOPTS *sopts = ReadOptions(); 
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
    cout << "exiting Linux_DnsRecursionACLForService::associatorsSetting" << endl;
#endif
      return;
    }
    
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
    freeOptions( sopts );
    freeACL( list_acl );

#ifdef DEBUG
    cout << "exiting Linux_DnsRecursionACLForService::associatorsSetting" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsRecursionACLForServiceResourceAccess::associatorsElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsRecursionACLForService::associatorsElement" << endl;
#endif
    BINDOPTS *sopts = ReadOptions();
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
    cout << "exiting Linux_DnsRecursionACLForService::associatorsElement" << endl;
#endif
      return;
    }
    
    DnsArray list = DnsArray(myoptvalue);
    DnsArrayConstIterator iter;
    
    for ( iter = list.begin(); iter != list.end(); ++iter) {
      if ( strcmp( (*iter).c_str(), aSourceInstanceName.getName() ) )
	continue;
      
      Linux_DnsServiceInstance inst;
      Linux_DnsServiceInstanceName instanceName;
      
      instanceName.setNamespace( aNameSpaceP );
      instanceName.setName( DEFAULT_SERVICE_NAME );
      instanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
      instanceName.setSystemName( DEFAULT_SYSTEM_NAME );
      instanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );
      
      inst.setInstanceName(instanceName);
      
      anInstanceEnumeration.addElement(inst);
    }

#ifdef DEBUG
    cout << "exiting Linux_DnsRecursionACLForService::associatorsElement" << endl;
#endif
  }

   
  
  // extrinsic methods

	
}


