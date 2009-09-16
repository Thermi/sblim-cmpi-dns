// =======================================================================
// Linux_DnsServiceConfigurationForServiceRepositoryInstance.cpp
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
#include "Linux_DnsServiceConfigurationForServiceRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsServiceConfigurationForServiceRepositoryInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsServiceConfigurationForServiceRepositoryInstance::Linux_DnsServiceConfigurationForServiceRepositoryInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationForServiceRepositoryInstance::Linux_DnsServiceConfigurationForServiceRepositoryInstance(
    const Linux_DnsServiceConfigurationForServiceRepositoryInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationForServiceRepositoryInstance::Linux_DnsServiceConfigurationForServiceRepositoryInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsServiceConfigurationForServiceInstanceName(cop));

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationForServiceRepositoryInstance::
   ~Linux_DnsServiceConfigurationForServiceRepositoryInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationForServiceRepositoryInstance&
  Linux_DnsServiceConfigurationForServiceRepositoryInstance::operator=(
    const Linux_DnsServiceConfigurationForServiceRepositoryInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsServiceConfigurationForServiceRepositoryInstance::getCmpiInstance(
    const char** aPropertiesPP) const {
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (aPropertiesPP) {
	    cmpiInstance.setPropertyFilter(aPropertiesPP,0);
    }

  	
  	return cmpiInstance;
  	
  }
  
  //----------------------------------------------------------------------------
  // InstanceName related methods
  //----------------------------------------------------------------------------
  unsigned int 
  Linux_DnsServiceConfigurationForServiceRepositoryInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceConfigurationForServiceInstanceName&
  Linux_DnsServiceConfigurationForServiceRepositoryInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsServiceConfigurationForService");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceRepositoryInstance::setInstanceName(
    const Linux_DnsServiceConfigurationForServiceInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceRepositoryInstance::init() {
   	isSet.instanceName = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsServiceConfigurationForServiceRepositoryInstance::init(
    const Linux_DnsServiceConfigurationForServiceRepositoryInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
        
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceRepositoryInstance::reset() {
   	
  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumerationElement::Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumerationElement::~Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsServiceConfigurationForServiceRepositoryInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration::Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration::Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration(
    const Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration::~Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceConfigurationForServiceRepositoryInstance&  
  Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceConfigurationForServiceRepositoryInstance&
  Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration::getNext() {
   	
    Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumeration::addElement(
    const Linux_DnsServiceConfigurationForServiceRepositoryInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsServiceConfigurationForServiceRepositoryInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsServiceConfigurationForServiceRepositoryInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsServiceConfigurationForServiceRepositoryInstance(anInstance);
  	}

  }
  
}
