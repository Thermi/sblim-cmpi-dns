// =======================================================================
// Linux_DnsAllowQueryForServiceRepositoryInstance.h
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
#ifndef Linux_DnsAllowQueryForServiceRepositoryInstance_h
#define Linux_DnsAllowQueryForServiceRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowQueryForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowQueryForServiceRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowQueryForServiceRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsAllowQueryForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowQueryForServiceRepositoryInstance();
    Linux_DnsAllowQueryForServiceRepositoryInstance(
      const Linux_DnsAllowQueryForServiceRepositoryInstance& anInstance);
    Linux_DnsAllowQueryForServiceRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowQueryForServiceRepositoryInstance();
       
    Linux_DnsAllowQueryForServiceRepositoryInstance& operator=(
      const Linux_DnsAllowQueryForServiceRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowQueryForServiceInstanceName& anInstanceName);        
    const Linux_DnsAllowQueryForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowQueryForServiceRepositoryInstanceEnumerationElement {

    Linux_DnsAllowQueryForServiceRepositoryInstance* m_elementP;
    Linux_DnsAllowQueryForServiceRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowQueryForServiceRepositoryInstanceEnumerationElement();
    ~Linux_DnsAllowQueryForServiceRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowQueryForServiceRepositoryInstanceEnumeration {

    private:
    Linux_DnsAllowQueryForServiceRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowQueryForServiceRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowQueryForServiceRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowQueryForServiceRepositoryInstanceEnumeration();
    Linux_DnsAllowQueryForServiceRepositoryInstanceEnumeration(
      const Linux_DnsAllowQueryForServiceRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowQueryForServiceRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowQueryForServiceRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowQueryForServiceRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowQueryForServiceRepositoryInstance& anInstance);

  };

}

#endif
