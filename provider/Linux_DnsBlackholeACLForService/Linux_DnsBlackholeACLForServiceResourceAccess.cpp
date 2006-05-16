// =======================================================================
// Linux_DnsBlackholeACLForServiceResourceAccess.cpp
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
#include "Linux_DnsBlackholeACLForServiceResourceAccess.h"

#include <string>
#include <list>

using namespace std;

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

#define DNS_ATTR_STR	"blackhole"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsBlackholeACLForServiceResourceAccess::Linux_DnsBlackholeACLForServiceResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsBlackholeACLForServiceResourceAccess::~Linux_DnsBlackholeACLForServiceResourceAccess() { }
    
  // intrinsic methods

  //----------------------------------------------------------------------------
  void
  Linux_DnsBlackholeACLForServiceResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsBlackholeACLForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
    cout << "entering Linux_DnsBlackholeACLForService::enumInstanceNames" << endl;
#endif

    BINDOPTS *sopts = ReadOptions(); 
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
    cout << "exiting Linux_DnsBlackholeACLForService::enumInstanceNames" << endl;
#endif
      return;
    }
    
    DnsArray list = DnsArray(myoptvalue);
    DnsArrayConstIterator iter;
    
    for ( iter = list.begin(); iter != list.end(); ++iter) {
      Linux_DnsBlackholeACLForServiceInstanceName Inst;
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
#ifdef DEBUG
    cout << "exiting Linux_DnsBlackholeACLForService::enumInstanceNames" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsBlackholeACLForServiceResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsBlackholeACLForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsBlackholeACLForService::enumInstances" << endl;
#endif
    BINDOPTS *sopts = ReadOptions(); 
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
    cout << "exiting Linux_DnsBlackholeACLForService::enumInstances" << endl;
#endif
      return;
    }
    
    DnsArray list = DnsArray( myoptvalue );
    DnsArrayConstIterator iter;
    
    for ( iter = list.begin(); iter != list.end(); ++iter) {
      Linux_DnsBlackholeACLForServiceInstanceName Inst;
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
      
      Linux_DnsBlackholeACLForServiceManualInstance manualInst;
      manualInst.setInstanceName( Inst );
      
      aManualInstanceEnumeration.addElement(manualInst); 
    }
#ifdef DEBUG
    cout << "exiting Linux_DnsBlackholeACLForService::enumInstances" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  Linux_DnsBlackholeACLForServiceManualInstance 
  Linux_DnsBlackholeACLForServiceResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsBlackholeACLForServiceInstanceName& anInstanceName) {

#ifdef DEBUG
    cout << "entering Linux_DnsBlackholeACLForService::getInstance" << endl;
#endif

    Linux_DnsBlackholeACLForServiceManualInstance manualInst;
    manualInst.setInstanceName( anInstanceName );
    
#ifdef DEBUG
    cout << "exiting Linux_DnsBlackholeACLForService::getInstance" << endl;
#endif
    return manualInst;
  }

  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsBlackholeACLForServiceResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsBlackholeACLForServiceManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------

  Linux_DnsBlackholeACLForServiceInstanceName
  Linux_DnsBlackholeACLForServiceResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsBlackholeACLForServiceManualInstance& aManualInstance) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsBlackholeACLForService::createInstance" << endl;
#endif
    BINDOPTS* sopts = ReadOptions();
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    DnsArray list;
    
    if (myoptvalue)
      list.populate(myoptvalue);
    
    list.add( string(aManualInstance.getInstanceName().getSetting().getName()) );
    setOption(sopts, DNS_ATTR_STR,  list.toString().c_str());
    
#ifdef DEBUG
    cout << "exiting Linux_DnsBlackholeACLForService::createInstance" << endl;
