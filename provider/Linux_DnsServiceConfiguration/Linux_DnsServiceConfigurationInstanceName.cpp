// =======================================================================
// Linux_DnsServiceConfigurationInstanceName.cpp
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
#include "Linux_DnsServiceConfigurationInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //****************************************************************************
  //Linux_DnsServiceConfigurationInstanceName
  //---------------------------------------------------------------------------- 
  // empty constructor
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationInstanceName::Linux_DnsServiceConfigurationInstanceName() {
   	init();  	
  }
  
  //---------------------------------------------------------------------------- 
  // copy constructor	
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationInstanceName::Linux_DnsServiceConfigurationInstanceName(
    const Linux_DnsServiceConfigurationInstanceName& anInstanceName) {
   	init(anInstanceName);  	
  }
  
  //---------------------------------------------------------------------------- 
  // constructor using CmpiObjectPath
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationInstanceName::Linux_DnsServiceConfigurationInstanceName(
    const CmpiObjectPath& path) {
    
    init();
    
    m_CIMClassNameP = path.getClassName().charPtr();
    
    CmpiString namespaceP;
    namespaceP = path.getNameSpace();
    setNamespace(namespaceP.charPtr(),1);
        
    CmpiObjectPath Configuration = path.getKey("Configuration");
    setConfiguration(Linux_DnsConfigurationInstanceName(Configuration));
    
    CmpiObjectPath Element = path.getKey("Element");
    setElement(Linux_DnsServiceInstanceName(Element));

    
  }
  
  //---------------------------------------------------------------------------- 
  // destructor
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationInstanceName::~Linux_DnsServiceConfigurationInstanceName() {
   	reset();  	  
  }
  
  //---------------------------------------------------------------------------- 
  //copy operator
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationInstanceName&
  Linux_DnsServiceConfigurationInstanceName::operator=(
    const Linux_DnsServiceConfigurationInstanceName& anInstanceName) {    
    
    init(anInstanceName);
   	return *this;    
  
  }
  
  //---------------------------------------------------------------------------- 
  //returns the related CmpiObjectPath
  //---------------------------------------------------------------------------- 
  CmpiObjectPath 
  Linux_DnsServiceConfigurationInstanceName::getObjectPath() const {
   	
   	CmpiObjectPath objectPath(m_nameSpaceP, m_CIMClassNameP);
   	  	objectPath.setKey(
  	  "Configuration",
  	  CmpiData(m_Configuration.getObjectPath()));
  	objectPath.setKey(
  	  "Element",
  	  CmpiData(m_Element.getObjectPath()));

  	
  	return objectPath;
  	
  }
  
  //---------------------------------------------------------------------------- 
  // adds the related CmpiObjectPath to an existing cmpiInstance
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsServiceConfigurationInstanceName::fillKeys(CmpiInstance& cmpiInstance) const {
  	
  	if (isSet.Configuration) {
  	  
  	  cmpiInstance.setProperty(
  	    "Configuration",
  	    CmpiData(m_Configuration.getObjectPath()));
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
  Linux_DnsServiceConfigurationInstanceName::isNameSpaceSet() const {
  	return isSet.m_nameSpaceP;
  }
  
  //---------------------------------------------------------------------------- 
  const char* 
  Linux_DnsServiceConfigurationInstanceName::getNamespace() const {
    if ( ! isSet.m_nameSpaceP) {
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace",
   	   "Linux_DnsServiceConfiguration");
   	}
  	return m_nameSpaceP;
  }

  //---------------------------------------------------------------------------- 
  void
  Linux_DnsServiceConfigurationInstanceName::setNamespace(
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
  // Configuration related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceConfigurationInstanceName::isConfigurationSet() const {
    return isSet.Configuration;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceConfigurationInstanceName::setConfiguration(
    const Linux_DnsConfigurationInstanceName& aValue) {
  
    m_Configuration = aValue;
    isSet.Configuration = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsConfigurationInstanceName&
  Linux_DnsServiceConfigurationInstanceName::getConfiguration() const {
    
    if ( ! isSet.Configuration) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Configuration",
        "Linux_DnsServiceConfiguration");
   	}


    return m_Configuration;

  }
       
  //----------------------------------------------------------------------------
  // Element related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceConfigurationInstanceName::isElementSet() const {
    return isSet.Element;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceConfigurationInstanceName::setElement(
    const Linux_DnsServiceInstanceName& aValue) {
  
    m_Element = aValue;
    isSet.Element = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsServiceInstanceName&
  Linux_DnsServiceConfigurationInstanceName::getElement() const {
    
    if ( ! isSet.Element) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Element",
        "Linux_DnsServiceConfiguration");
   	}


    return m_Element;

  }


  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsServiceConfigurationInstanceName::init() {
  	
  	m_CIMClassNameP = "Linux_DnsServiceConfiguration";
  	isSet.m_nameSpaceP = 0; 
  	    isSet.Configuration = 0;
    isSet.Element = 0;

  	
  }
  
  //---------------------------------------------------------------------------- 
  //copies another instance properties in this
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsServiceConfigurationInstanceName::init(
    const Linux_DnsServiceConfigurationInstanceName& anOriginal) {
   	
   	init();
   	   	
    m_CIMClassNameP = anOriginal.m_CIMClassNameP;
    if (anOriginal.isNameSpaceSet()){
      setNamespace(anOriginal.getNamespace(),1);
    }
       	
    if (anOriginal.isConfigurationSet()) {
      const Linux_DnsConfigurationInstanceName& ConfigurationOriginal = anOriginal.getConfiguration();
      setConfiguration(ConfigurationOriginal);
    }
   	
    if (anOriginal.isElementSet()) {
      const Linux_DnsServiceInstanceName& ElementOriginal = anOriginal.getElement();
      setElement(ElementOriginal);
    }
    
  
  }
  
  //---------------------------------------------------------------------------- 
  void
  Linux_DnsServiceConfigurationInstanceName::reset() {
  	if (isSet.m_nameSpaceP) {
  	  delete(m_nameSpaceP);
  	}
  	  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationInstanceNameEnumerationElement::Linux_DnsServiceConfigurationInstanceNameEnumerationElement() {
  	m_elementP = 0;
  	m_nextP = 0; 
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationInstanceNameEnumerationElement::~Linux_DnsServiceConfigurationInstanceNameEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationInstanceNameEnumeration::Linux_DnsServiceConfigurationInstanceNameEnumeration() {
  	 m_firstElementP = 0;
     m_currentElementP = 0;
     m_endElementP = 0;
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationInstanceNameEnumeration::Linux_DnsServiceConfigurationInstanceNameEnumeration(
    const CmpiArray& aCmpiArray) {
  	
  	m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
    
    int size = aCmpiArray.size();
    for (int x=0; x < size; ++x) {
      addElement(Linux_DnsServiceConfigurationInstanceName(aCmpiArray[x]));
    }
    
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationInstanceNameEnumeration::Linux_DnsServiceConfigurationInstanceNameEnumeration(
    const Linux_DnsServiceConfigurationInstanceNameEnumeration& anInstanceNameEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceNameEnumeration.getSize();
    for (int x=0; x < size; ++x) {
      addElement(anInstanceNameEnumeration.getElement(x));
    }

  }
  	  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationInstanceNameEnumeration::~Linux_DnsServiceConfigurationInstanceNameEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }

  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsServiceConfigurationInstanceNameEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  
  }

  //---------------------------------------------------------------------------- 
  bool 
  Linux_DnsServiceConfigurationInstanceNameEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //---------------------------------------------------------------------------- 
  int
  Linux_DnsServiceConfigurationInstanceNameEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsServiceConfigurationInstanceNameEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsServiceConfigurationInstanceName&  
   Linux_DnsServiceConfigurationInstanceNameEnumeration::getElement(int anIndex) const {
   
    Linux_DnsServiceConfigurationInstanceNameEnumerationElement* followingP = m_firstElementP;
   
    int x=0;
    while (followingP && (x < anIndex) ) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsServiceConfigurationInstanceName&
  Linux_DnsServiceConfigurationInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsServiceConfigurationInstanceNameEnumerationElement* currentP = m_currentElementP;
  	 m_currentElementP = m_currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  
  }
  	  
  //---------------------------------------------------------------------------- 
  void Linux_DnsServiceConfigurationInstanceNameEnumeration::addElement
   (const Linux_DnsServiceConfigurationInstanceName& anElementP){
   	
  	if (m_firstElementP==0) {
  	  m_firstElementP = new Linux_DnsServiceConfigurationInstanceNameEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsServiceConfigurationInstanceName(anElementP);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsServiceConfigurationInstanceNameEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP=new Linux_DnsServiceConfigurationInstanceName(anElementP);
  	}

  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationInstanceNameEnumeration::operator CmpiArray() const {
  	int size = getSize();
   	CmpiArray cmpiArray = CmpiArray(size,CMPI_instance);
   	for (int x=0; x < size; ++x) {
   	  cmpiArray[x]=getElement(x).getObjectPath();
   	}
   	return cmpiArray;
  }
  
}
