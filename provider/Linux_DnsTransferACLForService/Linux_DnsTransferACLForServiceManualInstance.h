// =======================================================================
// Linux_DnsTransferACLForServiceManualInstance.h
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
#ifndef Linux_DnsTransferACLForServiceManualInstance_h
#define Linux_DnsTransferACLForServiceManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsTransferACLForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsTransferACLForServiceManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsTransferACLForServiceManualInstance& anInstance);
    void reset();
       
    Linux_DnsTransferACLForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsTransferACLForServiceManualInstance();
    Linux_DnsTransferACLForServiceManualInstance(
      const Linux_DnsTransferACLForServiceManualInstance& anInstance);
    Linux_DnsTransferACLForServiceManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsTransferACLForServiceManualInstance();
       
    Linux_DnsTransferACLForServiceManualInstance& operator=(
      const Linux_DnsTransferACLForServiceManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsTransferACLForServiceInstanceName& anInstanceName);        
    const Linux_DnsTransferACLForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsTransferACLForServiceManualInstanceEnumerationElement {

    Linux_DnsTransferACLForServiceManualInstance* m_elementP;
    Linux_DnsTransferACLForServiceManualInstanceEnumerationElement* m_nextP;

    Linux_DnsTransferACLForServiceManualInstanceEnumerationElement();
    ~Linux_DnsTransferACLForServiceManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsTransferACLForServiceManualInstanceEnumeration {

    private:
    Linux_DnsTransferACLForServiceManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsTransferACLForServiceManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsTransferACLForServiceManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsTransferACLForServiceManualInstanceEnumeration();
    Linux_DnsTransferACLForServiceManualInstanceEnumeration(
      const Linux_DnsTransferACLForServiceManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsTransferACLForServiceManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsTransferACLForServiceManualInstance& getNext();
    int getSize() const;
    const Linux_DnsTransferACLForServiceManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsTransferACLForServiceManualInstance& anInstance);

  };

}

#endif
