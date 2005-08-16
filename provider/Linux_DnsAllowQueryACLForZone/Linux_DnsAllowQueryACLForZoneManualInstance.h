 /**
 * Linux_DnsAllowQueryACLForZoneManualInstance.h
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
#ifndef Linux_DnsAllowQueryACLForZoneManualInstance_h
#define Linux_DnsAllowQueryACLForZoneManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowQueryACLForZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsAllowQueryACLForZoneManualInstance {
  public:
       Linux_DnsAllowQueryACLForZoneManualInstance();
  	
       Linux_DnsAllowQueryACLForZoneManualInstance
  	    (const Linux_DnsAllowQueryACLForZoneManualInstance& original);
  	   
       Linux_DnsAllowQueryACLForZoneManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAllowQueryACLForZoneManualInstance();
       
       Linux_DnsAllowQueryACLForZoneManualInstance& operator=
  	    (const Linux_DnsAllowQueryACLForZoneManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsAllowQueryACLForZoneInstanceName& val);        
       const Linux_DnsAllowQueryACLForZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsAllowQueryACLForZoneManualInstance& original);
       void reset();
       
       Linux_DnsAllowQueryACLForZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement{
  	Linux_DnsAllowQueryACLForZoneManualInstance* m_elementP;
  	Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement();
  	~Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration {
  	private:
  	  Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAllowQueryACLForZoneManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration();
  	  
  	  Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration(
  	   const Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAllowQueryACLForZoneManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAllowQueryACLForZoneManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAllowQueryACLForZoneManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAllowQueryACLForZoneManualInstance& elementP);
  };
}
#endif

