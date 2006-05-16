// =======================================================================
// Linux_DnsAllowQueryACLForZoneRepositoryInstance.h
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
#ifndef Linux_DnsAllowQueryACLForZoneRepositoryInstance_h
#define Linux_DnsAllowQueryACLForZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowQueryACLForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowQueryACLForZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowQueryACLForZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsAllowQueryACLForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowQueryACLForZoneRepositoryInstance();
    Linux_DnsAllowQueryACLForZoneRepositoryInstance(
      const Linux_DnsAllowQueryACLForZoneRepositoryInstance& anInstance);
    Linux_DnsAllowQueryACLForZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowQueryACLForZoneRepositoryInstance();
       
    Linux_DnsAllowQueryACLForZoneRepositoryInstance& operator=(
      const Linux_DnsAllowQueryACLForZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowQueryACLForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowQueryACLForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement {

    Linux_DnsAllowQueryACLForZoneRepositoryInstance* m_elementP;
    Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration();
    Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration(
      const Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowQueryACLForZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowQueryACLForZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowQueryACLForZoneRepositoryInstance& anInstance);

  };

}

#endif
