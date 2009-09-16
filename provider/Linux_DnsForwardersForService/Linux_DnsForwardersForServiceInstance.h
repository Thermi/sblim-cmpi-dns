// =======================================================================
// Linux_DnsForwardersForServiceInstance.h
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
#ifndef Linux_DnsForwardersForServiceInstance_h
#define Linux_DnsForwardersForServiceInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsForwardersForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsForwardersForServiceInstance {
       
    private:
    void init();
    void init(const Linux_DnsForwardersForServiceInstance& anInstance);
    void reset();
       
    Linux_DnsForwardersForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsForwardersForServiceInstance();
    Linux_DnsForwardersForServiceInstance(
      const Linux_DnsForwardersForServiceInstance& anInstance);
    Linux_DnsForwardersForServiceInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsForwardersForServiceInstance();
       
    Linux_DnsForwardersForServiceInstance& operator=(
      const Linux_DnsForwardersForServiceInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsForwardersForServiceInstanceName& anInstanceName);        
    const Linux_DnsForwardersForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsForwardersForServiceInstanceEnumerationElement {

    Linux_DnsForwardersForServiceInstance* m_elementP;
    Linux_DnsForwardersForServiceInstanceEnumerationElement* m_nextP;

    Linux_DnsForwardersForServiceInstanceEnumerationElement();
    ~Linux_DnsForwardersForServiceInstanceEnumerationElement();  

  };
  

  class Linux_DnsForwardersForServiceInstanceEnumeration {

    private:
    Linux_DnsForwardersForServiceInstanceEnumerationElement* m_firstElementP;
    Linux_DnsForwardersForServiceInstanceEnumerationElement* m_currentElementP;
    Linux_DnsForwardersForServiceInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsForwardersForServiceInstanceEnumeration();
    Linux_DnsForwardersForServiceInstanceEnumeration(
      const Linux_DnsForwardersForServiceInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsForwardersForServiceInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsForwardersForServiceInstance& getNext();
    int getSize() const;
    const Linux_DnsForwardersForServiceInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsForwardersForServiceInstance& anInstance);

  };

}

#endif
