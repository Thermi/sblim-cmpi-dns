// =======================================================================
// Linux_DnsServiceRepositoryInstance.h
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
#ifndef Linux_DnsServiceRepositoryInstance_h
#define Linux_DnsServiceRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsServiceRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsServiceRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsServiceRepositoryInstance();
    Linux_DnsServiceRepositoryInstance(
      const Linux_DnsServiceRepositoryInstance& anInstance);
    Linux_DnsServiceRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsServiceRepositoryInstance();
       
    Linux_DnsServiceRepositoryInstance& operator=(
      const Linux_DnsServiceRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsServiceInstanceName& anInstanceName);        
    const Linux_DnsServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsServiceRepositoryInstanceEnumerationElement {

    Linux_DnsServiceRepositoryInstance* m_elementP;
    Linux_DnsServiceRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsServiceRepositoryInstanceEnumerationElement();
    ~Linux_DnsServiceRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsServiceRepositoryInstanceEnumeration {

    private:
    Linux_DnsServiceRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsServiceRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsServiceRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsServiceRepositoryInstanceEnumeration();
    Linux_DnsServiceRepositoryInstanceEnumeration(
      const Linux_DnsServiceRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsServiceRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsServiceRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsServiceRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsServiceRepositoryInstance& anInstance);

  };

}

#endif
