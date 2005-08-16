 /**
 * Linux_DnsBlackholeACLForServiceRepositoryInstance.h
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
#ifndef Linux_DnsBlackholeACLForServiceRepositoryInstance_h
#define Linux_DnsBlackholeACLForServiceRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsBlackholeACLForServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsBlackholeACLForServiceRepositoryInstance {
  public:
       Linux_DnsBlackholeACLForServiceRepositoryInstance();
  	
       Linux_DnsBlackholeACLForServiceRepositoryInstance
  	    (const Linux_DnsBlackholeACLForServiceRepositoryInstance& original);
  	   
       Linux_DnsBlackholeACLForServiceRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsBlackholeACLForServiceRepositoryInstance();
       
       Linux_DnsBlackholeACLForServiceRepositoryInstance& operator=
  	    (const Linux_DnsBlackholeACLForServiceRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsBlackholeACLForServiceInstanceName& val);        
       const Linux_DnsBlackholeACLForServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsBlackholeACLForServiceRepositoryInstance& original);
       void reset();
       
       Linux_DnsBlackholeACLForServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumerationElement{
  	Linux_DnsBlackholeACLForServiceRepositoryInstance* m_elementP;
  	Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumerationElement();
  	~Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration(
  	   const Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsBlackholeACLForServiceRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsBlackholeACLForServiceRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsBlackholeACLForServiceRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsBlackholeACLForServiceRepositoryInstance& elementP);
  };
}
#endif

