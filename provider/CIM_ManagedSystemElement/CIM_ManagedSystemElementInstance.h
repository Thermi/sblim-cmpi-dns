 /**
 * CIM_ManagedSystemElementInstance.h
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
  public:
       CIM_ManagedSystemElementInstance();
  	
       CIM_ManagedSystemElementInstance
  	    (const CIM_ManagedSystemElementInstance& original);
  	   
       CIM_ManagedSystemElementInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~CIM_ManagedSystemElementInstance();
       
       CIM_ManagedSystemElementInstance& operator=
  	    (const CIM_ManagedSystemElementInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const CIM_ManagedSystemElementInstanceName& val);        
       const CIM_ManagedSystemElementInstanceName&
        getInstanceName() const;

       unsigned int isCaptionSet() const;
       void setCaption(const char* val, int makeCopy = 1);
       const char* getCaption() const;

       unsigned int isDescriptionSet() const;
       void setDescription(const char* val, int makeCopy = 1);
       const char* getDescription() const;

       unsigned int isElementNameSet() const;
       void setElementName(const char* val, int makeCopy = 1);
       const char* getElementName() const;

       unsigned int isInstallDateSet() const;
       void setInstallDate(const CmpiDateTime& val);
       const CmpiDateTime& getInstallDate() const;

       unsigned int isNameSet() const;
       void setName(const char* val, int makeCopy = 1);
       const char* getName() const;

       unsigned int isOperationalStatusSet() const;
       void setOperationalStatus(const CMPIUint16* val, unsigned const int size, int makeCopy = 1);
       const CMPIUint16* getOperationalStatus(unsigned int& size) const;

       unsigned int isStatusSet() const;
       void setStatus(const char* val, int makeCopy = 1);
       const char* getStatus() const;

       unsigned int isStatusDescriptionsSet() const;
       void setStatusDescriptions(const char** val, unsigned const int size, int makeCopy = 1);
       const char** getStatusDescriptions(unsigned int& size) const;
       
  private:
       void init();
       void init(const CIM_ManagedSystemElementInstance& original);
       void reset();
       
       CIM_ManagedSystemElementInstanceName m_instanceName;
       const char* m_Caption;
       const char* m_Description;
       const char* m_ElementName;
       CmpiDateTime m_InstallDate;
       const char* m_Name;
       const CMPIUint16* m_OperationalStatus;
        unsigned int OperationalStatusArraySize;
       const char* m_Status;
       const char** m_StatusDescriptions;
        unsigned int StatusDescriptionsArraySize;
       
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
  };
  
  
  struct CIM_ManagedSystemElementInstanceEnumerationElement{
  	CIM_ManagedSystemElementInstance* m_elementP;
  	CIM_ManagedSystemElementInstanceEnumerationElement* m_nextP;
  	
  	CIM_ManagedSystemElementInstanceEnumerationElement();
  	~CIM_ManagedSystemElementInstanceEnumerationElement();  	
  };
  

  class CIM_ManagedSystemElementInstanceEnumeration {
  	private:
  	  CIM_ManagedSystemElementInstanceEnumerationElement* firstElementP;
  	  CIM_ManagedSystemElementInstanceEnumerationElement* currentElementP;
  	  CIM_ManagedSystemElementInstanceEnumerationElement* endElementP;
  	
  	public:
  	  CIM_ManagedSystemElementInstanceEnumeration();
  	  
  	  CIM_ManagedSystemElementInstanceEnumeration(
  	   const CIM_ManagedSystemElementInstanceEnumeration& original);
  	  
  	  ~CIM_ManagedSystemElementInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const CIM_ManagedSystemElementInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const CIM_ManagedSystemElementInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const CIM_ManagedSystemElementInstance& elementP);
  };
}
#endif

