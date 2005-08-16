 /**
 * Linux_DnsServiceRepositoryInstance.h
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
#ifndef Linux_DnsServiceRepositoryInstance_h
#define Linux_DnsServiceRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsServiceRepositoryInstance {
  public:
       Linux_DnsServiceRepositoryInstance();
  	
       Linux_DnsServiceRepositoryInstance
  	    (const Linux_DnsServiceRepositoryInstance& original);
  	   
       Linux_DnsServiceRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsServiceRepositoryInstance();
       
       Linux_DnsServiceRepositoryInstance& operator=
  	    (const Linux_DnsServiceRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsServiceInstanceName& val);        
       const Linux_DnsServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsServiceRepositoryInstance& original);
       void reset();
       
       Linux_DnsServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsServiceRepositoryInstanceEnumerationElement{
  	Linux_DnsServiceRepositoryInstance* m_elementP;
  	Linux_DnsServiceRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsServiceRepositoryInstanceEnumerationElement();
  	~Linux_DnsServiceRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsServiceRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsServiceRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsServiceRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsServiceRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsServiceRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsServiceRepositoryInstanceEnumeration(
  	   const Linux_DnsServiceRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsServiceRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsServiceRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsServiceRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsServiceRepositoryInstance& elementP);
  };
}
#endif

