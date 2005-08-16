 /**
 * Linux_DnsAddressMatchListOfServiceRepositoryInstance.h
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
#ifndef Linux_DnsAddressMatchListOfServiceRepositoryInstance_h
#define Linux_DnsAddressMatchListOfServiceRepositoryInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAddressMatchListOfServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsAddressMatchListOfServiceRepositoryInstance {
  public:
       Linux_DnsAddressMatchListOfServiceRepositoryInstance();
  	
       Linux_DnsAddressMatchListOfServiceRepositoryInstance
  	    (const Linux_DnsAddressMatchListOfServiceRepositoryInstance& original);
  	   
       Linux_DnsAddressMatchListOfServiceRepositoryInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAddressMatchListOfServiceRepositoryInstance();
       
       Linux_DnsAddressMatchListOfServiceRepositoryInstance& operator=
  	    (const Linux_DnsAddressMatchListOfServiceRepositoryInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsAddressMatchListOfServiceInstanceName& val);        
       const Linux_DnsAddressMatchListOfServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsAddressMatchListOfServiceRepositoryInstance& original);
       void reset();
       
       Linux_DnsAddressMatchListOfServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement{
  	Linux_DnsAddressMatchListOfServiceRepositoryInstance* m_elementP;
  	Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement();
  	~Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration {
  	private:
  	  Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration();
  	  
  	  Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration(
  	   const Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAddressMatchListOfServiceRepositoryInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAddressMatchListOfServiceRepositoryInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAddressMatchListOfServiceRepositoryInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAddressMatchListOfServiceRepositoryInstance& elementP);
  };
}
#endif

