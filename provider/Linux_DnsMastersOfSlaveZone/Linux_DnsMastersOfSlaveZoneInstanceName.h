 /**
 * Linux_DnsMastersOfSlaveZoneInstanceName.h
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
#ifndef Linux_DnsMastersOfSlaveZoneInstanceName_h
#define Linux_DnsMastersOfSlaveZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"
#include "Linux_DnsSlaveZoneInstanceName.h"
#include "Linux_DnsIPAddressInstanceName.h"

namespace genProvider {

  class Linux_DnsMastersOfSlaveZoneInstanceName {
  public:
       Linux_DnsMastersOfSlaveZoneInstanceName();
  	
       Linux_DnsMastersOfSlaveZoneInstanceName
  	    (const Linux_DnsMastersOfSlaveZoneInstanceName& original);
  	   
       Linux_DnsMastersOfSlaveZoneInstanceName
        (const CmpiObjectPath& path);
  	 
       ~Linux_DnsMastersOfSlaveZoneInstanceName();
       
       Linux_DnsMastersOfSlaveZoneInstanceName& operator=
  	    (const Linux_DnsMastersOfSlaveZoneInstanceName& original);
       
       CmpiObjectPath getObjectPath() const;
       
       void fillKeys(CmpiInstance& cmpiInstance) const;
       
       unsigned int isNameSpaceSet() const;
       void setNamespace(const char * val, int makeCopy = 1);
       const char * getNamespace() const;

       unsigned int isElementSet() const;
       void setElement(const Linux_DnsSlaveZoneInstanceName& val);
       const Linux_DnsSlaveZoneInstanceName& getElement() const;

       unsigned int isSettingSet() const;
       void setSetting(const Linux_DnsIPAddressInstanceName& val);
       const Linux_DnsIPAddressInstanceName& getSetting() const;
       
  private:
       void init();
       void init(const Linux_DnsMastersOfSlaveZoneInstanceName& original);
       void reset();
       
       const char* m_CIMClassNameP;
       const char* m_namespace;
       Linux_DnsSlaveZoneInstanceName m_Element;
       Linux_DnsIPAddressInstanceName m_Setting;
       
       struct isSetType{
       	 unsigned int m_namespace:1;
         unsigned int Element:1;
         unsigned int Setting:1;
       } isSet;
  };
  
  
  struct Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement{
  	Linux_DnsMastersOfSlaveZoneInstanceName* m_elementP;
  	Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement();
  	~Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement();  	
  };
  

  class Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration {
  	private:
  	  Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement* firstElementP;
  	  Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement* currentElementP;
  	  Linux_DnsMastersOfSlaveZoneInstanceNameEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration();
  	  
  	  Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
  	  Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration(
  	   const Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration& original);
  	  
  	  ~Linux_DnsMastersOfSlaveZoneInstanceNameEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsMastersOfSlaveZoneInstanceName& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsMastersOfSlaveZoneInstanceName& getElement(int pos) const;  	  
  	  
  	  //no copy of the element is done
  	  void addElement(const Linux_DnsMastersOfSlaveZoneInstanceName& elementP);
  	  
  	  operator CmpiArray() const;
  };
}
#endif

