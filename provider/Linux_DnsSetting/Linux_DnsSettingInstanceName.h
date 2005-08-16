 /**
 * Linux_DnsSettingInstanceName.h
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
#ifndef Linux_DnsSettingInstanceName_h
#define Linux_DnsSettingInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"

namespace genProvider {

  class Linux_DnsSettingInstanceName {
  public:
       Linux_DnsSettingInstanceName();
  	
       Linux_DnsSettingInstanceName
  	    (const Linux_DnsSettingInstanceName& original);
  	   
       Linux_DnsSettingInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsSettingInstanceName();
       
       Linux_DnsSettingInstanceName& operator=
  	    (const Linux_DnsSettingInstanceName& original);
       
       CmpiObjectPath getObjectPath() const;
       
       void fillKeys(CmpiInstance& cmpiInstance) const;
       
       unsigned int isNameSpaceSet() const;
       void setNamespace(const char * val, int makeCopy = 1);
       const char * getNamespace() const;

       unsigned int isNameSet() const;
       void setName(const char* val, int makeCopy = 1);
       const char* getName() const;
       
  private:
       void init();
       void init(const Linux_DnsSettingInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       const char* m_Name;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int Name:1;
       } isSet;
  };
  
  
  struct Linux_DnsSettingInstanceNameEnumerationElement{
  	Linux_DnsSettingInstanceName* m_elementP;
  	Linux_DnsSettingInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsSettingInstanceNameEnumerationElement();
  	~Linux_DnsSettingInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsSettingInstanceNameEnumeration {
  	private:
  	  Linux_DnsSettingInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsSettingInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsSettingInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsSettingInstanceNameEnumeration();
  	  
  	  Linux_DnsSettingInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsSettingInstanceNameEnumeration(
  	   const Linux_DnsSettingInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsSettingInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsSettingInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsSettingInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsSettingInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

