// =======================================================================
// Linux_DnsResourceRecordInstanceName.cpp
//     created on Fri, 1 Dec 2006 using ECUTE 2.2
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
#include "Linux_DnsResourceRecordInstanceName.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {
	
  //****************************************************************************
  //Linux_DnsResourceRecordInstanceName
  //---------------------------------------------------------------------------- 
  // empty constructor
  //---------------------------------------------------------------------------- 
  Linux_DnsResourceRecordInstanceName::Linux_DnsResourceRecordInstanceName() {
   	init();  	
  }
  
  //---------------------------------------------------------------------------- 
  // copy constructor	
  //---------------------------------------------------------------------------- 
  Linux_DnsResourceRecordInstanceName::Linux_DnsResourceRecordInstanceName(
    const Linux_DnsResourceRecordInstanceName& anInstanceName) {
   	init(anInstanceName);  	
  }
  
  //---------------------------------------------------------------------------- 
  // constructor using CmpiObjectPath
  //---------------------------------------------------------------------------- 
  Linux_DnsResourceRecordInstanceName::Linux_DnsResourceRecordInstanceName(
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
    
    CmpiString Type = path.getKey("Type");
    setType(Type.charPtr());
    
    CmpiString Value = path.getKey("Value");
    setValue(Value.charPtr());
    
    CmpiString ZoneName = path.getKey("ZoneName");
    setZoneName(ZoneName.charPtr());

    
  }
  
  //---------------------------------------------------------------------------- 
  // destructor
  //---------------------------------------------------------------------------- 
  Linux_DnsResourceRecordInstanceName::~Linux_DnsResourceRecordInstanceName() {
   	reset();  	  
  }
  
  //---------------------------------------------------------------------------- 
  //copy operator
  //---------------------------------------------------------------------------- 
  Linux_DnsResourceRecordInstanceName&
  Linux_DnsResourceRecordInstanceName::operator=(
    const Linux_DnsResourceRecordInstanceName& anInstanceName) {    
    
    init(anInstanceName);
   	return *this;    
  
  }
  
  //---------------------------------------------------------------------------- 
  //returns the related CmpiObjectPath
  //---------------------------------------------------------------------------- 
  CmpiObjectPath 
  Linux_DnsResourceRecordInstanceName::getObjectPath() const {
   	
   	CmpiObjectPath objectPath(m_nameSpaceP, m_CIMClassNameP);
   	  	objectPath.setKey(
  	  "InstanceID",
  	  CmpiData(m_InstanceID));
  	objectPath.setKey(
  	  "Name",
  	  CmpiData(m_Name));
  	objectPath.setKey(
  	  "Type",
  	  CmpiData(m_Type));
  	objectPath.setKey(
  	  "Value",
  	  CmpiData(m_Value));
  	objectPath.setKey(
  	  "ZoneName",
  	  CmpiData(m_ZoneName));

  	
  	return objectPath;
  	
  }
  
  //---------------------------------------------------------------------------- 
  // adds the related CmpiObjectPath to an existing cmpiInstance
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsResourceRecordInstanceName::fillKeys(CmpiInstance& cmpiInstance) const {
  	
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

  	if (isSet.Type) {
  	  
  	  cmpiInstance.setProperty(
  	    "Type",
  	    CmpiData(m_Type));
  	}

  	if (isSet.Value) {
  	  
  	  cmpiInstance.setProperty(
  	    "Value",
  	    CmpiData(m_Value));
  	}

  	if (isSet.ZoneName) {
  	  
  	  cmpiInstance.setProperty(
  	    "ZoneName",
  	    CmpiData(m_ZoneName));
  	}

  }
  
  
  //---------------------------------------------------------------------------- 
  // NameSpace related methods
  //---------------------------------------------------------------------------- 
  unsigned int 
  Linux_DnsResourceRecordInstanceName::isNameSpaceSet() const {
  	return isSet.m_nameSpaceP;
  }
  
  //---------------------------------------------------------------------------- 
  const char* 
  Linux_DnsResourceRecordInstanceName::getNamespace() const {
    if ( ! isSet.m_nameSpaceP) {
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "NameSpace",
   	   "Linux_DnsResourceRecord");
   	}
  	return m_nameSpaceP;
  }

  //---------------------------------------------------------------------------- 
  void
  Linux_DnsResourceRecordInstanceName::setNamespace(
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
  Linux_DnsResourceRecordInstanceName::isInstanceIDSet() const {
    return isSet.InstanceID;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsResourceRecordInstanceName::setInstanceID(
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
  Linux_DnsResourceRecordInstanceName::getInstanceID() const {
    
    if ( ! isSet.InstanceID) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "InstanceID",
        "Linux_DnsResourceRecord");
   	}


    return m_InstanceID;

  }
       
  //----------------------------------------------------------------------------
  // Name related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsResourceRecordInstanceName::isNameSet() const {
    return isSet.Name;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsResourceRecordInstanceName::setName(
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
  Linux_DnsResourceRecordInstanceName::getName() const {
    
    if ( ! isSet.Name) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Name",
        "Linux_DnsResourceRecord");
   	}


    return m_Name;

  }
       
  //----------------------------------------------------------------------------
  // Type related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsResourceRecordInstanceName::isTypeSet() const {
    return isSet.Type;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsResourceRecordInstanceName::setType(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.Type) {
      delete [] m_Type;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_Type = valueP;
    } else {
      m_Type = aValueP;
    }
    
    isSet.Type = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsResourceRecordInstanceName::getType() const {
    
    if ( ! isSet.Type) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Type",
        "Linux_DnsResourceRecord");
   	}


    return m_Type;

  }
       
  //----------------------------------------------------------------------------
  // Value related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsResourceRecordInstanceName::isValueSet() const {
    return isSet.Value;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsResourceRecordInstanceName::setValue(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.Value) {
      delete [] m_Value;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_Value = valueP;
    } else {
      m_Value = aValueP;
    }
    
    isSet.Value = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsResourceRecordInstanceName::getValue() const {
    
    if ( ! isSet.Value) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Value",
        "Linux_DnsResourceRecord");
   	}


    return m_Value;

  }
       
  //----------------------------------------------------------------------------
  // ZoneName related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsResourceRecordInstanceName::isZoneNameSet() const {
    return isSet.ZoneName;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsResourceRecordInstanceName::setZoneName(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.ZoneName) {
      delete [] m_ZoneName;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_ZoneName = valueP;
    } else {
      m_ZoneName = aValueP;
    }
    
    isSet.ZoneName = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsResourceRecordInstanceName::getZoneName() const {
    
    if ( ! isSet.ZoneName) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ZoneName",
        "Linux_DnsResourceRecord");
   	}


    return m_ZoneName;

  }


  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsResourceRecordInstanceName::init() {
  	
  	m_CIMClassNameP = "Linux_DnsResourceRecord";
  	isSet.m_nameSpaceP = 0; 
  	    isSet.InstanceID = 0;
    isSet.Name = 0;
    isSet.Type = 0;
    isSet.Value = 0;
    isSet.ZoneName = 0;

  	
  }
  
  //---------------------------------------------------------------------------- 
  //copies another instance properties in this
  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsResourceRecordInstanceName::init(
    const Linux_DnsResourceRecordInstanceName& anOriginal) {
   	
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
   	
    if (anOriginal.isTypeSet()) {
      const char* TypeOriginal = anOriginal.getType();
      setType(TypeOriginal,1);
    }
   	
    if (anOriginal.isValueSet()) {
      const char* ValueOriginal = anOriginal.getValue();
      setValue(ValueOriginal,1);
    }
   	
    if (anOriginal.isZoneNameSet()) {
      const char* ZoneNameOriginal = anOriginal.getZoneName();
      setZoneName(ZoneNameOriginal,1);
    }
    
  
  }
  
  //---------------------------------------------------------------------------- 
  void
  Linux_DnsResourceRecordInstanceName::reset() {
  	if (isSet.m_nameSpaceP) {
  	  delete(m_nameSpaceP);
  	}
  	
  	if (isSet.InstanceID) {
  	  delete(m_InstanceID);
  	}

  	if (isSet.Name) {
  	  delete(m_Name);
  	}

  	if (isSet.Type) {
  	  delete(m_Type);
  	}

  	if (isSet.Value) {
  	  delete(m_Value);
  	}

  	if (isSet.ZoneName) {
  	  delete(m_ZoneName);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsResourceRecordInstanceNameEnumerationElement::Linux_DnsResourceRecordInstanceNameEnumerationElement() {
  	m_elementP = 0;
  	m_nextP = 0; 
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsResourceRecordInstanceNameEnumerationElement::~Linux_DnsResourceRecordInstanceNameEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsResourceRecordInstanceNameEnumeration::Linux_DnsResourceRecordInstanceNameEnumeration() {
  	 m_firstElementP = 0;
     m_currentElementP = 0;
     m_endElementP = 0;
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsResourceRecordInstanceNameEnumeration::Linux_DnsResourceRecordInstanceNameEnumeration(
    const CmpiArray& aCmpiArray) {
  	
  	m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
    
    int size = aCmpiArray.size();
    for (int x=0; x < size; ++x) {
      addElement(Linux_DnsResourceRecordInstanceName(aCmpiArray[x]));
    }
    
  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsResourceRecordInstanceNameEnumeration::Linux_DnsResourceRecordInstanceNameEnumeration(
    const Linux_DnsResourceRecordInstanceNameEnumeration& anInstanceNameEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceNameEnumeration.getSize();
    for (int x=0; x < size; ++x) {
      addElement(anInstanceNameEnumeration.getElement(x));
    }

  }
  	  
  //---------------------------------------------------------------------------- 
  Linux_DnsResourceRecordInstanceNameEnumeration::~Linux_DnsResourceRecordInstanceNameEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }

  //---------------------------------------------------------------------------- 
  void 
  Linux_DnsResourceRecordInstanceNameEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  
  }

  //---------------------------------------------------------------------------- 
  bool 
  Linux_DnsResourceRecordInstanceNameEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //---------------------------------------------------------------------------- 
  int
  Linux_DnsResourceRecordInstanceNameEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsResourceRecordInstanceNameEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsResourceRecordInstanceName&  
   Linux_DnsResourceRecordInstanceNameEnumeration::getElement(int anIndex) const {
   
    Linux_DnsResourceRecordInstanceNameEnumerationElement* followingP = m_firstElementP;
   
    int x=0;
    while (followingP && (x < anIndex) ) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);
  
  }
  
  //---------------------------------------------------------------------------- 
  const Linux_DnsResourceRecordInstanceName&
  Linux_DnsResourceRecordInstanceNameEnumeration::getNext() {
   	
  	 Linux_DnsResourceRecordInstanceNameEnumerationElement* currentP = m_currentElementP;
  	 m_currentElementP = m_currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  
  }
  	  
  //---------------------------------------------------------------------------- 
  void Linux_DnsResourceRecordInstanceNameEnumeration::addElement
   (const Linux_DnsResourceRecordInstanceName& anElementP){
   	
  	if (m_firstElementP==0) {
  	  m_firstElementP = new Linux_DnsResourceRecordInstanceNameEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsResourceRecordInstanceName(anElementP);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsResourceRecordInstanceNameEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP=new Linux_DnsResourceRecordInstanceName(anElementP);
  	}

  }
  
  //---------------------------------------------------------------------------- 
  Linux_DnsResourceRecordInstanceNameEnumeration::operator CmpiArray() const {
  	int size = getSize();
   	CmpiArray cmpiArray = CmpiArray(size,CMPI_instance);
   	for (int x=0; x < size; ++x) {
   	  cmpiArray[x]=getElement(x).getObjectPath();
   	}
   	return cmpiArray;
  }
  
}
