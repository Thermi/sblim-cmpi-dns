// =======================================================================
// Linux_DnsServiceConfigurationInstanceName.cpp
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
        
    CmpiString Name = path.getKey("Name");
    setName(Name.charPtr());

    
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
  	  "Name",
  	  CmpiData(m_Name));

  	
  	return objectPath;
  	
  }
  
  //---------------------------------------------------------------------------- 
  // adds the related CmpiObjectPath to an existing cmpiInstance
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsServiceConfigurationInstanceName::fillKeys(CmpiInstance& cmpiInstance) const {
  	
  	if (isSet.Name) {
  	  
  	  cmpiInstance.setProperty(
  	    "Name",
  	    CmpiData(m_Name));
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
  // Name related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceConfigurationInstanceName::isNameSet() const {
    return isSet.Name;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceConfigurationInstanceName::setName(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.Name) {
      delete [] m_Name;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_Name = valueP;
    } else {
      m_Name = aValueP;
    }
    
    isSet.Name = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsServiceConfigurationInstanceName::getName() const {
    
    if ( ! isSet.Name) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Name",
        "Linux_DnsServiceConfiguration");
   	}


    return m_Name;

  }


  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsServiceConfigurationInstanceName::init() {
  	
  	m_CIMClassNameP = "Linux_DnsServiceConfiguration";
  	isSet.m_nameSpaceP = 0; 
  	    isSet.Name = 0;

  	
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
       	
    if (anOriginal.isNameSet()) {
      const char* NameOriginal = anOriginal.getName();
      setName(NameOriginal,1);
    }
    
  
  }
  
  //---------------------------------------------------------------------------- 
  void
  Linux_DnsServiceConfigurationInstanceName::reset() {
  	if (isSet.m_nameSpaceP) {
  	  delete(m_nameSpaceP);
  	}
  	
  	if (isSet.Name) {
  	  delete(m_Name);
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
