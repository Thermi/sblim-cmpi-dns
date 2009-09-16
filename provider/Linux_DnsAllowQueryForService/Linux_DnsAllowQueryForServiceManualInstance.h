// =======================================================================
// Linux_DnsAllowQueryForServiceManualInstance.h
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
#ifndef Linux_DnsAllowQueryForServiceManualInstance_h
#define Linux_DnsAllowQueryForServiceManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowQueryForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowQueryForServiceManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowQueryForServiceManualInstance& anInstance);
    void reset();
       
    Linux_DnsAllowQueryForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowQueryForServiceManualInstance();
    Linux_DnsAllowQueryForServiceManualInstance(
      const Linux_DnsAllowQueryForServiceManualInstance& anInstance);
    Linux_DnsAllowQueryForServiceManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowQueryForServiceManualInstance();
       
    Linux_DnsAllowQueryForServiceManualInstance& operator=(
      const Linux_DnsAllowQueryForServiceManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowQueryForServiceInstanceName& anInstanceName);        
    const Linux_DnsAllowQueryForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowQueryForServiceManualInstanceEnumerationElement {

    Linux_DnsAllowQueryForServiceManualInstance* m_elementP;
    Linux_DnsAllowQueryForServiceManualInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowQueryForServiceManualInstanceEnumerationElement();
    ~Linux_DnsAllowQueryForServiceManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowQueryForServiceManualInstanceEnumeration {

    private:
    Linux_DnsAllowQueryForServiceManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowQueryForServiceManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowQueryForServiceManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowQueryForServiceManualInstanceEnumeration();
    Linux_DnsAllowQueryForServiceManualInstanceEnumeration(
      const Linux_DnsAllowQueryForServiceManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowQueryForServiceManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowQueryForServiceManualInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowQueryForServiceManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowQueryForServiceManualInstance& anInstance);

  };

}

#endif