#endif
    return aManualInstance.getInstanceName();
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsBlackholeACLForServiceResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsBlackholeACLForServiceInstanceName& anInstanceName) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsBlackholeACLForService::deleteInstance" << endl;
#endif

    BINDOPTS* sopts = ReadOptions();
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    DnsArray list;
    
    if (myoptvalue)
      list.populate(myoptvalue);
    
    list.remove( string(anInstanceName.getSetting().getName()) );
    setOption(sopts, DNS_ATTR_STR,  list.toString().c_str());

#ifdef DEBUG
    cout << "exiting Linux_DnsBlackholeACLForService::deleteInstance" << endl;
#endif
  }

	

  // Association Interface
  //----------------------------------------------------------------------------

  void Linux_DnsBlackholeACLForServiceResourceAccess::referencesSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsBlackholeACLForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsBlackholeACLForService::referencesSetting" << endl;
#endif

    BINDOPTS *sopts = ReadOptions(); 
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
    cout << "exiting Linux_DnsBlackholeACLForService::referencesSetting" << endl;
#endif
      return;
    }
    
    DnsArray list = DnsArray(myoptvalue);
    DnsArrayConstIterator iter;
    
    for ( iter = list.begin(); iter != list.end(); ++iter) {
      Linux_DnsBlackholeACLForServiceInstanceName Inst;
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
      
      Linux_DnsBlackholeACLForServiceManualInstance manualInst;
      manualInst.setInstanceName( Inst );
      
      aManualInstanceEnumeration.addElement(manualInst); 
    } 
#ifdef DEBUG
    cout << "exiting Linux_DnsBlackholeACLForService::referencesSetting" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsBlackholeACLForServiceResourceAccess::referencesElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsBlackholeACLForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsBlackholeACLForService::referencesElement" << endl;
#endif

    BINDOPTS *sopts = ReadOptions();
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
    cout << "exiting Linux_DnsBlackholeACLForService::referencesElement" << endl;
#endif
      return;
    }
    
    DnsArray list = DnsArray(myoptvalue);
    DnsArrayConstIterator iter;
    
    for ( iter = list.begin(); iter != list.end(); ++iter) {
      if ( strcmp( (*iter).c_str(), aSourceInstanceName.getName()) )
	continue;
      
      Linux_DnsServiceInstanceName serviceInstanceName;
      
      serviceInstanceName.setNamespace( aNameSpaceP );
      serviceInstanceName.setName( DEFAULT_SERVICE_NAME );
      serviceInstanceName.setSystemCreationClassName( DEFAULT_SYSTEM_CREATION_CLASS_NAME );
      serviceInstanceName.setSystemName( DEFAULT_SYSTEM_NAME );
      serviceInstanceName.setCreationClassName( DEFAULT_CREATION_CLASS_NAME );
      
      Linux_DnsBlackholeACLForServiceManualInstance inst;
      Linux_DnsBlackholeACLForServiceInstanceName instName;
      instName.setNamespace( aNameSpaceP );
      instName.setElement( serviceInstanceName );
      instName.setSetting( aSourceInstanceName );
      inst.setInstanceName( instName );
      aManualInstanceEnumeration.addElement(inst); 
    }

#ifdef DEBUG
    cout << "entering Linux_DnsBlackholeACLForService::referencesElement" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsBlackholeACLForServiceResourceAccess::associatorsSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsBlackholeACLForService::associatorsSetting" << endl;
#endif

    ACL *list_acl = ReadACL();
    
    BINDOPTS *sopts = ReadOptions(); 
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
    cout << "exiting Linux_DnsBlackholeACLForService::associatorsSetting" << endl;
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
    freeACL( list_acl ); 

#ifdef DEBUG
    cout << "entering Linux_DnsBlackholeACLForService::associatorsSetting" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsBlackholeACLForServiceResourceAccess::associatorsElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsBlackholeACLForService::associatorsElement" << endl;
#endif

    BINDOPTS *sopts = ReadOptions();
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
    cout << "exiting Linux_DnsBlackholeACLForService::associatorsElement" << endl;
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
    cout << "exiting Linux_DnsBlackholeACLForService::associatorsElement" << endl;
#endif
  }

   
  
  // extrinsic methods

	
}


