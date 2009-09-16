// =======================================================================
// Linux_DnsAllowNotifyForZoneRepositoryInstance.cpp
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
#include "Linux_DnsAllowNotifyForZoneRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsAllowNotifyForZoneRepositoryInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsAllowNotifyForZoneRepositoryInstance::Linux_DnsAllowNotifyForZoneRepositoryInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForZoneRepositoryInstance::Linux_DnsAllowNotifyForZoneRepositoryInstance(
    const Linux_DnsAllowNotifyForZoneRepositoryInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForZoneRepositoryInstance::Linux_DnsAllowNotifyForZoneRepositoryInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsAllowNotifyForZoneInstanceName(cop));

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForZoneRepositoryInstance::
   ~Linux_DnsAllowNotifyForZoneRepositoryInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForZoneRepositoryInstance&
  Linux_DnsAllowNotifyForZoneRepositoryInstance::operator=(
    const Linux_DnsAllowNotifyForZoneRepositoryInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsAllowNotifyForZoneRepositoryInstance::getCmpiInstance(
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
  Linux_DnsAllowNotifyForZoneRepositoryInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsAllowNotifyForZoneInstanceName&
  Linux_DnsAllowNotifyForZoneRepositoryInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsAllowNotifyForZone");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowNotifyForZoneRepositoryInstance::setInstanceName(
    const Linux_DnsAllowNotifyForZoneInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowNotifyForZoneRepositoryInstance::init() {
   	isSet.instanceName = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsAllowNotifyForZoneRepositoryInstance::init(
    const Linux_DnsAllowNotifyForZoneRepositoryInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
        
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowNotifyForZoneRepositoryInstance::reset() {
   	
  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumerationElement::Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumerationElement::~Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsAllowNotifyForZoneRepositoryInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration::Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration::Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration(
    const Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration::~Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsAllowNotifyForZoneRepositoryInstance&  
  Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsAllowNotifyForZoneRepositoryInstance&
  Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration::getNext() {
   	
    Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration::addElement(
    const Linux_DnsAllowNotifyForZoneRepositoryInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsAllowNotifyForZoneRepositoryInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsAllowNotifyForZoneRepositoryInstance(anInstance);
  	}

  }
  
}
