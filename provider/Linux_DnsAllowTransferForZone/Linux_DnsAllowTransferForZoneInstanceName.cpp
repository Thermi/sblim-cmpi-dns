// =======================================================================
// Linux_DnsAllowTransferForZoneInstanceName.cpp
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
#include "Linux_DnsAllowTransferForZoneInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //****************************************************************************
  //Linux_DnsAllowTransferForZoneInstanceName
  //---------------------------------------------------------------------------- 
  // empty constructor
  //---------------------------------------------------------------------------- 
  Linux_DnsAllowTransferForZoneInstanceName::Linux_DnsAllowTransferForZoneInstanceName() {
   	init();  	
  }
  
  //---------------------------------------------------------------------------- 
  // copy constructor	
  //---------------------------------------------------------------------------- 
  Linux_DnsAllowTransferForZoneInstanceName::Linux_DnsAllowTransferForZoneInstanceName(
    const Linux_DnsAllowTransferForZoneInstanceName& anInstanceName) {
   	init(anInstanceName);  	
  }
  
  //---------------------------------------------------------------------------- 
  // constructor using CmpiObjectPath
  //---------------------------------------------------------------------------- 
  Linux_DnsAllowTransferForZoneInstanceName::Linux_DnsAllowTransferForZoneInstanceName(
    const CmpiObjectPath& path) {
    
    init();
    
    m_CIMClassNameP = path.getClassName().charPtr();
    
    CmpiString namespaceP;
    namespaceP = path.getNameSpace();
    setNamespace(namespaceP.charPtr(),1);
        
    CmpiObjectPath GroupComponent = path.getKey("GroupComponent");
    setGroupComponent(Linux_DnsZoneInstanceName(GroupComponent));
    
    CmpiObjectPath PartComponent = path.getKey("PartComponent");
    setPartComponent(Linux_DnsAddressMatchListInstanceName(PartComponent));

    
  }
  
  //---------------------------------------------------------------------------- 
  // destructor
  //---------------------------------------------------------------------------- 
  Linux_DnsAllowTransferForZoneInstanceName::~Linux_DnsAllowTransferForZoneInstanceName() {
   	reset();  	  
  }
  
  //---------------------------------------------------------------------------- 
  //copy operator
  //---------------------------------------------------------------------------- 
  Linux_DnsAllowTransferForZoneInstanceName&
  Linux_DnsAllowTransferForZoneInstanceName::operator=(
    const Linux_DnsAllowTransferForZoneInstanceName& anInstanceName) {    
    
    init(anInstanceName);
   	return *this;    
  
  }
  
  //---------------------------------------------------------------------------- 
  //returns the related CmpiObjectPath
  //---------------------------------------------------------------------------- 
  CmpiObjectPath 
  Linux_DnsAllowTransferForZoneInstanceName::getObjectPath() const {
   	
   	CmpiObjectPath objectPath(m_nameSpaceP, m_CIMClassNameP);
   	  	objectPath.setKey(
  	  "GroupComponent",
  	  CmpiData(m_GroupComponent.getObjectPath()));
  	objectPath.setKey(
  	  "PartComponent",
  	  CmpiData(m_PartComponent.getObjectPath()));

  	
  	return objectPath;
  	
  }
  
  //---------------------------------------------------------------------------- 
  // adds the related CmpiObjectPath to an existing cmpiInstance
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsAllowTransferForZoneInstanceName::fillKeys(CmpiInstance& cmpiInstance) const {
  	
  	if (isSet.GroupComponent) {
  	  
  	  cmpiInstance.setProperty(
  	    "GroupComponent",
  	    CmpiData(m_GroupComponent.getObjectPath()));
  	}

  	if (isSet.PartComponent) {
  	  
  	  cmpiInstance.setProperty(
  	    "PartComponent",
  	    CmpiData(m_PartComponent.getObjectPath()));
  	}

  }
  
  
  //---------------------------------------------------------------------------- 
  // NameSpace related methods
  //---------------------------------------------------------------------------- 
  unsigned int 
  Linux_DnsAllowTransferForZoneInstanceName::isNameSpaceSet() const {
  	return isSet.m_nameSpaceP;
  }
  
  //---------------------------------------------------------------------------- 
  const char* 
  Linux_DnsAllowTransferForZoneInstanceName::getNamespace() const {
    if ( ! isSet.m_nameSpaceP) {
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace",
   	   "Linux_DnsAllowTransferForZone");
   	}
  	return m_nameSpaceP;
  }

  //---------------------------------------------------------------------------- 
  void
  Linux_DnsAllowTransferForZoneInstanceName::setNamespace(
    const char* aNameSpaceP,
    int aCopyFlag) {
  
    if (isSet.m_nameSpaceP) {
      delete m_nameSpaceP;
    }
    
    if (aCopyFlag && aNameSpaceP) {
      char* nameSpaceP = new char[strlen(aNameSpaceP) + 1];
      strcpy(nameSpaceP,aNameSpaceP);
      m_nameSpaceP = nameSpaceP;
    } else {
      m_nameSpaceP = aNameSpaceP;
    }
    
    isSet.m_nameSpaceP = 1;
  }
         
  //----------------------------------------------------------------------------
  // GroupComponent related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsAllowTransferForZoneInstanceName::isGroupComponentSet() const {
    return isSet.GroupComponent;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsAllowTransferForZoneInstanceName::setGroupComponent(
    const Linux_DnsZoneInstanceName& aValue) {
  
    m_GroupComponent = aValue;
    isSet.GroupComponent = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsZoneInstanceName&
  Linux_DnsAllowTransferForZoneInstanceName::getGroupComponent() const {
    
    if ( ! isSet.GroupComponent) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "GroupComponent",
        "Linux_DnsAllowTransferForZone");
   	}


    return m_GroupComponent;

  }
       
  //----------------------------------------------------------------------------
  // PartComponent related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsAllowTransferForZoneInstanceName::isPartComponentSet() const {
    return isSet.PartComponent;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsAllowTransferForZoneInstanceName::setPartComponent(
    const Linux_DnsAddressMatchListInstanceName& aValue) {
  
    m_PartComponent = aValue;
    isSet.PartComponent = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsAddressMatchListInstanceName&
  Linux_DnsAllowTransferForZoneInstanceName::getPartComponent() const {
    
    if ( ! isSet.PartComponent) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "PartComponent",
        "Linux_DnsAllowTransferForZone");
   	}


    return m_PartComponent;

  }


  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsAllowTransferForZoneInstanceName::init() {
  	
  	m_CIMClassNameP = "Linux_DnsAllowTransferForZone";
  	isSet.m_nameSpaceP = 0; 
  	    isSet.GroupComponent = 0;
    isSet.PartComponent = 0;

  	
  }
  
  //---------------------------------------------------------------------------- 
  //copies another instance properties in this
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsAllowTransferForZoneInstanceName::init(
    const Linux_DnsAllowTransferForZoneInstanceName& anOriginal) {
   	
   	init();
   	   	
    m_CIMClassNameP = anOriginal.m_CIMClassNameP;
    if (anOriginal.isNameSpaceSet()){
      setNamespace(anOriginal.getNamespace(),1);
    }
       	
    if (anOriginal.isGroupComponentSet()) {
      const Linux_DnsZoneInstanceName& GroupComponentOriginal = anOriginal.getGroupComponent();
      setGroupComponent(GroupComponentOriginal);
    }
   	
    if (anOriginal.isPartComponentSet()) {
      const Linux_DnsAddressMatchListInstanceName& PartComponentOriginal = anOriginal.getPartComponent();
      setPartComponent(PartComponentOriginal);
    }
    
  
  }
  
  //---------------------------------------------------------------------------- 
  void
  Linux_DnsAllowTransferForZoneInstanceName::reset() {
  	if (isSet.m_nameSpaceP) {
  	  delete(m_nameSpaceP);
  	}
  	  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsAllowTransferForZoneInstanceNameEnumerationElement::Linux_DnsAllowTransferForZoneInstanceNameEnumerationElement() {
  	m_elementP = 0;
  	m_nextP = 0; 
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsAllowTransferForZoneInstanceNameEnumerationElement::~Linux_DnsAllowTransferForZoneInstanceNameEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsAllowTransferForZoneInstanceNameEnumeration::Linux_DnsAllowTransferForZoneInstanceNameEnumeration() {
  	 m_firstElementP = 0;
     m_currentElementP = 0;
     m_endElementP = 0;
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsAllowTransferForZoneInstanceNameEnumeration::Linux_DnsAllowTransferForZoneInstanceNameEnumeration(
    const CmpiArray& aCmpiArray) {
  	
  	m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
    
    int size = aCmpiArray.size();
    for (int x=0; x < size; ++x) {
      addElement(Linux_DnsAllowTransferForZoneInstanceName(aCmpiArray[x]));
    }
    
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsAllowTransferForZoneInstanceNameEnumeration::Linux_DnsAllowTransferForZoneInstanceNameEnumeration(
    const Linux_DnsAllowTransferForZoneInstanceNameEnumeration& anInstanceNameEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceNameEnumeration.getSize();
    for (int x=0; x < size; ++x) {
      addElement(anInstanceNameEnumeration.getElement(x));
    }

  }
  	  
  //---------------------------------------------------------------------------- 
  Linux_DnsAllowTransferForZoneInstanceNameEnumeration::~Linux_DnsAllowTransferForZoneInstanceNameEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }

  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsAllowTransferForZoneInstanceNameEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  
  }

  //---------------------------------------------------------------------------- 
  bool 
  Linux_DnsAllowTransferForZoneInstanceNameEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //---------------------------------------------------------------------------- 
  int
  Linux_DnsAllowTransferForZoneInstanceNameEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsAllowTransferForZoneInstanceNameEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsAllowTransferForZoneInstanceName&  
   Linux_DnsAllowTransferForZoneInstanceNameEnumeration::getElement(int anIndex) const {
   
    Linux_DnsAllowTransferForZoneInstanceNameEnumerationElement* followingP = m_firstElementP;
   
    int x=0;
    while (followingP && (x < anIndex) ) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsAllowTransferForZoneInstanceName&
  Linux_DnsAllowTransferForZoneInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsAllowTransferForZoneInstanceNameEnumerationElement* currentP = m_currentElementP;
  	 m_currentElementP = m_currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  
  }
  	  
  //---------------------------------------------------------------------------- 
  void Linux_DnsAllowTransferForZoneInstanceNameEnumeration::addElement
   (const Linux_DnsAllowTransferForZoneInstanceName& anElementP){
   	
  	if (m_firstElementP==0) {
  	  m_firstElementP = new Linux_DnsAllowTransferForZoneInstanceNameEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsAllowTransferForZoneInstanceName(anElementP);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsAllowTransferForZoneInstanceNameEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP=new Linux_DnsAllowTransferForZoneInstanceName(anElementP);
  	}

  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsAllowTransferForZoneInstanceNameEnumeration::operator CmpiArray() const {
  	int size = getSize();
   	CmpiArray cmpiArray = CmpiArray(size,CMPI_instance);
   	for (int x=0; x < size; ++x) {
   	  cmpiArray[x]=getElement(x).getObjectPath();
   	}
   	return cmpiArray;
  }
  
}
