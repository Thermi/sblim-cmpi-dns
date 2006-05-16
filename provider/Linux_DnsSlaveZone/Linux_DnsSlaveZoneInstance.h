// =======================================================================
// Linux_DnsSlaveZoneInstance.h
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
#ifndef Linux_DnsSlaveZoneInstance_h
#define Linux_DnsSlaveZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsSlaveZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsSlaveZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsSlaveZoneInstance& anInstance);
    void reset();
       
    Linux_DnsSlaveZoneInstanceName m_instanceName;
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
    Linux_DnsSlaveZoneInstance();
    Linux_DnsSlaveZoneInstance(
      const Linux_DnsSlaveZoneInstance& anInstance);
    Linux_DnsSlaveZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsSlaveZoneInstance();
       
    Linux_DnsSlaveZoneInstance& operator=(
      const Linux_DnsSlaveZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsSlaveZoneInstanceName& anInstanceName);        
    const Linux_DnsSlaveZoneInstanceName& getInstanceName() const;

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
  
  struct Linux_DnsSlaveZoneInstanceEnumerationElement {

    Linux_DnsSlaveZoneInstance* m_elementP;
    Linux_DnsSlaveZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsSlaveZoneInstanceEnumerationElement();
    ~Linux_DnsSlaveZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsSlaveZoneInstanceEnumeration {

    private:
    Linux_DnsSlaveZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsSlaveZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsSlaveZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsSlaveZoneInstanceEnumeration();
    Linux_DnsSlaveZoneInstanceEnumeration(
      const Linux_DnsSlaveZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsSlaveZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsSlaveZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsSlaveZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsSlaveZoneInstance& anInstance);

  };

}

#endif
