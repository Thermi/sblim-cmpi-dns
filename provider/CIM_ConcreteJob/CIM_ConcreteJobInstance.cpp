 /**
 * CIM_ConcreteJobInstance.cpp
 *
 * (C) Copyright IBM Corp. 2005
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Common Public License from
 * http://www.opensource.org/licenses/cpl1.0.php
 *
 * author:     Murillo Bernardes <bernarde@br.ibm.com>
 *
 * Contributors:
 *
 */
#include "CIM_ConcreteJobInstance.h"
#include "CmpiData.h"
#include "CmpiString.h"
#include "CmpiArray.h"
#include <string>

namespace genProvider {

  //*********************************************************
  //CIM_ConcreteJobInstance
  //*********************************************************

  //empty constructor
  CIM_ConcreteJobInstance::
   CIM_ConcreteJobInstance(){   	
   	init();  	   	
  };
  
  
  //copy constructor	
  CIM_ConcreteJobInstance::
   CIM_ConcreteJobInstance
   (const CIM_ConcreteJobInstance& original){   	
   	init(original);  	   	
  };
  
  
  //constructor using CmpiInstance
  CIM_ConcreteJobInstance::
   CIM_ConcreteJobInstance (const CmpiInstance& inst, const char* instanceNamespace){
    CmpiData cmpiData;
    init(); 
    
    CmpiObjectPath cop=inst.getObjectPath();
    cop.setNameSpace(instanceNamespace);
    setInstanceName(CIM_ConcreteJobInstanceName(cop));
    
    cmpiData = inst.getProperty("Caption");
    if(!cmpiData.isNullValue()){
      CmpiString Caption = cmpiData;
      setCaption(Caption.charPtr());
    }
    
    cmpiData = inst.getProperty("DeleteOnCompletion");
    if(!cmpiData.isNullValue()){
      CMPIBoolean DeleteOnCompletion = cmpiData;
      setDeleteOnCompletion(DeleteOnCompletion);
    }
    
    cmpiData = inst.getProperty("Description");
    if(!cmpiData.isNullValue()){
      CmpiString Description = cmpiData;
      setDescription(Description.charPtr());
    }
    
    cmpiData = inst.getProperty("ElapsedTime");
    if(!cmpiData.isNullValue()){
      CmpiDateTime ElapsedTime = cmpiData;
      setElapsedTime(ElapsedTime);
    }
    
    cmpiData = inst.getProperty("ElementName");
    if(!cmpiData.isNullValue()){
      CmpiString ElementName = cmpiData;
      setElementName(ElementName.charPtr());
    }
    
    cmpiData = inst.getProperty("ErrorCode");
    if(!cmpiData.isNullValue()){
      CMPIUint16 ErrorCode = cmpiData;
      setErrorCode(ErrorCode);
    }
    
    cmpiData = inst.getProperty("ErrorDescription");
    if(!cmpiData.isNullValue()){
      CmpiString ErrorDescription = cmpiData;
      setErrorDescription(ErrorDescription.charPtr());
    }
    
    cmpiData = inst.getProperty("InstallDate");
    if(!cmpiData.isNullValue()){
      CmpiDateTime InstallDate = cmpiData;
      setInstallDate(InstallDate);
    }
    
    cmpiData = inst.getProperty("JobRunTimes");
    if(!cmpiData.isNullValue()){
      CMPIUint32 JobRunTimes = cmpiData;
      setJobRunTimes(JobRunTimes);
    }
    
    cmpiData = inst.getProperty("JobState");
    if(!cmpiData.isNullValue()){
      CMPIUint16 JobState = cmpiData;
      setJobState(JobState);
    }
    
    cmpiData = inst.getProperty("JobStatus");
    if(!cmpiData.isNullValue()){
      CmpiString JobStatus = cmpiData;
      setJobStatus(JobStatus.charPtr());
    }
    
    cmpiData = inst.getProperty("LocalOrUtcTime");
    if(!cmpiData.isNullValue()){
      CMPIUint16 LocalOrUtcTime = cmpiData;
      setLocalOrUtcTime(LocalOrUtcTime);
    }
    
    cmpiData = inst.getProperty("Name");
    if(!cmpiData.isNullValue()){
      CmpiString Name = cmpiData;
      setName(Name.charPtr());
    }
    
    cmpiData = inst.getProperty("Notify");
    if(!cmpiData.isNullValue()){
      CmpiString Notify = cmpiData;
      setNotify(Notify.charPtr());
    }
    
    cmpiData = inst.getProperty("OperationalStatus");
    if(!cmpiData.isNullValue()){
      CmpiArray OperationalStatus = cmpiData;
      unsigned int OperationalStatusSize;
      const CMPIUint16* OperationalStatusArray;
      ArrayConverter::makeArray(OperationalStatus, (CMPIUint16**)&OperationalStatusArray, OperationalStatusSize);
      setOperationalStatus(OperationalStatusArray, OperationalStatusSize, 0);
    }
    
    cmpiData = inst.getProperty("OtherRecoveryAction");
    if(!cmpiData.isNullValue()){
      CmpiString OtherRecoveryAction = cmpiData;
      setOtherRecoveryAction(OtherRecoveryAction.charPtr());
    }
    
    cmpiData = inst.getProperty("Owner");
    if(!cmpiData.isNullValue()){
      CmpiString Owner = cmpiData;
      setOwner(Owner.charPtr());
    }
    
    cmpiData = inst.getProperty("PercentComplete");
    if(!cmpiData.isNullValue()){
      CMPIUint16 PercentComplete = cmpiData;
      setPercentComplete(PercentComplete);
    }
    
    cmpiData = inst.getProperty("Priority");
    if(!cmpiData.isNullValue()){
      CMPIUint32 Priority = cmpiData;
      setPriority(Priority);
    }
    
    cmpiData = inst.getProperty("RecoveryAction");
    if(!cmpiData.isNullValue()){
      CMPIUint16 RecoveryAction = cmpiData;
      setRecoveryAction(RecoveryAction);
    }
    
    cmpiData = inst.getProperty("RunDay");
    if(!cmpiData.isNullValue()){
      CMPISint8 RunDay = cmpiData;
      setRunDay(RunDay);
    }
    
    cmpiData = inst.getProperty("RunDayOfWeek");
    if(!cmpiData.isNullValue()){
      CMPISint8 RunDayOfWeek = cmpiData;
      setRunDayOfWeek(RunDayOfWeek);
    }
    
    cmpiData = inst.getProperty("RunMonth");
    if(!cmpiData.isNullValue()){
      CMPIUint8 RunMonth = cmpiData;
      setRunMonth(RunMonth);
    }
    
    cmpiData = inst.getProperty("RunStartInterval");
    if(!cmpiData.isNullValue()){
      CmpiDateTime RunStartInterval = cmpiData;
      setRunStartInterval(RunStartInterval);
    }
    
    cmpiData = inst.getProperty("ScheduledStartTime");
    if(!cmpiData.isNullValue()){
      CmpiDateTime ScheduledStartTime = cmpiData;
      setScheduledStartTime(ScheduledStartTime);
    }
    
    cmpiData = inst.getProperty("StartTime");
    if(!cmpiData.isNullValue()){
      CmpiDateTime StartTime = cmpiData;
      setStartTime(StartTime);
    }
    
    cmpiData = inst.getProperty("Status");
    if(!cmpiData.isNullValue()){
      CmpiString Status = cmpiData;
      setStatus(Status.charPtr());
    }
    
    cmpiData = inst.getProperty("StatusDescriptions");
    if(!cmpiData.isNullValue()){
      CmpiArray StatusDescriptions = cmpiData;
      unsigned int StatusDescriptionsSize;
      const char** StatusDescriptionsArray;
      ArrayConverter::makeArray(StatusDescriptions, (char***)&StatusDescriptionsArray, StatusDescriptionsSize);
      setStatusDescriptions(StatusDescriptionsArray, StatusDescriptionsSize, 0);
    }
    
    cmpiData = inst.getProperty("TimeBeforeRemoval");
    if(!cmpiData.isNullValue()){
      CmpiDateTime TimeBeforeRemoval = cmpiData;
      setTimeBeforeRemoval(TimeBeforeRemoval);
    }
    
    cmpiData = inst.getProperty("TimeOfLastStateChange");
    if(!cmpiData.isNullValue()){
      CmpiDateTime TimeOfLastStateChange = cmpiData;
      setTimeOfLastStateChange(TimeOfLastStateChange);
    }
    
    cmpiData = inst.getProperty("TimeSubmitted");
    if(!cmpiData.isNullValue()){
      CmpiDateTime TimeSubmitted = cmpiData;
      setTimeSubmitted(TimeSubmitted);
    }
    
    cmpiData = inst.getProperty("UntilTime");
    if(!cmpiData.isNullValue()){
      CmpiDateTime UntilTime = cmpiData;
      setUntilTime(UntilTime);
    }
    
  }
  
  
  //Destructor
  CIM_ConcreteJobInstance::
   ~CIM_ConcreteJobInstance(){
   	reset();  	  
  };
  
  
  //copy operator
  CIM_ConcreteJobInstance&
   CIM_ConcreteJobInstance::operator=
   (const CIM_ConcreteJobInstance& original){   	
   	init(original);
   	return *this;
  };
  
  
  //converts to CmpiInstance
  CmpiInstance CIM_ConcreteJobInstance::
   getCmpiInstance(const char** properties) const{
   	
   	CmpiObjectPath objectPath=getInstanceName().getObjectPath();      
    CmpiInstance cmpiInstance(objectPath);    
    getInstanceName().fillKeys(cmpiInstance);
    
    if (properties) {
	  cmpiInstance.setPropertyFilter(properties,0);
    }

  	if(isSet.Caption){
  	  cmpiInstance.setProperty("Caption",CmpiData(m_Caption));
  	}

  	if(isSet.DeleteOnCompletion){
  	  cmpiInstance.setProperty("DeleteOnCompletion",CmpiBooleanData(m_DeleteOnCompletion));
  	}

  	if(isSet.Description){
  	  cmpiInstance.setProperty("Description",CmpiData(m_Description));
  	}

  	if(isSet.ElapsedTime){
  	  cmpiInstance.setProperty("ElapsedTime",CmpiData(m_ElapsedTime));
  	}

  	if(isSet.ElementName){
  	  cmpiInstance.setProperty("ElementName",CmpiData(m_ElementName));
  	}

  	if(isSet.ErrorCode){
  	  cmpiInstance.setProperty("ErrorCode",CmpiData(m_ErrorCode));
  	}

  	if(isSet.ErrorDescription){
  	  cmpiInstance.setProperty("ErrorDescription",CmpiData(m_ErrorDescription));
  	}

  	if(isSet.InstallDate){
  	  cmpiInstance.setProperty("InstallDate",CmpiData(m_InstallDate));
  	}

  	if(isSet.JobRunTimes){
  	  cmpiInstance.setProperty("JobRunTimes",CmpiData(m_JobRunTimes));
  	}

  	if(isSet.JobState){
  	  cmpiInstance.setProperty("JobState",CmpiData(m_JobState));
  	}

  	if(isSet.JobStatus){
  	  cmpiInstance.setProperty("JobStatus",CmpiData(m_JobStatus));
  	}

  	if(isSet.LocalOrUtcTime){
  	  cmpiInstance.setProperty("LocalOrUtcTime",CmpiData(m_LocalOrUtcTime));
  	}

  	if(isSet.Name){
  	  cmpiInstance.setProperty("Name",CmpiData(m_Name));
  	}

  	if(isSet.Notify){
  	  cmpiInstance.setProperty("Notify",CmpiData(m_Notify));
  	}

  	if(isSet.OperationalStatus){
  	  unsigned int OperationalStatusSize;
      const CMPIUint16* arrayOperationalStatus=getOperationalStatus(OperationalStatusSize);
      CmpiArray arrayCmpiOperationalStatus=CmpiArray(OperationalStatusSize,CMPI_uint16);
      for(unsigned int i=0;i<OperationalStatusSize;i++)
        arrayCmpiOperationalStatus[i]=CmpiData(arrayOperationalStatus[i]);
  	cmpiInstance.setProperty("OperationalStatus",CmpiData(arrayCmpiOperationalStatus));
  	}

  	if(isSet.OtherRecoveryAction){
  	  cmpiInstance.setProperty("OtherRecoveryAction",CmpiData(m_OtherRecoveryAction));
  	}

  	if(isSet.Owner){
  	  cmpiInstance.setProperty("Owner",CmpiData(m_Owner));
  	}

  	if(isSet.PercentComplete){
  	  cmpiInstance.setProperty("PercentComplete",CmpiData(m_PercentComplete));
  	}

  	if(isSet.Priority){
  	  cmpiInstance.setProperty("Priority",CmpiData(m_Priority));
  	}

  	if(isSet.RecoveryAction){
  	  cmpiInstance.setProperty("RecoveryAction",CmpiData(m_RecoveryAction));
  	}

  	if(isSet.RunDay){
  	  cmpiInstance.setProperty("RunDay",CmpiData(m_RunDay));
  	}

  	if(isSet.RunDayOfWeek){
  	  cmpiInstance.setProperty("RunDayOfWeek",CmpiData(m_RunDayOfWeek));
  	}

  	if(isSet.RunMonth){
  	  cmpiInstance.setProperty("RunMonth",CmpiData(m_RunMonth));
  	}

  	if(isSet.RunStartInterval){
  	  cmpiInstance.setProperty("RunStartInterval",CmpiData(m_RunStartInterval));
  	}

  	if(isSet.ScheduledStartTime){
  	  cmpiInstance.setProperty("ScheduledStartTime",CmpiData(m_ScheduledStartTime));
  	}

  	if(isSet.StartTime){
  	  cmpiInstance.setProperty("StartTime",CmpiData(m_StartTime));
  	}

  	if(isSet.Status){
  	  cmpiInstance.setProperty("Status",CmpiData(m_Status));
  	}

  	if(isSet.StatusDescriptions){
  	  unsigned int StatusDescriptionsSize;
      const char** arrayStatusDescriptions=getStatusDescriptions(StatusDescriptionsSize);
      CmpiArray arrayCmpiStatusDescriptions=CmpiArray(StatusDescriptionsSize,CMPI_chars);
      for(unsigned int i=0;i<StatusDescriptionsSize;i++)
        arrayCmpiStatusDescriptions[i]=CmpiData(arrayStatusDescriptions[i]);
  	cmpiInstance.setProperty("StatusDescriptions",CmpiData(arrayCmpiStatusDescriptions));
  	}

  	if(isSet.TimeBeforeRemoval){
  	  cmpiInstance.setProperty("TimeBeforeRemoval",CmpiData(m_TimeBeforeRemoval));
  	}

  	if(isSet.TimeOfLastStateChange){
  	  cmpiInstance.setProperty("TimeOfLastStateChange",CmpiData(m_TimeOfLastStateChange));
  	}

  	if(isSet.TimeSubmitted){
  	  cmpiInstance.setProperty("TimeSubmitted",CmpiData(m_TimeSubmitted));
  	}

  	if(isSet.UntilTime){
  	  cmpiInstance.setProperty("UntilTime",CmpiData(m_UntilTime));
  	}
  	
  	return cmpiInstance;
  	
  }
  
  
  //InstanceName related methods
  unsigned int CIM_ConcreteJobInstance::
   isInstanceNameSet() const{
  	return isSet.instanceName;
  }
  
