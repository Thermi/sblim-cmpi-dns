// =======================================================================
// Linux_DnsZoneInstance.h
//     created on Tue, 7 Mar 2006 using ECUTE
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
//                Rodrigo Ceron    <rceron@br.ibm.com>
//                Wolfgang Taphorn <taphorn@de.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsZoneInstance_h
#define Linux_DnsZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsZoneInstance& anInstance);
    void reset();
       
    Linux_DnsZoneInstanceName m_instanceName;
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
    Linux_DnsZoneInstance();
    Linux_DnsZoneInstance(
      const Linux_DnsZoneInstance& anInstance);
    Linux_DnsZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsZoneInstance();
       
    Linux_DnsZoneInstance& operator=(
      const Linux_DnsZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsZoneInstanceName& anInstanceName);        
    const Linux_DnsZoneInstanceName& getInstanceName() const;

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
  
  struct Linux_DnsZoneInstanceEnumerationElement {

    Linux_DnsZoneInstance* m_elementP;
    Linux_DnsZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsZoneInstanceEnumerationElement();
    ~Linux_DnsZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsZoneInstanceEnumeration {

    private:
    Linux_DnsZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsZoneInstanceEnumeration();
    Linux_DnsZoneInstanceEnumeration(
      const Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsZoneInstance& anInstance);

  };

}

#endif
