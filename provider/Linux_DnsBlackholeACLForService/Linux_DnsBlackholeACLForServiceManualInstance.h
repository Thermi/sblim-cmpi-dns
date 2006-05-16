// =======================================================================
// Linux_DnsBlackholeACLForServiceManualInstance.h
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
#ifndef Linux_DnsBlackholeACLForServiceManualInstance_h
#define Linux_DnsBlackholeACLForServiceManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsBlackholeACLForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsBlackholeACLForServiceManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsBlackholeACLForServiceManualInstance& anInstance);
    void reset();
       
    Linux_DnsBlackholeACLForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsBlackholeACLForServiceManualInstance();
    Linux_DnsBlackholeACLForServiceManualInstance(
      const Linux_DnsBlackholeACLForServiceManualInstance& anInstance);
    Linux_DnsBlackholeACLForServiceManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsBlackholeACLForServiceManualInstance();
       
    Linux_DnsBlackholeACLForServiceManualInstance& operator=(
      const Linux_DnsBlackholeACLForServiceManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsBlackholeACLForServiceInstanceName& anInstanceName);        
    const Linux_DnsBlackholeACLForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsBlackholeACLForServiceManualInstanceEnumerationElement {

    Linux_DnsBlackholeACLForServiceManualInstance* m_elementP;
    Linux_DnsBlackholeACLForServiceManualInstanceEnumerationElement* m_nextP;

    Linux_DnsBlackholeACLForServiceManualInstanceEnumerationElement();
    ~Linux_DnsBlackholeACLForServiceManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsBlackholeACLForServiceManualInstanceEnumeration {

    private:
    Linux_DnsBlackholeACLForServiceManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsBlackholeACLForServiceManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsBlackholeACLForServiceManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsBlackholeACLForServiceManualInstanceEnumeration();
    Linux_DnsBlackholeACLForServiceManualInstanceEnumeration(
      const Linux_DnsBlackholeACLForServiceManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsBlackholeACLForServiceManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsBlackholeACLForServiceManualInstance& getNext();
    int getSize() const;
    const Linux_DnsBlackholeACLForServiceManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsBlackholeACLForServiceManualInstance& anInstance);

  };

}

#endif
