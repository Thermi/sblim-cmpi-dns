// =======================================================================
// Linux_DnsHintZoneInstance.cpp
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
#include "Linux_DnsHintZoneInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsHintZoneInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsHintZoneInstance::Linux_DnsHintZoneInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneInstance::Linux_DnsHintZoneInstance(
    const Linux_DnsHintZoneInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneInstance::Linux_DnsHintZoneInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsHintZoneInstanceName(cop));

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

    cmpiData = aCmpiInstance.getProperty("TTL");
    if ( ! cmpiData.isNullValue()){
      CMPISint32 TTL = cmpiData;
      setTTL(TTL);
    }

    cmpiData = aCmpiInstance.getProperty("Type");
    if ( ! cmpiData.isNullValue()){
      CMPIUint8 Type = cmpiData;
      setType(Type);
    }

    cmpiData = aCmpiInstance.getProperty("ZoneFile");
    if ( ! cmpiData.isNullValue()){
      CmpiString ZoneFile = cmpiData;
      setZoneFile(ZoneFile.charPtr());
    }

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneInstance::
   ~Linux_DnsHintZoneInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneInstance&
  Linux_DnsHintZoneInstance::operator=(
    const Linux_DnsHintZoneInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsHintZoneInstance::getCmpiInstance(
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

  	if (isSet.TTL) {
  	  
  	  cmpiInstance.setProperty(
  	    "TTL",
  	    CmpiData(m_TTL));
  	}

  	if (isSet.Type) {
  	  
  	  cmpiInstance.setProperty(
  	    "Type",
  	    CmpiData(m_Type));
  	}

  	if (isSet.ZoneFile) {
  	  
  	  cmpiInstance.setProperty(
  	    "ZoneFile",
  	    CmpiData(m_ZoneFile));
  	}

  	
  	return cmpiInstance;
  	
  }
  
  //----------------------------------------------------------------------------
  // InstanceName related methods
  //----------------------------------------------------------------------------
  unsigned int 
  Linux_DnsHintZoneInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsHintZoneInstanceName&
  Linux_DnsHintZoneInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsHintZone");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsHintZoneInstance::setInstanceName(
    const Linux_DnsHintZoneInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // Caption related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsHintZoneInstance::isCaptionSet() const {
    return isSet.Caption;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsHintZoneInstance::setCaption(
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
  Linux_DnsHintZoneInstance::getCaption() const {
    
    if ( ! isSet.Caption) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Caption",
        "Linux_DnsHintZone");
   	}


    return m_Caption;

  }
       
  //----------------------------------------------------------------------------
  // Description related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsHintZoneInstance::isDescriptionSet() const {
    return isSet.Description;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsHintZoneInstance::setDescription(
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
  Linux_DnsHintZoneInstance::getDescription() const {
    
    if ( ! isSet.Description) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Description",
        "Linux_DnsHintZone");
   	}


    return m_Description;

  }
       
  //----------------------------------------------------------------------------
  // ElementName related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsHintZoneInstance::isElementNameSet() const {
    return isSet.ElementName;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsHintZoneInstance::setElementName(
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
  Linux_DnsHintZoneInstance::getElementName() const {
    
    if ( ! isSet.ElementName) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ElementName",
        "Linux_DnsHintZone");
   	}


    return m_ElementName;

  }
       
  //----------------------------------------------------------------------------
  // TTL related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsHintZoneInstance::isTTLSet() const {
    return isSet.TTL;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsHintZoneInstance::setTTL(
    const CMPISint32 aValue) {
  
    m_TTL = aValue;
    isSet.TTL = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPISint32
  Linux_DnsHintZoneInstance::getTTL() const {
    
    if ( ! isSet.TTL) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "TTL",
        "Linux_DnsHintZone");
   	}


    return m_TTL;

  }
       
  //----------------------------------------------------------------------------
  // Type related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsHintZoneInstance::isTypeSet() const {
    return isSet.Type;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsHintZoneInstance::setType(
    const CMPIUint8 aValue) {
  
    m_Type = aValue;
    isSet.Type = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint8
  Linux_DnsHintZoneInstance::getType() const {
    
    if ( ! isSet.Type) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Type",
        "Linux_DnsHintZone");
   	}


    return m_Type;

  }
       
  //----------------------------------------------------------------------------
  // ZoneFile related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsHintZoneInstance::isZoneFileSet() const {
    return isSet.ZoneFile;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsHintZoneInstance::setZoneFile(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.ZoneFile) {
      delete [] m_ZoneFile;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_ZoneFile = valueP;
    } else {
      m_ZoneFile = aValueP;
    }
    
    isSet.ZoneFile = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsHintZoneInstance::getZoneFile() const {
    
    if ( ! isSet.ZoneFile) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ZoneFile",
        "Linux_DnsHintZone");
   	}


    return m_ZoneFile;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsHintZoneInstance::init() {
   	isSet.instanceName = 0;
    isSet.Caption = 0;
    isSet.Description = 0;
    isSet.ElementName = 0;
    isSet.TTL = 0;
    isSet.Type = 0;
    isSet.ZoneFile = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsHintZoneInstance::init(
    const Linux_DnsHintZoneInstance& anOriginal) {   	

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
   	
    if (anOriginal.isTTLSet()) {
      const CMPISint32 TTLOriginal = anOriginal.getTTL();
      setTTL(TTLOriginal);
    }
   	
    if (anOriginal.isTypeSet()) {
      const CMPIUint8 TypeOriginal = anOriginal.getType();
      setType(TypeOriginal);
    }
   	
    if (anOriginal.isZoneFileSet()) {
      const char* ZoneFileOriginal = anOriginal.getZoneFile();
      setZoneFile(ZoneFileOriginal,1);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsHintZoneInstance::reset() {
   	
  	if (isSet.Caption) {
  	  delete(m_Caption);
  	}

  	if (isSet.Description) {
  	  delete(m_Description);
  	}

  	if (isSet.ElementName) {
  	  delete(m_ElementName);
  	}

  	if (isSet.ZoneFile) {
  	  delete(m_ZoneFile);
  	}

  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsHintZoneInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneInstanceEnumerationElement::Linux_DnsHintZoneInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneInstanceEnumerationElement::~Linux_DnsHintZoneInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsHintZoneInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneInstanceEnumeration::Linux_DnsHintZoneInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneInstanceEnumeration::Linux_DnsHintZoneInstanceEnumeration(
    const Linux_DnsHintZoneInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsHintZoneInstanceEnumeration::~Linux_DnsHintZoneInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsHintZoneInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsHintZoneInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsHintZoneInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsHintZoneInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsHintZoneInstance&  
  Linux_DnsHintZoneInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsHintZoneInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsHintZoneInstance&
  Linux_DnsHintZoneInstanceEnumeration::getNext() {
   	
    Linux_DnsHintZoneInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsHintZoneInstanceEnumeration::addElement(
    const Linux_DnsHintZoneInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsHintZoneInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsHintZoneInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsHintZoneInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsHintZoneInstance(anInstance);
  	}

  }
  
}
