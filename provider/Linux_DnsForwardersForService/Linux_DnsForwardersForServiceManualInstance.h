// =======================================================================
// Linux_DnsForwardersForServiceManualInstance.h
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
#ifndef Linux_DnsForwardersForServiceManualInstance_h
#define Linux_DnsForwardersForServiceManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsForwardersForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsForwardersForServiceManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsForwardersForServiceManualInstance& anInstance);
    void reset();
       
    Linux_DnsForwardersForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsForwardersForServiceManualInstance();
    Linux_DnsForwardersForServiceManualInstance(
      const Linux_DnsForwardersForServiceManualInstance& anInstance);
    Linux_DnsForwardersForServiceManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsForwardersForServiceManualInstance();
       
    Linux_DnsForwardersForServiceManualInstance& operator=(
      const Linux_DnsForwardersForServiceManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsForwardersForServiceInstanceName& anInstanceName);        
    const Linux_DnsForwardersForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsForwardersForServiceManualInstanceEnumerationElement {

    Linux_DnsForwardersForServiceManualInstance* m_elementP;
    Linux_DnsForwardersForServiceManualInstanceEnumerationElement* m_nextP;

    Linux_DnsForwardersForServiceManualInstanceEnumerationElement();
    ~Linux_DnsForwardersForServiceManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsForwardersForServiceManualInstanceEnumeration {

    private:
    Linux_DnsForwardersForServiceManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsForwardersForServiceManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsForwardersForServiceManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsForwardersForServiceManualInstanceEnumeration();
    Linux_DnsForwardersForServiceManualInstanceEnumeration(
      const Linux_DnsForwardersForServiceManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsForwardersForServiceManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsForwardersForServiceManualInstance& getNext();
    int getSize() const;
    const Linux_DnsForwardersForServiceManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsForwardersForServiceManualInstance& anInstance);

  };

}

#endif
