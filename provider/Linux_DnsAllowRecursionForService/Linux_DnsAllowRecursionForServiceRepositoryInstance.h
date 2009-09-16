// =======================================================================
// Linux_DnsAllowRecursionForServiceRepositoryInstance.h
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
#ifndef Linux_DnsAllowRecursionForServiceRepositoryInstance_h
#define Linux_DnsAllowRecursionForServiceRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowRecursionForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowRecursionForServiceRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowRecursionForServiceRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsAllowRecursionForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowRecursionForServiceRepositoryInstance();
    Linux_DnsAllowRecursionForServiceRepositoryInstance(
      const Linux_DnsAllowRecursionForServiceRepositoryInstance& anInstance);
    Linux_DnsAllowRecursionForServiceRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowRecursionForServiceRepositoryInstance();
       
    Linux_DnsAllowRecursionForServiceRepositoryInstance& operator=(
      const Linux_DnsAllowRecursionForServiceRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowRecursionForServiceInstanceName& anInstanceName);        
    const Linux_DnsAllowRecursionForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowRecursionForServiceRepositoryInstanceEnumerationElement {

    Linux_DnsAllowRecursionForServiceRepositoryInstance* m_elementP;
    Linux_DnsAllowRecursionForServiceRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowRecursionForServiceRepositoryInstanceEnumerationElement();
    ~Linux_DnsAllowRecursionForServiceRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowRecursionForServiceRepositoryInstanceEnumeration {

    private:
    Linux_DnsAllowRecursionForServiceRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowRecursionForServiceRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowRecursionForServiceRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowRecursionForServiceRepositoryInstanceEnumeration();
    Linux_DnsAllowRecursionForServiceRepositoryInstanceEnumeration(
      const Linux_DnsAllowRecursionForServiceRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowRecursionForServiceRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowRecursionForServiceRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowRecursionForServiceRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowRecursionForServiceRepositoryInstance& anInstance);

  };

}

#endif
