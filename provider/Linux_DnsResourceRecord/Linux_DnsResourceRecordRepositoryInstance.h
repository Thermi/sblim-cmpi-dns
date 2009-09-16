// =======================================================================
// Linux_DnsResourceRecordRepositoryInstance.h
//     created on Fri, 1 Dec 2006 using ECUTE 2.2
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
#ifndef Linux_DnsResourceRecordRepositoryInstance_h
#define Linux_DnsResourceRecordRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsResourceRecordInstanceName.h"


namespace genProvider {

  class Linux_DnsResourceRecordRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsResourceRecordRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsResourceRecordInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsResourceRecordRepositoryInstance();
    Linux_DnsResourceRecordRepositoryInstance(
      const Linux_DnsResourceRecordRepositoryInstance& anInstance);
    Linux_DnsResourceRecordRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsResourceRecordRepositoryInstance();
       
    Linux_DnsResourceRecordRepositoryInstance& operator=(
      const Linux_DnsResourceRecordRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsResourceRecordInstanceName& anInstanceName);        
    const Linux_DnsResourceRecordInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsResourceRecordRepositoryInstanceEnumerationElement {

    Linux_DnsResourceRecordRepositoryInstance* m_elementP;
    Linux_DnsResourceRecordRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsResourceRecordRepositoryInstanceEnumerationElement();
    ~Linux_DnsResourceRecordRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsResourceRecordRepositoryInstanceEnumeration {

    private:
    Linux_DnsResourceRecordRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsResourceRecordRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsResourceRecordRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsResourceRecordRepositoryInstanceEnumeration();
    Linux_DnsResourceRecordRepositoryInstanceEnumeration(
      const Linux_DnsResourceRecordRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsResourceRecordRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsResourceRecordRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsResourceRecordRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsResourceRecordRepositoryInstance& anInstance);

  };

}

#endif
