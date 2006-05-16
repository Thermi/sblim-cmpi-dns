// =======================================================================
// Linux_DnsBlackholeACLForZoneManualInstance.h
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
#ifndef Linux_DnsBlackholeACLForZoneManualInstance_h
#define Linux_DnsBlackholeACLForZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsBlackholeACLForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsBlackholeACLForZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsBlackholeACLForZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsBlackholeACLForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsBlackholeACLForZoneManualInstance();
    Linux_DnsBlackholeACLForZoneManualInstance(
      const Linux_DnsBlackholeACLForZoneManualInstance& anInstance);
    Linux_DnsBlackholeACLForZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsBlackholeACLForZoneManualInstance();
       
    Linux_DnsBlackholeACLForZoneManualInstance& operator=(
      const Linux_DnsBlackholeACLForZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsBlackholeACLForZoneInstanceName& anInstanceName);        
    const Linux_DnsBlackholeACLForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsBlackholeACLForZoneManualInstanceEnumerationElement {

    Linux_DnsBlackholeACLForZoneManualInstance* m_elementP;
    Linux_DnsBlackholeACLForZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsBlackholeACLForZoneManualInstanceEnumerationElement();
    ~Linux_DnsBlackholeACLForZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsBlackholeACLForZoneManualInstanceEnumeration {

    private:
    Linux_DnsBlackholeACLForZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsBlackholeACLForZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsBlackholeACLForZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsBlackholeACLForZoneManualInstanceEnumeration();
    Linux_DnsBlackholeACLForZoneManualInstanceEnumeration(
      const Linux_DnsBlackholeACLForZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsBlackholeACLForZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsBlackholeACLForZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsBlackholeACLForZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsBlackholeACLForZoneManualInstance& anInstance);

  };

}

#endif
