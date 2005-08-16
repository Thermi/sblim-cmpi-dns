 /**
 * Linux_DnsAllowNotifyACLForZoneManualInstance.h
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
#ifndef Linux_DnsAllowNotifyACLForZoneManualInstance_h
#define Linux_DnsAllowNotifyACLForZoneManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowNotifyACLForZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsAllowNotifyACLForZoneManualInstance {
  public:
       Linux_DnsAllowNotifyACLForZoneManualInstance();
  	
       Linux_DnsAllowNotifyACLForZoneManualInstance
  	    (const Linux_DnsAllowNotifyACLForZoneManualInstance& original);
  	   
       Linux_DnsAllowNotifyACLForZoneManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAllowNotifyACLForZoneManualInstance();
       
       Linux_DnsAllowNotifyACLForZoneManualInstance& operator=
  	    (const Linux_DnsAllowNotifyACLForZoneManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsAllowNotifyACLForZoneInstanceName& val);        
       const Linux_DnsAllowNotifyACLForZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsAllowNotifyACLForZoneManualInstance& original);
       void reset();
       
       Linux_DnsAllowNotifyACLForZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsAllowNotifyACLForZoneManualInstanceEnumerationElement{
  	Linux_DnsAllowNotifyACLForZoneManualInstance* m_elementP;
  	Linux_DnsAllowNotifyACLForZoneManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowNotifyACLForZoneManualInstanceEnumerationElement();
  	~Linux_DnsAllowNotifyACLForZoneManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration {
  	private:
  	  Linux_DnsAllowNotifyACLForZoneManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAllowNotifyACLForZoneManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAllowNotifyACLForZoneManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration();
  	  
  	  Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration(
  	   const Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAllowNotifyACLForZoneManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAllowNotifyACLForZoneManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAllowNotifyACLForZoneManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAllowNotifyACLForZoneManualInstance& elementP);
  };
}
#endif

