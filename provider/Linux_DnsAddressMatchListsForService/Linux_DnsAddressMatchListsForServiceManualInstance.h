// =======================================================================
// Linux_DnsAddressMatchListsForServiceManualInstance.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
// 
// Copyright (c) 2006, 2009, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Eclipse Public License from
// http://www.opensource.org/licenses/eclipse-1.0.php
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
#ifndef Linux_DnsAddressMatchListsForServiceManualInstance_h
#define Linux_DnsAddressMatchListsForServiceManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAddressMatchListsForServiceInstanceName.h"


namespace genProvider {

  class Linux_DnsAddressMatchListsForServiceManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsAddressMatchListsForServiceManualInstance& anInstance);
    void reset();
       
    Linux_DnsAddressMatchListsForServiceInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAddressMatchListsForServiceManualInstance();
    Linux_DnsAddressMatchListsForServiceManualInstance(
      const Linux_DnsAddressMatchListsForServiceManualInstance& anInstance);
    Linux_DnsAddressMatchListsForServiceManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAddressMatchListsForServiceManualInstance();
       
    Linux_DnsAddressMatchListsForServiceManualInstance& operator=(
      const Linux_DnsAddressMatchListsForServiceManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAddressMatchListsForServiceInstanceName& anInstanceName);        
    const Linux_DnsAddressMatchListsForServiceInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAddressMatchListsForServiceManualInstanceEnumerationElement {

    Linux_DnsAddressMatchListsForServiceManualInstance* m_elementP;
    Linux_DnsAddressMatchListsForServiceManualInstanceEnumerationElement* m_nextP;

    Linux_DnsAddressMatchListsForServiceManualInstanceEnumerationElement();
    ~Linux_DnsAddressMatchListsForServiceManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsAddressMatchListsForServiceManualInstanceEnumeration {

    private:
    Linux_DnsAddressMatchListsForServiceManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAddressMatchListsForServiceManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAddressMatchListsForServiceManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAddressMatchListsForServiceManualInstanceEnumeration();
    Linux_DnsAddressMatchListsForServiceManualInstanceEnumeration(
      const Linux_DnsAddressMatchListsForServiceManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAddressMatchListsForServiceManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAddressMatchListsForServiceManualInstance& getNext();
    int getSize() const;
    const Linux_DnsAddressMatchListsForServiceManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAddressMatchListsForServiceManualInstance& anInstance);

  };

}

#endif
