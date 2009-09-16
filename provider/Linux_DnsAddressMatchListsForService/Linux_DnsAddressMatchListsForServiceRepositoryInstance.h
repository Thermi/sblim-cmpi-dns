// =======================================================================
// Linux_DnsAddressMatchListsForServiceRepositoryInstance.h
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
#ifndef Linux_DnsAddressMatchListsForServiceRepositoryInstance_h
#define Linux_DnsAddressMatchListsForServiceRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAddressMatchListsForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAddressMatchListsForServiceRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsAddressMatchListsForServiceRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsAddressMatchListsForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAddressMatchListsForServiceRepositoryInstance();
    Linux_DnsAddressMatchListsForServiceRepositoryInstance(
      const Linux_DnsAddressMatchListsForServiceRepositoryInstance& anInstance);
    Linux_DnsAddressMatchListsForServiceRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAddressMatchListsForServiceRepositoryInstance();
       
    Linux_DnsAddressMatchListsForServiceRepositoryInstance& operator=(
      const Linux_DnsAddressMatchListsForServiceRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAddressMatchListsForServiceInstanceName& anInstanceName);        
    const Linux_DnsAddressMatchListsForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAddressMatchListsForServiceRepositoryInstanceEnumerationElement {

    Linux_DnsAddressMatchListsForServiceRepositoryInstance* m_elementP;
    Linux_DnsAddressMatchListsForServiceRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsAddressMatchListsForServiceRepositoryInstanceEnumerationElement();
    ~Linux_DnsAddressMatchListsForServiceRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsAddressMatchListsForServiceRepositoryInstanceEnumeration {

    private:
    Linux_DnsAddressMatchListsForServiceRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAddressMatchListsForServiceRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAddressMatchListsForServiceRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAddressMatchListsForServiceRepositoryInstanceEnumeration();
    Linux_DnsAddressMatchListsForServiceRepositoryInstanceEnumeration(
      const Linux_DnsAddressMatchListsForServiceRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAddressMatchListsForServiceRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAddressMatchListsForServiceRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsAddressMatchListsForServiceRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAddressMatchListsForServiceRepositoryInstance& anInstance);

  };

}

#endif
