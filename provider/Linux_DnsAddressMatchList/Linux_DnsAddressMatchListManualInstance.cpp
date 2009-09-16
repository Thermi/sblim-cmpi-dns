// =======================================================================
// Linux_DnsAddressMatchListManualInstance.cpp
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
#include "Linux_DnsAddressMatchListManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsAddressMatchListManualInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsAddressMatchListManualInstance::Linux_DnsAddressMatchListManualInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstance::Linux_DnsAddressMatchListManualInstance(
    const Linux_DnsAddressMatchListManualInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstance::Linux_DnsAddressMatchListManualInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsAddressMatchListInstanceName(cop));

    cmpiData = aCmpiInstance.getProperty("AddressMatchListElementType");
    if ( ! cmpiData.isNullValue()){
      CmpiArray AddressMatchListElementType = cmpiData;
    unsigned int AddressMatchListElementTypeSize;
    const CMPIUint8* AddressMatchListElementTypeArray;
    ArrayConverter::makeArray(
      AddressMatchListElementType, 
      (CMPIUint8**)&AddressMatchListElementTypeArray, 
      AddressMatchListElementTypeSize);
      setAddressMatchListElementType(AddressMatchListElementTypeArray, AddressMatchListElementTypeSize, 0);
    }

    cmpiData = aCmpiInstance.getProperty("AddressMatchListElement");
    if ( ! cmpiData.isNullValue()){
      CmpiArray AddressMatchListElement = cmpiData;
    unsigned int AddressMatchListElementSize;
    const char** AddressMatchListElementArray;
    ArrayConverter::makeArray(
      AddressMatchListElement, 
      (char***)&AddressMatchListElementArray, 
      AddressMatchListElementSize);
      setAddressMatchListElement(AddressMatchListElementArray, AddressMatchListElementSize, 0);
    }

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstance::
   ~Linux_DnsAddressMatchListManualInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstance&
  Linux_DnsAddressMatchListManualInstance::operator=(
    const Linux_DnsAddressMatchListManualInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsAddressMatchListManualInstance::getCmpiInstance(
    const char** aPropertiesPP) const {
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (aPropertiesPP) {
	    cmpiInstance.setPropertyFilter(aPropertiesPP,0);
    }

  	if (isSet.AddressMatchListElementType) {
  	  
      unsigned int AddressMatchListElementTypeSize;
      const CMPIUint8* arrayAddressMatchListElementType = getAddressMatchListElementType(AddressMatchListElementTypeSize);
      CmpiArray cmpiArrayAddressMatchListElementType = CmpiArray(
        AddressMatchListElementTypeSize,
        CMPI_uint8);
      for (unsigned int x=0; x < AddressMatchListElementTypeSize; ++x) {
        cmpiArrayAddressMatchListElementType[x] = CmpiData(arrayAddressMatchListElementType[x]);
      }
  	  cmpiInstance.setProperty(
  	    "AddressMatchListElementType",
  	    CmpiData(cmpiArrayAddressMatchListElementType));
  	}

  	if (isSet.AddressMatchListElement) {
  	  
      unsigned int AddressMatchListElementSize;
      const char** arrayAddressMatchListElement = getAddressMatchListElement(AddressMatchListElementSize);
      CmpiArray cmpiArrayAddressMatchListElement = CmpiArray(
        AddressMatchListElementSize,
        CMPI_chars);
      for (unsigned int x=0; x < AddressMatchListElementSize; ++x) {
        cmpiArrayAddressMatchListElement[x] = CmpiData(arrayAddressMatchListElement[x]);
      }
  	  cmpiInstance.setProperty(
  	    "AddressMatchListElement",
  	    CmpiData(cmpiArrayAddressMatchListElement));
  	}

  	
  	return cmpiInstance;
  	
  }
  
  //----------------------------------------------------------------------------
  // InstanceName related methods
  //----------------------------------------------------------------------------
  unsigned int 
  Linux_DnsAddressMatchListManualInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsAddressMatchListInstanceName&
  Linux_DnsAddressMatchListManualInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsAddressMatchList");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListManualInstance::setInstanceName(
    const Linux_DnsAddressMatchListInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // AddressMatchListElementType related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsAddressMatchListManualInstance::isAddressMatchListElementTypeSet() const {
    return isSet.AddressMatchListElementType;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsAddressMatchListManualInstance::setAddressMatchListElementType(
    const CMPIUint8* aValueP,
    const unsigned int aSize,
    int aCopyFlag) {
    
    if (isSet.AddressMatchListElementType) {
      delete []m_AddressMatchListElementType;
    }
    
    if (aCopyFlag && aValueP) {
      CMPIUint8* arrayP = new CMPIUint8[aSize];
      for(unsigned int x=0; x < aSize; ++x) {
        arrayP[x] = aValueP[x];
      }
      m_AddressMatchListElementType = arrayP;
    } else {
      m_AddressMatchListElementType = aValueP;
    }
    
    m_AddressMatchListElementTypeSize = aSize;

    isSet.AddressMatchListElementType = 1;
    
  }       

  //----------------------------------------------------------------------------
  const CMPIUint8*
  Linux_DnsAddressMatchListManualInstance::getAddressMatchListElementType(unsigned int& aSize) const {
    
    if ( ! isSet.AddressMatchListElementType) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "AddressMatchListElementType",
        "Linux_DnsAddressMatchList");
   	}

    aSize = m_AddressMatchListElementTypeSize;
    return m_AddressMatchListElementType;

  }
       
  //----------------------------------------------------------------------------
  // AddressMatchListElement related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsAddressMatchListManualInstance::isAddressMatchListElementSet() const {
    return isSet.AddressMatchListElement;
  }

  //----------------------------------------------------------------------------
  void  
  Linux_DnsAddressMatchListManualInstance::setAddressMatchListElement(
    const char** aValuePP, 
    const unsigned int aSize,
    int aCopyFlag) {
    
    if (isSet.AddressMatchListElement) {
      delete m_AddressMatchListElement;
    }
    
    if (aCopyFlag && aValuePP) {
      m_AddressMatchListElement = new const char*[aSize];
      for (unsigned int x=0; x < aSize; ++x) {
        char* stringP = new char[strlen(aValuePP[x])+1];
        strcpy(stringP,aValuePP[x]);
        m_AddressMatchListElement[x] = stringP;
      }      
    } else {
      m_AddressMatchListElement = aValuePP;
    }
    
    m_AddressMatchListElementSize = aSize;
    
    isSet.AddressMatchListElement = 1;
    
  }       

  //----------------------------------------------------------------------------
  const char**
  Linux_DnsAddressMatchListManualInstance::getAddressMatchListElement(unsigned int& aSize) const {
    
    if ( ! isSet.AddressMatchListElement) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "AddressMatchListElement",
        "Linux_DnsAddressMatchList");
   	}

    aSize = m_AddressMatchListElementSize;
    return m_AddressMatchListElement;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListManualInstance::init() {
   	isSet.instanceName = 0;
    isSet.AddressMatchListElementType = 0;
    m_AddressMatchListElementTypeSize = 0;
    isSet.AddressMatchListElement = 0;
    m_AddressMatchListElementSize = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsAddressMatchListManualInstance::init(
    const Linux_DnsAddressMatchListManualInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
       	
    if (anOriginal.isAddressMatchListElementTypeSet()) {
      unsigned int sizeAddressMatchListElementType;
      const CMPIUint8* AddressMatchListElementTypeOriginal = anOriginal.getAddressMatchListElementType(sizeAddressMatchListElementType);
      setAddressMatchListElementType(AddressMatchListElementTypeOriginal, sizeAddressMatchListElementType,1);
    }
   	
    if (anOriginal.isAddressMatchListElementSet()) {
      unsigned int sizeAddressMatchListElement;
      const char** AddressMatchListElementOriginal = anOriginal.getAddressMatchListElement(sizeAddressMatchListElement);
      setAddressMatchListElement(AddressMatchListElementOriginal, sizeAddressMatchListElement,1);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListManualInstance::reset() {
   	
  	if (isSet.AddressMatchListElementType) {
  	  ArrayConverter::destructArray((CMPIUint8*)m_AddressMatchListElementType);
  	}

  	if (isSet.AddressMatchListElement) {
  	  ArrayConverter::destructArray((char**)m_AddressMatchListElement,m_AddressMatchListElementSize);
  	}

  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsAddressMatchListManualInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstanceEnumerationElement::Linux_DnsAddressMatchListManualInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstanceEnumerationElement::~Linux_DnsAddressMatchListManualInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsAddressMatchListManualInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstanceEnumeration::Linux_DnsAddressMatchListManualInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstanceEnumeration::Linux_DnsAddressMatchListManualInstanceEnumeration(
    const Linux_DnsAddressMatchListManualInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListManualInstanceEnumeration::~Linux_DnsAddressMatchListManualInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListManualInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsAddressMatchListManualInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsAddressMatchListManualInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsAddressMatchListManualInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsAddressMatchListManualInstance&  
  Linux_DnsAddressMatchListManualInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsAddressMatchListManualInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsAddressMatchListManualInstance&
  Linux_DnsAddressMatchListManualInstanceEnumeration::getNext() {
   	
    Linux_DnsAddressMatchListManualInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListManualInstanceEnumeration::addElement(
    const Linux_DnsAddressMatchListManualInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsAddressMatchListManualInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsAddressMatchListManualInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsAddressMatchListManualInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsAddressMatchListManualInstance(anInstance);
  	}

  }
  
}
