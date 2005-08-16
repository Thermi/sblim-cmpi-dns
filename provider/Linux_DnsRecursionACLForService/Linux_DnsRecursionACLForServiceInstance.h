 /**
 * Linux_DnsRecursionACLForServiceInstance.h
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
#ifndef Linux_DnsRecursionACLForServiceInstance_h
#define Linux_DnsRecursionACLForServiceInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsRecursionACLForServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsRecursionACLForServiceInstance {
  public:
       Linux_DnsRecursionACLForServiceInstance();
  	
       Linux_DnsRecursionACLForServiceInstance
  	    (const Linux_DnsRecursionACLForServiceInstance& original);
  	   
       Linux_DnsRecursionACLForServiceInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsRecursionACLForServiceInstance();
       
       Linux_DnsRecursionACLForServiceInstance& operator=
  	    (const Linux_DnsRecursionACLForServiceInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsRecursionACLForServiceInstanceName& val);        
       const Linux_DnsRecursionACLForServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsRecursionACLForServiceInstance& original);
       void reset();
       
       Linux_DnsRecursionACLForServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsRecursionACLForServiceInstanceEnumerationElement{
  	Linux_DnsRecursionACLForServiceInstance* m_elementP;
  	Linux_DnsRecursionACLForServiceInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsRecursionACLForServiceInstanceEnumerationElement();
  	~Linux_DnsRecursionACLForServiceInstanceEnumerationElement();  	
  };
  

  class Linux_DnsRecursionACLForServiceInstanceEnumeration {
  	private:
  	  Linux_DnsRecursionACLForServiceInstanceEnumerationElement* firstElementP;
  	  Linux_DnsRecursionACLForServiceInstanceEnumerationElement* currentElementP;
  	  Linux_DnsRecursionACLForServiceInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsRecursionACLForServiceInstanceEnumeration();
  	  
  	  Linux_DnsRecursionACLForServiceInstanceEnumeration(
  	   const Linux_DnsRecursionACLForServiceInstanceEnumeration& original);
  	  
  	  ~Linux_DnsRecursionACLForServiceInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsRecursionACLForServiceInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsRecursionACLForServiceInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsRecursionACLForServiceInstance& elementP);
  };
}
#endif

