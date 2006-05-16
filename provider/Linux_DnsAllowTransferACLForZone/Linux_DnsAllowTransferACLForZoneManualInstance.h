// =======================================================================
// Linux_DnsAllowTransferACLForZoneManualInstance.h
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
#ifndef Linux_DnsAllowTransferACLForZoneManualInstance_h
#define Linux_DnsAllowTransferACLForZoneManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowTransferACLForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowTransferACLForZoneManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowTransferACLForZoneManualInstance& anInstance);
    void reset();
       
    Linux_DnsAllowTransferACLForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowTransferACLForZoneManualInstance();
    Linux_DnsAllowTransferACLForZoneManualInstance(
      const Linux_DnsAllowTransferACLForZoneManualInstance& anInstance);
    Linux_DnsAllowTransferACLForZoneManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowTransferACLForZoneManualInstance();
       
    Linux_DnsAllowTransferACLForZoneManualInstance& operator=(
      const Linux_DnsAllowTransferACLForZoneManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowTransferACLForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowTransferACLForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement {

    Linux_DnsAllowTransferACLForZoneManualInstance* m_elementP;
    Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement();
    ~Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration {

    private:
    Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration();
    Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration(
      const Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowTransferACLForZoneManualInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowTransferACLForZoneManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowTransferACLForZoneManualInstance& anInstance);

  };

}

#endif