  const CIM_ConcreteJobInstanceName&
    CIM_ConcreteJobInstance::getInstanceName() const{

    if(!isSet.instanceName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstanceName not set in CIM_ConcreteJob instance");
  		
   	return m_instanceName;
  }

  void CIM_ConcreteJobInstance::setInstanceName(
   const CIM_ConcreteJobInstanceName& val){
    m_instanceName = val;
    isSet.instanceName=1;
  }
       
  //Caption related methods
  unsigned int CIM_ConcreteJobInstance::isCaptionSet() const{
    return isSet.Caption;
  }
  void  CIM_ConcreteJobInstance::
   setCaption(const char* val, int makeCopy){
    if (isSet.Caption) {
      delete []m_Caption;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_Caption = tmpval;
    } else {
      m_Caption = val;
    }
    isSet.Caption=1;
  }       
  const char* CIM_ConcreteJobInstance::
   getCaption() const{
    
    if(!isSet.Caption)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Caption not set");
   	   	
    return m_Caption;
  }
       
  //DeleteOnCompletion related methods
  unsigned int CIM_ConcreteJobInstance::isDeleteOnCompletionSet() const{
    return isSet.DeleteOnCompletion;
  }
  void CIM_ConcreteJobInstance::
   setDeleteOnCompletion(const CMPIBoolean val){
    m_DeleteOnCompletion = val;
    isSet.DeleteOnCompletion=1;
  }       
  const CMPIBoolean CIM_ConcreteJobInstance::
   getDeleteOnCompletion() const{
    
    if(!isSet.DeleteOnCompletion)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "DeleteOnCompletion not set");
   	   	
    return m_DeleteOnCompletion;
  }
       
