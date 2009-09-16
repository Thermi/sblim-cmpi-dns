// =======================================================================
// Linux_DnsStubZoneRepositoryInstance.h
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
#ifndef Linux_DnsStubZoneRepositoryInstance_h
#define Linux_DnsStubZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsStubZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsStubZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsStubZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsStubZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsStubZoneRepositoryInstance();
    Linux_DnsStubZoneRepositoryInstance(
      const Linux_DnsStubZoneRepositoryInstance& anInstance);
    Linux_DnsStubZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsStubZoneRepositoryInstance();
       
    Linux_DnsStubZoneRepositoryInstance& operator=(
      const Linux_DnsStubZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsStubZoneInstanceName& anInstanceName);        
    const Linux_DnsStubZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsStubZoneRepositoryInstanceEnumerationElement {

    Linux_DnsStubZoneRepositoryInstance* m_elementP;
    Linux_DnsStubZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsStubZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsStubZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsStubZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsStubZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsStubZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsStubZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsStubZoneRepositoryInstanceEnumeration();
    Linux_DnsStubZoneRepositoryInstanceEnumeration(
      const Linux_DnsStubZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsStubZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsStubZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsStubZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsStubZoneRepositoryInstance& anInstance);

  };

}

#endif
