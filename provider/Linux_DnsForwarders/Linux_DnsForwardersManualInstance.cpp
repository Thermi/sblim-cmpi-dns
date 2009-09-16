// =======================================================================
// Linux_DnsForwardersManualInstance.cpp
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
#include "Linux_DnsForwardersManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsForwardersManualInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsForwardersManualInstance::Linux_DnsForwardersManualInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsForwardersManualInstance::Linux_DnsForwardersManualInstance(
    const Linux_DnsForwardersManualInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsForwardersManualInstance::Linux_DnsForwardersManualInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsForwardersInstanceName(cop));

    cmpiData = aCmpiInstance.getProperty("ForwardersElementType");
    if ( ! cmpiData.isNullValue()){
      CmpiArray ForwardersElementType = cmpiData;
    unsigned int ForwardersElementTypeSize;
    const CMPIUint8* ForwardersElementTypeArray;
    ArrayConverter::makeArray(
      ForwardersElementType, 
      (CMPIUint8**)&ForwardersElementTypeArray, 
      ForwardersElementTypeSize);
      setForwardersElementType(ForwardersElementTypeArray, ForwardersElementTypeSize, 0);
    }

    cmpiData = aCmpiInstance.getProperty("ForwardersElement");
    if ( ! cmpiData.isNullValue()){
      CmpiArray ForwardersElement = cmpiData;
    unsigned int ForwardersElementSize;
    const char** ForwardersElementArray;
    ArrayConverter::makeArray(
      ForwardersElement, 
      (char***)&ForwardersElementArray, 
      ForwardersElementSize);
      setForwardersElement(ForwardersElementArray, ForwardersElementSize, 0);
    }

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsForwardersManualInstance::
   ~Linux_DnsForwardersManualInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsForwardersManualInstance&
  Linux_DnsForwardersManualInstance::operator=(
    const Linux_DnsForwardersManualInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsForwardersManualInstance::getCmpiInstance(
    const char** aPropertiesPP) const {
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (aPropertiesPP) {
	    cmpiInstance.setPropertyFilter(aPropertiesPP,0);
    }

  	if (isSet.ForwardersElementType) {
  	  
      unsigned int ForwardersElementTypeSize;
      const CMPIUint8* arrayForwardersElementType = getForwardersElementType(ForwardersElementTypeSize);
      CmpiArray cmpiArrayForwardersElementType = CmpiArray(
        ForwardersElementTypeSize,
        CMPI_uint8);
      for (unsigned int x=0; x < ForwardersElementTypeSize; ++x) {
        cmpiArrayForwardersElementType[x] = CmpiData(arrayForwardersElementType[x]);
      }
  	  cmpiInstance.setProperty(
  	    "ForwardersElementType",
  	    CmpiData(cmpiArrayForwardersElementType));
  	}

  	if (isSet.ForwardersElement) {
  	  
      unsigned int ForwardersElementSize;
      const char** arrayForwardersElement = getForwardersElement(ForwardersElementSize);
      CmpiArray cmpiArrayForwardersElement = CmpiArray(
        ForwardersElementSize,
        CMPI_chars);
      for (unsigned int x=0; x < ForwardersElementSize; ++x) {
        cmpiArrayForwardersElement[x] = CmpiData(arrayForwardersElement[x]);
      }
  	  cmpiInstance.setProperty(
  	    "ForwardersElement",
  	    CmpiData(cmpiArrayForwardersElement));
  	}

  	
  	return cmpiInstance;
  	
  }
  
  //----------------------------------------------------------------------------
  // InstanceName related methods
  //----------------------------------------------------------------------------
  unsigned int 
  Linux_DnsForwardersManualInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsForwardersInstanceName&
  Linux_DnsForwardersManualInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsForwarders");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersManualInstance::setInstanceName(
    const Linux_DnsForwardersInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // ForwardersElementType related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardersManualInstance::isForwardersElementTypeSet() const {
    return isSet.ForwardersElementType;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsForwardersManualInstance::setForwardersElementType(
    const CMPIUint8* aValueP,
    const unsigned int aSize,
    int aCopyFlag) {
    
    if (isSet.ForwardersElementType) {
      delete []m_ForwardersElementType;
    }
    
    if (aCopyFlag && aValueP) {
      CMPIUint8* arrayP = new CMPIUint8[aSize];
      for(unsigned int x=0; x < aSize; ++x) {
        arrayP[x] = aValueP[x];
      }
      m_ForwardersElementType = arrayP;
    } else {
      m_ForwardersElementType = aValueP;
    }
    
    m_ForwardersElementTypeSize = aSize;

    isSet.ForwardersElementType = 1;
    
  }       

  //----------------------------------------------------------------------------
  const CMPIUint8*
  Linux_DnsForwardersManualInstance::getForwardersElementType(unsigned int& aSize) const {
    
    if ( ! isSet.ForwardersElementType) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ForwardersElementType",
        "Linux_DnsForwarders");
   	}

    aSize = m_ForwardersElementTypeSize;
    return m_ForwardersElementType;

  }
       
  //----------------------------------------------------------------------------
  // ForwardersElement related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardersManualInstance::isForwardersElementSet() const {
    return isSet.ForwardersElement;
  }

  //----------------------------------------------------------------------------
  void  
  Linux_DnsForwardersManualInstance::setForwardersElement(
    const char** aValuePP, 
    const unsigned int aSize,
    int aCopyFlag) {
    
    if (isSet.ForwardersElement) {
      delete m_ForwardersElement;
    }
    
    if (aCopyFlag && aValuePP) {
      m_ForwardersElement = new const char*[aSize];
      for (unsigned int x=0; x < aSize; ++x) {
        char* stringP = new char[strlen(aValuePP[x])+1];
        strcpy(stringP,aValuePP[x]);
        m_ForwardersElement[x] = stringP;
      }      
    } else {
      m_ForwardersElement = aValuePP;
    }
    
    m_ForwardersElementSize = aSize;
    
    isSet.ForwardersElement = 1;
    
  }       

  //----------------------------------------------------------------------------
  const char**
  Linux_DnsForwardersManualInstance::getForwardersElement(unsigned int& aSize) const {
    
    if ( ! isSet.ForwardersElement) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ForwardersElement",
        "Linux_DnsForwarders");
   	}

    aSize = m_ForwardersElementSize;
    return m_ForwardersElement;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersManualInstance::init() {
   	isSet.instanceName = 0;
    isSet.ForwardersElementType = 0;
    m_ForwardersElementTypeSize = 0;
    isSet.ForwardersElement = 0;
    m_ForwardersElementSize = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsForwardersManualInstance::init(
    const Linux_DnsForwardersManualInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
       	
    if (anOriginal.isForwardersElementTypeSet()) {
      unsigned int sizeForwardersElementType;
      const CMPIUint8* ForwardersElementTypeOriginal = anOriginal.getForwardersElementType(sizeForwardersElementType);
      setForwardersElementType(ForwardersElementTypeOriginal, sizeForwardersElementType,1);
    }
   	
    if (anOriginal.isForwardersElementSet()) {
      unsigned int sizeForwardersElement;
      const char** ForwardersElementOriginal = anOriginal.getForwardersElement(sizeForwardersElement);
      setForwardersElement(ForwardersElementOriginal, sizeForwardersElement,1);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersManualInstance::reset() {
   	
  	if (isSet.ForwardersElementType) {
  	  ArrayConverter::destructArray((CMPIUint8*)m_ForwardersElementType);
  	}

  	if (isSet.ForwardersElement) {
  	  ArrayConverter::destructArray((char**)m_ForwardersElement,m_ForwardersElementSize);
  	}

  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsForwardersManualInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsForwardersManualInstanceEnumerationElement::Linux_DnsForwardersManualInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsForwardersManualInstanceEnumerationElement::~Linux_DnsForwardersManualInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsForwardersManualInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsForwardersManualInstanceEnumeration::Linux_DnsForwardersManualInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsForwardersManualInstanceEnumeration::Linux_DnsForwardersManualInstanceEnumeration(
    const Linux_DnsForwardersManualInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsForwardersManualInstanceEnumeration::~Linux_DnsForwardersManualInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersManualInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsForwardersManualInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsForwardersManualInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsForwardersManualInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsForwardersManualInstance&  
  Linux_DnsForwardersManualInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsForwardersManualInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsForwardersManualInstance&
  Linux_DnsForwardersManualInstanceEnumeration::getNext() {
   	
    Linux_DnsForwardersManualInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersManualInstanceEnumeration::addElement(
    const Linux_DnsForwardersManualInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsForwardersManualInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsForwardersManualInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsForwardersManualInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsForwardersManualInstance(anInstance);
  	}

  }
  
}
