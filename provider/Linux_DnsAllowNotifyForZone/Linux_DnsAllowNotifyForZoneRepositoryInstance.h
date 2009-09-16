// =======================================================================
// Linux_DnsAllowNotifyForZoneRepositoryInstance.h
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
#ifndef Linux_DnsAllowNotifyForZoneRepositoryInstance_h
#define Linux_DnsAllowNotifyForZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowNotifyForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowNotifyForZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowNotifyForZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsAllowNotifyForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowNotifyForZoneRepositoryInstance();
    Linux_DnsAllowNotifyForZoneRepositoryInstance(
      const Linux_DnsAllowNotifyForZoneRepositoryInstance& anInstance);
    Linux_DnsAllowNotifyForZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowNotifyForZoneRepositoryInstance();
       
    Linux_DnsAllowNotifyForZoneRepositoryInstance& operator=(
      const Linux_DnsAllowNotifyForZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowNotifyForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowNotifyForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumerationElement {

    Linux_DnsAllowNotifyForZoneRepositoryInstance* m_elementP;
    Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration();
    Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration(
      const Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowNotifyForZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowNotifyForZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowNotifyForZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowNotifyForZoneRepositoryInstance& anInstance);

  };

}

#endif
