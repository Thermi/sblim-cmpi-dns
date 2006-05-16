// =======================================================================
// Linux_DnsRecursionACLForServiceRepositoryInstance.h
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
#ifndef Linux_DnsRecursionACLForServiceRepositoryInstance_h
#define Linux_DnsRecursionACLForServiceRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsRecursionACLForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsRecursionACLForServiceRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsRecursionACLForServiceRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsRecursionACLForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsRecursionACLForServiceRepositoryInstance();
    Linux_DnsRecursionACLForServiceRepositoryInstance(
      const Linux_DnsRecursionACLForServiceRepositoryInstance& anInstance);
    Linux_DnsRecursionACLForServiceRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsRecursionACLForServiceRepositoryInstance();
       
    Linux_DnsRecursionACLForServiceRepositoryInstance& operator=(
      const Linux_DnsRecursionACLForServiceRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsRecursionACLForServiceInstanceName& anInstanceName);        
    const Linux_DnsRecursionACLForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement {

    Linux_DnsRecursionACLForServiceRepositoryInstance* m_elementP;
    Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement();
    ~Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration {

    private:
    Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration();
    Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration(
      const Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsRecursionACLForServiceRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsRecursionACLForServiceRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsRecursionACLForServiceRepositoryInstance& anInstance);

  };

}

#endif
