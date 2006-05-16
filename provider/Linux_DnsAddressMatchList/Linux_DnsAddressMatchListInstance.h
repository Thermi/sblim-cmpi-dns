// =======================================================================
// Linux_DnsAddressMatchListInstance.h
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
    CMPIUint16 m_AddressListType;
    const char** m_AddressList;
    unsigned int m_AddressListSize;
    const char* m_Caption;
    const char* m_Description;
    const char* m_ElementName;
    const char* m_SettingID;
       
    struct isSetType{
      unsigned int instanceName:1;
      unsigned int AddressListType:1;
      unsigned int AddressList:1;
      unsigned int Caption:1;
      unsigned int Description:1;
      unsigned int ElementName:1;
      unsigned int SettingID:1;

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

    unsigned int isAddressListTypeSet() const;
    void setAddressListType(const CMPIUint16 aValue);
    const CMPIUint16 getAddressListType() const;

    unsigned int isAddressListSet() const;
    void setAddressList(const char** aValue, unsigned const int aSize, int aCopyFlag = 1);
    const char** getAddressList(unsigned int& aSize) const;

    unsigned int isCaptionSet() const;
    void setCaption(const char* aValue, int aCopyFlag = 1);
    const char* getCaption() const;

    unsigned int isDescriptionSet() const;
    void setDescription(const char* aValue, int aCopyFlag = 1);
    const char* getDescription() const;

    unsigned int isElementNameSet() const;
    void setElementName(const char* aValue, int aCopyFlag = 1);
    const char* getElementName() const;

    unsigned int isSettingIDSet() const;
    void setSettingID(const char* aValue, int aCopyFlag = 1);
    const char* getSettingID() const;


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
