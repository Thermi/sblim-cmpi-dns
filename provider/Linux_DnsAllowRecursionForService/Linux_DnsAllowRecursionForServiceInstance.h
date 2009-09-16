// =======================================================================
// Linux_DnsAllowRecursionForServiceInstance.h
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
#ifndef Linux_DnsAllowRecursionForServiceInstance_h
#define Linux_DnsAllowRecursionForServiceInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowRecursionForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowRecursionForServiceInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowRecursionForServiceInstance& anInstance);
    void reset();
       
    Linux_DnsAllowRecursionForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowRecursionForServiceInstance();
    Linux_DnsAllowRecursionForServiceInstance(
      const Linux_DnsAllowRecursionForServiceInstance& anInstance);
    Linux_DnsAllowRecursionForServiceInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowRecursionForServiceInstance();
       
    Linux_DnsAllowRecursionForServiceInstance& operator=(
      const Linux_DnsAllowRecursionForServiceInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowRecursionForServiceInstanceName& anInstanceName);        
    const Linux_DnsAllowRecursionForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowRecursionForServiceInstanceEnumerationElement {

    Linux_DnsAllowRecursionForServiceInstance* m_elementP;
    Linux_DnsAllowRecursionForServiceInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowRecursionForServiceInstanceEnumerationElement();
    ~Linux_DnsAllowRecursionForServiceInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowRecursionForServiceInstanceEnumeration {

    private:
    Linux_DnsAllowRecursionForServiceInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowRecursionForServiceInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowRecursionForServiceInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowRecursionForServiceInstanceEnumeration();
    Linux_DnsAllowRecursionForServiceInstanceEnumeration(
      const Linux_DnsAllowRecursionForServiceInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowRecursionForServiceInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowRecursionForServiceInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowRecursionForServiceInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowRecursionForServiceInstance& anInstance);

  };

}

#endif
