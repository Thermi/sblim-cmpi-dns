// =======================================================================
// CIM_ManagedSystemElementInstance.cpp
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
#include "CIM_ManagedSystemElementInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //CIM_ManagedSystemElementInstance
  //----------------------------------------------------------------------------
  //empty constructor
  CIM_ManagedSystemElementInstance::CIM_ManagedSystemElementInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  CIM_ManagedSystemElementInstance::CIM_ManagedSystemElementInstance(
    const CIM_ManagedSystemElementInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  CIM_ManagedSystemElementInstance::CIM_ManagedSystemElementInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(CIM_ManagedSystemElementInstanceName(cop));

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

    cmpiData = aCmpiInstance.getProperty("InstallDate");
    if ( ! cmpiData.isNullValue()){
      CmpiDateTime InstallDate = cmpiData;
      setInstallDate(InstallDate);
    }

    cmpiData = aCmpiInstance.getProperty("Name");
    if ( ! cmpiData.isNullValue()){
      CmpiString Name = cmpiData;
      setName(Name.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("OperationalStatus");
    if ( ! cmpiData.isNullValue()){
      CmpiArray OperationalStatus = cmpiData;
    unsigned int OperationalStatusSize;
    const CMPIUint16* OperationalStatusArray;
    ArrayConverter::makeArray(
      OperationalStatus, 
      (CMPIUint16**)&OperationalStatusArray, 
      OperationalStatusSize);
      setOperationalStatus(OperationalStatusArray, OperationalStatusSize, 0);
    }

    cmpiData = aCmpiInstance.getProperty("Status");
    if ( ! cmpiData.isNullValue()){
      CmpiString Status = cmpiData;
      setStatus(Status.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("StatusDescriptions");
    if ( ! cmpiData.isNullValue()){
      CmpiArray StatusDescriptions = cmpiData;
    unsigned int StatusDescriptionsSize;
    const char** StatusDescriptionsArray;
    ArrayConverter::makeArray(
      StatusDescriptions, 
      (char***)&StatusDescriptionsArray, 
      StatusDescriptionsSize);
      setStatusDescriptions(StatusDescriptionsArray, StatusDescriptionsSize, 0);
    }

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  CIM_ManagedSystemElementInstance::
   ~CIM_ManagedSystemElementInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  CIM_ManagedSystemElementInstance&
  CIM_ManagedSystemElementInstance::operator=(
    const CIM_ManagedSystemElementInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  CIM_ManagedSystemElementInstance::getCmpiInstance(
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

  	if (isSet.InstallDate) {
  	  
  	  cmpiInstance.setProperty(
  	    "InstallDate",
  	    CmpiData(m_InstallDate));
  	}

  	if (isSet.Name) {
  	  
  	  cmpiInstance.setProperty(
  	    "Name",
  	    CmpiData(m_Name));
  	}

  	if (isSet.OperationalStatus) {
  	  
      unsigned int OperationalStatusSize;
      const CMPIUint16* arrayOperationalStatus = getOperationalStatus(OperationalStatusSize);
      CmpiArray cmpiArrayOperationalStatus = CmpiArray(
        OperationalStatusSize,
        CMPI_uint16);
      for (unsigned int x=0; x < OperationalStatusSize; ++x) {
        cmpiArrayOperationalStatus[x] = CmpiData(arrayOperationalStatus[x]);
      }
  	  cmpiInstance.setProperty(
  	    "OperationalStatus",
  	    CmpiData(cmpiArrayOperationalStatus));
  	}

  	if (isSet.Status) {
  	  
  	  cmpiInstance.setProperty(
  	    "Status",
  	    CmpiData(m_Status));
  	}

  	if (isSet.StatusDescriptions) {
  	  
      unsigned int StatusDescriptionsSize;
      const char** arrayStatusDescriptions = getStatusDescriptions(StatusDescriptionsSize);
      CmpiArray cmpiArrayStatusDescriptions = CmpiArray(
        StatusDescriptionsSize,
        CMPI_chars);
      for (unsigned int x=0; x < StatusDescriptionsSize; ++x) {
        cmpiArrayStatusDescriptions[x] = CmpiData(arrayStatusDescriptions[x]);
      }
  	  cmpiInstance.setProperty(
  	    "StatusDescriptions",
  	    CmpiData(cmpiArrayStatusDescriptions));
  	}

  	
  	return cmpiInstance;
  	
  }
  
  //----------------------------------------------------------------------------
  // InstanceName related methods
  //----------------------------------------------------------------------------
  unsigned int 
  CIM_ManagedSystemElementInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const CIM_ManagedSystemElementInstanceName&
  CIM_ManagedSystemElementInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "CIM_ManagedSystemElement");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  CIM_ManagedSystemElementInstance::setInstanceName(
    const CIM_ManagedSystemElementInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // Caption related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ManagedSystemElementInstance::isCaptionSet() const {
    return isSet.Caption;
  }

  //----------------------------------------------------------------------------
  void
  CIM_ManagedSystemElementInstance::setCaption(
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
  CIM_ManagedSystemElementInstance::getCaption() const {
    
    if ( ! isSet.Caption) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Caption",
        "CIM_ManagedSystemElement");
   	}


    return m_Caption;

  }
       
  //----------------------------------------------------------------------------
  // Description related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ManagedSystemElementInstance::isDescriptionSet() const {
    return isSet.Description;
  }

  //----------------------------------------------------------------------------
  void
  CIM_ManagedSystemElementInstance::setDescription(
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
  CIM_ManagedSystemElementInstance::getDescription() const {
    
    if ( ! isSet.Description) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Description",
        "CIM_ManagedSystemElement");
   	}


    return m_Description;

  }
       
  //----------------------------------------------------------------------------
  // ElementName related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ManagedSystemElementInstance::isElementNameSet() const {
    return isSet.ElementName;
  }

  //----------------------------------------------------------------------------
  void
  CIM_ManagedSystemElementInstance::setElementName(
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
  CIM_ManagedSystemElementInstance::getElementName() const {
    
    if ( ! isSet.ElementName) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ElementName",
        "CIM_ManagedSystemElement");
   	}


    return m_ElementName;

  }
       
  //----------------------------------------------------------------------------
  // InstallDate related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ManagedSystemElementInstance::isInstallDateSet() const {
    return isSet.InstallDate;
  }

  //----------------------------------------------------------------------------
  void CIM_ManagedSystemElementInstance::setInstallDate(
    const CmpiDateTime& aValue) {
  
    m_InstallDate = aValue;
    isSet.InstallDate = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CmpiDateTime&
  CIM_ManagedSystemElementInstance::getInstallDate() const {
    
    if ( ! isSet.InstallDate) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "InstallDate",
        "CIM_ManagedSystemElement");
   	}


    return m_InstallDate;

  }
       
  //----------------------------------------------------------------------------
  // Name related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ManagedSystemElementInstance::isNameSet() const {
    return isSet.Name;
  }

  //----------------------------------------------------------------------------
  void
  CIM_ManagedSystemElementInstance::setName(
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
  CIM_ManagedSystemElementInstance::getName() const {
    
    if ( ! isSet.Name) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Name",
        "CIM_ManagedSystemElement");
   	}


    return m_Name;

  }
       
  //----------------------------------------------------------------------------
  // OperationalStatus related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ManagedSystemElementInstance::isOperationalStatusSet() const {
    return isSet.OperationalStatus;
  }

  //----------------------------------------------------------------------------
  void CIM_ManagedSystemElementInstance::setOperationalStatus(
    const CMPIUint16* aValueP,
    const unsigned int aSize,
    int aCopyFlag) {
    
    if (isSet.OperationalStatus) {
      delete []m_OperationalStatus;
    }
    
    if (aCopyFlag && aValueP) {
      CMPIUint16* arrayP = new CMPIUint16[aSize];
      for(unsigned int x=0; x < aSize; ++x) {
        arrayP[x] = aValueP[x];
      }
      m_OperationalStatus = arrayP;
    } else {
      m_OperationalStatus = aValueP;
    }
    
    m_OperationalStatusSize = aSize;

    isSet.OperationalStatus = 1;
    
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16*
  CIM_ManagedSystemElementInstance::getOperationalStatus(unsigned int& aSize) const {
    
    if ( ! isSet.OperationalStatus) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "OperationalStatus",
        "CIM_ManagedSystemElement");
   	}

    aSize = m_OperationalStatusSize;
    return m_OperationalStatus;

  }
       
  //----------------------------------------------------------------------------
  // Status related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ManagedSystemElementInstance::isStatusSet() const {
    return isSet.Status;
  }

  //----------------------------------------------------------------------------
  void
  CIM_ManagedSystemElementInstance::setStatus(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.Status) {
      delete [] m_Status;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_Status = valueP;
    } else {
      m_Status = aValueP;
    }
    
    isSet.Status = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  CIM_ManagedSystemElementInstance::getStatus() const {
    
    if ( ! isSet.Status) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Status",
        "CIM_ManagedSystemElement");
   	}


    return m_Status;

  }
       
  //----------------------------------------------------------------------------
  // StatusDescriptions related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ManagedSystemElementInstance::isStatusDescriptionsSet() const {
    return isSet.StatusDescriptions;
  }

  //----------------------------------------------------------------------------
  void  
  CIM_ManagedSystemElementInstance::setStatusDescriptions(
    const char** aValuePP, 
    const unsigned int aSize,
    int aCopyFlag) {
    
    if (isSet.StatusDescriptions) {
      delete m_StatusDescriptions;
    }
    
    if (aCopyFlag && aValuePP) {
      m_StatusDescriptions = new const char*[aSize];
      for (unsigned int x=0; x < aSize; ++x) {
        char* stringP = new char[strlen(aValuePP[x])+1];
        strcpy(stringP,aValuePP[x]);
        m_StatusDescriptions[x] = stringP;
      }      
    } else {
      m_StatusDescriptions = aValuePP;
    }
    
    m_StatusDescriptionsSize = aSize;
    
    isSet.StatusDescriptions = 1;
    
  }       

  //----------------------------------------------------------------------------
  const char**
  CIM_ManagedSystemElementInstance::getStatusDescriptions(unsigned int& aSize) const {
    
    if ( ! isSet.StatusDescriptions) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "StatusDescriptions",
        "CIM_ManagedSystemElement");
   	}

    aSize = m_StatusDescriptionsSize;
    return m_StatusDescriptions;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  CIM_ManagedSystemElementInstance::init() {
   	isSet.instanceName = 0;
    isSet.Caption = 0;
    isSet.Description = 0;
    isSet.ElementName = 0;
    isSet.InstallDate = 0;
    isSet.Name = 0;
    isSet.OperationalStatus = 0;
    m_OperationalStatusSize = 0;
    isSet.Status = 0;
    isSet.StatusDescriptions = 0;
    m_StatusDescriptionsSize = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  CIM_ManagedSystemElementInstance::init(
    const CIM_ManagedSystemElementInstance& anOriginal) {   	

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
   	
    if (anOriginal.isInstallDateSet()) {
      const CmpiDateTime& InstallDateOriginal = anOriginal.getInstallDate();
      setInstallDate(InstallDateOriginal);
    }
   	
    if (anOriginal.isNameSet()) {
      const char* NameOriginal = anOriginal.getName();
      setName(NameOriginal,1);
    }
   	
    if (anOriginal.isOperationalStatusSet()) {
      unsigned int sizeOperationalStatus;
      const CMPIUint16* OperationalStatusOriginal = anOriginal.getOperationalStatus(sizeOperationalStatus);
      setOperationalStatus(OperationalStatusOriginal, sizeOperationalStatus,1);
    }
   	
    if (anOriginal.isStatusSet()) {
      const char* StatusOriginal = anOriginal.getStatus();
      setStatus(StatusOriginal,1);
    }
   	
    if (anOriginal.isStatusDescriptionsSet()) {
      unsigned int sizeStatusDescriptions;
      const char** StatusDescriptionsOriginal = anOriginal.getStatusDescriptions(sizeStatusDescriptions);
      setStatusDescriptions(StatusDescriptionsOriginal, sizeStatusDescriptions,1);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  CIM_ManagedSystemElementInstance::reset() {
   	
  	if (isSet.Caption) {
  	  delete(m_Caption);
  	}

  	if (isSet.Description) {
  	  delete(m_Description);
  	}

  	if (isSet.ElementName) {
  	  delete(m_ElementName);
  	}

  	if (isSet.Name) {
  	  delete(m_Name);
  	}

  	if (isSet.OperationalStatus) {
  	  ArrayConverter::destructArray((CMPIUint16*)m_OperationalStatus);
  	}

  	if (isSet.Status) {
  	  delete(m_Status);
  	}

  	if (isSet.StatusDescriptions) {
  	  ArrayConverter::destructArray((char**)m_StatusDescriptions,m_StatusDescriptionsSize);
  	}

  }
  
  //----------------------------------------------------------------------------
  //CIM_ManagedSystemElementInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  CIM_ManagedSystemElementInstanceEnumerationElement::CIM_ManagedSystemElementInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  CIM_ManagedSystemElementInstanceEnumerationElement::~CIM_ManagedSystemElementInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //CIM_ManagedSystemElementInstanceNameEnumeration
  //----------------------------------------------------------------------------
  CIM_ManagedSystemElementInstanceEnumeration::CIM_ManagedSystemElementInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  CIM_ManagedSystemElementInstanceEnumeration::CIM_ManagedSystemElementInstanceEnumeration(
    const CIM_ManagedSystemElementInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  CIM_ManagedSystemElementInstanceEnumeration::~CIM_ManagedSystemElementInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  CIM_ManagedSystemElementInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  CIM_ManagedSystemElementInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  CIM_ManagedSystemElementInstanceEnumeration::getSize() const {
  	
    int size = 0;
    CIM_ManagedSystemElementInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const CIM_ManagedSystemElementInstance&  
  CIM_ManagedSystemElementInstanceEnumeration::getElement(int anIndex) const {
   
    CIM_ManagedSystemElementInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const CIM_ManagedSystemElementInstance&
  CIM_ManagedSystemElementInstanceEnumeration::getNext() {
   	
    CIM_ManagedSystemElementInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  CIM_ManagedSystemElementInstanceEnumeration::addElement(
    const CIM_ManagedSystemElementInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new CIM_ManagedSystemElementInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new CIM_ManagedSystemElementInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new CIM_ManagedSystemElementInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new CIM_ManagedSystemElementInstance(anInstance);
  	}

  }
  
}
