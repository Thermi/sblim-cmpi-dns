// =======================================================================
// Linux_DnsAddressMatchListsForServiceInstance.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
// 
// Copyright (c) 2006, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Common Public License from
// http://www.opensource.org/licenses/cpl1.0.txt
//
// Author:        generated
//
// Contributors:
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsAddressMatchListsForServiceInstance_h
#define Linux_DnsAddressMatchListsForServiceInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAddressMatchListsForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAddressMatchListsForServiceInstance {
       
    private:
    void init();
    void init(const Linux_DnsAddressMatchListsForServiceInstance& anInstance);
    void reset();
       
    Linux_DnsAddressMatchListsForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAddressMatchListsForServiceInstance();
    Linux_DnsAddressMatchListsForServiceInstance(
      const Linux_DnsAddressMatchListsForServiceInstance& anInstance);
    Linux_DnsAddressMatchListsForServiceInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAddressMatchListsForServiceInstance();
       
    Linux_DnsAddressMatchListsForServiceInstance& operator=(
      const Linux_DnsAddressMatchListsForServiceInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAddressMatchListsForServiceInstanceName& anInstanceName);        
    const Linux_DnsAddressMatchListsForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAddressMatchListsForServiceInstanceEnumerationElement {

    Linux_DnsAddressMatchListsForServiceInstance* m_elementP;
    Linux_DnsAddressMatchListsForServiceInstanceEnumerationElement* m_nextP;

    Linux_DnsAddressMatchListsForServiceInstanceEnumerationElement();
    ~Linux_DnsAddressMatchListsForServiceInstanceEnumerationElement();  

  };
  

  class Linux_DnsAddressMatchListsForServiceInstanceEnumeration {

    private:
    Linux_DnsAddressMatchListsForServiceInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAddressMatchListsForServiceInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAddressMatchListsForServiceInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAddressMatchListsForServiceInstanceEnumeration();
    Linux_DnsAddressMatchListsForServiceInstanceEnumeration(
      const Linux_DnsAddressMatchListsForServiceInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAddressMatchListsForServiceInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAddressMatchListsForServiceInstance& getNext();
    int getSize() const;
    const Linux_DnsAddressMatchListsForServiceInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAddressMatchListsForServiceInstance& anInstance);

  };

}

#endif
