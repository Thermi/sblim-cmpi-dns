// =======================================================================
// Linux_DnsAddressMatchListsForServiceExternal.cpp
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
// 
// Copyright (c) 2006, 2009, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Eclipse Public License from
// http://www.opensource.org/licenses/eclipse-1.0.php
//
// Author:        generated
//
// Contributors:
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 

#include "Linux_DnsAddressMatchListsForServiceExternal.h"

namespace genProvider {
	
	//----------------------------------------------------------------------------
  Linux_DnsAddressMatchListsForServiceExternal::Linux_DnsAddressMatchListsForServiceExternal(
    const CmpiBroker& aBroker,
    const CmpiContext& aContext ) 
    : m_broker(aBroker),
    m_context(aContext) { }
   
	//----------------------------------------------------------------------------
  Linux_DnsAddressMatchListsForServiceExternal::~Linux_DnsAddressMatchListsForServiceExternal() { }
    
	//----------------------------------------------------------------------------
  void 
  Linux_DnsAddressMatchListsForServiceExternal::enumInstanceNames(
    const char *aNameSpaceP,
    Linux_DnsAddressMatchListsForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {

    CmpiObjectPath classObjectPath(aNameSpaceP,"Linux_DnsAddressMatchListsForService");
    CmpiEnumeration cmpiEnumeration = 
      m_broker.enumInstanceNames(m_context,classObjectPath);
    while (cmpiEnumeration.hasNext()) {
      CmpiObjectPath objectPath = cmpiEnumeration.getNext();
      Linux_DnsAddressMatchListsForServiceInstanceName instanceName(objectPath);
      anInstanceNameEnumeration.addElement(instanceName);
    }
  
  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListsForServiceExternal::enumInstances(
    const char *aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsAddressMatchListsForServiceInstanceEnumeration& anInstanceEnumeration) {
   		
    CmpiObjectPath classObjectPath(aNameSpaceP,"Linux_DnsAddressMatchListsForService");
    CmpiEnumeration cmpiEnumeration = 
      m_broker.enumInstances(m_context,classObjectPath,aPropertiesPP);
    while (cmpiEnumeration.hasNext()) {
      CmpiInstance cmpiInstance = cmpiEnumeration.getNext();
      Linux_DnsAddressMatchListsForServiceInstance instance(cmpiInstance,aNameSpaceP);
      anInstanceEnumeration.addElement(instance);
    }
  
  }
  	  
	//----------------------------------------------------------------------------
  Linux_DnsAddressMatchListsForServiceInstance
  Linux_DnsAddressMatchListsForServiceExternal::getInstance(
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListsForServiceInstanceName& anInstanceName) {
    
    CmpiObjectPath cmpiObjectPath = anInstanceName.getObjectPath();
    CmpiInstance cmpiInstance = 
      m_broker.getInstance(m_context,cmpiObjectPath,aPropertiesPP);
  
    return Linux_DnsAddressMatchListsForServiceInstance(cmpiInstance,anInstanceName.getNamespace());
  
  }
      
	//----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListsForServiceExternal::setInstance(
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListsForServiceInstance& anInstance) {
  
    CmpiObjectPath cmpiObjectPath = anInstance.getInstanceName().getObjectPath();
    CmpiInstance cmpiInstance = anInstance.getCmpiInstance();
    m_broker.setInstance(m_context,cmpiObjectPath,cmpiInstance,aPropertiesPP);
  
  }
      
	//----------------------------------------------------------------------------
  Linux_DnsAddressMatchListsForServiceInstanceName
  Linux_DnsAddressMatchListsForServiceExternal::createInstance(
    const Linux_DnsAddressMatchListsForServiceInstance& anInstance) {
  
    CmpiObjectPath cmpiObjectPath = anInstance.getInstanceName().getObjectPath();
    CmpiInstance cmpiInstance = anInstance.getCmpiInstance();
    return Linux_DnsAddressMatchListsForServiceInstanceName(
		m_broker.createInstance(m_context,cmpiObjectPath,cmpiInstance));

  }
  
	//----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListsForServiceExternal::deleteInstance(
    const Linux_DnsAddressMatchListsForServiceInstanceName& anInstanceName) {
    
    CmpiObjectPath cmpiObjectPath = anInstanceName.getObjectPath();
    m_broker.deleteInstance(m_context,cmpiObjectPath);
  
  }
  // Reference calls

  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListsForServiceExternal::referencesGroupComponent( 
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListsForServiceInstanceEnumeration& anInstanceEnumeration) {
      
    CmpiObjectPath cmpiObjectPath = aSourceInstanceName.getObjectPath();

    CmpiEnumeration cmpiEnumeration = m_broker.references(
      m_context,
      cmpiObjectPath,
      "Linux_DnsAddressMatchList",
      "GroupComponent",
      aPropertiesPP);

    while (cmpiEnumeration.hasNext()) {
      CmpiInstance cmpiInstance = cmpiEnumeration.getNext();
      Linux_DnsAddressMatchListsForServiceInstance instance(cmpiInstance,aNameSpaceP);
      anInstanceEnumeration.addElement(instance);
    }      

  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListsForServiceExternal::referenceNamesGroupComponent( 
    const char* aNameSpaceP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListsForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
      
    CmpiObjectPath cmpiObjectPath = aSourceInstanceName.getObjectPath();

    CmpiEnumeration cmpiEnumeration = m_broker.referenceNames(
      m_context,
      cmpiObjectPath,
      "Linux_DnsAddressMatchList",
      "GroupComponent");

    while (cmpiEnumeration.hasNext()) {
      CmpiObjectPath cmpiInstanceName = cmpiEnumeration.getNext();
      Linux_DnsAddressMatchListsForServiceInstanceName instanceName(cmpiInstanceName);
      anInstanceNameEnumeration.addElement(instanceName);
    }      

  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListsForServiceExternal::referencesPartComponent( 
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListsForServiceInstanceEnumeration& anInstanceEnumeration){
      
    CmpiObjectPath cmpiObjectPath = aSourceInstanceName.getObjectPath();
  
    CmpiEnumeration cmpiEnumeration = m_broker.references(
      m_context,
      cmpiObjectPath,
      "Linux_DnsService",
      "PartComponent",
      aPropertiesPP);

    while(cmpiEnumeration.hasNext()) {
      CmpiInstance cmpiInstance = cmpiEnumeration.getNext();
      Linux_DnsAddressMatchListsForServiceInstance instance(cmpiInstance,aNameSpaceP);
      anInstanceEnumeration.addElement(instance);
    }      

  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListsForServiceExternal::referenceNamesPartComponent( 
    const char* aNameSpaceP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListsForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
      
    CmpiObjectPath cmpiObjectPath = aSourceInstanceName.getObjectPath();
    CmpiEnumeration cmpiEnumeration = m_broker.referenceNames(
      m_context,
      cmpiObjectPath,
      "Linux_DnsService",
      "PartComponent");
   
    while (cmpiEnumeration.hasNext()) {
      CmpiObjectPath cmpiInstanceName = cmpiEnumeration.getNext();
      Linux_DnsAddressMatchListsForServiceInstanceName instanceName(cmpiInstanceName);
      anInstanceNameEnumeration.addElement(instanceName);
    }      

  }
     
  //Associator calls
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListsForServiceExternal::associatorsGroupComponent( 
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration) {
      
    CmpiObjectPath cmpiObjectPath = aSourceInstanceName.getObjectPath();

    CmpiEnumeration cmpiEnumeration = m_broker.associators(
      m_context,
      cmpiObjectPath,
      0,
      0,
      0,
      0,
      aPropertiesPP);

    while (cmpiEnumeration.hasNext()) {
      CmpiInstance cmpiInstance = cmpiEnumeration.getNext();
      Linux_DnsServiceInstance instance(cmpiInstance,aNameSpaceP);
      anInstanceEnumeration.addElement(instance);
    }

  }

  //----------------------------------------------------------------------------
  void Linux_DnsAddressMatchListsForServiceExternal::associatorNamesGroupComponent( 
    const char* aNameSpaceP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
      
    CmpiObjectPath cmpiObjectPath = aSourceInstanceName.getObjectPath();

    CmpiEnumeration cmpiEnumeration = m_broker.associatorNames(
     m_context,
     cmpiObjectPath,
     0,
     0,
     0,
     0);

    while(cmpiEnumeration.hasNext()) {
      CmpiObjectPath cmpiInstanceName = cmpiEnumeration.getNext();
      Linux_DnsServiceInstanceName instanceName(cmpiInstanceName);
      anInstanceNameEnumeration.addElement(instanceName);
    }

  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListsForServiceExternal::associatorsPartComponent( 
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration) {
      
    CmpiObjectPath cmpiObjectPath = aSourceInstanceName.getObjectPath();

    CmpiEnumeration cmpiEnumeration = m_broker.associators(
      m_context,
      cmpiObjectPath,
      0,
      0,
      0,
      0,
      aPropertiesPP);

    while (cmpiEnumeration.hasNext()) {
      CmpiInstance cmpiInstance = cmpiEnumeration.getNext();
      Linux_DnsAddressMatchListInstance instance(cmpiInstance,aNameSpaceP);
      anInstanceEnumeration.addElement(instance);
    }      

  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListsForServiceExternal::associatorNamesPartComponent( 
    const char* aNameSpaceP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListInstanceNameEnumeration& anInstanceNameEnumeration) {
      
    CmpiObjectPath cmpiObjectPath = aSourceInstanceName.getObjectPath();

    CmpiEnumeration cmpiEnumeration = m_broker.associatorNames(
      m_context,
      cmpiObjectPath,
      0,
      0,
      0,
      0);

    while (cmpiEnumeration.hasNext()) {
      CmpiObjectPath cmpiInstanceName = cmpiEnumeration.getNext();
      Linux_DnsAddressMatchListInstanceName instanceName(cmpiInstanceName);
      anInstanceNameEnumeration.addElement(instanceName);
    }

  }
      
}
