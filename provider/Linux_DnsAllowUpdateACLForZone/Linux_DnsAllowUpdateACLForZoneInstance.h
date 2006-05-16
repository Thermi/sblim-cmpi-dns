// =======================================================================
// Linux_DnsAllowUpdateACLForZoneInstance.h
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
#ifndef Linux_DnsAllowUpdateACLForZoneInstance_h
#define Linux_DnsAllowUpdateACLForZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowUpdateACLForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowUpdateACLForZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowUpdateACLForZoneInstance& anInstance);
    void reset();
       
    Linux_DnsAllowUpdateACLForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowUpdateACLForZoneInstance();
    Linux_DnsAllowUpdateACLForZoneInstance(
      const Linux_DnsAllowUpdateACLForZoneInstance& anInstance);
    Linux_DnsAllowUpdateACLForZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowUpdateACLForZoneInstance();
       
    Linux_DnsAllowUpdateACLForZoneInstance& operator=(
      const Linux_DnsAllowUpdateACLForZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowUpdateACLForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowUpdateACLForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement {

    Linux_DnsAllowUpdateACLForZoneInstance* m_elementP;
    Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement();
    ~Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowUpdateACLForZoneInstanceEnumeration {

    private:
    Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowUpdateACLForZoneInstanceEnumeration();
    Linux_DnsAllowUpdateACLForZoneInstanceEnumeration(
      const Linux_DnsAllowUpdateACLForZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowUpdateACLForZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowUpdateACLForZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowUpdateACLForZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowUpdateACLForZoneInstance& anInstance);

  };

}

#endif
