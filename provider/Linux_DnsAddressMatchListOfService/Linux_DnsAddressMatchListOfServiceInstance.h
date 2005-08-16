 /**
 * Linux_DnsAddressMatchListOfServiceInstance.h
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
#ifndef Linux_DnsAddressMatchListOfServiceInstance_h
#define Linux_DnsAddressMatchListOfServiceInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAddressMatchListOfServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsAddressMatchListOfServiceInstance {
  public:
       Linux_DnsAddressMatchListOfServiceInstance();
  	
       Linux_DnsAddressMatchListOfServiceInstance
  	    (const Linux_DnsAddressMatchListOfServiceInstance& original);
  	   
       Linux_DnsAddressMatchListOfServiceInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAddressMatchListOfServiceInstance();
       
       Linux_DnsAddressMatchListOfServiceInstance& operator=
  	    (const Linux_DnsAddressMatchListOfServiceInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsAddressMatchListOfServiceInstanceName& val);        
       const Linux_DnsAddressMatchListOfServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsAddressMatchListOfServiceInstance& original);
       void reset();
       
       Linux_DnsAddressMatchListOfServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsAddressMatchListOfServiceInstanceEnumerationElement{
  	Linux_DnsAddressMatchListOfServiceInstance* m_elementP;
  	Linux_DnsAddressMatchListOfServiceInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAddressMatchListOfServiceInstanceEnumerationElement();
  	~Linux_DnsAddressMatchListOfServiceInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAddressMatchListOfServiceInstanceEnumeration {
  	private:
  	  Linux_DnsAddressMatchListOfServiceInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAddressMatchListOfServiceInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAddressMatchListOfServiceInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAddressMatchListOfServiceInstanceEnumeration();
  	  
  	  Linux_DnsAddressMatchListOfServiceInstanceEnumeration(
  	   const Linux_DnsAddressMatchListOfServiceInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAddressMatchListOfServiceInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAddressMatchListOfServiceInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAddressMatchListOfServiceInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAddressMatchListOfServiceInstance& elementP);
  };
}
#endif

