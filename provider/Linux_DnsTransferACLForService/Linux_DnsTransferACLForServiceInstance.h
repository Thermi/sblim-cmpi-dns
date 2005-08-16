 /**
 * Linux_DnsTransferACLForServiceInstance.h
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
#ifndef Linux_DnsTransferACLForServiceInstance_h
#define Linux_DnsTransferACLForServiceInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsTransferACLForServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsTransferACLForServiceInstance {
  public:
       Linux_DnsTransferACLForServiceInstance();
  	
       Linux_DnsTransferACLForServiceInstance
  	    (const Linux_DnsTransferACLForServiceInstance& original);
  	   
       Linux_DnsTransferACLForServiceInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsTransferACLForServiceInstance();
       
       Linux_DnsTransferACLForServiceInstance& operator=
  	    (const Linux_DnsTransferACLForServiceInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsTransferACLForServiceInstanceName& val);        
       const Linux_DnsTransferACLForServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsTransferACLForServiceInstance& original);
       void reset();
       
       Linux_DnsTransferACLForServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsTransferACLForServiceInstanceEnumerationElement{
  	Linux_DnsTransferACLForServiceInstance* m_elementP;
  	Linux_DnsTransferACLForServiceInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsTransferACLForServiceInstanceEnumerationElement();
  	~Linux_DnsTransferACLForServiceInstanceEnumerationElement();  	
  };
  

  class Linux_DnsTransferACLForServiceInstanceEnumeration {
  	private:
  	  Linux_DnsTransferACLForServiceInstanceEnumerationElement* firstElementP;
  	  Linux_DnsTransferACLForServiceInstanceEnumerationElement* currentElementP;
  	  Linux_DnsTransferACLForServiceInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsTransferACLForServiceInstanceEnumeration();
  	  
  	  Linux_DnsTransferACLForServiceInstanceEnumeration(
  	   const Linux_DnsTransferACLForServiceInstanceEnumeration& original);
  	  
  	  ~Linux_DnsTransferACLForServiceInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsTransferACLForServiceInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsTransferACLForServiceInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsTransferACLForServiceInstance& elementP);
  };
}
#endif

