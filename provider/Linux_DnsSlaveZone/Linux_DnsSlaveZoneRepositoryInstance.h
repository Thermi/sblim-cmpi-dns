 /**
 * Linux_DnsSlaveZoneRepositoryInstance.h
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
#ifndef Linux_DnsSlaveZoneRepositoryInstance_h
#define Linux_DnsSlaveZoneRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsSlaveZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsSlaveZoneRepositoryInstance {
  public:
       Linux_DnsSlaveZoneRepositoryInstance();
  	
       Linux_DnsSlaveZoneRepositoryInstance
  	    (const Linux_DnsSlaveZoneRepositoryInstance& original);
  	   
       Linux_DnsSlaveZoneRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsSlaveZoneRepositoryInstance();
       
       Linux_DnsSlaveZoneRepositoryInstance& operator=
  	    (const Linux_DnsSlaveZoneRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsSlaveZoneInstanceName& val);        
       const Linux_DnsSlaveZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsSlaveZoneRepositoryInstance& original);
       void reset();
       
       Linux_DnsSlaveZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement{
  	Linux_DnsSlaveZoneRepositoryInstance* m_elementP;
  	Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement();
  	~Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsSlaveZoneRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsSlaveZoneRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsSlaveZoneRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsSlaveZoneRepositoryInstanceEnumeration(
  	   const Linux_DnsSlaveZoneRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsSlaveZoneRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsSlaveZoneRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsSlaveZoneRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsSlaveZoneRepositoryInstance& elementP);
  };
}
#endif

