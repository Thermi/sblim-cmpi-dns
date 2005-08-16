 /**
 * Linux_DnsAllowUpdateACLForZoneInstanceName.h
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
#ifndef Linux_DnsAllowUpdateACLForZoneInstanceName_h
#define Linux_DnsAllowUpdateACLForZoneInstanceName_h

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

  class Linux_DnsAllowUpdateACLForZoneInstanceName {
  public:
       Linux_DnsAllowUpdateACLForZoneInstanceName();
  	
       Linux_DnsAllowUpdateACLForZoneInstanceName
  	    (const Linux_DnsAllowUpdateACLForZoneInstanceName& original);
  	   
       Linux_DnsAllowUpdateACLForZoneInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsAllowUpdateACLForZoneInstanceName();
       
       Linux_DnsAllowUpdateACLForZoneInstanceName& operator=
  	    (const Linux_DnsAllowUpdateACLForZoneInstanceName& original);
       
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
       void init(const Linux_DnsAllowUpdateACLForZoneInstanceName& original);
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
  
  
  struct Linux_DnsAllowUpdateACLForZoneInstanceNameEnumerationElement{
  	Linux_DnsAllowUpdateACLForZoneInstanceName* m_elementP;
  	Linux_DnsAllowUpdateACLForZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowUpdateACLForZoneInstanceNameEnumerationElement();
  	~Linux_DnsAllowUpdateACLForZoneInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsAllowUpdateACLForZoneInstanceNameEnumeration {
  	private:
  	  Linux_DnsAllowUpdateACLForZoneInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsAllowUpdateACLForZoneInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsAllowUpdateACLForZoneInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAllowUpdateACLForZoneInstanceNameEnumeration();
  	  
  	  Linux_DnsAllowUpdateACLForZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsAllowUpdateACLForZoneInstanceNameEnumeration(
  	   const Linux_DnsAllowUpdateACLForZoneInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsAllowUpdateACLForZoneInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAllowUpdateACLForZoneInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAllowUpdateACLForZoneInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsAllowUpdateACLForZoneInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

