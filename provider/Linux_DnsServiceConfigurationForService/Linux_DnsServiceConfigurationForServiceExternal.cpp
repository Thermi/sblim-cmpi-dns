// =======================================================================
// Linux_DnsServiceConfigurationForServiceExternal.cpp
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

#include "Linux_DnsServiceConfigurationForServiceExternal.h"

namespace genProvider {
	
	//----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationForServiceExternal::Linux_DnsServiceConfigurationForServiceExternal(
    const CmpiBroker& aBroker,
    const CmpiContext& aContext ) 
    : m_broker(aBroker),
    m_context(aContext) { }
   
	//----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationForServiceExternal::~Linux_DnsServiceConfigurationForServiceExternal() { }
    
	//----------------------------------------------------------------------------
  void 
  Linux_DnsServiceConfigurationForServiceExternal::enumInstanceNames(
    const char *aNameSpaceP,
    Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {

    CmpiObjectPath classObjectPath(aNameSpaceP,"Linux_DnsServiceConfigurationForService");
    CmpiEnumeration cmpiEnumeration = 
      m_broker.enumInstanceNames(m_context,classObjectPath);
    while (cmpiEnumeration.hasNext()) {
      CmpiObjectPath objectPath = cmpiEnumeration.getNext();
      Linux_DnsServiceConfigurationForServiceInstanceName instanceName(objectPath);
      anInstanceNameEnumeration.addElement(instanceName);
    }
  
  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceExternal::enumInstances(
    const char *aNameSpaceP,
    const char** aPropertiesPP,
    Linux_DnsServiceConfigurationForServiceInstanceEnumeration& anInstanceEnumeration) {
   		
    CmpiObjectPath classObjectPath(aNameSpaceP,"Linux_DnsServiceConfigurationForService");
    CmpiEnumeration cmpiEnumeration = 
      m_broker.enumInstances(m_context,classObjectPath,aPropertiesPP);
    while (cmpiEnumeration.hasNext()) {
      CmpiInstance cmpiInstance = cmpiEnumeration.getNext();
      Linux_DnsServiceConfigurationForServiceInstance instance(cmpiInstance,aNameSpaceP);
      anInstanceEnumeration.addElement(instance);
    }
  
  }
  	  
	//----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationForServiceInstance
  Linux_DnsServiceConfigurationForServiceExternal::getInstance(
    const char** aPropertiesPP,
    const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName) {
    
    CmpiObjectPath cmpiObjectPath = anInstanceName.getObjectPath();
    CmpiInstance cmpiInstance = 
      m_broker.getInstance(m_context,cmpiObjectPath,aPropertiesPP);
  
    return Linux_DnsServiceConfigurationForServiceInstance(cmpiInstance,anInstanceName.getNamespace());
  
  }
      
	//----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceExternal::setInstance(
    const char** aPropertiesPP,
    const Linux_DnsServiceConfigurationForServiceInstance& anInstance) {
  
    CmpiObjectPath cmpiObjectPath = anInstance.getInstanceName().getObjectPath();
    CmpiInstance cmpiInstance = anInstance.getCmpiInstance();
    m_broker.setInstance(m_context,cmpiObjectPath,cmpiInstance,aPropertiesPP);
  
  }
      
	//----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationForServiceInstanceName
  Linux_DnsServiceConfigurationForServiceExternal::createInstance(
    const Linux_DnsServiceConfigurationForServiceInstance& anInstance) {
  
    CmpiObjectPath cmpiObjectPath = anInstance.getInstanceName().getObjectPath();
    CmpiInstance cmpiInstance = anInstance.getCmpiInstance();
    return Linux_DnsServiceConfigurationForServiceInstanceName(
		m_broker.createInstance(m_context,cmpiObjectPath,cmpiInstance));

  }
  
	//----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceExternal::deleteInstance(
    const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName) {
    
    CmpiObjectPath cmpiObjectPath = anInstanceName.getObjectPath();
    m_broker.deleteInstance(m_context,cmpiObjectPath);
  
  }
  // Reference calls

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceExternal::referencesElement( 
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
    Linux_DnsServiceConfigurationForServiceInstanceEnumeration& anInstanceEnumeration) {
      
    CmpiObjectPath cmpiObjectPath = aSourceInstanceName.getObjectPath();

    CmpiEnumeration cmpiEnumeration = m_broker.references(
      m_context,
      cmpiObjectPath,
      "Linux_DnsServiceConfiguration",
      "Element",
      aPropertiesPP);

    while (cmpiEnumeration.hasNext()) {
      CmpiInstance cmpiInstance = cmpiEnumeration.getNext();
      Linux_DnsServiceConfigurationForServiceInstance instance(cmpiInstance,aNameSpaceP);
      anInstanceEnumeration.addElement(instance);
    }      

  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceExternal::referenceNamesElement( 
    const char* aNameSpaceP,
    const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
    Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
      
    CmpiObjectPath cmpiObjectPath = aSourceInstanceName.getObjectPath();

    CmpiEnumeration cmpiEnumeration = m_broker.referenceNames(
      m_context,
      cmpiObjectPath,
      "Linux_DnsServiceConfiguration",
      "Element");

    while (cmpiEnumeration.hasNext()) {
      CmpiObjectPath cmpiInstanceName = cmpiEnumeration.getNext();
      Linux_DnsServiceConfigurationForServiceInstanceName instanceName(cmpiInstanceName);
      anInstanceNameEnumeration.addElement(instanceName);
    }      

  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceExternal::referencesConfiguration( 
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsServiceConfigurationForServiceInstanceEnumeration& anInstanceEnumeration){
      
    CmpiObjectPath cmpiObjectPath = aSourceInstanceName.getObjectPath();
  
    CmpiEnumeration cmpiEnumeration = m_broker.references(
      m_context,
      cmpiObjectPath,
      "Linux_DnsService",
      "Configuration",
      aPropertiesPP);

    while(cmpiEnumeration.hasNext()) {
      CmpiInstance cmpiInstance = cmpiEnumeration.getNext();
      Linux_DnsServiceConfigurationForServiceInstance instance(cmpiInstance,aNameSpaceP);
      anInstanceEnumeration.addElement(instance);
    }      

  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceExternal::referenceNamesConfiguration( 
    const char* aNameSpaceP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
      
    CmpiObjectPath cmpiObjectPath = aSourceInstanceName.getObjectPath();
    CmpiEnumeration cmpiEnumeration = m_broker.referenceNames(
      m_context,
      cmpiObjectPath,
      "Linux_DnsService",
      "Configuration");
   
    while (cmpiEnumeration.hasNext()) {
      CmpiObjectPath cmpiInstanceName = cmpiEnumeration.getNext();
      Linux_DnsServiceConfigurationForServiceInstanceName instanceName(cmpiInstanceName);
      anInstanceNameEnumeration.addElement(instanceName);
    }      

  }
     
  //Associator calls
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceExternal::associatorsElement( 
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
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
  void Linux_DnsServiceConfigurationForServiceExternal::associatorNamesElement( 
    const char* aNameSpaceP,
    const Linux_DnsServiceConfigurationInstanceName& aSourceInstanceName,
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
  Linux_DnsServiceConfigurationForServiceExternal::associatorsConfiguration( 
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsServiceConfigurationInstanceEnumeration& anInstanceEnumeration) {
      
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
      Linux_DnsServiceConfigurationInstance instance(cmpiInstance,aNameSpaceP);
      anInstanceEnumeration.addElement(instance);
    }      

  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceExternal::associatorNamesConfiguration( 
    const char* aNameSpaceP,
    const Linux_DnsServiceInstanceName& aSourceInstanceName,
    Linux_DnsServiceConfigurationInstanceNameEnumeration& anInstanceNameEnumeration) {
      
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
      Linux_DnsServiceConfigurationInstanceName instanceName(cmpiInstanceName);
      anInstanceNameEnumeration.addElement(instanceName);
    }

  }
      
}
