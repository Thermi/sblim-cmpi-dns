// =======================================================================
// Linux_DnsForwardersForServiceInstanceName.cpp
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
#include "Linux_DnsForwardersForServiceInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //****************************************************************************
  //Linux_DnsForwardersForServiceInstanceName
  //---------------------------------------------------------------------------- 
  // empty constructor
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersForServiceInstanceName::Linux_DnsForwardersForServiceInstanceName() {
   	init();  	
  }
  
  //---------------------------------------------------------------------------- 
  // copy constructor	
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersForServiceInstanceName::Linux_DnsForwardersForServiceInstanceName(
    const Linux_DnsForwardersForServiceInstanceName& anInstanceName) {
   	init(anInstanceName);  	
  }
  
  //---------------------------------------------------------------------------- 
  // constructor using CmpiObjectPath
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersForServiceInstanceName::Linux_DnsForwardersForServiceInstanceName(
    const CmpiObjectPath& path) {
    
    init();
    
    m_CIMClassNameP = path.getClassName().charPtr();
    
    CmpiString namespaceP;
    namespaceP = path.getNameSpace();
    setNamespace(namespaceP.charPtr(),1);
        
    CmpiObjectPath GroupComponent = path.getKey("GroupComponent");
    setGroupComponent(Linux_DnsServiceInstanceName(GroupComponent));
    
    CmpiObjectPath PartComponent = path.getKey("PartComponent");
    setPartComponent(Linux_DnsForwardersInstanceName(PartComponent));

    
  }
  
  //---------------------------------------------------------------------------- 
  // destructor
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersForServiceInstanceName::~Linux_DnsForwardersForServiceInstanceName() {
   	reset();  	  
  }
  
  //---------------------------------------------------------------------------- 
  //copy operator
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersForServiceInstanceName&
  Linux_DnsForwardersForServiceInstanceName::operator=(
    const Linux_DnsForwardersForServiceInstanceName& anInstanceName) {    
    
    init(anInstanceName);
   	return *this;    
  
  }
  
  //---------------------------------------------------------------------------- 
  //returns the related CmpiObjectPath
  //---------------------------------------------------------------------------- 
  CmpiObjectPath 
  Linux_DnsForwardersForServiceInstanceName::getObjectPath() const {
   	
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
  Linux_DnsForwardersForServiceInstanceName::fillKeys(CmpiInstance& cmpiInstance) const {
  	
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
  Linux_DnsForwardersForServiceInstanceName::isNameSpaceSet() const {
  	return isSet.m_nameSpaceP;
  }
  
  //---------------------------------------------------------------------------- 
  const char* 
  Linux_DnsForwardersForServiceInstanceName::getNamespace() const {
    if ( ! isSet.m_nameSpaceP) {
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace",
   	   "Linux_DnsForwardersForService");
   	}
  	return m_nameSpaceP;
  }

  //---------------------------------------------------------------------------- 
  void
  Linux_DnsForwardersForServiceInstanceName::setNamespace(
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
  Linux_DnsForwardersForServiceInstanceName::isGroupComponentSet() const {
    return isSet.GroupComponent;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsForwardersForServiceInstanceName::setGroupComponent(
    const Linux_DnsServiceInstanceName& aValue) {
  
    m_GroupComponent = aValue;
    isSet.GroupComponent = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsServiceInstanceName&
  Linux_DnsForwardersForServiceInstanceName::getGroupComponent() const {
    
    if ( ! isSet.GroupComponent) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "GroupComponent",
        "Linux_DnsForwardersForService");
   	}


    return m_GroupComponent;

  }
       
  //----------------------------------------------------------------------------
  // PartComponent related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardersForServiceInstanceName::isPartComponentSet() const {
    return isSet.PartComponent;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsForwardersForServiceInstanceName::setPartComponent(
    const Linux_DnsForwardersInstanceName& aValue) {
  
    m_PartComponent = aValue;
    isSet.PartComponent = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsForwardersInstanceName&
  Linux_DnsForwardersForServiceInstanceName::getPartComponent() const {
    
    if ( ! isSet.PartComponent) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "PartComponent",
        "Linux_DnsForwardersForService");
   	}


    return m_PartComponent;

  }


  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsForwardersForServiceInstanceName::init() {
  	
  	m_CIMClassNameP = "Linux_DnsForwardersForService";
  	isSet.m_nameSpaceP = 0; 
  	    isSet.GroupComponent = 0;
    isSet.PartComponent = 0;

  	
  }
  
  //---------------------------------------------------------------------------- 
  //copies another instance properties in this
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsForwardersForServiceInstanceName::init(
    const Linux_DnsForwardersForServiceInstanceName& anOriginal) {
   	
   	init();
   	   	
    m_CIMClassNameP = anOriginal.m_CIMClassNameP;
    if (anOriginal.isNameSpaceSet()){
      setNamespace(anOriginal.getNamespace(),1);
    }
       	
    if (anOriginal.isGroupComponentSet()) {
      const Linux_DnsServiceInstanceName& GroupComponentOriginal = anOriginal.getGroupComponent();
      setGroupComponent(GroupComponentOriginal);
    }
   	
    if (anOriginal.isPartComponentSet()) {
      const Linux_DnsForwardersInstanceName& PartComponentOriginal = anOriginal.getPartComponent();
      setPartComponent(PartComponentOriginal);
    }
    
  
  }
  
  //---------------------------------------------------------------------------- 
  void
  Linux_DnsForwardersForServiceInstanceName::reset() {
  	if (isSet.m_nameSpaceP) {
  	  delete(m_nameSpaceP);
  	}
  	  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersForServiceInstanceNameEnumerationElement::Linux_DnsForwardersForServiceInstanceNameEnumerationElement() {
  	m_elementP = 0;
  	m_nextP = 0; 
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersForServiceInstanceNameEnumerationElement::~Linux_DnsForwardersForServiceInstanceNameEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersForServiceInstanceNameEnumeration::Linux_DnsForwardersForServiceInstanceNameEnumeration() {
  	 m_firstElementP = 0;
     m_currentElementP = 0;
     m_endElementP = 0;
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersForServiceInstanceNameEnumeration::Linux_DnsForwardersForServiceInstanceNameEnumeration(
    const CmpiArray& aCmpiArray) {
  	
  	m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
    
    int size = aCmpiArray.size();
    for (int x=0; x < size; ++x) {
      addElement(Linux_DnsForwardersForServiceInstanceName(aCmpiArray[x]));
    }
    
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersForServiceInstanceNameEnumeration::Linux_DnsForwardersForServiceInstanceNameEnumeration(
    const Linux_DnsForwardersForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceNameEnumeration.getSize();
    for (int x=0; x < size; ++x) {
      addElement(anInstanceNameEnumeration.getElement(x));
    }

  }
  	  
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersForServiceInstanceNameEnumeration::~Linux_DnsForwardersForServiceInstanceNameEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }

  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsForwardersForServiceInstanceNameEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  
  }

  //---------------------------------------------------------------------------- 
  bool 
  Linux_DnsForwardersForServiceInstanceNameEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //---------------------------------------------------------------------------- 
  int
  Linux_DnsForwardersForServiceInstanceNameEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsForwardersForServiceInstanceNameEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsForwardersForServiceInstanceName&  
   Linux_DnsForwardersForServiceInstanceNameEnumeration::getElement(int anIndex) const {
   
    Linux_DnsForwardersForServiceInstanceNameEnumerationElement* followingP = m_firstElementP;
   
    int x=0;
    while (followingP && (x < anIndex) ) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsForwardersForServiceInstanceName&
  Linux_DnsForwardersForServiceInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsForwardersForServiceInstanceNameEnumerationElement* currentP = m_currentElementP;
  	 m_currentElementP = m_currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  
  }
  	  
  //---------------------------------------------------------------------------- 
  void Linux_DnsForwardersForServiceInstanceNameEnumeration::addElement
   (const Linux_DnsForwardersForServiceInstanceName& anElementP){
   	
  	if (m_firstElementP==0) {
  	  m_firstElementP = new Linux_DnsForwardersForServiceInstanceNameEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsForwardersForServiceInstanceName(anElementP);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsForwardersForServiceInstanceNameEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP=new Linux_DnsForwardersForServiceInstanceName(anElementP);
  	}

  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersForServiceInstanceNameEnumeration::operator CmpiArray() const {
  	int size = getSize();
   	CmpiArray cmpiArray = CmpiArray(size,CMPI_instance);
   	for (int x=0; x < size; ++x) {
   	  cmpiArray[x]=getElement(x).getObjectPath();
   	}
   	return cmpiArray;
  }
  
}
