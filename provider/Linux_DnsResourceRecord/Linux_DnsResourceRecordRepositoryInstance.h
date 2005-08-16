 /**
 * Linux_DnsResourceRecordRepositoryInstance.h
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
#ifndef Linux_DnsResourceRecordRepositoryInstance_h
#define Linux_DnsResourceRecordRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsResourceRecordInstanceName.h"

namespace genProvider {

  class Linux_DnsResourceRecordRepositoryInstance {
  public:
       Linux_DnsResourceRecordRepositoryInstance();
  	
       Linux_DnsResourceRecordRepositoryInstance
  	    (const Linux_DnsResourceRecordRepositoryInstance& original);
  	   
       Linux_DnsResourceRecordRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsResourceRecordRepositoryInstance();
       
       Linux_DnsResourceRecordRepositoryInstance& operator=
  	    (const Linux_DnsResourceRecordRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsResourceRecordInstanceName& val);        
       const Linux_DnsResourceRecordInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsResourceRecordRepositoryInstance& original);
       void reset();
       
       Linux_DnsResourceRecordInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsResourceRecordRepositoryInstanceEnumerationElement{
  	Linux_DnsResourceRecordRepositoryInstance* m_elementP;
  	Linux_DnsResourceRecordRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsResourceRecordRepositoryInstanceEnumerationElement();
  	~Linux_DnsResourceRecordRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsResourceRecordRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsResourceRecordRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsResourceRecordRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsResourceRecordRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsResourceRecordRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsResourceRecordRepositoryInstanceEnumeration(
  	   const Linux_DnsResourceRecordRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsResourceRecordRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsResourceRecordRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsResourceRecordRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsResourceRecordRepositoryInstance& elementP);
  };
}
#endif

