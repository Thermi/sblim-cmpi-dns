// =======================================================================
// CIM_ConcreteJobInstance.cpp
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
//				  Amir Sanjar        <v1sanjar(at)us.ibm.com>
// =======================================================================
//
// 
#include "CIM_ConcreteJobInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //****************************************************************************
  //CIM_ConcreteJobInstance
  //----------------------------------------------------------------------------
  //empty constructor
  CIM_ConcreteJobInstance::CIM_ConcreteJobInstance() {   	
   	init();  	   	
  }
  
  //----------------------------------------------------------------------------
  //copy constructor	
  //----------------------------------------------------------------------------
  CIM_ConcreteJobInstance::CIM_ConcreteJobInstance(
    const CIM_ConcreteJobInstance& anInstance) {   	
   	init(anInstance);  	   	
  }
  
  //----------------------------------------------------------------------------
  //constructor using CmpiInstance
  //----------------------------------------------------------------------------
  CIM_ConcreteJobInstance::CIM_ConcreteJobInstance(
    const CmpiInstance& aCmpiInstance,
    const char* anInstanceNamespaceP) {

    CmpiData cmpiData;

    init(); 
    
    CmpiObjectPath cop = aCmpiInstance.getObjectPath();
    cop.setNameSpace(anInstanceNamespaceP);
    setInstanceName(CIM_ConcreteJobInstanceName(cop));

    cmpiData = aCmpiInstance.getProperty("Caption");
    if ( ! cmpiData.isNullValue()){
      CmpiString Caption = cmpiData;
      setCaption(Caption.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("DeleteOnCompletion");
    if ( ! cmpiData.isNullValue()){
      CMPIBoolean DeleteOnCompletion = cmpiData;
      setDeleteOnCompletion(DeleteOnCompletion);
    }

    cmpiData = aCmpiInstance.getProperty("Description");
    if ( ! cmpiData.isNullValue()){
      CmpiString Description = cmpiData;
      setDescription(Description.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("ElapsedTime");
    if ( ! cmpiData.isNullValue()){
      CmpiDateTime ElapsedTime = cmpiData;
      setElapsedTime(ElapsedTime);
    }

    cmpiData = aCmpiInstance.getProperty("ElementName");
    if ( ! cmpiData.isNullValue()){
      CmpiString ElementName = cmpiData;
      setElementName(ElementName.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("ErrorCode");
    if ( ! cmpiData.isNullValue()){
      CMPIUint16 ErrorCode = cmpiData;
      setErrorCode(ErrorCode);
    }

    cmpiData = aCmpiInstance.getProperty("ErrorDescription");
    if ( ! cmpiData.isNullValue()){
      CmpiString ErrorDescription = cmpiData;
      setErrorDescription(ErrorDescription.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("InstallDate");
    if ( ! cmpiData.isNullValue()){
      CmpiDateTime InstallDate = cmpiData;
      setInstallDate(InstallDate);
    }

    cmpiData = aCmpiInstance.getProperty("JobRunTimes");
    if ( ! cmpiData.isNullValue()){
      CMPIUint32 JobRunTimes = cmpiData;
      setJobRunTimes(JobRunTimes);
    }

    cmpiData = aCmpiInstance.getProperty("JobState");
    if ( ! cmpiData.isNullValue()){
      CMPIUint16 JobState = cmpiData;
      setJobState(JobState);
    }

    cmpiData = aCmpiInstance.getProperty("JobStatus");
    if ( ! cmpiData.isNullValue()){
      CmpiString JobStatus = cmpiData;
      setJobStatus(JobStatus.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("LocalOrUtcTime");
    if ( ! cmpiData.isNullValue()){
      CMPIUint16 LocalOrUtcTime = cmpiData;
      setLocalOrUtcTime(LocalOrUtcTime);
    }

    cmpiData = aCmpiInstance.getProperty("Name");
    if ( ! cmpiData.isNullValue()){
      CmpiString Name = cmpiData;
      setName(Name.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("Notify");
    if ( ! cmpiData.isNullValue()){
      CmpiString Notify = cmpiData;
      setNotify(Notify.charPtr());
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

    cmpiData = aCmpiInstance.getProperty("OtherRecoveryAction");
    if ( ! cmpiData.isNullValue()){
      CmpiString OtherRecoveryAction = cmpiData;
      setOtherRecoveryAction(OtherRecoveryAction.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("Owner");
    if ( ! cmpiData.isNullValue()){
      CmpiString Owner = cmpiData;
      setOwner(Owner.charPtr());
    }

    cmpiData = aCmpiInstance.getProperty("PercentComplete");
    if ( ! cmpiData.isNullValue()){
      CMPIUint16 PercentComplete = cmpiData;
      setPercentComplete(PercentComplete);
    }

    cmpiData = aCmpiInstance.getProperty("Priority");
    if ( ! cmpiData.isNullValue()){
      CMPIUint32 Priority = cmpiData;
      setPriority(Priority);
    }

    cmpiData = aCmpiInstance.getProperty("RecoveryAction");
    if ( ! cmpiData.isNullValue()){
      CMPIUint16 RecoveryAction = cmpiData;
      setRecoveryAction(RecoveryAction);
    }

    cmpiData = aCmpiInstance.getProperty("RunDay");
    if ( ! cmpiData.isNullValue()){
      CMPISint8 RunDay = cmpiData;
      setRunDay(RunDay);
    }

    cmpiData = aCmpiInstance.getProperty("RunDayOfWeek");
    if ( ! cmpiData.isNullValue()){
      CMPISint8 RunDayOfWeek = cmpiData;
      setRunDayOfWeek(RunDayOfWeek);
    }

    cmpiData = aCmpiInstance.getProperty("RunMonth");
    if ( ! cmpiData.isNullValue()){
      CMPIUint8 RunMonth = cmpiData;
      setRunMonth(RunMonth);
    }

    cmpiData = aCmpiInstance.getProperty("RunStartInterval");
    if ( ! cmpiData.isNullValue()){
      CmpiDateTime RunStartInterval = cmpiData;
      setRunStartInterval(RunStartInterval);
    }

    cmpiData = aCmpiInstance.getProperty("ScheduledStartTime");
    if ( ! cmpiData.isNullValue()){
      CmpiDateTime ScheduledStartTime = cmpiData;
      setScheduledStartTime(ScheduledStartTime);
    }

    cmpiData = aCmpiInstance.getProperty("StartTime");
    if ( ! cmpiData.isNullValue()){
      CmpiDateTime StartTime = cmpiData;
      setStartTime(StartTime);
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

    cmpiData = aCmpiInstance.getProperty("TimeBeforeRemoval");
    if ( ! cmpiData.isNullValue()){
      CmpiDateTime TimeBeforeRemoval = cmpiData;
      setTimeBeforeRemoval(TimeBeforeRemoval);
    }

    cmpiData = aCmpiInstance.getProperty("TimeOfLastStateChange");
    if ( ! cmpiData.isNullValue()){
      CmpiDateTime TimeOfLastStateChange = cmpiData;
      setTimeOfLastStateChange(TimeOfLastStateChange);
    }

    cmpiData = aCmpiInstance.getProperty("TimeSubmitted");
    if ( ! cmpiData.isNullValue()){
      CmpiDateTime TimeSubmitted = cmpiData;
      setTimeSubmitted(TimeSubmitted);
    }

    cmpiData = aCmpiInstance.getProperty("UntilTime");
    if ( ! cmpiData.isNullValue()){
      CmpiDateTime UntilTime = cmpiData;
      setUntilTime(UntilTime);
    }

    
  }
  
  //----------------------------------------------------------------------------
  //Destructor
  //----------------------------------------------------------------------------
  CIM_ConcreteJobInstance::
   ~CIM_ConcreteJobInstance(){
   	reset();  	  
  }
  
  
  //----------------------------------------------------------------------------
  //copy operator
  //----------------------------------------------------------------------------
  CIM_ConcreteJobInstance&
  CIM_ConcreteJobInstance::operator=(
    const CIM_ConcreteJobInstance& anInstance) {   	
   	
   	init(anInstance);
   	return *this;
  
  }
  
  
  //----------------------------------------------------------------------------
  //converts to CmpiInstance
  //----------------------------------------------------------------------------
  CmpiInstance
  CIM_ConcreteJobInstance::getCmpiInstance(
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

  	if (isSet.DeleteOnCompletion) {
  	  
  	  cmpiInstance.setProperty(
  	    "DeleteOnCompletion",
  	    CmpiBooleanData(m_DeleteOnCompletion));
  	}

  	if (isSet.Description) {
  	  
  	  cmpiInstance.setProperty(
  	    "Description",
  	    CmpiData(m_Description));
  	}

  	if (isSet.ElapsedTime) {
  	  
  	  cmpiInstance.setProperty(
  	    "ElapsedTime",
  	    CmpiData(m_ElapsedTime));
  	}

  	if (isSet.ElementName) {
  	  
  	  cmpiInstance.setProperty(
  	    "ElementName",
  	    CmpiData(m_ElementName));
  	}

  	if (isSet.ErrorCode) {
  	  
  	  cmpiInstance.setProperty(
  	    "ErrorCode",
  	    CmpiData(m_ErrorCode));
  	}

  	if (isSet.ErrorDescription) {
  	  
  	  cmpiInstance.setProperty(
  	    "ErrorDescription",
  	    CmpiData(m_ErrorDescription));
  	}

  	if (isSet.InstallDate) {
  	  
  	  cmpiInstance.setProperty(
  	    "InstallDate",
  	    CmpiData(m_InstallDate));
  	}

  	if (isSet.JobRunTimes) {
  	  
  	  cmpiInstance.setProperty(
  	    "JobRunTimes",
  	    CmpiData(m_JobRunTimes));
  	}

  	if (isSet.JobState) {
  	  
  	  cmpiInstance.setProperty(
  	    "JobState",
  	    CmpiData(m_JobState));
  	}

  	if (isSet.JobStatus) {
  	  
  	  cmpiInstance.setProperty(
  	    "JobStatus",
  	    CmpiData(m_JobStatus));
  	}

  	if (isSet.LocalOrUtcTime) {
  	  
  	  cmpiInstance.setProperty(
  	    "LocalOrUtcTime",
  	    CmpiData(m_LocalOrUtcTime));
  	}

  	if (isSet.Name) {
  	  
  	  cmpiInstance.setProperty(
  	    "Name",
  	    CmpiData(m_Name));
  	}

  	if (isSet.Notify) {
  	  
  	  cmpiInstance.setProperty(
  	    "Notify",
  	    CmpiData(m_Notify));
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

  	if (isSet.OtherRecoveryAction) {
  	  
  	  cmpiInstance.setProperty(
  	    "OtherRecoveryAction",
  	    CmpiData(m_OtherRecoveryAction));
  	}

  	if (isSet.Owner) {
  	  
  	  cmpiInstance.setProperty(
  	    "Owner",
  	    CmpiData(m_Owner));
  	}

  	if (isSet.PercentComplete) {
  	  
  	  cmpiInstance.setProperty(
  	    "PercentComplete",
  	    CmpiData(m_PercentComplete));
  	}

  	if (isSet.Priority) {
  	  
  	  cmpiInstance.setProperty(
  	    "Priority",
  	    CmpiData(m_Priority));
  	}

  	if (isSet.RecoveryAction) {
  	  
  	  cmpiInstance.setProperty(
  	    "RecoveryAction",
  	    CmpiData(m_RecoveryAction));
  	}

  	if (isSet.RunDay) {
  	  
  	  cmpiInstance.setProperty(
  	    "RunDay",
  	    CmpiData(m_RunDay));
  	}

  	if (isSet.RunDayOfWeek) {
  	  
  	  cmpiInstance.setProperty(
  	    "RunDayOfWeek",
  	    CmpiData(m_RunDayOfWeek));
  	}

  	if (isSet.RunMonth) {
  	  
  	  cmpiInstance.setProperty(
  	    "RunMonth",
  	    CmpiData(m_RunMonth));
  	}

  	if (isSet.RunStartInterval) {
  	  
  	  cmpiInstance.setProperty(
  	    "RunStartInterval",
  	    CmpiData(m_RunStartInterval));
  	}

  	if (isSet.ScheduledStartTime) {
  	  
  	  cmpiInstance.setProperty(
  	    "ScheduledStartTime",
  	    CmpiData(m_ScheduledStartTime));
  	}

  	if (isSet.StartTime) {
  	  
  	  cmpiInstance.setProperty(
  	    "StartTime",
  	    CmpiData(m_StartTime));
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

  	if (isSet.TimeBeforeRemoval) {
  	  
  	  cmpiInstance.setProperty(
  	    "TimeBeforeRemoval",
  	    CmpiData(m_TimeBeforeRemoval));
  	}

  	if (isSet.TimeOfLastStateChange) {
  	  
  	  cmpiInstance.setProperty(
  	    "TimeOfLastStateChange",
  	    CmpiData(m_TimeOfLastStateChange));
  	}

  	if (isSet.TimeSubmitted) {
  	  
  	  cmpiInstance.setProperty(
  	    "TimeSubmitted",
  	    CmpiData(m_TimeSubmitted));
  	}

  	if (isSet.UntilTime) {
  	  
  	  cmpiInstance.setProperty(
  	    "UntilTime",
  	    CmpiData(m_UntilTime));
  	}

  	
  	return cmpiInstance;
  	
  }
  
  //----------------------------------------------------------------------------
  // InstanceName related methods
  //----------------------------------------------------------------------------
  unsigned int 
  CIM_ConcreteJobInstance::isInstanceNameSet() const {
  	return isSet.instanceName;
  }
  
  //----------------------------------------------------------------------------
  const CIM_ConcreteJobInstanceName&
  CIM_ConcreteJobInstance::getInstanceName() const {

    if( ! isSet.instanceName) {
   	  throw CmpiErrorFormater::getErrorException(
        CmpiErrorFormater::NOT_SET,
        "InstanceName (CIM Key Attributes)",
        "CIM_ConcreteJob");
   	}
  		
   	return m_instanceName;
  
  }

  //----------------------------------------------------------------------------
  void
  CIM_ConcreteJobInstance::setInstanceName(
    const CIM_ConcreteJobInstanceName& val) {

    m_instanceName = val;
    isSet.instanceName = 1;

  }
       
  //----------------------------------------------------------------------------
  // Caption related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isCaptionSet() const {
    return isSet.Caption;
  }

  //----------------------------------------------------------------------------
  void
  CIM_ConcreteJobInstance::setCaption(
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
  CIM_ConcreteJobInstance::getCaption() const {
    
    if ( ! isSet.Caption) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Caption",
        "CIM_ConcreteJob");
   	}


    return m_Caption;

  }
       
  //----------------------------------------------------------------------------
  // DeleteOnCompletion related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isDeleteOnCompletionSet() const {
    return isSet.DeleteOnCompletion;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setDeleteOnCompletion(
    const CMPIBoolean aValue) {
  
    m_DeleteOnCompletion = aValue;
    isSet.DeleteOnCompletion = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIBoolean
  CIM_ConcreteJobInstance::getDeleteOnCompletion() const {
    
    if ( ! isSet.DeleteOnCompletion) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "DeleteOnCompletion",
        "CIM_ConcreteJob");
   	}


    return m_DeleteOnCompletion;

  }
       
  //----------------------------------------------------------------------------
  // Description related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isDescriptionSet() const {
    return isSet.Description;
  }

  //----------------------------------------------------------------------------
  void
  CIM_ConcreteJobInstance::setDescription(
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
  CIM_ConcreteJobInstance::getDescription() const {
    
    if ( ! isSet.Description) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Description",
        "CIM_ConcreteJob");
   	}


    return m_Description;

  }
       
  //----------------------------------------------------------------------------
  // ElapsedTime related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isElapsedTimeSet() const {
    return isSet.ElapsedTime;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setElapsedTime(
    const CmpiDateTime& aValue) {
  
    m_ElapsedTime = aValue;
    isSet.ElapsedTime = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CmpiDateTime&
  CIM_ConcreteJobInstance::getElapsedTime() const {
    
    if ( ! isSet.ElapsedTime) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ElapsedTime",
        "CIM_ConcreteJob");
   	}


    return m_ElapsedTime;

  }
       
  //----------------------------------------------------------------------------
  // ElementName related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isElementNameSet() const {
    return isSet.ElementName;
  }

  //----------------------------------------------------------------------------
  void
  CIM_ConcreteJobInstance::setElementName(
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
  CIM_ConcreteJobInstance::getElementName() const {
    
    if ( ! isSet.ElementName) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ElementName",
        "CIM_ConcreteJob");
   	}


    return m_ElementName;

  }
       
  //----------------------------------------------------------------------------
  // ErrorCode related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isErrorCodeSet() const {
    return isSet.ErrorCode;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setErrorCode(
    const CMPIUint16 aValue) {
  
    m_ErrorCode = aValue;
    isSet.ErrorCode = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16
  CIM_ConcreteJobInstance::getErrorCode() const {
    
    if ( ! isSet.ErrorCode) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ErrorCode",
        "CIM_ConcreteJob");
   	}


    return m_ErrorCode;

  }
       
  //----------------------------------------------------------------------------
  // ErrorDescription related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isErrorDescriptionSet() const {
    return isSet.ErrorDescription;
  }

  //----------------------------------------------------------------------------
  void
  CIM_ConcreteJobInstance::setErrorDescription(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.ErrorDescription) {
      delete [] m_ErrorDescription;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_ErrorDescription = valueP;
    } else {
      m_ErrorDescription = aValueP;
    }
    
    isSet.ErrorDescription = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  CIM_ConcreteJobInstance::getErrorDescription() const {
    
    if ( ! isSet.ErrorDescription) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ErrorDescription",
        "CIM_ConcreteJob");
   	}


    return m_ErrorDescription;

  }
       
  //----------------------------------------------------------------------------
  // InstallDate related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isInstallDateSet() const {
    return isSet.InstallDate;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setInstallDate(
    const CmpiDateTime& aValue) {
  
    m_InstallDate = aValue;
    isSet.InstallDate = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CmpiDateTime&
  CIM_ConcreteJobInstance::getInstallDate() const {
    
    if ( ! isSet.InstallDate) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "InstallDate",
        "CIM_ConcreteJob");
   	}


    return m_InstallDate;

  }
       
  //----------------------------------------------------------------------------
  // JobRunTimes related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isJobRunTimesSet() const {
    return isSet.JobRunTimes;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setJobRunTimes(
    const CMPIUint32 aValue) {
  
    m_JobRunTimes = aValue;
    isSet.JobRunTimes = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint32
  CIM_ConcreteJobInstance::getJobRunTimes() const {
    
    if ( ! isSet.JobRunTimes) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "JobRunTimes",
        "CIM_ConcreteJob");
   	}


    return m_JobRunTimes;

  }
       
  //----------------------------------------------------------------------------
  // JobState related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isJobStateSet() const {
    return isSet.JobState;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setJobState(
    const CMPIUint16 aValue) {
  
    m_JobState = aValue;
    isSet.JobState = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16
  CIM_ConcreteJobInstance::getJobState() const {
    
    if ( ! isSet.JobState) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "JobState",
        "CIM_ConcreteJob");
   	}


    return m_JobState;

  }
       
  //----------------------------------------------------------------------------
  // JobStatus related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isJobStatusSet() const {
    return isSet.JobStatus;
  }

  //----------------------------------------------------------------------------
  void
  CIM_ConcreteJobInstance::setJobStatus(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.JobStatus) {
      delete [] m_JobStatus;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_JobStatus = valueP;
    } else {
      m_JobStatus = aValueP;
    }
    
    isSet.JobStatus = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  CIM_ConcreteJobInstance::getJobStatus() const {
    
    if ( ! isSet.JobStatus) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "JobStatus",
        "CIM_ConcreteJob");
   	}


    return m_JobStatus;

  }
       
  //----------------------------------------------------------------------------
  // LocalOrUtcTime related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isLocalOrUtcTimeSet() const {
    return isSet.LocalOrUtcTime;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setLocalOrUtcTime(
    const CMPIUint16 aValue) {
  
    m_LocalOrUtcTime = aValue;
    isSet.LocalOrUtcTime = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16
  CIM_ConcreteJobInstance::getLocalOrUtcTime() const {
    
    if ( ! isSet.LocalOrUtcTime) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "LocalOrUtcTime",
        "CIM_ConcreteJob");
   	}


    return m_LocalOrUtcTime;

  }
       
  //----------------------------------------------------------------------------
  // Name related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isNameSet() const {
    return isSet.Name;
  }

  //----------------------------------------------------------------------------
  void
  CIM_ConcreteJobInstance::setName(
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
  CIM_ConcreteJobInstance::getName() const {
    
    if ( ! isSet.Name) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Name",
        "CIM_ConcreteJob");
   	}


    return m_Name;

  }
       
  //----------------------------------------------------------------------------
  // Notify related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isNotifySet() const {
    return isSet.Notify;
  }

  //----------------------------------------------------------------------------
  void
  CIM_ConcreteJobInstance::setNotify(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.Notify) {
      delete [] m_Notify;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_Notify = valueP;
    } else {
      m_Notify = aValueP;
    }
    
    isSet.Notify = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  CIM_ConcreteJobInstance::getNotify() const {
    
    if ( ! isSet.Notify) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Notify",
        "CIM_ConcreteJob");
   	}


    return m_Notify;

  }
       
  //----------------------------------------------------------------------------
  // OperationalStatus related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isOperationalStatusSet() const {
    return isSet.OperationalStatus;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setOperationalStatus(
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
  CIM_ConcreteJobInstance::getOperationalStatus(unsigned int& aSize) const {
    
    if ( ! isSet.OperationalStatus) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "OperationalStatus",
        "CIM_ConcreteJob");
   	}

    aSize = m_OperationalStatusSize;
    return m_OperationalStatus;

  }
       
  //----------------------------------------------------------------------------
  // OtherRecoveryAction related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isOtherRecoveryActionSet() const {
    return isSet.OtherRecoveryAction;
  }

  //----------------------------------------------------------------------------
  void
  CIM_ConcreteJobInstance::setOtherRecoveryAction(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.OtherRecoveryAction) {
      delete [] m_OtherRecoveryAction;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_OtherRecoveryAction = valueP;
    } else {
      m_OtherRecoveryAction = aValueP;
    }
    
    isSet.OtherRecoveryAction = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  CIM_ConcreteJobInstance::getOtherRecoveryAction() const {
    
    if ( ! isSet.OtherRecoveryAction) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "OtherRecoveryAction",
        "CIM_ConcreteJob");
   	}


    return m_OtherRecoveryAction;

  }
       
  //----------------------------------------------------------------------------
  // Owner related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isOwnerSet() const {
    return isSet.Owner;
  }

  //----------------------------------------------------------------------------
  void
  CIM_ConcreteJobInstance::setOwner(
    const char* aValueP,
    int aCopyFlag) {
    
    if (isSet.Owner) {
      delete [] m_Owner;
    }
    
    if (aCopyFlag && aValueP) {
      char* valueP = new char[strlen(aValueP) + 1];
      strcpy(valueP,aValueP);
      m_Owner = valueP;
    } else {
      m_Owner = aValueP;
    }
    
    isSet.Owner = 1;

  }       

  //----------------------------------------------------------------------------
  const char*
  CIM_ConcreteJobInstance::getOwner() const {
    
    if ( ! isSet.Owner) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Owner",
        "CIM_ConcreteJob");
   	}


    return m_Owner;

  }
       
  //----------------------------------------------------------------------------
  // PercentComplete related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isPercentCompleteSet() const {
    return isSet.PercentComplete;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setPercentComplete(
    const CMPIUint16 aValue) {
  
    m_PercentComplete = aValue;
    isSet.PercentComplete = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16
  CIM_ConcreteJobInstance::getPercentComplete() const {
    
    if ( ! isSet.PercentComplete) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "PercentComplete",
        "CIM_ConcreteJob");
   	}


    return m_PercentComplete;

  }
       
  //----------------------------------------------------------------------------
  // Priority related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isPrioritySet() const {
    return isSet.Priority;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setPriority(
    const CMPIUint32 aValue) {
  
    m_Priority = aValue;
    isSet.Priority = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint32
  CIM_ConcreteJobInstance::getPriority() const {
    
    if ( ! isSet.Priority) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Priority",
        "CIM_ConcreteJob");
   	}


    return m_Priority;

  }
       
  //----------------------------------------------------------------------------
  // RecoveryAction related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isRecoveryActionSet() const {
    return isSet.RecoveryAction;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setRecoveryAction(
    const CMPIUint16 aValue) {
  
    m_RecoveryAction = aValue;
    isSet.RecoveryAction = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint16
  CIM_ConcreteJobInstance::getRecoveryAction() const {
    
    if ( ! isSet.RecoveryAction) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "RecoveryAction",
        "CIM_ConcreteJob");
   	}


    return m_RecoveryAction;

  }
       
  //----------------------------------------------------------------------------
  // RunDay related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isRunDaySet() const {
    return isSet.RunDay;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setRunDay(
    const CMPISint8 aValue) {
  
    m_RunDay = aValue;
    isSet.RunDay = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPISint8
  CIM_ConcreteJobInstance::getRunDay() const {
    
    if ( ! isSet.RunDay) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "RunDay",
        "CIM_ConcreteJob");
   	}


    return m_RunDay;

  }
       
  //----------------------------------------------------------------------------
  // RunDayOfWeek related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isRunDayOfWeekSet() const {
    return isSet.RunDayOfWeek;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setRunDayOfWeek(
    const CMPISint8 aValue) {
  
    m_RunDayOfWeek = aValue;
    isSet.RunDayOfWeek = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPISint8
  CIM_ConcreteJobInstance::getRunDayOfWeek() const {
    
    if ( ! isSet.RunDayOfWeek) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "RunDayOfWeek",
        "CIM_ConcreteJob");
   	}


    return m_RunDayOfWeek;

  }
       
  //----------------------------------------------------------------------------
  // RunMonth related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isRunMonthSet() const {
    return isSet.RunMonth;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setRunMonth(
    const CMPIUint8 aValue) {
  
    m_RunMonth = aValue;
    isSet.RunMonth = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CMPIUint8
  CIM_ConcreteJobInstance::getRunMonth() const {
    
    if ( ! isSet.RunMonth) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "RunMonth",
        "CIM_ConcreteJob");
   	}


    return m_RunMonth;

  }
       
  //----------------------------------------------------------------------------
  // RunStartInterval related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isRunStartIntervalSet() const {
    return isSet.RunStartInterval;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setRunStartInterval(
    const CmpiDateTime& aValue) {
  
    m_RunStartInterval = aValue;
    isSet.RunStartInterval = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CmpiDateTime&
  CIM_ConcreteJobInstance::getRunStartInterval() const {
    
    if ( ! isSet.RunStartInterval) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "RunStartInterval",
        "CIM_ConcreteJob");
   	}


    return m_RunStartInterval;

  }
       
  //----------------------------------------------------------------------------
  // ScheduledStartTime related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isScheduledStartTimeSet() const {
    return isSet.ScheduledStartTime;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setScheduledStartTime(
    const CmpiDateTime& aValue) {
  
    m_ScheduledStartTime = aValue;
    isSet.ScheduledStartTime = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CmpiDateTime&
  CIM_ConcreteJobInstance::getScheduledStartTime() const {
    
    if ( ! isSet.ScheduledStartTime) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "ScheduledStartTime",
        "CIM_ConcreteJob");
   	}


    return m_ScheduledStartTime;

  }
       
  //----------------------------------------------------------------------------
  // StartTime related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isStartTimeSet() const {
    return isSet.StartTime;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setStartTime(
    const CmpiDateTime& aValue) {
  
    m_StartTime = aValue;
    isSet.StartTime = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CmpiDateTime&
  CIM_ConcreteJobInstance::getStartTime() const {
    
    if ( ! isSet.StartTime) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "StartTime",
        "CIM_ConcreteJob");
   	}


    return m_StartTime;

  }
       
  //----------------------------------------------------------------------------
  // Status related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isStatusSet() const {
    return isSet.Status;
  }

  //----------------------------------------------------------------------------
  void
  CIM_ConcreteJobInstance::setStatus(
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
  CIM_ConcreteJobInstance::getStatus() const {
    
    if ( ! isSet.Status) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "Status",
        "CIM_ConcreteJob");
   	}


    return m_Status;

  }
       
  //----------------------------------------------------------------------------
  // StatusDescriptions related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isStatusDescriptionsSet() const {
    return isSet.StatusDescriptions;
  }

  //----------------------------------------------------------------------------
  void  
  CIM_ConcreteJobInstance::setStatusDescriptions(
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
  CIM_ConcreteJobInstance::getStatusDescriptions(unsigned int& aSize) const {
    
    if ( ! isSet.StatusDescriptions) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "StatusDescriptions",
        "CIM_ConcreteJob");
   	}

    aSize = m_StatusDescriptionsSize;
    return m_StatusDescriptions;

  }
       
  //----------------------------------------------------------------------------
  // TimeBeforeRemoval related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isTimeBeforeRemovalSet() const {
    return isSet.TimeBeforeRemoval;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setTimeBeforeRemoval(
    const CmpiDateTime& aValue) {
  
    m_TimeBeforeRemoval = aValue;
    isSet.TimeBeforeRemoval = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CmpiDateTime&
  CIM_ConcreteJobInstance::getTimeBeforeRemoval() const {
    
    if ( ! isSet.TimeBeforeRemoval) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "TimeBeforeRemoval",
        "CIM_ConcreteJob");
   	}


    return m_TimeBeforeRemoval;

  }
       
  //----------------------------------------------------------------------------
  // TimeOfLastStateChange related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isTimeOfLastStateChangeSet() const {
    return isSet.TimeOfLastStateChange;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setTimeOfLastStateChange(
    const CmpiDateTime& aValue) {
  
    m_TimeOfLastStateChange = aValue;
    isSet.TimeOfLastStateChange = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CmpiDateTime&
  CIM_ConcreteJobInstance::getTimeOfLastStateChange() const {
    
    if ( ! isSet.TimeOfLastStateChange) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "TimeOfLastStateChange",
        "CIM_ConcreteJob");
   	}


    return m_TimeOfLastStateChange;

  }
       
  //----------------------------------------------------------------------------
  // TimeSubmitted related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isTimeSubmittedSet() const {
    return isSet.TimeSubmitted;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setTimeSubmitted(
    const CmpiDateTime& aValue) {
  
    m_TimeSubmitted = aValue;
    isSet.TimeSubmitted = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CmpiDateTime&
  CIM_ConcreteJobInstance::getTimeSubmitted() const {
    
    if ( ! isSet.TimeSubmitted) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "TimeSubmitted",
        "CIM_ConcreteJob");
   	}


    return m_TimeSubmitted;

  }
       
  //----------------------------------------------------------------------------
  // UntilTime related methods
  //----------------------------------------------------------------------------
  unsigned int
  CIM_ConcreteJobInstance::isUntilTimeSet() const {
    return isSet.UntilTime;
  }

  //----------------------------------------------------------------------------
  void CIM_ConcreteJobInstance::setUntilTime(
    const CmpiDateTime& aValue) {
  
    m_UntilTime = aValue;
    isSet.UntilTime = 1;
  
  }       

  //----------------------------------------------------------------------------
  const CmpiDateTime&
  CIM_ConcreteJobInstance::getUntilTime() const {
    
    if ( ! isSet.UntilTime) {
   	  throw CmpiErrorFormater::getErrorException(
   	    CmpiErrorFormater::NOT_SET,
        "UntilTime",
        "CIM_ConcreteJob");
   	}


    return m_UntilTime;

  }

  
  //----------------------------------------------------------------------------
  //set isSet attributes to FALSE
  //----------------------------------------------------------------------------
  void
  CIM_ConcreteJobInstance::init() {
   	isSet.instanceName = 0;
    isSet.Caption = 0;
    isSet.DeleteOnCompletion = 0;
    isSet.Description = 0;
    isSet.ElapsedTime = 0;
    isSet.ElementName = 0;
    isSet.ErrorCode = 0;
    isSet.ErrorDescription = 0;
    isSet.InstallDate = 0;
    isSet.JobRunTimes = 0;
    isSet.JobState = 0;
    isSet.JobStatus = 0;
    isSet.LocalOrUtcTime = 0;
    isSet.Name = 0;
    isSet.Notify = 0;
    isSet.OperationalStatus = 0;
    m_OperationalStatusSize = 0;
    isSet.OtherRecoveryAction = 0;
    isSet.Owner = 0;
    isSet.PercentComplete = 0;
    isSet.Priority = 0;
    isSet.RecoveryAction = 0;
    isSet.RunDay = 0;
    isSet.RunDayOfWeek = 0;
    isSet.RunMonth = 0;
    isSet.RunStartInterval = 0;
    isSet.ScheduledStartTime = 0;
    isSet.StartTime = 0;
    isSet.Status = 0;
    isSet.StatusDescriptions = 0;
    m_StatusDescriptionsSize = 0;
    isSet.TimeBeforeRemoval = 0;
    isSet.TimeOfLastStateChange = 0;
    isSet.TimeSubmitted = 0;
    isSet.UntilTime = 0;
  	
  }
  
  //----------------------------------------------------------------------------
  //copies another instance properties in this
  //----------------------------------------------------------------------------
  void 
  CIM_ConcreteJobInstance::init(
    const CIM_ConcreteJobInstance& anOriginal) {   	

   	init();
   	   	
    if(anOriginal.isInstanceNameSet()) {
      setInstanceName(anOriginal.getInstanceName());
    }
       	
    if (anOriginal.isCaptionSet()) {
      const char* CaptionOriginal = anOriginal.getCaption();
      setCaption(CaptionOriginal,1);
    }
   	
    if (anOriginal.isDeleteOnCompletionSet()) {
      const CMPIBoolean DeleteOnCompletionOriginal = anOriginal.getDeleteOnCompletion();
      setDeleteOnCompletion(DeleteOnCompletionOriginal);
    }
   	
    if (anOriginal.isDescriptionSet()) {
      const char* DescriptionOriginal = anOriginal.getDescription();
      setDescription(DescriptionOriginal,1);
    }
   	
    if (anOriginal.isElapsedTimeSet()) {
      const CmpiDateTime& ElapsedTimeOriginal = anOriginal.getElapsedTime();
      setElapsedTime(ElapsedTimeOriginal);
    }
   	
    if (anOriginal.isElementNameSet()) {
      const char* ElementNameOriginal = anOriginal.getElementName();
      setElementName(ElementNameOriginal,1);
    }
   	
    if (anOriginal.isErrorCodeSet()) {
      const CMPIUint16 ErrorCodeOriginal = anOriginal.getErrorCode();
      setErrorCode(ErrorCodeOriginal);
    }
   	
    if (anOriginal.isErrorDescriptionSet()) {
      const char* ErrorDescriptionOriginal = anOriginal.getErrorDescription();
      setErrorDescription(ErrorDescriptionOriginal,1);
    }
   	
    if (anOriginal.isInstallDateSet()) {
      const CmpiDateTime& InstallDateOriginal = anOriginal.getInstallDate();
      setInstallDate(InstallDateOriginal);
    }
   	
    if (anOriginal.isJobRunTimesSet()) {
      const CMPIUint32 JobRunTimesOriginal = anOriginal.getJobRunTimes();
      setJobRunTimes(JobRunTimesOriginal);
    }
   	
    if (anOriginal.isJobStateSet()) {
      const CMPIUint16 JobStateOriginal = anOriginal.getJobState();
      setJobState(JobStateOriginal);
    }
   	
    if (anOriginal.isJobStatusSet()) {
      const char* JobStatusOriginal = anOriginal.getJobStatus();
      setJobStatus(JobStatusOriginal,1);
    }
   	
    if (anOriginal.isLocalOrUtcTimeSet()) {
      const CMPIUint16 LocalOrUtcTimeOriginal = anOriginal.getLocalOrUtcTime();
      setLocalOrUtcTime(LocalOrUtcTimeOriginal);
    }
   	
    if (anOriginal.isNameSet()) {
      const char* NameOriginal = anOriginal.getName();
      setName(NameOriginal,1);
    }
   	
    if (anOriginal.isNotifySet()) {
      const char* NotifyOriginal = anOriginal.getNotify();
      setNotify(NotifyOriginal,1);
    }
   	
    if (anOriginal.isOperationalStatusSet()) {
      unsigned int sizeOperationalStatus;
      const CMPIUint16* OperationalStatusOriginal = anOriginal.getOperationalStatus(sizeOperationalStatus);
      setOperationalStatus(OperationalStatusOriginal, sizeOperationalStatus,1);
    }
   	
    if (anOriginal.isOtherRecoveryActionSet()) {
      const char* OtherRecoveryActionOriginal = anOriginal.getOtherRecoveryAction();
      setOtherRecoveryAction(OtherRecoveryActionOriginal,1);
    }
   	
    if (anOriginal.isOwnerSet()) {
      const char* OwnerOriginal = anOriginal.getOwner();
      setOwner(OwnerOriginal,1);
    }
   	
    if (anOriginal.isPercentCompleteSet()) {
      const CMPIUint16 PercentCompleteOriginal = anOriginal.getPercentComplete();
      setPercentComplete(PercentCompleteOriginal);
    }
   	
    if (anOriginal.isPrioritySet()) {
      const CMPIUint32 PriorityOriginal = anOriginal.getPriority();
      setPriority(PriorityOriginal);
    }
   	
    if (anOriginal.isRecoveryActionSet()) {
      const CMPIUint16 RecoveryActionOriginal = anOriginal.getRecoveryAction();
      setRecoveryAction(RecoveryActionOriginal);
    }
   	
    if (anOriginal.isRunDaySet()) {
      const CMPISint8 RunDayOriginal = anOriginal.getRunDay();
      setRunDay(RunDayOriginal);
    }
   	
    if (anOriginal.isRunDayOfWeekSet()) {
      const CMPISint8 RunDayOfWeekOriginal = anOriginal.getRunDayOfWeek();
      setRunDayOfWeek(RunDayOfWeekOriginal);
    }
   	
    if (anOriginal.isRunMonthSet()) {
      const CMPIUint8 RunMonthOriginal = anOriginal.getRunMonth();
      setRunMonth(RunMonthOriginal);
    }
   	
    if (anOriginal.isRunStartIntervalSet()) {
      const CmpiDateTime& RunStartIntervalOriginal = anOriginal.getRunStartInterval();
      setRunStartInterval(RunStartIntervalOriginal);
    }
   	
    if (anOriginal.isScheduledStartTimeSet()) {
      const CmpiDateTime& ScheduledStartTimeOriginal = anOriginal.getScheduledStartTime();
      setScheduledStartTime(ScheduledStartTimeOriginal);
    }
   	
    if (anOriginal.isStartTimeSet()) {
      const CmpiDateTime& StartTimeOriginal = anOriginal.getStartTime();
      setStartTime(StartTimeOriginal);
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
   	
    if (anOriginal.isTimeBeforeRemovalSet()) {
      const CmpiDateTime& TimeBeforeRemovalOriginal = anOriginal.getTimeBeforeRemoval();
      setTimeBeforeRemoval(TimeBeforeRemovalOriginal);
    }
   	
    if (anOriginal.isTimeOfLastStateChangeSet()) {
      const CmpiDateTime& TimeOfLastStateChangeOriginal = anOriginal.getTimeOfLastStateChange();
      setTimeOfLastStateChange(TimeOfLastStateChangeOriginal);
    }
   	
    if (anOriginal.isTimeSubmittedSet()) {
      const CmpiDateTime& TimeSubmittedOriginal = anOriginal.getTimeSubmitted();
      setTimeSubmitted(TimeSubmittedOriginal);
    }
   	
    if (anOriginal.isUntilTimeSet()) {
      const CmpiDateTime& UntilTimeOriginal = anOriginal.getUntilTime();
      setUntilTime(UntilTimeOriginal);
    }
    
  }
  
  //----------------------------------------------------------------------------
  //reset the instance data
  //----------------------------------------------------------------------------
  void
  CIM_ConcreteJobInstance::reset() {
   	
  	if (isSet.Caption) {
  	  delete(m_Caption);
  	}

  	if (isSet.Description) {
  	  delete(m_Description);
  	}

  	if (isSet.ElementName) {
  	  delete(m_ElementName);
  	}

  	if (isSet.ErrorDescription) {
  	  delete(m_ErrorDescription);
  	}

  	if (isSet.JobStatus) {
  	  delete(m_JobStatus);
  	}

  	if (isSet.Name) {
  	  delete(m_Name);
  	}

  	if (isSet.Notify) {
  	  delete(m_Notify);
  	}

  	if (isSet.OperationalStatus) {
  	  ArrayConverter::destructArray((CMPIUint16*)m_OperationalStatus);
  	}

  	if (isSet.OtherRecoveryAction) {
  	  delete(m_OtherRecoveryAction);
  	}

  	if (isSet.Owner) {
  	  delete(m_Owner);
  	}

  	if (isSet.Status) {
  	  delete(m_Status);
  	}

  	if (isSet.StatusDescriptions) {
  	  ArrayConverter::destructArray((char**)m_StatusDescriptions,m_StatusDescriptionsSize);
  	}

  }
  
  //----------------------------------------------------------------------------
  //CIM_ConcreteJobInstanceEnumerationElement	
  //----------------------------------------------------------------------------
  CIM_ConcreteJobInstanceEnumerationElement::CIM_ConcreteJobInstanceEnumerationElement() {
   	
  	m_elementP = 0;
  	m_nextP = 0;
  	  
  }
  
  //----------------------------------------------------------------------------
  CIM_ConcreteJobInstanceEnumerationElement::~CIM_ConcreteJobInstanceEnumerationElement() {
   	
  	if (m_elementP) {
  	  delete(m_elementP);
  	}
  	
  	if (m_nextP) {
  	  delete(m_nextP);
  	}
  	  
  }

  //----------------------------------------------------------------------------
  //CIM_ConcreteJobInstanceNameEnumeration
  //----------------------------------------------------------------------------
  CIM_ConcreteJobInstanceEnumeration::CIM_ConcreteJobInstanceEnumeration() {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  
  }
  
  //----------------------------------------------------------------------------
  CIM_ConcreteJobInstanceEnumeration::CIM_ConcreteJobInstanceEnumeration(
    const CIM_ConcreteJobInstanceEnumeration& anInstanceEnumeration) {
   	
    m_firstElementP = 0;
    m_currentElementP = 0;
    m_endElementP = 0;
  	 
    int size = anInstanceEnumeration.getSize();
    for (int x=0; x < size;++x) {
      addElement(anInstanceEnumeration.getElement(x));
    }           

  }
  
  //----------------------------------------------------------------------------
  CIM_ConcreteJobInstanceEnumeration::~CIM_ConcreteJobInstanceEnumeration() {
   	
  	if (m_firstElementP) {
  	  delete(m_firstElementP);
  	}
  	  	
  }
  
  //----------------------------------------------------------------------------
  void
  CIM_ConcreteJobInstanceEnumeration::reset() {
  	
  	m_currentElementP = m_firstElementP;
  	
  }
  	  
  //----------------------------------------------------------------------------
  bool
  CIM_ConcreteJobInstanceEnumeration::hasNext() const {
  	
  	return (m_currentElementP != 0);
  
  }
  
  //----------------------------------------------------------------------------
  int
  CIM_ConcreteJobInstanceEnumeration::getSize() const {
  	
    int size = 0;
    CIM_ConcreteJobInstanceEnumerationElement* followingP = m_firstElementP;
  	
  	while (followingP) {
      followingP = followingP->m_nextP;
      ++size;
    }
  	
    return size;
    
  }
  
  //----------------------------------------------------------------------------
  const CIM_ConcreteJobInstance&  
  CIM_ConcreteJobInstanceEnumeration::getElement(int anIndex) const {
   
    CIM_ConcreteJobInstanceEnumerationElement* followingP = m_firstElementP;
   
    int x = 0;
    while (followingP && (x < anIndex)) {
      followingP = followingP->m_nextP;
      ++x;
    }
    
    return *(followingP->m_elementP);

  }
  
  //----------------------------------------------------------------------------
  const CIM_ConcreteJobInstance&
  CIM_ConcreteJobInstanceEnumeration::getNext() {
   	
    CIM_ConcreteJobInstanceEnumerationElement* currentElementP =
  	  m_currentElementP;

    m_currentElementP = m_currentElementP->m_nextP;
  	 
    return *(currentElementP->m_elementP);

  }
  	  
  //----------------------------------------------------------------------------
  void
  CIM_ConcreteJobInstanceEnumeration::addElement(
    const CIM_ConcreteJobInstance& anInstance) {
   	
  	if (m_firstElementP == 0) {
  	  m_firstElementP = new CIM_ConcreteJobInstanceEnumerationElement();
  	  m_firstElementP->m_elementP = new CIM_ConcreteJobInstance(anInstance);
  	  m_endElementP = m_firstElementP;
  	  m_currentElementP = m_firstElementP;
  	} else {
  	  m_endElementP->m_nextP = new CIM_ConcreteJobInstanceEnumerationElement();
  	  m_endElementP = m_endElementP->m_nextP;
  	  m_endElementP->m_elementP = new CIM_ConcreteJobInstance(anInstance);
  	}

  }
  
}
