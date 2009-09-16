// =======================================================================
// Linux_DnsResourceRecordsForZoneRepositoryInstance.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
// 
// Copyright (c) 2006, 2009, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Eclipse Public License from
// http://www.opensource.org/licenses/eclipse-1.0.php
//
// Author:        generated
//
// Contributors:
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsResourceRecordsForZoneRepositoryInstance_h
#define Linux_DnsResourceRecordsForZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsResourceRecordsForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsResourceRecordsForZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsResourceRecordsForZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsResourceRecordsForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsResourceRecordsForZoneRepositoryInstance();
    Linux_DnsResourceRecordsForZoneRepositoryInstance(
      const Linux_DnsResourceRecordsForZoneRepositoryInstance& anInstance);
    Linux_DnsResourceRecordsForZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsResourceRecordsForZoneRepositoryInstance();
       
    Linux_DnsResourceRecordsForZoneRepositoryInstance& operator=(
      const Linux_DnsResourceRecordsForZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsResourceRecordsForZoneInstanceName& anInstanceName);        
    const Linux_DnsResourceRecordsForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsResourceRecordsForZoneRepositoryInstanceEnumerationElement {

    Linux_DnsResourceRecordsForZoneRepositoryInstance* m_elementP;
    Linux_DnsResourceRecordsForZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsResourceRecordsForZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsResourceRecordsForZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsResourceRecordsForZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsResourceRecordsForZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsResourceRecordsForZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsResourceRecordsForZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsResourceRecordsForZoneRepositoryInstanceEnumeration();
    Linux_DnsResourceRecordsForZoneRepositoryInstanceEnumeration(
      const Linux_DnsResourceRecordsForZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsResourceRecordsForZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsResourceRecordsForZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsResourceRecordsForZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsResourceRecordsForZoneRepositoryInstance& anInstance);

  };

}

#endif
