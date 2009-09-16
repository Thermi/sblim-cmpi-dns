// =======================================================================
// Linux_DnsServiceConfigurationForServiceInstanceName.cpp
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
#include "Linux_DnsServiceConfigurationForServiceInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //****************************************************************************
  //Linux_DnsServiceConfigurationForServiceInstanceName
  //---------------------------------------------------------------------------- 
  // empty constructor
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationForServiceInstanceName::Linux_DnsServiceConfigurationForServiceInstanceName() {
   	init();  	
  }
  
  //---------------------------------------------------------------------------- 
  // copy constructor	
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationForServiceInstanceName::Linux_DnsServiceConfigurationForServiceInstanceName(
    const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName) {
   	init(anInstanceName);  	
  }
  
  //---------------------------------------------------------------------------- 
  // constructor using CmpiObjectPath
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationForServiceInstanceName::Linux_DnsServiceConfigurationForServiceInstanceName(
    const CmpiObjectPath& path) {
    
    init();
    
    m_CIMClassNameP = path.getClassName().charPtr();
    
    CmpiString namespaceP;
    namespaceP = path.getNameSpace();
    setNamespace(namespaceP.charPtr(),1);
        
    CmpiObjectPath Element = path.getKey("Element");
    setElement(Linux_DnsServiceInstanceName(Element));
    
    CmpiObjectPath Configuration = path.getKey("Configuration");
    setConfiguration(Linux_DnsServiceConfigurationInstanceName(Configuration));

    
  }
  
  //---------------------------------------------------------------------------- 
  // destructor
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationForServiceInstanceName::~Linux_DnsServiceConfigurationForServiceInstanceName() {
   	reset();  	  
  }
  
  //---------------------------------------------------------------------------- 
  //copy operator
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationForServiceInstanceName&
  Linux_DnsServiceConfigurationForServiceInstanceName::operator=(
    const Linux_DnsServiceConfigurationForServiceInstanceName& anInstanceName) {    
    
    init(anInstanceName);
   	return *this;    
  
  }
  
  //---------------------------------------------------------------------------- 
  //returns the related CmpiObjectPath
  //---------------------------------------------------------------------------- 
  CmpiObjectPath 
  Linux_DnsServiceConfigurationForServiceInstanceName::getObjectPath() const {
   	
   	CmpiObjectPath objectPath(m_nameSpaceP, m_CIMClassNameP);
   	  	objectPath.setKey(
  	  "Element",
  	  CmpiData(m_Element.getObjectPath()));
  	objectPath.setKey(
  	  "Configuration",
  	  CmpiData(m_Configuration.getObjectPath()));

  	
  	return objectPath;
  	
  }
  
  //---------------------------------------------------------------------------- 
  // adds the related CmpiObjectPath to an existing cmpiInstance
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsServiceConfigurationForServiceInstanceName::fillKeys(CmpiInstance& cmpiInstance) const {
  	
  	if (isSet.Element) {
  	  
  	  cmpiInstance.setProperty(
  	    "Element",
  	    CmpiData(m_Element.getObjectPath()));
  	}

  	if (isSet.Configuration) {
  	  
  	  cmpiInstance.setProperty(
  	    "Configuration",
  	    CmpiData(m_Configuration.getObjectPath()));
  	}

  }
  
  
  //---------------------------------------------------------------------------- 
  // NameSpace related methods
  //---------------------------------------------------------------------------- 
  unsigned int 
  Linux_DnsServiceConfigurationForServiceInstanceName::isNameSpaceSet() const {
  	return isSet.m_nameSpaceP;
  }
  
  //---------------------------------------------------------------------------- 
  const char* 
  Linux_DnsServiceConfigurationForServiceInstanceName::getNamespace() const {
    if ( ! isSet.m_nameSpaceP) {
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace",
   	   "Linux_DnsServiceConfigurationForService");
   	}
  	return m_nameSpaceP;
  }

  //---------------------------------------------------------------------------- 
  void
  Linux_DnsServiceConfigurationForServiceInstanceName::setNamespace(
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
  // Element related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceConfigurationForServiceInstanceName::isElementSet() const {
    return isSet.Element;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceConfigurationForServiceInstanceName::setElement(
    const Linux_DnsServiceInstanceName& aValue) {
  
    m_Element = aValue;
    isSet.Element = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsServiceInstanceName&
  Linux_DnsServiceConfigurationForServiceInstanceName::getElement() const {
    
    if ( ! isSet.Element) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Element",
        "Linux_DnsServiceConfigurationForService");
   	}


    return m_Element;

  }
       
  //----------------------------------------------------------------------------
  // Configuration related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceConfigurationForServiceInstanceName::isConfigurationSet() const {
    return isSet.Configuration;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceConfigurationForServiceInstanceName::setConfiguration(
    const Linux_DnsServiceConfigurationInstanceName& aValue) {
  
    m_Configuration = aValue;
    isSet.Configuration = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsServiceConfigurationInstanceName&
  Linux_DnsServiceConfigurationForServiceInstanceName::getConfiguration() const {
    
    if ( ! isSet.Configuration) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Configuration",
        "Linux_DnsServiceConfigurationForService");
   	}


    return m_Configuration;

  }


  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsServiceConfigurationForServiceInstanceName::init() {
  	
  	m_CIMClassNameP = "Linux_DnsServiceConfigurationForService";
  	isSet.m_nameSpaceP = 0; 
  	    isSet.Element = 0;
    isSet.Configuration = 0;

  	
  }
  
  //---------------------------------------------------------------------------- 
  //copies another instance properties in this
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsServiceConfigurationForServiceInstanceName::init(
    const Linux_DnsServiceConfigurationForServiceInstanceName& anOriginal) {
   	
   	init();
   	   	
    m_CIMClassNameP = anOriginal.m_CIMClassNameP;
    if (anOriginal.isNameSpaceSet()){
      setNamespace(anOriginal.getNamespace(),1);
    }
       	
    if (anOriginal.isElementSet()) {
      const Linux_DnsServiceInstanceName& ElementOriginal = anOriginal.getElement();
      setElement(ElementOriginal);
    }
   	
    if (anOriginal.isConfigurationSet()) {
      const Linux_DnsServiceConfigurationInstanceName& ConfigurationOriginal = anOriginal.getConfiguration();
      setConfiguration(ConfigurationOriginal);
    }
    
  
  }
  
  //---------------------------------------------------------------------------- 
  void
  Linux_DnsServiceConfigurationForServiceInstanceName::reset() {
  	if (isSet.m_nameSpaceP) {
  	  delete(m_nameSpaceP);
  	}
  	  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationForServiceInstanceNameEnumerationElement::Linux_DnsServiceConfigurationForServiceInstanceNameEnumerationElement() {
  	m_elementP = 0;
  	m_nextP = 0; 
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationForServiceInstanceNameEnumerationElement::~Linux_DnsServiceConfigurationForServiceInstanceNameEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration::Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration() {
  	 m_firstElementP = 0;
     m_currentElementP = 0;
     m_endElementP = 0;
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration::Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration(
    const CmpiArray& aCmpiArray) {
  	
  	m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
    
    int size = aCmpiArray.size();
    for (int x=0; x < size; ++x) {
      addElement(Linux_DnsServiceConfigurationForServiceInstanceName(aCmpiArray[x]));
    }
    
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration::Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration(
    const Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceNameEnumeration.getSize();
    for (int x=0; x < size; ++x) {
      addElement(anInstanceNameEnumeration.getElement(x));
    }

  }
  	  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration::~Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }

  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  
  }

  //---------------------------------------------------------------------------- 
  bool 
  Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //---------------------------------------------------------------------------- 
  int
  Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsServiceConfigurationForServiceInstanceNameEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsServiceConfigurationForServiceInstanceName&  
   Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration::getElement(int anIndex) const {
   
    Linux_DnsServiceConfigurationForServiceInstanceNameEnumerationElement* followingP = m_firstElementP;
   
    int x=0;
    while (followingP && (x < anIndex) ) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsServiceConfigurationForServiceInstanceName&
  Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsServiceConfigurationForServiceInstanceNameEnumerationElement* currentP = m_currentElementP;
  	 m_currentElementP = m_currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  
  }
  	  
  //---------------------------------------------------------------------------- 
  void Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration::addElement
   (const Linux_DnsServiceConfigurationForServiceInstanceName& anElementP){
   	
  	if (m_firstElementP==0) {
  	  m_firstElementP = new Linux_DnsServiceConfigurationForServiceInstanceNameEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsServiceConfigurationForServiceInstanceName(anElementP);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsServiceConfigurationForServiceInstanceNameEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP=new Linux_DnsServiceConfigurationForServiceInstanceName(anElementP);
  	}

  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsServiceConfigurationForServiceInstanceNameEnumeration::operator CmpiArray() const {
  	int size = getSize();
   	CmpiArray cmpiArray = CmpiArray(size,CMPI_instance);
   	for (int x=0; x < size; ++x) {
   	  cmpiArray[x]=getElement(x).getObjectPath();
   	}
   	return cmpiArray;
  }
  
}
