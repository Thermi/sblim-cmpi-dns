 /**
 * Linux_DnsNotifyACLForServiceRepositoryInstance.h
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
#ifndef Linux_DnsNotifyACLForServiceRepositoryInstance_h
#define Linux_DnsNotifyACLForServiceRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsNotifyACLForServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsNotifyACLForServiceRepositoryInstance {
  public:
       Linux_DnsNotifyACLForServiceRepositoryInstance();
  	
       Linux_DnsNotifyACLForServiceRepositoryInstance
  	    (const Linux_DnsNotifyACLForServiceRepositoryInstance& original);
  	   
       Linux_DnsNotifyACLForServiceRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsNotifyACLForServiceRepositoryInstance();
       
       Linux_DnsNotifyACLForServiceRepositoryInstance& operator=
  	    (const Linux_DnsNotifyACLForServiceRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsNotifyACLForServiceInstanceName& val);        
       const Linux_DnsNotifyACLForServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsNotifyACLForServiceRepositoryInstance& original);
       void reset();
       
       Linux_DnsNotifyACLForServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement{
  	Linux_DnsNotifyACLForServiceRepositoryInstance* m_elementP;
  	Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement();
  	~Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsNotifyACLForServiceRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration(
  	   const Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsNotifyACLForServiceRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsNotifyACLForServiceRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsNotifyACLForServiceRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsNotifyACLForServiceRepositoryInstance& elementP);
  };
}
#endif

