// =======================================================================
// Linux_DnsMasterZoneInstanceName.cpp
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
#include "Linux_DnsMasterZoneInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //****************************************************************************
  //Linux_DnsMasterZoneInstanceName
  //---------------------------------------------------------------------------- 
  // empty constructor
  //---------------------------------------------------------------------------- 
  Linux_DnsMasterZoneInstanceName::Linux_DnsMasterZoneInstanceName() {
   	init();  	
  }
  
  //---------------------------------------------------------------------------- 
  // copy constructor	
  //---------------------------------------------------------------------------- 
  Linux_DnsMasterZoneInstanceName::Linux_DnsMasterZoneInstanceName(
    const Linux_DnsMasterZoneInstanceName& anInstanceName) {
   	init(anInstanceName);  	
  }
  
  //---------------------------------------------------------------------------- 
  // constructor using CmpiObjectPath
  //---------------------------------------------------------------------------- 
  Linux_DnsMasterZoneInstanceName::Linux_DnsMasterZoneInstanceName(
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
  Linux_DnsMasterZoneInstanceName::~Linux_DnsMasterZoneInstanceName() {
   	reset();  	  
  }
  
  //---------------------------------------------------------------------------- 
  //copy operator
  //---------------------------------------------------------------------------- 
  Linux_DnsMasterZoneInstanceName&
  Linux_DnsMasterZoneInstanceName::operator=(
    const Linux_DnsMasterZoneInstanceName& anInstanceName) {    
    
    init(anInstanceName);
   	return *this;    
  
  }
  
  //---------------------------------------------------------------------------- 
  //returns the related CmpiObjectPath
  //---------------------------------------------------------------------------- 
  CmpiObjectPath 
  Linux_DnsMasterZoneInstanceName::getObjectPath() const {
   	
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
  Linux_DnsMasterZoneInstanceName::fillKeys(CmpiInstance& cmpiInstance) const {
  	
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
  Linux_DnsMasterZoneInstanceName::isNameSpaceSet() const {
  	return isSet.m_nameSpaceP;
  }
  
  //---------------------------------------------------------------------------- 
  const char* 
  Linux_DnsMasterZoneInstanceName::getNamespace() const {
    if ( ! isSet.m_nameSpaceP) {
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace",
   	   "Linux_DnsMasterZone");
   	}
  	return m_nameSpaceP;
  }

  //---------------------------------------------------------------------------- 
  void
  Linux_DnsMasterZoneInstanceName::setNamespace(
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
  Linux_DnsMasterZoneInstanceName::isInstanceIDSet() const {
    return isSet.InstanceID;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneInstanceName::setInstanceID(
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
  Linux_DnsMasterZoneInstanceName::getInstanceID() const {
    
    if ( ! isSet.InstanceID) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "InstanceID",
        "Linux_DnsMasterZone");
   	}


    return m_InstanceID;

  }
       
  //----------------------------------------------------------------------------
  // Name related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMasterZoneInstanceName::isNameSet() const {
    return isSet.Name;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMasterZoneInstanceName::setName(
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
  Linux_DnsMasterZoneInstanceName::getName() const {
    
    if ( ! isSet.Name) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Name",
        "Linux_DnsMasterZone");
   	}


    return m_Name;

  }


  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsMasterZoneInstanceName::init() {
  	
  	m_CIMClassNameP = "Linux_DnsMasterZone";
  	isSet.m_nameSpaceP = 0; 
  	    isSet.InstanceID = 0;
    isSet.Name = 0;

  	
  }
  
  //---------------------------------------------------------------------------- 
  //copies another instance properties in this
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsMasterZoneInstanceName::init(
    const Linux_DnsMasterZoneInstanceName& anOriginal) {
   	
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
  Linux_DnsMasterZoneInstanceName::reset() {
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
  Linux_DnsMasterZoneInstanceNameEnumerationElement::Linux_DnsMasterZoneInstanceNameEnumerationElement() {
  	m_elementP = 0;
  	m_nextP = 0; 
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsMasterZoneInstanceNameEnumerationElement::~Linux_DnsMasterZoneInstanceNameEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsMasterZoneInstanceNameEnumeration::Linux_DnsMasterZoneInstanceNameEnumeration() {
  	 m_firstElementP = 0;
     m_currentElementP = 0;
     m_endElementP = 0;
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsMasterZoneInstanceNameEnumeration::Linux_DnsMasterZoneInstanceNameEnumeration(
    const CmpiArray& aCmpiArray) {
  	
  	m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
    
    int size = aCmpiArray.size();
    for (int x=0; x < size; ++x) {
      addElement(Linux_DnsMasterZoneInstanceName(aCmpiArray[x]));
    }
    
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsMasterZoneInstanceNameEnumeration::Linux_DnsMasterZoneInstanceNameEnumeration(
    const Linux_DnsMasterZoneInstanceNameEnumeration& anInstanceNameEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceNameEnumeration.getSize();
    for (int x=0; x < size; ++x) {
      addElement(anInstanceNameEnumeration.getElement(x));
    }

  }
  	  
  //---------------------------------------------------------------------------- 
  Linux_DnsMasterZoneInstanceNameEnumeration::~Linux_DnsMasterZoneInstanceNameEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }

  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsMasterZoneInstanceNameEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  
  }

  //---------------------------------------------------------------------------- 
  bool 
  Linux_DnsMasterZoneInstanceNameEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //---------------------------------------------------------------------------- 
  int
  Linux_DnsMasterZoneInstanceNameEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsMasterZoneInstanceNameEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsMasterZoneInstanceName&  
   Linux_DnsMasterZoneInstanceNameEnumeration::getElement(int anIndex) const {
   
    Linux_DnsMasterZoneInstanceNameEnumerationElement* followingP = m_firstElementP;
   
    int x=0;
    while (followingP && (x < anIndex) ) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsMasterZoneInstanceName&
  Linux_DnsMasterZoneInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsMasterZoneInstanceNameEnumerationElement* currentP = m_currentElementP;
  	 m_currentElementP = m_currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  
  }
  	  
  //---------------------------------------------------------------------------- 
  void Linux_DnsMasterZoneInstanceNameEnumeration::addElement
   (const Linux_DnsMasterZoneInstanceName& anElementP){
   	
  	if (m_firstElementP==0) {
  	  m_firstElementP = new Linux_DnsMasterZoneInstanceNameEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsMasterZoneInstanceName(anElementP);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsMasterZoneInstanceNameEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP=new Linux_DnsMasterZoneInstanceName(anElementP);
  	}

  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsMasterZoneInstanceNameEnumeration::operator CmpiArray() const {
  	int size = getSize();
   	CmpiArray cmpiArray = CmpiArray(size,CMPI_instance);
   	for (int x=0; x < size; ++x) {
   	  cmpiArray[x]=getElement(x).getObjectPath();
   	}
   	return cmpiArray;
  }
  
}
