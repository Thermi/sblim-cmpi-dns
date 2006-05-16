// =======================================================================
// Linux_DnsAllowTransferACLForZoneInstance.h
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
#ifndef Linux_DnsAllowTransferACLForZoneInstance_h
#define Linux_DnsAllowTransferACLForZoneInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowTransferACLForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowTransferACLForZoneInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowTransferACLForZoneInstance& anInstance);
    void reset();
       
    Linux_DnsAllowTransferACLForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowTransferACLForZoneInstance();
    Linux_DnsAllowTransferACLForZoneInstance(
      const Linux_DnsAllowTransferACLForZoneInstance& anInstance);
    Linux_DnsAllowTransferACLForZoneInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowTransferACLForZoneInstance();
       
    Linux_DnsAllowTransferACLForZoneInstance& operator=(
      const Linux_DnsAllowTransferACLForZoneInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowTransferACLForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowTransferACLForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement {

    Linux_DnsAllowTransferACLForZoneInstance* m_elementP;
    Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement();
    ~Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowTransferACLForZoneInstanceEnumeration {

    private:
    Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowTransferACLForZoneInstanceEnumeration();
    Linux_DnsAllowTransferACLForZoneInstanceEnumeration(
      const Linux_DnsAllowTransferACLForZoneInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowTransferACLForZoneInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowTransferACLForZoneInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowTransferACLForZoneInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowTransferACLForZoneInstance& anInstance);

  };

}

#endif
