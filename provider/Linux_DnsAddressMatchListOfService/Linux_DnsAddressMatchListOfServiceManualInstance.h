// =======================================================================
// Linux_DnsAddressMatchListOfServiceManualInstance.h
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
#ifndef Linux_DnsAddressMatchListOfServiceManualInstance_h
#define Linux_DnsAddressMatchListOfServiceManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAddressMatchListOfServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAddressMatchListOfServiceManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsAddressMatchListOfServiceManualInstance& anInstance);
    void reset();
       
    Linux_DnsAddressMatchListOfServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAddressMatchListOfServiceManualInstance();
    Linux_DnsAddressMatchListOfServiceManualInstance(
      const Linux_DnsAddressMatchListOfServiceManualInstance& anInstance);
    Linux_DnsAddressMatchListOfServiceManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAddressMatchListOfServiceManualInstance();
       
    Linux_DnsAddressMatchListOfServiceManualInstance& operator=(
      const Linux_DnsAddressMatchListOfServiceManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAddressMatchListOfServiceInstanceName& anInstanceName);        
    const Linux_DnsAddressMatchListOfServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement {

    Linux_DnsAddressMatchListOfServiceManualInstance* m_elementP;
    Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement* m_nextP;

    Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement();
    ~Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration {

    private:
    Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration();
    Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration(
      const Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAddressMatchListOfServiceManualInstance& getNext();
    int getSize() const;
    const Linux_DnsAddressMatchListOfServiceManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAddressMatchListOfServiceManualInstance& anInstance);

  };

}

#endif
