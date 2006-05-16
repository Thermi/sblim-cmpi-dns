// =======================================================================
// Linux_DnsRecursionACLForServiceInstance.h
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
#ifndef Linux_DnsRecursionACLForServiceInstance_h
#define Linux_DnsRecursionACLForServiceInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsRecursionACLForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsRecursionACLForServiceInstance {
       
    private:
    void init();
    void init(const Linux_DnsRecursionACLForServiceInstance& anInstance);
    void reset();
       
    Linux_DnsRecursionACLForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsRecursionACLForServiceInstance();
    Linux_DnsRecursionACLForServiceInstance(
      const Linux_DnsRecursionACLForServiceInstance& anInstance);
    Linux_DnsRecursionACLForServiceInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsRecursionACLForServiceInstance();
       
    Linux_DnsRecursionACLForServiceInstance& operator=(
      const Linux_DnsRecursionACLForServiceInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsRecursionACLForServiceInstanceName& anInstanceName);        
    const Linux_DnsRecursionACLForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsRecursionACLForServiceInstanceEnumerationElement {

    Linux_DnsRecursionACLForServiceInstance* m_elementP;
    Linux_DnsRecursionACLForServiceInstanceEnumerationElement* m_nextP;

    Linux_DnsRecursionACLForServiceInstanceEnumerationElement();
    ~Linux_DnsRecursionACLForServiceInstanceEnumerationElement();  

  };
  

  class Linux_DnsRecursionACLForServiceInstanceEnumeration {

    private:
    Linux_DnsRecursionACLForServiceInstanceEnumerationElement* m_firstElementP;
    Linux_DnsRecursionACLForServiceInstanceEnumerationElement* m_currentElementP;
    Linux_DnsRecursionACLForServiceInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsRecursionACLForServiceInstanceEnumeration();
    Linux_DnsRecursionACLForServiceInstanceEnumeration(
      const Linux_DnsRecursionACLForServiceInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsRecursionACLForServiceInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsRecursionACLForServiceInstance& getNext();
    int getSize() const;
    const Linux_DnsRecursionACLForServiceInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsRecursionACLForServiceInstance& anInstance);

  };

}

#endif
