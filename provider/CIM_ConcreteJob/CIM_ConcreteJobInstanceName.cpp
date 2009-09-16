// =======================================================================
// CIM_ConcreteJobInstanceName.cpp
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
#include "CIM_ConcreteJobInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //****************************************************************************
  //CIM_ConcreteJobInstanceName
  //---------------------------------------------------------------------------- 
  // empty constructor
  //---------------------------------------------------------------------------- 
  CIM_ConcreteJobInstanceName::CIM_ConcreteJobInstanceName() {
   	init();  	
  }
  
  //---------------------------------------------------------------------------- 
  // copy constructor	
  //---------------------------------------------------------------------------- 
  CIM_ConcreteJobInstanceName::CIM_ConcreteJobInstanceName(
    const CIM_ConcreteJobInstanceName& anInstanceName) {
   	init(anInstanceName);  	
  }
  
  //---------------------------------------------------------------------------- 
  // constructor using CmpiObjectPath
  //---------------------------------------------------------------------------- 
  CIM_ConcreteJobInstanceName::CIM_ConcreteJobInstanceName(
    const CmpiObjectPath& path) {
    
    init();
    
    m_CIMClassNameP = path.getClassName().charPtr();
    
    CmpiString namespaceP;
    namespaceP = path.getNameSpace();
    setNamespace(namespaceP.charPtr(),1);
        
    CmpiString InstanceID = path.getKey("InstanceID");
    setInstanceID(InstanceID.charPtr());

    
  }
  
  //---------------------------------------------------------------------------- 
  // destructor
  //---------------------------------------------------------------------------- 
  CIM_ConcreteJobInstanceName::~CIM_ConcreteJobInstanceName() {
   	reset();  	  
  }
  
  //---------------------------------------------------------------------------- 
  //copy operator
  //---------------------------------------------------------------------------- 
  CIM_ConcreteJobInstanceName&
  CIM_ConcreteJobInstanceName::operator=(
    const CIM_ConcreteJobInstanceName& anInstanceName) {    
    
    init(anInstanceName);
   	return *this;    
  
  }
  
  //---------------------------------------------------------------------------- 
  //returns the related CmpiObjectPath
  //---------------------------------------------------------------------------- 
  CmpiObjectPath 
  CIM_ConcreteJobInstanceName::getObjectPath() const {
   	
   	CmpiObjectPath objectPath(m_nameSpaceP, m_CIMClassNameP);
   	  	objectPath.setKey(
  	  "InstanceID",
  	  CmpiData(m_InstanceID));

  	
  	return objectPath;
  	
  }
  
  //---------------------------------------------------------------------------- 
  // adds the related CmpiObjectPath to an existing cmpiInstance
  //---------------------------------------------------------------------------- 
  void 
  CIM_ConcreteJobInstanceName::fillKeys(CmpiInstance& cmpiInstance) const {
  	
  	if (isSet.InstanceID) {
  	  
  	  cmpiInstance.setProperty(
  	    "InstanceID",
  	    CmpiData(m_InstanceID));
  	}

  }
  
  
  //---------------------------------------------------------------------------- 
  // NameSpace related methods
  //---------------------------------------------------------------------------- 
  unsigned int 
  CIM_ConcreteJobInstanceName::isNameSpaceSet() const {
  	return isSet.m_nameSpaceP;
  }
  
  //---------------------------------------------------------------------------- 
  const char* 
  CIM_ConcreteJobInstanceName::getNamespace() const {
    if ( ! isSet.m_nameSpaceP) {
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace",
   	   "CIM_ConcreteJob");
   	}
  	return m_nameSpaceP;
  }

  //---------------------------------------------------------------------------- 
  void
  CIM_ConcreteJobInstanceName::setNamespace(
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
  CIM_ConcreteJobInstanceName::isInstanceIDSet() const {
    return isSet.InstanceID;
  }

  //----------------------------------------------------------------------------
  void
  CIM_ConcreteJobInstanceName::setInstanceID(
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
  CIM_ConcreteJobInstanceName::getInstanceID() const {
    
    if ( ! isSet.InstanceID) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "InstanceID",
        "CIM_ConcreteJob");
   	}


    return m_InstanceID;

  }


  //---------------------------------------------------------------------------- 
  void 
  CIM_ConcreteJobInstanceName::init() {
  	
  	m_CIMClassNameP = "CIM_ConcreteJob";
  	isSet.m_nameSpaceP = 0; 
  	    isSet.InstanceID = 0;

  	
  }
  
  //---------------------------------------------------------------------------- 
  //copies another instance properties in this
  //---------------------------------------------------------------------------- 
  void 
  CIM_ConcreteJobInstanceName::init(
    const CIM_ConcreteJobInstanceName& anOriginal) {
   	
   	init();
   	   	
    m_CIMClassNameP = anOriginal.m_CIMClassNameP;
    if (anOriginal.isNameSpaceSet()){
      setNamespace(anOriginal.getNamespace(),1);
    }
       	
    if (anOriginal.isInstanceIDSet()) {
      const char* InstanceIDOriginal = anOriginal.getInstanceID();
      setInstanceID(InstanceIDOriginal,1);
    }
    
  
  }
  
  //---------------------------------------------------------------------------- 
  void
  CIM_ConcreteJobInstanceName::reset() {
  	if (isSet.m_nameSpaceP) {
  	  delete(m_nameSpaceP);
  	}
  	
  	if (isSet.InstanceID) {
  	  delete(m_InstanceID);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  CIM_ConcreteJobInstanceNameEnumerationElement::CIM_ConcreteJobInstanceNameEnumerationElement() {
  	m_elementP = 0;
  	m_nextP = 0; 
  }
  
  //---------------------------------------------------------------------------- 
  CIM_ConcreteJobInstanceNameEnumerationElement::~CIM_ConcreteJobInstanceNameEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  CIM_ConcreteJobInstanceNameEnumeration::CIM_ConcreteJobInstanceNameEnumeration() {
  	 m_firstElementP = 0;
     m_currentElementP = 0;
     m_endElementP = 0;
  }
  
  //---------------------------------------------------------------------------- 
  CIM_ConcreteJobInstanceNameEnumeration::CIM_ConcreteJobInstanceNameEnumeration(
    const CmpiArray& aCmpiArray) {
  	
  	m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
    
    int size = aCmpiArray.size();
    for (int x=0; x < size; ++x) {
      addElement(CIM_ConcreteJobInstanceName(aCmpiArray[x]));
    }
    
  }
  
  //---------------------------------------------------------------------------- 
  CIM_ConcreteJobInstanceNameEnumeration::CIM_ConcreteJobInstanceNameEnumeration(
    const CIM_ConcreteJobInstanceNameEnumeration& anInstanceNameEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceNameEnumeration.getSize();
    for (int x=0; x < size; ++x) {
      addElement(anInstanceNameEnumeration.getElement(x));
    }

  }
  	  
  //---------------------------------------------------------------------------- 
  CIM_ConcreteJobInstanceNameEnumeration::~CIM_ConcreteJobInstanceNameEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }

  //---------------------------------------------------------------------------- 
  void 
  CIM_ConcreteJobInstanceNameEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  
  }

  //---------------------------------------------------------------------------- 
  bool 
  CIM_ConcreteJobInstanceNameEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //---------------------------------------------------------------------------- 
  int
  CIM_ConcreteJobInstanceNameEnumeration::getSize() const {
  	
    int size = 0;
    CIM_ConcreteJobInstanceNameEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
  
  }
  
  //---------------------------------------------------------------------------- 
  const CIM_ConcreteJobInstanceName&  
   CIM_ConcreteJobInstanceNameEnumeration::getElement(int anIndex) const {
   
    CIM_ConcreteJobInstanceNameEnumerationElement* followingP = m_firstElementP;
   
    int x=0;
    while (followingP && (x < anIndex) ) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);
  
  }
  
  //---------------------------------------------------------------------------- 
  const CIM_ConcreteJobInstanceName&
  CIM_ConcreteJobInstanceNameEnumeration::getNext() {
   	
  	 CIM_ConcreteJobInstanceNameEnumerationElement* currentP = m_currentElementP;
  	 m_currentElementP = m_currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  
  }
  	  
  //---------------------------------------------------------------------------- 
  void CIM_ConcreteJobInstanceNameEnumeration::addElement
   (const CIM_ConcreteJobInstanceName& anElementP){
   	
  	if (m_firstElementP==0) {
  	  m_firstElementP = new CIM_ConcreteJobInstanceNameEnumerationElement();
  	  m_firstElementP->m_elementP = new CIM_ConcreteJobInstanceName(anElementP);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new CIM_ConcreteJobInstanceNameEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP=new CIM_ConcreteJobInstanceName(anElementP);
  	}

  }
  
  //---------------------------------------------------------------------------- 
  CIM_ConcreteJobInstanceNameEnumeration::operator CmpiArray() const {
  	int size = getSize();
   	CmpiArray cmpiArray = CmpiArray(size,CMPI_instance);
   	for (int x=0; x < size; ++x) {
   	  cmpiArray[x]=getElement(x).getObjectPath();
   	}
   	return cmpiArray;
  }
  
}
