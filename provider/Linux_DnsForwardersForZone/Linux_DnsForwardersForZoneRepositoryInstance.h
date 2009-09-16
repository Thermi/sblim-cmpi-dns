// =======================================================================
// Linux_DnsForwardersForZoneRepositoryInstance.h
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
#ifndef Linux_DnsForwardersForZoneRepositoryInstance_h
#define Linux_DnsForwardersForZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsForwardersForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsForwardersForZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsForwardersForZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsForwardersForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsForwardersForZoneRepositoryInstance();
    Linux_DnsForwardersForZoneRepositoryInstance(
      const Linux_DnsForwardersForZoneRepositoryInstance& anInstance);
    Linux_DnsForwardersForZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsForwardersForZoneRepositoryInstance();
       
    Linux_DnsForwardersForZoneRepositoryInstance& operator=(
      const Linux_DnsForwardersForZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsForwardersForZoneInstanceName& anInstanceName);        
    const Linux_DnsForwardersForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsForwardersForZoneRepositoryInstanceEnumerationElement {

    Linux_DnsForwardersForZoneRepositoryInstance* m_elementP;
    Linux_DnsForwardersForZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsForwardersForZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsForwardersForZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsForwardersForZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsForwardersForZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsForwardersForZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsForwardersForZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsForwardersForZoneRepositoryInstanceEnumeration();
    Linux_DnsForwardersForZoneRepositoryInstanceEnumeration(
      const Linux_DnsForwardersForZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsForwardersForZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsForwardersForZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsForwardersForZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsForwardersForZoneRepositoryInstance& anInstance);

  };

}

#endif
