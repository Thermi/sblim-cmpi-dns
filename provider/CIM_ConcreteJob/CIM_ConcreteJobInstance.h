 /**
 * CIM_ConcreteJobInstance.h
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
#ifndef CIM_ConcreteJobInstance_h
#define CIM_ConcreteJobInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "CIM_ConcreteJobInstanceName.h"

namespace genProvider {

  class CIM_ConcreteJobInstance {
  public:
       CIM_ConcreteJobInstance();
  	
       CIM_ConcreteJobInstance
  	    (const CIM_ConcreteJobInstance& original);
  	   
       CIM_ConcreteJobInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~CIM_ConcreteJobInstance();
       
       CIM_ConcreteJobInstance& operator=
  	    (const CIM_ConcreteJobInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const CIM_ConcreteJobInstanceName& val);        
       const CIM_ConcreteJobInstanceName&
        getInstanceName() const;

       unsigned int isCaptionSet() const;
       void setCaption(const char* val, int makeCopy = 1);
       const char* getCaption() const;

       unsigned int isDeleteOnCompletionSet() const;
       void setDeleteOnCompletion(const CMPIBoolean val);
       const CMPIBoolean getDeleteOnCompletion() const;

       unsigned int isDescriptionSet() const;
       void setDescription(const char* val, int makeCopy = 1);
       const char* getDescription() const;

       unsigned int isElapsedTimeSet() const;
       void setElapsedTime(const CmpiDateTime& val);
       const CmpiDateTime& getElapsedTime() const;

       unsigned int isElementNameSet() const;
       void setElementName(const char* val, int makeCopy = 1);
       const char* getElementName() const;

       unsigned int isErrorCodeSet() const;
       void setErrorCode(const CMPIUint16 val);
       const CMPIUint16 getErrorCode() const;

       unsigned int isErrorDescriptionSet() const;
       void setErrorDescription(const char* val, int makeCopy = 1);
       const char* getErrorDescription() const;

       unsigned int isInstallDateSet() const;
       void setInstallDate(const CmpiDateTime& val);
       const CmpiDateTime& getInstallDate() const;

       unsigned int isJobRunTimesSet() const;
       void setJobRunTimes(const CMPIUint32 val);
       const CMPIUint32 getJobRunTimes() const;

       unsigned int isJobStateSet() const;
       void setJobState(const CMPIUint16 val);
       const CMPIUint16 getJobState() const;

       unsigned int isJobStatusSet() const;
       void setJobStatus(const char* val, int makeCopy = 1);
       const char* getJobStatus() const;

       unsigned int isLocalOrUtcTimeSet() const;
       void setLocalOrUtcTime(const CMPIUint16 val);
       const CMPIUint16 getLocalOrUtcTime() const;

       unsigned int isNameSet() const;
       void setName(const char* val, int makeCopy = 1);
       const char* getName() const;

       unsigned int isNotifySet() const;
       void setNotify(const char* val, int makeCopy = 1);
       const char* getNotify() const;

       unsigned int isOperationalStatusSet() const;
       void setOperationalStatus(const CMPIUint16* val, unsigned const int size, int makeCopy = 1);
       const CMPIUint16* getOperationalStatus(unsigned int& size) const;

       unsigned int isOtherRecoveryActionSet() const;
       void setOtherRecoveryAction(const char* val, int makeCopy = 1);
       const char* getOtherRecoveryAction() const;

       unsigned int isOwnerSet() const;
       void setOwner(const char* val, int makeCopy = 1);
       const char* getOwner() const;

       unsigned int isPercentCompleteSet() const;
       void setPercentComplete(const CMPIUint16 val);
       const CMPIUint16 getPercentComplete() const;

       unsigned int isPrioritySet() const;
       void setPriority(const CMPIUint32 val);
       const CMPIUint32 getPriority() const;

       unsigned int isRecoveryActionSet() const;
       void setRecoveryAction(const CMPIUint16 val);
       const CMPIUint16 getRecoveryAction() const;

       unsigned int isRunDaySet() const;
       void setRunDay(const CMPISint8 val);
       const CMPISint8 getRunDay() const;

       unsigned int isRunDayOfWeekSet() const;
       void setRunDayOfWeek(const CMPISint8 val);
       const CMPISint8 getRunDayOfWeek() const;

       unsigned int isRunMonthSet() const;
       void setRunMonth(const CMPIUint8 val);
       const CMPIUint8 getRunMonth() const;

       unsigned int isRunStartIntervalSet() const;
       void setRunStartInterval(const CmpiDateTime& val);
       const CmpiDateTime& getRunStartInterval() const;

       unsigned int isScheduledStartTimeSet() const;
       void setScheduledStartTime(const CmpiDateTime& val);
       const CmpiDateTime& getScheduledStartTime() const;

       unsigned int isStartTimeSet() const;
       void setStartTime(const CmpiDateTime& val);
       const CmpiDateTime& getStartTime() const;

       unsigned int isStatusSet() const;
       void setStatus(const char* val, int makeCopy = 1);
       const char* getStatus() const;

       unsigned int isStatusDescriptionsSet() const;
       void setStatusDescriptions(const char** val, unsigned const int size, int makeCopy = 1);
       const char** getStatusDescriptions(unsigned int& size) const;

       unsigned int isTimeBeforeRemovalSet() const;
       void setTimeBeforeRemoval(const CmpiDateTime& val);
       const CmpiDateTime& getTimeBeforeRemoval() const;

       unsigned int isTimeOfLastStateChangeSet() const;
       void setTimeOfLastStateChange(const CmpiDateTime& val);
       const CmpiDateTime& getTimeOfLastStateChange() const;

       unsigned int isTimeSubmittedSet() const;
       void setTimeSubmitted(const CmpiDateTime& val);
       const CmpiDateTime& getTimeSubmitted() const;

       unsigned int isUntilTimeSet() const;
       void setUntilTime(const CmpiDateTime& val);
       const CmpiDateTime& getUntilTime() const;
       
  private:
       void init();
       void init(const CIM_ConcreteJobInstance& original);
       void reset();
       
       CIM_ConcreteJobInstanceName m_instanceName;
       const char* m_Caption;
       CMPIBoolean m_DeleteOnCompletion;
       const char* m_Description;
       CmpiDateTime m_ElapsedTime;
       const char* m_ElementName;
       CMPIUint16 m_ErrorCode;
       const char* m_ErrorDescription;
       CmpiDateTime m_InstallDate;
       CMPIUint32 m_JobRunTimes;
       CMPIUint16 m_JobState;
       const char* m_JobStatus;
       CMPIUint16 m_LocalOrUtcTime;
       const char* m_Name;
       const char* m_Notify;
       const CMPIUint16* m_OperationalStatus;
        unsigned int OperationalStatusArraySize;
       const char* m_OtherRecoveryAction;
       const char* m_Owner;
       CMPIUint16 m_PercentComplete;
       CMPIUint32 m_Priority;
       CMPIUint16 m_RecoveryAction;
       CMPISint8 m_RunDay;
       CMPISint8 m_RunDayOfWeek;
       CMPIUint8 m_RunMonth;
       CmpiDateTime m_RunStartInterval;
       CmpiDateTime m_ScheduledStartTime;
       CmpiDateTime m_StartTime;
       const char* m_Status;
       const char** m_StatusDescriptions;
        unsigned int StatusDescriptionsArraySize;
       CmpiDateTime m_TimeBeforeRemoval;
       CmpiDateTime m_TimeOfLastStateChange;
       CmpiDateTime m_TimeSubmitted;
       CmpiDateTime m_UntilTime;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int Caption:1;
         unsigned int DeleteOnCompletion:1;
         unsigned int Description:1;
         unsigned int ElapsedTime:1;
         unsigned int ElementName:1;
         unsigned int ErrorCode:1;
         unsigned int ErrorDescription:1;
         unsigned int InstallDate:1;
         unsigned int JobRunTimes:1;
         unsigned int JobState:1;
         unsigned int JobStatus:1;
         unsigned int LocalOrUtcTime:1;
         unsigned int Name:1;
         unsigned int Notify:1;
         unsigned int OperationalStatus:1;
         unsigned int OtherRecoveryAction:1;
         unsigned int Owner:1;
         unsigned int PercentComplete:1;
         unsigned int Priority:1;
         unsigned int RecoveryAction:1;
         unsigned int RunDay:1;
         unsigned int RunDayOfWeek:1;
         unsigned int RunMonth:1;
         unsigned int RunStartInterval:1;
         unsigned int ScheduledStartTime:1;
         unsigned int StartTime:1;
         unsigned int Status:1;
         unsigned int StatusDescriptions:1;
         unsigned int TimeBeforeRemoval:1;
         unsigned int TimeOfLastStateChange:1;
         unsigned int TimeSubmitted:1;
         unsigned int UntilTime:1;
       } isSet;
  };
  
  
  struct CIM_ConcreteJobInstanceEnumerationElement{
  	CIM_ConcreteJobInstance* m_elementP;
  	CIM_ConcreteJobInstanceEnumerationElement* m_nextP;
  	
  	CIM_ConcreteJobInstanceEnumerationElement();
  	~CIM_ConcreteJobInstanceEnumerationElement();  	
  };
  

  class CIM_ConcreteJobInstanceEnumeration {
  	private:
  	  CIM_ConcreteJobInstanceEnumerationElement* firstElementP;
  	  CIM_ConcreteJobInstanceEnumerationElement* currentElementP;
  	  CIM_ConcreteJobInstanceEnumerationElement* endElementP;
  	
  	public:
  	  CIM_ConcreteJobInstanceEnumeration();
  	  
  	  CIM_ConcreteJobInstanceEnumeration(
  	   const CIM_ConcreteJobInstanceEnumeration& original);
  	  
  	  ~CIM_ConcreteJobInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const CIM_ConcreteJobInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const CIM_ConcreteJobInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const CIM_ConcreteJobInstance& elementP);
  };
}
#endif

