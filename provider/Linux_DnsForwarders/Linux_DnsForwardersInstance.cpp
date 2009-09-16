// =======================================================================
// Linux_DnsForwardersInstance.cpp
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
#include "Linux_DnsForwardersInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsForwardersInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsForwardersInstance::Linux_DnsForwardersInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsForwardersInstance::Linux_DnsForwardersInstance(
    const Linux_DnsForwardersInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsForwardersInstance::Linux_DnsForwardersInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsForwardersInstanceName(cop));

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
  Linux_DnsForwardersInstance::
   ~Linux_DnsForwardersInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsForwardersInstance&
  Linux_DnsForwardersInstance::operator=(
    const Linux_DnsForwardersInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsForwardersInstance::getCmpiInstance(
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
  Linux_DnsForwardersInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsForwardersInstanceName&
  Linux_DnsForwardersInstance::getInstanceName() const {

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
  Linux_DnsForwardersInstance::setInstanceName(
    const Linux_DnsForwardersInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // Caption related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardersInstance::isCaptionSet() const {
    return isSet.Caption;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersInstance::setCaption(
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
  Linux_DnsForwardersInstance::getCaption() const {
    
    if ( ! isSet.Caption) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Caption",
        "Linux_DnsForwarders");
   	}


    return m_Caption;

  }
       
  //----------------------------------------------------------------------------
  // Description related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardersInstance::isDescriptionSet() const {
    return isSet.Description;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersInstance::setDescription(
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
  Linux_DnsForwardersInstance::getDescription() const {
    
    if ( ! isSet.Description) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Description",
        "Linux_DnsForwarders");
   	}


    return m_Description;

  }
       
  //----------------------------------------------------------------------------
  // ElementName related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardersInstance::isElementNameSet() const {
    return isSet.ElementName;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersInstance::setElementName(
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
  Linux_DnsForwardersInstance::getElementName() const {
    
    if ( ! isSet.ElementName) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ElementName",
        "Linux_DnsForwarders");
   	}


    return m_ElementName;

  }
       
  //----------------------------------------------------------------------------
  // ForwardersElementType related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardersInstance::isForwardersElementTypeSet() const {
    return isSet.ForwardersElementType;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsForwardersInstance::setForwardersElementType(
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
  Linux_DnsForwardersInstance::getForwardersElementType(unsigned int& aSize) const {
    
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
  Linux_DnsForwardersInstance::isForwardersElementSet() const {
    return isSet.ForwardersElement;
  }

  //----------------------------------------------------------------------------
  void  
  Linux_DnsForwardersInstance::setForwardersElement(
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
  Linux_DnsForwardersInstance::getForwardersElement(unsigned int& aSize) const {
    
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
  Linux_DnsForwardersInstance::init() {
   	isSet.instanceName = 0;
    isSet.Caption = 0;
    isSet.Description = 0;
    isSet.ElementName = 0;
    isSet.ForwardersElementType = 0;
    m_ForwardersElementTypeSize = 0;
    isSet.ForwardersElement = 0;
    m_ForwardersElementSize = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsForwardersInstance::init(
    const Linux_DnsForwardersInstance& anOriginal) {   	

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
  Linux_DnsForwardersInstance::reset() {
   	
  	if (isSet.Caption) {
  	  delete(m_Caption);
  	}

  	if (isSet.Description) {
  	  delete(m_Description);
  	}

  	if (isSet.ElementName) {
  	  delete(m_ElementName);
  	}

  	if (isSet.ForwardersElementType) {
  	  ArrayConverter::destructArray((CMPIUint8*)m_ForwardersElementType);
  	}

  	if (isSet.ForwardersElement) {
  	  ArrayConverter::destructArray((char**)m_ForwardersElement,m_ForwardersElementSize);
  	}

  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsForwardersInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsForwardersInstanceEnumerationElement::Linux_DnsForwardersInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsForwardersInstanceEnumerationElement::~Linux_DnsForwardersInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsForwardersInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsForwardersInstanceEnumeration::Linux_DnsForwardersInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsForwardersInstanceEnumeration::Linux_DnsForwardersInstanceEnumeration(
    const Linux_DnsForwardersInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsForwardersInstanceEnumeration::~Linux_DnsForwardersInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsForwardersInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsForwardersInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsForwardersInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsForwardersInstance&  
  Linux_DnsForwardersInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsForwardersInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsForwardersInstance&
  Linux_DnsForwardersInstanceEnumeration::getNext() {
   	
    Linux_DnsForwardersInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardersInstanceEnumeration::addElement(
    const Linux_DnsForwardersInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsForwardersInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsForwardersInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsForwardersInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsForwardersInstance(anInstance);
  	}

  }
  
}
