// =======================================================================
// Linux_DnsAllowNotifyACLForZoneRepositoryInstance.h
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
#ifndef Linux_DnsAllowNotifyACLForZoneRepositoryInstance_h
#define Linux_DnsAllowNotifyACLForZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowNotifyACLForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowNotifyACLForZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsAllowNotifyACLForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowNotifyACLForZoneRepositoryInstance();
    Linux_DnsAllowNotifyACLForZoneRepositoryInstance(
      const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& anInstance);
    Linux_DnsAllowNotifyACLForZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowNotifyACLForZoneRepositoryInstance();
       
    Linux_DnsAllowNotifyACLForZoneRepositoryInstance& operator=(
      const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowNotifyACLForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowNotifyACLForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement {

    Linux_DnsAllowNotifyACLForZoneRepositoryInstance* m_elementP;
    Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration();
    Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration(
      const Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& anInstance);

  };

}

#endif
