// =======================================================================
// Linux_DnsAllowQueryForServiceInstance.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
// 
// Copyright (c) 2006, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Common Public License from
// http://www.opensource.org/licenses/cpl1.0.txt
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
#ifndef Linux_DnsAllowQueryForServiceInstance_h
#define Linux_DnsAllowQueryForServiceInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowQueryForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowQueryForServiceInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowQueryForServiceInstance& anInstance);
    void reset();
       
    Linux_DnsAllowQueryForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowQueryForServiceInstance();
    Linux_DnsAllowQueryForServiceInstance(
      const Linux_DnsAllowQueryForServiceInstance& anInstance);
    Linux_DnsAllowQueryForServiceInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowQueryForServiceInstance();
       
    Linux_DnsAllowQueryForServiceInstance& operator=(
      const Linux_DnsAllowQueryForServiceInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowQueryForServiceInstanceName& anInstanceName);        
    const Linux_DnsAllowQueryForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowQueryForServiceInstanceEnumerationElement {

    Linux_DnsAllowQueryForServiceInstance* m_elementP;
    Linux_DnsAllowQueryForServiceInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowQueryForServiceInstanceEnumerationElement();
    ~Linux_DnsAllowQueryForServiceInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowQueryForServiceInstanceEnumeration {

    private:
    Linux_DnsAllowQueryForServiceInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowQueryForServiceInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowQueryForServiceInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowQueryForServiceInstanceEnumeration();
    Linux_DnsAllowQueryForServiceInstanceEnumeration(
      const Linux_DnsAllowQueryForServiceInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowQueryForServiceInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowQueryForServiceInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowQueryForServiceInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowQueryForServiceInstance& anInstance);

  };

}

#endif
