// =======================================================================
// Linux_DnsNotifyACLForServiceRepositoryInstance.h
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
#ifndef Linux_DnsNotifyACLForServiceRepositoryInstance_h
#define Linux_DnsNotifyACLForServiceRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsNotifyACLForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsNotifyACLForServiceRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsNotifyACLForServiceRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsNotifyACLForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsNotifyACLForServiceRepositoryInstance();
    Linux_DnsNotifyACLForServiceRepositoryInstance(
      const Linux_DnsNotifyACLForServiceRepositoryInstance& anInstance);
    Linux_DnsNotifyACLForServiceRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsNotifyACLForServiceRepositoryInstance();
       
    Linux_DnsNotifyACLForServiceRepositoryInstance& operator=(
      const Linux_DnsNotifyACLForServiceRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsNotifyACLForServiceInstanceName& anInstanceName);        
    const Linux_DnsNotifyACLForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement {

    Linux_DnsNotifyACLForServiceRepositoryInstance* m_elementP;
    Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement();
    ~Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration {

    private:
    Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration();
    Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration(
      const Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsNotifyACLForServiceRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsNotifyACLForServiceRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsNotifyACLForServiceRepositoryInstance& anInstance);

  };

}

#endif
