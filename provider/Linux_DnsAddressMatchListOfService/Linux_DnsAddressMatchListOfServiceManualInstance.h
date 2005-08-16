 /**
 * Linux_DnsAddressMatchListOfServiceManualInstance.h
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
#ifndef Linux_DnsAddressMatchListOfServiceManualInstance_h
#define Linux_DnsAddressMatchListOfServiceManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAddressMatchListOfServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsAddressMatchListOfServiceManualInstance {
  public:
       Linux_DnsAddressMatchListOfServiceManualInstance();
  	
       Linux_DnsAddressMatchListOfServiceManualInstance
  	    (const Linux_DnsAddressMatchListOfServiceManualInstance& original);
  	   
       Linux_DnsAddressMatchListOfServiceManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsAddressMatchListOfServiceManualInstance();
       
       Linux_DnsAddressMatchListOfServiceManualInstance& operator=
  	    (const Linux_DnsAddressMatchListOfServiceManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsAddressMatchListOfServiceInstanceName& val);        
       const Linux_DnsAddressMatchListOfServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsAddressMatchListOfServiceManualInstance& original);
       void reset();
       
       Linux_DnsAddressMatchListOfServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement{
  	Linux_DnsAddressMatchListOfServiceManualInstance* m_elementP;
  	Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement();
  	~Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration {
  	private:
  	  Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsAddressMatchListOfServiceManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration();
  	  
  	  Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration(
  	   const Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsAddressMatchListOfServiceManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsAddressMatchListOfServiceManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsAddressMatchListOfServiceManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsAddressMatchListOfServiceManualInstance& elementP);
  };
}
#endif

