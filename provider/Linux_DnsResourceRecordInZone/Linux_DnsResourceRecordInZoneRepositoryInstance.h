 /**
 * Linux_DnsResourceRecordInZoneRepositoryInstance.h
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
#ifndef Linux_DnsResourceRecordInZoneRepositoryInstance_h
#define Linux_DnsResourceRecordInZoneRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsResourceRecordInZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsResourceRecordInZoneRepositoryInstance {
  public:
       Linux_DnsResourceRecordInZoneRepositoryInstance();
  	
       Linux_DnsResourceRecordInZoneRepositoryInstance
  	    (const Linux_DnsResourceRecordInZoneRepositoryInstance& original);
  	   
       Linux_DnsResourceRecordInZoneRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsResourceRecordInZoneRepositoryInstance();
       
       Linux_DnsResourceRecordInZoneRepositoryInstance& operator=
  	    (const Linux_DnsResourceRecordInZoneRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsResourceRecordInZoneInstanceName& val);        
       const Linux_DnsResourceRecordInZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsResourceRecordInZoneRepositoryInstance& original);
       void reset();
       
       Linux_DnsResourceRecordInZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement{
  	Linux_DnsResourceRecordInZoneRepositoryInstance* m_elementP;
  	Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement();
  	~Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsResourceRecordInZoneRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration(
  	   const Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsResourceRecordInZoneRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsResourceRecordInZoneRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsResourceRecordInZoneRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsResourceRecordInZoneRepositoryInstance& elementP);
  };
}
#endif

