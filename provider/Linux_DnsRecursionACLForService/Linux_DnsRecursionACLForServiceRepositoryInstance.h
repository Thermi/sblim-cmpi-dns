 /**
 * Linux_DnsRecursionACLForServiceRepositoryInstance.h
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
#ifndef Linux_DnsRecursionACLForServiceRepositoryInstance_h
#define Linux_DnsRecursionACLForServiceRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsRecursionACLForServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsRecursionACLForServiceRepositoryInstance {
  public:
       Linux_DnsRecursionACLForServiceRepositoryInstance();
  	
       Linux_DnsRecursionACLForServiceRepositoryInstance
  	    (const Linux_DnsRecursionACLForServiceRepositoryInstance& original);
  	   
       Linux_DnsRecursionACLForServiceRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsRecursionACLForServiceRepositoryInstance();
       
       Linux_DnsRecursionACLForServiceRepositoryInstance& operator=
  	    (const Linux_DnsRecursionACLForServiceRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsRecursionACLForServiceInstanceName& val);        
       const Linux_DnsRecursionACLForServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsRecursionACLForServiceRepositoryInstance& original);
       void reset();
       
       Linux_DnsRecursionACLForServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement{
  	Linux_DnsRecursionACLForServiceRepositoryInstance* m_elementP;
  	Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement();
  	~Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsRecursionACLForServiceRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration(
  	   const Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsRecursionACLForServiceRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsRecursionACLForServiceRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsRecursionACLForServiceRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsRecursionACLForServiceRepositoryInstance& elementP);
  };
}
#endif

