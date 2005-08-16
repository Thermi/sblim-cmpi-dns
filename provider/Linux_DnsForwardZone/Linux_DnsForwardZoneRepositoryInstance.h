 /**
 * Linux_DnsForwardZoneRepositoryInstance.h
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
#ifndef Linux_DnsForwardZoneRepositoryInstance_h
#define Linux_DnsForwardZoneRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsForwardZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsForwardZoneRepositoryInstance {
  public:
       Linux_DnsForwardZoneRepositoryInstance();
  	
       Linux_DnsForwardZoneRepositoryInstance
  	    (const Linux_DnsForwardZoneRepositoryInstance& original);
  	   
       Linux_DnsForwardZoneRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsForwardZoneRepositoryInstance();
       
       Linux_DnsForwardZoneRepositoryInstance& operator=
  	    (const Linux_DnsForwardZoneRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsForwardZoneInstanceName& val);        
       const Linux_DnsForwardZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsForwardZoneRepositoryInstance& original);
       void reset();
       
       Linux_DnsForwardZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsForwardZoneRepositoryInstanceEnumerationElement{
  	Linux_DnsForwardZoneRepositoryInstance* m_elementP;
  	Linux_DnsForwardZoneRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsForwardZoneRepositoryInstanceEnumerationElement();
  	~Linux_DnsForwardZoneRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsForwardZoneRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsForwardZoneRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsForwardZoneRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsForwardZoneRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsForwardZoneRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsForwardZoneRepositoryInstanceEnumeration(
  	   const Linux_DnsForwardZoneRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsForwardZoneRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsForwardZoneRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsForwardZoneRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsForwardZoneRepositoryInstance& elementP);
  };
}
#endif

