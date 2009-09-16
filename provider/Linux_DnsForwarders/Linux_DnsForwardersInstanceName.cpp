// =======================================================================
// Linux_DnsForwardersInstanceName.cpp
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
#include "Linux_DnsForwardersInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //****************************************************************************
  //Linux_DnsForwardersInstanceName
  //---------------------------------------------------------------------------- 
  // empty constructor
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersInstanceName::Linux_DnsForwardersInstanceName() {
   	init();  	
  }
  
  //---------------------------------------------------------------------------- 
  // copy constructor	
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersInstanceName::Linux_DnsForwardersInstanceName(
    const Linux_DnsForwardersInstanceName& anInstanceName) {
   	init(anInstanceName);  	
  }
  
  //---------------------------------------------------------------------------- 
  // constructor using CmpiObjectPath
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersInstanceName::Linux_DnsForwardersInstanceName(
    const CmpiObjectPath& path) {
    
    init();
    
    m_CIMClassNameP = path.getClassName().charPtr();
    
    CmpiString namespaceP;
    namespaceP = path.getNameSpace();
    setNamespace(namespaceP.charPtr(),1);
        
    CmpiString InstanceID = path.getKey("InstanceID");
    setInstanceID(InstanceID.charPtr());
    
    CmpiString Name = path.getKey("Name");
    setName(Name.charPtr());

    
  }
  
  //---------------------------------------------------------------------------- 
  // destructor
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersInstanceName::~Linux_DnsForwardersInstanceName() {
   	reset();  	  
  }
  
  //---------------------------------------------------------------------------- 
  //copy operator
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersInstanceName&
  Linux_DnsForwardersInstanceName::operator=(
    const Linux_DnsForwardersInstanceName& anInstanceName) {    
    
    init(anInstanceName);
   	return *this;    
  
  }
  
  //---------------------------------------------------------------------------- 
  //returns the related CmpiObjectPath
  //---------------------------------------------------------------------------- 
  CmpiObjectPath 
  Linux_DnsForwardersInstanceName::getObjectPath() const {
   	
   	CmpiObjectPath objectPath(m_nameSpaceP, m_CIMClassNameP);
   	  	objectPath.setKey(
  	  "InstanceID",
  	  CmpiData(m_InstanceID));
  	objectPath.setKey(
  	  "Name",
  	  CmpiData(m_Name));

  	
  	return objectPath;
  	
  }
  
  //---------------------------------------------------------------------------- 
  // adds the related CmpiObjectPath to an existing cmpiInstance
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsForwardersInstanceName::fillKeys(CmpiInstance& cmpiInstance) const {
  	
  	if (isSet.InstanceID) {
  	  
  	  cmpiInstance.setProperty(
  	    "InstanceID",
  	    CmpiData(m_InstanceID));
  	}

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
  Linux_DnsForwardersInstanceName::isNameSpaceSet() const {
  	return isSet.m_nameSpaceP;
  }
  
  //---------------------------------------------------------------------------- 
  const char* 
  Linux_DnsForwardersInstanceName::getNamespace() const {
    if ( ! isSet.m_nameSpaceP) {
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace",
   	   "Linux_DnsForwarders");
   	}
  	return m_nameSpaceP;
  }

  //---------------------------------------------------------------------------- 
  void
  Linux_DnsForwardersInstanceName::setNamespace(
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
  // InstanceID related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardersInstanceName::isInstanceIDSet() const {
    return isSet.InstanceID;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersInstanceName::setInstanceID(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.InstanceID) {
      delete [] m_InstanceID;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_InstanceID = valueP;
    } else {
      m_InstanceID = aValueP;
    }
    
    isSet.InstanceID = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsForwardersInstanceName::getInstanceID() const {
    
    if ( ! isSet.InstanceID) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "InstanceID",
        "Linux_DnsForwarders");
   	}


    return m_InstanceID;

  }
       
  //----------------------------------------------------------------------------
  // Name related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardersInstanceName::isNameSet() const {
    return isSet.Name;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersInstanceName::setName(
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
  Linux_DnsForwardersInstanceName::getName() const {
    
    if ( ! isSet.Name) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Name",
        "Linux_DnsForwarders");
   	}


    return m_Name;

  }


  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsForwardersInstanceName::init() {
  	
  	m_CIMClassNameP = "Linux_DnsForwarders";
  	isSet.m_nameSpaceP = 0; 
  	    isSet.InstanceID = 0;
    isSet.Name = 0;

  	
  }
  
  //---------------------------------------------------------------------------- 
  //copies another instance properties in this
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsForwardersInstanceName::init(
    const Linux_DnsForwardersInstanceName& anOriginal) {
   	
   	init();
   	   	
    m_CIMClassNameP = anOriginal.m_CIMClassNameP;
    if (anOriginal.isNameSpaceSet()){
      setNamespace(anOriginal.getNamespace(),1);
    }
       	
    if (anOriginal.isInstanceIDSet()) {
      const char* InstanceIDOriginal = anOriginal.getInstanceID();
      setInstanceID(InstanceIDOriginal,1);
    }
   	
    if (anOriginal.isNameSet()) {
      const char* NameOriginal = anOriginal.getName();
      setName(NameOriginal,1);
    }
    
  
  }
  
  //---------------------------------------------------------------------------- 
  void
  Linux_DnsForwardersInstanceName::reset() {
  	if (isSet.m_nameSpaceP) {
  	  delete(m_nameSpaceP);
  	}
  	
  	if (isSet.InstanceID) {
  	  delete(m_InstanceID);
  	}

  	if (isSet.Name) {
  	  delete(m_Name);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersInstanceNameEnumerationElement::Linux_DnsForwardersInstanceNameEnumerationElement() {
  	m_elementP = 0;
  	m_nextP = 0; 
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersInstanceNameEnumerationElement::~Linux_DnsForwardersInstanceNameEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersInstanceNameEnumeration::Linux_DnsForwardersInstanceNameEnumeration() {
  	 m_firstElementP = 0;
     m_currentElementP = 0;
     m_endElementP = 0;
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersInstanceNameEnumeration::Linux_DnsForwardersInstanceNameEnumeration(
    const CmpiArray& aCmpiArray) {
  	
  	m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
    
    int size = aCmpiArray.size();
    for (int x=0; x < size; ++x) {
      addElement(Linux_DnsForwardersInstanceName(aCmpiArray[x]));
    }
    
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersInstanceNameEnumeration::Linux_DnsForwardersInstanceNameEnumeration(
    const Linux_DnsForwardersInstanceNameEnumeration& anInstanceNameEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceNameEnumeration.getSize();
    for (int x=0; x < size; ++x) {
      addElement(anInstanceNameEnumeration.getElement(x));
    }

  }
  	  
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersInstanceNameEnumeration::~Linux_DnsForwardersInstanceNameEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }

  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsForwardersInstanceNameEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  
  }

  //---------------------------------------------------------------------------- 
  bool 
  Linux_DnsForwardersInstanceNameEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //---------------------------------------------------------------------------- 
  int
  Linux_DnsForwardersInstanceNameEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsForwardersInstanceNameEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsForwardersInstanceName&  
   Linux_DnsForwardersInstanceNameEnumeration::getElement(int anIndex) const {
   
    Linux_DnsForwardersInstanceNameEnumerationElement* followingP = m_firstElementP;
   
    int x=0;
    while (followingP && (x < anIndex) ) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsForwardersInstanceName&
  Linux_DnsForwardersInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsForwardersInstanceNameEnumerationElement* currentP = m_currentElementP;
  	 m_currentElementP = m_currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  
  }
  	  
  //---------------------------------------------------------------------------- 
  void Linux_DnsForwardersInstanceNameEnumeration::addElement
   (const Linux_DnsForwardersInstanceName& anElementP){
   	
  	if (m_firstElementP==0) {
  	  m_firstElementP = new Linux_DnsForwardersInstanceNameEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsForwardersInstanceName(anElementP);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsForwardersInstanceNameEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP=new Linux_DnsForwardersInstanceName(anElementP);
  	}

  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsForwardersInstanceNameEnumeration::operator CmpiArray() const {
  	int size = getSize();
   	CmpiArray cmpiArray = CmpiArray(size,CMPI_instance);
   	for (int x=0; x < size; ++x) {
   	  cmpiArray[x]=getElement(x).getObjectPath();
   	}
   	return cmpiArray;
  }
  
}
