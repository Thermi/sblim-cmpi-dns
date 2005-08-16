 /**
 * Linux_DnsTransferACLForServiceManualInstance.h
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
#ifndef Linux_DnsTransferACLForServiceManualInstance_h
#define Linux_DnsTransferACLForServiceManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsTransferACLForServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsTransferACLForServiceManualInstance {
  public:
       Linux_DnsTransferACLForServiceManualInstance();
  	
       Linux_DnsTransferACLForServiceManualInstance
  	    (const Linux_DnsTransferACLForServiceManualInstance& original);
  	   
       Linux_DnsTransferACLForServiceManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsTransferACLForServiceManualInstance();
       
       Linux_DnsTransferACLForServiceManualInstance& operator=
  	    (const Linux_DnsTransferACLForServiceManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsTransferACLForServiceInstanceName& val);        
       const Linux_DnsTransferACLForServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsTransferACLForServiceManualInstance& original);
       void reset();
       
       Linux_DnsTransferACLForServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsTransferACLForServiceManualInstanceEnumerationElement{
  	Linux_DnsTransferACLForServiceManualInstance* m_elementP;
  	Linux_DnsTransferACLForServiceManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsTransferACLForServiceManualInstanceEnumerationElement();
  	~Linux_DnsTransferACLForServiceManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsTransferACLForServiceManualInstanceEnumeration {
  	private:
  	  Linux_DnsTransferACLForServiceManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsTransferACLForServiceManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsTransferACLForServiceManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsTransferACLForServiceManualInstanceEnumeration();
  	  
  	  Linux_DnsTransferACLForServiceManualInstanceEnumeration(
  	   const Linux_DnsTransferACLForServiceManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsTransferACLForServiceManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsTransferACLForServiceManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsTransferACLForServiceManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsTransferACLForServiceManualInstance& elementP);
  };
}
#endif

