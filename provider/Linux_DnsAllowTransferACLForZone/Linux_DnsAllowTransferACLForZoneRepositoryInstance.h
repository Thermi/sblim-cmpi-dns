 /**
 * Linux_DnsAllowTransferACLForZoneRepositoryInstance.h
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
#ifndef Linux_DnsAllowTransferACLForZoneRepositoryInstance_h
#define Linux_DnsAllowTransferACLForZoneRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowTransferACLForZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsAllowTransferACLForZoneRepositoryInstance {
  public:
       Linux_DnsAllowTransferACLForZoneRepositoryInstance();
  	
       Linux_DnsAllowTransferACLForZoneRepositoryInstance
  	    (const Linux_DnsAllowTransferACLForZoneRepositoryInstance& original);
  	   
       Linux_DnsAllowTransferACLForZoneRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAllowTransferACLForZoneRepositoryInstance();
       
       Linux_DnsAllowTransferACLForZoneRepositoryInstance& operator=
  	    (const Linux_DnsAllowTransferACLForZoneRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsAllowTransferACLForZoneInstanceName& val);        
       const Linux_DnsAllowTransferACLForZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsAllowTransferACLForZoneRepositoryInstance& original);
       void reset();
       
       Linux_DnsAllowTransferACLForZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement{
  	Linux_DnsAllowTransferACLForZoneRepositoryInstance* m_elementP;
  	Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement();
  	~Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration(
  	   const Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAllowTransferACLForZoneRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAllowTransferACLForZoneRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAllowTransferACLForZoneRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAllowTransferACLForZoneRepositoryInstance& elementP);
  };
}
#endif