  //Description related methods
  unsigned int CIM_ConcreteJobInstance::isDescriptionSet() const{
    return isSet.Description;
  }
  void  CIM_ConcreteJobInstance::
   setDescription(const char* val, int makeCopy){
    if (isSet.Description) {
      delete []m_Description;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_Description = tmpval;
    } else {
      m_Description = val;
    }
    isSet.Description=1;
  }       
  const char* CIM_ConcreteJobInstance::
   getDescription() const{
    
    if(!isSet.Description)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Description not set");
   	   	
    return m_Description;
  }
       
  //ElapsedTime related methods
  unsigned int CIM_ConcreteJobInstance::isElapsedTimeSet() const{
    return isSet.ElapsedTime;
  }
  void CIM_ConcreteJobInstance::
   setElapsedTime(const CmpiDateTime& val){
    m_ElapsedTime = val;
    isSet.ElapsedTime=1;
  }       
  const CmpiDateTime& CIM_ConcreteJobInstance::
   getElapsedTime() const{
    
    if(!isSet.ElapsedTime)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ElapsedTime not set");
   	   	
    return m_ElapsedTime;
  }
       
  //ElementName related methods
  unsigned int CIM_ConcreteJobInstance::isElementNameSet() const{
    return isSet.ElementName;
  }
  void  CIM_ConcreteJobInstance::
   setElementName(const char* val, int makeCopy){
    if (isSet.ElementName) {
      delete []m_ElementName;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_ElementName = tmpval;
    } else {
      m_ElementName = val;
    }
    isSet.ElementName=1;
  }       
  const char* CIM_ConcreteJobInstance::
   getElementName() const{
    
    if(!isSet.ElementName)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ElementName not set");
   	   	
    return m_ElementName;
  }
       
