 /**
 * Linux_DnsAddressMatchListInstance.h
 *
 * (C) Copyright IBM Corp. 2005
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Common Public License from
 * http://www.opensource.org/licenses/cpl1.0.php
 *
 * author:     Murillo Bernardes <bernarde@br.ibm.com>
 *
 * Contributors:
 *
 */
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
  public:
       Linux_DnsAddressMatchListInstance();
  	
       Linux_DnsAddressMatchListInstance
  	    (const Linux_DnsAddressMatchListInstance& original);
  	   
       Linux_DnsAddressMatchListInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAddressMatchListInstance();
       
       Linux_DnsAddressMatchListInstance& operator=
  	    (const Linux_DnsAddressMatchListInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsAddressMatchListInstanceName& val);        
       const Linux_DnsAddressMatchListInstanceName&
        getInstanceName() const;

       unsigned int isAddressListTypeSet() const;
       void setAddressListType(const CMPIUint16 val);
       const CMPIUint16 getAddressListType() const;

       unsigned int isAddressListSet() const;
       void setAddressList(const char** val, unsigned const int size, int makeCopy = 1);
       const char** getAddressList(unsigned int& size) const;

       unsigned int isCaptionSet() const;
       void setCaption(const char* val, int makeCopy = 1);
       const char* getCaption() const;

       unsigned int isDescriptionSet() const;
       void setDescription(const char* val, int makeCopy = 1);
       const char* getDescription() const;

       unsigned int isElementNameSet() const;
       void setElementName(const char* val, int makeCopy = 1);
       const char* getElementName() const;

       unsigned int isSettingIDSet() const;
       void setSettingID(const char* val, int makeCopy = 1);
       const char* getSettingID() const;
       
  private:
       void init();
       void init(const Linux_DnsAddressMatchListInstance& original);
       void reset();
       
       Linux_DnsAddressMatchListInstanceName m_instanceName;
       CMPIUint16 m_AddressListType;
       const char** m_AddressList;
        unsigned int AddressListArraySize;
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
  };
  
  
  struct Linux_DnsAddressMatchListInstanceEnumerationElement{
  	Linux_DnsAddressMatchListInstance* m_elementP;
  	Linux_DnsAddressMatchListInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAddressMatchListInstanceEnumerationElement();
  	~Linux_DnsAddressMatchListInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAddressMatchListInstanceEnumeration {
  	private:
  	  Linux_DnsAddressMatchListInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAddressMatchListInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAddressMatchListInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAddressMatchListInstanceEnumeration();
  	  
  	  Linux_DnsAddressMatchListInstanceEnumeration(
  	   const Linux_DnsAddressMatchListInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAddressMatchListInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAddressMatchListInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAddressMatchListInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAddressMatchListInstance& elementP);
  };
}
#endif

