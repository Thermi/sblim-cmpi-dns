 /**
 * Linux_DnsQueryACLForServiceInstanceName.h
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
#ifndef Linux_DnsQueryACLForServiceInstanceName_h
#define Linux_DnsQueryACLForServiceInstanceName_h

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

  class Linux_DnsQueryACLForServiceInstanceName {
  public:
       Linux_DnsQueryACLForServiceInstanceName();
  	
       Linux_DnsQueryACLForServiceInstanceName
  	    (const Linux_DnsQueryACLForServiceInstanceName& original);
  	   
       Linux_DnsQueryACLForServiceInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsQueryACLForServiceInstanceName();
       
       Linux_DnsQueryACLForServiceInstanceName& operator=
  	    (const Linux_DnsQueryACLForServiceInstanceName& original);
       
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
       void init(const Linux_DnsQueryACLForServiceInstanceName& original);
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
  
  
  struct Linux_DnsQueryACLForServiceInstanceNameEnumerationElement{
  	Linux_DnsQueryACLForServiceInstanceName* m_elementP;
  	Linux_DnsQueryACLForServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsQueryACLForServiceInstanceNameEnumerationElement();
  	~Linux_DnsQueryACLForServiceInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsQueryACLForServiceInstanceNameEnumeration {
  	private:
  	  Linux_DnsQueryACLForServiceInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsQueryACLForServiceInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsQueryACLForServiceInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsQueryACLForServiceInstanceNameEnumeration();
  	  
  	  Linux_DnsQueryACLForServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsQueryACLForServiceInstanceNameEnumeration(
  	   const Linux_DnsQueryACLForServiceInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsQueryACLForServiceInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsQueryACLForServiceInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsQueryACLForServiceInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsQueryACLForServiceInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

