// =======================================================================
// Linux_DnsBlackholeACLForZoneInstanceName.cpp
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
#include "Linux_DnsBlackholeACLForZoneInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //****************************************************************************
  //Linux_DnsBlackholeACLForZoneInstanceName
  //---------------------------------------------------------------------------- 
  // empty constructor
  //---------------------------------------------------------------------------- 
  Linux_DnsBlackholeACLForZoneInstanceName::Linux_DnsBlackholeACLForZoneInstanceName() {
   	init();  	
  }
  
  //---------------------------------------------------------------------------- 
  // copy constructor	
  //---------------------------------------------------------------------------- 
  Linux_DnsBlackholeACLForZoneInstanceName::Linux_DnsBlackholeACLForZoneInstanceName(
    const Linux_DnsBlackholeACLForZoneInstanceName& anInstanceName) {
   	init(anInstanceName);  	
  }
  
  //---------------------------------------------------------------------------- 
  // constructor using CmpiObjectPath
  //---------------------------------------------------------------------------- 
  Linux_DnsBlackholeACLForZoneInstanceName::Linux_DnsBlackholeACLForZoneInstanceName(
    const CmpiObjectPath& path) {
    
    init();
    
    m_CIMClassNameP = path.getClassName().charPtr();
    
    CmpiString namespaceP;
    namespaceP = path.getNameSpace();
    setNamespace(namespaceP.charPtr(),1);
        
    CmpiObjectPath Setting = path.getKey("Setting");
    setSetting(Linux_DnsAddressMatchListInstanceName(Setting));
    
    CmpiObjectPath Element = path.getKey("Element");
    setElement(Linux_DnsZoneInstanceName(Element));

    
  }
  
  //---------------------------------------------------------------------------- 
  // destructor
  //---------------------------------------------------------------------------- 
  Linux_DnsBlackholeACLForZoneInstanceName::~Linux_DnsBlackholeACLForZoneInstanceName() {
   	reset();  	  
  }
  
  //---------------------------------------------------------------------------- 
  //copy operator
  //---------------------------------------------------------------------------- 
  Linux_DnsBlackholeACLForZoneInstanceName&
  Linux_DnsBlackholeACLForZoneInstanceName::operator=(
    const Linux_DnsBlackholeACLForZoneInstanceName& anInstanceName) {    
    
    init(anInstanceName);
   	return *this;    
  
  }
  
  //---------------------------------------------------------------------------- 
  //returns the related CmpiObjectPath
  //---------------------------------------------------------------------------- 
  CmpiObjectPath 
  Linux_DnsBlackholeACLForZoneInstanceName::getObjectPath() const {
   	
   	CmpiObjectPath objectPath(m_nameSpaceP, m_CIMClassNameP);
   	  	objectPath.setKey(
  	  "Setting",
  	  CmpiData(m_Setting.getObjectPath()));
  	objectPath.setKey(
  	  "Element",
  	  CmpiData(m_Element.getObjectPath()));

  	
  	return objectPath;
  	
  }
  
  //---------------------------------------------------------------------------- 
  // adds the related CmpiObjectPath to an existing cmpiInstance
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsBlackholeACLForZoneInstanceName::fillKeys(CmpiInstance& cmpiInstance) const {
  	
  	if (isSet.Setting) {
  	  
  	  cmpiInstance.setProperty(
  	    "Setting",
  	    CmpiData(m_Setting.getObjectPath()));
  	}

  	if (isSet.Element) {
  	  
  	  cmpiInstance.setProperty(
  	    "Element",
  	    CmpiData(m_Element.getObjectPath()));
  	}

  }
  
  
  //---------------------------------------------------------------------------- 
  // NameSpace related methods
  //---------------------------------------------------------------------------- 
  unsigned int 
  Linux_DnsBlackholeACLForZoneInstanceName::isNameSpaceSet() const {
  	return isSet.m_nameSpaceP;
  }
  
  //---------------------------------------------------------------------------- 
  const char* 
  Linux_DnsBlackholeACLForZoneInstanceName::getNamespace() const {
    if ( ! isSet.m_nameSpaceP) {
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace",
   	   "Linux_DnsBlackholeACLForZone");
   	}
  	return m_nameSpaceP;
  }

  //---------------------------------------------------------------------------- 
  void
  Linux_DnsBlackholeACLForZoneInstanceName::setNamespace(
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
  // Setting related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsBlackholeACLForZoneInstanceName::isSettingSet() const {
    return isSet.Setting;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsBlackholeACLForZoneInstanceName::setSetting(
    const Linux_DnsAddressMatchListInstanceName& aValue) {
  
    m_Setting = aValue;
    isSet.Setting = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsAddressMatchListInstanceName&
  Linux_DnsBlackholeACLForZoneInstanceName::getSetting() const {
    
    if ( ! isSet.Setting) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Setting",
        "Linux_DnsBlackholeACLForZone");
   	}


    return m_Setting;

  }
       
  //----------------------------------------------------------------------------
  // Element related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsBlackholeACLForZoneInstanceName::isElementSet() const {
    return isSet.Element;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsBlackholeACLForZoneInstanceName::setElement(
    const Linux_DnsZoneInstanceName& aValue) {
  
    m_Element = aValue;
    isSet.Element = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsZoneInstanceName&
  Linux_DnsBlackholeACLForZoneInstanceName::getElement() const {
    
    if ( ! isSet.Element) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Element",
        "Linux_DnsBlackholeACLForZone");
   	}


    return m_Element;

  }


  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsBlackholeACLForZoneInstanceName::init() {
  	
  	m_CIMClassNameP = "Linux_DnsBlackholeACLForZone";
  	isSet.m_nameSpaceP = 0; 
  	    isSet.Setting = 0;
    isSet.Element = 0;

  	
  }
  
  //---------------------------------------------------------------------------- 
  //copies another instance properties in this
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsBlackholeACLForZoneInstanceName::init(
    const Linux_DnsBlackholeACLForZoneInstanceName& anOriginal) {
   	
   	init();
   	   	
    m_CIMClassNameP = anOriginal.m_CIMClassNameP;
    if (anOriginal.isNameSpaceSet()){
      setNamespace(anOriginal.getNamespace(),1);
    }
       	
    if (anOriginal.isSettingSet()) {
      const Linux_DnsAddressMatchListInstanceName& SettingOriginal = anOriginal.getSetting();
      setSetting(SettingOriginal);
    }
   	
    if (anOriginal.isElementSet()) {
      const Linux_DnsZoneInstanceName& ElementOriginal = anOriginal.getElement();
      setElement(ElementOriginal);
    }
    
  
  }
  
  //---------------------------------------------------------------------------- 
  void
  Linux_DnsBlackholeACLForZoneInstanceName::reset() {
  	if (isSet.m_nameSpaceP) {
  	  delete(m_nameSpaceP);
  	}
  	  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsBlackholeACLForZoneInstanceNameEnumerationElement::Linux_DnsBlackholeACLForZoneInstanceNameEnumerationElement() {
  	m_elementP = 0;
  	m_nextP = 0; 
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsBlackholeACLForZoneInstanceNameEnumerationElement::~Linux_DnsBlackholeACLForZoneInstanceNameEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsBlackholeACLForZoneInstanceNameEnumeration::Linux_DnsBlackholeACLForZoneInstanceNameEnumeration() {
  	 m_firstElementP = 0;
     m_currentElementP = 0;
     m_endElementP = 0;
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsBlackholeACLForZoneInstanceNameEnumeration::Linux_DnsBlackholeACLForZoneInstanceNameEnumeration(
    const CmpiArray& aCmpiArray) {
  	
  	m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
    
    int size = aCmpiArray.size();
    for (int x=0; x < size; ++x) {
      addElement(Linux_DnsBlackholeACLForZoneInstanceName(aCmpiArray[x]));
    }
    
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsBlackholeACLForZoneInstanceNameEnumeration::Linux_DnsBlackholeACLForZoneInstanceNameEnumeration(
    const Linux_DnsBlackholeACLForZoneInstanceNameEnumeration& anInstanceNameEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceNameEnumeration.getSize();
    for (int x=0; x < size; ++x) {
      addElement(anInstanceNameEnumeration.getElement(x));
    }

  }
  	  
  //---------------------------------------------------------------------------- 
  Linux_DnsBlackholeACLForZoneInstanceNameEnumeration::~Linux_DnsBlackholeACLForZoneInstanceNameEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }

  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsBlackholeACLForZoneInstanceNameEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  
  }

  //---------------------------------------------------------------------------- 
  bool 
  Linux_DnsBlackholeACLForZoneInstanceNameEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //---------------------------------------------------------------------------- 
  int
  Linux_DnsBlackholeACLForZoneInstanceNameEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsBlackholeACLForZoneInstanceNameEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsBlackholeACLForZoneInstanceName&  
   Linux_DnsBlackholeACLForZoneInstanceNameEnumeration::getElement(int anIndex) const {
   
    Linux_DnsBlackholeACLForZoneInstanceNameEnumerationElement* followingP = m_firstElementP;
   
    int x=0;
    while (followingP && (x < anIndex) ) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsBlackholeACLForZoneInstanceName&
  Linux_DnsBlackholeACLForZoneInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsBlackholeACLForZoneInstanceNameEnumerationElement* currentP = m_currentElementP;
  	 m_currentElementP = m_currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  
  }
  	  
  //---------------------------------------------------------------------------- 
  void Linux_DnsBlackholeACLForZoneInstanceNameEnumeration::addElement
   (const Linux_DnsBlackholeACLForZoneInstanceName& anElementP){
   	
  	if (m_firstElementP==0) {
  	  m_firstElementP = new Linux_DnsBlackholeACLForZoneInstanceNameEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsBlackholeACLForZoneInstanceName(anElementP);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsBlackholeACLForZoneInstanceNameEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP=new Linux_DnsBlackholeACLForZoneInstanceName(anElementP);
  	}

  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsBlackholeACLForZoneInstanceNameEnumeration::operator CmpiArray() const {
  	int size = getSize();
   	CmpiArray cmpiArray = CmpiArray(size,CMPI_instance);
   	for (int x=0; x < size; ++x) {
   	  cmpiArray[x]=getElement(x).getObjectPath();
   	}
   	return cmpiArray;
  }
  
}
