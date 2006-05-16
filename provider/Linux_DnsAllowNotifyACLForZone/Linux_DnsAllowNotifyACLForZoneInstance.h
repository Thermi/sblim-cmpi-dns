// =======================================================================
// Linux_DnsAllowNotifyACLForZoneInstance.h
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
#ifndef Linux_DnsAllowNotifyACLForZoneInstance_h
#define Linux_DnsAllowNotifyACLForZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowNotifyACLForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowNotifyACLForZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowNotifyACLForZoneInstance& anInstance);
    void reset();
       
    Linux_DnsAllowNotifyACLForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowNotifyACLForZoneInstance();
    Linux_DnsAllowNotifyACLForZoneInstance(
      const Linux_DnsAllowNotifyACLForZoneInstance& anInstance);
    Linux_DnsAllowNotifyACLForZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowNotifyACLForZoneInstance();
       
    Linux_DnsAllowNotifyACLForZoneInstance& operator=(
      const Linux_DnsAllowNotifyACLForZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowNotifyACLForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowNotifyACLForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement {

    Linux_DnsAllowNotifyACLForZoneInstance* m_elementP;
    Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement();
    ~Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowNotifyACLForZoneInstanceEnumeration {

    private:
    Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowNotifyACLForZoneInstanceEnumeration();
    Linux_DnsAllowNotifyACLForZoneInstanceEnumeration(
      const Linux_DnsAllowNotifyACLForZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowNotifyACLForZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowNotifyACLForZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowNotifyACLForZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowNotifyACLForZoneInstance& anInstance);

  };

}

#endif
