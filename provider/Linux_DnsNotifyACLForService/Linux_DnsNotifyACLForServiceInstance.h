 /**
 * Linux_DnsNotifyACLForServiceInstance.h
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
#ifndef Linux_DnsNotifyACLForServiceInstance_h
#define Linux_DnsNotifyACLForServiceInstance_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsNotifyACLForServiceInstanceName.h"

namespace genProvider {

  class Linux_DnsNotifyACLForServiceInstance {
  public:
       Linux_DnsNotifyACLForServiceInstance();
  	
       Linux_DnsNotifyACLForServiceInstance
  	    (const Linux_DnsNotifyACLForServiceInstance& original);
  	   
       Linux_DnsNotifyACLForServiceInstance
        (const CmpiInstance& inst, const char* instanceNamespace);
  	 
       ~Linux_DnsNotifyACLForServiceInstance();
       
       Linux_DnsNotifyACLForServiceInstance& operator=
  	    (const Linux_DnsNotifyACLForServiceInstance& original);
       
       CmpiInstance getCmpiInstance(const char** properties=0) const;
       
       unsigned int isInstanceNameSet() const;
       void setInstanceName(
        const Linux_DnsNotifyACLForServiceInstanceName& val);        
       const Linux_DnsNotifyACLForServiceInstanceName&
        getInstanceName() const;
       
  private:
       void init();
       void init(const Linux_DnsNotifyACLForServiceInstance& original);
       void reset();
       
       Linux_DnsNotifyACLForServiceInstanceName m_instanceName;
       
       struct isSetType{
       	 unsigned int instanceName:1;
       } isSet;
  };
  
  
  struct Linux_DnsNotifyACLForServiceInstanceEnumerationElement{
  	Linux_DnsNotifyACLForServiceInstance* m_elementP;
  	Linux_DnsNotifyACLForServiceInstanceEnumerationElement* m_nextP;
  	
  	Linux_DnsNotifyACLForServiceInstanceEnumerationElement();
  	~Linux_DnsNotifyACLForServiceInstanceEnumerationElement();  	
  };
  

  class Linux_DnsNotifyACLForServiceInstanceEnumeration {
  	private:
  	  Linux_DnsNotifyACLForServiceInstanceEnumerationElement* firstElementP;
  	  Linux_DnsNotifyACLForServiceInstanceEnumerationElement* currentElementP;
  	  Linux_DnsNotifyACLForServiceInstanceEnumerationElement* endElementP;
  	
  	public:
  	  Linux_DnsNotifyACLForServiceInstanceEnumeration();
  	  
  	  Linux_DnsNotifyACLForServiceInstanceEnumeration(
  	   const Linux_DnsNotifyACLForServiceInstanceEnumeration& original);
  	  
  	  ~Linux_DnsNotifyACLForServiceInstanceEnumeration();
  	  
  	  void reset();
  	  
  	  bool hasNext() const;
  	  
  	  const Linux_DnsNotifyACLForServiceInstance& getNext();
  	  
  	  int getSize() const;
  	  
  	  const Linux_DnsNotifyACLForServiceInstance& getElement(int pos) const;  	  
  	  
  	 void addElement(const Linux_DnsNotifyACLForServiceInstance& elementP);
  };
}
#endif

