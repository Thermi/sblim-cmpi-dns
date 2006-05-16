// =======================================================================
// Linux_DnsForwardZoneInstance.cpp
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
#include "Linux_DnsForwardZoneInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsForwardZoneInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsForwardZoneInstance::Linux_DnsForwardZoneInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneInstance::Linux_DnsForwardZoneInstance(
    const Linux_DnsForwardZoneInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneInstance::Linux_DnsForwardZoneInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsForwardZoneInstanceName(cop));

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

    cmpiData = aCmpiInstance.getProperty("Forward");
    if ( ! cmpiData.isNullValue()){
      CMPIUint16 Forward = cmpiData;
      setForward(Forward);
    }

    cmpiData = aCmpiInstance.getProperty("Forwarders");
    if ( ! cmpiData.isNullValue()){
      CmpiArray Forwarders = cmpiData;
    unsigned int ForwardersSize;
    const char** ForwardersArray;
    ArrayConverter::makeArray(
      Forwarders, 
      (char***)&ForwardersArray, 
      ForwardersSize);
      setForwarders(ForwardersArray, ForwardersSize, 0);
    }

    cmpiData = aCmpiInstance.getProperty("ResourceRecordFile");
    if ( ! cmpiData.isNullValue()){
      CmpiString ResourceRecordFile = cmpiData;
      setResourceRecordFile(ResourceRecordFile.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("SettingID");
    if ( ! cmpiData.isNullValue()){
      CmpiString SettingID = cmpiData;
      setSettingID(SettingID.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("Type");
    if ( ! cmpiData.isNullValue()){
      CMPIUint16 Type = cmpiData;
      setType(Type);
    }

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneInstance::
   ~Linux_DnsForwardZoneInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneInstance&
  Linux_DnsForwardZoneInstance::operator=(
    const Linux_DnsForwardZoneInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsForwardZoneInstance::getCmpiInstance(
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

  	if (isSet.Forward) {
  	  
  	  cmpiInstance.setProperty(
  	    "Forward",
  	    CmpiData(m_Forward));
  	}

  	if (isSet.Forwarders) {
  	  
      unsigned int ForwardersSize;
      const char** arrayForwarders = getForwarders(ForwardersSize);
      CmpiArray cmpiArrayForwarders = CmpiArray(
        ForwardersSize,
        CMPI_chars);
      for (unsigned int x=0; x < ForwardersSize; ++x) {
        cmpiArrayForwarders[x] = CmpiData(arrayForwarders[x]);
      }
  	  cmpiInstance.setProperty(
  	    "Forwarders",
  	    CmpiData(cmpiArrayForwarders));
  	}

  	if (isSet.ResourceRecordFile) {
  	  
  	  cmpiInstance.setProperty(
  	    "ResourceRecordFile",
  	    CmpiData(m_ResourceRecordFile));
  	}

  	if (isSet.SettingID) {
  	  
  	  cmpiInstance.setProperty(
  	    "SettingID",
  	    CmpiData(m_SettingID));
  	}

  	if (isSet.Type) {
  	  
  	  cmpiInstance.setProperty(
  	    "Type",
  	    CmpiData(m_Type));
  	}

  	
  	return cmpiInstance;
  	
  }
  
  //----------------------------------------------------------------------------
  // InstanceName related methods
  //----------------------------------------------------------------------------
  unsigned int 
  Linux_DnsForwardZoneInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsForwardZoneInstanceName&
  Linux_DnsForwardZoneInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsForwardZone");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardZoneInstance::setInstanceName(
    const Linux_DnsForwardZoneInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // Caption related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardZoneInstance::isCaptionSet() const {
    return isSet.Caption;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardZoneInstance::setCaption(
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
  Linux_DnsForwardZoneInstance::getCaption() const {
    
    if ( ! isSet.Caption) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Caption",
        "Linux_DnsForwardZone");
   	}


    return m_Caption;

  }
       
  //----------------------------------------------------------------------------
  // Description related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardZoneInstance::isDescriptionSet() const {
    return isSet.Description;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardZoneInstance::setDescription(
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
  Linux_DnsForwardZoneInstance::getDescription() const {
    
    if ( ! isSet.Description) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Description",
        "Linux_DnsForwardZone");
   	}


    return m_Description;

  }
       
  //----------------------------------------------------------------------------
  // ElementName related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardZoneInstance::isElementNameSet() const {
    return isSet.ElementName;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardZoneInstance::setElementName(
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
  Linux_DnsForwardZoneInstance::getElementName() const {
    
    if ( ! isSet.ElementName) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ElementName",
        "Linux_DnsForwardZone");
   	}


    return m_ElementName;

  }
       
  //----------------------------------------------------------------------------
  // Forward related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardZoneInstance::isForwardSet() const {
    return isSet.Forward;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsForwardZoneInstance::setForward(
    const CMPIUint16 aValue) {
  
    m_Forward = aValue;
    isSet.Forward = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16
  Linux_DnsForwardZoneInstance::getForward() const {
    
    if ( ! isSet.Forward) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Forward",
        "Linux_DnsForwardZone");
   	}


    return m_Forward;

  }
       
  //----------------------------------------------------------------------------
  // Forwarders related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardZoneInstance::isForwardersSet() const {
    return isSet.Forwarders;
  }

  //----------------------------------------------------------------------------
  void  
  Linux_DnsForwardZoneInstance::setForwarders(
    const char** aValuePP, 
    const unsigned int aSize,
    int aCopyFlag) {
    
    if (isSet.Forwarders) {
      delete m_Forwarders;
    }
    
    if (aCopyFlag && aValuePP) {
      m_Forwarders = new const char*[aSize];
      for (unsigned int x=0; x < aSize; ++x) {
        char* stringP = new char[strlen(aValuePP[x])+1];
        strcpy(stringP,aValuePP[x]);
        m_Forwarders[x] = stringP;
      }      
    } else {
      m_Forwarders = aValuePP;
    }
    
    m_ForwardersSize = aSize;
    
    isSet.Forwarders = 1;
    
  }       

  //----------------------------------------------------------------------------
  const char**
  Linux_DnsForwardZoneInstance::getForwarders(unsigned int& aSize) const {
    
    if ( ! isSet.Forwarders) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Forwarders",
        "Linux_DnsForwardZone");
   	}

    aSize = m_ForwardersSize;
    return m_Forwarders;

  }
       
  //----------------------------------------------------------------------------
  // ResourceRecordFile related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardZoneInstance::isResourceRecordFileSet() const {
    return isSet.ResourceRecordFile;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardZoneInstance::setResourceRecordFile(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.ResourceRecordFile) {
      delete [] m_ResourceRecordFile;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_ResourceRecordFile = valueP;
    } else {
      m_ResourceRecordFile = aValueP;
    }
    
    isSet.ResourceRecordFile = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsForwardZoneInstance::getResourceRecordFile() const {
    
    if ( ! isSet.ResourceRecordFile) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ResourceRecordFile",
        "Linux_DnsForwardZone");
   	}


    return m_ResourceRecordFile;

  }
       
  //----------------------------------------------------------------------------
  // SettingID related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardZoneInstance::isSettingIDSet() const {
    return isSet.SettingID;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardZoneInstance::setSettingID(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.SettingID) {
      delete [] m_SettingID;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_SettingID = valueP;
    } else {
      m_SettingID = aValueP;
    }
    
    isSet.SettingID = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsForwardZoneInstance::getSettingID() const {
    
    if ( ! isSet.SettingID) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "SettingID",
        "Linux_DnsForwardZone");
   	}


    return m_SettingID;

  }
       
  //----------------------------------------------------------------------------
  // Type related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsForwardZoneInstance::isTypeSet() const {
    return isSet.Type;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsForwardZoneInstance::setType(
    const CMPIUint16 aValue) {
  
    m_Type = aValue;
    isSet.Type = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16
  Linux_DnsForwardZoneInstance::getType() const {
    
    if ( ! isSet.Type) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Type",
        "Linux_DnsForwardZone");
   	}


    return m_Type;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardZoneInstance::init() {
   	isSet.instanceName = 0;
    isSet.Caption = 0;
    isSet.Description = 0;
    isSet.ElementName = 0;
    isSet.Forward = 0;
    isSet.Forwarders = 0;
    m_ForwardersSize = 0;
    isSet.ResourceRecordFile = 0;
    isSet.SettingID = 0;
    isSet.Type = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsForwardZoneInstance::init(
    const Linux_DnsForwardZoneInstance& anOriginal) {   	

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
   	
    if (anOriginal.isForwardSet()) {
      const CMPIUint16 ForwardOriginal = anOriginal.getForward();
      setForward(ForwardOriginal);
    }
   	
    if (anOriginal.isForwardersSet()) {
      unsigned int sizeForwarders;
      const char** ForwardersOriginal = anOriginal.getForwarders(sizeForwarders);
      setForwarders(ForwardersOriginal, sizeForwarders,1);
    }
   	
    if (anOriginal.isResourceRecordFileSet()) {
      const char* ResourceRecordFileOriginal = anOriginal.getResourceRecordFile();
      setResourceRecordFile(ResourceRecordFileOriginal,1);
    }
   	
    if (anOriginal.isSettingIDSet()) {
      const char* SettingIDOriginal = anOriginal.getSettingID();
      setSettingID(SettingIDOriginal,1);
    }
   	
    if (anOriginal.isTypeSet()) {
      const CMPIUint16 TypeOriginal = anOriginal.getType();
      setType(TypeOriginal);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardZoneInstance::reset() {
   	
  	if (isSet.Caption) {
  	  delete(m_Caption);
  	}

  	if (isSet.Description) {
  	  delete(m_Description);
  	}

  	if (isSet.ElementName) {
  	  delete(m_ElementName);
  	}

  	if (isSet.Forwarders) {
  	  ArrayConverter::destructArray((char**)m_Forwarders,m_ForwardersSize);
  	}

  	if (isSet.ResourceRecordFile) {
  	  delete(m_ResourceRecordFile);
  	}

  	if (isSet.SettingID) {
  	  delete(m_SettingID);
  	}

  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsForwardZoneInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneInstanceEnumerationElement::Linux_DnsForwardZoneInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneInstanceEnumerationElement::~Linux_DnsForwardZoneInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsForwardZoneInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneInstanceEnumeration::Linux_DnsForwardZoneInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneInstanceEnumeration::Linux_DnsForwardZoneInstanceEnumeration(
    const Linux_DnsForwardZoneInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsForwardZoneInstanceEnumeration::~Linux_DnsForwardZoneInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardZoneInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsForwardZoneInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsForwardZoneInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsForwardZoneInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsForwardZoneInstance&  
  Linux_DnsForwardZoneInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsForwardZoneInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsForwardZoneInstance&
  Linux_DnsForwardZoneInstanceEnumeration::getNext() {
   	
    Linux_DnsForwardZoneInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsForwardZoneInstanceEnumeration::addElement(
    const Linux_DnsForwardZoneInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsForwardZoneInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsForwardZoneInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsForwardZoneInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsForwardZoneInstance(anInstance);
  	}

  }
  
}
