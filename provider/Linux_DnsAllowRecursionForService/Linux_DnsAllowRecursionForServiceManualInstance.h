// =======================================================================
// Linux_DnsAllowRecursionForServiceManualInstance.h
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
#ifndef Linux_DnsAllowRecursionForServiceManualInstance_h
#define Linux_DnsAllowRecursionForServiceManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowRecursionForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowRecursionForServiceManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowRecursionForServiceManualInstance& anInstance);
    void reset();
       
    Linux_DnsAllowRecursionForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowRecursionForServiceManualInstance();
    Linux_DnsAllowRecursionForServiceManualInstance(
      const Linux_DnsAllowRecursionForServiceManualInstance& anInstance);
    Linux_DnsAllowRecursionForServiceManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowRecursionForServiceManualInstance();
       
    Linux_DnsAllowRecursionForServiceManualInstance& operator=(
      const Linux_DnsAllowRecursionForServiceManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowRecursionForServiceInstanceName& anInstanceName);        
    const Linux_DnsAllowRecursionForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowRecursionForServiceManualInstanceEnumerationElement {

    Linux_DnsAllowRecursionForServiceManualInstance* m_elementP;
    Linux_DnsAllowRecursionForServiceManualInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowRecursionForServiceManualInstanceEnumerationElement();
    ~Linux_DnsAllowRecursionForServiceManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowRecursionForServiceManualInstanceEnumeration {

    private:
    Linux_DnsAllowRecursionForServiceManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowRecursionForServiceManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowRecursionForServiceManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowRecursionForServiceManualInstanceEnumeration();
    Linux_DnsAllowRecursionForServiceManualInstanceEnumeration(
      const Linux_DnsAllowRecursionForServiceManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowRecursionForServiceManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowRecursionForServiceManualInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowRecursionForServiceManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowRecursionForServiceManualInstance& anInstance);

  };

}

#endif
