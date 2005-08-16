 /**
 * Linux_DnsBlackholeACLForServiceManualInstance.h
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
#ifndef Linux_DnsBlackholeACLForServiceManualInstance_h
#define Linux_DnsBlackholeACLForServiceManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsBlackholeACLForServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsBlackholeACLForServiceManualInstance {
  public:
       Linux_DnsBlackholeACLForServiceManualInstance();
  	
       Linux_DnsBlackholeACLForServiceManualInstance
  	    (const Linux_DnsBlackholeACLForServiceManualInstance& original);
  	   
       Linux_DnsBlackholeACLForServiceManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsBlackholeACLForServiceManualInstance();
       
       Linux_DnsBlackholeACLForServiceManualInstance& operator=
  	    (const Linux_DnsBlackholeACLForServiceManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsBlackholeACLForServiceInstanceName& val);        
       const Linux_DnsBlackholeACLForServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsBlackholeACLForServiceManualInstance& original);
       void reset();
       
       Linux_DnsBlackholeACLForServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsBlackholeACLForServiceManualInstanceEnumerationElement{
  	Linux_DnsBlackholeACLForServiceManualInstance* m_elementP;
  	Linux_DnsBlackholeACLForServiceManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsBlackholeACLForServiceManualInstanceEnumerationElement();
  	~Linux_DnsBlackholeACLForServiceManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsBlackholeACLForServiceManualInstanceEnumeration {
  	private:
  	  Linux_DnsBlackholeACLForServiceManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsBlackholeACLForServiceManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsBlackholeACLForServiceManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsBlackholeACLForServiceManualInstanceEnumeration();
  	  
  	  Linux_DnsBlackholeACLForServiceManualInstanceEnumeration(
  	   const Linux_DnsBlackholeACLForServiceManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsBlackholeACLForServiceManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsBlackholeACLForServiceManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsBlackholeACLForServiceManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsBlackholeACLForServiceManualInstance& elementP);
  };
}
#endif

