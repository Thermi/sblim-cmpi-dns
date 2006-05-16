// =======================================================================
// Linux_DnsQueryACLForServiceInstance.h
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
#ifndef Linux_DnsQueryACLForServiceInstance_h
#define Linux_DnsQueryACLForServiceInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsQueryACLForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsQueryACLForServiceInstance {
       
    private:
    void init();
    void init(const Linux_DnsQueryACLForServiceInstance& anInstance);
    void reset();
       
    Linux_DnsQueryACLForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsQueryACLForServiceInstance();
    Linux_DnsQueryACLForServiceInstance(
      const Linux_DnsQueryACLForServiceInstance& anInstance);
    Linux_DnsQueryACLForServiceInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsQueryACLForServiceInstance();
       
    Linux_DnsQueryACLForServiceInstance& operator=(
      const Linux_DnsQueryACLForServiceInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsQueryACLForServiceInstanceName& anInstanceName);        
    const Linux_DnsQueryACLForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsQueryACLForServiceInstanceEnumerationElement {

    Linux_DnsQueryACLForServiceInstance* m_elementP;
    Linux_DnsQueryACLForServiceInstanceEnumerationElement* m_nextP;

    Linux_DnsQueryACLForServiceInstanceEnumerationElement();
    ~Linux_DnsQueryACLForServiceInstanceEnumerationElement();  

  };
  

  class Linux_DnsQueryACLForServiceInstanceEnumeration {

    private:
    Linux_DnsQueryACLForServiceInstanceEnumerationElement* m_firstElementP;
    Linux_DnsQueryACLForServiceInstanceEnumerationElement* m_currentElementP;
    Linux_DnsQueryACLForServiceInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsQueryACLForServiceInstanceEnumeration();
    Linux_DnsQueryACLForServiceInstanceEnumeration(
      const Linux_DnsQueryACLForServiceInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsQueryACLForServiceInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsQueryACLForServiceInstance& getNext();
    int getSize() const;
    const Linux_DnsQueryACLForServiceInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsQueryACLForServiceInstance& anInstance);

  };

}

#endif
