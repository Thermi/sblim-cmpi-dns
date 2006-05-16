// =======================================================================
// Linux_DnsElementSettingInstanceName.cpp
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
#include "Linux_DnsElementSettingInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //****************************************************************************
  //Linux_DnsElementSettingInstanceName
  //---------------------------------------------------------------------------- 
  // empty constructor
  //---------------------------------------------------------------------------- 
  Linux_DnsElementSettingInstanceName::Linux_DnsElementSettingInstanceName() {
   	init();  	
  }
  
  //---------------------------------------------------------------------------- 
  // copy constructor	
  //---------------------------------------------------------------------------- 
  Linux_DnsElementSettingInstanceName::Linux_DnsElementSettingInstanceName(
    const Linux_DnsElementSettingInstanceName& anInstanceName) {
   	init(anInstanceName);  	
  }
  
  //---------------------------------------------------------------------------- 
  // constructor using CmpiObjectPath
  //---------------------------------------------------------------------------- 
  Linux_DnsElementSettingInstanceName::Linux_DnsElementSettingInstanceName(
    const CmpiObjectPath& path) {
    
    init();
    
    m_CIMClassNameP = path.getClassName().charPtr();
    
    CmpiString namespaceP;
    namespaceP = path.getNameSpace();
    setNamespace(namespaceP.charPtr(),1);
        
    CmpiObjectPath Setting = path.getKey("Setting");
    setSetting(Linux_DnsSettingInstanceName(Setting));
    
    CmpiObjectPath Element = path.getKey("Element");
    setElement(Linux_DnsServiceInstanceName(Element));

    
  }
  
  //---------------------------------------------------------------------------- 
  // destructor
  //---------------------------------------------------------------------------- 
  Linux_DnsElementSettingInstanceName::~Linux_DnsElementSettingInstanceName() {
   	reset();  	  
  }
  
  //---------------------------------------------------------------------------- 
  //copy operator
  //---------------------------------------------------------------------------- 
  Linux_DnsElementSettingInstanceName&
  Linux_DnsElementSettingInstanceName::operator=(
    const Linux_DnsElementSettingInstanceName& anInstanceName) {    
    
    init(anInstanceName);
   	return *this;    
  
  }
  
  //---------------------------------------------------------------------------- 
  //returns the related CmpiObjectPath
  //---------------------------------------------------------------------------- 
  CmpiObjectPath 
  Linux_DnsElementSettingInstanceName::getObjectPath() const {
   	
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
  Linux_DnsElementSettingInstanceName::fillKeys(CmpiInstance& cmpiInstance) const {
  	
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
  Linux_DnsElementSettingInstanceName::isNameSpaceSet() const {
  	return isSet.m_nameSpaceP;
  }
  
  //---------------------------------------------------------------------------- 
  const char* 
  Linux_DnsElementSettingInstanceName::getNamespace() const {
    if ( ! isSet.m_nameSpaceP) {
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace",
   	   "Linux_DnsElementSetting");
   	}
  	return m_nameSpaceP;
  }

  //---------------------------------------------------------------------------- 
  void
  Linux_DnsElementSettingInstanceName::setNamespace(
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
  Linux_DnsElementSettingInstanceName::isSettingSet() const {
    return isSet.Setting;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsElementSettingInstanceName::setSetting(
    const Linux_DnsSettingInstanceName& aValue) {
  
    m_Setting = aValue;
    isSet.Setting = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsSettingInstanceName&
  Linux_DnsElementSettingInstanceName::getSetting() const {
    
    if ( ! isSet.Setting) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Setting",
        "Linux_DnsElementSetting");
   	}


    return m_Setting;

  }
       
  //----------------------------------------------------------------------------
  // Element related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsElementSettingInstanceName::isElementSet() const {
    return isSet.Element;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsElementSettingInstanceName::setElement(
    const Linux_DnsServiceInstanceName& aValue) {
  
    m_Element = aValue;
    isSet.Element = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsServiceInstanceName&
  Linux_DnsElementSettingInstanceName::getElement() const {
    
    if ( ! isSet.Element) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Element",
        "Linux_DnsElementSetting");
   	}


    return m_Element;

  }


  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsElementSettingInstanceName::init() {
  	
  	m_CIMClassNameP = "Linux_DnsElementSetting";
  	isSet.m_nameSpaceP = 0; 
  	    isSet.Setting = 0;
    isSet.Element = 0;

  	
  }
  
  //---------------------------------------------------------------------------- 
  //copies another instance properties in this
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsElementSettingInstanceName::init(
    const Linux_DnsElementSettingInstanceName& anOriginal) {
   	
   	init();
   	   	
    m_CIMClassNameP = anOriginal.m_CIMClassNameP;
    if (anOriginal.isNameSpaceSet()){
      setNamespace(anOriginal.getNamespace(),1);
    }
       	
    if (anOriginal.isSettingSet()) {
      const Linux_DnsSettingInstanceName& SettingOriginal = anOriginal.getSetting();
      setSetting(SettingOriginal);
    }
   	
    if (anOriginal.isElementSet()) {
      const Linux_DnsServiceInstanceName& ElementOriginal = anOriginal.getElement();
      setElement(ElementOriginal);
    }
    
  
  }
  
  //---------------------------------------------------------------------------- 
  void
  Linux_DnsElementSettingInstanceName::reset() {
  	if (isSet.m_nameSpaceP) {
  	  delete(m_nameSpaceP);
  	}
  	  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsElementSettingInstanceNameEnumerationElement::Linux_DnsElementSettingInstanceNameEnumerationElement() {
  	m_elementP = 0;
  	m_nextP = 0; 
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsElementSettingInstanceNameEnumerationElement::~Linux_DnsElementSettingInstanceNameEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsElementSettingInstanceNameEnumeration::Linux_DnsElementSettingInstanceNameEnumeration() {
  	 m_firstElementP = 0;
     m_currentElementP = 0;
     m_endElementP = 0;
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsElementSettingInstanceNameEnumeration::Linux_DnsElementSettingInstanceNameEnumeration(
    const CmpiArray& aCmpiArray) {
  	
  	m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
    
    int size = aCmpiArray.size();
    for (int x=0; x < size; ++x) {
      addElement(Linux_DnsElementSettingInstanceName(aCmpiArray[x]));
    }
    
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsElementSettingInstanceNameEnumeration::Linux_DnsElementSettingInstanceNameEnumeration(
    const Linux_DnsElementSettingInstanceNameEnumeration& anInstanceNameEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceNameEnumeration.getSize();
    for (int x=0; x < size; ++x) {
      addElement(anInstanceNameEnumeration.getElement(x));
    }

  }
  	  
  //---------------------------------------------------------------------------- 
  Linux_DnsElementSettingInstanceNameEnumeration::~Linux_DnsElementSettingInstanceNameEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }

  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsElementSettingInstanceNameEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  
  }

  //---------------------------------------------------------------------------- 
  bool 
  Linux_DnsElementSettingInstanceNameEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //---------------------------------------------------------------------------- 
  int
  Linux_DnsElementSettingInstanceNameEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsElementSettingInstanceNameEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsElementSettingInstanceName&  
   Linux_DnsElementSettingInstanceNameEnumeration::getElement(int anIndex) const {
   
    Linux_DnsElementSettingInstanceNameEnumerationElement* followingP = m_firstElementP;
   
    int x=0;
    while (followingP && (x < anIndex) ) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsElementSettingInstanceName&
  Linux_DnsElementSettingInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsElementSettingInstanceNameEnumerationElement* currentP = m_currentElementP;
  	 m_currentElementP = m_currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  
  }
  	  
  //---------------------------------------------------------------------------- 
  void Linux_DnsElementSettingInstanceNameEnumeration::addElement
   (const Linux_DnsElementSettingInstanceName& anElementP){
   	
  	if (m_firstElementP==0) {
  	  m_firstElementP = new Linux_DnsElementSettingInstanceNameEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsElementSettingInstanceName(anElementP);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsElementSettingInstanceNameEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP=new Linux_DnsElementSettingInstanceName(anElementP);
  	}

  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsElementSettingInstanceNameEnumeration::operator CmpiArray() const {
  	int size = getSize();
   	CmpiArray cmpiArray = CmpiArray(size,CMPI_instance);
   	for (int x=0; x < size; ++x) {
   	  cmpiArray[x]=getElement(x).getObjectPath();
   	}
   	return cmpiArray;
  }
  
}
