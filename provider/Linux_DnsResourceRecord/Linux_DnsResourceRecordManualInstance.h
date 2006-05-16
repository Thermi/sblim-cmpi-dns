// =======================================================================
// Linux_DnsResourceRecordManualInstance.h
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
#ifndef Linux_DnsResourceRecordManualInstance_h
#define Linux_DnsResourceRecordManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsResourceRecordInstanceName.h"


namespace genProvider {

  class Linux_DnsResourceRecordManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsResourceRecordManualInstance& anInstance);
    void reset();
       
    Linux_DnsResourceRecordInstanceName m_instanceName;
    CMPIUint16 m_Family;
    CMPIUint32 m_TTL;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int Family:1;
      unsigned int TTL:1;

    } isSet;
    
    public:
    Linux_DnsResourceRecordManualInstance();
    Linux_DnsResourceRecordManualInstance(
      const Linux_DnsResourceRecordManualInstance& anInstance);
    Linux_DnsResourceRecordManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsResourceRecordManualInstance();
       
    Linux_DnsResourceRecordManualInstance& operator=(
      const Linux_DnsResourceRecordManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsResourceRecordInstanceName& anInstanceName);        
    const Linux_DnsResourceRecordInstanceName& getInstanceName() const;

    unsigned int isFamilySet() const;
    void setFamily(const CMPIUint16 aValue);
    const CMPIUint16 getFamily() const;

    unsigned int isTTLSet() const;
    void setTTL(const CMPIUint32 aValue);
    const CMPIUint32 getTTL() const;


  };
  
  struct Linux_DnsResourceRecordManualInstanceEnumerationElement {

    Linux_DnsResourceRecordManualInstance* m_elementP;
    Linux_DnsResourceRecordManualInstanceEnumerationElement* m_nextP;

    Linux_DnsResourceRecordManualInstanceEnumerationElement();
    ~Linux_DnsResourceRecordManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsResourceRecordManualInstanceEnumeration {

    private:
    Linux_DnsResourceRecordManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsResourceRecordManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsResourceRecordManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsResourceRecordManualInstanceEnumeration();
    Linux_DnsResourceRecordManualInstanceEnumeration(
      const Linux_DnsResourceRecordManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsResourceRecordManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsResourceRecordManualInstance& getNext();
    int getSize() const;
    const Linux_DnsResourceRecordManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsResourceRecordManualInstance& anInstance);

  };

}

#endif
