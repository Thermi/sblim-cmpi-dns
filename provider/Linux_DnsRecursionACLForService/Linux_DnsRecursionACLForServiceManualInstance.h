// =======================================================================
// Linux_DnsRecursionACLForServiceManualInstance.h
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
#ifndef Linux_DnsRecursionACLForServiceManualInstance_h
#define Linux_DnsRecursionACLForServiceManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsRecursionACLForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsRecursionACLForServiceManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsRecursionACLForServiceManualInstance& anInstance);
    void reset();
       
    Linux_DnsRecursionACLForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsRecursionACLForServiceManualInstance();
    Linux_DnsRecursionACLForServiceManualInstance(
      const Linux_DnsRecursionACLForServiceManualInstance& anInstance);
    Linux_DnsRecursionACLForServiceManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsRecursionACLForServiceManualInstance();
       
    Linux_DnsRecursionACLForServiceManualInstance& operator=(
      const Linux_DnsRecursionACLForServiceManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsRecursionACLForServiceInstanceName& anInstanceName);        
    const Linux_DnsRecursionACLForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement {

    Linux_DnsRecursionACLForServiceManualInstance* m_elementP;
    Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement* m_nextP;

    Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement();
    ~Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsRecursionACLForServiceManualInstanceEnumeration {

    private:
    Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsRecursionACLForServiceManualInstanceEnumeration();
    Linux_DnsRecursionACLForServiceManualInstanceEnumeration(
      const Linux_DnsRecursionACLForServiceManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsRecursionACLForServiceManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsRecursionACLForServiceManualInstance& getNext();
    int getSize() const;
    const Linux_DnsRecursionACLForServiceManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsRecursionACLForServiceManualInstance& anInstance);

  };

}

#endif
