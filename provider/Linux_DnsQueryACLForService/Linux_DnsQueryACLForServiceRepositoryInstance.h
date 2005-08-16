 /**
 * Linux_DnsQueryACLForServiceRepositoryInstance.h
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
#ifndef Linux_DnsQueryACLForServiceRepositoryInstance_h
#define Linux_DnsQueryACLForServiceRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsQueryACLForServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsQueryACLForServiceRepositoryInstance {
  public:
       Linux_DnsQueryACLForServiceRepositoryInstance();
  	
       Linux_DnsQueryACLForServiceRepositoryInstance
  	    (const Linux_DnsQueryACLForServiceRepositoryInstance& original);
  	   
       Linux_DnsQueryACLForServiceRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsQueryACLForServiceRepositoryInstance();
       
       Linux_DnsQueryACLForServiceRepositoryInstance& operator=
  	    (const Linux_DnsQueryACLForServiceRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsQueryACLForServiceInstanceName& val);        
       const Linux_DnsQueryACLForServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsQueryACLForServiceRepositoryInstance& original);
       void reset();
       
       Linux_DnsQueryACLForServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement{
  	Linux_DnsQueryACLForServiceRepositoryInstance* m_elementP;
  	Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement();
  	~Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsQueryACLForServiceRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration(
  	   const Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsQueryACLForServiceRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsQueryACLForServiceRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsQueryACLForServiceRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsQueryACLForServiceRepositoryInstance& elementP);
  };
}
#endif

