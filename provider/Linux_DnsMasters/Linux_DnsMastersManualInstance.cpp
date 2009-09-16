// =======================================================================
// Linux_DnsMastersManualInstance.cpp
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
#include "Linux_DnsMastersManualInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsMastersManualInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsMastersManualInstance::Linux_DnsMastersManualInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsMastersManualInstance::Linux_DnsMastersManualInstance(
    const Linux_DnsMastersManualInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsMastersManualInstance::Linux_DnsMastersManualInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsMastersInstanceName(cop));

    cmpiData = aCmpiInstance.getProperty("MasterElementType");
    if ( ! cmpiData.isNullValue()){
      CmpiArray MasterElementType = cmpiData;
    unsigned int MasterElementTypeSize;
    const CMPIUint8* MasterElementTypeArray;
    ArrayConverter::makeArray(
      MasterElementType, 
      (CMPIUint8**)&MasterElementTypeArray, 
      MasterElementTypeSize);
      setMasterElementType(MasterElementTypeArray, MasterElementTypeSize, 0);
    }

    cmpiData = aCmpiInstance.getProperty("MasterElement");
    if ( ! cmpiData.isNullValue()){
      CmpiArray MasterElement = cmpiData;
    unsigned int MasterElementSize;
    const char** MasterElementArray;
    ArrayConverter::makeArray(
      MasterElement, 
      (char***)&MasterElementArray, 
      MasterElementSize);
      setMasterElement(MasterElementArray, MasterElementSize, 0);
    }

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsMastersManualInstance::
   ~Linux_DnsMastersManualInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsMastersManualInstance&
  Linux_DnsMastersManualInstance::operator=(
    const Linux_DnsMastersManualInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsMastersManualInstance::getCmpiInstance(
    const char** aPropertiesPP) const {
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (aPropertiesPP) {
	    cmpiInstance.setPropertyFilter(aPropertiesPP,0);
    }

  	if (isSet.MasterElementType) {
  	  
      unsigned int MasterElementTypeSize;
      const CMPIUint8* arrayMasterElementType = getMasterElementType(MasterElementTypeSize);
      CmpiArray cmpiArrayMasterElementType = CmpiArray(
        MasterElementTypeSize,
        CMPI_uint8);
      for (unsigned int x=0; x < MasterElementTypeSize; ++x) {
        cmpiArrayMasterElementType[x] = CmpiData(arrayMasterElementType[x]);
      }
  	  cmpiInstance.setProperty(
  	    "MasterElementType",
  	    CmpiData(cmpiArrayMasterElementType));
  	}

  	if (isSet.MasterElement) {
  	  
      unsigned int MasterElementSize;
      const char** arrayMasterElement = getMasterElement(MasterElementSize);
      CmpiArray cmpiArrayMasterElement = CmpiArray(
        MasterElementSize,
        CMPI_chars);
      for (unsigned int x=0; x < MasterElementSize; ++x) {
        cmpiArrayMasterElement[x] = CmpiData(arrayMasterElement[x]);
      }
  	  cmpiInstance.setProperty(
  	    "MasterElement",
  	    CmpiData(cmpiArrayMasterElement));
  	}

  	
  	return cmpiInstance;
  	
  }
  
  //----------------------------------------------------------------------------
  // InstanceName related methods
  //----------------------------------------------------------------------------
  unsigned int 
  Linux_DnsMastersManualInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsMastersInstanceName&
  Linux_DnsMastersManualInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsMasters");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersManualInstance::setInstanceName(
    const Linux_DnsMastersInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // MasterElementType related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMastersManualInstance::isMasterElementTypeSet() const {
    return isSet.MasterElementType;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMastersManualInstance::setMasterElementType(
    const CMPIUint8* aValueP,
    const unsigned int aSize,
    int aCopyFlag) {
    
    if (isSet.MasterElementType) {
      delete []m_MasterElementType;
    }
    
    if (aCopyFlag && aValueP) {
      CMPIUint8* arrayP = new CMPIUint8[aSize];
      for(unsigned int x=0; x < aSize; ++x) {
        arrayP[x] = aValueP[x];
      }
      m_MasterElementType = arrayP;
    } else {
      m_MasterElementType = aValueP;
    }
    
    m_MasterElementTypeSize = aSize;

    isSet.MasterElementType = 1;
    
  }       

  //----------------------------------------------------------------------------
  const CMPIUint8*
  Linux_DnsMastersManualInstance::getMasterElementType(unsigned int& aSize) const {
    
    if ( ! isSet.MasterElementType) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "MasterElementType",
        "Linux_DnsMasters");
   	}

    aSize = m_MasterElementTypeSize;
    return m_MasterElementType;

  }
       
  //----------------------------------------------------------------------------
  // MasterElement related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMastersManualInstance::isMasterElementSet() const {
    return isSet.MasterElement;
  }

  //----------------------------------------------------------------------------
  void  
  Linux_DnsMastersManualInstance::setMasterElement(
    const char** aValuePP, 
    const unsigned int aSize,
    int aCopyFlag) {
    
    if (isSet.MasterElement) {
      delete m_MasterElement;
    }
    
    if (aCopyFlag && aValuePP) {
      m_MasterElement = new const char*[aSize];
      for (unsigned int x=0; x < aSize; ++x) {
        char* stringP = new char[strlen(aValuePP[x])+1];
        strcpy(stringP,aValuePP[x]);
        m_MasterElement[x] = stringP;
      }      
    } else {
      m_MasterElement = aValuePP;
    }
    
    m_MasterElementSize = aSize;
    
    isSet.MasterElement = 1;
    
  }       

  //----------------------------------------------------------------------------
  const char**
  Linux_DnsMastersManualInstance::getMasterElement(unsigned int& aSize) const {
    
    if ( ! isSet.MasterElement) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "MasterElement",
        "Linux_DnsMasters");
   	}

    aSize = m_MasterElementSize;
    return m_MasterElement;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersManualInstance::init() {
   	isSet.instanceName = 0;
    isSet.MasterElementType = 0;
    m_MasterElementTypeSize = 0;
    isSet.MasterElement = 0;
    m_MasterElementSize = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsMastersManualInstance::init(
    const Linux_DnsMastersManualInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
       	
    if (anOriginal.isMasterElementTypeSet()) {
      unsigned int sizeMasterElementType;
      const CMPIUint8* MasterElementTypeOriginal = anOriginal.getMasterElementType(sizeMasterElementType);
      setMasterElementType(MasterElementTypeOriginal, sizeMasterElementType,1);
    }
   	
    if (anOriginal.isMasterElementSet()) {
      unsigned int sizeMasterElement;
      const char** MasterElementOriginal = anOriginal.getMasterElement(sizeMasterElement);
      setMasterElement(MasterElementOriginal, sizeMasterElement,1);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersManualInstance::reset() {
   	
  	if (isSet.MasterElementType) {
  	  ArrayConverter::destructArray((CMPIUint8*)m_MasterElementType);
  	}

  	if (isSet.MasterElement) {
  	  ArrayConverter::destructArray((char**)m_MasterElement,m_MasterElementSize);
  	}

  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsMastersManualInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsMastersManualInstanceEnumerationElement::Linux_DnsMastersManualInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsMastersManualInstanceEnumerationElement::~Linux_DnsMastersManualInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsMastersManualInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsMastersManualInstanceEnumeration::Linux_DnsMastersManualInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsMastersManualInstanceEnumeration::Linux_DnsMastersManualInstanceEnumeration(
    const Linux_DnsMastersManualInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsMastersManualInstanceEnumeration::~Linux_DnsMastersManualInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersManualInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsMastersManualInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsMastersManualInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsMastersManualInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsMastersManualInstance&  
  Linux_DnsMastersManualInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsMastersManualInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsMastersManualInstance&
  Linux_DnsMastersManualInstanceEnumeration::getNext() {
   	
    Linux_DnsMastersManualInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersManualInstanceEnumeration::addElement(
    const Linux_DnsMastersManualInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsMastersManualInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsMastersManualInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsMastersManualInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsMastersManualInstance(anInstance);
  	}

  }
  
}
