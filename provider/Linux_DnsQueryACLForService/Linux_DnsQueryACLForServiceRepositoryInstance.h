// =======================================================================
// Linux_DnsQueryACLForServiceRepositoryInstance.h
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
#ifndef Linux_DnsQueryACLForServiceRepositoryInstance_h
#define Linux_DnsQueryACLForServiceRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsQueryACLForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsQueryACLForServiceRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsQueryACLForServiceRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsQueryACLForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsQueryACLForServiceRepositoryInstance();
    Linux_DnsQueryACLForServiceRepositoryInstance(
      const Linux_DnsQueryACLForServiceRepositoryInstance& anInstance);
    Linux_DnsQueryACLForServiceRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsQueryACLForServiceRepositoryInstance();
       
    Linux_DnsQueryACLForServiceRepositoryInstance& operator=(
      const Linux_DnsQueryACLForServiceRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsQueryACLForServiceInstanceName& anInstanceName);        
    const Linux_DnsQueryACLForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement {

    Linux_DnsQueryACLForServiceRepositoryInstance* m_elementP;
    Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement();
    ~Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration {

    private:
    Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration();
    Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration(
      const Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsQueryACLForServiceRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsQueryACLForServiceRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsQueryACLForServiceRepositoryInstance& anInstance);

  };

}

#endif
