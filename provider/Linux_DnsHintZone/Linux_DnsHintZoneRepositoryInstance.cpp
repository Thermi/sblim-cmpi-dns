// =======================================================================
// Linux_DnsHintZoneRepositoryInstance.cpp
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
#include "Linux_DnsHintZoneRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsHintZoneRepositoryInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsHintZoneRepositoryInstance::Linux_DnsHintZoneRepositoryInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneRepositoryInstance::Linux_DnsHintZoneRepositoryInstance(
    const Linux_DnsHintZoneRepositoryInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneRepositoryInstance::Linux_DnsHintZoneRepositoryInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsHintZoneInstanceName(cop));

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneRepositoryInstance::
   ~Linux_DnsHintZoneRepositoryInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneRepositoryInstance&
  Linux_DnsHintZoneRepositoryInstance::operator=(
    const Linux_DnsHintZoneRepositoryInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsHintZoneRepositoryInstance::getCmpiInstance(
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
  Linux_DnsHintZoneRepositoryInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsHintZoneInstanceName&
  Linux_DnsHintZoneRepositoryInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsHintZone");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsHintZoneRepositoryInstance::setInstanceName(
    const Linux_DnsHintZoneInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsHintZoneRepositoryInstance::init() {
   	isSet.instanceName = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsHintZoneRepositoryInstance::init(
    const Linux_DnsHintZoneRepositoryInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
        
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsHintZoneRepositoryInstance::reset() {
   	
  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsHintZoneRepositoryInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneRepositoryInstanceEnumerationElement::Linux_DnsHintZoneRepositoryInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneRepositoryInstanceEnumerationElement::~Linux_DnsHintZoneRepositoryInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsHintZoneRepositoryInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneRepositoryInstanceEnumeration::Linux_DnsHintZoneRepositoryInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneRepositoryInstanceEnumeration::Linux_DnsHintZoneRepositoryInstanceEnumeration(
    const Linux_DnsHintZoneRepositoryInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneRepositoryInstanceEnumeration::~Linux_DnsHintZoneRepositoryInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsHintZoneRepositoryInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsHintZoneRepositoryInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsHintZoneRepositoryInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsHintZoneRepositoryInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsHintZoneRepositoryInstance&  
  Linux_DnsHintZoneRepositoryInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsHintZoneRepositoryInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsHintZoneRepositoryInstance&
  Linux_DnsHintZoneRepositoryInstanceEnumeration::getNext() {
   	
    Linux_DnsHintZoneRepositoryInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsHintZoneRepositoryInstanceEnumeration::addElement(
    const Linux_DnsHintZoneRepositoryInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsHintZoneRepositoryInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsHintZoneRepositoryInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsHintZoneRepositoryInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsHintZoneRepositoryInstance(anInstance);
  	}

  }
  
}
