 /**
 * Linux_DnsQueryACLForServiceManualInstance.h
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
#ifndef Linux_DnsQueryACLForServiceManualInstance_h
#define Linux_DnsQueryACLForServiceManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsQueryACLForServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsQueryACLForServiceManualInstance {
  public:
       Linux_DnsQueryACLForServiceManualInstance();
  	
       Linux_DnsQueryACLForServiceManualInstance
  	    (const Linux_DnsQueryACLForServiceManualInstance& original);
  	   
       Linux_DnsQueryACLForServiceManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsQueryACLForServiceManualInstance();
       
       Linux_DnsQueryACLForServiceManualInstance& operator=
  	    (const Linux_DnsQueryACLForServiceManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsQueryACLForServiceInstanceName& val);        
       const Linux_DnsQueryACLForServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsQueryACLForServiceManualInstance& original);
       void reset();
       
       Linux_DnsQueryACLForServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsQueryACLForServiceManualInstanceEnumerationElement{
  	Linux_DnsQueryACLForServiceManualInstance* m_elementP;
  	Linux_DnsQueryACLForServiceManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsQueryACLForServiceManualInstanceEnumerationElement();
  	~Linux_DnsQueryACLForServiceManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsQueryACLForServiceManualInstanceEnumeration {
  	private:
  	  Linux_DnsQueryACLForServiceManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsQueryACLForServiceManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsQueryACLForServiceManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsQueryACLForServiceManualInstanceEnumeration();
  	  
  	  Linux_DnsQueryACLForServiceManualInstanceEnumeration(
  	   const Linux_DnsQueryACLForServiceManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsQueryACLForServiceManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsQueryACLForServiceManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsQueryACLForServiceManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsQueryACLForServiceManualInstance& elementP);
  };
}
#endif

