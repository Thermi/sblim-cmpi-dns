 /**
 * Linux_DnsRecursionACLForServiceManualInstance.h
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
#ifndef Linux_DnsRecursionACLForServiceManualInstance_h
#define Linux_DnsRecursionACLForServiceManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsRecursionACLForServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsRecursionACLForServiceManualInstance {
  public:
       Linux_DnsRecursionACLForServiceManualInstance();
  	
       Linux_DnsRecursionACLForServiceManualInstance
  	    (const Linux_DnsRecursionACLForServiceManualInstance& original);
  	   
       Linux_DnsRecursionACLForServiceManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsRecursionACLForServiceManualInstance();
       
       Linux_DnsRecursionACLForServiceManualInstance& operator=
  	    (const Linux_DnsRecursionACLForServiceManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsRecursionACLForServiceInstanceName& val);        
       const Linux_DnsRecursionACLForServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsRecursionACLForServiceManualInstance& original);
       void reset();
       
       Linux_DnsRecursionACLForServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement{
  	Linux_DnsRecursionACLForServiceManualInstance* m_elementP;
  	Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement();
  	~Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsRecursionACLForServiceManualInstanceEnumeration {
  	private:
  	  Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsRecursionACLForServiceManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsRecursionACLForServiceManualInstanceEnumeration();
  	  
  	  Linux_DnsRecursionACLForServiceManualInstanceEnumeration(
  	   const Linux_DnsRecursionACLForServiceManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsRecursionACLForServiceManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsRecursionACLForServiceManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsRecursionACLForServiceManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsRecursionACLForServiceManualInstance& elementP);
  };
}
#endif

