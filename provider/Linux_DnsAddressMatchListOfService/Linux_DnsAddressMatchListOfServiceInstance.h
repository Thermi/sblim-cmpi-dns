// =======================================================================
// Linux_DnsAddressMatchListOfServiceInstance.h
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
#ifndef Linux_DnsAddressMatchListOfServiceInstance_h
#define Linux_DnsAddressMatchListOfServiceInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAddressMatchListOfServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAddressMatchListOfServiceInstance {
       
    private:
    void init();
    void init(const Linux_DnsAddressMatchListOfServiceInstance& anInstance);
    void reset();
       
    Linux_DnsAddressMatchListOfServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAddressMatchListOfServiceInstance();
    Linux_DnsAddressMatchListOfServiceInstance(
      const Linux_DnsAddressMatchListOfServiceInstance& anInstance);
    Linux_DnsAddressMatchListOfServiceInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAddressMatchListOfServiceInstance();
       
    Linux_DnsAddressMatchListOfServiceInstance& operator=(
      const Linux_DnsAddressMatchListOfServiceInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAddressMatchListOfServiceInstanceName& anInstanceName);        
    const Linux_DnsAddressMatchListOfServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAddressMatchListOfServiceInstanceEnumerationElement {

    Linux_DnsAddressMatchListOfServiceInstance* m_elementP;
    Linux_DnsAddressMatchListOfServiceInstanceEnumerationElement* m_nextP;

    Linux_DnsAddressMatchListOfServiceInstanceEnumerationElement();
    ~Linux_DnsAddressMatchListOfServiceInstanceEnumerationElement();  

  };
  

  class Linux_DnsAddressMatchListOfServiceInstanceEnumeration {

    private:
    Linux_DnsAddressMatchListOfServiceInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAddressMatchListOfServiceInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAddressMatchListOfServiceInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAddressMatchListOfServiceInstanceEnumeration();
    Linux_DnsAddressMatchListOfServiceInstanceEnumeration(
      const Linux_DnsAddressMatchListOfServiceInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAddressMatchListOfServiceInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAddressMatchListOfServiceInstance& getNext();
    int getSize() const;
    const Linux_DnsAddressMatchListOfServiceInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAddressMatchListOfServiceInstance& anInstance);

  };

}

#endif
