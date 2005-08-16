 /**
 * Linux_DnsAddressMatchListInstanceName.h
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
#ifndef Linux_DnsAddressMatchListInstanceName_h
#define Linux_DnsAddressMatchListInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"

namespace genProvider {

  class Linux_DnsAddressMatchListInstanceName {
  public:
       Linux_DnsAddressMatchListInstanceName();
  	
       Linux_DnsAddressMatchListInstanceName
  	    (const Linux_DnsAddressMatchListInstanceName& original);
  	   
       Linux_DnsAddressMatchListInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsAddressMatchListInstanceName();
       
       Linux_DnsAddressMatchListInstanceName& operator=
  	    (const Linux_DnsAddressMatchListInstanceName& original);
       
       CmpiObjectPath getObjectPath() const;
       
       void fillKeys(CmpiInstance& cmpiInstance) const;
       
       unsigned int isNameSpaceSet() const;
       void setNamespace(const char * val, int makeCopy = 1);
       const char * getNamespace() const;

       unsigned int isNameSet() const;
       void setName(const char* val, int makeCopy = 1);
       const char* getName() const;

       unsigned int isServiceNameSet() const;
       void setServiceName(const char* val, int makeCopy = 1);
       const char* getServiceName() const;
       
  private:
       void init();
       void init(const Linux_DnsAddressMatchListInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       const char* m_Name;
       const char* m_ServiceName;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int Name:1;
         unsigned int ServiceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsAddressMatchListInstanceNameEnumerationElement{
  	Linux_DnsAddressMatchListInstanceName* m_elementP;
  	Linux_DnsAddressMatchListInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsAddressMatchListInstanceNameEnumerationElement();
  	~Linux_DnsAddressMatchListInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsAddressMatchListInstanceNameEnumeration {
  	private:
  	  Linux_DnsAddressMatchListInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsAddressMatchListInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsAddressMatchListInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAddressMatchListInstanceNameEnumeration();
  	  
  	  Linux_DnsAddressMatchListInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsAddressMatchListInstanceNameEnumeration(
  	   const Linux_DnsAddressMatchListInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsAddressMatchListInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAddressMatchListInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAddressMatchListInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsAddressMatchListInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

