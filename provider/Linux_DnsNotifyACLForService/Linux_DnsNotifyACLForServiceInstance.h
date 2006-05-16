// =======================================================================
// Linux_DnsNotifyACLForServiceInstance.h
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
#ifndef Linux_DnsNotifyACLForServiceInstance_h
#define Linux_DnsNotifyACLForServiceInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsNotifyACLForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsNotifyACLForServiceInstance {
       
    private:
    void init();
    void init(const Linux_DnsNotifyACLForServiceInstance& anInstance);
    void reset();
       
    Linux_DnsNotifyACLForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsNotifyACLForServiceInstance();
    Linux_DnsNotifyACLForServiceInstance(
      const Linux_DnsNotifyACLForServiceInstance& anInstance);
    Linux_DnsNotifyACLForServiceInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsNotifyACLForServiceInstance();
       
    Linux_DnsNotifyACLForServiceInstance& operator=(
      const Linux_DnsNotifyACLForServiceInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsNotifyACLForServiceInstanceName& anInstanceName);        
    const Linux_DnsNotifyACLForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsNotifyACLForServiceInstanceEnumerationElement {

    Linux_DnsNotifyACLForServiceInstance* m_elementP;
    Linux_DnsNotifyACLForServiceInstanceEnumerationElement* m_nextP;

    Linux_DnsNotifyACLForServiceInstanceEnumerationElement();
    ~Linux_DnsNotifyACLForServiceInstanceEnumerationElement();  

  };
  

  class Linux_DnsNotifyACLForServiceInstanceEnumeration {

    private:
    Linux_DnsNotifyACLForServiceInstanceEnumerationElement* m_firstElementP;
    Linux_DnsNotifyACLForServiceInstanceEnumerationElement* m_currentElementP;
    Linux_DnsNotifyACLForServiceInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsNotifyACLForServiceInstanceEnumeration();
    Linux_DnsNotifyACLForServiceInstanceEnumeration(
      const Linux_DnsNotifyACLForServiceInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsNotifyACLForServiceInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsNotifyACLForServiceInstance& getNext();
    int getSize() const;
    const Linux_DnsNotifyACLForServiceInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsNotifyACLForServiceInstance& anInstance);

  };

}

#endif
