 /**
 * Linux_DnsElementSettingInstanceName.h
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
#ifndef Linux_DnsElementSettingInstanceName_h
#define Linux_DnsElementSettingInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsServiceInstanceName.h"
#include "Linux_DnsSettingInstanceName.h"

namespace genProvider {

  class Linux_DnsElementSettingInstanceName {
  public:
       Linux_DnsElementSettingInstanceName();
  	
       Linux_DnsElementSettingInstanceName
  	    (const Linux_DnsElementSettingInstanceName& original);
  	   
       Linux_DnsElementSettingInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsElementSettingInstanceName();
       
       Linux_DnsElementSettingInstanceName& operator=
  	    (const Linux_DnsElementSettingInstanceName& original);
       
       CmpiObjectPath getObjectPath() const;
       
       void fillKeys(CmpiInstance& cmpiInstance) const;
       
       unsigned int isNameSpaceSet() const;
       void setNamespace(const char * val, int makeCopy = 1);
       const char * getNamespace() const;

       unsigned int isElementSet() const;
       void setElement(const Linux_DnsServiceInstanceName& val);
       const Linux_DnsServiceInstanceName& getElement() const;

       unsigned int isSettingSet() const;
       void setSetting(const Linux_DnsSettingInstanceName& val);
       const Linux_DnsSettingInstanceName& getSetting() const;
       
  private:
       void init();
       void init(const Linux_DnsElementSettingInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       Linux_DnsServiceInstanceName m_Element;
       Linux_DnsSettingInstanceName m_Setting;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int Element:1;
         unsigned int Setting:1;
       } isSet;
  };
  
  
  struct Linux_DnsElementSettingInstanceNameEnumerationElement{
  	Linux_DnsElementSettingInstanceName* m_elementP;
  	Linux_DnsElementSettingInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsElementSettingInstanceNameEnumerationElement();
  	~Linux_DnsElementSettingInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsElementSettingInstanceNameEnumeration {
  	private:
  	  Linux_DnsElementSettingInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsElementSettingInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsElementSettingInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsElementSettingInstanceNameEnumeration();
  	  
  	  Linux_DnsElementSettingInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsElementSettingInstanceNameEnumeration(
  	   const Linux_DnsElementSettingInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsElementSettingInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsElementSettingInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsElementSettingInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsElementSettingInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

