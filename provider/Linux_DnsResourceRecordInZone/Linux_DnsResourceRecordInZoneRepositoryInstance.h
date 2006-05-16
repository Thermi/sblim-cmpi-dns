// =======================================================================
// Linux_DnsResourceRecordInZoneRepositoryInstance.h
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
#ifndef Linux_DnsResourceRecordInZoneRepositoryInstance_h
#define Linux_DnsResourceRecordInZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsResourceRecordInZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsResourceRecordInZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsResourceRecordInZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsResourceRecordInZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsResourceRecordInZoneRepositoryInstance();
    Linux_DnsResourceRecordInZoneRepositoryInstance(
      const Linux_DnsResourceRecordInZoneRepositoryInstance& anInstance);
    Linux_DnsResourceRecordInZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsResourceRecordInZoneRepositoryInstance();
       
    Linux_DnsResourceRecordInZoneRepositoryInstance& operator=(
      const Linux_DnsResourceRecordInZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsResourceRecordInZoneInstanceName& anInstanceName);        
    const Linux_DnsResourceRecordInZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement {

    Linux_DnsResourceRecordInZoneRepositoryInstance* m_elementP;
    Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration();
    Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration(
      const Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsResourceRecordInZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsResourceRecordInZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsResourceRecordInZoneRepositoryInstance& anInstance);

  };

}

#endif
