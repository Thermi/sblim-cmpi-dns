// =======================================================================
// Linux_DnsForwardZoneRepositoryInstance.h
//     created on Wed, 29 Nov 2006 using ECUTE 2.2
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
#ifndef Linux_DnsForwardZoneRepositoryInstance_h
#define Linux_DnsForwardZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsForwardZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsForwardZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsForwardZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsForwardZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsForwardZoneRepositoryInstance();
    Linux_DnsForwardZoneRepositoryInstance(
      const Linux_DnsForwardZoneRepositoryInstance& anInstance);
    Linux_DnsForwardZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsForwardZoneRepositoryInstance();
       
    Linux_DnsForwardZoneRepositoryInstance& operator=(
      const Linux_DnsForwardZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsForwardZoneInstanceName& anInstanceName);        
    const Linux_DnsForwardZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsForwardZoneRepositoryInstanceEnumerationElement {

    Linux_DnsForwardZoneRepositoryInstance* m_elementP;
    Linux_DnsForwardZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsForwardZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsForwardZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsForwardZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsForwardZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsForwardZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsForwardZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsForwardZoneRepositoryInstanceEnumeration();
    Linux_DnsForwardZoneRepositoryInstanceEnumeration(
      const Linux_DnsForwardZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsForwardZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsForwardZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsForwardZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsForwardZoneRepositoryInstance& anInstance);

  };

}

#endif
