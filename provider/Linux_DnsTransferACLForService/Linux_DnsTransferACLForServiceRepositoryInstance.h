 /**
 * Linux_DnsTransferACLForServiceRepositoryInstance.h
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
#ifndef Linux_DnsTransferACLForServiceRepositoryInstance_h
#define Linux_DnsTransferACLForServiceRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsTransferACLForServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsTransferACLForServiceRepositoryInstance {
  public:
       Linux_DnsTransferACLForServiceRepositoryInstance();
  	
       Linux_DnsTransferACLForServiceRepositoryInstance
  	    (const Linux_DnsTransferACLForServiceRepositoryInstance& original);
  	   
       Linux_DnsTransferACLForServiceRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsTransferACLForServiceRepositoryInstance();
       
       Linux_DnsTransferACLForServiceRepositoryInstance& operator=
  	    (const Linux_DnsTransferACLForServiceRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsTransferACLForServiceInstanceName& val);        
       const Linux_DnsTransferACLForServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsTransferACLForServiceRepositoryInstance& original);
       void reset();
       
       Linux_DnsTransferACLForServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement{
  	Linux_DnsTransferACLForServiceRepositoryInstance* m_elementP;
  	Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement();
  	~Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsTransferACLForServiceRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration(
  	   const Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsTransferACLForServiceRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsTransferACLForServiceRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsTransferACLForServiceRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsTransferACLForServiceRepositoryInstance& elementP);
  };
}
#endif

