// =======================================================================
// Linux_DnsBlackholeForServiceRepositoryInstance.h
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
#ifndef Linux_DnsBlackholeForServiceRepositoryInstance_h
#define Linux_DnsBlackholeForServiceRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsBlackholeForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsBlackholeForServiceRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsBlackholeForServiceRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsBlackholeForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsBlackholeForServiceRepositoryInstance();
    Linux_DnsBlackholeForServiceRepositoryInstance(
      const Linux_DnsBlackholeForServiceRepositoryInstance& anInstance);
    Linux_DnsBlackholeForServiceRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsBlackholeForServiceRepositoryInstance();
       
    Linux_DnsBlackholeForServiceRepositoryInstance& operator=(
      const Linux_DnsBlackholeForServiceRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsBlackholeForServiceInstanceName& anInstanceName);        
    const Linux_DnsBlackholeForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsBlackholeForServiceRepositoryInstanceEnumerationElement {

    Linux_DnsBlackholeForServiceRepositoryInstance* m_elementP;
    Linux_DnsBlackholeForServiceRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsBlackholeForServiceRepositoryInstanceEnumerationElement();
    ~Linux_DnsBlackholeForServiceRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsBlackholeForServiceRepositoryInstanceEnumeration {

    private:
    Linux_DnsBlackholeForServiceRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsBlackholeForServiceRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsBlackholeForServiceRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsBlackholeForServiceRepositoryInstanceEnumeration();
    Linux_DnsBlackholeForServiceRepositoryInstanceEnumeration(
      const Linux_DnsBlackholeForServiceRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsBlackholeForServiceRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsBlackholeForServiceRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsBlackholeForServiceRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsBlackholeForServiceRepositoryInstance& anInstance);

  };

}

#endif
