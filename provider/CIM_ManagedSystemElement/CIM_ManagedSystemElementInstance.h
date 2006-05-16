// =======================================================================
// CIM_ManagedSystemElementInstance.h
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
#ifndef CIM_ManagedSystemElementInstance_h
#define CIM_ManagedSystemElementInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "CIM_ManagedSystemElementInstanceName.h"


namespace genProvider {

  class CIM_ManagedSystemElementInstance {
       
    private:
    void init();
    void init(const CIM_ManagedSystemElementInstance& anInstance);
    void reset();
       
    CIM_ManagedSystemElementInstanceName m_instanceName;
    const char* m_Caption;
    const char* m_Description;
    const char* m_ElementName;
    CmpiDateTime m_InstallDate;
    const char* m_Name;
    const CMPIUint16* m_OperationalStatus;
    unsigned int m_OperationalStatusSize;
    const char* m_Status;
    const char** m_StatusDescriptions;
    unsigned int m_StatusDescriptionsSize;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int Caption:1;
      unsigned int Description:1;
      unsigned int ElementName:1;
      unsigned int InstallDate:1;
      unsigned int Name:1;
      unsigned int OperationalStatus:1;
      unsigned int Status:1;
      unsigned int StatusDescriptions:1;

    } isSet;
    
    public:
    CIM_ManagedSystemElementInstance();
    CIM_ManagedSystemElementInstance(
      const CIM_ManagedSystemElementInstance& anInstance);
    CIM_ManagedSystemElementInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~CIM_ManagedSystemElementInstance();
       
    CIM_ManagedSystemElementInstance& operator=(
      const CIM_ManagedSystemElementInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const CIM_ManagedSystemElementInstanceName& anInstanceName);        
    const CIM_ManagedSystemElementInstanceName& getInstanceName() const;

    unsigned int isCaptionSet() const;
    void setCaption(const char* aValue, int aCopyFlag = 1);
    const char* getCaption() const;

    unsigned int isDescriptionSet() const;
    void setDescription(const char* aValue, int aCopyFlag = 1);
    const char* getDescription() const;

    unsigned int isElementNameSet() const;
    void setElementName(const char* aValue, int aCopyFlag = 1);
    const char* getElementName() const;

    unsigned int isInstallDateSet() const;
    void setInstallDate(const CmpiDateTime& aValue);
    const CmpiDateTime& getInstallDate() const;

    unsigned int isNameSet() const;
    void setName(const char* aValue, int aCopyFlag = 1);
    const char* getName() const;

    unsigned int isOperationalStatusSet() const;
    void setOperationalStatus(const CMPIUint16* aValue, unsigned const int aSize, int aCopyFlag = 1);
    const CMPIUint16* getOperationalStatus(unsigned int& aSize) const;

    unsigned int isStatusSet() const;
    void setStatus(const char* aValue, int aCopyFlag = 1);
    const char* getStatus() const;

    unsigned int isStatusDescriptionsSet() const;
    void setStatusDescriptions(const char** aValue, unsigned const int aSize, int aCopyFlag = 1);
    const char** getStatusDescriptions(unsigned int& aSize) const;


  };
  
  struct CIM_ManagedSystemElementInstanceEnumerationElement {

    CIM_ManagedSystemElementInstance* m_elementP;
    CIM_ManagedSystemElementInstanceEnumerationElement* m_nextP;

    CIM_ManagedSystemElementInstanceEnumerationElement();
    ~CIM_ManagedSystemElementInstanceEnumerationElement();  

  };
  

  class CIM_ManagedSystemElementInstanceEnumeration {

    private:
    CIM_ManagedSystemElementInstanceEnumerationElement* m_firstElementP;
    CIM_ManagedSystemElementInstanceEnumerationElement* m_currentElementP;
    CIM_ManagedSystemElementInstanceEnumerationElement* m_endElementP;

    public:
    CIM_ManagedSystemElementInstanceEnumeration();
    CIM_ManagedSystemElementInstanceEnumeration(
      const CIM_ManagedSystemElementInstanceEnumeration& anInstanceEnumeration);
    ~CIM_ManagedSystemElementInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const CIM_ManagedSystemElementInstance& getNext();
    int getSize() const;
    const CIM_ManagedSystemElementInstance& getElement(int anIndex) const;  	  
    void addElement(const CIM_ManagedSystemElementInstance& anInstance);

  };

}

#endif
