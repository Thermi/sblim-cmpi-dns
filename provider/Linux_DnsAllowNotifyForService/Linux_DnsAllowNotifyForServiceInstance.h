// =======================================================================
// Linux_DnsAllowNotifyForServiceInstance.h
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
#ifndef Linux_DnsAllowNotifyForServiceInstance_h
#define Linux_DnsAllowNotifyForServiceInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowNotifyForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowNotifyForServiceInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowNotifyForServiceInstance& anInstance);
    void reset();
       
    Linux_DnsAllowNotifyForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowNotifyForServiceInstance();
    Linux_DnsAllowNotifyForServiceInstance(
      const Linux_DnsAllowNotifyForServiceInstance& anInstance);
    Linux_DnsAllowNotifyForServiceInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowNotifyForServiceInstance();
       
    Linux_DnsAllowNotifyForServiceInstance& operator=(
      const Linux_DnsAllowNotifyForServiceInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowNotifyForServiceInstanceName& anInstanceName);        
    const Linux_DnsAllowNotifyForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowNotifyForServiceInstanceEnumerationElement {

    Linux_DnsAllowNotifyForServiceInstance* m_elementP;
    Linux_DnsAllowNotifyForServiceInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowNotifyForServiceInstanceEnumerationElement();
    ~Linux_DnsAllowNotifyForServiceInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowNotifyForServiceInstanceEnumeration {

    private:
    Linux_DnsAllowNotifyForServiceInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowNotifyForServiceInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowNotifyForServiceInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowNotifyForServiceInstanceEnumeration();
    Linux_DnsAllowNotifyForServiceInstanceEnumeration(
      const Linux_DnsAllowNotifyForServiceInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowNotifyForServiceInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowNotifyForServiceInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowNotifyForServiceInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowNotifyForServiceInstance& anInstance);

  };

}

#endif
