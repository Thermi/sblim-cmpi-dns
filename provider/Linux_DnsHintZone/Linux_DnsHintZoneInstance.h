// =======================================================================
// Linux_DnsHintZoneInstance.h
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
#ifndef Linux_DnsHintZoneInstance_h
#define Linux_DnsHintZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsHintZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsHintZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsHintZoneInstance& anInstance);
    void reset();
       
    Linux_DnsHintZoneInstanceName m_instanceName;
    const char* m_Caption;
    const char* m_Description;
    const char* m_ElementName;
    const char* m_ResourceRecordFile;
    const char* m_SettingID;
    CMPIUint16 m_Type;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int Caption:1;
      unsigned int Description:1;
      unsigned int ElementName:1;
      unsigned int ResourceRecordFile:1;
      unsigned int SettingID:1;
      unsigned int Type:1;

    } isSet;
    
    public:
    Linux_DnsHintZoneInstance();
    Linux_DnsHintZoneInstance(
      const Linux_DnsHintZoneInstance& anInstance);
    Linux_DnsHintZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsHintZoneInstance();
       
    Linux_DnsHintZoneInstance& operator=(
      const Linux_DnsHintZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsHintZoneInstanceName& anInstanceName);        
    const Linux_DnsHintZoneInstanceName& getInstanceName() const;

    unsigned int isCaptionSet() const;
    void setCaption(const char* aValue, int aCopyFlag = 1);
    const char* getCaption() const;

    unsigned int isDescriptionSet() const;
    void setDescription(const char* aValue, int aCopyFlag = 1);
    const char* getDescription() const;

    unsigned int isElementNameSet() const;
    void setElementName(const char* aValue, int aCopyFlag = 1);
    const char* getElementName() const;

    unsigned int isResourceRecordFileSet() const;
    void setResourceRecordFile(const char* aValue, int aCopyFlag = 1);
    const char* getResourceRecordFile() const;

    unsigned int isSettingIDSet() const;
    void setSettingID(const char* aValue, int aCopyFlag = 1);
    const char* getSettingID() const;

    unsigned int isTypeSet() const;
    void setType(const CMPIUint16 aValue);
    const CMPIUint16 getType() const;


  };
  
  struct Linux_DnsHintZoneInstanceEnumerationElement {

    Linux_DnsHintZoneInstance* m_elementP;
    Linux_DnsHintZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsHintZoneInstanceEnumerationElement();
    ~Linux_DnsHintZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsHintZoneInstanceEnumeration {

    private:
    Linux_DnsHintZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsHintZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsHintZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsHintZoneInstanceEnumeration();
    Linux_DnsHintZoneInstanceEnumeration(
      const Linux_DnsHintZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsHintZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsHintZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsHintZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsHintZoneInstance& anInstance);

  };

}

#endif
