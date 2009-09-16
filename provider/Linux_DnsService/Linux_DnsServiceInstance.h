// =======================================================================
// Linux_DnsServiceInstance.h
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
#ifndef Linux_DnsServiceInstance_h
#define Linux_DnsServiceInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceInstance {
       
    private:
    void init();
    void init(const Linux_DnsServiceInstance& anInstance);
    void reset();
       
    Linux_DnsServiceInstanceName m_instanceName;
    const char* m_Caption;
    const char* m_Description;
    const char* m_ElementName;
    CMPIUint16 m_EnabledDefault;
    CMPIUint16 m_EnabledState;
    CmpiDateTime m_InstallDate;
    const CMPIUint16* m_OperationalStatus;
    unsigned int m_OperationalStatusSize;
    const char* m_OtherEnabledState;
    const char* m_PrimaryOwnerContact;
    const char* m_PrimaryOwnerName;
    CMPIUint16 m_RequestedState;
    CMPIBoolean m_RunAsRoot;
    const char* m_StartMode;
    CMPIBoolean m_Started;
    const char* m_Status;
    const char** m_StatusDescriptions;
    unsigned int m_StatusDescriptionsSize;
    CmpiDateTime m_TimeOfLastStateChange;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int Caption:1;
      unsigned int Description:1;
      unsigned int ElementName:1;
      unsigned int EnabledDefault:1;
      unsigned int EnabledState:1;
      unsigned int InstallDate:1;
      unsigned int OperationalStatus:1;
      unsigned int OtherEnabledState:1;
      unsigned int PrimaryOwnerContact:1;
      unsigned int PrimaryOwnerName:1;
      unsigned int RequestedState:1;
      unsigned int RunAsRoot:1;
      unsigned int StartMode:1;
      unsigned int Started:1;
      unsigned int Status:1;
      unsigned int StatusDescriptions:1;
      unsigned int TimeOfLastStateChange:1;

    } isSet;
    
    public:
    Linux_DnsServiceInstance();
    Linux_DnsServiceInstance(
      const Linux_DnsServiceInstance& anInstance);
    Linux_DnsServiceInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsServiceInstance();
       
    Linux_DnsServiceInstance& operator=(
      const Linux_DnsServiceInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsServiceInstanceName& anInstanceName);        
    const Linux_DnsServiceInstanceName& getInstanceName() const;

    unsigned int isCaptionSet() const;
    void setCaption(const char* aValue, int aCopyFlag = 1);
    const char* getCaption() const;

    unsigned int isDescriptionSet() const;
    void setDescription(const char* aValue, int aCopyFlag = 1);
    const char* getDescription() const;

    unsigned int isElementNameSet() const;
    void setElementName(const char* aValue, int aCopyFlag = 1);
    const char* getElementName() const;

    unsigned int isEnabledDefaultSet() const;
    void setEnabledDefault(const CMPIUint16 aValue);
    const CMPIUint16 getEnabledDefault() const;

    unsigned int isEnabledStateSet() const;
    void setEnabledState(const CMPIUint16 aValue);
    const CMPIUint16 getEnabledState() const;

    unsigned int isInstallDateSet() const;
    void setInstallDate(const CmpiDateTime& aValue);
    const CmpiDateTime& getInstallDate() const;

    unsigned int isOperationalStatusSet() const;
    void setOperationalStatus(const CMPIUint16* aValue, unsigned const int aSize, int aCopyFlag = 1);
    const CMPIUint16* getOperationalStatus(unsigned int& aSize) const;

    unsigned int isOtherEnabledStateSet() const;
    void setOtherEnabledState(const char* aValue, int aCopyFlag = 1);
    const char* getOtherEnabledState() const;

    unsigned int isPrimaryOwnerContactSet() const;
    void setPrimaryOwnerContact(const char* aValue, int aCopyFlag = 1);
    const char* getPrimaryOwnerContact() const;

    unsigned int isPrimaryOwnerNameSet() const;
    void setPrimaryOwnerName(const char* aValue, int aCopyFlag = 1);
    const char* getPrimaryOwnerName() const;

    unsigned int isRequestedStateSet() const;
    void setRequestedState(const CMPIUint16 aValue);
    const CMPIUint16 getRequestedState() const;

    unsigned int isRunAsRootSet() const;
    void setRunAsRoot(const CMPIBoolean aValue);
    const CMPIBoolean getRunAsRoot() const;

    unsigned int isStartModeSet() const;
    void setStartMode(const char* aValue, int aCopyFlag = 1);
    const char* getStartMode() const;

    unsigned int isStartedSet() const;
    void setStarted(const CMPIBoolean aValue);
    const CMPIBoolean getStarted() const;

    unsigned int isStatusSet() const;
    void setStatus(const char* aValue, int aCopyFlag = 1);
    const char* getStatus() const;

    unsigned int isStatusDescriptionsSet() const;
    void setStatusDescriptions(const char** aValue, unsigned const int aSize, int aCopyFlag = 1);
    const char** getStatusDescriptions(unsigned int& aSize) const;

    unsigned int isTimeOfLastStateChangeSet() const;
    void setTimeOfLastStateChange(const CmpiDateTime& aValue);
    const CmpiDateTime& getTimeOfLastStateChange() const;


  };
  
  struct Linux_DnsServiceInstanceEnumerationElement {

    Linux_DnsServiceInstance* m_elementP;
    Linux_DnsServiceInstanceEnumerationElement* m_nextP;

    Linux_DnsServiceInstanceEnumerationElement();
    ~Linux_DnsServiceInstanceEnumerationElement();  

  };
  

  class Linux_DnsServiceInstanceEnumeration {

    private:
    Linux_DnsServiceInstanceEnumerationElement* m_firstElementP;
    Linux_DnsServiceInstanceEnumerationElement* m_currentElementP;
    Linux_DnsServiceInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsServiceInstanceEnumeration();
    Linux_DnsServiceInstanceEnumeration(
      const Linux_DnsServiceInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsServiceInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsServiceInstance& getNext();
    int getSize() const;
    const Linux_DnsServiceInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsServiceInstance& anInstance);

  };

}

#endif
