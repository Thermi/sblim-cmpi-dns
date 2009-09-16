// =======================================================================
// Linux_DnsForwardersForServiceRepositoryInstance.h
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
#ifndef Linux_DnsForwardersForServiceRepositoryInstance_h
#define Linux_DnsForwardersForServiceRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsForwardersForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsForwardersForServiceRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsForwardersForServiceRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsForwardersForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsForwardersForServiceRepositoryInstance();
    Linux_DnsForwardersForServiceRepositoryInstance(
      const Linux_DnsForwardersForServiceRepositoryInstance& anInstance);
    Linux_DnsForwardersForServiceRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsForwardersForServiceRepositoryInstance();
       
    Linux_DnsForwardersForServiceRepositoryInstance& operator=(
      const Linux_DnsForwardersForServiceRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsForwardersForServiceInstanceName& anInstanceName);        
    const Linux_DnsForwardersForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsForwardersForServiceRepositoryInstanceEnumerationElement {

    Linux_DnsForwardersForServiceRepositoryInstance* m_elementP;
    Linux_DnsForwardersForServiceRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsForwardersForServiceRepositoryInstanceEnumerationElement();
    ~Linux_DnsForwardersForServiceRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsForwardersForServiceRepositoryInstanceEnumeration {

    private:
    Linux_DnsForwardersForServiceRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsForwardersForServiceRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsForwardersForServiceRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsForwardersForServiceRepositoryInstanceEnumeration();
    Linux_DnsForwardersForServiceRepositoryInstanceEnumeration(
      const Linux_DnsForwardersForServiceRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsForwardersForServiceRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsForwardersForServiceRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsForwardersForServiceRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsForwardersForServiceRepositoryInstance& anInstance);

  };

}

#endif
