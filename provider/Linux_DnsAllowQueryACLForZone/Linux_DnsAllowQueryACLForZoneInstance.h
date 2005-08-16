 /**
 * Linux_DnsAllowQueryACLForZoneInstance.h
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
#ifndef Linux_DnsAllowQueryACLForZoneInstance_h
#define Linux_DnsAllowQueryACLForZoneInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowQueryACLForZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsAllowQueryACLForZoneInstance {
  public:
       Linux_DnsAllowQueryACLForZoneInstance();
  	
       Linux_DnsAllowQueryACLForZoneInstance
  	    (const Linux_DnsAllowQueryACLForZoneInstance& original);
  	   
       Linux_DnsAllowQueryACLForZoneInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAllowQueryACLForZoneInstance();
       
       Linux_DnsAllowQueryACLForZoneInstance& operator=
  	    (const Linux_DnsAllowQueryACLForZoneInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsAllowQueryACLForZoneInstanceName& val);        
       const Linux_DnsAllowQueryACLForZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsAllowQueryACLForZoneInstance& original);
       void reset();
       
       Linux_DnsAllowQueryACLForZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement{
  	Linux_DnsAllowQueryACLForZoneInstance* m_elementP;
  	Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement();
  	~Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAllowQueryACLForZoneInstanceEnumeration {
  	private:
  	  Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAllowQueryACLForZoneInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAllowQueryACLForZoneInstanceEnumeration();
  	  
  	  Linux_DnsAllowQueryACLForZoneInstanceEnumeration(
  	   const Linux_DnsAllowQueryACLForZoneInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAllowQueryACLForZoneInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAllowQueryACLForZoneInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAllowQueryACLForZoneInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAllowQueryACLForZoneInstance& elementP);
  };
}
#endif

