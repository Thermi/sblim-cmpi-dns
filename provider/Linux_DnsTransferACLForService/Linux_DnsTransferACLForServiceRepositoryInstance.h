// =======================================================================
// Linux_DnsTransferACLForServiceRepositoryInstance.h
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
#ifndef Linux_DnsTransferACLForServiceRepositoryInstance_h
#define Linux_DnsTransferACLForServiceRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsTransferACLForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsTransferACLForServiceRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsTransferACLForServiceRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsTransferACLForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsTransferACLForServiceRepositoryInstance();
    Linux_DnsTransferACLForServiceRepositoryInstance(
      const Linux_DnsTransferACLForServiceRepositoryInstance& anInstance);
    Linux_DnsTransferACLForServiceRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsTransferACLForServiceRepositoryInstance();
       
    Linux_DnsTransferACLForServiceRepositoryInstance& operator=(
      const Linux_DnsTransferACLForServiceRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsTransferACLForServiceInstanceName& anInstanceName);        
    const Linux_DnsTransferACLForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement {

    Linux_DnsTransferACLForServiceRepositoryInstance* m_elementP;
    Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement();
    ~Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration {

    private:
    Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration();
    Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration(
      const Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsTransferACLForServiceRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsTransferACLForServiceRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsTransferACLForServiceRepositoryInstance& anInstance);

  };

}

#endif
