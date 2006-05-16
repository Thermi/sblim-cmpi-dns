// =======================================================================
// Linux_DnsBlackholeACLForZoneRepositoryInstance.h
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
#ifndef Linux_DnsBlackholeACLForZoneRepositoryInstance_h
#define Linux_DnsBlackholeACLForZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsBlackholeACLForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsBlackholeACLForZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsBlackholeACLForZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsBlackholeACLForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsBlackholeACLForZoneRepositoryInstance();
    Linux_DnsBlackholeACLForZoneRepositoryInstance(
      const Linux_DnsBlackholeACLForZoneRepositoryInstance& anInstance);
    Linux_DnsBlackholeACLForZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsBlackholeACLForZoneRepositoryInstance();
       
    Linux_DnsBlackholeACLForZoneRepositoryInstance& operator=(
      const Linux_DnsBlackholeACLForZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsBlackholeACLForZoneInstanceName& anInstanceName);        
    const Linux_DnsBlackholeACLForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsBlackholeACLForZoneRepositoryInstanceEnumerationElement {

    Linux_DnsBlackholeACLForZoneRepositoryInstance* m_elementP;
    Linux_DnsBlackholeACLForZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsBlackholeACLForZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsBlackholeACLForZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsBlackholeACLForZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsBlackholeACLForZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsBlackholeACLForZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsBlackholeACLForZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsBlackholeACLForZoneRepositoryInstanceEnumeration();
    Linux_DnsBlackholeACLForZoneRepositoryInstanceEnumeration(
      const Linux_DnsBlackholeACLForZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsBlackholeACLForZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsBlackholeACLForZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsBlackholeACLForZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsBlackholeACLForZoneRepositoryInstance& anInstance);

  };

}

#endif
