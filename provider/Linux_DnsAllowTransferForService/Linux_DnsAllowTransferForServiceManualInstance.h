// =======================================================================
// Linux_DnsAllowTransferForServiceManualInstance.h
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
#ifndef Linux_DnsAllowTransferForServiceManualInstance_h
#define Linux_DnsAllowTransferForServiceManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowTransferForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowTransferForServiceManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowTransferForServiceManualInstance& anInstance);
    void reset();
       
    Linux_DnsAllowTransferForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowTransferForServiceManualInstance();
    Linux_DnsAllowTransferForServiceManualInstance(
      const Linux_DnsAllowTransferForServiceManualInstance& anInstance);
    Linux_DnsAllowTransferForServiceManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowTransferForServiceManualInstance();
       
    Linux_DnsAllowTransferForServiceManualInstance& operator=(
      const Linux_DnsAllowTransferForServiceManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowTransferForServiceInstanceName& anInstanceName);        
    const Linux_DnsAllowTransferForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowTransferForServiceManualInstanceEnumerationElement {

    Linux_DnsAllowTransferForServiceManualInstance* m_elementP;
    Linux_DnsAllowTransferForServiceManualInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowTransferForServiceManualInstanceEnumerationElement();
    ~Linux_DnsAllowTransferForServiceManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowTransferForServiceManualInstanceEnumeration {

    private:
    Linux_DnsAllowTransferForServiceManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowTransferForServiceManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowTransferForServiceManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowTransferForServiceManualInstanceEnumeration();
    Linux_DnsAllowTransferForServiceManualInstanceEnumeration(
      const Linux_DnsAllowTransferForServiceManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowTransferForServiceManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowTransferForServiceManualInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowTransferForServiceManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowTransferForServiceManualInstance& anInstance);

  };

}

#endif
