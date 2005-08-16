 /**
 * Linux_DnsRecursionACLForServiceInstanceName.h
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
#ifndef Linux_DnsRecursionACLForServiceInstanceName_h
#define Linux_DnsRecursionACLForServiceInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsServiceInstanceName.h"
#include "Linux_DnsAddressMatchListInstanceName.h"

namespace genProvider {

  class Linux_DnsRecursionACLForServiceInstanceName {
  public:
       Linux_DnsRecursionACLForServiceInstanceName();
  	
       Linux_DnsRecursionACLForServiceInstanceName
  	    (const Linux_DnsRecursionACLForServiceInstanceName& original);
  	   
       Linux_DnsRecursionACLForServiceInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsRecursionACLForServiceInstanceName();
       
       Linux_DnsRecursionACLForServiceInstanceName& operator=
  	    (const Linux_DnsRecursionACLForServiceInstanceName& original);
       
       CmpiObjectPath getObjectPath() const;
       
       void fillKeys(CmpiInstance& cmpiInstance) const;
       
       unsigned int isNameSpaceSet() const;
       void setNamespace(const char * val, int makeCopy = 1);
       const char * getNamespace() const;

       unsigned int isElementSet() const;
       void setElement(const Linux_DnsServiceInstanceName& val);
       const Linux_DnsServiceInstanceName& getElement() const;

       unsigned int isSettingSet() const;
       void setSetting(const Linux_DnsAddressMatchListInstanceName& val);
       const Linux_DnsAddressMatchListInstanceName& getSetting() const;
       
  private:
       void init();
       void init(const Linux_DnsRecursionACLForServiceInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       Linux_DnsServiceInstanceName m_Element;
       Linux_DnsAddressMatchListInstanceName m_Setting;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int Element:1;
         unsigned int Setting:1;
       } isSet;
  };
  
  
  struct Linux_DnsRecursionACLForServiceInstanceNameEnumerationElement{
  	Linux_DnsRecursionACLForServiceInstanceName* m_elementP;
  	Linux_DnsRecursionACLForServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsRecursionACLForServiceInstanceNameEnumerationElement();
  	~Linux_DnsRecursionACLForServiceInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsRecursionACLForServiceInstanceNameEnumeration {
  	private:
  	  Linux_DnsRecursionACLForServiceInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsRecursionACLForServiceInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsRecursionACLForServiceInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsRecursionACLForServiceInstanceNameEnumeration();
  	  
  	  Linux_DnsRecursionACLForServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsRecursionACLForServiceInstanceNameEnumeration(
  	   const Linux_DnsRecursionACLForServiceInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsRecursionACLForServiceInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsRecursionACLForServiceInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsRecursionACLForServiceInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsRecursionACLForServiceInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

