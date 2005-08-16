 /**
 * Linux_DnsNotifyACLForServiceInstanceName.h
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
#ifndef Linux_DnsNotifyACLForServiceInstanceName_h
#define Linux_DnsNotifyACLForServiceInstanceName_h

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

  class Linux_DnsNotifyACLForServiceInstanceName {
  public:
       Linux_DnsNotifyACLForServiceInstanceName();
  	
       Linux_DnsNotifyACLForServiceInstanceName
  	    (const Linux_DnsNotifyACLForServiceInstanceName& original);
  	   
       Linux_DnsNotifyACLForServiceInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsNotifyACLForServiceInstanceName();
       
       Linux_DnsNotifyACLForServiceInstanceName& operator=
  	    (const Linux_DnsNotifyACLForServiceInstanceName& original);
       
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
       void init(const Linux_DnsNotifyACLForServiceInstanceName& original);
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
  
  
  struct Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement{
  	Linux_DnsNotifyACLForServiceInstanceName* m_elementP;
  	Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement();
  	~Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsNotifyACLForServiceInstanceNameEnumeration {
  	private:
  	  Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsNotifyACLForServiceInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsNotifyACLForServiceInstanceNameEnumeration();
  	  
  	  Linux_DnsNotifyACLForServiceInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsNotifyACLForServiceInstanceNameEnumeration(
  	   const Linux_DnsNotifyACLForServiceInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsNotifyACLForServiceInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsNotifyACLForServiceInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsNotifyACLForServiceInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsNotifyACLForServiceInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

