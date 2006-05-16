// =======================================================================
// Linux_DnsQueryACLForServiceManualInstance.h
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
#ifndef Linux_DnsQueryACLForServiceManualInstance_h
#define Linux_DnsQueryACLForServiceManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsQueryACLForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsQueryACLForServiceManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsQueryACLForServiceManualInstance& anInstance);
    void reset();
       
    Linux_DnsQueryACLForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsQueryACLForServiceManualInstance();
    Linux_DnsQueryACLForServiceManualInstance(
      const Linux_DnsQueryACLForServiceManualInstance& anInstance);
    Linux_DnsQueryACLForServiceManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsQueryACLForServiceManualInstance();
       
    Linux_DnsQueryACLForServiceManualInstance& operator=(
      const Linux_DnsQueryACLForServiceManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsQueryACLForServiceInstanceName& anInstanceName);        
    const Linux_DnsQueryACLForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsQueryACLForServiceManualInstanceEnumerationElement {

    Linux_DnsQueryACLForServiceManualInstance* m_elementP;
    Linux_DnsQueryACLForServiceManualInstanceEnumerationElement* m_nextP;

    Linux_DnsQueryACLForServiceManualInstanceEnumerationElement();
    ~Linux_DnsQueryACLForServiceManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsQueryACLForServiceManualInstanceEnumeration {

    private:
    Linux_DnsQueryACLForServiceManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsQueryACLForServiceManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsQueryACLForServiceManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsQueryACLForServiceManualInstanceEnumeration();
    Linux_DnsQueryACLForServiceManualInstanceEnumeration(
      const Linux_DnsQueryACLForServiceManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsQueryACLForServiceManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsQueryACLForServiceManualInstance& getNext();
    int getSize() const;
    const Linux_DnsQueryACLForServiceManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsQueryACLForServiceManualInstance& anInstance);

  };

}

#endif
