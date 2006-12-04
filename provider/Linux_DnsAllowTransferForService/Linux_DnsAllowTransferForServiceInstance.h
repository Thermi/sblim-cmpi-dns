// =======================================================================
// Linux_DnsAllowTransferForServiceInstance.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
// 
// Copyright (c) 2006, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Common Public License from
// http://oss.software.ibm.com/developerworks/opensource/license-cpl.html
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
#ifndef Linux_DnsAllowTransferForServiceInstance_h
#define Linux_DnsAllowTransferForServiceInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowTransferForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowTransferForServiceInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowTransferForServiceInstance& anInstance);
    void reset();
       
    Linux_DnsAllowTransferForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowTransferForServiceInstance();
    Linux_DnsAllowTransferForServiceInstance(
      const Linux_DnsAllowTransferForServiceInstance& anInstance);
    Linux_DnsAllowTransferForServiceInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowTransferForServiceInstance();
       
    Linux_DnsAllowTransferForServiceInstance& operator=(
      const Linux_DnsAllowTransferForServiceInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowTransferForServiceInstanceName& anInstanceName);        
    const Linux_DnsAllowTransferForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowTransferForServiceInstanceEnumerationElement {

    Linux_DnsAllowTransferForServiceInstance* m_elementP;
    Linux_DnsAllowTransferForServiceInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowTransferForServiceInstanceEnumerationElement();
    ~Linux_DnsAllowTransferForServiceInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowTransferForServiceInstanceEnumeration {

    private:
    Linux_DnsAllowTransferForServiceInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowTransferForServiceInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowTransferForServiceInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowTransferForServiceInstanceEnumeration();
    Linux_DnsAllowTransferForServiceInstanceEnumeration(
      const Linux_DnsAllowTransferForServiceInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowTransferForServiceInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowTransferForServiceInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowTransferForServiceInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowTransferForServiceInstance& anInstance);

  };

}

#endif