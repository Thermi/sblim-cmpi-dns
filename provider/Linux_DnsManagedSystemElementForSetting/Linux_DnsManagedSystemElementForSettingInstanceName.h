 /**
 * Linux_DnsManagedSystemElementForSettingInstanceName.h
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
#ifndef Linux_DnsManagedSystemElementForSettingInstanceName_h
#define Linux_DnsManagedSystemElementForSettingInstanceName_h

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

  class Linux_DnsManagedSystemElementForSettingInstanceName {
  public:
       Linux_DnsManagedSystemElementForSettingInstanceName();
  	
       Linux_DnsManagedSystemElementForSettingInstanceName
  	    (const Linux_DnsManagedSystemElementForSettingInstanceName& original);
  	   
       Linux_DnsManagedSystemElementForSettingInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsManagedSystemElementForSettingInstanceName();
       
       Linux_DnsManagedSystemElementForSettingInstanceName& operator=
  	    (const Linux_DnsManagedSystemElementForSettingInstanceName& original);
       
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
       void init(const Linux_DnsManagedSystemElementForSettingInstanceName& original);
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
  
  
  struct Linux_DnsManagedSystemElementForSettingInstanceNameEnumerationElement{
  	Linux_DnsManagedSystemElementForSettingInstanceName* m_elementP;
  	Linux_DnsManagedSystemElementForSettingInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsManagedSystemElementForSettingInstanceNameEnumerationElement();
  	~Linux_DnsManagedSystemElementForSettingInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration {
  	private:
  	  Linux_DnsManagedSystemElementForSettingInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsManagedSystemElementForSettingInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsManagedSystemElementForSettingInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration();
  	  
  	  Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration(
  	   const Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsManagedSystemElementForSettingInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsManagedSystemElementForSettingInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsManagedSystemElementForSettingInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsManagedSystemElementForSettingInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

