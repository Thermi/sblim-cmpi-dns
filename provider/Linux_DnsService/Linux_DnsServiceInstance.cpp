// =======================================================================
// Linux_DnsServiceInstance.cpp
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
#include "Linux_DnsServiceInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //Linux_DnsServiceInstance
  //----------------------------------------------------------------------------
  //empty constructor
  Linux_DnsServiceInstance::Linux_DnsServiceInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  Linux_DnsServiceInstance::Linux_DnsServiceInstance(
    const Linux_DnsServiceInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  Linux_DnsServiceInstance::Linux_DnsServiceInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(Linux_DnsServiceInstanceName(cop));

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

    cmpiData = aCmpiInstance.getProperty("EnabledDefault");
    if ( ! cmpiData.isNullValue()){
      CMPIUint16 EnabledDefault = cmpiData;
      setEnabledDefault(EnabledDefault);
    }

    cmpiData = aCmpiInstance.getProperty("EnabledState");
    if ( ! cmpiData.isNullValue()){
      CMPIUint16 EnabledState = cmpiData;
      setEnabledState(EnabledState);
    }

    cmpiData = aCmpiInstance.getProperty("InstallDate");
    if ( ! cmpiData.isNullValue()){
      CmpiDateTime InstallDate = cmpiData;
      setInstallDate(InstallDate);
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

    cmpiData = aCmpiInstance.getProperty("OtherEnabledState");
    if ( ! cmpiData.isNullValue()){
      CmpiString OtherEnabledState = cmpiData;
      setOtherEnabledState(OtherEnabledState.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("PrimaryOwnerContact");
    if ( ! cmpiData.isNullValue()){
      CmpiString PrimaryOwnerContact = cmpiData;
      setPrimaryOwnerContact(PrimaryOwnerContact.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("PrimaryOwnerName");
    if ( ! cmpiData.isNullValue()){
      CmpiString PrimaryOwnerName = cmpiData;
      setPrimaryOwnerName(PrimaryOwnerName.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("RequestedState");
    if ( ! cmpiData.isNullValue()){
      CMPIUint16 RequestedState = cmpiData;
      setRequestedState(RequestedState);
    }

    cmpiData = aCmpiInstance.getProperty("RunAsRoot");
    if ( ! cmpiData.isNullValue()){
      CMPIBoolean RunAsRoot = cmpiData;
      setRunAsRoot(RunAsRoot);
    }

    cmpiData = aCmpiInstance.getProperty("StartMode");
    if ( ! cmpiData.isNullValue()){
      CmpiString StartMode = cmpiData;
      setStartMode(StartMode.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("Started");
    if ( ! cmpiData.isNullValue()){
      CMPIBoolean Started = cmpiData;
      setStarted(Started);
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

    cmpiData = aCmpiInstance.getProperty("TimeOfLastStateChange");
    if ( ! cmpiData.isNullValue()){
      CmpiDateTime TimeOfLastStateChange = cmpiData;
      setTimeOfLastStateChange(TimeOfLastStateChange);
    }

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  Linux_DnsServiceInstance::
   ~Linux_DnsServiceInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  Linux_DnsServiceInstance&
  Linux_DnsServiceInstance::operator=(
    const Linux_DnsServiceInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  Linux_DnsServiceInstance::getCmpiInstance(
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

  	if (isSet.EnabledDefault) {
  	  
  	  cmpiInstance.setProperty(
  	    "EnabledDefault",
  	    CmpiData(m_EnabledDefault));
  	}

  	if (isSet.EnabledState) {
  	  
  	  cmpiInstance.setProperty(
  	    "EnabledState",
  	    CmpiData(m_EnabledState));
  	}

  	if (isSet.InstallDate) {
  	  
  	  cmpiInstance.setProperty(
  	    "InstallDate",
  	    CmpiData(m_InstallDate));
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

  	if (isSet.OtherEnabledState) {
  	  
  	  cmpiInstance.setProperty(
  	    "OtherEnabledState",
  	    CmpiData(m_OtherEnabledState));
  	}

  	if (isSet.PrimaryOwnerContact) {
  	  
  	  cmpiInstance.setProperty(
  	    "PrimaryOwnerContact",
  	    CmpiData(m_PrimaryOwnerContact));
  	}

  	if (isSet.PrimaryOwnerName) {
  	  
  	  cmpiInstance.setProperty(
  	    "PrimaryOwnerName",
  	    CmpiData(m_PrimaryOwnerName));
  	}

  	if (isSet.RequestedState) {
  	  
  	  cmpiInstance.setProperty(
  	    "RequestedState",
  	    CmpiData(m_RequestedState));
  	}

  	if (isSet.RunAsRoot) {
  	  
  	  cmpiInstance.setProperty(
  	    "RunAsRoot",
  	    CmpiBooleanData(m_RunAsRoot));
  	}

  	if (isSet.StartMode) {
  	  
  	  cmpiInstance.setProperty(
  	    "StartMode",
  	    CmpiData(m_StartMode));
  	}

  	if (isSet.Started) {
  	  
  	  cmpiInstance.setProperty(
  	    "Started",
  	    CmpiBooleanData(m_Started));
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

  	if (isSet.TimeOfLastStateChange) {
  	  
  	  cmpiInstance.setProperty(
  	    "TimeOfLastStateChange",
  	    CmpiData(m_TimeOfLastStateChange));
  	}

  	
  	return cmpiInstance;
  	
  }
  
  //----------------------------------------------------------------------------
  // InstanceName related methods
  //----------------------------------------------------------------------------
  unsigned int 
  Linux_DnsServiceInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceInstanceName&
  Linux_DnsServiceInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "Linux_DnsService");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceInstance::setInstanceName(
    const Linux_DnsServiceInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // Caption related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceInstance::isCaptionSet() const {
    return isSet.Caption;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceInstance::setCaption(
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
  Linux_DnsServiceInstance::getCaption() const {
    
    if ( ! isSet.Caption) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Caption",
        "Linux_DnsService");
   	}


    return m_Caption;

  }
       
  //----------------------------------------------------------------------------
  // Description related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceInstance::isDescriptionSet() const {
    return isSet.Description;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceInstance::setDescription(
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
  Linux_DnsServiceInstance::getDescription() const {
    
    if ( ! isSet.Description) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Description",
        "Linux_DnsService");
   	}


    return m_Description;

  }
       
  //----------------------------------------------------------------------------
  // ElementName related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceInstance::isElementNameSet() const {
    return isSet.ElementName;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceInstance::setElementName(
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
  Linux_DnsServiceInstance::getElementName() const {
    
    if ( ! isSet.ElementName) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ElementName",
        "Linux_DnsService");
   	}


    return m_ElementName;

  }
       
  //----------------------------------------------------------------------------
  // EnabledDefault related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceInstance::isEnabledDefaultSet() const {
    return isSet.EnabledDefault;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceInstance::setEnabledDefault(
    const CMPIUint16 aValue) {
  
    m_EnabledDefault = aValue;
    isSet.EnabledDefault = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16
  Linux_DnsServiceInstance::getEnabledDefault() const {
    
    if ( ! isSet.EnabledDefault) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "EnabledDefault",
        "Linux_DnsService");
   	}


    return m_EnabledDefault;

  }
       
  //----------------------------------------------------------------------------
  // EnabledState related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceInstance::isEnabledStateSet() const {
    return isSet.EnabledState;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceInstance::setEnabledState(
    const CMPIUint16 aValue) {
  
    m_EnabledState = aValue;
    isSet.EnabledState = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16
  Linux_DnsServiceInstance::getEnabledState() const {
    
    if ( ! isSet.EnabledState) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "EnabledState",
        "Linux_DnsService");
   	}


    return m_EnabledState;

  }
       
  //----------------------------------------------------------------------------
  // InstallDate related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceInstance::isInstallDateSet() const {
    return isSet.InstallDate;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceInstance::setInstallDate(
    const CmpiDateTime& aValue) {
  
    m_InstallDate = aValue;
    isSet.InstallDate = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CmpiDateTime&
  Linux_DnsServiceInstance::getInstallDate() const {
    
    if ( ! isSet.InstallDate) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "InstallDate",
        "Linux_DnsService");
   	}


    return m_InstallDate;

  }
       
  //----------------------------------------------------------------------------
  // OperationalStatus related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceInstance::isOperationalStatusSet() const {
    return isSet.OperationalStatus;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceInstance::setOperationalStatus(
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
  Linux_DnsServiceInstance::getOperationalStatus(unsigned int& aSize) const {
    
    if ( ! isSet.OperationalStatus) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "OperationalStatus",
        "Linux_DnsService");
   	}

    aSize = m_OperationalStatusSize;
    return m_OperationalStatus;

  }
       
  //----------------------------------------------------------------------------
  // OtherEnabledState related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceInstance::isOtherEnabledStateSet() const {
    return isSet.OtherEnabledState;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceInstance::setOtherEnabledState(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.OtherEnabledState) {
      delete [] m_OtherEnabledState;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_OtherEnabledState = valueP;
    } else {
      m_OtherEnabledState = aValueP;
    }
    
    isSet.OtherEnabledState = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsServiceInstance::getOtherEnabledState() const {
    
    if ( ! isSet.OtherEnabledState) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "OtherEnabledState",
        "Linux_DnsService");
   	}


    return m_OtherEnabledState;

  }
       
  //----------------------------------------------------------------------------
  // PrimaryOwnerContact related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceInstance::isPrimaryOwnerContactSet() const {
    return isSet.PrimaryOwnerContact;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceInstance::setPrimaryOwnerContact(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.PrimaryOwnerContact) {
      delete [] m_PrimaryOwnerContact;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_PrimaryOwnerContact = valueP;
    } else {
      m_PrimaryOwnerContact = aValueP;
    }
    
    isSet.PrimaryOwnerContact = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsServiceInstance::getPrimaryOwnerContact() const {
    
    if ( ! isSet.PrimaryOwnerContact) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "PrimaryOwnerContact",
        "Linux_DnsService");
   	}


    return m_PrimaryOwnerContact;

  }
       
  //----------------------------------------------------------------------------
  // PrimaryOwnerName related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceInstance::isPrimaryOwnerNameSet() const {
    return isSet.PrimaryOwnerName;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceInstance::setPrimaryOwnerName(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.PrimaryOwnerName) {
      delete [] m_PrimaryOwnerName;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_PrimaryOwnerName = valueP;
    } else {
      m_PrimaryOwnerName = aValueP;
    }
    
    isSet.PrimaryOwnerName = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsServiceInstance::getPrimaryOwnerName() const {
    
    if ( ! isSet.PrimaryOwnerName) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "PrimaryOwnerName",
        "Linux_DnsService");
   	}


    return m_PrimaryOwnerName;

  }
       
  //----------------------------------------------------------------------------
  // RequestedState related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceInstance::isRequestedStateSet() const {
    return isSet.RequestedState;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceInstance::setRequestedState(
    const CMPIUint16 aValue) {
  
    m_RequestedState = aValue;
    isSet.RequestedState = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16
  Linux_DnsServiceInstance::getRequestedState() const {
    
    if ( ! isSet.RequestedState) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "RequestedState",
        "Linux_DnsService");
   	}


    return m_RequestedState;

  }
       
  //----------------------------------------------------------------------------
  // RunAsRoot related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceInstance::isRunAsRootSet() const {
    return isSet.RunAsRoot;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceInstance::setRunAsRoot(
    const CMPIBoolean aValue) {
  
    m_RunAsRoot = aValue;
    isSet.RunAsRoot = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIBoolean
  Linux_DnsServiceInstance::getRunAsRoot() const {
    
    if ( ! isSet.RunAsRoot) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "RunAsRoot",
        "Linux_DnsService");
   	}


    return m_RunAsRoot;

  }
       
  //----------------------------------------------------------------------------
  // StartMode related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceInstance::isStartModeSet() const {
    return isSet.StartMode;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceInstance::setStartMode(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.StartMode) {
      delete [] m_StartMode;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_StartMode = valueP;
    } else {
      m_StartMode = aValueP;
    }
    
    isSet.StartMode = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  Linux_DnsServiceInstance::getStartMode() const {
    
    if ( ! isSet.StartMode) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "StartMode",
        "Linux_DnsService");
   	}


    return m_StartMode;

  }
       
  //----------------------------------------------------------------------------
  // Started related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceInstance::isStartedSet() const {
    return isSet.Started;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceInstance::setStarted(
    const CMPIBoolean aValue) {
  
    m_Started = aValue;
    isSet.Started = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIBoolean
  Linux_DnsServiceInstance::getStarted() const {
    
    if ( ! isSet.Started) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Started",
        "Linux_DnsService");
   	}


    return m_Started;

  }
       
  //----------------------------------------------------------------------------
  // Status related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceInstance::isStatusSet() const {
    return isSet.Status;
  }

  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceInstance::setStatus(
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
  Linux_DnsServiceInstance::getStatus() const {
    
    if ( ! isSet.Status) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Status",
        "Linux_DnsService");
   	}


    return m_Status;

  }
       
  //----------------------------------------------------------------------------
  // StatusDescriptions related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceInstance::isStatusDescriptionsSet() const {
    return isSet.StatusDescriptions;
  }

  //----------------------------------------------------------------------------
  void  
  Linux_DnsServiceInstance::setStatusDescriptions(
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
  Linux_DnsServiceInstance::getStatusDescriptions(unsigned int& aSize) const {
    
    if ( ! isSet.StatusDescriptions) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "StatusDescriptions",
        "Linux_DnsService");
   	}

    aSize = m_StatusDescriptionsSize;
    return m_StatusDescriptions;

  }
       
  //----------------------------------------------------------------------------
  // TimeOfLastStateChange related methods
  //----------------------------------------------------------------------------
  unsigned int
  Linux_DnsServiceInstance::isTimeOfLastStateChangeSet() const {
    return isSet.TimeOfLastStateChange;
  }

  //----------------------------------------------------------------------------
  void Linux_DnsServiceInstance::setTimeOfLastStateChange(
    const CmpiDateTime& aValue) {
  
    m_TimeOfLastStateChange = aValue;
    isSet.TimeOfLastStateChange = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CmpiDateTime&
  Linux_DnsServiceInstance::getTimeOfLastStateChange() const {
    
    if ( ! isSet.TimeOfLastStateChange) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "TimeOfLastStateChange",
        "Linux_DnsService");
   	}


    return m_TimeOfLastStateChange;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceInstance::init() {
   	isSet.instanceName = 0;
    isSet.Caption = 0;
    isSet.Description = 0;
    isSet.ElementName = 0;
    isSet.EnabledDefault = 0;
    isSet.EnabledState = 0;
    isSet.InstallDate = 0;
    isSet.OperationalStatus = 0;
    m_OperationalStatusSize = 0;
    isSet.OtherEnabledState = 0;
    isSet.PrimaryOwnerContact = 0;
    isSet.PrimaryOwnerName = 0;
    isSet.RequestedState = 0;
    isSet.RunAsRoot = 0;
    isSet.StartMode = 0;
    isSet.Started = 0;
    isSet.Status = 0;
    isSet.StatusDescriptions = 0;
    m_StatusDescriptionsSize = 0;
    isSet.TimeOfLastStateChange = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  Linux_DnsServiceInstance::init(
    const Linux_DnsServiceInstance& anOriginal) {   	

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
   	
    if (anOriginal.isEnabledDefaultSet()) {
      const CMPIUint16 EnabledDefaultOriginal = anOriginal.getEnabledDefault();
      setEnabledDefault(EnabledDefaultOriginal);
    }
   	
    if (anOriginal.isEnabledStateSet()) {
      const CMPIUint16 EnabledStateOriginal = anOriginal.getEnabledState();
      setEnabledState(EnabledStateOriginal);
    }
   	
    if (anOriginal.isInstallDateSet()) {
      const CmpiDateTime& InstallDateOriginal = anOriginal.getInstallDate();
      setInstallDate(InstallDateOriginal);
    }
   	
    if (anOriginal.isOperationalStatusSet()) {
      unsigned int sizeOperationalStatus;
      const CMPIUint16* OperationalStatusOriginal = anOriginal.getOperationalStatus(sizeOperationalStatus);
      setOperationalStatus(OperationalStatusOriginal, sizeOperationalStatus,1);
    }
   	
    if (anOriginal.isOtherEnabledStateSet()) {
      const char* OtherEnabledStateOriginal = anOriginal.getOtherEnabledState();
      setOtherEnabledState(OtherEnabledStateOriginal,1);
    }
   	
    if (anOriginal.isPrimaryOwnerContactSet()) {
      const char* PrimaryOwnerContactOriginal = anOriginal.getPrimaryOwnerContact();
      setPrimaryOwnerContact(PrimaryOwnerContactOriginal,1);
    }
   	
    if (anOriginal.isPrimaryOwnerNameSet()) {
      const char* PrimaryOwnerNameOriginal = anOriginal.getPrimaryOwnerName();
      setPrimaryOwnerName(PrimaryOwnerNameOriginal,1);
    }
   	
    if (anOriginal.isRequestedStateSet()) {
      const CMPIUint16 RequestedStateOriginal = anOriginal.getRequestedState();
      setRequestedState(RequestedStateOriginal);
    }
   	
    if (anOriginal.isRunAsRootSet()) {
      const CMPIBoolean RunAsRootOriginal = anOriginal.getRunAsRoot();
      setRunAsRoot(RunAsRootOriginal);
    }
   	
    if (anOriginal.isStartModeSet()) {
      const char* StartModeOriginal = anOriginal.getStartMode();
      setStartMode(StartModeOriginal,1);
    }
   	
    if (anOriginal.isStartedSet()) {
      const CMPIBoolean StartedOriginal = anOriginal.getStarted();
      setStarted(StartedOriginal);
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
   	
    if (anOriginal.isTimeOfLastStateChangeSet()) {
      const CmpiDateTime& TimeOfLastStateChangeOriginal = anOriginal.getTimeOfLastStateChange();
      setTimeOfLastStateChange(TimeOfLastStateChangeOriginal);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceInstance::reset() {
   	
  	if (isSet.Caption) {
  	  delete(m_Caption);
  	}

  	if (isSet.Description) {
  	  delete(m_Description);
  	}

  	if (isSet.ElementName) {
  	  delete(m_ElementName);
  	}

  	if (isSet.OperationalStatus) {
  	  ArrayConverter::destructArray((CMPIUint16*)m_OperationalStatus);
  	}

  	if (isSet.OtherEnabledState) {
  	  delete(m_OtherEnabledState);
  	}

  	if (isSet.PrimaryOwnerContact) {
  	  delete(m_PrimaryOwnerContact);
  	}

  	if (isSet.PrimaryOwnerName) {
  	  delete(m_PrimaryOwnerName);
  	}

  	if (isSet.StartMode) {
  	  delete(m_StartMode);
  	}

  	if (isSet.Status) {
  	  delete(m_Status);
  	}

  	if (isSet.StatusDescriptions) {
  	  ArrayConverter::destructArray((char**)m_StatusDescriptions,m_StatusDescriptionsSize);
  	}

  }
  
  //----------------------------------------------------------------------------
  //Linux_DnsServiceInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  Linux_DnsServiceInstanceEnumerationElement::Linux_DnsServiceInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceInstanceEnumerationElement::~Linux_DnsServiceInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //Linux_DnsServiceInstanceNameEnumeration
  //----------------------------------------------------------------------------
  Linux_DnsServiceInstanceEnumeration::Linux_DnsServiceInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceInstanceEnumeration::Linux_DnsServiceInstanceEnumeration(
    const Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  Linux_DnsServiceInstanceEnumeration::~Linux_DnsServiceInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  Linux_DnsServiceInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  Linux_DnsServiceInstanceEnumeration::getSize() const {
  	
    int size = 0;
    Linux_DnsServiceInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceInstance&  
  Linux_DnsServiceInstanceEnumeration::getElement(int anIndex) const {
   
    Linux_DnsServiceInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const Linux_DnsServiceInstance&
  Linux_DnsServiceInstanceEnumeration::getNext() {
   	
    Linux_DnsServiceInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  Linux_DnsServiceInstanceEnumeration::addElement(
    const Linux_DnsServiceInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new Linux_DnsServiceInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new Linux_DnsServiceInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new Linux_DnsServiceInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new Linux_DnsServiceInstance(anInstance);
  	}

  }
  
}
