 /**
 * Linux_DnsQueryACLForServiceInstance.h
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
#ifndef Linux_DnsQueryACLForServiceInstance_h
#define Linux_DnsQueryACLForServiceInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsQueryACLForServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsQueryACLForServiceInstance {
  public:
       Linux_DnsQueryACLForServiceInstance();
  	
       Linux_DnsQueryACLForServiceInstance
  	    (const Linux_DnsQueryACLForServiceInstance& original);
  	   
       Linux_DnsQueryACLForServiceInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsQueryACLForServiceInstance();
       
       Linux_DnsQueryACLForServiceInstance& operator=
  	    (const Linux_DnsQueryACLForServiceInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsQueryACLForServiceInstanceName& val);        
       const Linux_DnsQueryACLForServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsQueryACLForServiceInstance& original);
       void reset();
       
       Linux_DnsQueryACLForServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsQueryACLForServiceInstanceEnumerationElement{
  	Linux_DnsQueryACLForServiceInstance* m_elementP;
  	Linux_DnsQueryACLForServiceInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsQueryACLForServiceInstanceEnumerationElement();
  	~Linux_DnsQueryACLForServiceInstanceEnumerationElement();  	
  };
  

  class Linux_DnsQueryACLForServiceInstanceEnumeration {
  	private:
  	  Linux_DnsQueryACLForServiceInstanceEnumerationElement* firstElementP;
  	  Linux_DnsQueryACLForServiceInstanceEnumerationElement* currentElementP;
  	  Linux_DnsQueryACLForServiceInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsQueryACLForServiceInstanceEnumeration();
  	  
  	  Linux_DnsQueryACLForServiceInstanceEnumeration(
  	   const Linux_DnsQueryACLForServiceInstanceEnumeration& original);
  	  
  	  ~Linux_DnsQueryACLForServiceInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsQueryACLForServiceInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsQueryACLForServiceInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsQueryACLForServiceInstance& elementP);
  };
}
#endif

