// =======================================================================
// Linux_DnsSettingContextInstanceName.cpp
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
#include "Linux_DnsSettingContextInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //****************************************************************************
  //Linux_DnsSettingContextInstanceName
  //---------------------------------------------------------------------------- 
  // empty constructor
  //---------------------------------------------------------------------------- 
  Linux_DnsSettingContextInstanceName::Linux_DnsSettingContextInstanceName() {
   	init();  	
  }
  
  //---------------------------------------------------------------------------- 
  // copy constructor	
  //---------------------------------------------------------------------------- 
  Linux_DnsSettingContextInstanceName::Linux_DnsSettingContextInstanceName(
    const Linux_DnsSettingContextInstanceName& anInstanceName) {
   	init(anInstanceName);  	
  }
  
  //---------------------------------------------------------------------------- 
  // constructor using CmpiObjectPath
  //---------------------------------------------------------------------------- 
  Linux_DnsSettingContextInstanceName::Linux_DnsSettingContextInstanceName(
    const CmpiObjectPath& path) {
    
    init();
    
    m_CIMClassNameP = path.getClassName().charPtr();
    
    CmpiString namespaceP;
    namespaceP = path.getNameSpace();
    setNamespace(namespaceP.charPtr(),1);
        
    CmpiObjectPath Setting = path.getKey("Setting");
    setSetting(Linux_DnsSettingInstanceName(Setting));
    
    CmpiObjectPath Context = path.getKey("Context");
    setContext(Linux_DnsConfigurationInstanceName(Context));

    
  }
  
  //---------------------------------------------------------------------------- 
  // destructor
  //---------------------------------------------------------------------------- 
  Linux_DnsSettingContextInstanceName::~Linux_DnsSettingContextInstanceName() {
   	reset();  	  
  }
  
  //---------------------------------------------------------------------------- 
  //copy operator
  //---------------------------------------------------------------------------- 
  Linux_DnsSettingContextInstanceName&
  Linux_DnsSettingContextInstanceName::operator=(
    const Linux_DnsSettingContextInstanceName& anInstanceName) {    
    
    init(anInstanceName);
   	return *this;    
  
  }
  
  //---------------------------------------------------------------------------- 
  //returns the related CmpiObjectPath
  //---------------------------------------------------------------------------- 
  CmpiObjectPath 
  Linux_DnsSettingContextInstanceName::getObjectPath() const {
   	
   	CmpiObjectPath objectPath(m_nameSpaceP, m_CIMClassNameP);
   	  	objectPath.setKey(
  	  "Setting",
  	  CmpiData(m_Setting.getObjectPath()));
  	objectPath.setKey(
  	  "Context",
  	  CmpiData(m_Context.getObjectPath()));

  	
  	return objectPath;
  	
  }
  
  //---------------------------------------------------------------------------- 
  // adds the related CmpiObjectPath to an existing cmpiInstance
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsSettingContextInstanceName::fillKeys(CmpiInstance& cmpiInstance) const {
  	
  	if (isSet.Setting) {
  	  
  	  cmpiInstance.setProperty(
  	    "Setting",
  	    CmpiData(m_Setting.getObjectPath()));
  	}

  	if (isSet.Context) {
  	  
  	  cmpiInstance.setProperty(
  	    "Context",
  	    CmpiData(m_Context.getObjectPath()));
  	}

  }
  
  
  //---------------------------------------------------------------------------- 
  // NameSpace related methods
  //---------------------------------------------------------------------------- 
  unsigned int 
  Linux_DnsSettingContextInstanceName::isNameSpaceSet() const {
  	return isSet.m_nameSpaceP;
  }
  
  //---------------------------------------------------------------------------- 
  const char* 
  Linux_DnsSettingContextInstanceName::getNamespace() const {
    if ( ! isSet.m_nameSpaceP) {
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace",
   	   "Linux_DnsSettingContext");
   	}
  	return m_nameSpaceP;
  }

  //---------------------------------------------------------------------------- 
  void
  Linux_DnsSettingContextInstanceName::setNamespace(
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
  Linux_DnsSettingContextInstanceName::isSettingSet() const {
    return isSet.Setting;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsSettingContextInstanceName::setSetting(
    const Linux_DnsSettingInstanceName& aValue) {
  
    m_Setting = aValue;
    isSet.Setting = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsSettingInstanceName&
  Linux_DnsSettingContextInstanceName::getSetting() const {
    
    if ( ! isSet.Setting) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Setting",
        "Linux_DnsSettingContext");
   	}


    return m_Setting;

  }
       
  //----------------------------------------------------------------------------
  // Context related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsSettingContextInstanceName::isContextSet() const {
    return isSet.Context;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsSettingContextInstanceName::setContext(
    const Linux_DnsConfigurationInstanceName& aValue) {
  
    m_Context = aValue;
    isSet.Context = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsConfigurationInstanceName&
  Linux_DnsSettingContextInstanceName::getContext() const {
    
    if ( ! isSet.Context) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Context",
        "Linux_DnsSettingContext");
   	}


    return m_Context;

  }


  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsSettingContextInstanceName::init() {
  	
  	m_CIMClassNameP = "Linux_DnsSettingContext";
  	isSet.m_nameSpaceP = 0; 
  	    isSet.Setting = 0;
    isSet.Context = 0;

  	
  }
  
  //---------------------------------------------------------------------------- 
  //copies another instance properties in this
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsSettingContextInstanceName::init(
    const Linux_DnsSettingContextInstanceName& anOriginal) {
   	
   	init();
   	   	
    m_CIMClassNameP = anOriginal.m_CIMClassNameP;
    if (anOriginal.isNameSpaceSet()){
      setNamespace(anOriginal.getNamespace(),1);
    }
       	
    if (anOriginal.isSettingSet()) {
      const Linux_DnsSettingInstanceName& SettingOriginal = anOriginal.getSetting();
      setSetting(SettingOriginal);
    }
   	
    if (anOriginal.isContextSet()) {
      const Linux_DnsConfigurationInstanceName& ContextOriginal = anOriginal.getContext();
      setContext(ContextOriginal);
    }
    
  
  }
  
  //---------------------------------------------------------------------------- 
  void
  Linux_DnsSettingContextInstanceName::reset() {
  	if (isSet.m_nameSpaceP) {
  	  delete(m_nameSpaceP);
  	}
  	  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsSettingContextInstanceNameEnumerationElement::Linux_DnsSettingContextInstanceNameEnumerationElement() {
  	m_elementP = 0;
  	m_nextP = 0; 
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsSettingContextInstanceNameEnumerationElement::~Linux_DnsSettingContextInstanceNameEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsSettingContextInstanceNameEnumeration::Linux_DnsSettingContextInstanceNameEnumeration() {
  	 m_firstElementP = 0;
     m_currentElementP = 0;
     m_endElementP = 0;
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsSettingContextInstanceNameEnumeration::Linux_DnsSettingContextInstanceNameEnumeration(
    const CmpiArray& aCmpiArray) {
  	
  	m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
    
    int size = aCmpiArray.size();
    for (int x=0; x < size; ++x) {
      addElement(Linux_DnsSettingContextInstanceName(aCmpiArray[x]));
    }
    
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsSettingContextInstanceNameEnumeration::Linux_DnsSettingContextInstanceNameEnumeration(
    const Linux_DnsSettingContextInstanceNameEnumeration& anInstanceNameEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceNameEnumeration.getSize();
    for (int x=0; x < size; ++x) {
      addElement(anInstanceNameEnumeration.getElement(x));
    }

  }
  	  
  //---------------------------------------------------------------------------- 
  Linux_DnsSettingContextInstanceNameEnumeration::~Linux_DnsSettingContextInstanceNameEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }

  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsSettingContextInstanceNameEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  
  }

  //---------------------------------------------------------------------------- 
  bool 
  Linux_DnsSettingContextInstanceNameEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //---------------------------------------------------------------------------- 
  int
  Linux_DnsSettingContextInstanceNameEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsSettingContextInstanceNameEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsSettingContextInstanceName&  
   Linux_DnsSettingContextInstanceNameEnumeration::getElement(int anIndex) const {
   
    Linux_DnsSettingContextInstanceNameEnumerationElement* followingP = m_firstElementP;
   
    int x=0;
    while (followingP && (x < anIndex) ) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsSettingContextInstanceName&
  Linux_DnsSettingContextInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsSettingContextInstanceNameEnumerationElement* currentP = m_currentElementP;
  	 m_currentElementP = m_currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  
  }
  	  
  //---------------------------------------------------------------------------- 
  void Linux_DnsSettingContextInstanceNameEnumeration::addElement
   (const Linux_DnsSettingContextInstanceName& anElementP){
   	
  	if (m_firstElementP==0) {
  	  m_firstElementP = new Linux_DnsSettingContextInstanceNameEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsSettingContextInstanceName(anElementP);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsSettingContextInstanceNameEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP=new Linux_DnsSettingContextInstanceName(anElementP);
  	}

  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsSettingContextInstanceNameEnumeration::operator CmpiArray() const {
  	int size = getSize();
   	CmpiArray cmpiArray = CmpiArray(size,CMPI_instance);
   	for (int x=0; x < size; ++x) {
   	  cmpiArray[x]=getElement(x).getObjectPath();
   	}
   	return cmpiArray;
  }
  
}
