// =======================================================================
// Linux_DnsHintZoneManualInstance.h
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
#ifndef Linux_DnsHintZoneManualInstance_h
#define Linux_DnsHintZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsHintZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsHintZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsHintZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsHintZoneInstanceName m_instanceName;
    const char* m_ResourceRecordFile;
    CMPIUint16 m_Type;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int ResourceRecordFile:1;
      unsigned int Type:1;

    } isSet;
    
    public:
    Linux_DnsHintZoneManualInstance();
    Linux_DnsHintZoneManualInstance(
      const Linux_DnsHintZoneManualInstance& anInstance);
    Linux_DnsHintZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsHintZoneManualInstance();
       
    Linux_DnsHintZoneManualInstance& operator=(
      const Linux_DnsHintZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsHintZoneInstanceName& anInstanceName);        
    const Linux_DnsHintZoneInstanceName& getInstanceName() const;

    unsigned int isResourceRecordFileSet() const;
    void setResourceRecordFile(const char* aValue, int aCopyFlag = 1);
    const char* getResourceRecordFile() const;

    unsigned int isTypeSet() const;
    void setType(const CMPIUint16 aValue);
    const CMPIUint16 getType() const;


  };
  
  struct Linux_DnsHintZoneManualInstanceEnumerationElement {

    Linux_DnsHintZoneManualInstance* m_elementP;
    Linux_DnsHintZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsHintZoneManualInstanceEnumerationElement();
    ~Linux_DnsHintZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsHintZoneManualInstanceEnumeration {

    private:
    Linux_DnsHintZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsHintZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsHintZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsHintZoneManualInstanceEnumeration();
    Linux_DnsHintZoneManualInstanceEnumeration(
      const Linux_DnsHintZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsHintZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsHintZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsHintZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsHintZoneManualInstance& anInstance);

  };

}

#endif
