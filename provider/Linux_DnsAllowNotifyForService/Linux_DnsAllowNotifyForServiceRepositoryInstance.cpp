// =======================================================================
// Linux_DnsAllowNotifyForServiceRepositoryInstance.cpp
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
#include "Linux_DnsAllowNotifyForServiceRepositoryInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsAllowNotifyForServiceRepositoryInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsAllowNotifyForServiceRepositoryInstance::Linux_DnsAllowNotifyForServiceRepositoryInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForServiceRepositoryInstance::Linux_DnsAllowNotifyForServiceRepositoryInstance(
    const Linux_DnsAllowNotifyForServiceRepositoryInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForServiceRepositoryInstance::Linux_DnsAllowNotifyForServiceRepositoryInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsAllowNotifyForServiceInstanceName(cop));

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForServiceRepositoryInstance::
   ~Linux_DnsAllowNotifyForServiceRepositoryInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForServiceRepositoryInstance&
  Linux_DnsAllowNotifyForServiceRepositoryInstance::operator=(
    const Linux_DnsAllowNotifyForServiceRepositoryInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsAllowNotifyForServiceRepositoryInstance::getCmpiInstance(
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
  Linux_DnsAllowNotifyForServiceRepositoryInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsAllowNotifyForServiceInstanceName&
  Linux_DnsAllowNotifyForServiceRepositoryInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsAllowNotifyForService");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowNotifyForServiceRepositoryInstance::setInstanceName(
    const Linux_DnsAllowNotifyForServiceInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowNotifyForServiceRepositoryInstance::init() {
   	isSet.instanceName = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsAllowNotifyForServiceRepositoryInstance::init(
    const Linux_DnsAllowNotifyForServiceRepositoryInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
        
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowNotifyForServiceRepositoryInstance::reset() {
   	
  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumerationElement::Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumerationElement::~Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsAllowNotifyForServiceRepositoryInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration::Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration::Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration(
    const Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration::~Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsAllowNotifyForServiceRepositoryInstance&  
  Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsAllowNotifyForServiceRepositoryInstance&
  Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration::getNext() {
   	
    Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration::addElement(
    const Linux_DnsAllowNotifyForServiceRepositoryInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsAllowNotifyForServiceRepositoryInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsAllowNotifyForServiceRepositoryInstance(anInstance);
  	}

  }
  
}
