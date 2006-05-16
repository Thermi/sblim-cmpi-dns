// =======================================================================
// Linux_DnsAddressMatchListRepositoryInstance.h
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
#ifndef Linux_DnsAddressMatchListRepositoryInstance_h
#define Linux_DnsAddressMatchListRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAddressMatchListInstanceName.h"


namespace genProvider {

  class Linux_DnsAddressMatchListRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsAddressMatchListRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsAddressMatchListInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAddressMatchListRepositoryInstance();
    Linux_DnsAddressMatchListRepositoryInstance(
      const Linux_DnsAddressMatchListRepositoryInstance& anInstance);
    Linux_DnsAddressMatchListRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAddressMatchListRepositoryInstance();
       
    Linux_DnsAddressMatchListRepositoryInstance& operator=(
      const Linux_DnsAddressMatchListRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAddressMatchListInstanceName& anInstanceName);        
    const Linux_DnsAddressMatchListInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement {

    Linux_DnsAddressMatchListRepositoryInstance* m_elementP;
    Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement();
    ~Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsAddressMatchListRepositoryInstanceEnumeration {

    private:
    Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAddressMatchListRepositoryInstanceEnumeration();
    Linux_DnsAddressMatchListRepositoryInstanceEnumeration(
      const Linux_DnsAddressMatchListRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAddressMatchListRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAddressMatchListRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsAddressMatchListRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAddressMatchListRepositoryInstance& anInstance);

  };

}

#endif
