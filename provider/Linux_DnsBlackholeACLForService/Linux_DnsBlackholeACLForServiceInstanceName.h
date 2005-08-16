 /**
 * Linux_DnsBlackholeACLForServiceInstanceName.h
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
#ifndef Linux_DnsBlackholeACLForServiceInstanceName_h
#define Linux_DnsBlackholeACLForServiceInstanceName_h

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

  class Linux_DnsBlackholeACLForServiceInstanceName {
  public:
       Linux_DnsBlackholeACLForServiceInstanceName();
  	
       Linux_DnsBlackholeACLForServiceInstanceName
  	    (const Linux_DnsBlackholeACLForServiceInstanceName& original);
  	   
       Linux_DnsBlackholeACLForServiceInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsBlackholeACLForServiceInstanceName();
       
       Linux_DnsBlackholeACLForServiceInstanceName& operator=
  	    (const Linux_DnsBlackholeACLForServiceInstanceName& original);
       
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
       void init(const Linux_DnsBlackholeACLForServiceInstanceName& original);
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
  
  
  struct Linux_DnsBlackholeACLForServiceInstanceNameEnumerationElement{
  	Linux_DnsBlackholeACLForServiceInstanceName* m_elementP;
  	Linux_DnsBlackholeACLForServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsBlackholeACLForServiceInstanceNameEnumerationElement();
  	~Linux_DnsBlackholeACLForServiceInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsBlackholeACLForServiceInstanceNameEnumeration {
  	private:
  	  Linux_DnsBlackholeACLForServiceInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsBlackholeACLForServiceInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsBlackholeACLForServiceInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsBlackholeACLForServiceInstanceNameEnumeration();
  	  
  	  Linux_DnsBlackholeACLForServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsBlackholeACLForServiceInstanceNameEnumeration(
  	   const Linux_DnsBlackholeACLForServiceInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsBlackholeACLForServiceInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsBlackholeACLForServiceInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsBlackholeACLForServiceInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsBlackholeACLForServiceInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

