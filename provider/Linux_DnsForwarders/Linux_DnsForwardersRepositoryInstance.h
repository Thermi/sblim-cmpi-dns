// =======================================================================
// Linux_DnsForwardersRepositoryInstance.h
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
#ifndef Linux_DnsForwardersRepositoryInstance_h
#define Linux_DnsForwardersRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsForwardersInstanceName.h"


namespace genProvider {

  class Linux_DnsForwardersRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsForwardersRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsForwardersInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsForwardersRepositoryInstance();
    Linux_DnsForwardersRepositoryInstance(
      const Linux_DnsForwardersRepositoryInstance& anInstance);
    Linux_DnsForwardersRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsForwardersRepositoryInstance();
       
    Linux_DnsForwardersRepositoryInstance& operator=(
      const Linux_DnsForwardersRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsForwardersInstanceName& anInstanceName);        
    const Linux_DnsForwardersInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsForwardersRepositoryInstanceEnumerationElement {

    Linux_DnsForwardersRepositoryInstance* m_elementP;
    Linux_DnsForwardersRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsForwardersRepositoryInstanceEnumerationElement();
    ~Linux_DnsForwardersRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsForwardersRepositoryInstanceEnumeration {

    private:
    Linux_DnsForwardersRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsForwardersRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsForwardersRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsForwardersRepositoryInstanceEnumeration();
    Linux_DnsForwardersRepositoryInstanceEnumeration(
      const Linux_DnsForwardersRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsForwardersRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsForwardersRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsForwardersRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsForwardersRepositoryInstance& anInstance);

  };

}

#endif
