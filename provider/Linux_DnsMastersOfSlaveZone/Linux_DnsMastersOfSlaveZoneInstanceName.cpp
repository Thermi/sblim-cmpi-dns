// =======================================================================
// Linux_DnsMastersOfSlaveZoneInstanceName.cpp
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
#include "Linux_DnsMastersOfSlaveZoneInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //****************************************************************************
  //Linux_DnsMastersOfSlaveZoneInstanceName
  //---------------------------------------------------------------------------- 
  // empty constructor
  //---------------------------------------------------------------------------- 
  Linux_DnsMastersOfSlaveZoneInstanceName::Linux_DnsMastersOfSlaveZoneInstanceName() {
   	init();  	
  }
  
  //---------------------------------------------------------------------------- 
  // copy constructor	
  //---------------------------------------------------------------------------- 
  Linux_DnsMastersOfSlaveZoneInstanceName::Linux_DnsMastersOfSlaveZoneInstanceName(
    const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName) {
   	init(anInstanceName);  	
  }
  
  //---------------------------------------------------------------------------- 
  // constructor using CmpiObjectPath
  //---------------------------------------------------------------------------- 
  Linux_DnsMastersOfSlaveZoneInstanceName::Linux_DnsMastersOfSlaveZoneInstanceName(
    const CmpiObjectPath& path) {
    
    init();
    
    m_CIMClassNameP = path.getClassName().charPtr();
    
    CmpiString namespaceP;
    namespaceP = path.getNameSpace();
    setNamespace(namespaceP.charPtr(),1);
        
    CmpiObjectPath Setting = path.getKey("Setting");
    setSetting(Linux_DnsIPAddressInstanceName(Setting));
    
    CmpiObjectPath Element = path.getKey("Element");
    setElement(Linux_DnsSlaveZoneInstanceName(Element));

    
  }
  
  //---------------------------------------------------------------------------- 
  // destructor
  //---------------------------------------------------------------------------- 
  Linux_DnsMastersOfSlaveZoneInstanceName::~Linux_DnsMastersOfSlaveZoneInstanceName() {
   	reset();  	  
  }
  
  //---------------------------------------------------------------------------- 
  //copy operator
  //---------------------------------------------------------------------------- 
  Linux_DnsMastersOfSlaveZoneInstanceName&
  Linux_DnsMastersOfSlaveZoneInstanceName::operator=(
    const Linux_DnsMastersOfSlaveZoneInstanceName& anInstanceName) {    
    
    init(anInstanceName);
   	return *this;    
  
  }
  
  //---------------------------------------------------------------------------- 
  //returns the related CmpiObjectPath
  //---------------------------------------------------------------------------- 
  CmpiObjectPath 
  Linux_DnsMastersOfSlaveZoneInstanceName::getObjectPath() const {
   	
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
  Linux_DnsMastersOfSlaveZoneInstanceName::fillKeys(CmpiInstance& cmpiInstance) const {
  	
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
  Linux_DnsMastersOfSlaveZoneInstanceName::isNameSpaceSet() const {
  	return isSet.m_nameSpaceP;
  }
  
  //---------------------------------------------------------------------------- 
  const char* 
  Linux_DnsMastersOfSlaveZoneInstanceName::getNamespace() const {
    if ( ! isSet.m_nameSpaceP) {
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace",
   	   "Linux_DnsMastersOfSlaveZone");
   	}
  	return m_nameSpaceP;
  }

  //---------------------------------------------------------------------------- 
  void
  Linux_DnsMastersOfSlaveZoneInstanceName::setNamespace(
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
  Linux_DnsMastersOfSlaveZoneInstanceName::isSettingSet() const {
    return isSet.Setting;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMastersOfSlaveZoneInstanceName::setSetting(
    const Linux_DnsIPAddressInstanceName& aValue) {
  
    m_Setting = aValue;
    isSet.Setting = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsIPAddressInstanceName&
  Linux_DnsMastersOfSlaveZoneInstanceName::getSetting() const {
    
    if ( ! isSet.Setting) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Setting",
        "Linux_DnsMastersOfSlaveZone");
   	}


    return m_Setting;

  }
       
  //----------------------------------------------------------------------------
  // Element related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMastersOfSlaveZoneInstanceName::isElementSet() const {
    return isSet.Element;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMastersOfSlaveZoneInstanceName::setElement(
    const Linux_DnsSlaveZoneInstanceName& aValue) {
  
    m_Element = aValue;
    isSet.Element = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsSlaveZoneInstanceName&
  Linux_DnsMastersOfSlaveZoneInstanceName::getElement() const {
    
    if ( ! isSet.Element) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Element",
        "Linux_DnsMastersOfSlaveZone");
   	}


    return m_Element;

  }


  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsMastersOfSlaveZoneInstanceName::init() {
  	
  	m_CIMClassNameP = "Linux_DnsMastersOfSlaveZone";
  	isSet.m_nameSpaceP = 0; 
  	    isSet.Setting = 0;
    isSet.Element = 0;

  	
  }
  
  //---------------------------------------------------------------------------- 
  //copies another instance properties in this
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsMastersOfSlaveZoneInstanceName::init(
    const Linux_DnsMastersOfSlaveZoneInstanceName& anOriginal) {
   	
   	init();
   	   	
    m_CIMClassNameP = anOriginal.m_CIMClassNameP;
    if (anOriginal.isNameSpaceSet()){
      setNamespace(anOriginal.getNamespace(),1);
    }
       	
    if (anOriginal.isSettingSet()) {
      const Linux_DnsIPAddressInstanceName& SettingOriginal = anOriginal.getSetting();
      setSetting(SettingOriginal);
    }
   	
    if (anOriginal.isElementSet()) {
      const Linux_DnsSlaveZoneInstanceName& ElementOriginal = anOriginal.getElement();
      setElement(ElementOriginal);
    }
    
  
  }
  
  //---------------------------------------------------------------------------- 
  void
  Linux_DnsMastersOfSlaveZoneInstanceName::reset() {
  	if (isSet.m_nameSpaceP) {
  	  delete(m_nameSpaceP);
  	}
  	  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement::Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement() {
  	m_elementP = 0;
  	m_nextP = 0; 
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement::~Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration() {
  	 m_firstElementP = 0;
     m_currentElementP = 0;
     m_endElementP = 0;
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration(
    const CmpiArray& aCmpiArray) {
  	
  	m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
    
    int size = aCmpiArray.size();
    for (int x=0; x < size; ++x) {
      addElement(Linux_DnsMastersOfSlaveZoneInstanceName(aCmpiArray[x]));
    }
    
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration(
    const Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& anInstanceNameEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceNameEnumeration.getSize();
    for (int x=0; x < size; ++x) {
      addElement(anInstanceNameEnumeration.getElement(x));
    }

  }
  	  
  //---------------------------------------------------------------------------- 
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::~Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }

  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  
  }

  //---------------------------------------------------------------------------- 
  bool 
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //---------------------------------------------------------------------------- 
  int
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsMastersOfSlaveZoneInstanceName&  
   Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::getElement(int anIndex) const {
   
    Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement* followingP = m_firstElementP;
   
    int x=0;
    while (followingP && (x < anIndex) ) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsMastersOfSlaveZoneInstanceName&
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement* currentP = m_currentElementP;
  	 m_currentElementP = m_currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  
  }
  	  
  //---------------------------------------------------------------------------- 
  void Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::addElement
   (const Linux_DnsMastersOfSlaveZoneInstanceName& anElementP){
   	
  	if (m_firstElementP==0) {
  	  m_firstElementP = new Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsMastersOfSlaveZoneInstanceName(anElementP);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP=new Linux_DnsMastersOfSlaveZoneInstanceName(anElementP);
  	}

  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration::operator CmpiArray() const {
  	int size = getSize();
   	CmpiArray cmpiArray = CmpiArray(size,CMPI_instance);
   	for (int x=0; x < size; ++x) {
   	  cmpiArray[x]=getElement(x).getObjectPath();
   	}
   	return cmpiArray;
  }
  
}
