// =======================================================================
// Linux_DnsAllowUpdateForZoneRepositoryInstance.h
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
#ifndef Linux_DnsAllowUpdateForZoneRepositoryInstance_h
#define Linux_DnsAllowUpdateForZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowUpdateForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowUpdateForZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowUpdateForZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsAllowUpdateForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowUpdateForZoneRepositoryInstance();
    Linux_DnsAllowUpdateForZoneRepositoryInstance(
      const Linux_DnsAllowUpdateForZoneRepositoryInstance& anInstance);
    Linux_DnsAllowUpdateForZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowUpdateForZoneRepositoryInstance();
       
    Linux_DnsAllowUpdateForZoneRepositoryInstance& operator=(
      const Linux_DnsAllowUpdateForZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowUpdateForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowUpdateForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowUpdateForZoneRepositoryInstanceEnumerationElement {

    Linux_DnsAllowUpdateForZoneRepositoryInstance* m_elementP;
    Linux_DnsAllowUpdateForZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowUpdateForZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsAllowUpdateForZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowUpdateForZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsAllowUpdateForZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowUpdateForZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowUpdateForZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowUpdateForZoneRepositoryInstanceEnumeration();
    Linux_DnsAllowUpdateForZoneRepositoryInstanceEnumeration(
      const Linux_DnsAllowUpdateForZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowUpdateForZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowUpdateForZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowUpdateForZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowUpdateForZoneRepositoryInstance& anInstance);

  };

}

#endif
