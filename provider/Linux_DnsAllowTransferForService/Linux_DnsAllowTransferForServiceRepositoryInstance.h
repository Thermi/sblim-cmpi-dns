// =======================================================================
// Linux_DnsAllowTransferForServiceRepositoryInstance.h
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
#ifndef Linux_DnsAllowTransferForServiceRepositoryInstance_h
#define Linux_DnsAllowTransferForServiceRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowTransferForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowTransferForServiceRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowTransferForServiceRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsAllowTransferForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowTransferForServiceRepositoryInstance();
    Linux_DnsAllowTransferForServiceRepositoryInstance(
      const Linux_DnsAllowTransferForServiceRepositoryInstance& anInstance);
    Linux_DnsAllowTransferForServiceRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowTransferForServiceRepositoryInstance();
       
    Linux_DnsAllowTransferForServiceRepositoryInstance& operator=(
      const Linux_DnsAllowTransferForServiceRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowTransferForServiceInstanceName& anInstanceName);        
    const Linux_DnsAllowTransferForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowTransferForServiceRepositoryInstanceEnumerationElement {

    Linux_DnsAllowTransferForServiceRepositoryInstance* m_elementP;
    Linux_DnsAllowTransferForServiceRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowTransferForServiceRepositoryInstanceEnumerationElement();
    ~Linux_DnsAllowTransferForServiceRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowTransferForServiceRepositoryInstanceEnumeration {

    private:
    Linux_DnsAllowTransferForServiceRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowTransferForServiceRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowTransferForServiceRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowTransferForServiceRepositoryInstanceEnumeration();
    Linux_DnsAllowTransferForServiceRepositoryInstanceEnumeration(
      const Linux_DnsAllowTransferForServiceRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowTransferForServiceRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowTransferForServiceRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowTransferForServiceRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowTransferForServiceRepositoryInstance& anInstance);

  };

}

#endif
