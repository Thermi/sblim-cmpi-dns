// =======================================================================
// Linux_DnsHintZoneRepositoryInstance.h
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
#ifndef Linux_DnsHintZoneRepositoryInstance_h
#define Linux_DnsHintZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsHintZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsHintZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsHintZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsHintZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsHintZoneRepositoryInstance();
    Linux_DnsHintZoneRepositoryInstance(
      const Linux_DnsHintZoneRepositoryInstance& anInstance);
    Linux_DnsHintZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsHintZoneRepositoryInstance();
       
    Linux_DnsHintZoneRepositoryInstance& operator=(
      const Linux_DnsHintZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsHintZoneInstanceName& anInstanceName);        
    const Linux_DnsHintZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsHintZoneRepositoryInstanceEnumerationElement {

    Linux_DnsHintZoneRepositoryInstance* m_elementP;
    Linux_DnsHintZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsHintZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsHintZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsHintZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsHintZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsHintZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsHintZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsHintZoneRepositoryInstanceEnumeration();
    Linux_DnsHintZoneRepositoryInstanceEnumeration(
      const Linux_DnsHintZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsHintZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsHintZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsHintZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsHintZoneRepositoryInstance& anInstance);

  };

}

#endif
