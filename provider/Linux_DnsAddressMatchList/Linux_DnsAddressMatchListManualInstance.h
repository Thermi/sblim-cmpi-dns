// =======================================================================
// Linux_DnsAddressMatchListManualInstance.h
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
#ifndef Linux_DnsAddressMatchListManualInstance_h
#define Linux_DnsAddressMatchListManualInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAddressMatchListInstanceName.h"


namespace genProvider {

  class Linux_DnsAddressMatchListManualInstance {
       
    private:
    void init();
    void init(const Linux_DnsAddressMatchListManualInstance& anInstance);
    void reset();
       
    Linux_DnsAddressMatchListInstanceName m_instanceName;
    const CMPIUint8* m_AddressMatchListElementType;
    unsigned int m_AddressMatchListElementTypeSize;
    const char** m_AddressMatchListElement;
    unsigned int m_AddressMatchListElementSize;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int AddressMatchListElementType:1;
      unsigned int AddressMatchListElement:1;

    } isSet;
    
    public:
    Linux_DnsAddressMatchListManualInstance();
    Linux_DnsAddressMatchListManualInstance(
      const Linux_DnsAddressMatchListManualInstance& anInstance);
    Linux_DnsAddressMatchListManualInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAddressMatchListManualInstance();
       
    Linux_DnsAddressMatchListManualInstance& operator=(
      const Linux_DnsAddressMatchListManualInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAddressMatchListInstanceName& anInstanceName);        
    const Linux_DnsAddressMatchListInstanceName& getInstanceName() const;

    unsigned int isAddressMatchListElementTypeSet() const;
    void setAddressMatchListElementType(const CMPIUint8* aValue, unsigned const int aSize, int aCopyFlag = 1);
    const CMPIUint8* getAddressMatchListElementType(unsigned int& aSize) const;

    unsigned int isAddressMatchListElementSet() const;
    void setAddressMatchListElement(const char** aValue, unsigned const int aSize, int aCopyFlag = 1);
    const char** getAddressMatchListElement(unsigned int& aSize) const;


  };
  
  struct Linux_DnsAddressMatchListManualInstanceEnumerationElement {

    Linux_DnsAddressMatchListManualInstance* m_elementP;
    Linux_DnsAddressMatchListManualInstanceEnumerationElement* m_nextP;

    Linux_DnsAddressMatchListManualInstanceEnumerationElement();
    ~Linux_DnsAddressMatchListManualInstanceEnumerationElement();  

  };
  

  class Linux_DnsAddressMatchListManualInstanceEnumeration {

    private:
    Linux_DnsAddressMatchListManualInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAddressMatchListManualInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAddressMatchListManualInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAddressMatchListManualInstanceEnumeration();
    Linux_DnsAddressMatchListManualInstanceEnumeration(
      const Linux_DnsAddressMatchListManualInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAddressMatchListManualInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAddressMatchListManualInstance& getNext();
    int getSize() const;
    const Linux_DnsAddressMatchListManualInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAddressMatchListManualInstance& anInstance);

  };

}

#endif
