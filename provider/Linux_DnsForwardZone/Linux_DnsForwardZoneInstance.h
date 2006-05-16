// =======================================================================
// Linux_DnsForwardZoneInstance.h
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
#ifndef Linux_DnsForwardZoneInstance_h
#define Linux_DnsForwardZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsForwardZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsForwardZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsForwardZoneInstance& anInstance);
    void reset();
       
    Linux_DnsForwardZoneInstanceName m_instanceName;
    const char* m_Caption;
    const char* m_Description;
    const char* m_ElementName;
    CMPIUint16 m_Forward;
    const char** m_Forwarders;
    unsigned int m_ForwardersSize;
    const char* m_ResourceRecordFile;
    const char* m_SettingID;
    CMPIUint16 m_Type;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int Caption:1;
      unsigned int Description:1;
      unsigned int ElementName:1;
      unsigned int Forward:1;
      unsigned int Forwarders:1;
      unsigned int ResourceRecordFile:1;
      unsigned int SettingID:1;
      unsigned int Type:1;

    } isSet;
    
    public:
    Linux_DnsForwardZoneInstance();
    Linux_DnsForwardZoneInstance(
      const Linux_DnsForwardZoneInstance& anInstance);
    Linux_DnsForwardZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsForwardZoneInstance();
       
    Linux_DnsForwardZoneInstance& operator=(
      const Linux_DnsForwardZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsForwardZoneInstanceName& anInstanceName);        
    const Linux_DnsForwardZoneInstanceName& getInstanceName() const;

    unsigned int isCaptionSet() const;
    void setCaption(const char* aValue, int aCopyFlag = 1);
    const char* getCaption() const;

    unsigned int isDescriptionSet() const;
    void setDescription(const char* aValue, int aCopyFlag = 1);
    const char* getDescription() const;

    unsigned int isElementNameSet() const;
    void setElementName(const char* aValue, int aCopyFlag = 1);
    const char* getElementName() const;

    unsigned int isForwardSet() const;
    void setForward(const CMPIUint16 aValue);
    const CMPIUint16 getForward() const;

    unsigned int isForwardersSet() const;
    void setForwarders(const char** aValue, unsigned const int aSize, int aCopyFlag = 1);
    const char** getForwarders(unsigned int& aSize) const;

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
  
  struct Linux_DnsForwardZoneInstanceEnumerationElement {

    Linux_DnsForwardZoneInstance* m_elementP;
    Linux_DnsForwardZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsForwardZoneInstanceEnumerationElement();
    ~Linux_DnsForwardZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsForwardZoneInstanceEnumeration {

    private:
    Linux_DnsForwardZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsForwardZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsForwardZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsForwardZoneInstanceEnumeration();
    Linux_DnsForwardZoneInstanceEnumeration(
      const Linux_DnsForwardZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsForwardZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsForwardZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsForwardZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsForwardZoneInstance& anInstance);

  };

}

#endif
