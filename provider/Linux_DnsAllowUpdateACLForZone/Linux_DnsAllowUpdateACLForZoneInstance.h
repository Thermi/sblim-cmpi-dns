 /**
 * Linux_DnsAllowUpdateACLForZoneInstance.h
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
#ifndef Linux_DnsAllowUpdateACLForZoneInstance_h
#define Linux_DnsAllowUpdateACLForZoneInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowUpdateACLForZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsAllowUpdateACLForZoneInstance {
  public:
       Linux_DnsAllowUpdateACLForZoneInstance();
  	
       Linux_DnsAllowUpdateACLForZoneInstance
  	    (const Linux_DnsAllowUpdateACLForZoneInstance& original);
  	   
       Linux_DnsAllowUpdateACLForZoneInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAllowUpdateACLForZoneInstance();
       
       Linux_DnsAllowUpdateACLForZoneInstance& operator=
  	    (const Linux_DnsAllowUpdateACLForZoneInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsAllowUpdateACLForZoneInstanceName& val);        
       const Linux_DnsAllowUpdateACLForZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsAllowUpdateACLForZoneInstance& original);
       void reset();
       
       Linux_DnsAllowUpdateACLForZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement{
  	Linux_DnsAllowUpdateACLForZoneInstance* m_elementP;
  	Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement();
  	~Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAllowUpdateACLForZoneInstanceEnumeration {
  	private:
  	  Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAllowUpdateACLForZoneInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAllowUpdateACLForZoneInstanceEnumeration();
  	  
  	  Linux_DnsAllowUpdateACLForZoneInstanceEnumeration(
  	   const Linux_DnsAllowUpdateACLForZoneInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAllowUpdateACLForZoneInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAllowUpdateACLForZoneInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAllowUpdateACLForZoneInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAllowUpdateACLForZoneInstance& elementP);
  };
}
#endif

