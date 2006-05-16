// =======================================================================
// Linux_DnsAllowTransferACLForZoneRepositoryInstance.h
//     created on Fri, 3 Mar 2006 using ECUTE
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
//                Murillo Bernardes <bernarde@br.ibm.com>
//                Wolfgang Taphorn <taphorn@de.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsAllowTransferACLForZoneRepositoryInstance_h
#define Linux_DnsAllowTransferACLForZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowTransferACLForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowTransferACLForZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowTransferACLForZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsAllowTransferACLForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowTransferACLForZoneRepositoryInstance();
    Linux_DnsAllowTransferACLForZoneRepositoryInstance(
      const Linux_DnsAllowTransferACLForZoneRepositoryInstance& anInstance);
    Linux_DnsAllowTransferACLForZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowTransferACLForZoneRepositoryInstance();
       
    Linux_DnsAllowTransferACLForZoneRepositoryInstance& operator=(
      const Linux_DnsAllowTransferACLForZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowTransferACLForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowTransferACLForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement {

    Linux_DnsAllowTransferACLForZoneRepositoryInstance* m_elementP;
    Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration();
    Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration(
      const Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowTransferACLForZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowTransferACLForZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowTransferACLForZoneRepositoryInstance& anInstance);

  };

}

#endif
