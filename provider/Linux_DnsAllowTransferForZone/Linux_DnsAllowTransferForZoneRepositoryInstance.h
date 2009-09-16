// =======================================================================
// Linux_DnsAllowTransferForZoneRepositoryInstance.h
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
#ifndef Linux_DnsAllowTransferForZoneRepositoryInstance_h
#define Linux_DnsAllowTransferForZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowTransferForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowTransferForZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowTransferForZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsAllowTransferForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowTransferForZoneRepositoryInstance();
    Linux_DnsAllowTransferForZoneRepositoryInstance(
      const Linux_DnsAllowTransferForZoneRepositoryInstance& anInstance);
    Linux_DnsAllowTransferForZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowTransferForZoneRepositoryInstance();
       
    Linux_DnsAllowTransferForZoneRepositoryInstance& operator=(
      const Linux_DnsAllowTransferForZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowTransferForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowTransferForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowTransferForZoneRepositoryInstanceEnumerationElement {

    Linux_DnsAllowTransferForZoneRepositoryInstance* m_elementP;
    Linux_DnsAllowTransferForZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowTransferForZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsAllowTransferForZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowTransferForZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsAllowTransferForZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowTransferForZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowTransferForZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowTransferForZoneRepositoryInstanceEnumeration();
    Linux_DnsAllowTransferForZoneRepositoryInstanceEnumeration(
      const Linux_DnsAllowTransferForZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowTransferForZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowTransferForZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowTransferForZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowTransferForZoneRepositoryInstance& anInstance);

  };

}

#endif
