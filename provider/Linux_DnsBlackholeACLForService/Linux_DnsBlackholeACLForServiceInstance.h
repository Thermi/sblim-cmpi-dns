// =======================================================================
// Linux_DnsBlackholeACLForServiceInstance.h
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
#ifndef Linux_DnsBlackholeACLForServiceInstance_h
#define Linux_DnsBlackholeACLForServiceInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsBlackholeACLForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsBlackholeACLForServiceInstance {
       
    private:
    void init();
    void init(const Linux_DnsBlackholeACLForServiceInstance& anInstance);
    void reset();
       
    Linux_DnsBlackholeACLForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsBlackholeACLForServiceInstance();
    Linux_DnsBlackholeACLForServiceInstance(
      const Linux_DnsBlackholeACLForServiceInstance& anInstance);
    Linux_DnsBlackholeACLForServiceInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsBlackholeACLForServiceInstance();
       
    Linux_DnsBlackholeACLForServiceInstance& operator=(
      const Linux_DnsBlackholeACLForServiceInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsBlackholeACLForServiceInstanceName& anInstanceName);        
    const Linux_DnsBlackholeACLForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsBlackholeACLForServiceInstanceEnumerationElement {

    Linux_DnsBlackholeACLForServiceInstance* m_elementP;
    Linux_DnsBlackholeACLForServiceInstanceEnumerationElement* m_nextP;

    Linux_DnsBlackholeACLForServiceInstanceEnumerationElement();
    ~Linux_DnsBlackholeACLForServiceInstanceEnumerationElement();  

  };
  

  class Linux_DnsBlackholeACLForServiceInstanceEnumeration {

    private:
    Linux_DnsBlackholeACLForServiceInstanceEnumerationElement* m_firstElementP;
    Linux_DnsBlackholeACLForServiceInstanceEnumerationElement* m_currentElementP;
    Linux_DnsBlackholeACLForServiceInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsBlackholeACLForServiceInstanceEnumeration();
    Linux_DnsBlackholeACLForServiceInstanceEnumeration(
      const Linux_DnsBlackholeACLForServiceInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsBlackholeACLForServiceInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsBlackholeACLForServiceInstance& getNext();
    int getSize() const;
    const Linux_DnsBlackholeACLForServiceInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsBlackholeACLForServiceInstance& anInstance);

  };

}

#endif
