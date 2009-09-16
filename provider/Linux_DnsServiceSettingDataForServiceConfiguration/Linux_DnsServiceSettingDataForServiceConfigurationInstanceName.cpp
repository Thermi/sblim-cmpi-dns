// =======================================================================
// Linux_DnsServiceSettingDataForServiceConfigurationInstanceName.cpp
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
#include "Linux_DnsServiceSettingDataForServiceConfigurationInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //****************************************************************************
  //Linux_DnsServiceSettingDataForServiceConfigurationInstanceName
  //---------------------------------------------------------------------------- 
  // empty constructor
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::Linux_DnsServiceSettingDataForServiceConfigurationInstanceName() {
   	init();  	
  }
  
  //---------------------------------------------------------------------------- 
  // copy constructor	
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::Linux_DnsServiceSettingDataForServiceConfigurationInstanceName(
    const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anInstanceName) {
   	init(anInstanceName);  	
  }
  
  //---------------------------------------------------------------------------- 
  // constructor using CmpiObjectPath
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::Linux_DnsServiceSettingDataForServiceConfigurationInstanceName(
    const CmpiObjectPath& path) {
    
    init();
    
    m_CIMClassNameP = path.getClassName().charPtr();
    
    CmpiString namespaceP;
    namespaceP = path.getNameSpace();
    setNamespace(namespaceP.charPtr(),1);
        
    CmpiObjectPath GroupComponent = path.getKey("GroupComponent");
    setGroupComponent(Linux_DnsServiceConfigurationInstanceName(GroupComponent));
    
    CmpiObjectPath PartComponent = path.getKey("PartComponent");
    setPartComponent(Linux_DnsServiceSettingDataInstanceName(PartComponent));

    
  }
  
  //---------------------------------------------------------------------------- 
  // destructor
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::~Linux_DnsServiceSettingDataForServiceConfigurationInstanceName() {
   	reset();  	  
  }
  
  //---------------------------------------------------------------------------- 
  //copy operator
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName&
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::operator=(
    const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anInstanceName) {    
    
    init(anInstanceName);
   	return *this;    
  
  }
  
  //---------------------------------------------------------------------------- 
  //returns the related CmpiObjectPath
  //---------------------------------------------------------------------------- 
  CmpiObjectPath 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::getObjectPath() const {
   	
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
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::fillKeys(CmpiInstance& cmpiInstance) const {
  	
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
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::isNameSpaceSet() const {
  	return isSet.m_nameSpaceP;
  }
  
  //---------------------------------------------------------------------------- 
  const char* 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::getNamespace() const {
    if ( ! isSet.m_nameSpaceP) {
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace",
   	   "Linux_DnsServiceSettingDataForServiceConfiguration");
   	}
  	return m_nameSpaceP;
  }

  //---------------------------------------------------------------------------- 
  void
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::setNamespace(
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
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::isGroupComponentSet() const {
    return isSet.GroupComponent;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::setGroupComponent(
    const Linux_DnsServiceConfigurationInstanceName& aValue) {
  
    m_GroupComponent = aValue;
    isSet.GroupComponent = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsServiceConfigurationInstanceName&
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::getGroupComponent() const {
    
    if ( ! isSet.GroupComponent) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "GroupComponent",
        "Linux_DnsServiceSettingDataForServiceConfiguration");
   	}


    return m_GroupComponent;

  }
       
  //----------------------------------------------------------------------------
  // PartComponent related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::isPartComponentSet() const {
    return isSet.PartComponent;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::setPartComponent(
    const Linux_DnsServiceSettingDataInstanceName& aValue) {
  
    m_PartComponent = aValue;
    isSet.PartComponent = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsServiceSettingDataInstanceName&
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::getPartComponent() const {
    
    if ( ! isSet.PartComponent) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "PartComponent",
        "Linux_DnsServiceSettingDataForServiceConfiguration");
   	}


    return m_PartComponent;

  }


  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::init() {
  	
  	m_CIMClassNameP = "Linux_DnsServiceSettingDataForServiceConfiguration";
  	isSet.m_nameSpaceP = 0; 
  	    isSet.GroupComponent = 0;
    isSet.PartComponent = 0;

  	
  }
  
  //---------------------------------------------------------------------------- 
  //copies another instance properties in this
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::init(
    const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anOriginal) {
   	
   	init();
   	   	
    m_CIMClassNameP = anOriginal.m_CIMClassNameP;
    if (anOriginal.isNameSpaceSet()){
      setNamespace(anOriginal.getNamespace(),1);
    }
       	
    if (anOriginal.isGroupComponentSet()) {
      const Linux_DnsServiceConfigurationInstanceName& GroupComponentOriginal = anOriginal.getGroupComponent();
      setGroupComponent(GroupComponentOriginal);
    }
   	
    if (anOriginal.isPartComponentSet()) {
      const Linux_DnsServiceSettingDataInstanceName& PartComponentOriginal = anOriginal.getPartComponent();
      setPartComponent(PartComponentOriginal);
    }
    
  
  }
  
  //---------------------------------------------------------------------------- 
  void
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceName::reset() {
  	if (isSet.m_nameSpaceP) {
  	  delete(m_nameSpaceP);
  	}
  	  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumerationElement::Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumerationElement() {
  	m_elementP = 0;
  	m_nextP = 0; 
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumerationElement::~Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration::Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration() {
  	 m_firstElementP = 0;
     m_currentElementP = 0;
     m_endElementP = 0;
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration::Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration(
    const CmpiArray& aCmpiArray) {
  	
  	m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
    
    int size = aCmpiArray.size();
    for (int x=0; x < size; ++x) {
      addElement(Linux_DnsServiceSettingDataForServiceConfigurationInstanceName(aCmpiArray[x]));
    }
    
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration::Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration(
    const Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration& anInstanceNameEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceNameEnumeration.getSize();
    for (int x=0; x < size; ++x) {
      addElement(anInstanceNameEnumeration.getElement(x));
    }

  }
  	  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration::~Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }

  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  
  }

  //---------------------------------------------------------------------------- 
  bool 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //---------------------------------------------------------------------------- 
  int
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName&  
   Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration::getElement(int anIndex) const {
   
    Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumerationElement* followingP = m_firstElementP;
   
    int x=0;
    while (followingP && (x < anIndex) ) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName&
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumerationElement* currentP = m_currentElementP;
  	 m_currentElementP = m_currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  
  }
  	  
  //---------------------------------------------------------------------------- 
  void Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration::addElement
   (const Linux_DnsServiceSettingDataForServiceConfigurationInstanceName& anElementP){
   	
  	if (m_firstElementP==0) {
  	  m_firstElementP = new Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsServiceSettingDataForServiceConfigurationInstanceName(anElementP);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP=new Linux_DnsServiceSettingDataForServiceConfigurationInstanceName(anElementP);
  	}

  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceSettingDataForServiceConfigurationInstanceNameEnumeration::operator CmpiArray() const {
  	int size = getSize();
   	CmpiArray cmpiArray = CmpiArray(size,CMPI_instance);
   	for (int x=0; x < size; ++x) {
   	  cmpiArray[x]=getElement(x).getObjectPath();
   	}
   	return cmpiArray;
  }
  
}
