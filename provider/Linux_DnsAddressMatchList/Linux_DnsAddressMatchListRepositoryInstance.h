 /**
 * Linux_DnsAddressMatchListRepositoryInstance.h
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
#ifndef Linux_DnsAddressMatchListRepositoryInstance_h
#define Linux_DnsAddressMatchListRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAddressMatchListInstanceName.h"

namespace genProvider {

  class Linux_DnsAddressMatchListRepositoryInstance {
  public:
       Linux_DnsAddressMatchListRepositoryInstance();
  	
       Linux_DnsAddressMatchListRepositoryInstance
  	    (const Linux_DnsAddressMatchListRepositoryInstance& original);
  	   
       Linux_DnsAddressMatchListRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAddressMatchListRepositoryInstance();
       
       Linux_DnsAddressMatchListRepositoryInstance& operator=
  	    (const Linux_DnsAddressMatchListRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsAddressMatchListInstanceName& val);        
       const Linux_DnsAddressMatchListInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsAddressMatchListRepositoryInstance& original);
       void reset();
       
       Linux_DnsAddressMatchListInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement{
  	Linux_DnsAddressMatchListRepositoryInstance* m_elementP;
  	Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement();
  	~Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAddressMatchListRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAddressMatchListRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAddressMatchListRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsAddressMatchListRepositoryInstanceEnumeration(
  	   const Linux_DnsAddressMatchListRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAddressMatchListRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAddressMatchListRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAddressMatchListRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAddressMatchListRepositoryInstance& elementP);
  };
}
#endif

