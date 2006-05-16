// =======================================================================
// Linux_DnsNotifyACLForServiceResourceAccess.cpp
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
#include "Linux_DnsNotifyACLForServiceResourceAccess.h"

#include <string>
#include <list>

using namespace std;

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

#define DNS_ATTR_STR	"allow-notify"

namespace genProvider {
  
  //----------------------------------------------------------------------------
  //Linux_DnsNotifyACLForServiceResourceAccess::Linux_DnsNotifyACLForServiceResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsNotifyACLForServiceResourceAccess::~Linux_DnsNotifyACLForServiceResourceAccess() { }
    
  // intrinsic methods

  //----------------------------------------------------------------------------
  void
  Linux_DnsNotifyACLForServiceResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsNotifyACLForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
    
#ifdef DEBUG
    cout << "entering Linux_DnsNotifyACLForService::enumInstanceNames" << endl;
#endif

    BINDOPTS *sopts = ReadOptions(); 
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
      cout << "exiting Linux_DnsNotifyACLForService::enumInstanceNames" << endl;
#endif
      return;
    }
    
    DnsArray list = DnsArray(myoptvalue);
    DnsArrayConstIterator iter;
    
    for ( iter = list.begin(); iter != list.end(); ++iter) {
      Linux_DnsNotifyACLForServiceInstanceName Inst;
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
      cout << "exiting Linux_DnsNotifyACLForService::enumInstanceNames" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsNotifyACLForServiceResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsNotifyACLForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
      cout << "entering Linux_DnsNotifyACLForService::enumInstances" << endl;
#endif

    BINDOPTS *sopts = ReadOptions(); 
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
      cout << "exiting Linux_DnsNotifyACLForService::enumInstances" << endl;
#endif
      return;
    }
    
    DnsArray list = DnsArray( myoptvalue );
    DnsArrayConstIterator iter;
    
    for ( iter = list.begin(); iter != list.end(); ++iter) {
      Linux_DnsNotifyACLForServiceInstanceName Inst;
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
      
      Linux_DnsNotifyACLForServiceManualInstance manualInst;
      manualInst.setInstanceName( Inst );
      
      aManualInstanceEnumeration.addElement(manualInst); 
    }
    freeOptions( sopts );

#ifdef DEBUG
      cout << "exiting Linux_DnsNotifyACLForService::enumInstances" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  Linux_DnsNotifyACLForServiceManualInstance 
  Linux_DnsNotifyACLForServiceResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsNotifyACLForServiceInstanceName& anInstanceName) {

#ifdef DEBUG
      cout << "entering Linux_DnsNotifyACLForService::getInstance" << endl;
#endif
    Linux_DnsNotifyACLForServiceManualInstance manualInst;
    manualInst.setInstanceName( anInstanceName );
    
#ifdef DEBUG
    cout << "exiting Linux_DnsNotifyACLForService::getInstance" << endl;
#endif
    return manualInst;
  }

  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsNotifyACLForServiceResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsNotifyACLForServiceManualInstance& aManualInstance) { }
  */
  
  //----------------------------------------------------------------------------

  Linux_DnsNotifyACLForServiceInstanceName
  Linux_DnsNotifyACLForServiceResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsNotifyACLForServiceManualInstance& aManualInstance) {
    
#ifdef DEBUG
      cout << "entering Linux_DnsNotifyACLForService::createInstance" << endl;
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
      cout << "exiting Linux_DnsNotifyACLForService::createInstance" << endl;
#endif
    return aManualInstance.getInstanceName();
  }

  
  //----------------------------------------------------------------------------

  void
  Linux_DnsNotifyACLForServiceResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsNotifyACLForServiceInstanceName& anInstanceName) {
    
#ifdef DEBUG
      cout << "entering Linux_DnsNotifyACLForService::deleteInstance" << endl;
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
      cout << "exiting Linux_DnsNotifyACLForService::deleteInstance" << endl;
#endif
  }

	

  // Association Interface
  //----------------------------------------------------------------------------

  void Linux_DnsNotifyACLForServiceResourceAccess::referencesSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsNotifyACLForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
      cout << "entering Linux_DnsNotifyACLForService::referencesSetting" << endl;
#endif

    BINDOPTS *sopts = ReadOptions(); 
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
      cout << "exiting Linux_DnsNotifyACLForService::referencesSetting" << endl;
#endif
      return;
    }
    
    DnsArray list = DnsArray(myoptvalue);
    DnsArrayConstIterator iter;
    
    for ( iter = list.begin(); iter != list.end(); ++iter) {
      Linux_DnsNotifyACLForServiceInstanceName Inst;
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
      
      Linux_DnsNotifyACLForServiceManualInstance manualInst;
      manualInst.setInstanceName( Inst );
      
      aManualInstanceEnumeration.addElement(manualInst); 
    } 
    freeOptions( sopts );

#ifdef DEBUG
      cout << "exiting Linux_DnsNotifyACLForService::referencesSetting" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsNotifyACLForServiceResourceAccess::referencesElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsNotifyACLForServiceManualInstanceEnumeration& aManualInstanceEnumeration) {
    
#ifdef DEBUG
      cout << "entering Linux_DnsNotifyACLForService::referencesElement" << endl;
#endif

    BINDOPTS *sopts = ReadOptions();
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
      cout << "exiting Linux_DnsNotifyACLForService::referencesElement" << endl;
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
      
      Linux_DnsNotifyACLForServiceManualInstance inst;
      Linux_DnsNotifyACLForServiceInstanceName instName;
      
      instName.setNamespace( aNameSpaceP );
      instName.setElement( serviceInstanceName );
      instName.setSetting( aSourceInstanceName );
      inst.setInstanceName( instName );
      aManualInstanceEnumeration.addElement(inst); 
    } 
#ifdef DEBUG
      cout << "exiting Linux_DnsNotifyACLForService::referencesElement" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsNotifyACLForServiceResourceAccess::associatorsSetting( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
      cout << "entering Linux_DnsNotifyACLForService::associatorsSetting" << endl;
#endif

    ACL *list_acl = ReadACL();
    
    BINDOPTS *sopts = ReadOptions(); 
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
      cout << "exiting Linux_DnsNotifyACLForService::associatorsSetting" << endl;
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
      cout << "exiting Linux_DnsNotifyACLForService::associatorsSetting" << endl;
#endif
  }

  
  //----------------------------------------------------------------------------

  void Linux_DnsNotifyACLForServiceResourceAccess::associatorsElement( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration) {
    
#ifdef DEBUG
      cout << "entering Linux_DnsNotifyACLForService::associatorsElement" << endl;
#endif

    BINDOPTS *sopts = ReadOptions();
    char *myoptvalue = getOption(sopts,DNS_ATTR_STR);
    
    if ( ! myoptvalue ) {
#ifdef DEBUG
      cout << "exiting Linux_DnsNotifyACLForService::associatorsElement" << endl;
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
      cout << "exiting Linux_DnsNotifyACLForService::associatorsElement" << endl;
#endif
  }

   
  
  // extrinsic methods

	
}


