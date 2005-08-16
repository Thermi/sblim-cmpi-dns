 /**
 * Linux_DnsZoneRepositoryInstance.h
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
#ifndef Linux_DnsZoneRepositoryInstance_h
#define Linux_DnsZoneRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsZoneRepositoryInstance {
  public:
       Linux_DnsZoneRepositoryInstance();
  	
       Linux_DnsZoneRepositoryInstance
  	    (const Linux_DnsZoneRepositoryInstance& original);
  	   
       Linux_DnsZoneRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsZoneRepositoryInstance();
       
       Linux_DnsZoneRepositoryInstance& operator=
  	    (const Linux_DnsZoneRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsZoneInstanceName& val);        
       const Linux_DnsZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsZoneRepositoryInstance& original);
       void reset();
       
       Linux_DnsZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsZoneRepositoryInstanceEnumerationElement{
  	Linux_DnsZoneRepositoryInstance* m_elementP;
  	Linux_DnsZoneRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsZoneRepositoryInstanceEnumerationElement();
  	~Linux_DnsZoneRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsZoneRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsZoneRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsZoneRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsZoneRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsZoneRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsZoneRepositoryInstanceEnumeration(
  	   const Linux_DnsZoneRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsZoneRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsZoneRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsZoneRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsZoneRepositoryInstance& elementP);
  };
}
#endif

