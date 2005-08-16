 /**
 * Linux_DnsAllowUpdateACLForZoneManualInstance.h
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
#ifndef Linux_DnsAllowUpdateACLForZoneManualInstance_h
#define Linux_DnsAllowUpdateACLForZoneManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowUpdateACLForZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsAllowUpdateACLForZoneManualInstance {
  public:
       Linux_DnsAllowUpdateACLForZoneManualInstance();
  	
       Linux_DnsAllowUpdateACLForZoneManualInstance
  	    (const Linux_DnsAllowUpdateACLForZoneManualInstance& original);
  	   
       Linux_DnsAllowUpdateACLForZoneManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAllowUpdateACLForZoneManualInstance();
       
       Linux_DnsAllowUpdateACLForZoneManualInstance& operator=
  	    (const Linux_DnsAllowUpdateACLForZoneManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsAllowUpdateACLForZoneInstanceName& val);        
       const Linux_DnsAllowUpdateACLForZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsAllowUpdateACLForZoneManualInstance& original);
       void reset();
       
       Linux_DnsAllowUpdateACLForZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement{
  	Linux_DnsAllowUpdateACLForZoneManualInstance* m_elementP;
  	Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement();
  	~Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration {
  	private:
  	  Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAllowUpdateACLForZoneManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration();
  	  
  	  Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration(
  	   const Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAllowUpdateACLForZoneManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAllowUpdateACLForZoneManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAllowUpdateACLForZoneManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAllowUpdateACLForZoneManualInstance& elementP);
  };
}
#endif

