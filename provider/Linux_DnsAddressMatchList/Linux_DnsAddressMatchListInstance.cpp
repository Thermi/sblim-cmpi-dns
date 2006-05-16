// =======================================================================
// Linux_DnsAddressMatchListInstance.cpp
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

    cmpiData = aCmpiInstance.getProperty("AddressListType");
    if ( ! cmpiData.isNullValue()){
      CMPIUint16 AddressListType = cmpiData;
      setAddressListType(AddressListType);
    }

    cmpiData = aCmpiInstance.getProperty("AddressList");
    if ( ! cmpiData.isNullValue()){
      CmpiArray AddressList = cmpiData;
    unsigned int AddressListSize;
    const char** AddressListArray;
    ArrayConverter::makeArray(
      AddressList, 
      (char***)&AddressListArray, 
      AddressListSize);
      setAddressList(AddressListArray, AddressListSize, 0);
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

    cmpiData = aCmpiInstance.getProperty("SettingID");
    if ( ! cmpiData.isNullValue()){
      CmpiString SettingID = cmpiData;
      setSettingID(SettingID.charPtr());
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

  	if (isSet.AddressListType) {
  	  
  	  cmpiInstance.setProperty(
  	    "AddressListType",
  	    CmpiData(m_AddressListType));
  	}

  	if (isSet.AddressList) {
  	  
      unsigned int AddressListSize;
      const char** arrayAddressList = getAddressList(AddressListSize);
      CmpiArray cmpiArrayAddressList = CmpiArray(
        AddressListSize,
        CMPI_chars);
      for (unsigned int x=0; x < AddressListSize; ++x) {
        cmpiArrayAddressList[x] = CmpiData(arrayAddressList[x]);
      }
  	  cmpiInstance.setProperty(
  	    "AddressList",
  	    CmpiData(cmpiArrayAddressList));
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

  	if (isSet.SettingID) {
  	  
  	  cmpiInstance.setProperty(
  	    "SettingID",
  	    CmpiData(m_SettingID));
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
  // AddressListType related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsAddressMatchListInstance::isAddressListTypeSet() const {
    return isSet.AddressListType;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsAddressMatchListInstance::setAddressListType(
    const CMPIUint16 aValue) {
  
    m_AddressListType = aValue;
    isSet.AddressListType = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16
  Linux_DnsAddressMatchListInstance::getAddressListType() const {
    
    if ( ! isSet.AddressListType) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "AddressListType",
        "Linux_DnsAddressMatchList");
   	}


    return m_AddressListType;

  }
       
  //----------------------------------------------------------------------------
  // AddressList related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsAddressMatchListInstance::isAddressListSet() const {
    return isSet.AddressList;
  }

  //----------------------------------------------------------------------------
  void  
  Linux_DnsAddressMatchListInstance::setAddressList(
    const char** aValuePP, 
    const unsigned int aSize,
    int aCopyFlag) {
    
    if (isSet.AddressList) {
      delete m_AddressList;
    }
    
    if (aCopyFlag && aValuePP) {
      m_AddressList = new const char*[aSize];
      for (unsigned int x=0; x < aSize; ++x) {
        char* stringP = new char[strlen(aValuePP[x])+1];
        strcpy(stringP,aValuePP[x]);
        m_AddressList[x] = stringP;
      }      
    } else {
      m_AddressList = aValuePP;
    }
    
    m_AddressListSize = aSize;
    
    isSet.AddressList = 1;
    
  }       

  //----------------------------------------------------------------------------
  const char**
  Linux_DnsAddressMatchListInstance::getAddressList(unsigned int& aSize) const {
    
    if ( ! isSet.AddressList) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "AddressList",
        "Linux_DnsAddressMatchList");
   	}

    aSize = m_AddressListSize;
    return m_AddressList;

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
  // SettingID related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsAddressMatchListInstance::isSettingIDSet() const {
    return isSet.SettingID;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListInstance::setSettingID(
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
  Linux_DnsAddressMatchListInstance::getSettingID() const {
    
    if ( ! isSet.SettingID) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "SettingID",
        "Linux_DnsAddressMatchList");
   	}


    return m_SettingID;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListInstance::init() {
   	isSet.instanceName = 0;
    isSet.AddressListType = 0;
    isSet.AddressList = 0;
    m_AddressListSize = 0;
    isSet.Caption = 0;
    isSet.Description = 0;
    isSet.ElementName = 0;
    isSet.SettingID = 0;
  	
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
       	
    if (anOriginal.isAddressListTypeSet()) {
      const CMPIUint16 AddressListTypeOriginal = anOriginal.getAddressListType();
      setAddressListType(AddressListTypeOriginal);
    }
   	
    if (anOriginal.isAddressListSet()) {
      unsigned int sizeAddressList;
      const char** AddressListOriginal = anOriginal.getAddressList(sizeAddressList);
      setAddressList(AddressListOriginal, sizeAddressList,1);
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
   	
    if (anOriginal.isSettingIDSet()) {
      const char* SettingIDOriginal = anOriginal.getSettingID();
      setSettingID(SettingIDOriginal,1);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsAddressMatchListInstance::reset() {
   	
  	if (isSet.AddressList) {
  	  ArrayConverter::destructArray((char**)m_AddressList,m_AddressListSize);
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

  	if (isSet.SettingID) {
  	  delete(m_SettingID);
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
