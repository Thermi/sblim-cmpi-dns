// =======================================================================
// Linux_DnsResourceRecordInstance.h
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
#ifndef Linux_DnsResourceRecordInstance_h
#define Linux_DnsResourceRecordInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsResourceRecordInstanceName.h"


namespace genProvider {

  class Linux_DnsResourceRecordInstance {
       
    private:
    void init();
    void init(const Linux_DnsResourceRecordInstance& anInstance);
    void reset();
       
    Linux_DnsResourceRecordInstanceName m_instanceName;
    const char* m_Caption;
    const char* m_Description;
    const char* m_ElementName;
    CMPIUint16 m_Family;
    const char* m_SettingID;
    CMPIUint32 m_TTL;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int Caption:1;
      unsigned int Description:1;
      unsigned int ElementName:1;
      unsigned int Family:1;
      unsigned int SettingID:1;
      unsigned int TTL:1;

    } isSet;
    
    public:
    Linux_DnsResourceRecordInstance();
    Linux_DnsResourceRecordInstance(
      const Linux_DnsResourceRecordInstance& anInstance);
    Linux_DnsResourceRecordInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsResourceRecordInstance();
       
    Linux_DnsResourceRecordInstance& operator=(
      const Linux_DnsResourceRecordInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsResourceRecordInstanceName& anInstanceName);        
    const Linux_DnsResourceRecordInstanceName& getInstanceName() const;

    unsigned int isCaptionSet() const;
    void setCaption(const char* aValue, int aCopyFlag = 1);
    const char* getCaption() const;

    unsigned int isDescriptionSet() const;
    void setDescription(const char* aValue, int aCopyFlag = 1);
    const char* getDescription() const;

    unsigned int isElementNameSet() const;
    void setElementName(const char* aValue, int aCopyFlag = 1);
    const char* getElementName() const;

    unsigned int isFamilySet() const;
    void setFamily(const CMPIUint16 aValue);
    const CMPIUint16 getFamily() const;

    unsigned int isSettingIDSet() const;
    void setSettingID(const char* aValue, int aCopyFlag = 1);
    const char* getSettingID() const;

    unsigned int isTTLSet() const;
    void setTTL(const CMPIUint32 aValue);
    const CMPIUint32 getTTL() const;


  };
  
  struct Linux_DnsResourceRecordInstanceEnumerationElement {

    Linux_DnsResourceRecordInstance* m_elementP;
    Linux_DnsResourceRecordInstanceEnumerationElement* m_nextP;

    Linux_DnsResourceRecordInstanceEnumerationElement();
    ~Linux_DnsResourceRecordInstanceEnumerationElement();  

  };
  

  class Linux_DnsResourceRecordInstanceEnumeration {

    private:
    Linux_DnsResourceRecordInstanceEnumerationElement* m_firstElementP;
    Linux_DnsResourceRecordInstanceEnumerationElement* m_currentElementP;
    Linux_DnsResourceRecordInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsResourceRecordInstanceEnumeration();
    Linux_DnsResourceRecordInstanceEnumeration(
      const Linux_DnsResourceRecordInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsResourceRecordInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsResourceRecordInstance& getNext();
    int getSize() const;
    const Linux_DnsResourceRecordInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsResourceRecordInstance& anInstance);

  };

}

#endif
