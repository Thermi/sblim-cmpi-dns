 /**
 * Linux_DnsAllowTransferACLForZoneManualInstance.h
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
#ifndef Linux_DnsAllowTransferACLForZoneManualInstance_h
#define Linux_DnsAllowTransferACLForZoneManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowTransferACLForZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsAllowTransferACLForZoneManualInstance {
  public:
       Linux_DnsAllowTransferACLForZoneManualInstance();
  	
       Linux_DnsAllowTransferACLForZoneManualInstance
  	    (const Linux_DnsAllowTransferACLForZoneManualInstance& original);
  	   
       Linux_DnsAllowTransferACLForZoneManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAllowTransferACLForZoneManualInstance();
       
       Linux_DnsAllowTransferACLForZoneManualInstance& operator=
  	    (const Linux_DnsAllowTransferACLForZoneManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsAllowTransferACLForZoneInstanceName& val);        
       const Linux_DnsAllowTransferACLForZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsAllowTransferACLForZoneManualInstance& original);
       void reset();
       
       Linux_DnsAllowTransferACLForZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement{
  	Linux_DnsAllowTransferACLForZoneManualInstance* m_elementP;
  	Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement();
  	~Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration {
  	private:
  	  Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAllowTransferACLForZoneManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration();
  	  
  	  Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration(
  	   const Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAllowTransferACLForZoneManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAllowTransferACLForZoneManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAllowTransferACLForZoneManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAllowTransferACLForZoneManualInstance& elementP);
  };
}
#endif