  //ErrorCode related methods
  unsigned int CIM_ConcreteJobInstance::isErrorCodeSet() const{
    return isSet.ErrorCode;
  }
  void CIM_ConcreteJobInstance::
   setErrorCode(const CMPIUint16 val){
    m_ErrorCode = val;
    isSet.ErrorCode=1;
  }       
  const CMPIUint16 CIM_ConcreteJobInstance::
   getErrorCode() const{
    
    if(!isSet.ErrorCode)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ErrorCode not set");
   	   	
    return m_ErrorCode;
  }
       
  //ErrorDescription related methods
  unsigned int CIM_ConcreteJobInstance::isErrorDescriptionSet() const{
    return isSet.ErrorDescription;
  }
  void  CIM_ConcreteJobInstance::
   setErrorDescription(const char* val, int makeCopy){
    if (isSet.ErrorDescription) {
      delete []m_ErrorDescription;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_ErrorDescription = tmpval;
    } else {
      m_ErrorDescription = val;
    }
    isSet.ErrorDescription=1;
  }       
  const char* CIM_ConcreteJobInstance::
   getErrorDescription() const{
    
    if(!isSet.ErrorDescription)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ErrorDescription not set");
   	   	
    return m_ErrorDescription;
  }
       
  //InstallDate related methods
  unsigned int CIM_ConcreteJobInstance::isInstallDateSet() const{
    return isSet.InstallDate;
  }
  void CIM_ConcreteJobInstance::
   setInstallDate(const CmpiDateTime& val){
    m_InstallDate = val;
    isSet.InstallDate=1;
  }       
  const CmpiDateTime& CIM_ConcreteJobInstance::
   getInstallDate() const{
    
    if(!isSet.InstallDate)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "InstallDate not set");
   	   	
