 /**
 * Linux_DnsSettingContextInstanceName.h
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
#ifndef Linux_DnsSettingContextInstanceName_h
#define Linux_DnsSettingContextInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsConfigurationInstanceName.h"
#include "Linux_DnsSettingInstanceName.h"

namespace genProvider {

  class Linux_DnsSettingContextInstanceName {
  public:
       Linux_DnsSettingContextInstanceName();
  	
       Linux_DnsSettingContextInstanceName
  	    (const Linux_DnsSettingContextInstanceName& original);
  	   
       Linux_DnsSettingContextInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsSettingContextInstanceName();
       
       Linux_DnsSettingContextInstanceName& operator=
  	    (const Linux_DnsSettingContextInstanceName& original);
       
       CmpiObjectPath getObjectPath() const;
       
       void fillKeys(CmpiInstance& cmpiInstance) const;
       
       unsigned int isNameSpaceSet() const;
       void setNamespace(const char * val, int makeCopy = 1);
       const char * getNamespace() const;

       unsigned int isContextSet() const;
       void setContext(const Linux_DnsConfigurationInstanceName& val);
       const Linux_DnsConfigurationInstanceName& getContext() const;

       unsigned int isSettingSet() const;
       void setSetting(const Linux_DnsSettingInstanceName& val);
       const Linux_DnsSettingInstanceName& getSetting() const;
       
  private:
       void init();
       void init(const Linux_DnsSettingContextInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       Linux_DnsConfigurationInstanceName m_Context;
       Linux_DnsSettingInstanceName m_Setting;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int Context:1;
         unsigned int Setting:1;
       } isSet;
  };
  
  
  struct Linux_DnsSettingContextInstanceNameEnumerationElement{
  	Linux_DnsSettingContextInstanceName* m_elementP;
  	Linux_DnsSettingContextInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsSettingContextInstanceNameEnumerationElement();
  	~Linux_DnsSettingContextInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsSettingContextInstanceNameEnumeration {
  	private:
  	  Linux_DnsSettingContextInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsSettingContextInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsSettingContextInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsSettingContextInstanceNameEnumeration();
  	  
  	  Linux_DnsSettingContextInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsSettingContextInstanceNameEnumeration(
  	   const Linux_DnsSettingContextInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsSettingContextInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsSettingContextInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsSettingContextInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsSettingContextInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

