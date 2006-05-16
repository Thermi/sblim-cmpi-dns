// =======================================================================
// Linux_DnsAddressMatchListOfServiceRepositoryInstance.h
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
#ifndef Linux_DnsAddressMatchListOfServiceRepositoryInstance_h
#define Linux_DnsAddressMatchListOfServiceRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAddressMatchListOfServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAddressMatchListOfServiceRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsAddressMatchListOfServiceRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsAddressMatchListOfServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAddressMatchListOfServiceRepositoryInstance();
    Linux_DnsAddressMatchListOfServiceRepositoryInstance(
      const Linux_DnsAddressMatchListOfServiceRepositoryInstance& anInstance);
    Linux_DnsAddressMatchListOfServiceRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAddressMatchListOfServiceRepositoryInstance();
       
    Linux_DnsAddressMatchListOfServiceRepositoryInstance& operator=(
      const Linux_DnsAddressMatchListOfServiceRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAddressMatchListOfServiceInstanceName& anInstanceName);        
    const Linux_DnsAddressMatchListOfServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement {

    Linux_DnsAddressMatchListOfServiceRepositoryInstance* m_elementP;
    Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement();
    ~Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration {

    private:
    Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration();
    Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration(
      const Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAddressMatchListOfServiceRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsAddressMatchListOfServiceRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAddressMatchListOfServiceRepositoryInstance& anInstance);

  };

}

#endif
