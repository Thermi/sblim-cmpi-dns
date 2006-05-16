// =======================================================================
// Linux_DnsAllowQueryACLForZoneManualInstance.h
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
#ifndef Linux_DnsAllowQueryACLForZoneManualInstance_h
#define Linux_DnsAllowQueryACLForZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowQueryACLForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowQueryACLForZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowQueryACLForZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsAllowQueryACLForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowQueryACLForZoneManualInstance();
    Linux_DnsAllowQueryACLForZoneManualInstance(
      const Linux_DnsAllowQueryACLForZoneManualInstance& anInstance);
    Linux_DnsAllowQueryACLForZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowQueryACLForZoneManualInstance();
       
    Linux_DnsAllowQueryACLForZoneManualInstance& operator=(
      const Linux_DnsAllowQueryACLForZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowQueryACLForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowQueryACLForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement {

    Linux_DnsAllowQueryACLForZoneManualInstance* m_elementP;
    Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement();
    ~Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration {

    private:
    Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration();
    Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration(
      const Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowQueryACLForZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowQueryACLForZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowQueryACLForZoneManualInstance& anInstance);

  };

}

#endif
