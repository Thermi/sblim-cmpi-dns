 /**
 * Linux_DnsAllowUpdateACLForZoneRepositoryInstance.h
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
#ifndef Linux_DnsAllowUpdateACLForZoneRepositoryInstance_h
#define Linux_DnsAllowUpdateACLForZoneRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowUpdateACLForZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsAllowUpdateACLForZoneRepositoryInstance {
  public:
       Linux_DnsAllowUpdateACLForZoneRepositoryInstance();
  	
       Linux_DnsAllowUpdateACLForZoneRepositoryInstance
  	    (const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& original);
  	   
       Linux_DnsAllowUpdateACLForZoneRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAllowUpdateACLForZoneRepositoryInstance();
       
       Linux_DnsAllowUpdateACLForZoneRepositoryInstance& operator=
  	    (const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsAllowUpdateACLForZoneInstanceName& val);        
       const Linux_DnsAllowUpdateACLForZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& original);
       void reset();
       
       Linux_DnsAllowUpdateACLForZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement{
  	Linux_DnsAllowUpdateACLForZoneRepositoryInstance* m_elementP;
  	Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement();
  	~Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration(
  	   const Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAllowUpdateACLForZoneRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAllowUpdateACLForZoneRepositoryInstance& elementP);
  };
}
#endif

