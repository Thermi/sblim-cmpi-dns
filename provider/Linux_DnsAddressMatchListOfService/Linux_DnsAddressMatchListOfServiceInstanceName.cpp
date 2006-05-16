// =======================================================================
// Linux_DnsAddressMatchListOfServiceInstanceName.cpp
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
#include "Linux_DnsAddressMatchListOfServiceInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //****************************************************************************
  //Linux_DnsAddressMatchListOfServiceInstanceName
  //---------------------------------------------------------------------------- 
  // empty constructor
  //---------------------------------------------------------------------------- 
  Linux_DnsAddressMatchListOfServiceInstanceName::Linux_DnsAddressMatchListOfServiceInstanceName() {
   	init();  	
  }
  
  //---------------------------------------------------------------------------- 
  // copy constructor	
  //---------------------------------------------------------------------------- 
  Linux_DnsAddressMatchListOfServiceInstanceName::Linux_DnsAddressMatchListOfServiceInstanceName(
    const Linux_DnsAddressMatchListOfServiceInstanceName& anInstanceName) {
   	init(anInstanceName);  	
  }
  
  //---------------------------------------------------------------------------- 
  // constructor using CmpiObjectPath
  //---------------------------------------------------------------------------- 
  Linux_DnsAddressMatchListOfServiceInstanceName::Linux_DnsAddressMatchListOfServiceInstanceName(
    const CmpiObjectPath& path) {
    
    init();
    
    m_CIMClassNameP = path.getClassName().charPtr();
    
    CmpiString namespaceP;
    namespaceP = path.getNameSpace();
    setNamespace(namespaceP.charPtr(),1);
        
    CmpiObjectPath Dependent = path.getKey("Dependent");
    setDependent(Linux_DnsAddressMatchListInstanceName(Dependent));
    
    CmpiObjectPath Antecedent = path.getKey("Antecedent");
    setAntecedent(Linux_DnsServiceInstanceName(Antecedent));

    
  }
  
  //---------------------------------------------------------------------------- 
  // destructor
  //---------------------------------------------------------------------------- 
  Linux_DnsAddressMatchListOfServiceInstanceName::~Linux_DnsAddressMatchListOfServiceInstanceName() {
   	reset();  	  
  }
  
  //---------------------------------------------------------------------------- 
  //copy operator
  //---------------------------------------------------------------------------- 
  Linux_DnsAddressMatchListOfServiceInstanceName&
  Linux_DnsAddressMatchListOfServiceInstanceName::operator=(
    const Linux_DnsAddressMatchListOfServiceInstanceName& anInstanceName) {    
    
    init(anInstanceName);
   	return *this;    
  
  }
  
  //---------------------------------------------------------------------------- 
  //returns the related CmpiObjectPath
  //---------------------------------------------------------------------------- 
  CmpiObjectPath 
  Linux_DnsAddressMatchListOfServiceInstanceName::getObjectPath() const {
   	
   	CmpiObjectPath objectPath(m_nameSpaceP, m_CIMClassNameP);
   	  	objectPath.setKey(
  	  "Dependent",
  	  CmpiData(m_Dependent.getObjectPath()));
  	objectPath.setKey(
  	  "Antecedent",
  	  CmpiData(m_Antecedent.getObjectPath()));

  	
  	return objectPath;
  	
  }
  
  //---------------------------------------------------------------------------- 
  // adds the related CmpiObjectPath to an existing cmpiInstance
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsAddressMatchListOfServiceInstanceName::fillKeys(CmpiInstance& cmpiInstance) const {
  	
  	if (isSet.Dependent) {
  	  
  	  cmpiInstance.setProperty(
  	    "Dependent",
  	    CmpiData(m_Dependent.getObjectPath()));
  	}

  	if (isSet.Antecedent) {
  	  
  	  cmpiInstance.setProperty(
  	    "Antecedent",
  	    CmpiData(m_Antecedent.getObjectPath()));
  	}

  }
  
  
  //---------------------------------------------------------------------------- 
  // NameSpace related methods
  //---------------------------------------------------------------------------- 
  unsigned int 
  Linux_DnsAddressMatchListOfServiceInstanceName::isNameSpaceSet() const {
  	return isSet.m_nameSpaceP;
  }
  
  //---------------------------------------------------------------------------- 
  const char* 
  Linux_DnsAddressMatchListOfServiceInstanceName::getNamespace() const {
    if ( ! isSet.m_nameSpaceP) {
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace",
   	   "Linux_DnsAddressMatchListOfService");
   	}
  	return m_nameSpaceP;
  }

  //---------------------------------------------------------------------------- 
  void
  Linux_DnsAddressMatchListOfServiceInstanceName::setNamespace(
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
  // Dependent related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsAddressMatchListOfServiceInstanceName::isDependentSet() const {
    return isSet.Dependent;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsAddressMatchListOfServiceInstanceName::setDependent(
    const Linux_DnsAddressMatchListInstanceName& aValue) {
  
    m_Dependent = aValue;
    isSet.Dependent = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsAddressMatchListInstanceName&
  Linux_DnsAddressMatchListOfServiceInstanceName::getDependent() const {
    
    if ( ! isSet.Dependent) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Dependent",
        "Linux_DnsAddressMatchListOfService");
   	}


    return m_Dependent;

  }
       
  //----------------------------------------------------------------------------
  // Antecedent related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsAddressMatchListOfServiceInstanceName::isAntecedentSet() const {
    return isSet.Antecedent;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsAddressMatchListOfServiceInstanceName::setAntecedent(
    const Linux_DnsServiceInstanceName& aValue) {
  
    m_Antecedent = aValue;
    isSet.Antecedent = 1;
  
  }       

  //----------------------------------------------------------------------------
  const Linux_DnsServiceInstanceName&
  Linux_DnsAddressMatchListOfServiceInstanceName::getAntecedent() const {
    
    if ( ! isSet.Antecedent) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Antecedent",
        "Linux_DnsAddressMatchListOfService");
   	}


    return m_Antecedent;

  }


  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsAddressMatchListOfServiceInstanceName::init() {
  	
  	m_CIMClassNameP = "Linux_DnsAddressMatchListOfService";
  	isSet.m_nameSpaceP = 0; 
  	    isSet.Dependent = 0;
    isSet.Antecedent = 0;

  	
  }
  
  //---------------------------------------------------------------------------- 
  //copies another instance properties in this
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsAddressMatchListOfServiceInstanceName::init(
    const Linux_DnsAddressMatchListOfServiceInstanceName& anOriginal) {
   	
   	init();
   	   	
    m_CIMClassNameP = anOriginal.m_CIMClassNameP;
    if (anOriginal.isNameSpaceSet()){
      setNamespace(anOriginal.getNamespace(),1);
    }
       	
    if (anOriginal.isDependentSet()) {
      const Linux_DnsAddressMatchListInstanceName& DependentOriginal = anOriginal.getDependent();
      setDependent(DependentOriginal);
    }
   	
    if (anOriginal.isAntecedentSet()) {
      const Linux_DnsServiceInstanceName& AntecedentOriginal = anOriginal.getAntecedent();
      setAntecedent(AntecedentOriginal);
    }
    
  
  }
  
  //---------------------------------------------------------------------------- 
  void
  Linux_DnsAddressMatchListOfServiceInstanceName::reset() {
  	if (isSet.m_nameSpaceP) {
  	  delete(m_nameSpaceP);
  	}
  	  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement::Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement() {
  	m_elementP = 0;
  	m_nextP = 0; 
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement::~Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration() {
  	 m_firstElementP = 0;
     m_currentElementP = 0;
     m_endElementP = 0;
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration(
    const CmpiArray& aCmpiArray) {
  	
  	m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
    
    int size = aCmpiArray.size();
    for (int x=0; x < size; ++x) {
      addElement(Linux_DnsAddressMatchListOfServiceInstanceName(aCmpiArray[x]));
    }
    
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration(
    const Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration& anInstanceNameEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceNameEnumeration.getSize();
    for (int x=0; x < size; ++x) {
      addElement(anInstanceNameEnumeration.getElement(x));
    }

  }
  	  
  //---------------------------------------------------------------------------- 
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::~Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }

  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  
  }

  //---------------------------------------------------------------------------- 
  bool 
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //---------------------------------------------------------------------------- 
  int
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsAddressMatchListOfServiceInstanceName&  
   Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::getElement(int anIndex) const {
   
    Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement* followingP = m_firstElementP;
   
    int x=0;
    while (followingP && (x < anIndex) ) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsAddressMatchListOfServiceInstanceName&
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement* currentP = m_currentElementP;
  	 m_currentElementP = m_currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  
  }
  	  
  //---------------------------------------------------------------------------- 
  void Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::addElement
   (const Linux_DnsAddressMatchListOfServiceInstanceName& anElementP){
   	
  	if (m_firstElementP==0) {
  	  m_firstElementP = new Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsAddressMatchListOfServiceInstanceName(anElementP);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsAddressMatchListOfServiceInstanceNameEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP=new Linux_DnsAddressMatchListOfServiceInstanceName(anElementP);
  	}

  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsAddressMatchListOfServiceInstanceNameEnumeration::operator CmpiArray() const {
  	int size = getSize();
   	CmpiArray cmpiArray = CmpiArray(size,CMPI_instance);
   	for (int x=0; x < size; ++x) {
   	  cmpiArray[x]=getElement(x).getObjectPath();
   	}
   	return cmpiArray;
  }
  
}
