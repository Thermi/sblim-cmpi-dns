// =======================================================================
// Linux_DnsTransferACLForServiceInstance.h
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
#ifndef Linux_DnsTransferACLForServiceInstance_h
#define Linux_DnsTransferACLForServiceInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsTransferACLForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsTransferACLForServiceInstance {
       
    private:
    void init();
    void init(const Linux_DnsTransferACLForServiceInstance& anInstance);
    void reset();
       
    Linux_DnsTransferACLForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsTransferACLForServiceInstance();
    Linux_DnsTransferACLForServiceInstance(
      const Linux_DnsTransferACLForServiceInstance& anInstance);
    Linux_DnsTransferACLForServiceInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsTransferACLForServiceInstance();
       
    Linux_DnsTransferACLForServiceInstance& operator=(
      const Linux_DnsTransferACLForServiceInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsTransferACLForServiceInstanceName& anInstanceName);        
    const Linux_DnsTransferACLForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsTransferACLForServiceInstanceEnumerationElement {

    Linux_DnsTransferACLForServiceInstance* m_elementP;
    Linux_DnsTransferACLForServiceInstanceEnumerationElement* m_nextP;

    Linux_DnsTransferACLForServiceInstanceEnumerationElement();
    ~Linux_DnsTransferACLForServiceInstanceEnumerationElement();  

  };
  

  class Linux_DnsTransferACLForServiceInstanceEnumeration {

    private:
    Linux_DnsTransferACLForServiceInstanceEnumerationElement* m_firstElementP;
    Linux_DnsTransferACLForServiceInstanceEnumerationElement* m_currentElementP;
    Linux_DnsTransferACLForServiceInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsTransferACLForServiceInstanceEnumeration();
    Linux_DnsTransferACLForServiceInstanceEnumeration(
      const Linux_DnsTransferACLForServiceInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsTransferACLForServiceInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsTransferACLForServiceInstance& getNext();
    int getSize() const;
    const Linux_DnsTransferACLForServiceInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsTransferACLForServiceInstance& anInstance);

  };

}

#endif
