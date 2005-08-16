 /**
 * Linux_DnsAllowTransferACLForZoneInstance.h
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
#ifndef Linux_DnsAllowTransferACLForZoneInstance_h
#define Linux_DnsAllowTransferACLForZoneInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowTransferACLForZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsAllowTransferACLForZoneInstance {
  public:
       Linux_DnsAllowTransferACLForZoneInstance();
  	
       Linux_DnsAllowTransferACLForZoneInstance
  	    (const Linux_DnsAllowTransferACLForZoneInstance& original);
  	   
       Linux_DnsAllowTransferACLForZoneInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAllowTransferACLForZoneInstance();
       
       Linux_DnsAllowTransferACLForZoneInstance& operator=
  	    (const Linux_DnsAllowTransferACLForZoneInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsAllowTransferACLForZoneInstanceName& val);        
       const Linux_DnsAllowTransferACLForZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsAllowTransferACLForZoneInstance& original);
       void reset();
       
       Linux_DnsAllowTransferACLForZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement{
  	Linux_DnsAllowTransferACLForZoneInstance* m_elementP;
  	Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement();
  	~Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAllowTransferACLForZoneInstanceEnumeration {
  	private:
  	  Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAllowTransferACLForZoneInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAllowTransferACLForZoneInstanceEnumeration();
  	  
  	  Linux_DnsAllowTransferACLForZoneInstanceEnumeration(
  	   const Linux_DnsAllowTransferACLForZoneInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAllowTransferACLForZoneInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAllowTransferACLForZoneInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAllowTransferACLForZoneInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAllowTransferACLForZoneInstance& elementP);
  };
}
#endif

