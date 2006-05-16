// =======================================================================
// Linux_DnsAllowUpdateACLForZoneManualInstance.h
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
#ifndef Linux_DnsAllowUpdateACLForZoneManualInstance_h
#define Linux_DnsAllowUpdateACLForZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowUpdateACLForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowUpdateACLForZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowUpdateACLForZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsAllowUpdateACLForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowUpdateACLForZoneManualInstance();
    Linux_DnsAllowUpdateACLForZoneManualInstance(
      const Linux_DnsAllowUpdateACLForZoneManualInstance& anInstance);
    Linux_DnsAllowUpdateACLForZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowUpdateACLForZoneManualInstance();
       
    Linux_DnsAllowUpdateACLForZoneManualInstance& operator=(
      const Linux_DnsAllowUpdateACLForZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowUpdateACLForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowUpdateACLForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement {

    Linux_DnsAllowUpdateACLForZoneManualInstance* m_elementP;
    Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement();
    ~Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration {

    private:
    Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration();
    Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration(
      const Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowUpdateACLForZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowUpdateACLForZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowUpdateACLForZoneManualInstance& anInstance);

  };

}

#endif
