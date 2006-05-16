// =======================================================================
// Linux_DnsAllowUpdateACLForZoneRepositoryInstance.h
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
#ifndef Linux_DnsAllowUpdateACLForZoneRepositoryInstance_h
#define Linux_DnsAllowUpdateACLForZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowUpdateACLForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowUpdateACLForZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsAllowUpdateACLForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowUpdateACLForZoneRepositoryInstance();
    Linux_DnsAllowUpdateACLForZoneRepositoryInstance(
      const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& anInstance);
    Linux_DnsAllowUpdateACLForZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowUpdateACLForZoneRepositoryInstance();
       
    Linux_DnsAllowUpdateACLForZoneRepositoryInstance& operator=(
      const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowUpdateACLForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowUpdateACLForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement {

    Linux_DnsAllowUpdateACLForZoneRepositoryInstance* m_elementP;
    Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration();
    Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration(
      const Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& anInstance);

  };

}

#endif
