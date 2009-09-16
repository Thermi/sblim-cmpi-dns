// =======================================================================
// Linux_DnsAllowNotifyForServiceManualInstance.h
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
#ifndef Linux_DnsAllowNotifyForServiceManualInstance_h
#define Linux_DnsAllowNotifyForServiceManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowNotifyForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowNotifyForServiceManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowNotifyForServiceManualInstance& anInstance);
    void reset();
       
    Linux_DnsAllowNotifyForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowNotifyForServiceManualInstance();
    Linux_DnsAllowNotifyForServiceManualInstance(
      const Linux_DnsAllowNotifyForServiceManualInstance& anInstance);
    Linux_DnsAllowNotifyForServiceManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowNotifyForServiceManualInstance();
       
    Linux_DnsAllowNotifyForServiceManualInstance& operator=(
      const Linux_DnsAllowNotifyForServiceManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowNotifyForServiceInstanceName& anInstanceName);        
    const Linux_DnsAllowNotifyForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowNotifyForServiceManualInstanceEnumerationElement {

    Linux_DnsAllowNotifyForServiceManualInstance* m_elementP;
    Linux_DnsAllowNotifyForServiceManualInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowNotifyForServiceManualInstanceEnumerationElement();
    ~Linux_DnsAllowNotifyForServiceManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowNotifyForServiceManualInstanceEnumeration {

    private:
    Linux_DnsAllowNotifyForServiceManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowNotifyForServiceManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowNotifyForServiceManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowNotifyForServiceManualInstanceEnumeration();
    Linux_DnsAllowNotifyForServiceManualInstanceEnumeration(
      const Linux_DnsAllowNotifyForServiceManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowNotifyForServiceManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowNotifyForServiceManualInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowNotifyForServiceManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowNotifyForServiceManualInstance& anInstance);

  };

}

#endif
