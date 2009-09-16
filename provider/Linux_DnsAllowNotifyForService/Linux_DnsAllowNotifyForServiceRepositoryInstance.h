// =======================================================================
// Linux_DnsAllowNotifyForServiceRepositoryInstance.h
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
#ifndef Linux_DnsAllowNotifyForServiceRepositoryInstance_h
#define Linux_DnsAllowNotifyForServiceRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowNotifyForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowNotifyForServiceRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowNotifyForServiceRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsAllowNotifyForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowNotifyForServiceRepositoryInstance();
    Linux_DnsAllowNotifyForServiceRepositoryInstance(
      const Linux_DnsAllowNotifyForServiceRepositoryInstance& anInstance);
    Linux_DnsAllowNotifyForServiceRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowNotifyForServiceRepositoryInstance();
       
    Linux_DnsAllowNotifyForServiceRepositoryInstance& operator=(
      const Linux_DnsAllowNotifyForServiceRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowNotifyForServiceInstanceName& anInstanceName);        
    const Linux_DnsAllowNotifyForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumerationElement {

    Linux_DnsAllowNotifyForServiceRepositoryInstance* m_elementP;
    Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumerationElement();
    ~Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration {

    private:
    Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration();
    Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration(
      const Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowNotifyForServiceRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowNotifyForServiceRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowNotifyForServiceRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowNotifyForServiceRepositoryInstance& anInstance);

  };

}

#endif
