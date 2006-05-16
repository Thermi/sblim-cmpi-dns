// =======================================================================
// Linux_DnsAllowQueryACLForZoneInstance.h
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
#ifndef Linux_DnsAllowQueryACLForZoneInstance_h
#define Linux_DnsAllowQueryACLForZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowQueryACLForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowQueryACLForZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowQueryACLForZoneInstance& anInstance);
    void reset();
       
    Linux_DnsAllowQueryACLForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowQueryACLForZoneInstance();
    Linux_DnsAllowQueryACLForZoneInstance(
      const Linux_DnsAllowQueryACLForZoneInstance& anInstance);
    Linux_DnsAllowQueryACLForZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowQueryACLForZoneInstance();
       
    Linux_DnsAllowQueryACLForZoneInstance& operator=(
      const Linux_DnsAllowQueryACLForZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowQueryACLForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowQueryACLForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement {

    Linux_DnsAllowQueryACLForZoneInstance* m_elementP;
    Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement();
    ~Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowQueryACLForZoneInstanceEnumeration {

    private:
    Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowQueryACLForZoneInstanceEnumeration();
    Linux_DnsAllowQueryACLForZoneInstanceEnumeration(
      const Linux_DnsAllowQueryACLForZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowQueryACLForZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowQueryACLForZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowQueryACLForZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowQueryACLForZoneInstance& anInstance);

  };

}

#endif
