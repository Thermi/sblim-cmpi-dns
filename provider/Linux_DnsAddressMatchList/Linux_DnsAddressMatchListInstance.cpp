// =======================================================================
// Linux_DnsAddressMatchListInstance.cpp
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
#include "Linux_DnsAddressMatchListInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsAddressMatchListInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsAddressMatchListInstance::Linux_DnsAddressMatchListInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListInstance::Linux_DnsAddressMatchListInstance(
    const Linux_DnsAddressMatchListInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListInstance::Linux_DnsAddressMatchListInstance(
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

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListInstance::
   ~Linux_DnsAddressMatchListInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListInstance&
  Linux_DnsAddressMatchListInstance::operator=(
    const Linux_DnsAddressMatchListInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsAddressMatchListInstance::getCmpiInstance(
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

  	
  	return cmpiInstance;
  	
  }
  
  //----------------------------------------------------------------------------
  // InstanceName related methods
  //----------------------------------------------------------------------------
  unsigned int 
  Linux_DnsAddressMatchListInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsAddressMatchListInstanceName&
  Linux_DnsAddressMatchListInstance::getInstanceName() const {

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
  Linux_DnsAddressMatchListInstance::setInstanceName(
    const Linux_DnsAddressMatchListInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // AddressMatchListElementType related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsAddressMatchListInstance::isAddressMatchListElementTypeSet() const {
    return isSet.AddressMatchListElementType;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsAddressMatchListInstance::setAddressMatchListElementType(
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
  Linux_DnsAddressMatchListInstance::getAddressMatchListElementType(unsigned int& aSize) const {
    
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
  Linux_DnsAddressMatchListInstance::isAddressMatchListElementSet() const {
    return isSet.AddressMatchListElement;
  }

  //----------------------------------------------------------------------------
  void  
  Linux_DnsAddressMatchListInstance::setAddressMatchListElement(
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
  Linux_DnsAddressMatchListInstance::getAddressMatchListElement(unsigned int& aSize) const {
    
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
  // Caption related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsAddressMatchListInstance::isCaptionSet() const {
    return isSet.Caption;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListInstance::setCaption(
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
  Linux_DnsAddressMatchListInstance::getCaption() const {
    
    if ( ! isSet.Caption) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Caption",
        "Linux_DnsAddressMatchList");
   	}


    return m_Caption;

  }
       
  //----------------------------------------------------------------------------
  // Description related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsAddressMatchListInstance::isDescriptionSet() const {
    return isSet.Description;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListInstance::setDescription(
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
  Linux_DnsAddressMatchListInstance::getDescription() const {
    
    if ( ! isSet.Description) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Description",
        "Linux_DnsAddressMatchList");
   	}


    return m_Description;

  }
       
  //----------------------------------------------------------------------------
  // ElementName related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsAddressMatchListInstance::isElementNameSet() const {
    return isSet.ElementName;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListInstance::setElementName(
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
  Linux_DnsAddressMatchListInstance::getElementName() const {
    
    if ( ! isSet.ElementName) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ElementName",
        "Linux_DnsAddressMatchList");
   	}


    return m_ElementName;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListInstance::init() {
   	isSet.instanceName = 0;
    isSet.AddressMatchListElementType = 0;
    m_AddressMatchListElementTypeSize = 0;
    isSet.AddressMatchListElement = 0;
    m_AddressMatchListElementSize = 0;
    isSet.Caption = 0;
    isSet.Description = 0;
    isSet.ElementName = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsAddressMatchListInstance::init(
    const Linux_DnsAddressMatchListInstance& anOriginal) {   	

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
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListInstance::reset() {
   	
  	if (isSet.AddressMatchListElementType) {
  	  ArrayConverter::destructArray((CMPIUint8*)m_AddressMatchListElementType);
  	}

  	if (isSet.AddressMatchListElement) {
  	  ArrayConverter::destructArray((char**)m_AddressMatchListElement,m_AddressMatchListElementSize);
  	}

  	if (isSet.Caption) {
  	  delete(m_Caption);
  	}

  	if (isSet.Description) {
  	  delete(m_Description);
  	}

  	if (isSet.ElementName) {
  	  delete(m_ElementName);
  	}

  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsAddressMatchListInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListInstanceEnumerationElement::Linux_DnsAddressMatchListInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListInstanceEnumerationElement::~Linux_DnsAddressMatchListInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsAddressMatchListInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListInstanceEnumeration::Linux_DnsAddressMatchListInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListInstanceEnumeration::Linux_DnsAddressMatchListInstanceEnumeration(
    const Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAddressMatchListInstanceEnumeration::~Linux_DnsAddressMatchListInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsAddressMatchListInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsAddressMatchListInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsAddressMatchListInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsAddressMatchListInstance&  
  Linux_DnsAddressMatchListInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsAddressMatchListInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsAddressMatchListInstance&
  Linux_DnsAddressMatchListInstanceEnumeration::getNext() {
   	
    Linux_DnsAddressMatchListInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListInstanceEnumeration::addElement(
    const Linux_DnsAddressMatchListInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsAddressMatchListInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsAddressMatchListInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsAddressMatchListInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsAddressMatchListInstance(anInstance);
  	}

  }
  
}
