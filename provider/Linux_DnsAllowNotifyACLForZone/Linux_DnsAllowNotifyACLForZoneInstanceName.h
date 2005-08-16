 /**
 * Linux_DnsAllowNotifyACLForZoneInstanceName.h
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
#ifndef Linux_DnsAllowNotifyACLForZoneInstanceName_h
#define Linux_DnsAllowNotifyACLForZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsZoneInstanceName.h"
#include "Linux_DnsAddressMatchListInstanceName.h"

namespace genProvider {

  class Linux_DnsAllowNotifyACLForZoneInstanceName {
  public:
       Linux_DnsAllowNotifyACLForZoneInstanceName();
  	
       Linux_DnsAllowNotifyACLForZoneInstanceName
  	    (const Linux_DnsAllowNotifyACLForZoneInstanceName& original);
  	   
       Linux_DnsAllowNotifyACLForZoneInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsAllowNotifyACLForZoneInstanceName();
       
       Linux_DnsAllowNotifyACLForZoneInstanceName& operator=
  	    (const Linux_DnsAllowNotifyACLForZoneInstanceName& original);
       
       CmpiObjectPath getObjectPath() const;
       
       void fillKeys(CmpiInstance& cmpiInstance) const;
       
       unsigned int isNameSpaceSet() const;
       void setNamespace(const char * val, int makeCopy = 1);
       const char * getNamespace() const;

       unsigned int isElementSet() const;
       void setElement(const Linux_DnsZoneInstanceName& val);
       const Linux_DnsZoneInstanceName& getElement() const;

       unsigned int isSettingSet() const;
       void setSetting(const Linux_DnsAddressMatchListInstanceName& val);
       const Linux_DnsAddressMatchListInstanceName& getSetting() const;
       
  private:
       void init();
       void init(const Linux_DnsAllowNotifyACLForZoneInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       Linux_DnsZoneInstanceName m_Element;
       Linux_DnsAddressMatchListInstanceName m_Setting;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int Element:1;
         unsigned int Setting:1;
       } isSet;
  };
  
  
  struct Linux_DnsAllowNotifyACLForZoneInstanceNameEnumerationElement{
  	Linux_DnsAllowNotifyACLForZoneInstanceName* m_elementP;
  	Linux_DnsAllowNotifyACLForZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowNotifyACLForZoneInstanceNameEnumerationElement();
  	~Linux_DnsAllowNotifyACLForZoneInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration {
  	private:
  	  Linux_DnsAllowNotifyACLForZoneInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsAllowNotifyACLForZoneInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsAllowNotifyACLForZoneInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration();
  	  
  	  Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration(
  	   const Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsAllowNotifyACLForZoneInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAllowNotifyACLForZoneInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAllowNotifyACLForZoneInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsAllowNotifyACLForZoneInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

