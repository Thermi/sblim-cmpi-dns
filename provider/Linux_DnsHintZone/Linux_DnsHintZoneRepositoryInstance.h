 /**
 * Linux_DnsHintZoneRepositoryInstance.h
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
#ifndef Linux_DnsHintZoneRepositoryInstance_h
#define Linux_DnsHintZoneRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsHintZoneInstanceName.h"

namespace genProvider {

  class Linux_DnsHintZoneRepositoryInstance {
  public:
       Linux_DnsHintZoneRepositoryInstance();
  	
       Linux_DnsHintZoneRepositoryInstance
  	    (const Linux_DnsHintZoneRepositoryInstance& original);
  	   
       Linux_DnsHintZoneRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsHintZoneRepositoryInstance();
       
       Linux_DnsHintZoneRepositoryInstance& operator=
  	    (const Linux_DnsHintZoneRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsHintZoneInstanceName& val);        
       const Linux_DnsHintZoneInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsHintZoneRepositoryInstance& original);
       void reset();
       
       Linux_DnsHintZoneInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsHintZoneRepositoryInstanceEnumerationElement{
  	Linux_DnsHintZoneRepositoryInstance* m_elementP;
  	Linux_DnsHintZoneRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsHintZoneRepositoryInstanceEnumerationElement();
  	~Linux_DnsHintZoneRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsHintZoneRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsHintZoneRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsHintZoneRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsHintZoneRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsHintZoneRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsHintZoneRepositoryInstanceEnumeration(
  	   const Linux_DnsHintZoneRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsHintZoneRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsHintZoneRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsHintZoneRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsHintZoneRepositoryInstance& elementP);
  };
}
#endif

