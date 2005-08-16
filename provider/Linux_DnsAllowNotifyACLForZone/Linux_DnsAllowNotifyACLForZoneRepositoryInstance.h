 /**
 * Linux_DnsAllowNotifyACLForZoneRepositoryInstance.h
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
#ifndef Linux_DnsAllowNotifyACLForZoneRepositoryInstance_h
#define Linux_DnsAllowNotifyACLForZoneRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowNotifyACLForZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsAllowNotifyACLForZoneRepositoryInstance {
  public:
       Linux_DnsAllowNotifyACLForZoneRepositoryInstance();
  	
       Linux_DnsAllowNotifyACLForZoneRepositoryInstance
  	    (const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& original);
  	   
       Linux_DnsAllowNotifyACLForZoneRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAllowNotifyACLForZoneRepositoryInstance();
       
       Linux_DnsAllowNotifyACLForZoneRepositoryInstance& operator=
  	    (const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsAllowNotifyACLForZoneInstanceName& val);        
       const Linux_DnsAllowNotifyACLForZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& original);
       void reset();
       
       Linux_DnsAllowNotifyACLForZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement{
  	Linux_DnsAllowNotifyACLForZoneRepositoryInstance* m_elementP;
  	Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement();
  	~Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration(
  	   const Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAllowNotifyACLForZoneRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAllowNotifyACLForZoneRepositoryInstance& elementP);
  };
}
#endif

