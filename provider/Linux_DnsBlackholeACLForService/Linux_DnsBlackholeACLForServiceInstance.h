 /**
 * Linux_DnsBlackholeACLForServiceInstance.h
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
#ifndef Linux_DnsBlackholeACLForServiceInstance_h
#define Linux_DnsBlackholeACLForServiceInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsBlackholeACLForServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsBlackholeACLForServiceInstance {
  public:
       Linux_DnsBlackholeACLForServiceInstance();
  	
       Linux_DnsBlackholeACLForServiceInstance
  	    (const Linux_DnsBlackholeACLForServiceInstance& original);
  	   
       Linux_DnsBlackholeACLForServiceInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsBlackholeACLForServiceInstance();
       
       Linux_DnsBlackholeACLForServiceInstance& operator=
  	    (const Linux_DnsBlackholeACLForServiceInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsBlackholeACLForServiceInstanceName& val);        
       const Linux_DnsBlackholeACLForServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsBlackholeACLForServiceInstance& original);
       void reset();
       
       Linux_DnsBlackholeACLForServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsBlackholeACLForServiceInstanceEnumerationElement{
  	Linux_DnsBlackholeACLForServiceInstance* m_elementP;
  	Linux_DnsBlackholeACLForServiceInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsBlackholeACLForServiceInstanceEnumerationElement();
  	~Linux_DnsBlackholeACLForServiceInstanceEnumerationElement();  	
  };
  

  class Linux_DnsBlackholeACLForServiceInstanceEnumeration {
  	private:
  	  Linux_DnsBlackholeACLForServiceInstanceEnumerationElement* firstElementP;
  	  Linux_DnsBlackholeACLForServiceInstanceEnumerationElement* currentElementP;
  	  Linux_DnsBlackholeACLForServiceInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsBlackholeACLForServiceInstanceEnumeration();
  	  
  	  Linux_DnsBlackholeACLForServiceInstanceEnumeration(
  	   const Linux_DnsBlackholeACLForServiceInstanceEnumeration& original);
  	  
  	  ~Linux_DnsBlackholeACLForServiceInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsBlackholeACLForServiceInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsBlackholeACLForServiceInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsBlackholeACLForServiceInstance& elementP);
  };
}
#endif

