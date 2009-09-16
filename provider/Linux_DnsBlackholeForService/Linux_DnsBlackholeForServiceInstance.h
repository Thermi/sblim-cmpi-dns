// =======================================================================
// Linux_DnsBlackholeForServiceInstance.h
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
#ifndef Linux_DnsBlackholeForServiceInstance_h
#define Linux_DnsBlackholeForServiceInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsBlackholeForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsBlackholeForServiceInstance {
       
    private:
    void init();
    void init(const Linux_DnsBlackholeForServiceInstance& anInstance);
    void reset();
       
    Linux_DnsBlackholeForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsBlackholeForServiceInstance();
    Linux_DnsBlackholeForServiceInstance(
      const Linux_DnsBlackholeForServiceInstance& anInstance);
    Linux_DnsBlackholeForServiceInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsBlackholeForServiceInstance();
       
    Linux_DnsBlackholeForServiceInstance& operator=(
      const Linux_DnsBlackholeForServiceInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsBlackholeForServiceInstanceName& anInstanceName);        
    const Linux_DnsBlackholeForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsBlackholeForServiceInstanceEnumerationElement {

    Linux_DnsBlackholeForServiceInstance* m_elementP;
    Linux_DnsBlackholeForServiceInstanceEnumerationElement* m_nextP;

    Linux_DnsBlackholeForServiceInstanceEnumerationElement();
    ~Linux_DnsBlackholeForServiceInstanceEnumerationElement();  

  };
  

  class Linux_DnsBlackholeForServiceInstanceEnumeration {

    private:
    Linux_DnsBlackholeForServiceInstanceEnumerationElement* m_firstElementP;
    Linux_DnsBlackholeForServiceInstanceEnumerationElement* m_currentElementP;
    Linux_DnsBlackholeForServiceInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsBlackholeForServiceInstanceEnumeration();
    Linux_DnsBlackholeForServiceInstanceEnumeration(
      const Linux_DnsBlackholeForServiceInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsBlackholeForServiceInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsBlackholeForServiceInstance& getNext();
    int getSize() const;
    const Linux_DnsBlackholeForServiceInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsBlackholeForServiceInstance& anInstance);

  };

}

#endif
