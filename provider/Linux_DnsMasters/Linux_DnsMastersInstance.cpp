// =======================================================================
// Linux_DnsMastersInstance.cpp
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
#include "Linux_DnsMastersInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsMastersInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsMastersInstance::Linux_DnsMastersInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsMastersInstance::Linux_DnsMastersInstance(
    const Linux_DnsMastersInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsMastersInstance::Linux_DnsMastersInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsMastersInstanceName(cop));

    cmpiData = aCmpiInstance.getProperty("Caption");
    if ( ! cmpiData.isNullValue()){
      CmpiString Caption = cmpiData;
      setCaption(Caption.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("Description");
    if ( ! cmpiData.isNullValue()){
      CmpiString Description = cmpiData;
      setDescription(Description.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("ElementName");
    if ( ! cmpiData.isNullValue()){
      CmpiString ElementName = cmpiData;
      setElementName(ElementName.charPtr());
    }

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
  Linux_DnsMastersInstance::
   ~Linux_DnsMastersInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsMastersInstance&
  Linux_DnsMastersInstance::operator=(
    const Linux_DnsMastersInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsMastersInstance::getCmpiInstance(
    const char** aPropertiesPP) const {
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (aPropertiesPP) {
	    cmpiInstance.setPropertyFilter(aPropertiesPP,0);
    }

  	if (isSet.Caption) {
  	  
  	  cmpiInstance.setProperty(
  	    "Caption",
  	    CmpiData(m_Caption));
  	}

  	if (isSet.Description) {
  	  
  	  cmpiInstance.setProperty(
  	    "Description",
  	    CmpiData(m_Description));
  	}

  	if (isSet.ElementName) {
  	  
  	  cmpiInstance.setProperty(
  	    "ElementName",
  	    CmpiData(m_ElementName));
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
  Linux_DnsMastersInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsMastersInstanceName&
  Linux_DnsMastersInstance::getInstanceName() const {

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
  Linux_DnsMastersInstance::setInstanceName(
    const Linux_DnsMastersInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // Caption related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMastersInstance::isCaptionSet() const {
    return isSet.Caption;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersInstance::setCaption(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.Caption) {
      delete [] m_Caption;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_Caption = valueP;
    } else {
      m_Caption = aValueP;
    }
    
    isSet.Caption = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsMastersInstance::getCaption() const {
    
    if ( ! isSet.Caption) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Caption",
        "Linux_DnsMasters");
   	}


    return m_Caption;

  }
       
  //----------------------------------------------------------------------------
  // Description related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMastersInstance::isDescriptionSet() const {
    return isSet.Description;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersInstance::setDescription(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.Description) {
      delete [] m_Description;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_Description = valueP;
    } else {
      m_Description = aValueP;
    }
    
    isSet.Description = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsMastersInstance::getDescription() const {
    
    if ( ! isSet.Description) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Description",
        "Linux_DnsMasters");
   	}


    return m_Description;

  }
       
  //----------------------------------------------------------------------------
  // ElementName related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMastersInstance::isElementNameSet() const {
    return isSet.ElementName;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersInstance::setElementName(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.ElementName) {
      delete [] m_ElementName;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_ElementName = valueP;
    } else {
      m_ElementName = aValueP;
    }
    
    isSet.ElementName = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsMastersInstance::getElementName() const {
    
    if ( ! isSet.ElementName) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ElementName",
        "Linux_DnsMasters");
   	}


    return m_ElementName;

  }
       
  //----------------------------------------------------------------------------
  // MasterElementType related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsMastersInstance::isMasterElementTypeSet() const {
    return isSet.MasterElementType;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsMastersInstance::setMasterElementType(
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
  Linux_DnsMastersInstance::getMasterElementType(unsigned int& aSize) const {
    
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
  Linux_DnsMastersInstance::isMasterElementSet() const {
    return isSet.MasterElement;
  }

  //----------------------------------------------------------------------------
  void  
  Linux_DnsMastersInstance::setMasterElement(
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
  Linux_DnsMastersInstance::getMasterElement(unsigned int& aSize) const {
    
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
  Linux_DnsMastersInstance::init() {
   	isSet.instanceName = 0;
    isSet.Caption = 0;
    isSet.Description = 0;
    isSet.ElementName = 0;
    isSet.MasterElementType = 0;
    m_MasterElementTypeSize = 0;
    isSet.MasterElement = 0;
    m_MasterElementSize = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsMastersInstance::init(
    const Linux_DnsMastersInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
       	
    if (anOriginal.isCaptionSet()) {
      const char* CaptionOriginal = anOriginal.getCaption();
      setCaption(CaptionOriginal,1);
    }
   	
    if (anOriginal.isDescriptionSet()) {
      const char* DescriptionOriginal = anOriginal.getDescription();
      setDescription(DescriptionOriginal,1);
    }
   	
    if (anOriginal.isElementNameSet()) {
      const char* ElementNameOriginal = anOriginal.getElementName();
      setElementName(ElementNameOriginal,1);
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
  Linux_DnsMastersInstance::reset() {
   	
  	if (isSet.Caption) {
  	  delete(m_Caption);
  	}

  	if (isSet.Description) {
  	  delete(m_Description);
  	}

  	if (isSet.ElementName) {
  	  delete(m_ElementName);
  	}

  	if (isSet.MasterElementType) {
  	  ArrayConverter::destructArray((CMPIUint8*)m_MasterElementType);
  	}

  	if (isSet.MasterElement) {
  	  ArrayConverter::destructArray((char**)m_MasterElement,m_MasterElementSize);
  	}

  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsMastersInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsMastersInstanceEnumerationElement::Linux_DnsMastersInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsMastersInstanceEnumerationElement::~Linux_DnsMastersInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsMastersInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsMastersInstanceEnumeration::Linux_DnsMastersInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsMastersInstanceEnumeration::Linux_DnsMastersInstanceEnumeration(
    const Linux_DnsMastersInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsMastersInstanceEnumeration::~Linux_DnsMastersInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsMastersInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsMastersInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsMastersInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsMastersInstance&  
  Linux_DnsMastersInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsMastersInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsMastersInstance&
  Linux_DnsMastersInstanceEnumeration::getNext() {
   	
    Linux_DnsMastersInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsMastersInstanceEnumeration::addElement(
    const Linux_DnsMastersInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsMastersInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsMastersInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsMastersInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsMastersInstance(anInstance);
  	}

  }
  
}