    return m_InstallDate;
  }
       
  //JobRunTimes related methods
  unsigned int CIM_ConcreteJobInstance::isJobRunTimesSet() const{
    return isSet.JobRunTimes;
  }
  void CIM_ConcreteJobInstance::
   setJobRunTimes(const CMPIUint32 val){
    m_JobRunTimes = val;
    isSet.JobRunTimes=1;
  }       
  const CMPIUint32 CIM_ConcreteJobInstance::
   getJobRunTimes() const{
    
    if(!isSet.JobRunTimes)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "JobRunTimes not set");
   	   	
    return m_JobRunTimes;
  }
       
  //JobState related methods
  unsigned int CIM_ConcreteJobInstance::isJobStateSet() const{
    return isSet.JobState;
  }
  void CIM_ConcreteJobInstance::
   setJobState(const CMPIUint16 val){
    m_JobState = val;
    isSet.JobState=1;
  }       
  const CMPIUint16 CIM_ConcreteJobInstance::
   getJobState() const{
    
    if(!isSet.JobState)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "JobState not set");
   	   	
    return m_JobState;
  }
       
  //JobStatus related methods
  unsigned int CIM_ConcreteJobInstance::isJobStatusSet() const{
    return isSet.JobStatus;
  }
  void  CIM_ConcreteJobInstance::
   setJobStatus(const char* val, int makeCopy){
    if (isSet.JobStatus) {
      delete []m_JobStatus;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_JobStatus = tmpval;
    } else {
      m_JobStatus = val;
    }
    isSet.JobStatus=1;
  }       
  const char* CIM_ConcreteJobInstance::
   getJobStatus() const{
    
    if(!isSet.JobStatus)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "JobStatus not set");
   	   	
    return m_JobStatus;
  }
       
  //LocalOrUtcTime related methods
  unsigned int CIM_ConcreteJobInstance::isLocalOrUtcTimeSet() const{
    return isSet.LocalOrUtcTime;
  }
  void CIM_ConcreteJobInstance::
   setLocalOrUtcTime(const CMPIUint16 val){
    m_LocalOrUtcTime = val;
    isSet.LocalOrUtcTime=1;
  }       
  const CMPIUint16 CIM_ConcreteJobInstance::
   getLocalOrUtcTime() const{
    
    if(!isSet.LocalOrUtcTime)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "LocalOrUtcTime not set");
   	   	
    return m_LocalOrUtcTime;
  }
       
  //Name related methods
  unsigned int CIM_ConcreteJobInstance::isNameSet() const{
    return isSet.Name;
  }
  void  CIM_ConcreteJobInstance::
   setName(const char* val, int makeCopy){
    if (isSet.Name) {
      delete []m_Name;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_Name = tmpval;
    } else {
      m_Name = val;
    }
    isSet.Name=1;
  }       
  const char* CIM_ConcreteJobInstance::
   getName() const{
    
    if(!isSet.Name)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Name not set");
   	   	
    return m_Name;
  }
       
  //Notify related methods
  unsigned int CIM_ConcreteJobInstance::isNotifySet() const{
    return isSet.Notify;
  }
  void  CIM_ConcreteJobInstance::
   setNotify(const char* val, int makeCopy){
    if (isSet.Notify) {
      delete []m_Notify;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_Notify = tmpval;
    } else {
      m_Notify = val;
    }
    isSet.Notify=1;
  }       
  const char* CIM_ConcreteJobInstance::
   getNotify() const{
    
    if(!isSet.Notify)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Notify not set");
   	   	
    return m_Notify;
  }
       
  //OperationalStatus related methods
  unsigned int CIM_ConcreteJobInstance::isOperationalStatusSet() const{
    return isSet.OperationalStatus;
  }
  void CIM_ConcreteJobInstance::
   setOperationalStatus(const CMPIUint16* val, const unsigned int size, int makeCopy){
    OperationalStatusArraySize=size;
    if (isSet.OperationalStatus) {
      delete []m_OperationalStatus;
    }
    if (makeCopy&&val) {
      CMPIUint16* AnArray = new CMPIUint16[size];
      for(unsigned int i=0;i<size;i++)
        AnArray[i] = val[i];
      m_OperationalStatus=AnArray;
    } else {
      m_OperationalStatus = val;
    }
    isSet.OperationalStatus=1;
  }       
  const CMPIUint16* CIM_ConcreteJobInstance::
   getOperationalStatus(unsigned int& size) const{
    
    if(!isSet.OperationalStatus)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "OperationalStatus not set");
   	   	
    size=OperationalStatusArraySize;
    return m_OperationalStatus;
  }
       
  //OtherRecoveryAction related methods
  unsigned int CIM_ConcreteJobInstance::isOtherRecoveryActionSet() const{
    return isSet.OtherRecoveryAction;
  }
  void  CIM_ConcreteJobInstance::
   setOtherRecoveryAction(const char* val, int makeCopy){
    if (isSet.OtherRecoveryAction) {
      delete []m_OtherRecoveryAction;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_OtherRecoveryAction = tmpval;
    } else {
      m_OtherRecoveryAction = val;
    }
    isSet.OtherRecoveryAction=1;
  }       
  const char* CIM_ConcreteJobInstance::
   getOtherRecoveryAction() const{
    
    if(!isSet.OtherRecoveryAction)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "OtherRecoveryAction not set");
   	   	
    return m_OtherRecoveryAction;
  }
       
  //Owner related methods
  unsigned int CIM_ConcreteJobInstance::isOwnerSet() const{
    return isSet.Owner;
  }
  void  CIM_ConcreteJobInstance::
   setOwner(const char* val, int makeCopy){
    if (isSet.Owner) {
      delete []m_Owner;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_Owner = tmpval;
    } else {
      m_Owner = val;
    }
    isSet.Owner=1;
  }       
  const char* CIM_ConcreteJobInstance::
   getOwner() const{
    
    if(!isSet.Owner)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Owner not set");
   	   	
    return m_Owner;
  }
       
  //PercentComplete related methods
  unsigned int CIM_ConcreteJobInstance::isPercentCompleteSet() const{
    return isSet.PercentComplete;
  }
  void CIM_ConcreteJobInstance::
   setPercentComplete(const CMPIUint16 val){
    m_PercentComplete = val;
    isSet.PercentComplete=1;
  }       
  const CMPIUint16 CIM_ConcreteJobInstance::
   getPercentComplete() const{
    
    if(!isSet.PercentComplete)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "PercentComplete not set");
   	   	
    return m_PercentComplete;
  }
       
  //Priority related methods
  unsigned int CIM_ConcreteJobInstance::isPrioritySet() const{
    return isSet.Priority;
  }
  void CIM_ConcreteJobInstance::
   setPriority(const CMPIUint32 val){
    m_Priority = val;
    isSet.Priority=1;
  }       
  const CMPIUint32 CIM_ConcreteJobInstance::
   getPriority() const{
    
    if(!isSet.Priority)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Priority not set");
   	   	
    return m_Priority;
  }
       
  //RecoveryAction related methods
  unsigned int CIM_ConcreteJobInstance::isRecoveryActionSet() const{
    return isSet.RecoveryAction;
  }
  void CIM_ConcreteJobInstance::
   setRecoveryAction(const CMPIUint16 val){
    m_RecoveryAction = val;
    isSet.RecoveryAction=1;
  }       
  const CMPIUint16 CIM_ConcreteJobInstance::
   getRecoveryAction() const{
    
    if(!isSet.RecoveryAction)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "RecoveryAction not set");
   	   	
    return m_RecoveryAction;
  }
       
  //RunDay related methods
  unsigned int CIM_ConcreteJobInstance::isRunDaySet() const{
    return isSet.RunDay;
  }
  void CIM_ConcreteJobInstance::
   setRunDay(const CMPISint8 val){
    m_RunDay = val;
    isSet.RunDay=1;
  }       
  const CMPISint8 CIM_ConcreteJobInstance::
   getRunDay() const{
    
    if(!isSet.RunDay)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "RunDay not set");
   	   	
    return m_RunDay;
  }
       
  //RunDayOfWeek related methods
  unsigned int CIM_ConcreteJobInstance::isRunDayOfWeekSet() const{
    return isSet.RunDayOfWeek;
  }
  void CIM_ConcreteJobInstance::
   setRunDayOfWeek(const CMPISint8 val){
    m_RunDayOfWeek = val;
    isSet.RunDayOfWeek=1;
  }       
  const CMPISint8 CIM_ConcreteJobInstance::
   getRunDayOfWeek() const{
    
    if(!isSet.RunDayOfWeek)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "RunDayOfWeek not set");
   	   	
    return m_RunDayOfWeek;
  }
       
  //RunMonth related methods
  unsigned int CIM_ConcreteJobInstance::isRunMonthSet() const{
    return isSet.RunMonth;
  }
  void CIM_ConcreteJobInstance::
   setRunMonth(const CMPIUint8 val){
    m_RunMonth = val;
    isSet.RunMonth=1;
  }       
  const CMPIUint8 CIM_ConcreteJobInstance::
   getRunMonth() const{
    
    if(!isSet.RunMonth)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "RunMonth not set");
   	   	
    return m_RunMonth;
  }
       
  //RunStartInterval related methods
  unsigned int CIM_ConcreteJobInstance::isRunStartIntervalSet() const{
    return isSet.RunStartInterval;
  }
  void CIM_ConcreteJobInstance::
   setRunStartInterval(const CmpiDateTime& val){
    m_RunStartInterval = val;
    isSet.RunStartInterval=1;
  }       
  const CmpiDateTime& CIM_ConcreteJobInstance::
   getRunStartInterval() const{
    
    if(!isSet.RunStartInterval)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "RunStartInterval not set");
   	   	
    return m_RunStartInterval;
  }
       
  //ScheduledStartTime related methods
  unsigned int CIM_ConcreteJobInstance::isScheduledStartTimeSet() const{
    return isSet.ScheduledStartTime;
  }
  void CIM_ConcreteJobInstance::
   setScheduledStartTime(const CmpiDateTime& val){
    m_ScheduledStartTime = val;
    isSet.ScheduledStartTime=1;
  }       
  const CmpiDateTime& CIM_ConcreteJobInstance::
   getScheduledStartTime() const{
    
    if(!isSet.ScheduledStartTime)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "ScheduledStartTime not set");
   	   	
    return m_ScheduledStartTime;
  }
       
  //StartTime related methods
  unsigned int CIM_ConcreteJobInstance::isStartTimeSet() const{
    return isSet.StartTime;
  }
  void CIM_ConcreteJobInstance::
   setStartTime(const CmpiDateTime& val){
    m_StartTime = val;
    isSet.StartTime=1;
  }       
  const CmpiDateTime& CIM_ConcreteJobInstance::
   getStartTime() const{
    
    if(!isSet.StartTime)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "StartTime not set");
   	   	
    return m_StartTime;
  }
       
  //Status related methods
  unsigned int CIM_ConcreteJobInstance::isStatusSet() const{
    return isSet.Status;
  }
  void  CIM_ConcreteJobInstance::
   setStatus(const char* val, int makeCopy){
    if (isSet.Status) {
      delete []m_Status;
    }
    if (makeCopy&&val) {
      char* tmpval = new char[strlen(val)+1];
      strcpy(tmpval,val);
      m_Status = tmpval;
    } else {
      m_Status = val;
    }
    isSet.Status=1;
  }       
  const char* CIM_ConcreteJobInstance::
   getStatus() const{
    
    if(!isSet.Status)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "Status not set");
   	   	
    return m_Status;
  }
       
  //StatusDescriptions related methods
  unsigned int CIM_ConcreteJobInstance::isStatusDescriptionsSet() const{
    return isSet.StatusDescriptions;
  }
  void  CIM_ConcreteJobInstance::
   setStatusDescriptions(const char** val, const unsigned int size, int makeCopy){
    StatusDescriptionsArraySize=size;
    if (isSet.StatusDescriptions) {
      delete m_StatusDescriptions;
    }
    if (makeCopy&&val) {
      m_StatusDescriptions = new const char*[size];
      for(unsigned int i=0;i<size;i++){
        char* aString = new char[strlen(val[i])+1];
        strcpy(aString,val[i]);
        m_StatusDescriptions[i]=aString;
      }      
    } else {
      m_StatusDescriptions = val;
    }
    isSet.StatusDescriptions=1;
  }       
  const char** CIM_ConcreteJobInstance::
   getStatusDescriptions(unsigned int& size) const{
    
    if(!isSet.StatusDescriptions)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "StatusDescriptions not set");
   	   	
    size=StatusDescriptionsArraySize;
    return m_StatusDescriptions;
  }
       
  //TimeBeforeRemoval related methods
  unsigned int CIM_ConcreteJobInstance::isTimeBeforeRemovalSet() const{
    return isSet.TimeBeforeRemoval;
  }
  void CIM_ConcreteJobInstance::
   setTimeBeforeRemoval(const CmpiDateTime& val){
    m_TimeBeforeRemoval = val;
    isSet.TimeBeforeRemoval=1;
  }       
  const CmpiDateTime& CIM_ConcreteJobInstance::
   getTimeBeforeRemoval() const{
    
    if(!isSet.TimeBeforeRemoval)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "TimeBeforeRemoval not set");
   	   	
    return m_TimeBeforeRemoval;
  }
       
  //TimeOfLastStateChange related methods
  unsigned int CIM_ConcreteJobInstance::isTimeOfLastStateChangeSet() const{
    return isSet.TimeOfLastStateChange;
  }
  void CIM_ConcreteJobInstance::
   setTimeOfLastStateChange(const CmpiDateTime& val){
    m_TimeOfLastStateChange = val;
    isSet.TimeOfLastStateChange=1;
  }       
  const CmpiDateTime& CIM_ConcreteJobInstance::
   getTimeOfLastStateChange() const{
    
    if(!isSet.TimeOfLastStateChange)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "TimeOfLastStateChange not set");
   	   	
    return m_TimeOfLastStateChange;
  }
       
  //TimeSubmitted related methods
  unsigned int CIM_ConcreteJobInstance::isTimeSubmittedSet() const{
    return isSet.TimeSubmitted;
  }
  void CIM_ConcreteJobInstance::
   setTimeSubmitted(const CmpiDateTime& val){
    m_TimeSubmitted = val;
    isSet.TimeSubmitted=1;
  }       
  const CmpiDateTime& CIM_ConcreteJobInstance::
   getTimeSubmitted() const{
    
    if(!isSet.TimeSubmitted)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "TimeSubmitted not set");
   	   	
    return m_TimeSubmitted;
  }
       
  //UntilTime related methods
  unsigned int CIM_ConcreteJobInstance::isUntilTimeSet() const{
    return isSet.UntilTime;
  }
  void CIM_ConcreteJobInstance::
   setUntilTime(const CmpiDateTime& val){
    m_UntilTime = val;
    isSet.UntilTime=1;
  }       
  const CmpiDateTime& CIM_ConcreteJobInstance::
   getUntilTime() const{
    
    if(!isSet.UntilTime)
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_SET,
   	   "UntilTime not set");
   	   	
    return m_UntilTime;
  }


  
  //set isSet attributes to FALSE
  void CIM_ConcreteJobInstance::init(){
   	isSet.instanceName=0;
   	   	
    isSet.Caption=0;   	
    isSet.DeleteOnCompletion=0;   	
    isSet.Description=0;   	
    isSet.ElapsedTime=0;   	
    isSet.ElementName=0;   	
    isSet.ErrorCode=0;   	
    isSet.ErrorDescription=0;   	
    isSet.InstallDate=0;   	
    isSet.JobRunTimes=0;   	
    isSet.JobState=0;   	
    isSet.JobStatus=0;   	
    isSet.LocalOrUtcTime=0;   	
    isSet.Name=0;   	
    isSet.Notify=0;   	
    isSet.OperationalStatus=0;   	
    OperationalStatusArraySize=0;   	
    isSet.OtherRecoveryAction=0;   	
    isSet.Owner=0;   	
    isSet.PercentComplete=0;   	
    isSet.Priority=0;   	
    isSet.RecoveryAction=0;   	
    isSet.RunDay=0;   	
    isSet.RunDayOfWeek=0;   	
    isSet.RunMonth=0;   	
    isSet.RunStartInterval=0;   	
    isSet.ScheduledStartTime=0;   	
    isSet.StartTime=0;   	
    isSet.Status=0;   	
    isSet.StatusDescriptions=0;   	
    StatusDescriptionsArraySize=0;   	
    isSet.TimeBeforeRemoval=0;   	
    isSet.TimeOfLastStateChange=0;   	
    isSet.TimeSubmitted=0;   	
    isSet.UntilTime=0;  	
  };
  
  
  //copies another instance properties in this
  void CIM_ConcreteJobInstance::init
   (const CIM_ConcreteJobInstance& original){   	
   	init();
   	   	
    if(original.isInstanceNameSet()){
      setInstanceName(original.getInstanceName());
    }   	
    if(original.isCaptionSet()){
      const char* CaptionOriginal=original.getCaption();
      setCaption(CaptionOriginal, 1);
    }   	
    if(original.isDeleteOnCompletionSet()){
      const CMPIBoolean DeleteOnCompletionOriginal=original.getDeleteOnCompletion();
      setDeleteOnCompletion(DeleteOnCompletionOriginal);
    }   	
    if(original.isDescriptionSet()){
      const char* DescriptionOriginal=original.getDescription();
      setDescription(DescriptionOriginal, 1);
    }   	
    if(original.isElapsedTimeSet()){
      const CmpiDateTime& ElapsedTimeOriginal=original.getElapsedTime();
      setElapsedTime(ElapsedTimeOriginal);
    }   	
    if(original.isElementNameSet()){
      const char* ElementNameOriginal=original.getElementName();
      setElementName(ElementNameOriginal, 1);
    }   	
    if(original.isErrorCodeSet()){
      const CMPIUint16 ErrorCodeOriginal=original.getErrorCode();
      setErrorCode(ErrorCodeOriginal);
    }   	
    if(original.isErrorDescriptionSet()){
      const char* ErrorDescriptionOriginal=original.getErrorDescription();
      setErrorDescription(ErrorDescriptionOriginal, 1);
    }   	
    if(original.isInstallDateSet()){
      const CmpiDateTime& InstallDateOriginal=original.getInstallDate();
      setInstallDate(InstallDateOriginal);
    }   	
    if(original.isJobRunTimesSet()){
      const CMPIUint32 JobRunTimesOriginal=original.getJobRunTimes();
      setJobRunTimes(JobRunTimesOriginal);
    }   	
    if(original.isJobStateSet()){
      const CMPIUint16 JobStateOriginal=original.getJobState();
      setJobState(JobStateOriginal);
    }   	
    if(original.isJobStatusSet()){
      const char* JobStatusOriginal=original.getJobStatus();
      setJobStatus(JobStatusOriginal, 1);
    }   	
    if(original.isLocalOrUtcTimeSet()){
      const CMPIUint16 LocalOrUtcTimeOriginal=original.getLocalOrUtcTime();
      setLocalOrUtcTime(LocalOrUtcTimeOriginal);
    }   	
    if(original.isNameSet()){
      const char* NameOriginal=original.getName();
      setName(NameOriginal, 1);
    }   	
    if(original.isNotifySet()){
      const char* NotifyOriginal=original.getNotify();
      setNotify(NotifyOriginal, 1);
    }   	
    if(original.isOperationalStatusSet()){
      unsigned int sizeOperationalStatus;
    const CMPIUint16* OperationalStatusOriginal=original.getOperationalStatus(sizeOperationalStatus);
      setOperationalStatus(OperationalStatusOriginal, sizeOperationalStatus, 1);
    }   	
    if(original.isOtherRecoveryActionSet()){
      const char* OtherRecoveryActionOriginal=original.getOtherRecoveryAction();
      setOtherRecoveryAction(OtherRecoveryActionOriginal, 1);
    }   	
    if(original.isOwnerSet()){
      const char* OwnerOriginal=original.getOwner();
      setOwner(OwnerOriginal, 1);
    }   	
    if(original.isPercentCompleteSet()){
      const CMPIUint16 PercentCompleteOriginal=original.getPercentComplete();
      setPercentComplete(PercentCompleteOriginal);
    }   	
    if(original.isPrioritySet()){
      const CMPIUint32 PriorityOriginal=original.getPriority();
      setPriority(PriorityOriginal);
    }   	
    if(original.isRecoveryActionSet()){
      const CMPIUint16 RecoveryActionOriginal=original.getRecoveryAction();
      setRecoveryAction(RecoveryActionOriginal);
    }   	
    if(original.isRunDaySet()){
      const CMPISint8 RunDayOriginal=original.getRunDay();
      setRunDay(RunDayOriginal);
    }   	
    if(original.isRunDayOfWeekSet()){
      const CMPISint8 RunDayOfWeekOriginal=original.getRunDayOfWeek();
      setRunDayOfWeek(RunDayOfWeekOriginal);
    }   	
    if(original.isRunMonthSet()){
      const CMPIUint8 RunMonthOriginal=original.getRunMonth();
      setRunMonth(RunMonthOriginal);
    }   	
    if(original.isRunStartIntervalSet()){
      const CmpiDateTime& RunStartIntervalOriginal=original.getRunStartInterval();
      setRunStartInterval(RunStartIntervalOriginal);
    }   	
    if(original.isScheduledStartTimeSet()){
      const CmpiDateTime& ScheduledStartTimeOriginal=original.getScheduledStartTime();
      setScheduledStartTime(ScheduledStartTimeOriginal);
    }   	
    if(original.isStartTimeSet()){
      const CmpiDateTime& StartTimeOriginal=original.getStartTime();
      setStartTime(StartTimeOriginal);
    }   	
    if(original.isStatusSet()){
      const char* StatusOriginal=original.getStatus();
      setStatus(StatusOriginal, 1);
    }   	
    if(original.isStatusDescriptionsSet()){
      unsigned int sizeStatusDescriptions;
    const char** StatusDescriptionsOriginal=original.getStatusDescriptions(sizeStatusDescriptions);
      setStatusDescriptions(StatusDescriptionsOriginal, sizeStatusDescriptions, 1);
    }   	
    if(original.isTimeBeforeRemovalSet()){
      const CmpiDateTime& TimeBeforeRemovalOriginal=original.getTimeBeforeRemoval();
      setTimeBeforeRemoval(TimeBeforeRemovalOriginal);
    }   	
    if(original.isTimeOfLastStateChangeSet()){
      const CmpiDateTime& TimeOfLastStateChangeOriginal=original.getTimeOfLastStateChange();
      setTimeOfLastStateChange(TimeOfLastStateChangeOriginal);
    }   	
    if(original.isTimeSubmittedSet()){
      const CmpiDateTime& TimeSubmittedOriginal=original.getTimeSubmitted();
      setTimeSubmitted(TimeSubmittedOriginal);
    }   	
    if(original.isUntilTimeSet()){
      const CmpiDateTime& UntilTimeOriginal=original.getUntilTime();
      setUntilTime(UntilTimeOriginal);
    }    
   }
  
  
  //reset the instance data
  void CIM_ConcreteJobInstance::reset(){
   	

  	if (isSet.Caption)
  	  delete(m_Caption);

  	if (isSet.Description)
  	  delete(m_Description);

  	if (isSet.ElementName)
  	  delete(m_ElementName);

  	if (isSet.ErrorDescription)
  	  delete(m_ErrorDescription);

  	if (isSet.JobStatus)
  	  delete(m_JobStatus);

  	if (isSet.Name)
  	  delete(m_Name);

  	if (isSet.Notify)
  	  delete(m_Notify);

  	if (isSet.OperationalStatus){
  	  ArrayConverter::destructArray((CMPIUint16*)m_OperationalStatus);
  	}

  	if (isSet.OtherRecoveryAction)
  	  delete(m_OtherRecoveryAction);

  	if (isSet.Owner)
  	  delete(m_Owner);

  	if (isSet.Status)
  	  delete(m_Status);

  	if (isSet.StatusDescriptions){
  	  ArrayConverter::destructArray((char**)(char**)m_StatusDescriptions,StatusDescriptionsArraySize);
  	}
  	  
  };
  
  
  //*********************************************************
  //CIM_ConcreteJobInstanceEnumerationElement	
  //*********************************************************
  
  CIM_ConcreteJobInstanceEnumerationElement::
   CIM_ConcreteJobInstanceEnumerationElement(){
   	
  	m_elementP=0;
  	m_nextP=0;
  	  
  };
  
  
  CIM_ConcreteJobInstanceEnumerationElement::
   ~CIM_ConcreteJobInstanceEnumerationElement(){
   	
  	if (m_elementP!=0)
  	  delete(m_elementP);
  	if (m_nextP!=0)
  	  delete(m_nextP);
  	  
  };

  
  //*********************************************************
  //CIM_ConcreteJobInstanceNameEnumeration
  //*********************************************************

  CIM_ConcreteJobInstanceEnumeration::
   CIM_ConcreteJobInstanceEnumeration(){
   	
  	 firstElementP=0;
     currentElementP=0;
     endElementP=0;
  };
  
  CIM_ConcreteJobInstanceEnumeration::
   CIM_ConcreteJobInstanceEnumeration(
   const CIM_ConcreteJobInstanceEnumeration& original){
   	
     firstElementP=0;
     currentElementP=0;
     endElementP=0;
  	 
     int size=original.getSize();
     for(int i=0;i<size;i++)
       addElement(original.getElement(i));           
  };
  
  	  
  CIM_ConcreteJobInstanceEnumeration::
   ~CIM_ConcreteJobInstanceEnumeration(){
   	
  	if (firstElementP!=0)
  	  delete(firstElementP);
  	  	
  };
  
  	  
  void CIM_ConcreteJobInstanceEnumeration::reset(){
  	
  	currentElementP=firstElementP;
  };
  
  	  
  bool CIM_ConcreteJobInstanceEnumeration::hasNext() const{
  	
  	return (currentElementP!=0);
  
  };
  
  int CIM_ConcreteJobInstanceEnumeration::getSize() const{
  	
    int size=0;
    CIM_ConcreteJobInstanceEnumerationElement* followingP=firstElementP;
  	
  	while(followingP!=0){
        followingP=followingP->m_nextP;
        size++;
    }
  	
    return size;
    
  };
  
  const CIM_ConcreteJobInstance&  
   CIM_ConcreteJobInstanceEnumeration::getElement(int pos) const{
   
    CIM_ConcreteJobInstanceEnumerationElement* followingP=firstElementP;
   
    int i=0;
    while((followingP!=0)&&(i<pos)){
        followingP=followingP->m_nextP;
        i++;
    }
    
    return *(followingP->m_elementP);
  };
  
  	  
  const CIM_ConcreteJobInstance&
   CIM_ConcreteJobInstanceEnumeration::getNext() {
   	
  	 CIM_ConcreteJobInstanceEnumerationElement* currentP=
  	  currentElementP;
  	 currentElementP=currentElementP->m_nextP;
  	 
  	 return *(currentP->m_elementP);
  };
  	  
  void CIM_ConcreteJobInstanceEnumeration::addElement
   (const CIM_ConcreteJobInstance& elementP){
   	
  	if(firstElementP==0){
  	  firstElementP=new CIM_ConcreteJobInstanceEnumerationElement();
  	  firstElementP->m_elementP=new CIM_ConcreteJobInstance(elementP);
  	  endElementP=firstElementP;
  	  currentElementP=firstElementP;
  	}else{
  	  endElementP->m_nextP=new CIM_ConcreteJobInstanceEnumerationElement();
  	  endElementP=endElementP->m_nextP;
  	  endElementP->m_elementP=new CIM_ConcreteJobInstance(elementP);
  	}
  };  
}
 
