// =======================================================================
// Linux_DnsAddressMatchListInstance.h
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
#ifndef Linux_DnsAddressMatchListInstance_h
#define Linux_DnsAddressMatchListInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAddressMatchListInstanceName.h"


namespace genProvider {

  class Linux_DnsAddressMatchListInstance {
       
    private:
    void init();
    void init(const Linux_DnsAddressMatchListInstance& anInstance);
    void reset();
       
    Linux_DnsAddressMatchListInstanceName m_instanceName;
    const CMPIUint8* m_AddressMatchListElementType;
    unsigned int m_AddressMatchListElementTypeSize;
    const char** m_AddressMatchListElement;
    unsigned int m_AddressMatchListElementSize;
    const char* m_Caption;
    const char* m_Description;
    const char* m_ElementName;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int AddressMatchListElementType:1;
      unsigned int AddressMatchListElement:1;
      unsigned int Caption:1;
      unsigned int Description:1;
      unsigned int ElementName:1;

    } isSet;
    
    public:
    Linux_DnsAddressMatchListInstance();
    Linux_DnsAddressMatchListInstance(
      const Linux_DnsAddressMatchListInstance& anInstance);
    Linux_DnsAddressMatchListInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAddressMatchListInstance();
       
    Linux_DnsAddressMatchListInstance& operator=(
      const Linux_DnsAddressMatchListInstance& anInstance);
       
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

    unsigned int isCaptionSet() const;
    void setCaption(const char* aValue, int aCopyFlag = 1);
    const char* getCaption() const;

    unsigned int isDescriptionSet() const;
    void setDescription(const char* aValue, int aCopyFlag = 1);
    const char* getDescription() const;

    unsigned int isElementNameSet() const;
    void setElementName(const char* aValue, int aCopyFlag = 1);
    const char* getElementName() const;


  };
  
  struct Linux_DnsAddressMatchListInstanceEnumerationElement {

    Linux_DnsAddressMatchListInstance* m_elementP;
    Linux_DnsAddressMatchListInstanceEnumerationElement* m_nextP;

    Linux_DnsAddressMatchListInstanceEnumerationElement();
    ~Linux_DnsAddressMatchListInstanceEnumerationElement();  

  };
  

  class Linux_DnsAddressMatchListInstanceEnumeration {

    private:
    Linux_DnsAddressMatchListInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAddressMatchListInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAddressMatchListInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAddressMatchListInstanceEnumeration();
    Linux_DnsAddressMatchListInstanceEnumeration(
      const Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAddressMatchListInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAddressMatchListInstance& getNext();
    int getSize() const;
    const Linux_DnsAddressMatchListInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAddressMatchListInstance& anInstance);

  };

}

#endif
