 /**
 * Linux_DnsNotifyACLForServiceManualInstance.h
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
#ifndef Linux_DnsNotifyACLForServiceManualInstance_h
#define Linux_DnsNotifyACLForServiceManualInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsNotifyACLForServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsNotifyACLForServiceManualInstance {
  public:
       Linux_DnsNotifyACLForServiceManualInstance();
  	
       Linux_DnsNotifyACLForServiceManualInstance
  	    (const Linux_DnsNotifyACLForServiceManualInstance& original);
  	   
       Linux_DnsNotifyACLForServiceManualInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsNotifyACLForServiceManualInstance();
       
       Linux_DnsNotifyACLForServiceManualInstance& operator=
  	    (const Linux_DnsNotifyACLForServiceManualInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsNotifyACLForServiceInstanceName& val);        
       const Linux_DnsNotifyACLForServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsNotifyACLForServiceManualInstance& original);
       void reset();
       
       Linux_DnsNotifyACLForServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsNotifyACLForServiceManualInstanceEnumerationElement{
  	Linux_DnsNotifyACLForServiceManualInstance* m_elementP;
  	Linux_DnsNotifyACLForServiceManualInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsNotifyACLForServiceManualInstanceEnumerationElement();
  	~Linux_DnsNotifyACLForServiceManualInstanceEnumerationElement();  	
  };
  

  class Linux_DnsNotifyACLForServiceManualInstanceEnumeration {
  	private:
  	  Linux_DnsNotifyACLForServiceManualInstanceEnumerationElement* firstElementP;
  	  Linux_DnsNotifyACLForServiceManualInstanceEnumerationElement* currentElementP;
  	  Linux_DnsNotifyACLForServiceManualInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsNotifyACLForServiceManualInstanceEnumeration();
  	  
  	  Linux_DnsNotifyACLForServiceManualInstanceEnumeration(
  	   const Linux_DnsNotifyACLForServiceManualInstanceEnumeration& original);
  	  
  	  ~Linux_DnsNotifyACLForServiceManualInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsNotifyACLForServiceManualInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsNotifyACLForServiceManualInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsNotifyACLForServiceManualInstance& elementP);
  };
}
#endif

