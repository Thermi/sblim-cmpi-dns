 /**
 * Linux_DnsAddressMatchListManualInstance.h
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
  public:
       Linux_DnsAddressMatchListManualInstance();
  	
       Linux_DnsAddressMatchListManualInstance
  	    (const Linux_DnsAddressMatchListManualInstance& original);
  	   
       Linux_DnsAddressMatchListManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAddressMatchListManualInstance();
       
       Linux_DnsAddressMatchListManualInstance& operator=
  	    (const Linux_DnsAddressMatchListManualInstance& original);
       
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
       
  private:
       void init();
       void init(const Linux_DnsAddressMatchListManualInstance& original);
       void reset();
       
       Linux_DnsAddressMatchListInstanceName m_instanceName;
       CMPIUint16 m_AddressListType;
       const char** m_AddressList;
        unsigned int AddressListArraySize;
       
       struct isSetType{
       	 unsigned int instanceName:1;
         unsigned int AddressListType:1;
         unsigned int AddressList:1;
       } isSet;
  };
  
  
  struct Linux_DnsAddressMatchListManualInstanceEnumerationElement{
  	Linux_DnsAddressMatchListManualInstance* m_elementP;
  	Linux_DnsAddressMatchListManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAddressMatchListManualInstanceEnumerationElement();
  	~Linux_DnsAddressMatchListManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAddressMatchListManualInstanceEnumeration {
  	private:
  	  Linux_DnsAddressMatchListManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAddressMatchListManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAddressMatchListManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAddressMatchListManualInstanceEnumeration();
  	  
  	  Linux_DnsAddressMatchListManualInstanceEnumeration(
  	   const Linux_DnsAddressMatchListManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAddressMatchListManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAddressMatchListManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAddressMatchListManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAddressMatchListManualInstance& elementP);
  };
}
#endif

