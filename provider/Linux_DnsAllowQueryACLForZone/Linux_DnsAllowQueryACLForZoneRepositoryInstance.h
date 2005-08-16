 /**
 * Linux_DnsAllowQueryACLForZoneRepositoryInstance.h
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
#ifndef Linux_DnsAllowQueryACLForZoneRepositoryInstance_h
#define Linux_DnsAllowQueryACLForZoneRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowQueryACLForZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsAllowQueryACLForZoneRepositoryInstance {
  public:
       Linux_DnsAllowQueryACLForZoneRepositoryInstance();
  	
       Linux_DnsAllowQueryACLForZoneRepositoryInstance
  	    (const Linux_DnsAllowQueryACLForZoneRepositoryInstance& original);
  	   
       Linux_DnsAllowQueryACLForZoneRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAllowQueryACLForZoneRepositoryInstance();
       
       Linux_DnsAllowQueryACLForZoneRepositoryInstance& operator=
  	    (const Linux_DnsAllowQueryACLForZoneRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsAllowQueryACLForZoneInstanceName& val);        
       const Linux_DnsAllowQueryACLForZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsAllowQueryACLForZoneRepositoryInstance& original);
       void reset();
       
       Linux_DnsAllowQueryACLForZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement{
  	Linux_DnsAllowQueryACLForZoneRepositoryInstance* m_elementP;
  	Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement();
  	~Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration(
  	   const Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAllowQueryACLForZoneRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAllowQueryACLForZoneRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAllowQueryACLForZoneRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAllowQueryACLForZoneRepositoryInstance& elementP);
  };
}
#endif

