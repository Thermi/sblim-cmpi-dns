 /**
 * Linux_DnsAllowNotifyACLForZoneInstance.h
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
#ifndef Linux_DnsAllowNotifyACLForZoneInstance_h
#define Linux_DnsAllowNotifyACLForZoneInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowNotifyACLForZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsAllowNotifyACLForZoneInstance {
  public:
       Linux_DnsAllowNotifyACLForZoneInstance();
  	
       Linux_DnsAllowNotifyACLForZoneInstance
  	    (const Linux_DnsAllowNotifyACLForZoneInstance& original);
  	   
       Linux_DnsAllowNotifyACLForZoneInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAllowNotifyACLForZoneInstance();
       
       Linux_DnsAllowNotifyACLForZoneInstance& operator=
  	    (const Linux_DnsAllowNotifyACLForZoneInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsAllowNotifyACLForZoneInstanceName& val);        
       const Linux_DnsAllowNotifyACLForZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsAllowNotifyACLForZoneInstance& original);
       void reset();
       
       Linux_DnsAllowNotifyACLForZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement{
  	Linux_DnsAllowNotifyACLForZoneInstance* m_elementP;
  	Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement();
  	~Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAllowNotifyACLForZoneInstanceEnumeration {
  	private:
  	  Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAllowNotifyACLForZoneInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAllowNotifyACLForZoneInstanceEnumeration();
  	  
  	  Linux_DnsAllowNotifyACLForZoneInstanceEnumeration(
  	   const Linux_DnsAllowNotifyACLForZoneInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAllowNotifyACLForZoneInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAllowNotifyACLForZoneInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAllowNotifyACLForZoneInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAllowNotifyACLForZoneInstance& elementP);
  };
}
#endif
